#ifndef GUARD_DATA_CUTSCENE_H
#define GUARD_DATA_CUTSCENE_H

#include "global.h"
#include "constants/cutscene.h"
#include "constants/flags.h"
#include "cutscene.h"

// extern const u8 EventScript_ExampleCutsceneSkip[];
extern const u8 TapuKokoBridge_LillieCosmogSkip[];
extern const u8 TapuKokoBridge_BridgeShakeSkip[];

const struct CutsceneSkip sCutsceneSkipScripts[] =
{
    // Add entries like this:
    // [CUTSCENE_EXAMPLE] =
    // {
    //     .scriptCutsceneSkipPtr = EventScript_ExampleCutsceneSkip,
    //     .flag = FLAG_SEEN_CUTSCENE_EXAMPLE,  // Omit if CUTSCENE_FLAG_TRACKING is FALSE
    // },
    [CUTSCENE_TAPUKOKO_BRIDGE] =
    {
        .scriptCutsceneSkipPtr = TapuKokoBridge_LillieCosmogSkip,
    },
    [CUTSCENE_TAPUKOKO_BRIDGE_SHAKE] =
    {
        .scriptCutsceneSkipPtr = TapuKokoBridge_BridgeShakeSkip,
    },
};

#endif // GUARD_DATA_CUTSCENE_H
