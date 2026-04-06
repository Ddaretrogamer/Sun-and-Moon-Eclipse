#include "global.h"
#include "regions.h"
#include "constants/region_map_sections.h"


static const u16 sKantoSubregionMapsecs[KANTO_SUBREGION_COUNT][30] = {
    [KANTO_SUBREGION_KANTO] =
    {
        MAPSEC_NONE
    },
    [KANTO_SUBREGION_SEVII123] =
    {
        MAPSEC_ONE_ISLAND,
        MAPSEC_TWO_ISLAND,
        MAPSEC_THREE_ISLAND,
        MAPSEC_KINDLE_ROAD,
        MAPSEC_TREASURE_BEACH,
        MAPSEC_CAPE_BRINK,
        MAPSEC_BOND_BRIDGE,
        MAPSEC_THREE_ISLE_PORT,
        MAPSEC_MT_EMBER,
        MAPSEC_BERRY_FOREST,
        MAPSEC_THREE_ISLE_PATH,
        MAPSEC_EMBER_SPA,
        MAPSEC_NONE
    },
    [KANTO_SUBREGION_SEVII45] =
    {
        MAPSEC_FOUR_ISLAND,
        MAPSEC_FIVE_ISLAND,
        MAPSEC_RESORT_GORGEOUS,
        MAPSEC_WATER_LABYRINTH,
        MAPSEC_FIVE_ISLE_MEADOW,
        MAPSEC_MEMORIAL_PILLAR,
        MAPSEC_NAVEL_ROCK_FRLG,
        MAPSEC_ICEFALL_CAVE,
        MAPSEC_ROCKET_WAREHOUSE,
        MAPSEC_LOST_CAVE,
        MAPSEC_NONE
    },
    [KANTO_SUBREGION_SEVII67] =
    {
        MAPSEC_SEVEN_ISLAND,
        MAPSEC_SIX_ISLAND,
        MAPSEC_OUTCAST_ISLAND,
        MAPSEC_GREEN_PATH,
        MAPSEC_WATER_PATH,
        MAPSEC_RUIN_VALLEY,
        MAPSEC_TRAINER_TOWER,
        MAPSEC_CANYON_ENTRANCE,
        MAPSEC_SEVAULT_CANYON,
        MAPSEC_TANOBY_RUINS,
        MAPSEC_SEVII_ISLE_22,
        MAPSEC_SEVII_ISLE_23,
        MAPSEC_SEVII_ISLE_24,
        MAPSEC_TRAINER_TOWER_2,
        MAPSEC_DOTTED_HOLE,
        MAPSEC_PATTERN_BUSH,
        MAPSEC_ALTERING_CAVE_FRLG,
        MAPSEC_TANOBY_CHAMBERS,
        MAPSEC_TANOBY_KEY,
        MAPSEC_BIRTH_ISLAND_FRLG,
        MAPSEC_MONEAN_CHAMBER,
        MAPSEC_LIPTOO_CHAMBER,
        MAPSEC_WEEPTH_CHAMBER,
        MAPSEC_DILFORD_CHAMBER,
        MAPSEC_SCUFIB_CHAMBER,
        MAPSEC_RIXY_CHAMBER,
        MAPSEC_VIAPOIS_CHAMBER,
        MAPSEC_NONE
    }
};

enum KantoSubRegion GetKantoSubregion(u32 mapSecId)
{
    for (u32 i = KANTO_SUBREGION_KANTO; i <= KANTO_SUBREGION_SEVII67; i++)
    {
        for (u32 j = 0; sKantoSubregionMapsecs[i][j] != MAPSEC_NONE; j++)
        {
            if (mapSecId == sKantoSubregionMapsecs[i][j])
                return i;
        }
    }
    return KANTO_SUBREGION_KANTO;
}

static const u16 sAlolaSubregionMapsecs[ALOLA_SUBREGION_COUNT][5] = {
    [ALOLA_SUBREGION_MELEMELE] =
    {
        MAPSEC_NONE
    },
    [ALOLA_SUBREGION_AETHER] =
    {
        MAPSEC_AETHER_PARADISE_SM,
        MAPSEC_NONE
    }
};

enum AlolaSubRegion GetAlolaSubregion(u32 mapSecId)
{
    for (u32 i = ALOLA_SUBREGION_MELEMELE; i <= ALOLA_SUBREGION_AETHER; i++)
    {
        for (u32 j = 0; sAlolaSubregionMapsecs[i][j] != MAPSEC_NONE; j++)
        {
            if (mapSecId == sAlolaSubregionMapsecs[i][j])
                return i;
        }
    }
    return ALOLA_SUBREGION_MELEMELE;
}
