#!/usr/bin/env python3

"""
Converts .bin audio files (GBA format) to .wav files.
Reads the binary format created by aif2pcm and generates WAV files
that will produce identical binaries when processed by wav2agb -b.
"""

import struct
import sys
import os
from typing import Optional

# Delta encoding table used for compression/decompression
# Matches the table in tools/aif2pcm/main.c
DELTA_ENCODING_TABLE = [
    0, 1, 4, 9, 16, 25, 36, 49,
    -64, -49, -36, -25, -16, -9, -4, -1,
]


def delta_decompress(compressed_data: bytes, expected_length: int) -> bytes:
    """
    Decompress delta-encoded audio data.

    Delta compression format (from tools/aif2pcm/main.c):
    - Data is organized in blocks of up to 64 samples each
    - Each block starts with a base sample value (1 byte)
    - Followed by a delta index (4 bits) for the second sample
    - Then 31 pairs of delta indices (4 bits each, packed into bytes)
    - Delta indices reference DELTA_ENCODING_TABLE to get the actual delta value

    Args:
        compressed_data: The compressed audio data
        expected_length: Expected length of decompressed data

    Returns:
        Decompressed audio data as bytes
    """
    pcm = bytearray(expected_length + 0x40)  # Extra buffer space

    i = 0  # Input position
    j = 0  # Output position

    while i < len(compressed_data) and j < expected_length:
        # Read base sample for this block
        base = compressed_data[i]
        # Convert to signed int8 for calculations
        base_signed = base if base < 128 else base - 256
        pcm[j] = base
        i += 1
        j += 1

        if i >= len(compressed_data) or j >= expected_length:
            break

        # Read second sample using low nibble delta
        lo = compressed_data[i] & 0xf
        base_signed += DELTA_ENCODING_TABLE[lo]
        pcm[j] = base_signed & 0xff
        i += 1
        j += 1

        if i >= len(compressed_data) or j >= expected_length:
            break

        # Process up to 31 pairs of samples (62 samples total)
        for k in range(31):
            # High nibble
            hi = (compressed_data[i] >> 4) & 0xf
            base_signed += DELTA_ENCODING_TABLE[hi]
            pcm[j] = base_signed & 0xff
            j += 1

            if j >= expected_length:
                break

            # Low nibble
            lo = compressed_data[i] & 0xf
            base_signed += DELTA_ENCODING_TABLE[lo]
            pcm[j] = base_signed & 0xff
            j += 1
            i += 1

            if i >= len(compressed_data):
                break
            if j >= expected_length:
                break

        if j >= expected_length:
            break

    return bytes(pcm[:j])


def read_bin(bin_path: str) -> tuple:
    """
    Read a GBA audio .bin file and extract all data.

    Binary format (little-endian):
    - Bytes 0-3: flags (bit 0 = compression, bit 30 = loop enabled)
    - Bytes 4-7: pitch value = sample_rate * 1024
    - Bytes 8-11: loop start position
    - Bytes 12-15: loop end position (stored as actual_end - 1)
    - Remaining bytes: audio samples (8-bit signed)
    """
    with open(bin_path, 'rb') as f:
        bin_data = f.read()

    if len(bin_data) < 16:
        raise ValueError(f"File too small: {len(bin_data)} bytes")

    # Read header
    flags = struct.unpack('<I', bin_data[0:4])[0]
    pitch_value = struct.unpack('<I', bin_data[4:8])[0]
    loop_start = struct.unpack('<I', bin_data[8:12])[0]
    loop_end_stored = struct.unpack('<I', bin_data[12:16])[0]

    # Extract flags
    is_compressed = (flags & 0x01) != 0
    is_looped = (flags & 0x40000000) != 0

    # Calculate sample rate from pitch value
    sample_rate = pitch_value / 1024.0

    # loop_end_stored is the exact value that must appear in the output bin header.
    # We pass it through unchanged so write_wav can embed it in the 'agbl' chunk,
    # which wav2agb uses as a direct override (bypassing the smpl round-trip entirely).
    expected_num_samples = loop_end_stored + 1

    # Read sample data (8-bit signed)
    compressed_data = bin_data[16:]

    if is_compressed:
        samples = delta_decompress(compressed_data, expected_num_samples)

        # Pad to expected length if the compressed data is slightly short
        if len(samples) < expected_num_samples:
            last_sample = samples[-1] if len(samples) > 0 else 0
            padding = bytes([last_sample] * (expected_num_samples - len(samples)))
            samples = samples + padding
    else:
        # Use all audio bytes as-is (trailing alignment padding is harmless)
        samples = compressed_data

    return sample_rate, is_looped, loop_start, loop_end_stored, samples


def write_wav(wav_path: str, sample_rate: float, is_looped: bool,
              loop_start: int, loop_end_stored: int, samples: bytes):
    """
    Write a .wav file with smpl, agbp, and (for looped files) agbl chunks.

    loop_end_stored is the raw value from the bin header (i.e. last sample index,
    same as aif2pcm's off-by-one convention). It is written into a custom 'agbl'
    chunk which wav2agb reads as a direct loopEnd override, bypassing the smpl
    round-trip and its associated clamp entirely.
    """
    # WAV uses unsigned 8-bit, GBA bin uses signed 8-bit
    # Convert signed (-128 to +127) to unsigned (0 to 255)
    samples_unsigned = bytes((b + 128) & 0xFF for b in samples)

    # For WAV fmt chunk, use integer sample rate
    sample_rate_int = int(sample_rate)
    num_channels = 1
    bytes_per_sample = 1
    bits_per_sample = 8
    byte_rate = sample_rate_int * num_channels * bytes_per_sample
    block_align = num_channels * bytes_per_sample

    # Build fmt chunk
    fmt_chunk = struct.pack('<HHIIHH',
        1,                  # Audio format (1 = PCM)
        num_channels,       # Number of channels
        sample_rate_int,    # Sample rate (integer)
        byte_rate,          # Byte rate
        block_align,        # Block align
        bits_per_sample     # Bits per sample
    )

    # Build smpl chunk
    sample_period = int(1000000000.0 / sample_rate)
    midi_note = 60

    smpl_chunk = struct.pack('<IIIIIIII',
        0,                      # Manufacturer
        0,                      # Product
        sample_period,          # Sample period (nanoseconds)
        midi_note,              # MIDI unity note
        0,                      # MIDI pitch fraction
        0,                      # SMPTE format
        0,                      # SMPTE offset
        1 if is_looped else 0   # Num sample loops
    )
    smpl_chunk += struct.pack('<I', 0)  # Sampler data

    if is_looped:
        # smpl loop end is inclusive; loop_end_stored is already the last sample index
        smpl_chunk += struct.pack('<IIIIII',
            0,                  # Cue point ID
            0,                  # Type (0 = forward loop)
            loop_start,         # Start
            loop_end_stored,    # End (inclusive) - matches loop_end_stored exactly
            0,                  # Fraction
            0                   # Play count (0 = infinite)
        )

    # Build 'agbp' chunk: exact GBA pitch value to avoid precision loss
    pitch_value_int = int(sample_rate * 1024.0)
    agbp_chunk = struct.pack('<I', pitch_value_int)

    # Build 'agbl' chunk: direct loopEnd override for wav2agb.
    # wav2agb reads this value and uses it as-is for the bin header,
    # bypassing the smpl+clamp path entirely. This preserves the off-by-one
    # convention that aif2pcm used, which custom samples may depend on.
    agbl_chunk = struct.pack('<I', loop_end_stored) if is_looped else None

    # Assemble chunks list
    chunks = [
        (b'fmt ', fmt_chunk),
        (b'smpl', smpl_chunk),
        (b'agbp', agbp_chunk),
    ]
    if agbl_chunk is not None:
        chunks.append((b'agbl', agbl_chunk))
    chunks.append((b'data', samples_unsigned))

    # Calculate RIFF size
    riff_size = 4 + sum(8 + len(data) for _, data in chunks)

    with open(wav_path, 'wb') as f:
        f.write(b'RIFF')
        f.write(struct.pack('<I', riff_size))
        f.write(b'WAVE')
        for chunk_id, chunk_data in chunks:
            f.write(chunk_id)
            f.write(struct.pack('<I', len(chunk_data)))
            f.write(chunk_data)


def convert_bin_to_wav(bin_path: str, wav_path: Optional[str] = None):
    """Convert a single .bin file to .wav format"""
    if wav_path is None:
        wav_path = os.path.splitext(bin_path)[0] + '.wav'

    print(f"Converting {bin_path} -> {wav_path}")

    sample_rate, is_looped, loop_start, loop_end, samples = read_bin(bin_path)

    print(f"  Sample rate: {sample_rate} Hz")
    print(f"  Num samples: {len(samples)}")
    if is_looped:
        print(f"  Loop: {loop_start} -> {loop_end}")
    else:
        print(f"  Loop: None")

    write_wav(wav_path, sample_rate, is_looped, loop_start, loop_end, samples)
    print(f"  Done!")


def main():
    if len(sys.argv) < 2:
        print("Usage: bin_to_wav.py <input.bin> [output.wav]")
        print("   or: bin_to_wav.py <directory>  (converts all .bin files in directory)")
        sys.exit(1)

    input_path = sys.argv[1]

    if os.path.isdir(input_path):
        # Convert all .bin files in directory
        for filename in sorted(os.listdir(input_path)):
            if filename.lower().endswith('.bin'):
                bin_path = os.path.join(input_path, filename)
                convert_bin_to_wav(bin_path)
    else:
        # Convert single file
        output_path = sys.argv[2] if len(sys.argv) > 2 else None
        convert_bin_to_wav(input_path, output_path)


if __name__ == '__main__':
    main()