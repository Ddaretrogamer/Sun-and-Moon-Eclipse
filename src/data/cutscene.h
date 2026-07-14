#ifndef GUARD_DATA_CUTSCENE_H
#define GUARD_DATA_CUTSCENE_H

#include "global.h"
#include "constants/cutscene.h"
#include "constants/flags.h"
#include "cutscene.h"

// extern const u8 EventScript_ExampleCutsceneSkip[];
extern const u8 TapuKokoBridge_LillieCosmogSkip[];
extern const u8 TapuKokoBridge_BridgeShakeSkip[];
extern const u8 Ikitown_GetPokedexSkip[];
extern const u8 Ikitown_trigger_GiveHalaSparklingStoneSkip[];
extern const u8 PlayerHouse_ShowMomPokemonSkip[];
extern const u8 IkiTown_Trigger_HauGetStarterSkip[];
extern const u8 Route1NN_Trigger_GetStartersSkip[];
extern const u8 Route1NN_Trigger_GetStartersSkipPart2[];
extern const u8 Ikitown_trigger_WecomeToIkitownSkip[];
extern const u8 Ikitown_Trigger_UltraReconIntroSkip[];
extern const u8 Ikitown_Trigger_FestivalBattleSkip1[];
extern const u8 Ikitown_Trigger_FestivalBattleSkip2[];
extern const u8 Ikitown_Trigger_FestivalBattleSkip3[];
extern const u8 Ikitown_Trigger_FestivalBattleSkip4[];
extern const u8 Lillie_WalktoLabSkip[];
extern const u8 HauoliOutskirts_LillieOutsideLabSkip[];
extern const u8 AlolaLaboratory_FirstTimeIntroSkip[];

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
    [CUTSCENE_IKITOWN_GET_POKEDEX] =
    {
        .scriptCutsceneSkipPtr = Ikitown_GetPokedexSkip,
    },
    [CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE] =
    {
        .scriptCutsceneSkipPtr = Ikitown_trigger_GiveHalaSparklingStoneSkip,
    },
    [CUTSCENE_PLAYERHOUSE_SHOW_MOM_POKEMON] =
    {
        .scriptCutsceneSkipPtr = PlayerHouse_ShowMomPokemonSkip,
    },
    [CUTSCENE_HAU_GET_STARTER] =
    {
        .scriptCutsceneSkipPtr = IkiTown_Trigger_HauGetStarterSkip,
    },
    [CUTSCENE_PLAYER_GET_STARTER] =
    {
        .scriptCutsceneSkipPtr = Route1NN_Trigger_GetStartersSkip,
    },
    [CUTSCENE_KUKUI_POINTS_TO_IKI] =
    {
        .scriptCutsceneSkipPtr = Route1NN_Trigger_GetStartersSkipPart2,
    },
    [CUTSCENE_WELCOME_TO_IKITOWN] =
    {
        .scriptCutsceneSkipPtr = Ikitown_trigger_WecomeToIkitownSkip,
    },
    [CUTSCENE_ULTRARECON_INTRO] =
    {
        .scriptCutsceneSkipPtr = Ikitown_Trigger_UltraReconIntroSkip,
    },
    [CUTSCENE_IKITOWN_FESTIVAL_BATTLE_1] =
    {
        .scriptCutsceneSkipPtr = Ikitown_Trigger_FestivalBattleSkip1,
    },
    [CUTSCENE_IKITOWN_FESTIVAL_BATTLE_2] =
    {
        .scriptCutsceneSkipPtr = Ikitown_Trigger_FestivalBattleSkip2,
    },
    [CUTSCENE_IKITOWN_FESTIVAL_BATTLE_3] =
    {
        .scriptCutsceneSkipPtr = Ikitown_Trigger_FestivalBattleSkip3,
    },
    [CUTSCENE_IKITOWN_FESTIVAL_BATTLE_4] =
    {
        .scriptCutsceneSkipPtr = Ikitown_Trigger_FestivalBattleSkip4,
    },
    [CUTSCENE_ROUTE1_LILLIE_WALK_TO_LAB] =
    {
        .scriptCutsceneSkipPtr = Lillie_WalktoLabSkip,
    },
    [CUTSCENE_HAUOLI_OUTSKIRTS_LILLIE_OUTSIDE_LAB] =
    {
        .scriptCutsceneSkipPtr = HauoliOutskirts_LillieOutsideLabSkip,
    },
    [CUTSCENE_ALOLA_LABORATORY_FIRST_TIME_INTRO] =
    {
        .scriptCutsceneSkipPtr = AlolaLaboratory_FirstTimeIntroSkip,
    },
};

#endif // GUARD_DATA_CUTSCENE_H
