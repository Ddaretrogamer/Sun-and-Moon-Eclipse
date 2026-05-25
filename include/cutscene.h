#ifndef GUARD_CUTSCENE_H
#define GUARD_CUTSCENE_H

#include "script.h"

// Set to TRUE to track seen cutscenes via existing flags (defined per-entry in src/data/cutscene.h).
// Set to FALSE to use a dedicated bitfield in SaveBlock2 instead.
#define CUTSCENE_FLAG_TRACKING TRUE

struct CutsceneSkip
{
    const u8 *scriptCutsceneSkipPtr;
#if CUTSCENE_FLAG_TRACKING == TRUE
    u16 flag;
#endif
};

void StartSkippableCutscene(struct ScriptContext *ctx);
void EndSkippableCutscene(struct ScriptContext *ctx);

#endif // GUARD_CUTSCENE_H
