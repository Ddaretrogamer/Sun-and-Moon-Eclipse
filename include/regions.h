#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.h"
#include "constants/regions.h"
#include "constants/region_map_sections.h"

enum KantoSubRegion GetKantoSubregion(u32 mapSecId);
enum AlolaSubRegion GetAlolaSubregion(u32 mapSecId);

static inline enum Region GetRegionForSectionId(u32 sectionId)
{
    if (sectionId >= KANTO_MAPSEC_START && sectionId < MAPSEC_SPECIAL_AREA)
        return REGION_KANTO;
    if (sectionId >= MAPSEC_ROUTE_1_SM && sectionId <= MAPSEC_AETHER_PARADISE_SM)
        return REGION_ALOLA;
    return REGION_HOENN;
}

static inline enum Region GetCurrentRegion(void)
{
    return GetRegionForSectionId(gMapHeader.regionMapSectionId);
}

#endif // GUARD_REGIONS_H
