#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_anim.h"
#include "frontier_util.h"
#include "battle_message.h"
#include "battle_tent.h"
#include "battle_factory.h"
#include "bg.h"
#include "swsh_summary_screen.h"
#include "contest.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "egg_hatch.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "link.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mon_markings.h"
#include "move_relearner.h"
#include "naming_screen.h"
#include "party_menu.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokemon_sprite_visualizer.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_move_effects.h"
#include "constants/characters.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#if SWSH_SUMMARY_SCREEN == TRUE
enum SWSHPSSEffect
{
    PSS_EFFECT_BATTLE,
    PSS_EFFECT_COUNT 
};

enum SWSHSkillsPageState
{
    SKILL_STATE_STATS,
    SKILL_STATE_IVS,
    SKILL_STATE_EVS,
};

#define PSS_BUFFER_SIZE 0x400

// Screen titles (upper left)
#define PSS_LABEL_WINDOW_POKEMON_INFO_TITLE 0
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE 1
#define PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE 2

// Button control text (upper right)
#define PSS_LABEL_WINDOW_PROMPT_CANCEL 4 // Also handles the "rename" prompt if P_SUMMARY_SCREEN_RENAME is true
#define PSS_LABEL_WINDOW_PROMPT_SWITCH 5

// Info screen
#define PSS_LABEL_WINDOW_POKEMON_INFO_TYPE 6

// Skills screen
#define PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP 7 // EXP Next Level

// Moves screen
#define PSS_LABEL_WINDOW_MOVES_POWER_ACC 8 // Also contains the power and accuracy values

// Above/below the pokemon's portrait (right)
#define PSS_LABEL_WINDOW_PORTRAIT_INFO 9

// additional button prompts for IVs and EVs
#define PSS_LABEL_WINDOW_PROMPT_IVS 10
#define PSS_LABEL_WINDOW_PROMPT_EVS 11
#define PSS_LABEL_WINDOW_PROMPT_STATS 12

#define PSS_LABEL_WINDOW_END 13

// Dynamic fields for the Pokémon Info page
#define PSS_DATA_WINDOW_INFO_ITEM 0
#define PSS_DATA_WINDOW_INFO_SPECIES 1
#define PSS_DATA_WINDOW_INFO_MEMO 2
// #define PSS_DATA_WINDOW_INFO_OT_OTID 3

// Dynamic fields for the Pokémon Skills page
#define PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT 0 //ravetodo handle ribbons
#define PSS_DATA_WINDOW_SKILLS_STATS 1
#define PSS_DATA_WINDOW_EXP 2 // Exp
#define PSS_DATA_WINDOW_EXP_NEXT_LEVEL 3 // Exp next level
#define PSS_DATA_WINDOW_SKILLS_ABILITY 4

// Dynamic fields for the Battle Moves page
#define PSS_DATA_WINDOW_MOVE_NAMES_PP 0
#define PSS_DATA_WINDOW_MOVE_DESCRIPTION 1

#define MOVE_SELECTOR_SPRITES_COUNT 10
#define HELD_ITEM_BOX_SPRITES_COUNT 5
#define TYPE_ICON_SPRITE_COUNT (MAX_MON_MOVES + 1)

// Default font, see PrintTextOnWindow
#define PSS_DEFAULT_FONT FONT_SHORT_NARROW
// for the spriteIds field in PokemonSummaryScreenData
enum SwShSummarySprites
{
    SPRITE_ARR_ID_MON,
    SPRITE_ARR_ID_SHADOW,
    SPRITE_ARR_ID_BALL,
    SPRITE_ARR_ID_STATUS,
    SPRITE_ARR_ID_GENDER,
    SPRITE_ARR_ID_GIGANTAMAX,
    // all sprites below are considered "page-specific" and will be hidden when switching pages
    SPRITE_ARR_ID_POKERUS_CURED,
    SPRITE_ARR_ID_ITEM,
    SPRITE_ARR_ID_SHINY,
    SPRITE_ARR_ID_FRIENDSHIP,
    SPRITE_ARR_ID_CATEGORY,
    SPRITE_ARR_ID_HP_GRADE,
    SPRITE_ARR_ID_ATK_GRADE,
    SPRITE_ARR_ID_DEF_GRADE,
    SPRITE_ARR_ID_SPA_GRADE,
    SPRITE_ARR_ID_SPD_GRADE,
    SPRITE_ARR_ID_SPE_GRADE,
    SPRITE_ARR_ID_RELEARN_PROMPT,
    SPRITE_ARR_ID_INFO_PROMPT,
    SPRITE_ARR_ID_TERA_TYPE,
    SPRITE_ARR_ID_TYPE, // 2 for mon types, 5 for move types(4 moves and 1 to learn), used interchangeably, because mon types and move types aren't shown on the same screen
    SPRITE_ARR_ID_MOVE_SELECTOR1 = SPRITE_ARR_ID_TYPE + TYPE_ICON_SPRITE_COUNT, // 10 sprites that make up the selector
    SPRITE_ARR_ID_MOVE_SELECTOR2 = SPRITE_ARR_ID_MOVE_SELECTOR1 + MOVE_SELECTOR_SPRITES_COUNT,
    SPRITE_ARR_ID_HELD_ITEM_BOX = SPRITE_ARR_ID_MOVE_SELECTOR2 + MOVE_SELECTOR_SPRITES_COUNT,
    SPRITE_ARR_ID_COUNT = SPRITE_ARR_ID_HELD_ITEM_BOX + HELD_ITEM_BOX_SPRITES_COUNT
};

static EWRAM_DATA struct PokemonSummaryScreenData
{
    /*0x00*/ union {
        struct Pokemon *mons;
        struct BoxPokemon *boxMons;
    } monList;
    /*0x04*/ MainCallback callback;
    /*0x08*/ struct Sprite *markingsSprite;
    /*0x0C*/ struct Pokemon currentMon;
    /*0x70*/ struct PokeSummary
    {
        u16 species; // 0x0
        u16 species2; // 0x2
        u8 isEgg:1; // 0x4
        u8 isShiny:1;
        u8 padding:6;
        u8 level; // 0x5
        u8 ribbonCount; // 0x6
        u8 ailment; // 0x7
        u8 abilityNum; // 0x8
        u8 metLocation; // 0x9
        u8 metLevel; // 0xA
        u8 metGame; // 0xB
        u32 pid; // 0xC
        u32 exp; // 0x10
        u16 moves[MAX_MON_MOVES]; // 0x14
        u8 pp[MAX_MON_MOVES]; // 0x1C
        u16 currentHP; // 0x20
        u16 maxHP; // 0x22
        u16 atk; // 0x24
        u16 def; // 0x26
        u16 spatk; // 0x28
        u16 spdef; // 0x2A
        u16 speed; // 0x2C
        u16 item; // 0x2E
        u16 friendship; // 0x30
        u8 OTGender; // 0x32
        u8 nature; // 0x33
        u8 ppBonuses; // 0x34
        u8 sanity; // 0x35
        u8 OTName[17]; // 0x36
        u32 OTID; // 0x48  
        u8 teraType;
        u8 mintNature;
        u8 ivHp;
        u8 ivAtk;
        u8 ivDef;
        u8 ivSpatk;
        u8 ivSpdef;
        u8 ivSpeed;
        u8 evHp;
        u8 evAtk;
        u8 evDef;
        u8 evSpatk;
        u8 evSpdef;
        u8 evSpeed; // 0x56
    } summary;
    u16 bg3TilemapBuffers[PSS_BUFFER_SIZE];
    u16 bg2TilemapBuffers[PSS_PAGE_COUNT][PSS_BUFFER_SIZE];
    u16 bg1TilemapBuffers[PSS_EFFECT_COUNT][PSS_BUFFER_SIZE];
    u8 mode;
    bool8 isBoxMon;
    u8 curMonIndex;
    u8 maxMonIndex;
    u8 currPageIndex;
    u8 minPageIndex;
    u8 maxPageIndex;
    bool8 lockMonFlag; // This is used to prevent the player from changing Pokémon in the move deleter select, etc, but it is not needed because the input is handled differently there
    u16 newMove;
    u8 firstMoveIndex;
    u8 secondMoveIndex;
    bool8 lockMovesFlag; // This is used to prevent the player from changing position of moves in a battle or when trading.
    u8 bgDisplayOrder; // unused
    u8 relearnableMovesNum;
    u8 windowIds[8];
    u8 spriteIds[SPRITE_ARR_ID_COUNT];
    bool8 handleDeoxys;
    s16 switchCounter; // Used for various switch statement cases that decompress/load graphics or Pokémon data
    u16 monAnimTimer; // tracks time between re-playing mon anims
    bool8 monAnimPlayed; // tracks if anim has been played at least once
    u8 unk_filler4[2];
} *sMonSummaryScreen = NULL;

static EWRAM_DATA u8 sMoveSlotToReplace = 0;
ALIGNED(4) static EWRAM_DATA u8 sAnimDelayTaskId = 0;
ALIGNED(4) static EWRAM_DATA u8 sShadowAnimDelayTaskId = 0;
static EWRAM_DATA u8 sStringVar5[8] = {0};
EWRAM_DATA u8 gOriginSummaryScreenPage = 0;

// forward declarations
static bool8 LoadGraphics(void);
static void CB2_InitSummaryScreen(void);
static void InitBGs(void);
static bool8 DecompressGraphics(void);
static void CopyMonToSummaryStruct(struct Pokemon *);
static bool8 ExtractMonDataToSummaryStruct(struct Pokemon *);
static void SetSelectMoveTilemaps(void);
static void CloseSummaryScreen(u8);
static void Task_HandleInput(u8);
static void ChangeSummaryPokemon(u8, s8);
static void Task_ChangeSummaryMon(u8);
static s8 AdvanceMonIndex(s8);
static s8 AdvanceMultiBattleMonIndex(s8);
static bool8 IsValidToViewInMulti(struct Pokemon *);
static void ChangePage(u8, s8);
static void PssScroll(u8);
static void PssScrollEnd(u8);
static void TryDrawExperienceProgressBar(void);
static void SwitchToMoveSelection(u8);
static void Task_HandleInput_MoveSelect(u8);
static bool8 HasMoreThanOneMove(void);
static void ChangeSelectedMove(s16 *, s8, u8 *);
static void CloseMoveSelectMode(u8);
static void SwitchToMovePositionSwitchMode(u8);
static void Task_HandleInput_MovePositionSwitch(u8);
static void ExitMovePositionSwitchMode(u8, bool8);
static void SwapMonMoves(struct Pokemon *, u8, u8);
static void SwapBoxMonMoves(struct BoxPokemon *, u8, u8);
static void Task_SetHandleReplaceMoveInput(u8);
static void Task_HandleReplaceMoveInput(u8);
static bool8 CanReplaceMove(void);
static void ShowCantForgetHMsWindow(u8);
static void Task_HandleInputCantForgetHMsMoves(u8);
static void DrawExperienceProgressBar(struct Pokemon *);
static void ResetWindows(void);
static void PrintMonPortraitInfo(void);
static void PrintNotEggInfo(void);
static void PrintEggInfo(void);
static void PrintEggStepsRemaining(void);
static void LoadGenderGfx(void);
static void CreateGenderSprite(struct Pokemon *mon, u16 species);
static void CreateGigantamaxSprite(void);
// static void PrintGenderSymbol(struct Pokemon *, u16);
static void PrintPageNamesAndStats(void);
static void PutPageWindowTilemaps(u8);
static void ClearPageWindowTilemaps(u8);
static void RemoveWindowByIndex(u8);
static void PrintPageSpecificText(u8);
static void CreateTextPrinterTask(u8);
static void PrintInfoPageText(void);
static void Task_PrintInfoPage(u8);
static void PrintMonOTName(void);
static void PrintMonOTID(void);
static void PrintMonNature(void);
static void PrintMonDexNumberSpecies(void);
static void PrintMonAbilityName(void);
static void PrintMonAbilityDescription(void);
static void BufferMonTrainerMemo(void);
static void PrintMonTrainerMemo(void);
static void BufferNatureString(void);
static void GetMetLevelString(u8 *);
static bool8 DoesMonOTMatchOwner(void);
static bool8 DidMonComeFromGBAGames(void);
static bool8 IsInGamePartnerMon(void);
static void PrintEggOTName(void);
static void PrintEggOTID(void);
static void PrintEggState(void);
static void PrintEggMemo(void);
static void Task_PrintSkillsPage(u8);
static void PrintHeldItemInfo(void);
static void PrintSkillsPageText(void);
static void PrintRibbonCount(void);
static void PrintStatLabels(void);
static void PrintColoredStatLabel(u8, s8, const u8*, u8, u8, u8, u8, u8*);
static void BufferHPStats(void);
static void PrintHPStats(u8);
static void BufferNonHPStats(void);
static void PrintNonHPStats(void);
static void PrintExpPointsNextLevel(void);
static void PrintBattleMoves(void);
static void Task_PrintBattleMoves(u8);
static void PrintMoveNameAndPP(u8);
static void PrintMoveDescription(u16);
static void PrintNewMoveDetailsOrCancelText(void);
static void SwapMovesNamesPP(u8, u8);
static void PrintHMMovesCantBeForgotten(void);
static void ResetSpriteIds(void);
static void SetSpriteInvisibility(u8, bool8);
static void HidePageSpecificSprites(void);
static void SetTypeIcons(void);
static void CreateMoveTypeIcons(void);
static void SetMonTypeIcons(void);
static void SetMoveTypeIcons(void);
static void SetNewMoveTypeIcon(void);
static void SwapMovesTypeSprites(u8, u8);
static u8 LoadMonGfxAndSprite(struct Pokemon *, s16 *, bool32);
static u8 CreateMonSprite(struct Pokemon *, bool32);
static void SpriteCB_Pokemon(struct Sprite *);
static void StopPokemonAnimations(void);
static void CreateMonMarkingsSprite(struct Pokemon *);
static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *);
static void CreateCaughtBallSprite(struct Pokemon *);
static void CreateHeldItemBoxSprites(void);
static void DestroyHeldItemBoxSprites(void);
static void CreateHeldItemSprite(void);
static void DestroyHeldItemIconSprite(void);
static void CreateStatusSprite(void);
static void CreateMoveSelectorSprites(u8);
static void SpriteCB_MoveSelector(struct Sprite *);
static void DestroyMoveSelectorSprites(u8);
static void SetMainMoveSelectorColor(u8);
static void KeepMoveSelectorVisible(u8);
static void SummaryScreen_DestroyAnimDelayTask(void);
static void SetShinySprite(void);
static void SetPokerusCuredSprite(void);
static void HandleStatusSprite(struct Pokemon *);
static u8 AddWindowFromTemplateList(const struct WindowTemplate*, u8);
static void ClearCancelText(void);
static bool32 ShouldRemoveHyphen(const u8*, const u8*, const u8*);
static u8 FormatTextByWidth(u8*, s32, u8, const u8*, s16);
static void Task_ShowEffectTilemap(u8);
static void Task_HideEffectTilemap(u8);
static void ShowCategoryIcon(u16);
static void DestroyCategoryIcon(void);
static void ChangeSummaryState(s16*, u8);
static void DrawNextSkillsButtonPrompt(u8);
static void BufferAndPrintStats_HandleState(u8);
static void SetFriendshipSprite(void);
static void TrySetInfoPageIcons(void);
static void RunMonAnimTimer(void);
static bool32 ShouldShowMoveRelearner(void);
static void ShowMoveRelearner(void);
static void HideMoveRelearner(void);
static void ShowInfoPrompt(void);
static void HideInfoPrompt(void);
static bool32 ShouldShowRename(void);
static void ShowCancelOrRenamePrompt(void);
static void CB2_ReturnToSummaryScreenFromNamingScreen(void);
static void CB2_PssChangePokemonNickname(void);

// const rom data

static const u8 sMemoNatureTextColor[]              = _("{COLOR DYNAMIC_COLOR2}{SHADOW DYNAMIC_COLOR3}");
static const u8 sMemoMiscTextColor[]                = _("{COLOR WHITE}{SHADOW DARK_GRAY}");
static const u8 sStatsHPLayout[]                    = _("{DYNAMIC 0}/{DYNAMIC 1}");
static const u8 sStatsHPIVEVLayout[]                = _("{DYNAMIC 0}");
static const u8 sStatsNonHPLayout[]                 = _("{DYNAMIC 0}\n{DYNAMIC 1}\n{DYNAMIC 2}\n{DYNAMIC 3}\n{DYNAMIC 4}");
static const u8 sMovesPPLayout[]                    = _("{DYNAMIC 0}/{DYNAMIC 1}");
static const u8 sEggStepsLayout[]                   = _("{DYNAMIC 0} steps");

static const u8 sText_Empty[]                       = _("");
static const u8 sText_Cancel[]                      = _("Cancel");
static const u8 sText_Switch[]                      = _("Switch");
static const u8 sText_Rename[]                      = _("Rename");
static const u8 sText_Lv[]                          = _("Lv.");
static const u8 sText_HP_Title[]                    = _("HP");
static const u8 sText_Attack_Title[]                = _("Attack");
static const u8 sText_Defense_Title[]               = _("Defense");
static const u8 sText_SpAtk_Title[]                 = _("Sp. Atk");
static const u8 sText_SpDef_Title[]                 = _("Sp. Def");
static const u8 sText_Speed_Title[]                 = _("Speed");
static const u8 sText_ViewIVs[]                     = _("View IV");
static const u8 sText_ViewEVs[]                     = _("View EV");
static const u8 sText_ViewStats[]                   = _("View Stats");
static const u8 sText_Exp[]                         = _("Exp.");
static const u8 sText_NextLv[]                        = _("Next Lv.");
static const u8 sText_RentalPkmn[]                  = _("Rental Pokémon");
static const u8 sText_None[]                        = _("None");
static const u8 sText_Egg[]                         = _("Egg");

// bg gfx
const u32 sSummaryScreen_Gfx[]                      = INCBIN_U32("graphics/summary_screen/swsh/tiles.4bpp.lz");
const u16 sSummaryScreen_Pal[]                      = INCBIN_U16("graphics/summary_screen/swsh/tiles.gbapal");
const u32 sSummaryPage_ScrollBG_Tilemap[]           = INCBIN_U32("graphics/summary_screen/swsh/scroll_bg.bin.lz");
const u32 sSummaryPage_Info_Tilemap[]               = INCBIN_U32("graphics/summary_screen/swsh/page_info.bin.lz");
const u32 sSummaryPage_Skills_Tilemap[]             = INCBIN_U32("graphics/summary_screen/swsh/page_skills.bin.lz");
const u32 sSummaryPage_BattleMoves_Tilemap[]        = INCBIN_U32("graphics/summary_screen/swsh/page_battle_moves.bin.lz");
const u32 sSummaryEffect_Battle_Tilemap[]           = INCBIN_U32("graphics/summary_screen/swsh/effect_battle.bin.lz");
const u16 sSummaryScreen_PPTextPalette[]            = INCBIN_U16("graphics/summary_screen/swsh/text_pp.gbapal");

// sprite gfx
static const u8 sButtons_Gfx[][4 * TILE_SIZE_4BPP] = {
    INCBIN_U8("graphics/summary_screen/swsh/a_button.4bpp"),
    INCBIN_U8("graphics/summary_screen/swsh/b_button.4bpp"),
    INCBIN_U8("graphics/summary_screen/swsh/start_button.4bpp"),
};

#if SWSH_SUMMARY_SWSH_TYPE_ICONS == TRUE
    static const u32 sMoveTypes_Gfx[] = INCBIN_U32("graphics/types_swsh_summary_screen/move_types.4bpp.lz");
    #if SWSH_SUMMARY_SWSH_TYPE_ICONS_SV_PAL == TRUE
        static const u16 sMoveTypes_Pal[] = INCBIN_U16("graphics/types_swsh_summary_screen/move_types_sv.gbapal");
    #else
        static const u16 sMoveTypes_Pal[] = INCBIN_U16("graphics/types_swsh_summary_screen/move_types.gbapal");
    #endif
#endif
static const u32 sTeraTypes_Gfx[]                   = INCBIN_U32("graphics/types_swsh_summary_screen/tera/tera_types_swsh.4bpp.lz");
static const u32 sHeldItemBox_Gfx[]                 = INCBIN_U32("graphics/summary_screen/swsh/held_item_box.4bpp.lz");
static const u16 sHeldItemBox_Pal[]                 = INCBIN_U16("graphics/summary_screen/swsh/held_item_box.gbapal");
static const u32 sSummaryMoveSelect_Gfx[]           = INCBIN_U32("graphics/summary_screen/swsh/move_select.4bpp.lz");
static const u16 sSummaryMoveSelect_Pal[]           = INCBIN_U16("graphics/summary_screen/swsh/move_select.gbapal");
static const u16 sMarkings_Pal[]                    = INCBIN_U16("graphics/summary_screen/swsh/markings.gbapal");
static const u32 sShinyIcon_Gfx[]                   = INCBIN_U32("graphics/summary_screen/swsh/shiny_icon.4bpp.lz");
static const u32 sPokerusCuredIcon_Gfx[]            = INCBIN_U32("graphics/summary_screen/swsh/pokerus_cured_icon.4bpp.lz");
static const u32 sGenderGfx_Icons[]                 = INCBIN_U32("graphics/summary_screen/swsh/gender_icons.4bpp.lz");
static const u16 sGenderPal_Icons[]                 = INCBIN_U16("graphics/summary_screen/swsh/gender_icons.gbapal");
static const u16 sCategoryIcons_Pal[]               = INCBIN_U16("graphics/summary_screen/swsh/category_icons.gbapal");
static const u32 sCategoryIcons_Gfx[]               = INCBIN_U32("graphics/summary_screen/swsh/category_icons.4bpp.lz");
static const u16 sFriendshipIcon_Pal[]              = INCBIN_U16("graphics/summary_screen/swsh/heart.gbapal");
static const u32 sFriendshipIcon_Gfx[]              = INCBIN_U32("graphics/summary_screen/swsh/heart.4bpp.lz");
// rave note: yeah I know doing this with a sprite is mad jank, but I promise I have my reasons
// mont note: it is maaad jank, but it works, we promise
static const u32 sRelearnPrompt_Gfx[]               = INCBIN_U32("graphics/summary_screen/swsh/relearn_prompt.4bpp.lz");
static const u32 sInfoPrompt_Gfx[]                  = INCBIN_U32("graphics/summary_screen/swsh/info_prompt.4bpp.lz");
static const u32 sGigantamaxIcon_Gfx[]              = INCBIN_U32("graphics/summary_screen/swsh/gigantamax.4bpp.lz");

#if SWSH_SUMMARY_SWSH_STATUS_ICONS == TRUE
static const u32 sStatusGfx_Icons[]                 = INCBIN_U32("graphics/summary_screen/swsh/status_icons.4bpp.lz");
static const u16 sStatusPal_Icons[]                 = INCBIN_U16("graphics/summary_screen/swsh/status_icons.gbapal");
#endif


static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const s8 sMultiBattleOrder[] = {0, 2, 3, 1, 4, 5};
static const struct WindowTemplate sSummaryTemplate[] =
{
    [PSS_LABEL_WINDOW_POKEMON_INFO_TITLE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 11,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 1,
    },
    [PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 11,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 23,
    },
    [PSS_LABEL_WINDOW_PROMPT_CANCEL] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 18,
        .width = 9,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 67,
    },
    [PSS_LABEL_WINDOW_PROMPT_SWITCH] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 13,
        .width = 8,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 85,
    },
    [PSS_LABEL_WINDOW_POKEMON_INFO_TYPE] = {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 6,
        .width = 18,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 101,
    },
    [PSS_LABEL_WINDOW_MOVES_POWER_ACC] = {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 6,
        .height = 5,
        .paletteNum = 6,
        .baseBlock = 181,
    },
    [PSS_LABEL_WINDOW_PORTRAIT_INFO] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 1,
        .width = 13,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 211,
    },
    [PSS_LABEL_WINDOW_PROMPT_IVS] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 18,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 237,
    },
    [PSS_LABEL_WINDOW_PROMPT_EVS] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 18,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 257,
    },
    [PSS_LABEL_WINDOW_PROMPT_STATS] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 18,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 277,
    },
    // // Changed to print label inside PSS_DATA_WINDOW_EXP_NEXT_LEVEL
    // [PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP] = {
    //     .bg = 0,
    //     .tilemapLeft = 6,
    //     .tilemapTop = 10,
    //     .width = 11,
    //     .height = 4,
    //     .paletteNum = 6,
    //     .baseBlock = 137,
    // },
    [PSS_LABEL_WINDOW_END] = DUMMY_WIN_TEMPLATE
};
static const struct WindowTemplate sPageInfoTemplate[] =
{
    [PSS_DATA_WINDOW_INFO_ITEM] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 12,
        .width = 18,
        .height = 7,
        .paletteNum = 6,
        .baseBlock = 346,
    },
    [PSS_DATA_WINDOW_INFO_SPECIES] = {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 3,
        .width = 12,
        .height = 9,
        .paletteNum = 6,
        .baseBlock = 472,
    },
    [PSS_DATA_WINDOW_INFO_MEMO] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 26,
        .height = 7,
        .paletteNum = 6,
        .baseBlock = 580,
    },
    // [PSS_DATA_WINDOW_INFO_OT_OTID] = {
    //     .bg = 0,
    //     .tilemapLeft = 7,
    //     .tilemapTop = 8,
    //     .width = 12,
    //     .height = 2,
    //     .paletteNum = 6,
    //     .baseBlock = 472,
    // },
};
static const struct WindowTemplate sPageSkillsTemplate[] =
{
    [PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT] = { // currently unused
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 4,
        .width = 10,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 346,
    },
    [PSS_DATA_WINDOW_SKILLS_STATS] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 18,
        .height = 6,
        .paletteNum = 6,
        .baseBlock = 366,
    },
    [PSS_DATA_WINDOW_EXP] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 10,
        .width = 18,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 474,
    },
    [PSS_DATA_WINDOW_SKILLS_ABILITY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 18,
        .height = 5,
        .paletteNum = 6,
        .baseBlock = 510,
    },
    // [PSS_DATA_WINDOW_EXP_NEXT_LEVEL] = {
    //     .bg = 0,
    //     .tilemapLeft = 15,
    //     .tilemapTop = 10,
    //     .width = 4,
    //     .height = 2,
    //     .paletteNum = 6,
    //     .baseBlock = 492,
    // },
};
static const struct WindowTemplate sPageMovesTemplate[] = // This is used for both battle moves
{
    [PSS_DATA_WINDOW_MOVE_NAMES_PP] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 19,
        .height = 12,
        .paletteNum = 8,
        .baseBlock = 346,
    },
    [PSS_DATA_WINDOW_MOVE_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 15,
        .width = 18,
        .height = 5,
        .paletteNum = 6,
        .baseBlock = 574,
    },
};
static const u8 sTextColors[][3] =
{
    {0, 1, 2},
    {0, 3, 4},
    {0, 5, 6},
    {0, 7, 8},
    {0, 9, 10},
    {0, 11, 12},
    {0, 13, 14},
    {0, 7, 8},
    {13, 15, 14},
    {0, 1, 2},
    {0, 3, 4},
    {0, 5, 6},
    {0, 7, 8},
};

static void (*const sTextPrinterFunctions[])(void) =
{
    [PSS_PAGE_INFO] = PrintInfoPageText,
    [PSS_PAGE_SKILLS] = PrintSkillsPageText,
    [PSS_PAGE_BATTLE_MOVES] = PrintBattleMoves,
};

static void (*const sTextPrinterTasks[])(u8 taskId) =
{
    [PSS_PAGE_INFO] = Task_PrintInfoPage,
    [PSS_PAGE_SKILLS] = Task_PrintSkillsPage,
    [PSS_PAGE_BATTLE_MOVES] = Task_PrintBattleMoves,
};

#define TAG_MOVE_SELECTOR 30000
#define TAG_MON_STATUS 30001
#define TAG_MOVE_TYPES 30002
#define TAG_MON_MARKINGS 30003
#define TAG_MON_SHINY_ICON 30004
#define TAG_MON_POKERUS_CURED_ICON 30005
#define TAG_CATEGORY_ICONS 30006
#define TAG_STAT_GRADES 30007
#define TAG_FRIENDSHIP_ICON 30008
#define TAG_GIGANTAMAX_ICON 30009
#define TAG_TERA_TYPE 30010
#define TAG_MON_SHADOW 30011
#define TAG_RELEARN_PROMPT 30012
#define TAG_INFO_PROMPT 30013
#define TAG_GENDER_ICON 30014
#define TAG_HELD_ITEM_BOX 30015
#define TAG_HELD_ITEM_ICON 30016

enum SwShCategoryIcon
{
    CATEGORY_ICON_PHYSICAL,
    CATEGORY_ICON_SPECIAL,
    CATEGORY_ICON_STATUS,
};

static const struct OamData sOamData_CategoryIcons =
{
    .size = SPRITE_SIZE(32x16),
    .shape = SPRITE_SHAPE(32x16),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_CategoryIcons =
{
    .data = sCategoryIcons_Gfx,
    .size = 32*16*3/2,
    .tag = TAG_CATEGORY_ICONS,
};

static const struct SpritePalette sSpritePal_CategoryIcons =
{
    .data = sCategoryIcons_Pal,
    .tag = TAG_CATEGORY_ICONS
};

static const union AnimCmd sSpriteAnim_CategoryPhysical[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategorySpecial[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategoryStatus[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_CategoryIcons[] =
{
    [CATEGORY_ICON_PHYSICAL] = sSpriteAnim_CategoryPhysical,
    [CATEGORY_ICON_SPECIAL] = sSpriteAnim_CategorySpecial,
    [CATEGORY_ICON_STATUS] = sSpriteAnim_CategoryStatus,
};

static const struct SpriteTemplate sSpriteTemplate_CategoryIcons =
{
    .tileTag = TAG_CATEGORY_ICONS,
    .paletteTag = TAG_CATEGORY_ICONS,
    .oam = &sOamData_CategoryIcons,
    .anims = sSpriteAnimTable_CategoryIcons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_RelearnPrompt =
{
    .size = SPRITE_SIZE(64x32),
    .shape = SPRITE_SHAPE(64x32),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_RelearnPrompt =
{
    .data = sRelearnPrompt_Gfx,
    .size = 64*32/2,
    .tag = TAG_RELEARN_PROMPT,
};

static const struct SpriteTemplate sSpriteTemplate_RelearnPrompt =
{
    .tileTag = TAG_RELEARN_PROMPT,
    .paletteTag = TAG_MON_MARKINGS,
    .oam = &sOamData_RelearnPrompt,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_InfoPrompt =
{
    .size = SPRITE_SIZE(32x8),
    .shape = SPRITE_SHAPE(32x8),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_InfoPrompt =
{
    .data = sInfoPrompt_Gfx,
    .size = 32*8/2,
    .tag = TAG_INFO_PROMPT,
};

static const struct SpriteTemplate sSpriteTemplate_InfoPrompt =
{
    .tileTag = TAG_INFO_PROMPT,
    .paletteTag = TAG_MON_MARKINGS,
    .oam = &sOamData_InfoPrompt,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

enum FriendshipLevels
{
    FRIENDSHIP_LEVEL_0,
    FRIENDSHIP_LEVEL_1,
    FRIENDSHIP_LEVEL_2,
    FRIENDSHIP_LEVEL_3,
    FRIENDSHIP_LEVEL_4,
    FRIENDSHIP_LEVEL_5,
    FRIENDSHIP_LEVEL_MAX,
    FRIENDSHIP_LEVEL_COUNT,
};

// edit these to change what friendship value the heart icon changes at
static const u8 sFriendshipLevelToThreshold[FRIENDSHIP_LEVEL_COUNT] = 
{
    [FRIENDSHIP_LEVEL_0]    = 0,
    [FRIENDSHIP_LEVEL_1]    = 44,
    [FRIENDSHIP_LEVEL_2]    = 88,
    [FRIENDSHIP_LEVEL_3]    = 132,
    [FRIENDSHIP_LEVEL_4]    = 176,
    [FRIENDSHIP_LEVEL_5]    = 220,
    [FRIENDSHIP_LEVEL_MAX]  = MAX_FRIENDSHIP,
};

static const struct OamData sOamData_FriendshipIcon =
{
    .size = SPRITE_SIZE(8x8),
    .shape = SPRITE_SHAPE(8x8),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_FriendshipIcon =
{
    .data = sFriendshipIcon_Gfx,
    .size = FRIENDSHIP_LEVEL_COUNT * (8 * 8),
    .tag = TAG_FRIENDSHIP_ICON,
};

static const struct SpritePalette sSpritePal_FriendshipIcon =
{
    .data = sFriendshipIcon_Pal,
    .tag = TAG_FRIENDSHIP_ICON
};

static const union AnimCmd sSpriteAnim_FriendshipIcon0[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon1[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_1, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon2[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_2, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon3[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_3, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon4[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIcon5[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_5, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FriendshipIconMax[] = {
    ANIMCMD_FRAME(FRIENDSHIP_LEVEL_MAX, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_FriendshipIcon[FRIENDSHIP_LEVEL_COUNT] = {
    [FRIENDSHIP_LEVEL_0]    = sSpriteAnim_FriendshipIcon0,
    [FRIENDSHIP_LEVEL_1]    = sSpriteAnim_FriendshipIcon1,
    [FRIENDSHIP_LEVEL_2]    = sSpriteAnim_FriendshipIcon2,
    [FRIENDSHIP_LEVEL_3]    = sSpriteAnim_FriendshipIcon3,
    [FRIENDSHIP_LEVEL_4]    = sSpriteAnim_FriendshipIcon4,
    [FRIENDSHIP_LEVEL_5]    = sSpriteAnim_FriendshipIcon5,
    [FRIENDSHIP_LEVEL_MAX]  = sSpriteAnim_FriendshipIconMax,
};

static const struct SpriteTemplate sSpriteTemplate_FriendshipIcon =
{
    .tileTag = TAG_FRIENDSHIP_ICON,
    .paletteTag = TAG_FRIENDSHIP_ICON,
    .oam = &sOamData_FriendshipIcon,
    .anims = sSpriteAnimTable_FriendshipIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_MoveTypes =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_TypeNone[] = {
    ANIMCMD_FRAME(TYPE_NONE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFairy[] = {
    ANIMCMD_FRAME(TYPE_FAIRY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeStellar[] = {
    ANIMCMD_FRAME(TYPE_STELLAR * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};


static const union AnimCmd *const sSpriteAnimTable_MoveTypes[NUMBER_OF_MON_TYPES] = {
    [TYPE_NONE] = sSpriteAnim_TypeNone,
    [TYPE_NORMAL] = sSpriteAnim_TypeNormal,
    [TYPE_FIGHTING] = sSpriteAnim_TypeFighting,
    [TYPE_FLYING] = sSpriteAnim_TypeFlying,
    [TYPE_POISON] = sSpriteAnim_TypePoison,
    [TYPE_GROUND] = sSpriteAnim_TypeGround,
    [TYPE_ROCK] = sSpriteAnim_TypeRock,
    [TYPE_BUG] = sSpriteAnim_TypeBug,
    [TYPE_GHOST] = sSpriteAnim_TypeGhost,
    [TYPE_STEEL] = sSpriteAnim_TypeSteel,
    [TYPE_MYSTERY] = sSpriteAnim_TypeMystery,
    [TYPE_FIRE] = sSpriteAnim_TypeFire,
    [TYPE_WATER] = sSpriteAnim_TypeWater,
    [TYPE_GRASS] = sSpriteAnim_TypeGrass,
    [TYPE_ELECTRIC] = sSpriteAnim_TypeElectric,
    [TYPE_PSYCHIC] = sSpriteAnim_TypePsychic,
    [TYPE_ICE] = sSpriteAnim_TypeIce,
    [TYPE_DRAGON] = sSpriteAnim_TypeDragon,
    [TYPE_DARK] = sSpriteAnim_TypeDark,
    [TYPE_FAIRY] = sSpriteAnim_TypeFairy,
    [TYPE_STELLAR] = sSpriteAnim_TypeStellar,
};

static const struct CompressedSpriteSheet sSpriteSheet_MoveTypes =
{
#if SWSH_SUMMARY_SWSH_TYPE_ICONS == TRUE
    .data = sMoveTypes_Gfx,
#else
    .data = gMoveTypes_Gfx,
#endif
    .size = (NUMBER_OF_MON_TYPES) * 0x100,
    .tag = TAG_MOVE_TYPES
};

static const struct SpriteTemplate sSpriteTemplate_MoveTypes =
{
    .tileTag = TAG_MOVE_TYPES,
    .paletteTag = TAG_MOVE_TYPES,
    .oam = &sOamData_MoveTypes,
    .anims = sSpriteAnimTable_MoveTypes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const union AnimCmd sSpriteAnim_TeraTypeNone[] = {
    ANIMCMD_FRAME(TYPE_NONE * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeFairy[] = {
    ANIMCMD_FRAME(TYPE_FAIRY * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TeraTypeStellar[] = {
    ANIMCMD_FRAME(TYPE_STELLAR * 4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_TeraType[NUMBER_OF_MON_TYPES] = {
    [TYPE_NONE] = sSpriteAnim_TeraTypeNone,
    [TYPE_NORMAL] = sSpriteAnim_TeraTypeNormal,
    [TYPE_FIGHTING] = sSpriteAnim_TeraTypeFighting,
    [TYPE_FLYING] = sSpriteAnim_TeraTypeFlying,
    [TYPE_POISON] = sSpriteAnim_TeraTypePoison,
    [TYPE_GROUND] = sSpriteAnim_TeraTypeGround,
    [TYPE_ROCK] = sSpriteAnim_TeraTypeRock,
    [TYPE_BUG] = sSpriteAnim_TeraTypeBug,
    [TYPE_GHOST] = sSpriteAnim_TeraTypeGhost,
    [TYPE_STEEL] = sSpriteAnim_TeraTypeSteel,
    [TYPE_MYSTERY] = sSpriteAnim_TeraTypeMystery,
    [TYPE_FIRE] = sSpriteAnim_TeraTypeFire,
    [TYPE_WATER] = sSpriteAnim_TeraTypeWater,
    [TYPE_GRASS] = sSpriteAnim_TeraTypeGrass,
    [TYPE_ELECTRIC] = sSpriteAnim_TeraTypeElectric,
    [TYPE_PSYCHIC] = sSpriteAnim_TeraTypePsychic,
    [TYPE_ICE] = sSpriteAnim_TeraTypeIce,
    [TYPE_DRAGON] = sSpriteAnim_TeraTypeDragon,
    [TYPE_DARK] = sSpriteAnim_TeraTypeDark,
    [TYPE_FAIRY] = sSpriteAnim_TeraTypeFairy,
    [TYPE_STELLAR] = sSpriteAnim_TeraTypeStellar
};

static const struct OamData sOamData_TeraType =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_TeraType =
{
    .data = sTeraTypes_Gfx,
    .size = NUMBER_OF_MON_TYPES * (16 * 16),
    .tag = TAG_TERA_TYPE
};

static const struct SpriteTemplate sSpriteTemplate_TeraType =
{
    .tileTag = TAG_TERA_TYPE,
    .paletteTag = TAG_TERA_TYPE,
    .oam = &sOamData_TeraType,
    .anims = sSpriteAnimTable_TeraType,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_MoveSelector =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_MoveSelectorUnused0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorUnused1[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorUnused2[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorUnused3[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeft[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorMiddle[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRight[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeftAlt[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorMiddleAlt[] = {
    ANIMCMD_FRAME(40, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRightAlt[] = {
    ANIMCMD_FRAME(32, 0, FALSE, FALSE),
    ANIMCMD_END
};

// anims 0 - 3 are unused but be careful because
// removing them will mess up the StartAnim calls :)
static const union AnimCmd *const sSpriteAnimTable_MoveSelector[] = {
    sSpriteAnim_MoveSelectorUnused0,
    sSpriteAnim_MoveSelectorUnused1,
    sSpriteAnim_MoveSelectorUnused2,
    sSpriteAnim_MoveSelectorUnused3,
    sSpriteAnim_MoveSelectorLeft,
    sSpriteAnim_MoveSelectorRight,
    sSpriteAnim_MoveSelectorMiddle,
    sSpriteAnim_MoveSelectorLeftAlt,
    sSpriteAnim_MoveSelectorMiddleAlt,
    sSpriteAnim_MoveSelectorRightAlt,
};

static const struct CompressedSpriteSheet sMoveSelectorSpriteSheet =
{
    .data = sSummaryMoveSelect_Gfx,
    .size = 16*192/2,
    .tag = TAG_MOVE_SELECTOR
};

static const struct SpritePalette sMoveSelectorSpritePal =
{
    .data = sSummaryMoveSelect_Pal,
    .tag = TAG_MOVE_SELECTOR
};

static const struct SpriteTemplate sMoveSelectorSpriteTemplate =
{
    .tileTag = TAG_MOVE_SELECTOR,
    .paletteTag = TAG_MOVE_SELECTOR,
    .oam = &sOamData_MoveSelector,
    .anims = sSpriteAnimTable_MoveSelector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_HeldItemBox =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .size = SPRITE_SIZE(32x64),
    .x = 0,
    .matrixNum = 0,
    .shape = SPRITE_SHAPE(32x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

// Animations
static const union AnimCmd sSpriteAnim_HeldItemBoxLeft[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),  // First 32x64 frame (tiles 0-31)
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_HeldItemBoxLeftMiddle[] = {
    ANIMCMD_FRAME(32, 0, FALSE, FALSE),  // Second 32x64 frame (tiles 32-63)
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_HeldItemBoxRepeating[] = {
    ANIMCMD_FRAME(64, 0, FALSE, FALSE),  // Third 32x64 frame (tiles 64-95)
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_HeldItemBox[] = {
    sSpriteAnim_HeldItemBoxLeft,
    sSpriteAnim_HeldItemBoxLeftMiddle,
    sSpriteAnim_HeldItemBoxRepeating,
};

static const struct CompressedSpriteSheet sSpriteSheet_HeldItemBox =
{
    .data = sHeldItemBox_Gfx,
    .size = (32 * 64 * 3) / 2,  // 3072 bytes (only need 3 unique tiles)
    .tag = TAG_HELD_ITEM_BOX,
};

static const struct SpritePalette sSpritePal_HeldItemBox =
{
    .data = sHeldItemBox_Pal,
    .tag = TAG_HELD_ITEM_BOX,
};

static const struct SpriteTemplate sSpriteTemplate_HeldItemBox =
{
    .tileTag = TAG_HELD_ITEM_BOX,
    .paletteTag = TAG_HELD_ITEM_BOX,
    .oam = &sOamData_HeldItemBox,
    .anims = sSpriteAnimTable_HeldItemBox,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_StatusPoison[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusSleep[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrozen[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBurn[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusPokerus[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFaint[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrostbite[] = {
    ANIMCMD_FRAME(28, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_StatusCondition[] = {
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
    sSpriteAnim_StatusFrostbite,
};


static const struct CompressedSpriteSheet sStatusIconsSpriteSheet =
{
#if SWSH_SUMMARY_SWSH_STATUS_ICONS == TRUE
    .data = sStatusGfx_Icons,
#else
    .data = gStatusGfx_Icons,
#endif
    .size = 0x400,
    .tag = TAG_MON_STATUS
};

static const struct SpritePalette sStatusIconsSpritePalette =
{
#if SWSH_SUMMARY_SWSH_STATUS_ICONS == TRUE
    .data = sStatusPal_Icons,
#else
    .data = gStatusPal_Icons,
#endif
    .tag = TAG_MON_STATUS
};

static const struct SpriteTemplate sSpriteTemplate_StatusCondition =
{
    .tileTag = TAG_MON_STATUS,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteAnimTable_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_Gender =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_Female[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Male[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Gender[] = {
    sSpriteAnim_Female,
    sSpriteAnim_Male,
};

static const struct CompressedSpriteSheet sGenderIconsSpriteSheet =
{
    .data = sGenderGfx_Icons,
    .size = 0x200,
    .tag = TAG_GENDER_ICON
};

static const struct SpritePalette sGenderIconsSpritePalette =
{
    .data = sGenderPal_Icons,
    .tag = TAG_GENDER_ICON
};

static const struct SpriteTemplate sSpriteTemplate_Gender =
{
    .tileTag = TAG_GENDER_ICON,
    .paletteTag = TAG_GENDER_ICON,
    .oam = &sOamData_Gender,
    .anims = sSpriteAnimTable_Gender,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_ShinyIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sShinyIconSpriteSheet =
{
    .data = sShinyIcon_Gfx,
    .size = 8*8/2,
    .tag = TAG_MON_SHINY_ICON
};

static const struct SpriteTemplate sSpriteTemplate_ShinyIcon =
{
    .tileTag = TAG_MON_SHINY_ICON,
    .paletteTag = TAG_MON_MARKINGS,
    .oam = &sOamData_ShinyIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_GigantamaxIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sGigantamaxIconSpriteSheet =
{
    .data = sGigantamaxIcon_Gfx,
    .size = (16*16)/2,
    .tag = TAG_GIGANTAMAX_ICON
};

static const struct SpriteTemplate sSpriteTemplate_GigantamaxIcon =
{
    .tileTag = TAG_GIGANTAMAX_ICON,
    .paletteTag = TAG_GENDER_ICON,
    .oam = &sOamData_GigantamaxIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_PokerusCuredIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sPokerusCuredIconSpriteSheet =
{
    .data = sPokerusCuredIcon_Gfx,
    .size = 8*8,
    .tag = TAG_MON_POKERUS_CURED_ICON
};

static const struct SpriteTemplate sSpriteTemplate_PokerusCuredIcon =
{
    .tileTag = TAG_MON_POKERUS_CURED_ICON,
    .paletteTag = TAG_MON_MARKINGS,
    .oam = &sOamData_PokerusCuredIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u16 sMonShadowPalette[] = INCBIN_U16("graphics/summary_screen/swsh/shadow.gbapal");

static const struct SpritePalette sSpritePal_MonShadow =
{
    sMonShadowPalette, TAG_MON_SHADOW
};

// code
void ShowPokemonSummaryScreen_SwSh(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    u8 pageCount = PSS_PAGE_COUNT - 1;

    sMonSummaryScreen = AllocZeroed(sizeof(*sMonSummaryScreen));
    sMonSummaryScreen->mode = mode;
    sMonSummaryScreen->monList.mons = mons;
    sMonSummaryScreen->curMonIndex = monIndex;
    sMonSummaryScreen->maxMonIndex = maxMonIndex;
    sMonSummaryScreen->callback = callback;
    if (gInitialSummaryScreenCallback == NULL)
        gInitialSummaryScreenCallback = callback;

    if (mode == SUMMARY_MODE_BOX)
        sMonSummaryScreen->isBoxMon = TRUE;
    else
        sMonSummaryScreen->isBoxMon = FALSE;

    switch (mode)
    {
    case SUMMARY_MODE_NORMAL:
    case SUMMARY_MODE_BOX:
    case SUMMARY_MODE_BOX_CURSOR:
    case SUMMARY_MODE_RELEARNER_BATTLE:
        sMonSummaryScreen->minPageIndex = 0;
        sMonSummaryScreen->maxPageIndex = pageCount - 1;
        break;
    case SUMMARY_MODE_LOCK_MOVES:
        sMonSummaryScreen->minPageIndex = 0;
        sMonSummaryScreen->maxPageIndex = pageCount - 1;
        sMonSummaryScreen->lockMovesFlag = TRUE;
        break;
    case SUMMARY_MODE_SELECT_MOVE:
        sMonSummaryScreen->minPageIndex = PSS_PAGE_BATTLE_MOVES;
        sMonSummaryScreen->maxPageIndex = pageCount - 1;
        sMonSummaryScreen->lockMonFlag = TRUE;
        break;
    }

    if (mode == SUMMARY_MODE_RELEARNER_BATTLE)
        sMonSummaryScreen->currPageIndex = PSS_PAGE_BATTLE_MOVES;
    else
        sMonSummaryScreen->currPageIndex = sMonSummaryScreen->minPageIndex;

    SummaryScreen_SetAnimDelayTaskId_SwSh(TASK_NONE);
    SummaryScreen_SetShadowAnimDelayTaskId_SwSh(TASK_NONE);

    if (gMonSpritesGfxPtr == NULL)
        CreateMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A, MON_SPR_GFX_MODE_NORMAL);

    SetMainCallback2(CB2_InitSummaryScreen);
}

void ShowSelectMovePokemonSummaryScreen_SwSh(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove)
{
    ShowPokemonSummaryScreen_SwSh(SUMMARY_MODE_SELECT_MOVE, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->newMove = newMove;
}

void ShowPokemonSummaryScreenHandleDeoxys_SwSh(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    ShowPokemonSummaryScreen_SwSh(mode, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->handleDeoxys = TRUE;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    if (SWSH_SUMMARY_SCROLLING_BG)
    {
        ChangeBgX(3, 64, BG_COORD_ADD);
        ChangeBgY(3, 64, BG_COORD_ADD);
    }
    if (SWSH_SUMMARY_MON_IDLE_ANIMS && !sMonSummaryScreen->summary.isEgg)
    {
        RunMonAnimTimer();
    }
}

// Mon sprite data fields
#define sSpecies data[0]
#define sDontFlip data[1]
#define sDelayAnim data[2]
#define sIsShadow data[3]

static void RunMonAnimTimer(void)
{
    u32 i;

    if (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback == SpriteCallbackDummy) // mon anim is finished
    {
        sMonSummaryScreen->monAnimTimer++;
    }

    if (sMonSummaryScreen->monAnimTimer > SWSH_SUMMARY_MON_IDLE_ANIMS_FRAMES 
        && sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] != SPRITE_NONE) // time to re-run the anim
    {
        for (i = 1; i < 8; i++)
        {
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[i] = 0; // sprite data isn't always cleared after the anim finishes
            if (SWSH_SUMMARY_MON_SHADOWS)
                gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].data[i] = 0;
        }

        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].sSpecies = sMonSummaryScreen->summary.species2;
        if (SWSH_SUMMARY_MON_SHADOWS)
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].sSpecies = sMonSummaryScreen->summary.species2;

        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].sIsShadow = FALSE;
        if (SWSH_SUMMARY_MON_SHADOWS)
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].sIsShadow = TRUE;

        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback = SpriteCB_Pokemon;
        if (SWSH_SUMMARY_MON_SHADOWS)
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].callback = SpriteCB_Pokemon;

        sMonSummaryScreen->monAnimTimer = 0;
    }
}

static void CB2_InitSummaryScreen(void)
{
    while (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && LoadGraphics() != TRUE && MenuHelpers_IsLinkActive() != TRUE);
}

static bool8 LoadGraphics(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        InitBGs();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 6:
        if (DecompressGraphics() != FALSE)
            gMain.state++;
        break;
    case 7:
        ResetWindows();
        gMain.state++;
        break;
    case 8:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 9:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) != 0)
            gMain.state++;
        break;
    case 10:
        PrintMonPortraitInfo();
        gMain.state++;
        break;
    case 11:
        PrintPageNamesAndStats();
        gMain.state++;
        break;
    case 12:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 13:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
            SetSelectMoveTilemaps();
        else if (sMonSummaryScreen->mode == SUMMARY_MODE_RELEARNER_BATTLE) // load the appropriate moves page when returning from move relearner
            SetBgTilemapBuffer(2, sMonSummaryScreen->bg2TilemapBuffers[PSS_PAGE_BATTLE_MOVES]);
        gMain.state++;
        break;
    case 14:
        PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 15:
        ResetSpriteIds();
        CreateMoveTypeIcons();
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE && SWSH_SUMMARY_CATEGORY_ICONS)
            ShowCategoryIcon(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 16:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &sMonSummaryScreen->switchCounter, FALSE);
        if (SWSH_SUMMARY_MON_SHADOWS)
            sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &sMonSummaryScreen->switchCounter, TRUE);
        
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] != SPRITE_NONE)
        {
            sMonSummaryScreen->monAnimTimer = 0;
            sMonSummaryScreen->monAnimPlayed = FALSE;
            sMonSummaryScreen->switchCounter = 0;
            gMain.state++;
        }
        break;
    case 17:
        CreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 18:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 19:
        CreateStatusSprite();
        gMain.state++;
        break;
    case 20:
        CreateGenderSprite(&sMonSummaryScreen->currentMon, sMonSummaryScreen->summary.species);
        gMain.state++;
        break;
    case 21:
        if(SWSH_SUMMARY_SHOW_GIGANTAMAX)
            CreateGigantamaxSprite();
        gMain.state++;
        break;
    case 22:
        if (sMonSummaryScreen->summary.isEgg)
            ScheduleBgCopyTilemapToVram(2);
        gMain.state++;
        break;
    case 23:
        SetTypeIcons();
        TrySetInfoPageIcons();
        gMain.state++;
        break;
    case 24:
        if (sMonSummaryScreen->mode != SUMMARY_MODE_SELECT_MOVE)
            CreateTask(Task_HandleInput, 0);
        else
            CreateTask(Task_SetHandleReplaceMoveInput, 0);
        gMain.state++;
        break;
    case 25:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 26:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    case 27:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_RELEARNER_BATTLE)
        {
            ShowInfoPrompt();
        }
        gMain.state++;
        break;
    case 28:
        if ((sMonSummaryScreen->mode == SUMMARY_MODE_RELEARNER_BATTLE)
            && ShouldShowMoveRelearner())
        {
            ShowMoveRelearner();
        }
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlank);
        SetMainCallback2(MainCB2);
        return TRUE;
    }
    return FALSE;
}

static void InitBGs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(3, sMonSummaryScreen->bg3TilemapBuffers);
    SetBgTilemapBuffer(2, sMonSummaryScreen->bg2TilemapBuffers[PSS_PAGE_INFO]);
    SetBgTilemapBuffer(1, sMonSummaryScreen->bg1TilemapBuffers[PSS_EFFECT_BATTLE]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(3);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    if (SWSH_SUMMARY_BG_BLEND || SWSH_SUMMARY_MON_SHADOWS)
    {
        if (SWSH_SUMMARY_BG_BLEND)
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG1);
        else
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BG2 | BLDCNT_EFFECT_BLEND);

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(14, 6));
    }
    ShowBg(3);
    ShowBg(2);
    ShowBg(0);
}

static bool8 DecompressGraphics(void)
{
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, &sSummaryScreen_Gfx, 0, 0, 0);
        sMonSummaryScreen->switchCounter++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != 1)
        {
            DecompressDataWithHeaderWram(sSummaryPage_Info_Tilemap, sMonSummaryScreen->bg2TilemapBuffers[PSS_PAGE_INFO]);
            sMonSummaryScreen->switchCounter++;
        }
        break;
    case 2:
        DecompressDataWithHeaderWram(sSummaryPage_Skills_Tilemap, sMonSummaryScreen->bg2TilemapBuffers[PSS_PAGE_SKILLS]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 3:
        DecompressDataWithHeaderWram(sSummaryPage_BattleMoves_Tilemap, sMonSummaryScreen->bg2TilemapBuffers[PSS_PAGE_BATTLE_MOVES]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 4:
        DecompressDataWithHeaderWram(sSummaryEffect_Battle_Tilemap, sMonSummaryScreen->bg1TilemapBuffers[PSS_EFFECT_BATTLE]);
        sMonSummaryScreen->switchCounter++;
        break;
    case 5:
        DecompressDataWithHeaderWram(sSummaryPage_ScrollBG_Tilemap, sMonSummaryScreen->bg3TilemapBuffers);
        sMonSummaryScreen->switchCounter++;
        break;
    case 6:
        LoadPalette(sSummaryScreen_Pal, BG_PLTT_ID(0), 8 * PLTT_SIZE_4BPP);
        LoadPalette(&sSummaryScreen_PPTextPalette, BG_PLTT_ID(8) + 1, PLTT_SIZEOF(16 - 1));
        sMonSummaryScreen->switchCounter++;
        break;
    case 7:
        LoadCompressedSpriteSheet(&sSpriteSheet_MoveTypes);
        sMonSummaryScreen->switchCounter++;
        break;
    case 8:
        LoadCompressedSpriteSheet(&sMoveSelectorSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 9:
        LoadCompressedSpriteSheet(&sStatusIconsSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 10:
        LoadSpritePalette(&sStatusIconsSpritePalette);
        sMonSummaryScreen->switchCounter++;
        break;
    case 11:
        LoadCompressedSpriteSheet(&sShinyIconSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 12:
        LoadCompressedSpriteSheet(&sPokerusCuredIconSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 13:
        LoadSpritePalette(&sMoveSelectorSpritePal);
        sMonSummaryScreen->switchCounter++;
        break;
    case 14:
        if (SWSH_SUMMARY_CATEGORY_ICONS)
            LoadCompressedSpriteSheet(&sSpriteSheet_CategoryIcons);
        sMonSummaryScreen->switchCounter++;
        break;
    case 15:
        if (SWSH_SUMMARY_CATEGORY_ICONS)
            LoadSpritePalette(&sSpritePal_CategoryIcons);
        sMonSummaryScreen->switchCounter++;
        break;
    case 16:
        if (SWSH_SUMMARY_SHOW_FRIENDSHIP)
            LoadCompressedSpriteSheet(&sSpriteSheet_FriendshipIcon);
        sMonSummaryScreen->switchCounter++;
        break;
    case 17:
        if (SWSH_SUMMARY_SHOW_FRIENDSHIP)
            LoadSpritePalette(&sSpritePal_FriendshipIcon);
        sMonSummaryScreen->switchCounter++;
        break;
    case 18:
    #if SWSH_SUMMARY_SWSH_TYPE_ICONS == TRUE
        LoadPalette(sMoveTypes_Pal, OBJ_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
    #else
        LoadPalette(gMoveTypes_Pal, OBJ_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
    #endif
        sMonSummaryScreen->switchCounter++;
        break;
    case 19:
        if (SWSH_SUMMARY_SHOW_GIGANTAMAX)
            LoadCompressedSpriteSheet(&sGigantamaxIconSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 20:
        if (SWSH_SUMMARY_SHOW_TERA_TYPE)
            LoadCompressedSpriteSheet(&sSpriteSheet_TeraType);
        sMonSummaryScreen->switchCounter++;
        break;
    case 21:
        LoadCompressedSpriteSheet(&sSpriteSheet_InfoPrompt);
        sMonSummaryScreen->switchCounter++;
        break;
    case 22:
        if (P_SUMMARY_SCREEN_MOVE_RELEARNER)
            LoadCompressedSpriteSheet(&sSpriteSheet_RelearnPrompt);
        sMonSummaryScreen->switchCounter++;
        break;
    case 23:
        LoadCompressedSpriteSheet(&sSpriteSheet_HeldItemBox);
        sMonSummaryScreen->switchCounter++;
        break;
    case 24:
        LoadSpritePalette(&sSpritePal_HeldItemBox);
        sMonSummaryScreen->switchCounter = 0;
        return TRUE;
    }
    return FALSE;
}

static void CopyMonToSummaryStruct(struct Pokemon *mon)
{
    if (!sMonSummaryScreen->isBoxMon)
    {
        struct Pokemon *partyMon = sMonSummaryScreen->monList.mons;
        *mon = partyMon[sMonSummaryScreen->curMonIndex];
    }
    else
    {
        struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
        BoxMonToMon(&boxMon[sMonSummaryScreen->curMonIndex], mon);
    }
}

static bool8 ExtractMonDataToSummaryStruct(struct Pokemon *mon)
{
    u32 i;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    // Spread the data extraction over multiple frames.
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        sum->species = GetMonData(mon, MON_DATA_SPECIES);
        sum->species2 = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
        sum->exp = GetMonData(mon, MON_DATA_EXP);
        sum->level = GetMonData(mon, MON_DATA_LEVEL);
        sum->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
        sum->item = GetMonData(mon, MON_DATA_HELD_ITEM);
        sum->pid = GetMonData(mon, MON_DATA_PERSONALITY);
        sum->sanity = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);

        if (sum->sanity)
            sum->isEgg = TRUE;
        else
            sum->isEgg = GetMonData(mon, MON_DATA_IS_EGG);

        break;
    case 1:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            sum->moves[i] = GetMonData(mon, MON_DATA_MOVE1+i);
            sum->pp[i] = GetMonData(mon, MON_DATA_PP1+i);
        }
        sum->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
        break;
    case 2:
        if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == SUMMARY_MODE_BOX || sMonSummaryScreen->handleDeoxys == TRUE)
        {
            sum->nature = GetNature(mon);
            sum->mintNature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK);
            sum->def = GetMonData(mon, MON_DATA_DEF);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF);
            sum->speed = GetMonData(mon, MON_DATA_SPEED);
        }
        else
        {
            sum->nature = GetNature(mon);
            sum->mintNature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK2);
            sum->def = GetMonData(mon, MON_DATA_DEF2);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK2);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF2);
            sum->speed = GetMonData(mon, MON_DATA_SPEED2);
        }
        break;
    case 3:
        GetMonData(mon, MON_DATA_OT_NAME, sum->OTName);
        ConvertInternationalString(sum->OTName, GetMonData(mon, MON_DATA_LANGUAGE));
        sum->ailment = GetMonAilment(mon);
        sum->OTGender = GetMonData(mon, MON_DATA_OT_GENDER);
        sum->OTID = GetMonData(mon, MON_DATA_OT_ID);
        sum->metLocation = GetMonData(mon, MON_DATA_MET_LOCATION);
        sum->metLevel = GetMonData(mon, MON_DATA_MET_LEVEL);
        sum->metGame = GetMonData(mon, MON_DATA_MET_GAME);
        sum->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
        break;
    case 4:
        sum->ivHp = GetMonData(mon, MON_DATA_HP_IV);
        sum->ivAtk = GetMonData(mon, MON_DATA_ATK_IV);
        sum->ivDef = GetMonData(mon, MON_DATA_DEF_IV);
        sum->ivSpatk = GetMonData(mon, MON_DATA_SPATK_IV);
        sum->ivSpdef = GetMonData(mon, MON_DATA_SPDEF_IV);
        sum->ivSpeed = GetMonData(mon, MON_DATA_SPEED_IV);
        break;
    case 5:
        sum->evHp = GetMonData(mon, MON_DATA_HP_EV);
        sum->evAtk = GetMonData(mon, MON_DATA_ATK_EV);
        sum->evDef = GetMonData(mon, MON_DATA_DEF_EV);
        sum->evSpatk = GetMonData(mon, MON_DATA_SPATK_EV);
        sum->evSpdef = GetMonData(mon, MON_DATA_SPDEF_EV);
        sum->evSpeed = GetMonData(mon, MON_DATA_SPEED_EV);
        break;
    default:
        sum->ribbonCount = GetMonData(mon, MON_DATA_RIBBON_COUNT);        
        sum->teraType = GetMonData(mon, MON_DATA_TERA_TYPE);
        sum->isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
        sMonSummaryScreen->relearnableMovesNum = P_SUMMARY_SCREEN_MOVE_RELEARNER ? GetNumberOfRelearnableMoves(mon) : 0;
        return TRUE;
    }
    sMonSummaryScreen->switchCounter++;
    return FALSE;
}

static void SetSelectMoveTilemaps(void)
{
    SetBgTilemapBuffer(2, sMonSummaryScreen->bg2TilemapBuffers[PSS_PAGE_BATTLE_MOVES]);
    SetBgTilemapBuffer(1, sMonSummaryScreen->bg1TilemapBuffers[PSS_EFFECT_BATTLE]);
    ShowBg(1);
}

#define TILEMAP_PAGE_DOT_1_TILE_1   0x000D
#define TILEMAP_PAGE_DOT_1_TILE_2   0x002D
#define TILEMAP_PAGE_DOT_2_TILE_1   0x000F
#define TILEMAP_PAGE_DOT_2_TILE_2   0x002F
#define TILEMAP_PAGE_DOT_3_TILE_1   0x0011
#define TILEMAP_PAGE_DOT_3_TILE_2   0x0031
#define TILEMAP_PAGE_DOT_4_TILE_1   0x0013
#define TILEMAP_PAGE_DOT_4_TILE_2   0x0033

#define TILE_BLACK_SQUARE           0x00B5
#define TILE_INACTIVE_SQUARE_TOP    0x0002
#define TILE_INACTIVE_SQUARE_BOTTOM BG_TILE_V_FLIP(TILE_INACTIVE_SQUARE_TOP)


static void FreeSummaryScreen(void)
{
    FreeAllWindowBuffers();
    Free(sMonSummaryScreen);
}

static void BeginCloseSummaryScreen(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = CloseSummaryScreen;
}

static void CloseSummaryScreen(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        if (SWSH_SUMMARY_BG_BLEND || SWSH_SUMMARY_MON_SHADOWS)
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        }
        if (sMonSummaryScreen->callback == gInitialSummaryScreenCallback)
            gInitialSummaryScreenCallback = NULL;
        SetMainCallback2(sMonSummaryScreen->callback);
        gLastViewedMonIndex = sMonSummaryScreen->curMonIndex;
        SummaryScreen_DestroyAnimDelayTask();
        ResetSpriteData();
        FreeAllSpritePalettes();
        StopCryAndClearCrySongs();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        if (gMonSpritesGfxPtr == NULL)
            DestroyMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A);
        FreeSummaryScreen();
        DestroyTask(taskId);
    }
}

#define tSkillsState data[3]

// Cycle summary page between stats, IVs and EVs
static void ChangeSummaryState(s16 *data, u8 taskId)
{
    switch (tSkillsState)
    {
    case SKILL_STATE_STATS:
        tSkillsState = SKILL_STATE_IVS;
        break;
    case SKILL_STATE_IVS:
        tSkillsState = SKILL_STATE_EVS;
        break;
    case SKILL_STATE_EVS:
        tSkillsState = SKILL_STATE_STATS;
        break;
    }

    gTasks[taskId].func = Task_HandleInput;
}

// draw button prompts when cycling between stats, IVs and EVs
static void DrawNextSkillsButtonPrompt(u8 mode)
{
    switch (mode)
    {
        case SKILL_STATE_STATS:
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_STATS);
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
            break;
        case SKILL_STATE_IVS:
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
            break;
        case SKILL_STATE_EVS:
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
            PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_STATS);
            break;
    }
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 defaultSkillsState = SKILL_STATE_STATS;
    
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        if (JOY_NEW(DPAD_UP))
        {
            tSkillsState = defaultSkillsState;
            ChangeSummaryPokemon(taskId, -1);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            tSkillsState = defaultSkillsState;
            ChangeSummaryPokemon(taskId, 1);
        }
        else if ((JOY_NEW(DPAD_LEFT)) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            tSkillsState = defaultSkillsState;
            ChangePage(taskId, -1);
        }
        else if ((JOY_NEW(DPAD_RIGHT)) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            tSkillsState = defaultSkillsState;
            ChangePage(taskId, 1);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            {
                PlaySE(SE_SELECT);
                SwitchToMoveSelection(taskId);
            }
            else if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
            {
                if (SWSH_SUMMARY_SHOW_IV_EV)
                {
                    // Cycle through IVs/EVs/stats on pressing A
                    ChangeSummaryState(data, taskId);
                    DrawNextSkillsButtonPrompt(tSkillsState);
                    PlaySE(SE_SELECT);
                    BufferAndPrintStats_HandleState(tSkillsState);
                }
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            BeginCloseSummaryScreen(taskId);
        }  
        else if (JOY_NEW(START_BUTTON))
        {
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO && ShouldShowRename())
                {
                    if (ShouldShowRename())
                    {
                        sMonSummaryScreen->callback = CB2_PssChangePokemonNickname;
                        gSpecialVar_0x8004 = sMonSummaryScreen->curMonIndex;
                    }

                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    BeginCloseSummaryScreen(taskId);
                }
            if (ShouldShowMoveRelearner()
                && (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES))
            {
                sMonSummaryScreen->callback = CB2_InitLearnMove;
                gSpecialVar_0x8004 = sMonSummaryScreen->curMonIndex;
                gOriginSummaryScreenPage = sMonSummaryScreen->currPageIndex;
                StopPokemonAnimations();
                PlaySE(SE_SELECT);
                BeginCloseSummaryScreen(taskId);
            }  
        }        
        else if (DEBUG_POKEMON_SPRITE_VISUALIZER && JOY_NEW(SELECT_BUTTON) && !gMain.inBattle)
        {
            sMonSummaryScreen->callback = CB2_Pokemon_Sprite_Visualizer;
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            CloseSummaryScreen(taskId);
        }
    }
}

#undef tSkillsState

#define tSummaryState data[0]

static void ChangeSummaryPokemon(u8 taskId, s8 delta)
{
    s8 monId;

    if (!sMonSummaryScreen->lockMonFlag)
    {
        if (sMonSummaryScreen->isBoxMon == TRUE)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
            {
                if (delta == 1)
                    delta = 0;
                else
                    delta = 2;
            }
            else
            {
                if (delta == 1)
                    delta = 1;
                else
                    delta = 3;
            }
            monId = AdvanceStorageMonIndex(sMonSummaryScreen->monList.boxMons, sMonSummaryScreen->curMonIndex, sMonSummaryScreen->maxMonIndex, delta);
        }
        else if (IsMultiBattle() == TRUE)
        {
            monId = AdvanceMultiBattleMonIndex(delta);
        }
        else
        {
            monId = AdvanceMonIndex(delta);
        }

        if (monId != -1)
        {
            PlaySE(SE_SELECT);
            if (sMonSummaryScreen->summary.ailment != AILMENT_NONE)
            {
                SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
            }
            sMonSummaryScreen->curMonIndex = monId;
            sMonSummaryScreen->monAnimTimer = 0;
            sMonSummaryScreen->monAnimPlayed = FALSE;
            gTasks[taskId].tSummaryState = 0;
            gTasks[taskId].func = Task_ChangeSummaryMon;
        }
    }
}

static void Task_ChangeSummaryMon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tSummaryState)
    {
    case 0:
        StopCryAndClearCrySongs();
        break;
    case 1:
        SummaryScreen_DestroyAnimDelayTask();
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]]);
        if (SWSH_SUMMARY_MON_SHADOWS)
            DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]]);
        DestroyHeldItemIconSprite();
        break;
    case 2:
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]]);
        break;
    case 3:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        break;
    case 4:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) == FALSE)
        {
            return;
        }
        else
        {
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            {
                ShowInfoPrompt();
            }
            else if (P_SUMMARY_SCREEN_MOVE_RELEARNER
                && (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES))
            {
                if (ShouldShowMoveRelearner())
                    ShowMoveRelearner();
                else
                    HideMoveRelearner();
            }
        }
        break;
    case 5:
        RemoveAndCreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        break;
    case 6:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        break;
    case 7:
        CreateGenderSprite(&sMonSummaryScreen->currentMon, sMonSummaryScreen->summary.species);
        break;
    case 8:
        if (SWSH_SUMMARY_SHOW_GIGANTAMAX)
            CreateGigantamaxSprite();
        break;
    case 9:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &data[1], FALSE);

        if (SWSH_SUMMARY_MON_SHADOWS)
            sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &data[1], TRUE);

        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] == SPRITE_NONE)
            return;

        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].sDelayAnim = 1;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].sIsShadow = FALSE;

        if (SWSH_SUMMARY_MON_SHADOWS)
        {
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].sDelayAnim = 1;
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].sIsShadow = TRUE;
        }

        TryDrawExperienceProgressBar();
        data[1] = 0;
        break;
    case 10:
        SetTypeIcons();
        TrySetInfoPageIcons();
        break;
    case 11:
        PrintMonPortraitInfo();
        HandleStatusSprite(&sMonSummaryScreen->currentMon); // Moved here from case 7
        break;
    case 12:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
        { 
            ScheduleBgCopyTilemapToVram(2);

            if (P_SUMMARY_SCREEN_RENAME)
            {
                FillWindowPixelBuffer(PSS_LABEL_WINDOW_PROMPT_CANCEL, PIXEL_FILL(0));
                ShowCancelOrRenamePrompt();
                PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_CANCEL);  
            }
            CreateHeldItemBoxSprites();
            CreateHeldItemSprite();
        } 
        else if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        {
            DrawNextSkillsButtonPrompt(SKILL_STATE_STATS);
        }
        break;
    case 13:
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].sDelayAnim = 0;
        if (SWSH_SUMMARY_MON_SHADOWS)
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].sDelayAnim = 0;
        break;
    default:
        if (!MenuHelpers_ShouldWaitForLinkRecv())
        {
            data[0] = 0; // tSkillsState
            gTasks[taskId].func = Task_HandleInput;
        }
        return;
    }
    tSummaryState++;
}

static s8 AdvanceMonIndex(s8 delta)
{
    struct Pokemon *mon = sMonSummaryScreen->monList.mons;
    u8 index = sMonSummaryScreen->curMonIndex;
    u8 numMons = sMonSummaryScreen->maxMonIndex + 1;
    delta += numMons;

    index = (index + delta) % numMons;

    // skip over any Eggs unless on the Info Page
    if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
        while (GetMonData(&mon[index], MON_DATA_IS_EGG))
            index = (index + delta) % numMons;

    // to avoid "scrolling" to the same Pokemon
    if (index == sMonSummaryScreen->curMonIndex)
        return -1;
    else
        return index;
}

static s8 AdvanceMultiBattleMonIndex(s8 delta)
{
    struct Pokemon *mons = sMonSummaryScreen->monList.mons;
    s8 index, arrId = 0;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sMultiBattleOrder[i] == sMonSummaryScreen->curMonIndex)
        {
            arrId = i;
            break;
        }
    }

    while (TRUE)
    {
        const s8 *order = sMultiBattleOrder;

        arrId += delta;
        if (arrId < 0 || arrId >= PARTY_SIZE)
            return -1;
        index = order[arrId];
        if (IsValidToViewInMulti(&mons[index]) == TRUE)
            return index;
    }
}

static bool8 IsValidToViewInMulti(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return FALSE;
    else if (sMonSummaryScreen->curMonIndex != 0 || !GetMonData(mon, MON_DATA_IS_EGG))
        return TRUE;
    else
        return FALSE;
}

#define tScrollState data[0]
#define tMosaicStrength data[1]

static void ChangePage(u8 taskId, s8 delta)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    s16 *data = gTasks[taskId].data;

    if (summary->isEgg)
        return;
    else if (delta == -1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->minPageIndex)
        return;
    else if (delta == 1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->maxPageIndex)
        return;

    PlaySE(SE_SELECT);
    ClearPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
    sMonSummaryScreen->currPageIndex += delta;
    tScrollState = 0;
    SetTaskFuncWithFollowupFunc(taskId, PssScroll, gTasks[taskId].func);
    CreateTextPrinterTask(sMonSummaryScreen->currPageIndex);
    HidePageSpecificSprites();
}

static void PssScroll(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tScrollState == 0)
    {
        tMosaicStrength = 0;
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetBgTilemapBuffer(2, sMonSummaryScreen->bg2TilemapBuffers[sMonSummaryScreen->currPageIndex]);
        ShowBg(2);
        SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
            SetGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
    }
    
    // build up mosaic effect
    if (tScrollState <= 3)
    {
        tMosaicStrength += 1;
        SetGpuReg(REG_OFFSET_MOSAIC, (tMosaicStrength & 15) * 17);
    }
    // build down mosaic effect
    if (tScrollState > 3)
    {
        tMosaicStrength -= 1;
        SetGpuReg(REG_OFFSET_MOSAIC, (tMosaicStrength & 15) * 17);
    }

    tScrollState++;

    if (tScrollState >= 8)
        gTasks[taskId].func = PssScrollEnd;
}

static void PssScrollEnd(u8 taskId)
{
    if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
    {
        SetBgTilemapBuffer(1, sMonSummaryScreen->bg1TilemapBuffers[PSS_EFFECT_BATTLE]);
        ScheduleBgCopyTilemapToVram(1);
    }

    ClearGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
    if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
        ClearGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    ScheduleBgCopyTilemapToVram(2);
    PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);

    SetTypeIcons();
    TrySetInfoPageIcons();
    TryDrawExperienceProgressBar();

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
    {
        if (sMonSummaryScreen->markingsSprite != NULL)
           sMonSummaryScreen->markingsSprite->invisible = FALSE; 
    } 

    SwitchTaskToFollowupFunc(taskId);
}

#undef tScrollState
#undef tMosaicStrength

static void TryDrawExperienceProgressBar(void)
{
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
        DrawExperienceProgressBar(&sMonSummaryScreen->currentMon);
}


static void SwitchToMoveSelection(u8 taskId)
{
    sMonSummaryScreen->firstMoveIndex = 0;

    HideInfoPrompt();
    if (!sMonSummaryScreen->lockMovesFlag)
    {
        if (ShouldShowMoveRelearner())
            HideMoveRelearner();
        PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_SWITCH);
    }

    CreateTask(Task_ShowEffectTilemap, 1);

    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void Task_HandleInput_MoveSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 4;
            ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 4;
            ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->lockMovesFlag == TRUE
             || (sMonSummaryScreen->newMove == MOVE_NONE && sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES))
            {
                PlaySE(SE_SELECT);
                CloseMoveSelectMode(taskId);
            }
            else if (HasMoreThanOneMove() == TRUE)
            {
                PlaySE(SE_SELECT);
                SwitchToMovePositionSwitchMode(taskId);
                HideInfoPrompt();
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseMoveSelectMode(taskId);
        }
    }
}

static bool8 HasMoreThanOneMove(void)
{
    u8 i;
    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (sMonSummaryScreen->summary.moves[i] != 0)
            return TRUE;
    }
    return FALSE;
}

static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr)
{
    s8 i, newMoveIndex;
    u16 move;

    PlaySE(SE_SELECT);
    newMoveIndex = *moveIndexPtr;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        newMoveIndex += direction;
        if (newMoveIndex > taskData[0])
            newMoveIndex = 0;
        else if (newMoveIndex < 0)
            newMoveIndex = taskData[0];

        if (newMoveIndex == MAX_MON_MOVES)
        {
            move = sMonSummaryScreen->newMove;
            break;
        }
        move = sMonSummaryScreen->summary.moves[newMoveIndex];
        if (move != 0)
            break;
    }

    PrintMoveDescription(move);

    *moveIndexPtr = newMoveIndex;
    // Get rid of the 'flicker' effect(while idle) when scrolling.
    if (moveIndexPtr == &sMonSummaryScreen->firstMoveIndex)
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR1);
    else
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR2);
}

static void CloseMoveSelectMode(u8 taskId)
{
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_SWITCH);
    PrintMoveDescription(MOVE_NONE);
    if (ShouldShowMoveRelearner())
        ShowMoveRelearner();
    ShowInfoPrompt();
    sMonSummaryScreen->mode = SUMMARY_MODE_NORMAL;
    
    CreateTask(Task_HideEffectTilemap, 1);
    gTasks[taskId].func = Task_HandleInput;
}

static void SwitchToMovePositionSwitchMode(u8 taskId)
{
    sMonSummaryScreen->secondMoveIndex = sMonSummaryScreen->firstMoveIndex;
    SetMainMoveSelectorColor(1);
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);
    gTasks[taskId].func = Task_HandleInput_MovePositionSwitch;
}

static void Task_HandleInput_MovePositionSwitch(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->firstMoveIndex == sMonSummaryScreen->secondMoveIndex)
                ExitMovePositionSwitchMode(taskId, FALSE);
            else
                ExitMovePositionSwitchMode(taskId, TRUE);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            ExitMovePositionSwitchMode(taskId, FALSE);
        }
    }
}

static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves)
{
    u16 move;

    PlaySE(SE_SELECT);
    SetMainMoveSelectorColor(0);
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);

    if (swapMoves == TRUE)
    {
        if (!sMonSummaryScreen->isBoxMon)
        {
            struct Pokemon *mon = sMonSummaryScreen->monList.mons;
            SwapMonMoves(&mon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        else
        {
            struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
            SwapBoxMonMoves(&boxMon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        SwapMovesNamesPP(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        SwapMovesTypeSprites(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        sMonSummaryScreen->firstMoveIndex = sMonSummaryScreen->secondMoveIndex;
    }

    move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
    PrintMoveDescription(move);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void Task_SetHandleReplaceMoveInput(u8 taskId)
{
    SetNewMoveTypeIcon();
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleReplaceMoveInput;
}

static void Task_HandleReplaceMoveInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (gPaletteFade.active != TRUE)
        {
            if (JOY_NEW(DPAD_UP))
            {
                data[0] = 4;
                ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (JOY_NEW(DPAD_DOWN))
            {
                data[0] = 4;
                ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
            {
                ChangePage(taskId, -1);
            }
            else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
            {
                ChangePage(taskId, 1);
            }
            else if (JOY_NEW(A_BUTTON))
            {
                if (CanReplaceMove() == TRUE)
                {
                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    sMoveSlotToReplace = sMonSummaryScreen->firstMoveIndex;
                    gSpecialVar_0x8005 = sMoveSlotToReplace;
                    BeginCloseSummaryScreen(taskId);
                }
                else
                {
                    PlaySE(SE_FAILURE);
                    ShowCantForgetHMsWindow(taskId);
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                StopPokemonAnimations();
                PlaySE(SE_SELECT);
                sMoveSlotToReplace = MAX_MON_MOVES;
                gSpecialVar_0x8005 = MAX_MON_MOVES;
                BeginCloseSummaryScreen(taskId);
            }
        }
    }
}

static bool8 CanReplaceMove(void)
{
    if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES
        || sMonSummaryScreen->newMove == MOVE_NONE
        || IsMoveHM(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]) != TRUE)
        return TRUE;
    else
        return FALSE;
}

static void ShowCantForgetHMsWindow(u8 taskId)
{
    PrintHMMovesCantBeForgotten();
    gTasks[taskId].func = Task_HandleInputCantForgetHMsMoves;
}

// This redraws the power/accuracy window when the player scrolls out of the "HM Moves can't be forgotten" message
static void Task_HandleInputCantForgetHMsMoves(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 move;
    if (FuncIsActiveTask(Task_ShowEffectTilemap) != 1)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[1] = 1;
            data[0] = 4;
            ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[1] = 1;
            data[0] = 4;
            ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
        else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_BATTLE_MOVES)
            {
                move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
                gTasks[taskId].func = Task_HandleReplaceMoveInput;
                ChangePage(taskId, -1);
            }
        }
        else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_BATTLE_MOVES)
            {
                move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
                gTasks[taskId].func = Task_HandleReplaceMoveInput;
                ChangePage(taskId, 1);
            }
        }
        else if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
            PrintMoveDescription(move);
            ScheduleBgCopyTilemapToVram(0);
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
        }
    }
}

u8 GetMoveSlotToReplace_SwSh(void)
{
    return sMoveSlotToReplace;
}

#define tMoveTaskState data[2]
#define tMosaicStrength data[3]

static void Task_ShowEffectTilemap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    // set mosaic effect and appropriate tilemap buffer
    if (tMoveTaskState == 0)
    {
        tMosaicStrength = 6;
        SetGpuReg(REG_OFFSET_MOSAIC, (tMosaicStrength & 15) * 17);
        SetBgTilemapBuffer(1, sMonSummaryScreen->bg1TilemapBuffers[PSS_EFFECT_BATTLE]);
        ScheduleBgCopyTilemapToVram(1);
        ShowBg(1);
        SetGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
        tMoveTaskState++;
    }
    // attenuate mosaic effect
    else if (tMoveTaskState <= 4)
    {
        tMosaicStrength -= 1;
        SetGpuReg(REG_OFFSET_MOSAIC, (tMosaicStrength & 15) * 17);
        tMoveTaskState++;
    }
    // finish mosaic effect and print text
    else
    {
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        ClearGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
        PrintMoveDescription(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        PrintNewMoveDetailsOrCancelText();
        SetNewMoveTypeIcon();

        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            PutWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);

        DestroyTask(taskId);
    }
}

static void Task_HideEffectTilemap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 windowId;

    // wait for showing task to finish
    if (FuncIsActiveTask(Task_ShowEffectTilemap))
        return;

    // clean up the windows and text on the first pass
    // set up mosaic effect
    if (tMoveTaskState == 0)
    {
        tMosaicStrength = 0;
        SetGpuReg(REG_OFFSET_MOSAIC, (tMosaicStrength & 15) * 17);
        SetGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);

        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);

        windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
        ClearWindowTilemap(windowId);
        ClearCancelText();

        if (SWSH_SUMMARY_CATEGORY_ICONS)
            DestroyCategoryIcon();

        tMoveTaskState++;
    }
    // dial up mosaic effect over time
    else if (tMoveTaskState < 5)
    {
        tMosaicStrength++;
        SetGpuReg(REG_OFFSET_MOSAIC, (tMosaicStrength & 15) * 17);
        tMoveTaskState++;
    }
    // hide BG and clear mosaic effect
    else
    {
        HideBg(1);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        ClearGpuRegBits(REG_OFFSET_BG1CNT, BGCNT_MOSAIC);
        DestroyTask(taskId);
    }
}

#undef tMoveTaskState
#undef tMosaicStrength


// // Leftover as reference for moving EXP BAR location
// #define EXP_BAR_VERTICAL_OFFSET_TILES -3
// #define EXP_BAR_HORIZONTAL_OFFSET_TILES -9  // Negative = left, positive = right
// #define EXP_BAR_TILEMAP_START (0x1F4 + (EXP_BAR_VERTICAL_OFFSET_TILES * 32) + EXP_BAR_HORIZONTAL_OFFSET_TILES)
#define EXP_BAR_TILEMAP_START 0x18B
#define EXP_BAR_TILE_EMPTY    0x2150
#define EXP_BAR_TILE_FULL     0x2158

static void DrawExperienceProgressBar(struct Pokemon *unused)
{
    s64 numExpProgressBarTicks;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 *dst;
    u8 i;

    if (summary->level < MAX_LEVEL)
    {
        u32 expBetweenLevels = gExperienceTables[gSpeciesInfo[summary->species].growthRate][summary->level + 1] - gExperienceTables[gSpeciesInfo[summary->species].growthRate][summary->level];
        u32 expSinceLastLevel = summary->exp - gExperienceTables[gSpeciesInfo[summary->species].growthRate][summary->level];

        // Calculate the number of 1-pixel "ticks" to illuminate in the experience progress bar.
        // There are 8 tiles that make up the bar, and each tile has 8 "ticks". Hence, the numerator
        // is multiplied by 64.
        numExpProgressBarTicks = expSinceLastLevel * 64 / expBetweenLevels;
        if (numExpProgressBarTicks == 0 && expSinceLastLevel != 0)
            numExpProgressBarTicks = 1;
    }
    else
    {
        numExpProgressBarTicks = 0;
    }

    dst = &sMonSummaryScreen->bg2TilemapBuffers[PSS_PAGE_SKILLS][EXP_BAR_TILEMAP_START];
    for (i = 0; i < 8; i++)
    {
        if (numExpProgressBarTicks > 7)
            dst[i] = EXP_BAR_TILE_FULL;
        else
            dst[i] = EXP_BAR_TILE_EMPTY + (numExpProgressBarTicks % 8);
        numExpProgressBarTicks -= 8;
        if (numExpProgressBarTicks < 0)
            numExpProgressBarTicks = 0;
    }

    ScheduleBgCopyTilemapToVram(2);
}

static void ResetWindows(void)
{
    u8 i;

    InitWindows(sSummaryTemplate);
    DeactivateAllTextPrinters();
    for (i = 0; i < PSS_LABEL_WINDOW_END; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        sMonSummaryScreen->windowIds[i] = WINDOW_NONE;
}

static void PrintTextOnWindowWithFont(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId, u32 fontId)
{
    AddTextPrinterParameterized4(windowId, fontId, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void PrintTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    PrintTextOnWindowWithFont(windowId, string, x, y, lineSpacing, colorId, PSS_DEFAULT_FONT);
}
// Note: This function is unused, but left in for documentation purposes
static void UNUSED PrintTextOnWindowToFitPx(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId, u32 width)
{
    // Changed from FONT_SHORT TO FONT_NORMAL for lowercase L-letter spacing
    // Worked exclusively when FONT_NORMAL points to latin_frlg or latin_frlg_nums
    u32 fontId = GetFontIdToFit(string, FONT_NORMAL, 0, width); 
    PrintTextOnWindowWithFont(windowId, string, x, y, lineSpacing, colorId, fontId);
}

static void PrintTextOnWindowToFitPx_WithFont(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId, u32 fontId, u32 width)
{
    u32 font = GetFontIdToFit(string, fontId, 0, width);
    PrintTextOnWindowWithFont(windowId, string, x, y, lineSpacing, colorId, font);
}

static void PrintMonPortraitInfo(void)
{
    FillWindowPixelBuffer(PSS_LABEL_WINDOW_PORTRAIT_INFO, PIXEL_FILL(0));
    if (!sMonSummaryScreen->summary.isEgg)
        PrintNotEggInfo();
    else
        PrintEggInfo();
    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNotEggInfo(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);

    // print nickname
    GetMonNickname(mon, gStringVar1);
    PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_INFO, gStringVar1, 6, 1, 0, 1);

    // // Look for CreateGenderSprite function, not using gender symbols (text)
    // PrintGenderSymbol(mon, summary->species2);

    // print level only if no status condition
    if (statusAnim == 0)
    {
        // Convert level number to string
        ConvertIntToDecimalStringN(gStringVar2, summary->level, STR_CONV_MODE_LEFT_ALIGN, 3);

        // Print "Lv." with FONT_NORMAL
        PrintTextOnWindowWithFont(PSS_LABEL_WINDOW_PORTRAIT_INFO, sText_Lv, 74, 1, 0, 1, FONT_SMALL_NARROWER);
        // Print the level number with FONT_SHORT_NARROW, positioned after "Lv." (10) + space (1)
        PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_INFO, gStringVar2, 74 + 10 + 1, 1, 0, 1);
    }
    
    PutWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_INFO);
}

static void PrintEggStepsRemaining(void)
{
    u32 eggCycles = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_FRIENDSHIP);
    u32 stepsInCurrentCycle = gSaveBlock1Ptr->daycare.stepCounter;
    
    #if P_EGG_CYCLE_LENGTH >= GEN_8
        u32 stepsPerCycle = 128;
    #elif P_EGG_CYCLE_LENGTH == GEN_5 || P_EGG_CYCLE_LENGTH == GEN_6
        u32 stepsPerCycle = 257;
    #elif P_EGG_CYCLE_LENGTH == GEN_4
        u32 stepsPerCycle = 255;
    #else // GEN_3 or GEN_7
        u32 stepsPerCycle = 256;
    #endif

    // Handle fast-hatching abilities like Flame Body, etc.
    u8 cyclesToSubtract = GetEggCyclesToSubtract();
    u32 stepsRemaining;
    
    // Calculate how many actual step cycles are needed
    // 1. Round up division
    // 2. Add 1 for the last cycle (GF Jank?)
    u32 cyclesNeeded = ((eggCycles + cyclesToSubtract - 1) / cyclesToSubtract) + 1;
    stepsRemaining = ((cyclesNeeded) * stepsPerCycle) - stepsInCurrentCycle;
    
    ConvertIntToDecimalStringN(gStringVar1, stepsRemaining, STR_CONV_MODE_LEFT_ALIGN, 5);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar1, sEggStepsLayout);

    u8 stringXPos = GetStringRightAlignXOffset(FONT_SHORT_NARROW, gStringVar1, 80) + 24;
    PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_INFO, gStringVar1, stringXPos, 1, 0, 1);
}

static void PrintEggInfo(void)
{
    // GetMonNickname(&sMonSummaryScreen->currentMon, gStringVar1);
    StringCopy(gStringVar1, sText_Egg);
    PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_INFO, gStringVar1, 4, 1, 0, 1);
    PrintEggStepsRemaining();
    PutWindowTilemap(PSS_LABEL_WINDOW_PORTRAIT_INFO);
}

// Functions
static void LoadGenderGfx(void)
{
    if (GetSpriteTileStartByTag(TAG_GENDER_ICON) == 0xFFFF)
    {
        LoadCompressedSpriteSheet(&sGenderIconsSpriteSheet);
        LoadSpritePalette(&sGenderIconsSpritePalette);
    }
}

static void CreateGenderSprite(struct Pokemon *mon, u16 species)
{
    u8 *spriteId = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_GENDER];
    u8 gender;

    if (*spriteId == SPRITE_NONE)
    {
        LoadGenderGfx();
        *spriteId = CreateSprite(&sSpriteTemplate_Gender, 231, 17, 6);
    }
    
    if (species != SPECIES_NIDORAN_M && species != SPECIES_NIDORAN_F && !sMonSummaryScreen->summary.isEgg)
    {
        gender = GetMonGender(mon);
        if (gender == MON_MALE || gender == MON_FEMALE)
        {
            u8 animIndex = (gender == MON_MALE) ? 1 : 0;
            StartSpriteAnim(&gSprites[*spriteId], animIndex);
            SetSpriteInvisibility(SPRITE_ARR_ID_GENDER, FALSE);
        }
        else
        {
            SetSpriteInvisibility(SPRITE_ARR_ID_GENDER, TRUE);
        }
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_GENDER, TRUE);
    }
}

// // Unused function to print gender using symbol as text instead of customized sprite
// // See CreateGenderSprite
// static void PrintGenderSymbol(struct Pokemon *mon, u16 species)
// {
//     if (species != SPECIES_NIDORAN_M && species != SPECIES_NIDORAN_F)
//     {
//         switch (GetMonGender(mon))
//         {
//         case MON_MALE:
//             PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_INFO, gText_MaleSymbol, 103, 1, 0, 3);
//             break;
//         case MON_FEMALE:
//             PrintTextOnWindow(PSS_LABEL_WINDOW_PORTRAIT_INFO, gText_FemaleSymbol, 103, 1, 0, 4);
//             break;
//         }
//     }
// }

enum {
    BUTTON_A,
    BUTTON_B,
    BUTTON_START,
};

static void PrintButtonIcon(u8 windowId, u8 buttonType, u32 x, u32 y)
{
    static const struct {
        u8 width;
        u8 height;
    } sButtonDimensions[] = {
        [BUTTON_A]      = {8, 8},
        [BUTTON_B]      = {8, 8},
        [BUTTON_START]  = {32, 8},
    };
    
    const u8 *button = sButtons_Gfx[buttonType];
    u8 width = sButtonDimensions[buttonType].width;
    u8 height = sButtonDimensions[buttonType].height;

    BlitBitmapToWindow(windowId, button, x, y, width, height);
}

static void PrintPageNamesAndStats(void)
{
    int stringXPos;
    int iconXPos;
    int skillsLabelWidth = 78;

    ShowCancelOrRenamePrompt();

    stringXPos = GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_Switch, 62) - 2;
    iconXPos = stringXPos - 11;
    if (iconXPos < 0)
        iconXPos = 0;
    PrintButtonIcon(PSS_LABEL_WINDOW_PROMPT_SWITCH, BUTTON_A, iconXPos, 4);
    PrintTextOnWindowWithFont(PSS_LABEL_WINDOW_PROMPT_SWITCH, sText_Switch, stringXPos, 0, 0, 1, FONT_SMALL);

    if (SWSH_SUMMARY_SHOW_IV_EV)
    {
        stringXPos = GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_ViewIVs, skillsLabelWidth) - 2;
        iconXPos = stringXPos - 11;
        if (iconXPos < 0)
            iconXPos = 0;
        PrintButtonIcon(PSS_LABEL_WINDOW_PROMPT_IVS, BUTTON_A, iconXPos, 4);
        PrintTextOnWindowWithFont(PSS_LABEL_WINDOW_PROMPT_IVS, sText_ViewIVs, stringXPos, 0, 0, 1, FONT_SMALL);

        stringXPos = GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_ViewEVs, skillsLabelWidth) - 2;
        iconXPos = stringXPos - 11;
        if (iconXPos < 0)
            iconXPos = 0;
        PrintButtonIcon(PSS_LABEL_WINDOW_PROMPT_EVS, BUTTON_A, iconXPos, 4);
        PrintTextOnWindowWithFont(PSS_LABEL_WINDOW_PROMPT_EVS, sText_ViewEVs, stringXPos, 0, 0, 1, FONT_SMALL);

        stringXPos = GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_ViewStats, skillsLabelWidth) - 2;
        iconXPos = stringXPos - 11;
        if (iconXPos < 0)
            iconXPos = 0;
        PrintButtonIcon(PSS_LABEL_WINDOW_PROMPT_STATS, BUTTON_A, iconXPos, 4);
        PrintTextOnWindowWithFont(PSS_LABEL_WINDOW_PROMPT_STATS, sText_ViewStats, stringXPos, 0, 0, 1, FONT_SMALL);
    }
}

static void PutPageWindowTilemaps(u8 page)
{
    u8 i;

    ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_INFO_TITLE);
    ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE);
    ClearWindowTilemap(PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE);

    switch (page)
    {
    case PSS_PAGE_INFO:
        PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_INFO_TITLE);
        PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_CANCEL);
        break;
    case PSS_PAGE_SKILLS:
        PutWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_TITLE);
        PutWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
        break;
    case PSS_PAGE_BATTLE_MOVES:
        PutWindowTilemap(PSS_LABEL_WINDOW_BATTLE_MOVES_TITLE);
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                PutWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        }
        else
        {
            if (ShouldShowMoveRelearner())
                ShowMoveRelearner();
            ShowInfoPrompt();
        }
        break;
    }

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        PutWindowTilemap(sMonSummaryScreen->windowIds[i]);

    ScheduleBgCopyTilemapToVram(0);
}

static void ClearPageWindowTilemaps(u8 page)
{
    u8 i;

    switch (page)
    {
    case PSS_PAGE_INFO:
        ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_CANCEL);
        break;
    case PSS_PAGE_SKILLS:
        ClearWindowTilemap(PSS_LABEL_WINDOW_POKEMON_SKILLS_EXP);
        if (SWSH_SUMMARY_SHOW_IV_EV)
        {
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_STATS);
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_EVS);
            ClearWindowTilemap(PSS_LABEL_WINDOW_PROMPT_IVS);
        }
        break;
    case PSS_PAGE_BATTLE_MOVES:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                ClearWindowTilemap(PSS_LABEL_WINDOW_MOVES_POWER_ACC);
        }
        else
        {
            if (ShouldShowMoveRelearner())
                HideMoveRelearner();
            HideInfoPrompt();
        }
        break;
    }

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        RemoveWindowByIndex(i);

    ScheduleBgCopyTilemapToVram(0);
}

static u8 AddWindowFromTemplateList(const struct WindowTemplate *template, u8 templateId)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[templateId];
    if (*windowIdPtr == WINDOW_NONE)
    {
        *windowIdPtr = AddWindow(&template[templateId]);
        FillWindowPixelBuffer(*windowIdPtr, PIXEL_FILL(0));
    }
    return *windowIdPtr;
}

static void RemoveWindowByIndex(u8 windowIndex)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[windowIndex];
    if (*windowIdPtr != WINDOW_NONE)
    {
        ClearWindowTilemap(*windowIdPtr);
        RemoveWindow(*windowIdPtr);
        *windowIdPtr = WINDOW_NONE;
    }
}

static void PrintPageSpecificText(u8 pageIndex)
{
    u16 i;
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
    {
        if (sMonSummaryScreen->windowIds[i] != WINDOW_NONE)
            FillWindowPixelBuffer(sMonSummaryScreen->windowIds[i], PIXEL_FILL(0));
    }
    sTextPrinterFunctions[pageIndex]();
}

static void CreateTextPrinterTask(u8 pageIndex)
{
    CreateTask(sTextPrinterTasks[pageIndex], 16);
}

static void PrintInfoPageText(void)
{
    if (sMonSummaryScreen->summary.isEgg)
    {
        PrintMonDexNumberSpecies();
        PrintEggState();
    }
    else
    {
        PrintMonOTName();
        PrintMonOTID();
        PrintMonDexNumberSpecies();
        PrintHeldItemInfo();
        PrintMonNature();
        // BufferMonTrainerMemo();
        // PrintMonTrainerMemo();
    }
}

static void Task_PrintInfoPage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 1:
        PrintMonOTName();
        break;
    case 2:
        PrintMonOTID();
        break;
    case 3:
        PrintMonDexNumberSpecies();
        break;
    case 4:
        PrintHeldItemInfo();
        break;
    case 5:
        PrintMonNature();
        break;
    case 6:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintMonDexNumberSpecies(void)
{
    int windowId;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 dexNum = SpeciesToPokedexNum(summary->species); // not printing pokedex number

    windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_SPECIES);
    

    if (sMonSummaryScreen->summary.isEgg)
    {
        PrintTextOnWindow(windowId, gText_FiveMarks, 0, 3, 0, 0);
    }
    else
    {
        PrintTextOnWindow(windowId, GetSpeciesName(summary->species2), 0, 3, 0, 0);
        
        if (dexNum != 0xFFFF)
        {
            u8 digitCount = (NATIONAL_DEX_COUNT > 999 && IsNationalPokedexEnabled()) ? 4 : 3;

            StringCopy(gStringVar1, &gText_NumberClear01[0]);
            ConvertIntToDecimalStringN(gStringVar2, dexNum, STR_CONV_MODE_LEADING_ZEROS, digitCount);
            StringAppend(gStringVar1, gStringVar2);
            ConvertIntToDecimalStringN(gStringVar1, dexNum, STR_CONV_MODE_LEADING_ZEROS, digitCount);

            if (!IsMonShiny(mon))
            {
                PrintTextOnWindow(windowId, gStringVar1, 76, 3, 0, 0);
            }
            else
            {
                PrintTextOnWindow(windowId, gStringVar1, 76, 3, 0, 2);
            }
        }
    }

}

static void PrintMonOTName(void)
{
    int windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_SPECIES);
    // int windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID);
    if (InBattleFactory() != TRUE && InSlateportBattleTent() != TRUE)
    {
        PrintTextOnWindow(windowId, sMonSummaryScreen->summary.OTName, 0, 37, 0, 0);
        // if (sMonSummaryScreen->summary.OTGender == 0)
        //     PrintTextOnWindow(windowId, sMonSummaryScreen->summary.OTName, 0, 0, 0, 5);
        // else
        //     PrintTextOnWindow(windowId, sMonSummaryScreen->summary.OTName, 0, 0, 0, 6);
    }
    else
    {
        StringCopy(gStringVar1, sText_RentalPkmn);
        PrintTextOnWindow(windowId, gStringVar1, 0, 37, 0, 0);
    }
}

static void PrintMonOTID(void)
{
    if (InBattleFactory() != TRUE && InSlateportBattleTent() != TRUE)
    {
        ConvertIntToDecimalStringN(gStringVar1, (u16)sMonSummaryScreen->summary.OTID, STR_CONV_MODE_LEADING_ZEROS, 5);
        PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_SPECIES), gStringVar1, 71, 37, 0, 0);
    }
}

static void PrintMonNature(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    
    StringCopy(gStringVar4, gNaturesInfo[sum->nature].name);
    PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_SPECIES), gStringVar4, 0, 54, 0, 5);
}

static void PrintMonAbilityName(void)
{
    u16 ability = GetAbilityBySpecies(sMonSummaryScreen->summary.species, sMonSummaryScreen->summary.abilityNum);
    PrintTextOnWindow(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_ABILITY), gAbilitiesInfo[ability].name, 48, 5, 0, 0);
}

static void PrintMonAbilityDescription(void)
{
    u16 ability = GetAbilityBySpecies(sMonSummaryScreen->summary.species, sMonSummaryScreen->summary.abilityNum);
    PrintTextOnWindow(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_ABILITY), gAbilitiesInfo[ability].description, 0, 22, 0, 0);
}

static void UNUSED BufferMonTrainerMemo(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    const u8 *text;
    bool32 locationFound = sum->metLocation < MAPSEC_NONE;

    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sMemoNatureTextColor);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sMemoMiscTextColor);
    BufferNatureString();

    if (InBattleFactory() == TRUE || InSlateportBattleTent() == TRUE || IsInGamePartnerMon() == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_XNature);
    }
    else
    {
        u8 *metLevelString = Alloc(32);
        u8 *metLocationString = Alloc(32);
        GetMetLevelString(metLevelString);

        if (locationFound)
        {
            GetMapNameHandleAquaHideout(metLocationString, sum->metLocation);
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
        }

        text = gText_XNature;

        if (DoesMonOTMatchOwner() == TRUE)
        {
            if (sum->metLevel == 0)
                text = (!locationFound) ? gText_XNatureHatchedSomewhereAt : gText_XNatureHatchedAtYZ;
            else
                text = (!locationFound) ? gText_XNatureMetSomewhereAt : gText_XNatureMetAtYZ;
        }
        else if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
        {
            text = gText_XNatureFatefulEncounter;
        }
        else if (sum->metLocation != METLOC_IN_GAME_TRADE && DidMonComeFromGBAGames())
        {
            text = (!locationFound) ? gText_XNatureObtainedInTrade : gText_XNatureProbablyMetAt;
        }
        else
        {
            text = gText_XNatureObtainedInTrade;
        }

        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, text);



        Free(metLevelString);
        Free(metLocationString);
    }
}

static void UNUSED PrintMonTrainerMemo(void)
{
    PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_MEMO), gStringVar4, 16, 4, 0, 0);
}

static void BufferNatureString(void)
{
    struct PokemonSummaryScreenData *sumStruct = sMonSummaryScreen;
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gNaturesInfo[sumStruct->summary.nature].name);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, gText_EmptyString5);
}

static void GetMetLevelString(u8 *output)
{
    u8 level = sMonSummaryScreen->summary.metLevel;
    if (level == 0)
        level = EGG_HATCH_LEVEL;
    ConvertIntToDecimalStringN(output, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, output);
}

static bool8 DoesMonOTMatchOwner(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u32 trainerId;
    u8 gender;

    if (sMonSummaryScreen->monList.mons == gEnemyParty)
    {
        u8 multiID = GetMultiplayerId() ^ 1;
        trainerId = gLinkPlayers[multiID].trainerId & 0xFFFF;
        gender = gLinkPlayers[multiID].gender;
        StringCopy(gStringVar1, gLinkPlayers[multiID].name);
    }
    else
    {
        trainerId = GetPlayerIDAsU32() & 0xFFFF;
        gender = gSaveBlock2Ptr->playerGender;
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    }

    if (gender != sum->OTGender || trainerId != (sum->OTID & 0xFFFF) || StringCompareWithoutExtCtrlCodes(gStringVar1, sum->OTName))
        return FALSE;
    else
        return TRUE;
}

static bool8 DidMonComeFromGBAGames(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

static bool8 DidMonComeFromRSE(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_EMERALD)
        return TRUE;
    return FALSE;
}

static bool8 IsInGamePartnerMon(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gMain.inBattle)
    {
        if (sMonSummaryScreen->curMonIndex == 1 || sMonSummaryScreen->curMonIndex == 4 || sMonSummaryScreen->curMonIndex == 5)
            return TRUE;
    }
    return FALSE;
}

static void UNUSED PrintEggOTName(void)
{
    // u32 windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID);
    // PrintTextOnWindow(windowId, gText_FiveMarks, 0, 4, 0, 0);
}

static void UNUSED PrintEggOTID(void)
{
    // StringCopy(gStringVar1, gText_FiveMarks);
    // PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_OT_OTID), gStringVar1, 66, 4, 0, 0);
}

static void UNUSED PrintEggState(void)
{
    const u8 *text;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;

    // FillWindowPixelBuffer(PSS_DATA_WINDOW_INFO_ITEM, PIXEL_FILL(1));

    if (sMonSummaryScreen->summary.sanity == TRUE)
        text = gText_EggWillTakeALongTime;
    else if (sum->friendship <= 5)
        text = gText_EggAboutToHatch;
    else if (sum->friendship <= 10)
        text = gText_EggWillHatchSoon;
    else if (sum->friendship <= 40)
        text = gText_EggWillTakeSomeTime;
    else
        text = gText_EggWillTakeALongTime;
    text = gText_EmptyString5;

    PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_ITEM), text, 16, 4, 0, 0);
}

static void UNUSED PrintEggMemo(void)
{
    const u8 *text;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;

    if (sMonSummaryScreen->summary.sanity != 1)
    {
        if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
            text = gText_PeculiarEggNicePlace;
        else if (DidMonComeFromGBAGames() == FALSE || DoesMonOTMatchOwner() == FALSE)
            text = gText_PeculiarEggTrade;
        else if (sum->metLocation == METLOC_SPECIAL_EGG)
            text = (DidMonComeFromRSE() == TRUE) ? gText_EggFromHotSprings : gText_EggFromTraveler;
        else
            text = gText_OddEggFoundByCouple;
    }
    else
    {
        text = gText_OddEggFoundByCouple;
    }

    PrintTextOnWindow(AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_MEMO), text, 16, 28, 0, 0);
}

static void PrintSkillsPageText(void)
{
    //ravetodo handle ribbons
    //PrintRibbonCount();
    PrintMonAbilityName();
    PrintMonAbilityDescription();
    PrintStatLabels();
    BufferHPStats();
    PrintHPStats(SKILL_STATE_STATS);
    BufferNonHPStats();
    PrintNonHPStats();
    PrintExpPointsNextLevel();
}

// Update the task function to include stat label printing as a separate step
static void Task_PrintSkillsPage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintMonAbilityName();
        break;
    case 2:
        PrintMonAbilityDescription();
        break;
    case 3:
        PrintStatLabels();
        break;
    case 4:
        BufferHPStats();
        break;
    case 5:
        PrintHPStats(SKILL_STATE_STATS);
        break;
    case 6:
        BufferNonHPStats();
        break;
    case 7:
        PrintNonHPStats();
        break;
    case 8:
        PrintExpPointsNextLevel();
        break;
    case 9:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintHeldItemInfo(void)
{
    const u8 *text;
    const u8 *description;
    u8 desc[200];
    u32 fontId;
    u8 windowId = AddWindowFromTemplateList(sPageInfoTemplate, PSS_DATA_WINDOW_INFO_ITEM);

    if (sMonSummaryScreen->summary.item == ITEM_ENIGMA_BERRY_E_READER
        && IsMultiBattle() == TRUE
        && (sMonSummaryScreen->curMonIndex == 1 || sMonSummaryScreen->curMonIndex == 4 || sMonSummaryScreen->curMonIndex == 5))
    {
        text = GetItemName(ITEM_ENIGMA_BERRY_E_READER);
        description = GetItemDescription(ITEM_ENIGMA_BERRY_E_READER);
    }
    else if (sMonSummaryScreen->summary.item == ITEM_NONE)
    {
        text = sText_Empty;
        description = sText_Empty;
    }
    else
    {
        CopyItemName(sMonSummaryScreen->summary.item, gStringVar1);
        text = gStringVar1;
        description = GetItemDescription(sMonSummaryScreen->summary.item);
    }

    fontId = GetFontIdToFit(text, FONT_SHORT_NARROW, 0, 72);
    PrintTextOnWindowWithFont(windowId, text, 74, 5, 0, 0, fontId);
    
    fontId = FormatTextByWidth(desc, 144, FONT_SHORT_NARROW, description, GetFontAttribute(FONT_SHORT_NARROW, FONTATTR_LETTER_SPACING));
    PrintTextOnWindowWithFont(windowId, desc, 0, 23, 1, 0, fontId);
}

static void UNUSED PrintRibbonCount(void)
{
    const u8 *text;
    int x;

    if (sMonSummaryScreen->summary.ribbonCount == 0)
    {
        text = sText_None;
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, sMonSummaryScreen->summary.ribbonCount, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, gText_RibbonsVar1);
        text = gStringVar4;
    }

    x = GetStringCenterAlignXOffset(FONT_NORMAL, text, 70) + 6;
    PrintTextOnWindow(AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_RIBBON_COUNT), text, x, 1, 0, 0);
}


static void BufferStat(u8 *dst, u32 stat, u32 strId, u32 align)
{
    // Simplified BufferStat that only converts to string, no nature coloring
    ConvertIntToDecimalStringN(dst, stat, STR_CONV_MODE_RIGHT_ALIGN, align);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(strId, dst);
}


static void BufferAndPrintStats_HandleState(u8 mode)
{
    u16 hp, hp2, atk, def, spA, spD, spe;
    u8 *currentHPString = Alloc(20);
    u8 *maxHPString = Alloc(20);

    switch (mode)
    {
    case SKILL_STATE_STATS:
    default:
        hp = sMonSummaryScreen->summary.currentHP;
        hp2 = sMonSummaryScreen->summary.maxHP;
        atk = sMonSummaryScreen->summary.atk;
        def = sMonSummaryScreen->summary.def;
        spA = sMonSummaryScreen->summary.spatk;
        spD = sMonSummaryScreen->summary.spdef;
        spe = sMonSummaryScreen->summary.speed;
        break;
    case SKILL_STATE_IVS:
        hp = sMonSummaryScreen->summary.ivHp;
        atk = sMonSummaryScreen->summary.ivAtk;
        def = sMonSummaryScreen->summary.ivDef;
        spA = sMonSummaryScreen->summary.ivSpatk;
        spD = sMonSummaryScreen->summary.ivSpdef;
        spe = sMonSummaryScreen->summary.ivSpeed;
        break;
    case SKILL_STATE_EVS:
        hp = sMonSummaryScreen->summary.evHp;
        atk = sMonSummaryScreen->summary.evAtk;
        def = sMonSummaryScreen->summary.evDef;
        spA = sMonSummaryScreen->summary.evSpatk;
        spD = sMonSummaryScreen->summary.evSpdef;
        spe = sMonSummaryScreen->summary.evSpeed;
        break;
    }

    FillWindowPixelBuffer(sMonSummaryScreen->windowIds[PSS_DATA_WINDOW_SKILLS_STATS], 0);

    // Add the stat labels printing here for mode switching
    PrintStatLabels();

    if (mode == SKILL_STATE_STATS)
    {
        ConvertIntToDecimalStringN(currentHPString, hp, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(maxHPString, hp2, STR_CONV_MODE_RIGHT_ALIGN, 3);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, currentHPString);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, maxHPString);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsHPLayout);
        PrintHPStats(mode);

        DynamicPlaceholderTextUtil_Reset();
        BufferStat(gStringVar1, atk, 0, 3);
        BufferStat(gStringVar2, def, 1, 3);
        BufferStat(gStringVar3, spA, 2, 3);
        BufferStat(gStringVar4, spD, 3, 3);
        BufferStat(sStringVar5, spe, 4, 3);
        PrintNonHPStats();
    }
    else
    {
        BufferStat(maxHPString, hp, 0, 7);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, maxHPString);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsHPIVEVLayout);
        PrintHPStats(mode);

        BufferStat(gStringVar1, atk, 0, 3);
        BufferStat(gStringVar2, def, 1, 3);
        BufferStat(gStringVar3, spA, 2, 3);
        BufferStat(gStringVar4, spD, 3, 3);
        BufferStat(sStringVar5, spe, 4, 3);
        PrintNonHPStats();
    }

    Free(currentHPString); 
    Free(maxHPString); 
}

static void BufferHPStats(void)
{
    u8 *currentHPString = Alloc(8);
    u8 *maxHPString = Alloc(8);

    ConvertIntToDecimalStringN(currentHPString, sMonSummaryScreen->summary.currentHP, STR_CONV_MODE_RIGHT_ALIGN, 3);
    ConvertIntToDecimalStringN(maxHPString, sMonSummaryScreen->summary.maxHP, STR_CONV_MODE_RIGHT_ALIGN, 3);

    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, currentHPString);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, maxHPString);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sStatsHPLayout);

    Free(currentHPString);
    Free(maxHPString);
}

static void PrintHPStats(u8 mode)
{
    u8 windowId = AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_STATS);
    PrintTextOnWindow(windowId, gStringVar4, 72 - GetStringWidth(FONT_SHORT_NARROW, gStringVar4, 0), 0, 0, 0);
}


static void BufferNonHPStats(void)
{
    DynamicPlaceholderTextUtil_Reset();
    BufferStat(gStringVar1, sMonSummaryScreen->summary.atk, 0, 3);
    BufferStat(gStringVar2, sMonSummaryScreen->summary.def, 1, 3);
    BufferStat(gStringVar3, sMonSummaryScreen->summary.spatk, 2, 3);
    BufferStat(gStringVar4, sMonSummaryScreen->summary.spdef, 3, 3);
    BufferStat(sStringVar5, sMonSummaryScreen->summary.speed, 4, 3);
}


static void PrintNonHPStats(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_STATS);
    
    PrintTextOnWindow(windowId, gStringVar1, 144 - GetStringWidth(FONT_SHORT_NARROW, gStringVar1, 0), 0, 0, 0);
    PrintTextOnWindow(windowId, gStringVar2, 72 - GetStringWidth(FONT_SHORT_NARROW, gStringVar2, 0), 16, 0, 0);
    PrintTextOnWindow(windowId, gStringVar3, 144 - GetStringWidth(FONT_SHORT_NARROW, gStringVar3, 0), 16, 0, 0);
    PrintTextOnWindow(windowId, gStringVar4, 72 - GetStringWidth(FONT_SHORT_NARROW, gStringVar4, 0), 32, 0, 0);
    PrintTextOnWindow(windowId, sStringVar5, 144 - GetStringWidth(FONT_SHORT_NARROW, sStringVar5, 0), 32, 0, 0);
}

static void PrintColoredStatLabel(u8 windowId, s8 statIndex, const u8 *text, u8 x, u8 y, 
                                  u8 natureUpStat, u8 natureDownStat, u8 *coloredLabel)
{
    static const u8 sTextNatureDown[] = _("{COLOR}{07}{SHADOW}{08}");
    static const u8 sTextNatureUp[] = _("{COLOR}{05}{SHADOW}{06}");
    static const u8 sTextNatureNeutral[] = _("{COLOR}{01}");
    
    const u8 *color;
    
    // Check for neutral nature first
    if (natureUpStat == natureDownStat)
    {
        color = sTextNatureNeutral;
    }
    else
    {
        color = (statIndex == natureUpStat) ? sTextNatureUp : 
                (statIndex == natureDownStat) ? sTextNatureDown : 
                sTextNatureNeutral;
    }
    
    StringCopy(coloredLabel, color);
    StringAppend(coloredLabel, text); 
    PrintTextOnWindow(windowId, coloredLabel, x, y, 0, 0);
}

// Add a function to just print the stat labels
static void PrintStatLabels(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_SKILLS_STATS);
    u8 coloredLabel[64];
    
    // Pre-calculate nature info once
    u8 natureUpStat = gNaturesInfo[sMonSummaryScreen->summary.mintNature].statUp;
    u8 natureDownStat = gNaturesInfo[sMonSummaryScreen->summary.mintNature].statDown;

    // Print HP label
    PrintTextOnWindow(windowId, sText_HP_Title, 8, 0, 0, 0);
    
    // Print non-HP stat labels (colored)
    PrintColoredStatLabel(windowId, STAT_ATK, sText_Attack_Title, 80, 0, natureUpStat, natureDownStat, coloredLabel);
    PrintColoredStatLabel(windowId, STAT_DEF, sText_Defense_Title, 8, 16, natureUpStat, natureDownStat, coloredLabel);
    PrintColoredStatLabel(windowId, STAT_SPATK, sText_SpAtk_Title, 80, 16, natureUpStat, natureDownStat, coloredLabel);
    PrintColoredStatLabel(windowId, STAT_SPDEF, sText_SpDef_Title, 8, 32, natureUpStat, natureDownStat, coloredLabel);
    PrintColoredStatLabel(windowId, STAT_SPEED, sText_Speed_Title, 80, 32, natureUpStat, natureDownStat, coloredLabel);
}

static void PrintExpPointsNextLevel(void)
{
    u32 expToNextLevel;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u8 windowId = AddWindowFromTemplateList(sPageSkillsTemplate, PSS_DATA_WINDOW_EXP);

    // print exp
    ConvertIntToDecimalStringN(gStringVar1, sum->exp, STR_CONV_MODE_RIGHT_ALIGN, 7);
    PrintTextOnWindow(windowId, sText_Exp, 8, 0, 0, 0);
    PrintTextOnWindow(windowId, gStringVar1, 72 - GetStringWidth(FONT_SHORT_NARROW, gStringVar1, 0), 0, 0, 0);
    

    // print exp to next level
    if (sum->level < MAX_LEVEL)
        expToNextLevel = gExperienceTables[gSpeciesInfo[sum->species].growthRate][sum->level + 1] - sum->exp;
    else
        expToNextLevel = 0;

    PrintTextOnWindow(windowId, sText_NextLv, 80, 0, 0, 0);
    ConvertIntToDecimalStringN(gStringVar1, expToNextLevel, STR_CONV_MODE_RIGHT_ALIGN, 5);
    PrintTextOnWindow(windowId, gStringVar1, 144 - GetStringWidth(FONT_SHORT_NARROW, gStringVar1, 0), 0, 0, 0);
}

static void PrintBattleMoves(void)
{
    PrintMoveNameAndPP(0);
    PrintMoveNameAndPP(1);
    PrintMoveNameAndPP(2);
    PrintMoveNameAndPP(3);

    if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
    {
        PrintNewMoveDetailsOrCancelText();
        if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE)
                PrintMoveDescription(sMonSummaryScreen->newMove);
        }
        else
        {
            PrintMoveDescription(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
        }
    }
}

static void Task_PrintBattleMoves(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 1:
        PrintMoveNameAndPP(0);
        break;
    case 2:
        PrintMoveNameAndPP(1);
        break;
    case 3:
        PrintMoveNameAndPP(2);
        break;
    case 4:
        PrintMoveNameAndPP(3);
        break;
    case 5:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
            PrintNewMoveDetailsOrCancelText();
        break;
    case 6:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
                data[1] = sMonSummaryScreen->newMove;
            else
                data[1] = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
        }
        break;
    case 7:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
        {
            if (sMonSummaryScreen->newMove != MOVE_NONE || sMonSummaryScreen->firstMoveIndex != MAX_MON_MOVES)
                PrintMoveDescription(data[1]);
        }
        break;
    case 8:
        DestroyTask(taskId);
        return;
    }
    data[0]++;
}

static void PrintMoveNameAndPP(u8 moveIndex)
{
    u8 pp;
    int ppState; // todo: figure out palettes compatible with dark bg
    const u8 *text;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 moveNameWindowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);

    u16 move = summary->moves[moveIndex];

    if (move != 0)
    {
        PrintTextOnWindowToFitPx_WithFont(moveNameWindowId, GetMoveName(move), 4, moveIndex * 18 + 4, 0, 4, FONT_SMALL, WindowWidthPx(moveNameWindowId) - 3);
        pp = CalculatePPWithBonus(move, summary->ppBonuses, moveIndex);
        ConvertIntToDecimalStringN(gStringVar1, summary->pp[moveIndex], STR_CONV_MODE_RIGHT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sMovesPPLayout);
        text = gStringVar4;
        ppState = GetCurrentPpToMaxPpState(summary->pp[moveIndex], pp);
    }
    else
    {
        PrintTextOnWindow(moveNameWindowId, gText_ThreeDashes, 4, moveIndex * 18 + 4, 0, 4);
        text = gText_TwoDashes;
        ppState = 3;
    }

    PrintTextOnWindowWithFont(moveNameWindowId, text, 121, moveIndex * 18 + 4, 0, ppState, FONT_SMALL);
}

static void PrintMovePowerAndAccuracy(u16 moveIndex)
{
    const u8 *text;
    u8 xPos;
    FillWindowPixelRect(PSS_LABEL_WINDOW_MOVES_POWER_ACC, PIXEL_FILL(0), 0, 0, 24, 34);

    if (moveIndex != MOVE_NONE)
    {
        if (gMovesInfo[moveIndex].power < 2)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[moveIndex].power, STR_CONV_MODE_LEFT_ALIGN, 3);
            text = gStringVar1;
        }
        xPos = 22 - GetStringWidth(FONT_SHORT_NARROW, text, 0);
        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, xPos, 2, 0, 0);

        if (gMovesInfo[moveIndex].accuracy == 0)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[moveIndex].accuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
            text = gStringVar1;
        }
        xPos = 22 - GetStringWidth(FONT_SHORT_NARROW, text, 0);
        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, xPos, 22, 0, 0);
    } else {
        text = gText_ThreeDashes;
        xPos = 22 - GetStringWidth(FONT_SHORT_NARROW, text, 0);
        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, xPos, 2, 0, 0);
        PrintTextOnWindow(PSS_LABEL_WINDOW_MOVES_POWER_ACC, text, xPos, 22, 0, 0);
    }
}



static void PrintMoveDescription(u16 move)
{
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
    u8 desc[SWSH_MAX_MOVE_DESCRIPTION_LENGTH];
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    if (move != MOVE_NONE)
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        {
            if (SWSH_SUMMARY_CATEGORY_ICONS)
                ShowCategoryIcon(move);

            PrintMovePowerAndAccuracy(move);

            if (SWSH_SUMMARY_AUTO_FORMAT_MOVE_DESCRIPTIONS)
            {
                u8 descFontId;
                if (gMovesInfo[move].effect != EFFECT_PLACEHOLDER)
                    descFontId = FormatTextByWidth(desc, 136, FONT_SHORT_NARROW, gMovesInfo[move].description, GetFontAttribute(FONT_SHORT_NARROW, FONTATTR_LETTER_SPACING));
                else
                    descFontId = FormatTextByWidth(desc, 136, FONT_SHORT_NARROW, gNotDoneYetDescription, GetFontAttribute(FONT_SHORT_NARROW, FONTATTR_LETTER_SPACING));

                PrintTextOnWindowWithFont(windowId, desc, 0, 4, 1, 0, descFontId);
            }
            else
            {
                if (gMovesInfo[move].effect != EFFECT_PLACEHOLDER)
                    PrintTextOnWindow(windowId, gMovesInfo[move].description, 0, 4, 1, 0);
                else
                    PrintTextOnWindow(windowId, gNotDoneYetDescription, 0, 4, 1, 0);
            }

        }
        PutWindowTilemap(windowId);
    }
    else
    {
        if (SWSH_SUMMARY_CATEGORY_ICONS)
            DestroyCategoryIcon();

        ClearWindowTilemap(windowId);
        PrintMovePowerAndAccuracy(MOVE_NONE);
    }

    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNewMoveDetailsOrCancelText(void)
{
    u8 windowId1 = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);
    u8 moveIndex = 4;

    if (sMonSummaryScreen->newMove == MOVE_NONE)
    {

        PrintTextOnWindowWithFont(windowId1, sText_Cancel, 4, 4 * 18 + 4, 0, 5, FONT_SMALL);
    }
    else
    {
        u16 move = sMonSummaryScreen->newMove;

        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            PrintTextOnWindowToFitPx_WithFont(windowId1, GetMoveName(move), 4, moveIndex * 18 + 4, 0, 4, FONT_SMALL, WindowWidthPx(windowId1) - 3);
        else
            PrintTextOnWindowToFitPx_WithFont(windowId1, GetMoveName(move), 4, moveIndex * 18 + 4, 0, 4, FONT_SMALL, WindowWidthPx(windowId1) - 3);

        ConvertIntToDecimalStringN(gStringVar1, gMovesInfo[move].pp, STR_CONV_MODE_RIGHT_ALIGN, 2);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar1);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, sMovesPPLayout);
        PrintTextOnWindowWithFont(windowId1, gStringVar4, 121, moveIndex * 18 + 4, 0, 3, FONT_SMALL);
    }
}

static void ClearCancelText(void)
{
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);
    FillWindowPixelRect(windowId, PIXEL_FILL(0), 0, 77, 72, 16);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2)
{
    u8 windowId1 = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_NAMES_PP);

    FillWindowPixelRect(windowId1, PIXEL_FILL(0), 4, moveIndex1 * 17 + 4, 144, 16);
    FillWindowPixelRect(windowId1, PIXEL_FILL(0), 4, moveIndex2 * 17 + 4, 144, 16);

    PrintMoveNameAndPP(moveIndex1);
    PrintMoveNameAndPP(moveIndex2);
}

static void PrintHMMovesCantBeForgotten(void)
{
    u8 message[200];
    u8 windowId = AddWindowFromTemplateList(sPageMovesTemplate, PSS_DATA_WINDOW_MOVE_DESCRIPTION);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));

    u8 msgFontId = FormatTextByWidth(message, 136, FONT_SHORT_NARROW, gText_HMMovesCantBeForgotten2, GetFontAttribute(FONT_SHORT_NARROW, FONTATTR_LETTER_SPACING));
    PrintTextOnWindowWithFont(windowId, message, 0, 4, 0, 2, msgFontId);
}

static void ShowCategoryIcon(u16 move)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] = CreateSprite(&sSpriteTemplate_CategoryIcons, 68, 129, 0);
    
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]].invisible = FALSE;

    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]], GetBattleMoveCategory(move));
}

static void DestroyCategoryIcon(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] != SPRITE_NONE)
        DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY]]);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_CATEGORY] = SPRITE_NONE;
}

static void ResetSpriteIds(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
        sMonSummaryScreen->spriteIds[i] = SPRITE_NONE;
}

static void DestroySpriteInArray(u8 spriteArrayId)
{
    if (sMonSummaryScreen->spriteIds[spriteArrayId] != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]]);
        sMonSummaryScreen->spriteIds[spriteArrayId] = SPRITE_NONE;
    }
}

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]].invisible = invisible;
}

static void HidePageSpecificSprites(void)
{
    // Keeps Pokemon, caught ball, and status sprites visible.
    u8 i;

    for (i = SPRITE_ARR_ID_POKERUS_CURED; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
    {
        if (sMonSummaryScreen->spriteIds[i] != SPRITE_NONE)
            SetSpriteInvisibility(i, TRUE);
    }
    sMonSummaryScreen->markingsSprite->invisible = TRUE;
}

static void SetTypeIcons(void)
{
    switch (sMonSummaryScreen->currPageIndex)
    {
    case PSS_PAGE_INFO:
        SetMonTypeIcons();
        break;
    case PSS_PAGE_BATTLE_MOVES:
        SetMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    }
}

static void TrySetInfoPageIcons(void)
{
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
    { 
        SetPokerusCuredSprite();
        SetShinySprite();
        CreateHeldItemBoxSprites();
        CreateHeldItemSprite();
        // // Hold off on printing friendship
        if (SWSH_SUMMARY_SHOW_FRIENDSHIP)
            SetFriendshipSprite();
    }
}

static void CreateMoveTypeIcons(void)
{
    u8 i;

    for (i = SPRITE_ARR_ID_TERA_TYPE; i < SPRITE_ARR_ID_TYPE + TYPE_ICON_SPRITE_COUNT; i++)
    {
        if (sMonSummaryScreen->spriteIds[i] == SPRITE_NONE)
        {
            if (i == SPRITE_ARR_ID_TERA_TYPE)
            {
                if (SWSH_SUMMARY_SHOW_TERA_TYPE)
                    sMonSummaryScreen->spriteIds[i] = CreateSprite(&sSpriteTemplate_TeraType, 0, 0, 2);
            }
            else
            {
                sMonSummaryScreen->spriteIds[i] = CreateSprite(&sSpriteTemplate_MoveTypes, 0, 0, 2);
            }
        }

        SetSpriteInvisibility(i, TRUE);
    }
}

static void SetTypeSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    if (typeId < NUMBER_OF_MON_TYPES)
        sprite->oam.paletteNum = gTypesInfo[typeId].palette;
    sprite->x = x + 16;
    sprite->y = y + 7; // shift up by 1 to accomodate gen 8 type badges
    SetSpriteInvisibility(spriteArrayId, FALSE);
}

static void SetMonTypeIcons(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    if (summary->isEgg)
    {
        SetTypeSpritePosAndPal(TYPE_MYSTERY, 56, 43, SPRITE_ARR_ID_TYPE);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
        if (SWSH_SUMMARY_SHOW_TERA_TYPE)
            SetSpriteInvisibility(SPRITE_ARR_ID_TERA_TYPE, TRUE);
    }
    else
    {
        SetTypeSpritePosAndPal(gSpeciesInfo[summary->species].types[0], 56, 43, SPRITE_ARR_ID_TYPE);
        if (gSpeciesInfo[summary->species].types[0] != gSpeciesInfo[summary->species].types[1])
        {
            SetTypeSpritePosAndPal(gSpeciesInfo[summary->species].types[1], 92, 43, SPRITE_ARR_ID_TYPE + 1);
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, FALSE);
        }
        else
        {
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
        }
        if (SWSH_SUMMARY_SHOW_TERA_TYPE)
        {
            SetTypeSpritePosAndPal(summary->teraType, 124, 44, SPRITE_ARR_ID_TERA_TYPE);
        }
    }
}

static void SetMoveTypeIcons(void)
{
    u8 i;
    u16 move;
    u32 type;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        move = summary->moves[i];
        if (move != MOVE_NONE)
        {
            enum MonState state = gMain.inBattle ? MON_IN_BATTLE : MON_OUTSIDE_BATTLE;
            type = P_SHOW_DYNAMIC_TYPES ? CheckDynamicMoveType(&sMonSummaryScreen->currentMon, move, 0, state) : GetMoveType(move);
            SetTypeSpritePosAndPal(type, 96, 27 + (i * 18), i + SPRITE_ARR_ID_TYPE);
        }
        else
        {
            SetSpriteInvisibility(i + SPRITE_ARR_ID_TYPE, TRUE);
        }
            
    }
}


static void SetNewMoveTypeIcon(void)
{
    u32 move = sMonSummaryScreen->newMove;
    u8 i = 4;
    
    if (move == MOVE_NONE)
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 4, TRUE);
    }
    else
    {
        enum MonState state = gMain.inBattle ? MON_IN_BATTLE : MON_OUTSIDE_BATTLE;
        u32 type = P_SHOW_DYNAMIC_TYPES ? CheckDynamicMoveType(&sMonSummaryScreen->currentMon, move, 0, state) : GetMoveType(move);
        SetTypeSpritePosAndPal(type, 96, 27 + (i * 18), SPRITE_ARR_ID_TYPE + 4);
    }
}

static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2)
{
    struct Sprite *sprite1 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex1 + SPRITE_ARR_ID_TYPE]];
    struct Sprite *sprite2 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex2 + SPRITE_ARR_ID_TYPE]];

    u8 temp = sprite1->animNum;
    sprite1->animNum = sprite2->animNum;
    sprite2->animNum = temp;

    temp = sprite1->oam.paletteNum;
    sprite1->oam.paletteNum = sprite2->oam.paletteNum;
    sprite2->oam.paletteNum = temp;

    sprite1->animBeginning = TRUE;
    sprite1->animEnded = FALSE;
    sprite2->animBeginning = TRUE;
    sprite2->animEnded = FALSE;
}

static u8 LoadMonGfxAndSprite(struct Pokemon *mon, s16 *state, bool32 isShadow)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    switch (*state)
    {
    default:
        return CreateMonSprite(mon, isShadow);
    case 0:
        if (gMain.inBattle)
        {
            HandleLoadSpecialPokePic(TRUE,
                                     gMonSpritesGfxPtr->spritesGfx[B_POSITION_OPPONENT_LEFT],
                                     summary->species2,
                                     summary->pid);
        }
        else
        {
            if (gMonSpritesGfxPtr != NULL)
            {
                HandleLoadSpecialPokePic(TRUE,
                                         gMonSpritesGfxPtr->spritesGfx[B_POSITION_OPPONENT_LEFT],
                                         summary->species2,
                                         summary->pid);
            }
            else
            {
                HandleLoadSpecialPokePic(TRUE,
                                         MonSpritesGfxManager_GetSpritePtr(MON_SPR_GFX_MANAGER_A, B_POSITION_OPPONENT_LEFT),
                                         summary->species2,
                                         summary->pid);
            }
        }
        (*state)++;
        return 0xFF;
    case 1:
        LoadSpritePaletteWithTag(GetMonSpritePalFromSpeciesAndPersonality(summary->species2, summary->isShiny, summary->pid), summary->species2);
        SetMultiuseSpriteTemplateToPokemon(summary->species2, B_POSITION_OPPONENT_LEFT);
        (*state)++;
        return 0xFF;
    }
}

static void PlayMonCry(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    if (!summary->isEgg)
    {
        if (ShouldPlayNormalMonCry(&sMonSummaryScreen->currentMon) == TRUE)
            PlayCry_ByMode(summary->species2, 0, CRY_MODE_NORMAL);
        else
            PlayCry_ByMode(summary->species2, 0, CRY_MODE_WEAK);
    }
}

static u8 CreateMonSprite(struct Pokemon *unused, bool32 isShadow)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 shadowPalette = 0;
    u8 spriteId = CreateSprite(&gMultiuseSpriteTemplate, 204, 76, 5);

    FreeSpriteOamMatrix(&gSprites[spriteId]);
    gSprites[spriteId].sSpecies = summary->species2;
    gSprites[spriteId].sDelayAnim = 0;
    gSprites[spriteId].sIsShadow = isShadow;
    gSprites[spriteId].callback = SpriteCB_Pokemon;
    gSprites[spriteId].oam.priority = 2;

    if (isShadow)
    {
        FreeSpritePaletteByTag(TAG_MON_SHADOW); // reload the palette entirely because some sprite anims modify it
        shadowPalette = LoadSpritePalette(&sSpritePal_MonShadow);
        gSprites[spriteId].oam.paletteNum = shadowPalette;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[spriteId].x -= 5;
        gSprites[spriteId].y -= 2;
    }

    return spriteId;
}

static void SpriteCB_Pokemon(struct Sprite *sprite)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (!gPaletteFade.active && sprite->sDelayAnim != 1)
    {
        sprite->sDontFlip = TRUE;

        if (!sMonSummaryScreen->monAnimPlayed) // only play cry on the first time mon is animated
            PlayMonCry();

        PokemonSummaryDoMonAnimation(sprite, sprite->sSpecies, summary->isEgg, sprite->sIsShadow);
        sMonSummaryScreen->monAnimPlayed = TRUE;
    }
}

#undef sSpecies
#undef sDontFlip
#undef sDelayAnim
#undef sIsShadow

// Track and then destroy Task_PokemonSummaryAnimateAfterDelay
// Normally destroys itself but it can be interrupted before the animation starts
void SummaryScreen_SetAnimDelayTaskId_SwSh(u8 taskId)
{
    sAnimDelayTaskId = taskId;
}

void SummaryScreen_SetShadowAnimDelayTaskId_SwSh(u8 taskId)
{
    sShadowAnimDelayTaskId = taskId;
}

static void SummaryScreen_DestroyAnimDelayTask(void)
{
    if (sAnimDelayTaskId != TASK_NONE)
    {
        DestroyTask(sAnimDelayTaskId);
        sAnimDelayTaskId = TASK_NONE;
    }
    if (sShadowAnimDelayTaskId != TASK_NONE)
    {
        DestroyTask(sShadowAnimDelayTaskId);
        sShadowAnimDelayTaskId = TASK_NONE;
    }
}

static bool32 UNUSED IsMonAnimationFinished(void)
{
    if (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback == SpriteCallbackDummy)
        return FALSE;
    else
        return TRUE;
}

static void StopPokemonAnimations(void)  // A subtle effect, this function stops Pokémon animations when leaving the PSS
{
    u16 i;
    u16 paletteIndex;

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].animPaused = TRUE;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback = SpriteCallbackDummy;
    if (SWSH_SUMMARY_MON_SHADOWS)
    {
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].animPaused = TRUE;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHADOW]].callback = SpriteCallbackDummy;
    }
    StopPokemonAnimationDelayTask();

    paletteIndex = OBJ_PLTT_ID(gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.paletteNum);

    for (i = 0; i < 16; i++)
    {
        u16 id = i + paletteIndex;
        gPlttBufferUnfaded[id] = gPlttBufferFaded[id];
    }
}


static void CreateMonMarkingsSprite(struct Pokemon *mon)
{
    struct Sprite *sprite = CreateMonMarkingAllCombosSprite(TAG_MON_MARKINGS, TAG_MON_MARKINGS, sMarkings_Pal);

    sMonSummaryScreen->markingsSprite = sprite;
    if (sprite != NULL)
    {
        StartSpriteAnim(sprite, GetMonData(mon, MON_DATA_MARKINGS));
        sMonSummaryScreen->markingsSprite->x = 137;
        sMonSummaryScreen->markingsSprite->y = 87;
        sMonSummaryScreen->markingsSprite->oam.priority = 2;
        if (sMonSummaryScreen->currPageIndex != PSS_PAGE_INFO)
            sMonSummaryScreen->markingsSprite->invisible = TRUE;
    }
}

static void SetPokerusCuredSprite(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_POKERUS_CURED] == SPRITE_NONE)
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_POKERUS_CURED] = CreateSprite(&sSpriteTemplate_PokerusCuredIcon, 117, 87, 0);

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_POKERUS_CURED]].invisible = (CheckPartyPokerus(mon, 0) || !CheckPartyHasHadPokerus(mon, 0));
}

static void SetShinySprite(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY] = CreateSprite(&sSpriteTemplate_ShinyIcon, 126, 34, 6);

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SHINY]].invisible = !IsMonShiny(mon);
}

bool8 MonHasGigantamaxFactor(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_GIGANTAMAX_FACTOR, NULL);
}

static void CreateGigantamaxSprite(void)
{   
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u8 *spriteId = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_GIGANTAMAX];

    if (*spriteId == SPRITE_NONE)
        *spriteId = CreateSprite(&sSpriteTemplate_GigantamaxIcon, 114, 17, 6);

    gSprites[*spriteId].invisible = !MonHasGigantamaxFactor(mon);
}

static void SetFriendshipSprite(void)
{
    u8 level = FRIENDSHIP_LEVEL_0;
    
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP] = CreateSprite(&sSpriteTemplate_FriendshipIcon, 233, 32, 0);

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP]].invisible = FALSE;
    
    // don't even think about swapping the order of the conditions here or the compiler will smite you for your arrogance
    // I have no idea why it works that way
    while (level < FRIENDSHIP_LEVEL_MAX && sMonSummaryScreen->summary.friendship >= sFriendshipLevelToThreshold[level + 1])
        level++;

    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_FRIENDSHIP]], level);
}

static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon)
{
    DestroySprite(sMonSummaryScreen->markingsSprite);
    FreeSpriteTilesByTag(TAG_MON_MARKINGS);
    CreateMonMarkingsSprite(mon);
}

static void CreateCaughtBallSprite(struct Pokemon *mon)
{
    u8 ball = ItemIdToBallId(GetMonData(mon, MON_DATA_POKEBALL));

    LoadBallGfx(ball);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL] = CreateSprite(&gBallSpriteTemplates[ball], 95, 16, 6);
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].callback = SpriteCallbackDummy;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].oam.priority = 1;
}

static void CreateHeldItemBoxSprites(void)
{
    u16 itemId = sMonSummaryScreen->summary.item;
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_HELD_ITEM_BOX];
    
    // Always destroy old sprites first
    DestroyHeldItemBoxSprites();
    
    // Only create sprites if mon has an item
    if (itemId == ITEM_NONE)
        return;
    
    for (i = 0; i < HELD_ITEM_BOX_SPRITES_COUNT; i++)
    {
        spriteIds[i] = CreateSprite(&sSpriteTemplate_HeldItemBox, 16 + (i * 32), 96 + 32, 2);
        
        if (spriteIds[i] != MAX_SPRITES)
        {
            if (i == 0)
                StartSpriteAnim(&gSprites[spriteIds[i]], 0);  // First unique
            else if (i == 1)
                StartSpriteAnim(&gSprites[spriteIds[i]], 1);  // Second unique
            else
                StartSpriteAnim(&gSprites[spriteIds[i]], 2);  // Repeating
        }
    }
}

static void DestroyHeldItemBoxSprites(void)
{
    u8 i;    
    for (i = 0; i < HELD_ITEM_BOX_SPRITES_COUNT; i++)
        DestroySpriteInArray(SPRITE_ARR_ID_HELD_ITEM_BOX + i);
}

static void CreateHeldItemSprite(void)
{
    u16 itemId = sMonSummaryScreen->summary.item;
    u8 spriteId;
    
    // Always destroy old sprite first
    DestroyHeldItemIconSprite();
    
    // Only create new sprite if mon has an item
    if (itemId == ITEM_NONE)
        return;
    
    spriteId = AddItemIconSprite(TAG_HELD_ITEM_ICON, TAG_HELD_ITEM_ICON, itemId);
    
    if (spriteId != MAX_SPRITES)
    {
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM] = spriteId;
        gSprites[spriteId].x = 70;  // Set your desired x position
        gSprites[spriteId].y = 112;   // Set your desired y position
    }
}

static void DestroyHeldItemIconSprite(void)
{
    u8 spriteId = sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM];
    
    if (spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_HELD_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_HELD_ITEM_ICON);
        DestroySprite(&gSprites[spriteId]);
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM] = SPRITE_NONE;
    }
}

static void CreateStatusSprite(void)
{
    u8 *spriteId = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS];
    u8 statusAnim;

    if (*spriteId == SPRITE_NONE)
        *spriteId = CreateSprite(&sSpriteTemplate_StatusCondition, 205, 16, 6); // moved from 213 to 179 to print status where level is.

    statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static void HandleStatusSprite(struct Pokemon *mon)
{
    u8 statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS]], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static void CreateMoveSelectorSprites(u8 idArrayStart)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[idArrayStart];

    if (sMonSummaryScreen->currPageIndex >= PSS_PAGE_BATTLE_MOVES)
    {
        u8 subpriority = 0;
        if (idArrayStart == SPRITE_ARR_ID_MOVE_SELECTOR1)
            subpriority = 1;

        for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        {
            spriteIds[i] = CreateSprite(&sMoveSelectorSpriteTemplate, i * 16 + 17, 43, subpriority);
            if (i == 0)
                StartSpriteAnim(&gSprites[spriteIds[i]], 4); // left
            else if (i == MOVE_SELECTOR_SPRITES_COUNT - 1)
                StartSpriteAnim(&gSprites[spriteIds[i]], 5); // right, actually the same as left, but flipped
            else
                StartSpriteAnim(&gSprites[spriteIds[i]], 6); // middle

            gSprites[spriteIds[i]].callback = SpriteCB_MoveSelector;
            gSprites[spriteIds[i]].data[0] = idArrayStart;
            gSprites[spriteIds[i]].data[1] = 0;
        }
    }
}

static void SpriteCB_MoveSelector(struct Sprite *sprite)
{
    if (sprite->animNum > 3 && sprite->animNum < 7)
    {
        sprite->data[1] = (sprite->data[1] + 1) & 0x1F;
        if (sprite->data[1] > 24)
            sprite->invisible = FALSE; // Set to FALSE so selector doesn't blink. Probably more simple ways to disable.
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->data[1] = 0;
        sprite->invisible = FALSE;
    }

    if (sprite->data[0] == SPRITE_ARR_ID_MOVE_SELECTOR1)
        sprite->y2 = sMonSummaryScreen->firstMoveIndex * 18;
    else
        sprite->y2 = sMonSummaryScreen->secondMoveIndex * 18;
}

static void DestroyMoveSelectorSprites(u8 firstArrayId)
{
    u8 i;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        DestroySpriteInArray(firstArrayId + i);
}

static void SetMainMoveSelectorColor(u8 which)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MOVE_SELECTOR1];

    which *= 3;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        if (i == 0)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 4);
        else if (i == MOVE_SELECTOR_SPRITES_COUNT - 1)
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 5);
        else
            StartSpriteAnim(&gSprites[spriteIds[i]], which + 6);
    }
}

static void KeepMoveSelectorVisible(u8 firstSpriteId)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[firstSpriteId];

    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        gSprites[spriteIds[i]].data[1] = 0;
        gSprites[spriteIds[i]].invisible = FALSE;
    }
}

// New helper function that performs the formatting logic
static u8 PerformTextFormatting(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing, u32 *outLineCount)
{
    u8 *end, *ptr, *curLine, *lastSpace;
    
    end = result;
    // copy string, replacing spaces and line breaks with EOS
    // EXCEPT: if newline follows a hyphen, skip the newline without adding EOS
    while (*str != EOS)
    {
        if (*str == CHAR_SPACE || *str == CHAR_NEWLINE)
        {
            // Skip newline after hyphen, otherwise mark as break point
            if (!(*str == CHAR_NEWLINE && end > result && *(end - 1) == CHAR_HYPHEN))
            {
                *end = EOS;
                end++;
            }
        }
        else
        {
            // Regular character - copy it
            *end = *str;
            end++;
        }
        
        str++;
    }
    *end = EOS; // now end points to the true end of the string

    // Step 2: Remove hyphens for specific words only
    u8 *p = result;
    while (p < end)
    {
        if (*p == CHAR_HYPHEN && ShouldRemoveHyphen(p, result, end))
        {
            u8 *dst = p;
            u8 *src = p + 1;
            while (src <= end)
                *dst++ = *src++;
            end--;
        }
        else
        {
            p++;
        }
    }

    ptr = result;
    curLine = ptr;
    *outLineCount = 1;

    while (*ptr != EOS)
        ptr++;
    // now ptr is the first EOS char

    while (ptr != end)
    {
        // all the EOS chars (except *end) must be replaced by either ' ' or '\n'
        lastSpace = ptr++; // this points at the EOS

        // check that adding the next word this line still fits
        *lastSpace = CHAR_SPACE;
        if (GetStringWidth(fontId, curLine, letterSpacing) > maxWidth)
        {
            *lastSpace = CHAR_NEWLINE;
            (*outLineCount)++;
            curLine = ptr;
        }

        while (*ptr != EOS)
            ptr++;
        // now ptr is the next EOS char
    }
    
    // Check if the last line also fits within maxWidth
    return (GetStringWidth(fontId, curLine, letterSpacing) <= maxWidth);
}

// Original FormatTextByWidth function by Vexx on Ravepossum's branch
// Modified here to use PerformTextFormatting and try 1-font narrower if needed
static u8 FormatTextByWidth(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing)
{
    u32 lineCount;
    bool32 lastLineFits;
    
    // Try formatting with progressively narrower fonts until it fits in 2 lines or fewer
    while (TRUE)
    {
        lastLineFits = PerformTextFormatting(result, maxWidth, fontId, str, letterSpacing, &lineCount);
        
        // If we have 2 or fewer lines AND the last line fits, we're done
        if (lineCount < 3 && lastLineFits)
            break;
        
        // Try to get a narrower font
        u8 narrowerFontId = fontId;
        if (fontId == FONT_SHORT_NARROW)
            narrowerFontId = FONT_SHORT_NARROWER;
        
        // If no narrower font available, use what we have
        if (narrowerFontId == fontId)
            break;
        
        fontId = narrowerFontId;
        letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    }
    
    return fontId;
}

static inline bool32 ShouldShowMoveRelearner(void)
{
    return (P_SUMMARY_SCREEN_MOVE_RELEARNER
         && !sMonSummaryScreen->lockMovesFlag
         && sMonSummaryScreen->mode != SUMMARY_MODE_BOX
         && sMonSummaryScreen->mode != SUMMARY_MODE_BOX_CURSOR
         && sMonSummaryScreen->relearnableMovesNum > 0
         && !InBattleFactory() 
         && !InSlateportBattleTent());
}

static void ShowMoveRelearner(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_RELEARN_PROMPT] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_RELEARN_PROMPT] = CreateSprite(&sSpriteTemplate_RelearnPrompt, 169, 164, 0);
    
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_RELEARN_PROMPT]].invisible = FALSE;
}

static void HideMoveRelearner(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_RELEARN_PROMPT] != SPRITE_NONE)
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_RELEARN_PROMPT]].invisible = TRUE;
}

static void ShowInfoPrompt(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_INFO_PROMPT] == SPRITE_NONE)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_INFO_PROMPT] = CreateSprite(&sSpriteTemplate_InfoPrompt, 221, 152, 0);
    
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_INFO_PROMPT]].invisible = FALSE;
}

static void HideInfoPrompt(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_INFO_PROMPT] != SPRITE_NONE)
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_INFO_PROMPT]].invisible = TRUE;
}

static inline bool32 ShouldShowRename(void)
{
    return (P_SUMMARY_SCREEN_RENAME
         && !sMonSummaryScreen->lockMovesFlag
         && !sMonSummaryScreen->summary.isEgg
         && sMonSummaryScreen->mode != SUMMARY_MODE_BOX
         && sMonSummaryScreen->mode != SUMMARY_MODE_BOX_CURSOR
         && !InBattleFactory() 
         && !InSlateportBattleTent()
         && GetPlayerIDAsU32() == sMonSummaryScreen->summary.OTID);
}

static void ShowCancelOrRenamePrompt(void)
{
    const u8 *promptText = ShouldShowRename() ? sText_Rename : sText_Cancel;

    int stringXPos = GetStringRightAlignXOffset(FONT_SHORT_NARROW, promptText, 70) - 2;
    int iconXPos;
    
    if (ShouldShowRename())
    {
        iconXPos = stringXPos - 31;
        if (iconXPos < 0)
            iconXPos = 0;
        PrintButtonIcon(PSS_LABEL_WINDOW_PROMPT_CANCEL, BUTTON_START, iconXPos, 4);
        PrintTextOnWindowWithFont(PSS_LABEL_WINDOW_PROMPT_CANCEL, promptText, stringXPos, 0, 0, 1, FONT_SMALL);
    }
    else 
    {
        iconXPos = stringXPos - 11;
        if (iconXPos < 0)
            iconXPos = 0;
        PrintButtonIcon(PSS_LABEL_WINDOW_PROMPT_CANCEL, BUTTON_B, iconXPos, 4);
        PrintTextOnWindowWithFont(PSS_LABEL_WINDOW_PROMPT_CANCEL, promptText, stringXPos, 0, 0, 1, FONT_SMALL);
    }
}

static void CB2_ReturnToSummaryScreenFromNamingScreen(void)
{
    SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_NICKNAME, gStringVar2);
    ShowPokemonSummaryScreen_SwSh(SUMMARY_MODE_NORMAL, gPlayerParty, gSpecialVar_0x8004, gPlayerPartyCount - 1, gInitialSummaryScreenCallback);
}

static void CB2_PssChangePokemonNickname(void)
{
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_NICKNAME, gStringVar3);
    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_NICKNAME, gStringVar2);
    DoNamingScreen(NAMING_SCREEN_NICKNAME, gStringVar2, GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES, NULL), 
                   GetMonGender(&gPlayerParty[gSpecialVar_0x8004]), GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_PERSONALITY, NULL), 
                   CB2_ReturnToSummaryScreenFromNamingScreen);
}

/*
Montblanc note: 
- The functions below are used to remove hyphens from specific words when they are split across lines.
- For example, Incineum Z has "Incine-\n" and "roar", which the previous formatter would have rendered: "Incine-roar"
- Is this 100% overkill for just a few words? Yes.
- Is it worth it to read item descriptions and not see random jank? My sanity says yes.
*/
// Lookup table for hyphen removal - stores both parts of hyphenated words
static const struct HyphenPattern {
    const char *before;
    const char *after;
} sHyphenRemovalPatterns[] = {
    {"Incine", "roar"},
    {"La", "riat"},
    {"Marsha", "dow"},
    {"Thi", "ef"},
    {"Elec", "tric"},
    {"Fight", "ing"},
    {"pro", "motes"},
    {"Decidu", "eye"},
    {"Sha", "ckle"},
    {"invigor", "ating"},
    {"Thunder", "bolt"},
    {"inde", "scribable"},
};

// Convert ASCII char to GBA charset equivalent
static u8 AsciiToGbaChar(char c)
{
    if (c >= 'A' && c <= 'Z')
        return CHAR_A + (c - 'A');
    if (c >= 'a' && c <= 'z')
        return CHAR_a + (c - 'a');
    if (c >= '0' && c <= '9')
        return CHAR_0 + (c - '0');
    return c;
}

// Check if hyphen at position should be removed for specific words
static bool32 ShouldRemoveHyphen(const u8 *p, const u8 *start, const u8 *end)
{
    // Check all patterns in the table
    for (u32 i = 0; i < ARRAY_COUNT(sHyphenRemovalPatterns); i++)
    {
        const char *before = sHyphenRemovalPatterns[i].before;
        const char *after = sHyphenRemovalPatterns[i].after;
        
        // Calculate lengths
        u32 beforeLen = 0, afterLen = 0;
        while (before[beforeLen]) beforeLen++;
        while (after[afterLen]) afterLen++;
        
        // Check bounds
        if (p < start + beforeLen)
            continue;
        
        // Check "before" pattern
        bool32 matches = TRUE;
        for (u32 j = 0; j < beforeLen; j++)
        {
            if (p[-(s32)beforeLen + j] != AsciiToGbaChar(before[j]))
            {
                matches = FALSE;
                break;
            }
        }
        
        if (!matches)
            continue;
        
        // Check "after" pattern
        for (u32 j = 0; j < afterLen; j++)
        {
            if (p[1 + j] != AsciiToGbaChar(after[j]))
            {
                matches = FALSE;
                break;
            }
        }
        
        if (matches)
            return TRUE;
    }
    
    // Special case: Poké-mon (with é)
    if (p >= start + 4 && 
        p[-4] == CHAR_P && p[-3] == CHAR_o && p[-2] == CHAR_k && p[-1] == CHAR_e_ACUTE && 
        p[1] == CHAR_m && p[2] == CHAR_o && p[3] == CHAR_n)
        return TRUE;
    
    return FALSE;
}

#endif