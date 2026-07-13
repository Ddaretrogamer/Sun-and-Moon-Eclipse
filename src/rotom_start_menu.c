#include "rotom_start_menu.h"
#include "global.h"
#include "option_menu.h"
#include "bg.h"
#include "battle_pyramid.h"
#include "daycare.h"
#include "decompress.h"
#include "dexnav.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "fake_rtc.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "field_weather.h"
#include "frontier_pass.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "m4a.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "pokenav.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "safari_zone.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "trainer_card.h"
#include "trig.h"
#include "union_room.h"
#include "wallclock.h"
#include "constants/characters.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/weather.h"
#include "quests.h"

#ifdef RHH_EXPANSION
#include "constants/expansion.h"
#endif

#if !__has_include("comfy_anim.h")
    #error "ShantyTown's Comfy Anim Library is not found. Please download it from: https://github.com/huderlem/pokeemerald/tree/comfy_anims"
#else
    #include "comfy_anim.h"
#endif


#define NUM_FRAMES_FOR_MINUTES_UPDATE       (60 * 60) / FakeRtc_GetSecondsRatio() * RP_CONFIG_NUM_MINUTES_TO_UPDATE
#define ROTOM_PHONE_OW_MESSGAGE_TIMER       NUM_FRAMES_FOR_MINUTES_UPDATE / 2
#define ROTOM_PHONE_RR_MESSGAGE_TIMER       NUM_FRAMES_FOR_MINUTES_UPDATE

#define PHONE_OFFSCREEN_Y                   (RP_CONFIG_USE_ROTOM_PHONE ? 98 : 96)
#define PHONE_BASE_COLOUR_INDEX             5
#define PHONE_BG_PAL_SLOT                   14
#define TAG_ROTOM_FACE_GFX                  1234
#define TAG_PHONE_OW_ICON_GFX               1235
#define TAG_PHONE_RR_ICON_GFX               1236
#define TAG_PHONE_RR_ICON_GFX_2             1237
#define TAG_PHONE_RR_SHORTCUT_ICON          1238
#define TAG_PHONE_RR_DAYCARE_ICON           1239
#define TAG_ROTOM_FACE_ICON_PAL             0x4654 | BLEND_IMMUNE_FLAG
#define ROTOM_REALITY_COLUMN_ONE_X          34
#define ROTOM_REALITY_COLUMN_TWO_X          72
#define ROTOM_REALITY_COLUMN_THREE_X        168
#define ROTOM_REALITY_COLUMN_FOUR_X         206
#define ROTOM_REALITY_ROW_ONE_Y             40
#define ROTOM_REALITY_ROW_TWO_Y             80
#define ROTOM_REALITY_ROW_THREE_Y           120

#define PHONE_COMFY_SLIDE_DURATION          20
#define FACE_ICON_COMFY_SPRING_MASS         200
#define FACE_ICON_COMFY_SPRING_TENSION      25
#define FACE_ICON_COMFY_SPRING_FRICTION     800
#define FACE_ICON_COMFY_SPRING_CLAMP_AFTER  1
#define CURSOR_COMFY_SPRING_MASS            15
#define CURSOR_COMFY_SPRING_TENSION         100
#define CURSOR_COMFY_SPRING_FRICTION        850
#define CURSOR_COMFY_SPRING_CLAMP_AFTER     1

#define FADE_COLOUR_MAX                     0xFF
#define FADE_COLOUR_MID                     0x80
#define FADE_COLOUR_MIN                     0x00

#define ROTOM_REALITY_PANEL_BG_TILE         0x16


static void RotomPhone_OverworldMenu_Init(bool32 firstInit);
static void RotomPhone_OverworldMenu_ContinueInit(bool32 firstInit);
static void Task_RotomPhone_OverworldMenu_PhoneSlideOpen(u8 taskId);
static void Task_RotomPhone_OverworldMenu_PhoneSlideClose(u8 taskId);
static void Task_RotomPhone_OverworldMenu_HandleMainInput(u8 taskId);
static void RotomPhone_OverworldMenu_UpdateIconPaletteFade(u8 taskId);
static void Task_RotomPhone_OverworldMenu_RotomShutdown(u8 taskId);
static void Task_RotomPhone_OverworldMenu_CloseAndSave(u8 taskId);
static void Task_RotomPhone_OverworldMenu_CloseForSafari(u8 taskId);

static void RotomPhone_OverworldMenu_LoadSprites(void);
static void RotomPhone_OverworldMenu_CreateAllIconSprites(void);
static void RotomPhone_OverworldMenu_LoadBgGfx(bool32 firstInit);
static void RotomPhone_OverworldMenu_CreateSpeechWindows(void);
static void RotomPhone_OverworldMenu_CreateFlipPhoneWindow(void);
static void RotomPhone_OverworldMenu_PrintGreeting(void);
static void RotomPhone_OverworldMenu_CheckUpdateMessage(u8 taskId);
static void RotomPhone_OverworldMenu_PrintGoodbye(u8 taskId);
static void RotomPhone_OverworldMenu_PrintTime(u8 taskId);
static void RotomPhone_OverworldMenu_PrintSafari(u8 taskId);
static void RotomPhone_OverworldMenu_PrintDateWeather(u8 taskId);
static void RotomPhone_OverworldMenu_PrintHaveFun(u8 taskId);
static void RotomPhone_OverworldMenu_Personality(u8 taskId);
static void RotomPhone_OverworldMenu_PrintAdventure(u8 taskId);
static void RotomPhone_OverworldMenu_PrintHintPrompt(u8 taskId);
static void RotomPhone_OverworldMenu_PrintHint(u8 taskId);
static void RotomPhone_OverworldMenu_UpdateMenuPrompt(u8 taskId);


static void Task_RotomPhone_RotomRealityMenu_Open(u8 taskId);
static void RotomPhone_RotomRealityMenu_Init(void);
static void RotomPhone_RotomRealityMenu_SetupCB(void);

static void Task_RotomPhone_RotomRealityMenu_WaitFadeIn(u8 taskId);
static void Task_RotomPhone_RotomRealityMenu_HandleMainInput(u8 taskId);
static void Task_RotomPhone_RotomRealityMenu_PanelInput(u8 taskId);
static void Task_RotomPhone_RotomRealityMenu_PanelSlide(u8 taskId);
static void RotomPhone_RotomRealityMenu_StartPanelSlide(void);
static void Task_RotomPhone_RotomRealityMenu_WaitFadeAndBail(u8 taskId);
static void Task_RotomPhone_RotomRealityMenu_WaitFadeAndExitGracefully(u8 taskId);
static void Task_RotomPhone_RotomRealityMenu_WaitFadeAndExitGracefullyForSave(u8 taskId);
static void Task_RotomPhone_RotomRealityMenu_WaitFadeForSelection(u8 taskId);

static bool32 RotomPhone_RotomRealityMenu_InitBgs(void);
static void RotomPhone_RotomRealityMenu_FadeAndBail(void);
static bool32 RotomPhone_RotomRealityMenu_LoadGraphics(void);
static void RotomPhone_RotomRealityMenu_InitWindows(void);
static void RotomPhone_RotomRealityPanel_DestroyAssets(void);
static void RotomPhone_RotomRealityMenu_PrintTime(void);
static void RotomPhone_RotomRealityMenu_PrintMenuName(void);

static void RotomPhone_RotomRealityMenu_LoadSprites(void);
static void RotomPhone_RotomRealityMenu_CreateIconSprites(void);
static void RotomPhone_RotomRealityMenu_CreateShortcutIcon(void);
static void RotomPhone_RotomRealityMenu_CreateCursorSprite(void);
static void RotomPhone_RotomRealityMenu_TimerUpdates(u8 taskId);


static void RotomPhone_SaveScreen_SetupCB(void);
static void Task_RotomPhone_SaveScreen_WaitFadeIn(u8 taskId);
static void Task_RotomPhone_SaveScreen_WaitSaveGame(u8 taskId);
static void Task_RotomPhone_SaveScreen_WaitFadeAndExit(u8 taskId);

static bool32 RotomPhone_SaveScreen_InitBgs(void);
static void RotomPhone_SaveScreen_FadeAndBail(void);
static void RotomPhone_SaveScreen_InitWindows(void);


static void RotomPhone_RotomRealityMenu_SaveScreen_MainCB(void);
static void RotomPhone_RotomRealityMenu_SaveScreen_VBlankCB(void);
static void RotomPhone_RotomRealityMenu_SaveScreen_ResetGpuRegsAndBgs(void);
static void RotomPhone_RotomRealityMenu_SaveScreen_FreeResources(void);


static bool32 RotomPhone_StartMenu_IsRotomReality(void);
static void RotomPhone_StartMenu_LoadRotomFaceSpritesheet(void);
static void RotomPhone_StartMenu_CreateRotomFaceSprite(bool32 rotomFade);
static void RotomPhone_StartMenu_UpdateRotomFaceAnim(bool32 input);
static void RotomPhone_StartMenu_RotomShutdownPreparation(u8 taskId, bool32 overworld);

static void RotomPhone_StartMenu_DoCleanUpAndChangeCallback(MainCallback callback);
static u8 RotomPhone_StartMenu_DoCleanUpAndCreateTask(TaskFunc func, u8 priority);
static void RotomPhone_StartMenu_DoCleanUpAndChangeTaskFunc(u8 taskId, TaskFunc func);
static void RotomPhone_StartMenu_DoCleanUpAndDestroyTask(u8 taskId, bool32 overworldCleanup);

static bool32 RotomPhone_StartMenu_UnlockedFunc_Unlocked(void);
static bool32 UNUSED RotomPhone_StartMenu_UnlockedFunc_Unlocked_Overworld(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_Unlocked_RotomReality(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_Pokedex(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_Pokemon(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_PokeNav(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_RotomLog(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_Save(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_SafariFlag(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_RotomReality(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_DexNav(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_Clock(void);
static bool32 RotomPhone_StartMenu_UnlockedFunc_Shortcut(void);
static bool32 RotomPhone_StartMenu_IsValidScriptTarget(u16 menuItem);

static void RotomPhone_StartMenu_SelectedFunc_Shortcut(void);
static void RotomPhone_StartMenu_SelectedFunc_Pokedex(void);
static void RotomPhone_StartMenu_SelectedFunc_Pokemon(void);
static void RotomPhone_StartMenu_SelectedFunc_Bag(void);
static void RotomPhone_StartMenu_SelectedFunc_PokeNav(void);
static void RotomPhone_StartMenu_SelectedFunc_RotomLog(void);
static void RotomPhone_StartMenu_SelectedFunc_Trainer(void);
static void RotomPhone_StartMenu_SelectedFunc_Save(void);
static void RotomPhone_StartMenu_SelectedFunc_Settings(void);
static void RotomPhone_StartMenu_SelectedFunc_SafariFlag(void);
static void RotomPhone_StartMenu_SelectedFunc_RotomReality(void);
static void RotomPhone_StartMenu_SelectedFunc_DexNav(void);
static void RotomPhone_StartMenu_SelectedFunc_Clock(void);
static void RotomPhone_StartMenu_SelectedFunc_Daycare(void);
static void RotomPhone_StartMenu_CB2_OpenRegionMapFromRotomReality(void);
static void RotomPhone_StartMenu_ClearScriptState(void);

static EWRAM_DATA bool32 sRotomPhone_RotomReality;
static EWRAM_DATA bool32 sRotomPhone_StartMenuFromScript;
static EWRAM_DATA u16 sRotomPhone_StartMenuScriptTarget;
static EWRAM_DATA const u8 *sRotomPhone_StartMenuScriptPrompt;


// Init Rotom Start Menu
void RotomPhone_StartMenu_Open(bool32 firstInit)
{
    if (!RotomPhone_StartMenu_IsRotomReality() || gMain.callback2 == CB2_Overworld)
    {
        if (!RP_CONFIG_USE_ROTOM_PHONE && firstInit)
            PlaySE(SE_BALL_TRAY_ENTER);

        RotomPhone_OverworldMenu_Init(firstInit);
    }   
    else
    {
        RotomPhone_RotomRealityMenu_Init();
    }
}

void RotomPhone_StartMenu_OpenForScript(u16 menuItem, const u8 *customPromptText)
{
    sRotomPhone_StartMenuFromScript = TRUE;
    sRotomPhone_StartMenuScriptTarget = menuItem;
    sRotomPhone_StartMenuScriptPrompt = customPromptText;
    sRotomPhone_RotomReality = FALSE;
    RotomPhone_StartMenu_Open(TRUE);
}

bool32 RotomPhone_StartMenu_IsScriptDisplayActive(void)
{
    return sRotomPhone_StartMenuFromScript;
}


static const u32 sRotomPhone_OverworldTiles[] =                 INCGFX_U32("graphics/rotom_start_menu/overworld/rotom_phone_tiles.png", ".4bpp.lz");
static const u32 sRotomPhone_OverworldTilemap[] =               INCGFX_U32("graphics/rotom_start_menu/overworld/rotom_phone.bin", ".lz");
static const u32 sRotomPhone_OverworldSpeechTilemap[] =         INCGFX_U32("graphics/rotom_start_menu/overworld/rotom_phone_speech.bin", ".lz");
static const u32 sFlipPhone_OverworldTiles[] =                  INCGFX_U32("graphics/rotom_start_menu/overworld/flip_phone_tiles.png", ".4bpp.lz");
static const u32 sFlipPhone_OverworldOpenTilemap[] =            INCGFX_U32("graphics/rotom_start_menu/overworld/flip_phone_open.bin", ".lz");
static const u32 sFlipPhone_OverworldClosedTilemap[] =          INCGFX_U32("graphics/rotom_start_menu/overworld/flip_phone_closed.bin", ".lz");
static const u32 sRotomFlipPhone_OverworldIconsGfx[] =          INCGFX_U32("graphics/rotom_start_menu/overworld/icons.png", ".4bpp.lz");

static const u32 sRotomPhone_RotomRealityMenuTiles[] =          INCGFX_U32("graphics/rotom_start_menu/rotom_reality/rotom_phone_tiles.png", ".4bpp.lz");
static const u32 sRotomPhone_RotomRealityMenuTilemap[] =        INCGFX_U32("graphics/rotom_start_menu/rotom_reality/rotom_phone.bin", ".lz");
static const u32 sRotomPhone_RotomRealityMenuPanelTilemap[] =   INCGFX_U32("graphics/rotom_start_menu/rotom_reality/rotom_phone_panel.bin", ".lz");
static const u32 sRotomPhone_RotomRealityMenuIconsGfx_One[] =   INCGFX_U32("graphics/rotom_start_menu/rotom_reality/icons_1.png", ".4bpp.lz");
static const u32 sRotomPhone_RotomRealityMenuIconsGfx_Two[] =   INCGFX_U32("graphics/rotom_start_menu/rotom_reality/icons_2.png", ".4bpp.lz");
static const u16 sRotomPhone_RotomRealityMenuIconsPal_Two[] =   INCGFX_U16("graphics/rotom_start_menu/rotom_reality/icons_2.png", ".gbapal");
static const u32 sRotomPhone_RotomRealityMenuShortcutGfx[] =    INCGFX_U32("graphics/rotom_start_menu/rotom_reality/shortcut.png", ".4bpp.lz");
static const u16 sRotomPhone_RotomRealityMenuShortcutPal[] =    INCGFX_U16("graphics/rotom_start_menu/rotom_reality/shortcut.png", ".gbapal");
static const u32 sRotomPhone_DaycareCompatability_Gfx[] =       INCGFX_U32("graphics/rotom_start_menu/rotom_reality/panel/daycare/heart.png", ".4bpp.lz");
static const u16 sRotomPhone_DaycareCompatability_Pal[] =       INCGFX_U16("graphics/rotom_start_menu/rotom_reality/panel/daycare/heart.png", ".gbapal");

static const u16 sRotomPhone_StartMenuRotomFaceIconsPal[] =     INCGFX_U16("graphics/rotom_start_menu/rotom_face.png", ".gbapal");
static const u32 sRotomPhone_StartMenuRotomFaceGfx[] =          INCGFX_U32("graphics/rotom_start_menu/rotom_face.png", ".4bpp.lz");

static const u32 sRotomPhone_SaveScreenTiles[] =                INCGFX_U32("graphics/rotom_start_menu/save_screen/surfingpikachu_tiles.png", ".4bpp.lz");
static const u32 sRotomPhone_SaveScreenTilemap[] =              INCGFX_U32("graphics/rotom_start_menu/save_screen/surfingpikachu_tiles.bin", ".lz");
static const u16 sRotomPhone_SaveScreenPalette[] =              INCGFX_U16("graphics/rotom_start_menu/save_screen/surfingpikachu_tiles.png", ".gbapal");

static const u16 sRotomPhonePalette_Black[] =                   INCGFX_U16("graphics/rotom_start_menu/palettes/black.png", ".gbapal");
static const u16 sRotomPhonePalette_Red[] =                     INCGFX_U16("graphics/rotom_start_menu/palettes/red.png", ".gbapal");
static const u16 sRotomPhonePalette_Yellow[] =                  INCGFX_U16("graphics/rotom_start_menu/palettes/yellow.png", ".gbapal");
static const u16 sRotomPhonePalette_Green[] =                   INCGFX_U16("graphics/rotom_start_menu/palettes/green.png", ".gbapal");
static const u16 sRotomPhonePalette_Purple[] =                  INCGFX_U16("graphics/rotom_start_menu/palettes/purple.png", ".gbapal");
static const u16 sRotomPhonePalette_Blue[] =                    INCGFX_U16("graphics/rotom_start_menu/palettes/blue.png", ".gbapal");
static const u16 sRotomPhonePalette_Turquoise[] =               INCGFX_U16("graphics/rotom_start_menu/palettes/turquoise.png", ".gbapal");
static const u16 sRotomPhonePalette_Rose[] =                    INCGFX_U16("graphics/rotom_start_menu/palettes/rose.png", ".gbapal");
static const u16 sRotomPhonePalette_Brown[] =                   INCGFX_U16("graphics/rotom_start_menu/palettes/brown.png", ".gbapal");
static const u16 sRotomPhonePalette_DarkGreen[] =               INCGFX_U16("graphics/rotom_start_menu/palettes/dark_green.png", ".gbapal");
static const u16 sRotomPhonePalette_WineRed[] =                 INCGFX_U16("graphics/rotom_start_menu/palettes/wine_red.png", ".gbapal");
static const u16 sRotomPhonePalette_Navy[] =                    INCGFX_U16("graphics/rotom_start_menu/palettes/navy.png", ".gbapal");
static const u16 sRotomPhonePalette_White[] =                   INCGFX_U16("graphics/rotom_start_menu/palettes/white.png", ".gbapal");
static const u16 sRotomPhonePalette_Lavender[] =                INCGFX_U16("graphics/rotom_start_menu/palettes/lavender.png", ".gbapal");
static const u16 sRotomPhonePalette_Gold[] =                    INCGFX_U16("graphics/rotom_start_menu/palettes/gold.png", ".gbapal");
static const u16 sRotomPhonePalette_OG[] =                      INCGFX_U16("graphics/rotom_start_menu/palettes/og.png", ".gbapal");

static const u16 *const sRotomPhone_StartMenu_Palettes[ROTOM_PHONE_COLOUR_COUNT] =
{
    [ROTOM_PHONE_OG] =            sRotomPhonePalette_OG,
    [ROTOM_PHONE_BLACK] =       sRotomPhonePalette_Black,
    [ROTOM_PHONE_RED] =         sRotomPhonePalette_Red,
    [ROTOM_PHONE_YELLOW] =      sRotomPhonePalette_Yellow,
    [ROTOM_PHONE_GREEN] =       sRotomPhonePalette_Green,
    [ROTOM_PHONE_PURPLE] =      sRotomPhonePalette_Purple,
    [ROTOM_PHONE_BLUE] =        sRotomPhonePalette_Blue,
    [ROTOM_PHONE_TURQUOISE] =   sRotomPhonePalette_Turquoise,
    [ROTOM_PHONE_ROSE] =        sRotomPhonePalette_Rose,
    [ROTOM_PHONE_BROWN] =       sRotomPhonePalette_Brown,
    [ROTOM_PHONE_DARK_GREEN] =  sRotomPhonePalette_DarkGreen,
    [ROTOM_PHONE_WINE_RED] =    sRotomPhonePalette_WineRed,
    [ROTOM_PHONE_NAVY] =        sRotomPhonePalette_Navy,
    [ROTOM_PHONE_WHITE] =       sRotomPhonePalette_White,
    [ROTOM_PHONE_LAVENDER] =      sRotomPhonePalette_Lavender,
    [ROTOM_PHONE_GOLD] =          sRotomPhonePalette_Gold,
};

const u16 *RotomPhone_StartMenu_GetPhoneColour(void)
{
    u8 paletteId = gSaveBlock2Ptr->optionsRotomPhonePalette;
    if (paletteId >= ROTOM_PHONE_COLOUR_COUNT)
        paletteId = ROTOM_PHONE_OG; 
    return sRotomPhone_StartMenu_Palettes[paletteId];
}



#if RP_CONFIG_PALETTE_BUFFER
static EWRAM_DATA u16 ALIGNED(4) menuLoadedSpritePalette_One[PLTT_SIZE_4BPP];
static EWRAM_DATA u16 ALIGNED(4) menuLoadedSpritePalette_Two[PLTT_SIZE_4BPP];
static EWRAM_DATA u16 ALIGNED(4) menuLoadedBackgroundPalette[PLTT_SIZE_4BPP];
#endif

enum RotomPhone_Overworld_FaceIconPaletteIndex
{
    PAL_FACE_ICON_TRANSPARENT,
    PAL_ICON_RED,
    PAL_ICON_GREEN,
    PAL_ICON_BLUE,
    PAL_ICON_YELLOW,
    PAL_ICON_PURPLE,
    PAL_ICON_PINK,
    PAL_ICON_ORANGE,
    PAL_ICON_BROWN,
    PAL_ICON_MONOCHROME,    // Similar to Phone Background Colour
    PAL_ICON_WHITE,
    PAL_ROTOM_OUTLINE,
    PAL_ROTOM_EYE_WHITE,
    PAL_ROTOM_EYE_TOP,
    PAL_ROTOM_EYE_BOTTOM,
    PAL_ROTOM_ARC,
};

static u16 RotomPhone_StartMenu_GetPhoneBackgroundColour(u8 palSlot)
{
#if RP_CONFIG_PALETTE_BUFFER
    return menuLoadedBackgroundPalette[PHONE_BASE_COLOUR_INDEX];
#else
    return RotomPhone_StartMenu_GetPhoneColour()[PHONE_BASE_COLOUR_INDEX];
#endif
}

static u16 RotomPhone_StartMenu_GetFaceIconPaletteOriginalColour(u8 palSlot)
{
#if RP_CONFIG_PALETTE_BUFFER
    return menuLoadedSpritePalette_One[palSlot];
#else
    if (RP_CONFIG_USE_ROTOM_PHONE && !(RP_CONFIG_MONOCHROME_ICONS && palSlot < PAL_ICON_WHITE))
        return sRotomPhone_StartMenuRotomFaceIconsPal[palSlot];
    else
        return sRotomPhone_StartMenuRotomFaceIconsPal[PAL_ICON_MONOCHROME];
#endif
}

static u16 RotomPhone_StartMenu_GetFaceIconPaletteHighlightColour(u8 palSlot)
{
    #define MAX_RGB_COMPONENT 28
    #define LIGHTEN_FACTOR    8
    u16 colour = RotomPhone_StartMenu_GetFaceIconPaletteOriginalColour(palSlot);

    s32 r = GET_R(colour);
    s32 g = GET_G(colour);
    s32 b = GET_B(colour);

    r = (r + LIGHTEN_FACTOR > MAX_RGB_COMPONENT) ? MAX_RGB_COMPONENT : r + LIGHTEN_FACTOR;
    g = (g + LIGHTEN_FACTOR > MAX_RGB_COMPONENT) ? MAX_RGB_COMPONENT : g + LIGHTEN_FACTOR;
    b = (b + LIGHTEN_FACTOR > MAX_RGB_COMPONENT) ? MAX_RGB_COMPONENT : b + LIGHTEN_FACTOR;

    return RGB(r, g, b);
    #undef MAX_RGB_COMPONENT
    #undef LIGHTEN_FACTOR
}

static void RotomPhone_StartMenu_UpdateSpriteFadeColours(struct Sprite* sprite, enum RotomPhone_Overworld_FaceIconPaletteIndex index, u8 frameNum)
{
    if (index == PAL_FACE_ICON_TRANSPARENT)
        return;
    
    s32 intensity = (((Cos(frameNum, 128) + 128) * 10) / 250);
    s32 r;
    s32 g;
    s32 b;
    u16 colour;
    u16 colourTo;
    u16 colourFrom;

    switch (index)
    {
    case PAL_ROTOM_OUTLINE:
    case PAL_ROTOM_EYE_WHITE:
    case PAL_ROTOM_EYE_TOP:
    case PAL_ROTOM_EYE_BOTTOM:
    case PAL_ROTOM_ARC:
        colourFrom = RotomPhone_StartMenu_GetPhoneBackgroundColour(index);
        colourTo = RotomPhone_StartMenu_GetFaceIconPaletteOriginalColour(index);
        break;
    
    default:
        colourFrom = RotomPhone_StartMenu_GetFaceIconPaletteOriginalColour(index);
        colourTo = RotomPhone_StartMenu_GetFaceIconPaletteHighlightColour(index);
        break;
    }

    if (intensity == 0)
    {
        colour = colourTo;
    }
    else
    {
        if (GET_R(colourFrom) <= GET_R(colourTo))
            r = (GET_R(colourTo) - (((GET_R(colourTo) - GET_R(colourFrom)) * intensity) / 10));
        else
            r = (GET_R(colourTo) + (((GET_R(colourFrom) - GET_R(colourTo)) * intensity) / 10));

        if (GET_G(colourFrom) <= GET_G(colourTo))
            g = (GET_G(colourTo) - (((GET_G(colourTo) - GET_G(colourFrom)) * intensity) / 10));
        else
            g = (GET_G(colourTo) + (((GET_G(colourFrom) - GET_G(colourTo)) * intensity) / 10));

        if (GET_B(colourFrom) <= GET_B(colourTo))
            b = (GET_B(colourTo) - (((GET_B(colourTo) - GET_B(colourFrom)) * intensity) / 10));
        else
            b = (GET_B(colourTo) + (((GET_B(colourFrom) - GET_B(colourTo)) * intensity) / 10));

        colour = RGB(r, g, b);
    }
    
    LoadPalette(&colour, OBJ_PLTT_ID(IndexOfSpritePaletteTag(sprite->template->paletteTag)) + index, sizeof(colour));
}

#define sFrameNumComfyAnimId sprite->data[0]
static void SpriteCB_RotomPhone_OverworldMenu_RotomFace_Load(struct Sprite* sprite)
{
    TryAdvanceComfyAnim(&gComfyAnims[sFrameNumComfyAnimId]);
    if (gComfyAnims[sFrameNumComfyAnimId].completed)
    {
        ReleaseComfyAnim(sFrameNumComfyAnimId);
        sprite->callback = SpriteCallbackDummy;
        if (!RotomPhone_StartMenu_IsRotomReality())
            RotomPhone_OverworldMenu_ContinueInit(TRUE);
        return;
    }

    u32 frameNum = ReadComfyAnimValueSmooth(&gComfyAnims[sFrameNumComfyAnimId]);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_OUTLINE, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_EYE_WHITE, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_EYE_TOP, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_ARC, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_EYE_BOTTOM, frameNum);
}

static void SpriteCB_RotomPhone_OverworldMenu_RotomFace_Unload(struct Sprite* sprite)
{
    TryAdvanceComfyAnim(&gComfyAnims[sFrameNumComfyAnimId]);
    if (gComfyAnims[sFrameNumComfyAnimId].completed)
    {
        ReleaseComfyAnim(sFrameNumComfyAnimId);
        sprite->callback = SpriteCallbackDummy;
        return;
    }

    u32 frameNum = ReadComfyAnimValueSmooth(&gComfyAnims[sFrameNumComfyAnimId]);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_OUTLINE, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_EYE_WHITE, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_EYE_TOP, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_ARC, frameNum);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(sprite, PAL_ROTOM_EYE_BOTTOM, frameNum);
}


#define OW_FLIP_PHONE_TEXT_BG_COLOUR       12
#define OW_FLIP_PHONE_TEXT_FG_COLOUR       1
#define OW_FLIP_PHONE_TEXT_SHADOW_COLOUR   10
#define OW_ROTOM_PHONE_TEXT_BG_COLOUR      14
#define OW_ROTOM_PHONE_TEXT_FG_COLOUR      1
#define OW_ROTOM_PHONE_TEXT_SHADOW_COLOUR  10
#define RR_ROTOM_PHONE_TEXT_BG_COLOUR      14
#define RR_ROTOM_PHONE_TEXT_FG_COLOUR      1
#define RR_ROTOM_PHONE_TEXT_SHADOW_COLOUR  10
enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
    FONT_OW_FLIP_PHONE,
    FONT_OW_ROTOM_PHONE,
    FONT_RR_ROTOM_PHONE,
};
static const u8 sRotomPhone_StartMenu_FontColours[][3] =
{
    [FONT_BLACK]            = {TEXT_COLOR_TRANSPARENT,          TEXT_COLOR_DARK_GRAY,           TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]            = {TEXT_COLOR_TRANSPARENT,          TEXT_COLOR_WHITE,               TEXT_COLOR_DARK_GRAY},
    [FONT_RED]              = {TEXT_COLOR_TRANSPARENT,          TEXT_COLOR_RED,                 TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]             = {TEXT_COLOR_TRANSPARENT,          TEXT_COLOR_BLUE,                TEXT_COLOR_LIGHT_GRAY},
    [FONT_OW_FLIP_PHONE]    = {OW_FLIP_PHONE_TEXT_BG_COLOUR,    OW_FLIP_PHONE_TEXT_FG_COLOUR,   OW_FLIP_PHONE_TEXT_SHADOW_COLOUR},
    [FONT_OW_ROTOM_PHONE]   = {TEXT_COLOR_TRANSPARENT,          OW_ROTOM_PHONE_TEXT_FG_COLOUR,  OW_ROTOM_PHONE_TEXT_SHADOW_COLOUR},
    [FONT_RR_ROTOM_PHONE]   = {TEXT_COLOR_TRANSPARENT,          RR_ROTOM_PHONE_TEXT_FG_COLOUR,  RR_ROTOM_PHONE_TEXT_SHADOW_COLOUR},
};


enum RotomPhone_MenuItems
{
    RP_MENU_ROTOM_REALITY,
    RP_MENU_FLAG,
    RP_MENU_SHORTCUT,
    RP_MENU_CLOCK,
    RP_MENU_POKEDEX,
    RP_MENU_PARTY,
    RP_MENU_DAYCARE,
    RP_MENU_BAG,
    RP_MENU_DEXNAV,
    RP_MENU_POKENAV,
    RP_MENU_QUEST_LOG,
    RP_MENU_TRAINER_CARD,
    RP_MENU_SAVE,
    RP_MENU_OPTIONS,
    RP_MENU_COUNT,
};
#define RP_MENU_FIRST_OPTION RP_MENU_COUNT - RP_MENU_COUNT
#define RP_MENU_LAST_OPTION  RP_MENU_COUNT - 1
static enum RotomPhone_MenuItems RotomPhone_StartMenu_GetShortcutOption_Overworld(void)
{
    return RP_MENU_POKEDEX;
}
static enum RotomPhone_MenuItems RotomPhone_StartMenu_GetShortcutOption_RotomReality(void)
{
    return RP_MENU_CLOCK;
}
#define RP_GET_SHORTCUT_OPTION_OW RotomPhone_StartMenu_GetShortcutOption_Overworld()
#define RP_GET_SHORTCUT_OPTION_RR RotomPhone_StartMenu_GetShortcutOption_RotomReality()

enum RotomPhone_Overworld_Options
{
    RP_OW_OPTION_1,
    RP_OW_OPTION_2,
    RP_OW_OPTION_3,
    RP_OW_OPTION_4,
    RP_OW_OPTION_5,
    RP_OW_OPTION_6,
    RP_OW_OPTION_COUNT,
};

enum RotomPhone_FaceExpressions
{
    RP_FACE_HAPPY,
    RP_FACE_HAPPY_UP,
    RP_FACE_HAPPY_WITH,
    RP_FACE_SHOCKED,
    RP_FACE_SHOCKED_UP,
    RP_FACE_SHOCKED_WITH,
    RP_FACE_DAZED,
    RP_FACE_AWE,
    RP_FACE_SHEEPISH,
    RP_FACE_CONFUSED,
    RP_FACE_COUNT,
};
#define RP_FACE_LOOK_UP_ANIMS 2

enum RotomPhone_Overworld_Messages
{
    RP_MESSAGE_GOODBYE,
    RP_MESSAGE_TIME,
    RP_MESSAGE_SAFARI,
    RP_MESSAGE_DATE_WEATHER,
    RP_MESSAGE_PERSONALITY,
    RP_MESSAGE_FUN,
    RP_MESSAGE_ADVENTURE,
    RP_MESSAGE_HINT_PROMPT,
    RP_MESSAGE_COUNT,
};

enum RotomPhone_Overworld_MessagesGreeting
{
    RP_MESSAGE_GREETING_GOOD_DAY,
    RP_MESSAGE_GREETING_HELLO,
    RP_MESSAGE_GREETING_HI,
    RP_MESSAGE_GREETING_HOW_ARE_YOU,
    RP_MESSAGE_GREETING_COUNT,
};

enum RotomPhone_Overworld_MessagesGoodbye
{
    RP_MESSAGE_GOODBYE_GOODBYE,
    RP_MESSAGE_GOODBYE_SEE_YA,
    RP_MESSAGE_GOODBYE_LOGGING_OFF,
    RP_MESSAGE_GOODBYE_POWERING_DOWN,
    RP_MESSAGE_GOODBYE_COUNT,
};

enum RotomPhone_Overworld_MessagesDateWeather
{
    // RP_MESSAGE_DATE_WEATHER_DATE,
    // RP_MESSAGE_DATE_WEATHER_SEASON,
    RP_MESSAGE_DATE_WEATHER_CURRENT_WEATHER,
    // RP_MESSAGE_DATE_WEATHER_NEXT_WEATHER,
    RP_MESSAGE_DATE_WEATHER_COUNT,
};

enum RotomPhone_Overworld_MessagesPersonality
{
    RP_MESSAGE_PERSONALITY_MEEP_MORP,
    RP_MESSAGE_PERSONALITY_HANDS,
    RP_MESSAGE_PERSONALITY_RINGTONE,
    RP_MESSAGE_PERSONALITY_SCANNING,
    RP_MESSAGE_PERSONALITY_COUNT,
};

enum RotomPhone_Overworld_MessagesFun
{
    RP_MESSAGE_FUN_WINNING_GRINNING,
    RP_MESSAGE_FUN_ANYMORE_BATTLES,
    RP_MESSAGE_FUN_FUN_DETECTED,
    RP_MESSAGE_FUN_SOMETHING_SILLY,
    RP_MESSAGE_FUN_COUNT,
};

enum RotomPhone_Overworld_MessagesAdventure
{
    RP_MESSAGE_ADVENTURE_TO_DO,
    RP_MESSAGE_ADVENTURE_GET_LOST,
    RP_MESSAGE_ADVENTURE_STEP_STORY,
    RP_MESSAGE_ADVENTURE_PACK_CURIOSITY,
    RP_MESSAGE_ADVENTURE_COUNT,
};

enum RotomPhone_RotomReality_Options
{
    RP_RR_OPTION_1,
    RP_RR_OPTION_2,
    RP_RR_OPTION_3,
    RP_RR_OPTION_4,
    RP_RR_OPTION_5,
    RP_RR_OPTION_6,
    RP_RR_OPTION_7,
    RP_RR_OPTION_8,
    RP_RR_OPTION_9,
    RP_RR_OPTION_10,
    RP_RR_OPTION_COUNT,
};

struct RotomPhone_RotomReality_OptionsInfo
{
    u32 x;
    u32 y;
    enum RotomPhone_RotomReality_Options optionUp;
    enum RotomPhone_RotomReality_Options optionDown;
    enum RotomPhone_RotomReality_Options optionLeft;
    enum RotomPhone_RotomReality_Options optionRight;
};

static const struct RotomPhone_RotomReality_OptionsInfo sRotomRealityOptionInfo[RP_RR_OPTION_COUNT] =
{
    [RP_RR_OPTION_1] =
    {
        .x = ROTOM_REALITY_COLUMN_ONE_X,
        .y = ROTOM_REALITY_ROW_ONE_Y,
        .optionUp = RP_RR_OPTION_COUNT,
        .optionDown = RP_RR_OPTION_5,
        .optionLeft = RP_RR_OPTION_COUNT,
        .optionRight = RP_RR_OPTION_2,
    },
    [RP_RR_OPTION_2] =
    {
        .x = ROTOM_REALITY_COLUMN_TWO_X,
        .y = ROTOM_REALITY_ROW_ONE_Y,
        .optionUp = RP_RR_OPTION_COUNT,
        .optionDown = RP_RR_OPTION_6,
        .optionLeft = RP_RR_OPTION_1,
        .optionRight = RP_RR_OPTION_3,
    },
    [RP_RR_OPTION_3] =
    {
        .x = ROTOM_REALITY_COLUMN_THREE_X,
        .y = ROTOM_REALITY_ROW_ONE_Y,
        .optionUp = RP_RR_OPTION_COUNT,
        .optionDown = RP_RR_OPTION_7,
        .optionLeft = RP_RR_OPTION_2,
        .optionRight = RP_RR_OPTION_4,
    },
    [RP_RR_OPTION_4] =
    {
        .x = ROTOM_REALITY_COLUMN_FOUR_X,
        .y = ROTOM_REALITY_ROW_ONE_Y,
        .optionUp = RP_RR_OPTION_COUNT,
        .optionDown = RP_RR_OPTION_8,
        .optionLeft = RP_RR_OPTION_3,
        .optionRight = RP_RR_OPTION_COUNT,
    },
    [RP_RR_OPTION_5] =
    {
        .x = ROTOM_REALITY_COLUMN_ONE_X,
        .y = ROTOM_REALITY_ROW_TWO_Y,
        .optionUp = RP_RR_OPTION_1,
        .optionDown = RP_RR_OPTION_9,
        .optionLeft = RP_RR_OPTION_COUNT,
        .optionRight = RP_RR_OPTION_6,
    },
    [RP_RR_OPTION_6] =
    {
        .x = ROTOM_REALITY_COLUMN_TWO_X,
        .y = ROTOM_REALITY_ROW_TWO_Y,
        .optionUp = RP_RR_OPTION_2,
        .optionDown = RP_RR_OPTION_9,
        .optionLeft = RP_RR_OPTION_5,
        .optionRight = RP_RR_OPTION_7,
    },
    [RP_RR_OPTION_7] =
    {
        .x = ROTOM_REALITY_COLUMN_THREE_X,
        .y = ROTOM_REALITY_ROW_TWO_Y,
        .optionUp = RP_RR_OPTION_3,
        .optionDown = RP_RR_OPTION_10,
        .optionLeft = RP_RR_OPTION_6,
        .optionRight = RP_RR_OPTION_8,
    },
    [RP_RR_OPTION_8] =
    {
        .x = ROTOM_REALITY_COLUMN_FOUR_X,
        .y = ROTOM_REALITY_ROW_TWO_Y,
        .optionUp = RP_RR_OPTION_4,
        .optionDown = RP_RR_OPTION_10,
        .optionLeft = RP_RR_OPTION_7,
        .optionRight = RP_RR_OPTION_COUNT,
    },
    [RP_RR_OPTION_9] =
    {
        .x = ROTOM_REALITY_COLUMN_ONE_X + 16,
        .y = ROTOM_REALITY_ROW_THREE_Y,
        .optionUp = RP_RR_OPTION_5,
        .optionDown = RP_RR_OPTION_COUNT,
        .optionLeft = RP_RR_OPTION_COUNT,
        .optionRight = RP_RR_OPTION_10,
    },
    [RP_RR_OPTION_10] =
    {
        .x = ROTOM_REALITY_COLUMN_FOUR_X - 16,
        .y = ROTOM_REALITY_ROW_THREE_Y,
        .optionUp = RP_RR_OPTION_7,
        .optionDown = RP_RR_OPTION_COUNT,
        .optionLeft = RP_RR_OPTION_9,
        .optionRight = RP_RR_OPTION_COUNT,
    },
};

enum RotomPhone_RotomReality_SlidingPanelSprites
{
    RP_RR_PANEL_SPRITE_ONE,
    RP_RR_PANEL_SPRITE_TWO,
    RP_RR_PANEL_SPRITE_THREE,
    RP_RR_PANEL_SPRITE_FOUR,
    RP_RR_PANEL_SPRITE_FIVE,
    RP_RR_PANEL_SPRITE_SIX,
    RP_RR_PANEL_SPRITE_COUNT,
};

enum RotomPhone_RotomReality_SlidingPanelWindows
{
    RP_RR_PANEL_WIN_ONE,
    RP_RR_PANEL_WIN_TWO,
    RP_RR_PANEL_WIN_THREE,
    RP_RR_PANEL_WIN_FOUR,
    RP_RR_PANEL_WIN_FIVE,
    RP_RR_PANEL_WIN_SIX,
    RP_RR_PANEL_WIN_COUNT,
};

enum RotomPhone_RotomReality_DaycareCompatabilityAnims
{
    RP_DAYCARE_COMPATABILITY_ANIM_NON,
    RP_DAYCARE_COMPATABILITY_ANIM_LOW,
    RP_DAYCARE_COMPATABILITY_ANIM_MED,
    RP_DAYCARE_COMPATABILITY_ANIM_MAX,
    RP_DAYCARE_COMPATABILITY_ANIM_COUNT,
};


struct RotomPhone_StartMenu_State
{
    u32 menuRotomFaceSpriteId;
    u32 menuRotomFaceFlashSpriteId;
    enum RotomPhone_FaceExpressions rotomFaceLastLoaded;

    // Overworld Menu
    bool32 menuOverworldLoading;
    enum RotomPhone_MenuItems menuOverworldOptions[RP_OW_OPTION_COUNT];
    u32 menuOverworldIconSpriteId[RP_OW_OPTION_COUNT];
    u32 menuOverworldIconFlashSpriteId[RP_OW_OPTION_COUNT];
    u32 menuOverworldRotomSpeechTopWindowId;
    u32 menuOverworldRotomSpeechBottomWindowId;
    u32 menuOverworldFlipPhoneWindowId;

    // Rotom Reality Menu
    u32 menuRotomRealityLoadState;
    bool32 menuRotomRealityPanelOpen;
    enum RotomPhone_MenuItems menuRotomRealityOptions[RP_RR_OPTION_COUNT];
    enum RotomPhone_MenuItems menuRotomRealityFirstOnScreenOption;
    u32 menuRotomRealityIconSpriteId[RP_RR_OPTION_COUNT];
    u32 menuRotomRealityShortcutIconSpriteId;
    u32 menuRotomRealityCursorSpriteId;
    u32 menuRotomRealityPanelY;
    u32 menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_COUNT];
    u32 menuRotomRealityPanelWindowId[RP_RR_PANEL_WIN_COUNT];
};
static EWRAM_DATA struct RotomPhone_StartMenu_State *sRotomPhone_StartMenu = NULL;

// Separate memory allocation so it persist between destroying of menu.
static EWRAM_DATA enum RotomPhone_MenuItems menuSelectedOverworld;
static EWRAM_DATA enum RotomPhone_MenuItems menuSelectedRotomReality;
static EWRAM_DATA enum RotomPhone_FaceExpressions rotomFaceExpression;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;

static bool32 RotomPhone_StartMenu_IsRotomReality(void)
{
    return sRotomPhone_RotomReality;
}

static void RotomPhone_StartMenu_ClearScriptState(void)
{
    sRotomPhone_StartMenuFromScript = FALSE;
    sRotomPhone_StartMenuScriptTarget = RP_MENU_FIRST_OPTION;
    sRotomPhone_StartMenuScriptPrompt = NULL;
}

static bool32 RotomPhone_StartMenu_IsValidScriptTarget(u16 menuItem)
{
    switch (menuItem)
    {
    case ROTOM_SCRIPT_MENU_ROTOM_REALITY:
    case ROTOM_SCRIPT_MENU_FLAG:
    case ROTOM_SCRIPT_MENU_SHORTCUT:
    case ROTOM_SCRIPT_MENU_CLOCK:
    case ROTOM_SCRIPT_MENU_POKEDEX:
    case ROTOM_SCRIPT_MENU_PARTY:
    case ROTOM_SCRIPT_MENU_BAG:
    case ROTOM_SCRIPT_MENU_DEXNAV:
    case ROTOM_SCRIPT_MENU_SAVE:
    case ROTOM_SCRIPT_MENU_OPTIONS:
        return TRUE;
    }

    return FALSE;
}


enum RotomPhone_RotomReality_WindowIds
{
    RP_RR_WIN_TIME,
    RP_RR_WIN_MENU_NAME,
    RP_RR_WIN_COUNT,
};
#define RP_RR_WIN_LAST RP_RR_WIN_COUNT - 1

#define ROTOM_SPEECH_WINDOW_WIDTH   18
#define ROTOM_SPEECH_WINDOW_WIDTH_PXL ROTOM_SPEECH_WINDOW_WIDTH * 8
#define ROTOM_SPEECH_WINDOW_HEIGHT  2
#define ROTOM_SPEECH_WINDOW_LEFT    1
#define ROTOM_SPEECH_WINDOW_TOP     15
#define PHONE_STARTING_BASE_BLOCK   0xFF
static const struct WindowTemplate sWindowTemplate_RotomSpeech_Top = {
  .bg = 0, 
  .tilemapLeft = ROTOM_SPEECH_WINDOW_LEFT, 
  .tilemapTop = ROTOM_SPEECH_WINDOW_TOP, 
  .width = ROTOM_SPEECH_WINDOW_WIDTH,
  .height = ROTOM_SPEECH_WINDOW_HEIGHT, 
  .paletteNum = PHONE_BG_PAL_SLOT,
  .baseBlock = PHONE_STARTING_BASE_BLOCK
};

static const struct WindowTemplate sWindowTemplate_RotomSpeech_Bottom = {
    .bg = 0, 
    .tilemapLeft = ROTOM_SPEECH_WINDOW_LEFT, 
    .tilemapTop = ROTOM_SPEECH_WINDOW_TOP + 2, 
    .width = ROTOM_SPEECH_WINDOW_WIDTH, 
    .height = ROTOM_SPEECH_WINDOW_HEIGHT, 
    .paletteNum = PHONE_BG_PAL_SLOT,
    .baseBlock = PHONE_STARTING_BASE_BLOCK + (ROTOM_SPEECH_WINDOW_WIDTH*ROTOM_SPEECH_WINDOW_WIDTH)
};

static const struct WindowTemplate sWindowTemplate_FlipPhone = {
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 17,
    .width = 7,
    .height = 2,
    .paletteNum = PHONE_BG_PAL_SLOT,
    .baseBlock = PHONE_STARTING_BASE_BLOCK
};

static const struct WindowTemplate sRotomPhone_RotomRealityMenuWindowTemplates[] =
{
    [RP_RR_WIN_TIME] =
    {
        .bg = 0,
        .tilemapLeft = 13,
        .tilemapTop = 4,
        .width = 4,
        .height = 2,
        .paletteNum = PHONE_BG_PAL_SLOT,
        .baseBlock = 1
    },
    [RP_RR_WIN_MENU_NAME] =
    {
        .bg = 0,
        .tilemapLeft = 12,
        .tilemapTop = 6,
        .width = 6,
        .height = 2,
        .paletteNum = PHONE_BG_PAL_SLOT,
        .baseBlock = 1 + (4 * 8)
    },
    DUMMY_WIN_TEMPLATE
};
#define ROTOM_ROTOM_REALITY_NEXT_WIN_BASE_BLOCK 0xA0

static const struct WindowTemplate sRotomPhone_SaveScreen_Dialogue = {
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 15,
    .width = 26,
    .height = 4,
    .paletteNum = DLG_WINDOW_PALETTE_NUM,
    .baseBlock = 0xAA
};

static const struct BgTemplate sRotomPhone_RotomRealityMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    },
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .priority = 0
    }
};


static const struct SpritePalette sSpritePal_RotomFaceIcons[] =
{
    {sRotomPhone_StartMenuRotomFaceIconsPal, TAG_ROTOM_FACE_ICON_PAL},
    {NULL},
};

static const struct SpritePalette sSpritePal_RotomRealityIcons_Two[] =
{
    {sRotomPhone_RotomRealityMenuIconsPal_Two, TAG_PHONE_RR_ICON_GFX_2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_OverworldIcons[] = 
{
    {sRotomFlipPhone_OverworldIconsGfx, 32*352/2 , TAG_PHONE_OW_ICON_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_RotomRealityIcons_One[] = 
{
    {sRotomPhone_RotomRealityMenuIconsGfx_One, 32*352/2 , TAG_PHONE_RR_ICON_GFX},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_RotomRealityIcons_Two[] = 
{
    {sRotomPhone_RotomRealityMenuIconsGfx_Two, 32*32/2 , TAG_PHONE_RR_ICON_GFX_2},
    {NULL},
};

static const struct OamData sOam_RotomFace = {
    .size = SPRITE_SIZE(64x32),
    .shape = SPRITE_SHAPE(64x32),
    .priority = 0,
};

static const struct OamData sOam_RotomPhoneIcons = {
    .size = SPRITE_SIZE(32x32),
    .shape = SPRITE_SHAPE(32x32),
    .priority = 0,
};

enum RotomPhone_IconAnims
{
    RP_ICON_ANIM_BLANK,
    RP_ICON_ANIM_ONE,
    RP_ICON_ANIM_TWO,
    RP_ICON_ANIM_THREE,
    RP_ICON_ANIM_FOUR,
    RP_ICON_ANIM_FIVE,
    RP_ICON_ANIM_SIX,
    RP_ICON_ANIM_SEVEN,
    RP_ICON_ANIM_EIGHT,
    RP_ICON_ANIM_NINE,
    RP_ICON_ANIM_TEN,
    RP_ICON_ANIM_COUNT,
};

static const union AnimCmd sAnimCmd_MenuIcon_Blank[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_One[] = {
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Two[] = {
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Three[] = {
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Four[] = {
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Five[] = {
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Six[] = {
    ANIMCMD_FRAME(96, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Seven[] = {
    ANIMCMD_FRAME(112, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Eight[] = {
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Nine[] = {
    ANIMCMD_FRAME(144, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_MenuIcon_Ten[] = {
    ANIMCMD_FRAME(160, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_StartMenu_Icons[RP_ICON_ANIM_COUNT] = {
    sAnimCmd_MenuIcon_Blank,
    sAnimCmd_MenuIcon_One,
    sAnimCmd_MenuIcon_Two,
    sAnimCmd_MenuIcon_Three,
    sAnimCmd_MenuIcon_Four,
    sAnimCmd_MenuIcon_Five,
    sAnimCmd_MenuIcon_Six,
    sAnimCmd_MenuIcon_Seven,
    sAnimCmd_MenuIcon_Eight,
    sAnimCmd_MenuIcon_Nine,
    sAnimCmd_MenuIcon_Ten,
};

static const union AnimCmd sAnimCmd_RotomFace_Happy[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_HappyUp[] = {
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_HappyWith[] = {
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_Shocked[] = {
    ANIMCMD_FRAME(96, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_ShockedUp[] = {
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_ShockedWith[] = {
    ANIMCMD_FRAME(160, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_Dazed[] = {
    ANIMCMD_FRAME(192, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_Awe[] = {
    ANIMCMD_FRAME(224, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_Sheepish[] = {
    ANIMCMD_FRAME(256, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_RotomFace_Confused[] = {
    ANIMCMD_FRAME(288, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sRotomFaceAnims[RP_FACE_COUNT] = {
    sAnimCmd_RotomFace_Happy,
    sAnimCmd_RotomFace_HappyUp,
    sAnimCmd_RotomFace_HappyWith,
    sAnimCmd_RotomFace_Shocked,
    sAnimCmd_RotomFace_ShockedUp,
    sAnimCmd_RotomFace_ShockedWith,
    sAnimCmd_RotomFace_Dazed,
    sAnimCmd_RotomFace_Awe,
    sAnimCmd_RotomFace_Sheepish,
    sAnimCmd_RotomFace_Confused,
};

static const struct SpritePalette sSpritePal_RotomRealityShortcutIcon[] =
{
    {sRotomPhone_RotomRealityMenuShortcutPal, TAG_PHONE_RR_SHORTCUT_ICON},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_RotomRealityShortcutIcon[] = 
{
    {sRotomPhone_RotomRealityMenuShortcutGfx, 16*16/2 , TAG_PHONE_RR_SHORTCUT_ICON},
    {NULL},
};

static const struct OamData sOam_RotomRealityShortcutIcon = {
    .size = SPRITE_SIZE(16x16),
    .shape = SPRITE_SHAPE(16x16),
    .priority = 1,
};

static const struct SpriteTemplate sSpriteTemplate_RotomRealityShortcutIcon = {
    .tileTag = TAG_PHONE_RR_SHORTCUT_ICON,
    .paletteTag = TAG_PHONE_RR_SHORTCUT_ICON,
    .oam = &sOam_RotomRealityShortcutIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_CompatabilityIcon = {
    .data = sRotomPhone_DaycareCompatability_Gfx,
    .size = 32 * 32 * RP_DAYCARE_COMPATABILITY_ANIM_COUNT / 2,
    .tag = TAG_PHONE_RR_DAYCARE_ICON,
};

static const struct OamData sOam_IconDaycareCompatatbility = {
    .size = SPRITE_SIZE(32x32),
    .shape = SPRITE_SHAPE(32x32),
    .priority = 0,
};

static const union AnimCmd sAnim_IconDaycareCompatatbility_Not[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_IconDaycareCompatatbility_Low[] = {
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_IconDaycareCompatatbility_Med[] = {
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_IconDaycareCompatatbility_Max[] = {
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_IconDaycareCompatatbility[] =
{
    sAnim_IconDaycareCompatatbility_Not,
    sAnim_IconDaycareCompatatbility_Low,
    sAnim_IconDaycareCompatatbility_Med,
    sAnim_IconDaycareCompatatbility_Max,
};

static const struct SpriteTemplate sSpriteTemplate_OverworldIcon = {
    .tileTag = TAG_PHONE_OW_ICON_GFX,
    .paletteTag = TAG_ROTOM_FACE_ICON_PAL,
    .oam = &sOam_RotomPhoneIcons,
    .anims = sAnims_StartMenu_Icons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_RotomRealityIcons_One = {
    .tileTag = TAG_PHONE_RR_ICON_GFX,
    .paletteTag = TAG_ROTOM_FACE_ICON_PAL,
    .oam = &sOam_RotomPhoneIcons,
    .anims = sAnims_StartMenu_Icons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_RotomRealityIcons_Two = {
    .tileTag = TAG_PHONE_RR_ICON_GFX_2,
    .paletteTag = TAG_PHONE_RR_ICON_GFX_2,
    .oam = &sOam_RotomPhoneIcons,
    .anims = sAnims_StartMenu_Icons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_RotomFace = {
    .tileTag = TAG_ROTOM_FACE_GFX,
    .paletteTag = TAG_ROTOM_FACE_ICON_PAL,
    .oam = &sOam_RotomFace,
    .callback = SpriteCallbackDummy,
    .anims = sRotomFaceAnims,
    .affineAnims = gDummySpriteAffineAnimTable,
};

struct RotomPhone_MenuOptions
{
    const u8 *menuName;
    const u8 *rotomSpeech;
    bool32 (*unlockedFunc)(void);
    void (*selectedFunc)(void);
    u32 owIconPalSlot;
    bool32 rotomRealityPanel;
    enum RotomPhone_IconAnims owAnim;
    enum RotomPhone_IconAnims rrAnim;
    const struct SpriteTemplate *rrSpriteTemplate;
};
static const struct RotomPhone_MenuOptions sRotomPhoneOptions[RP_MENU_COUNT] =
{
    [RP_MENU_POKEDEX] =
    {
        .menuName = COMPOUND_STRING("Pokédex"),
        .rotomSpeech = COMPOUND_STRING("to open the Pokédex?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Pokedex,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Pokedex,
        .owIconPalSlot = PAL_ICON_RED,
        .owAnim = RP_ICON_ANIM_FOUR,
        .rrAnim = RP_ICON_ANIM_TWO,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_DEXNAV] =
    {
        .menuName = COMPOUND_STRING("DexNav"),
        .rotomSpeech = COMPOUND_STRING("to use the DexNav?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_DexNav,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_DexNav,
        .owIconPalSlot = PAL_ICON_ORANGE,
        .owAnim = RP_ICON_ANIM_SIX,
        .rrAnim = RP_ICON_ANIM_FOUR,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_PARTY] =
    {
        .menuName = COMPOUND_STRING("Party"),
        .rotomSpeech = COMPOUND_STRING("to view your Party?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Pokemon,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Pokemon,
        .owIconPalSlot = PAL_ICON_GREEN,
        .owAnim = RP_ICON_ANIM_FIVE,
        .rrAnim = RP_ICON_ANIM_THREE,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_BAG] =
    {
        .menuName = COMPOUND_STRING("Bag"),
        .rotomSpeech = COMPOUND_STRING("to look through your Bag?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Unlocked,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Bag,
        .owIconPalSlot = PAL_ICON_YELLOW,
        .owAnim = RP_ICON_ANIM_SEVEN,
        .rrAnim = RP_ICON_ANIM_FIVE,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_POKENAV] =
    {
        .menuName = COMPOUND_STRING("PokéNav"),
        .rotomSpeech = COMPOUND_STRING("to browse the PokéNav?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_PokeNav,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_PokeNav,
        .owIconPalSlot = PAL_ICON_ORANGE,
        .owAnim = RP_ICON_ANIM_EIGHT,
        .rrAnim = RP_ICON_ANIM_SIX,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_QUEST_LOG] =
    {
        .menuName = COMPOUND_STRING("Rotom Log"),
        .rotomSpeech = COMPOUND_STRING("to check your Rotom Log?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_RotomLog,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_RotomLog,
        .owIconPalSlot = PAL_ICON_BLUE,
        .owAnim = RP_ICON_ANIM_NINE,
        .rrAnim = RP_ICON_ANIM_SEVEN,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_TRAINER_CARD] =
    {
        .menuName = COMPOUND_STRING("Trainer"),
        .rotomSpeech = COMPOUND_STRING("to view your ID Card?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Unlocked_RotomReality,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Trainer,
        .rrAnim = RP_ICON_ANIM_TEN,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_SAVE] =
    {
        .menuName = COMPOUND_STRING("Save"),
        .rotomSpeech = COMPOUND_STRING("to write in your Journal?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Save,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Save,
        .owIconPalSlot = PAL_ICON_PURPLE,
        .owAnim = RP_ICON_ANIM_NINE,
        .rrAnim = RP_ICON_ANIM_SEVEN,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_OPTIONS] =
    {
        .menuName = COMPOUND_STRING("Settings"),
        .rotomSpeech = COMPOUND_STRING("to change the Settings?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Unlocked,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Settings,
        .owIconPalSlot = PAL_ICON_PINK,
        .owAnim = RP_ICON_ANIM_TEN,
        .rrAnim = RP_ICON_ANIM_EIGHT,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_FLAG] =
    {
        .menuName = COMPOUND_STRING("Retire"),
        .rotomSpeech = COMPOUND_STRING("to end the Safari?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_SafariFlag,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_SafariFlag,
        .owIconPalSlot = PAL_ICON_MONOCHROME,
        .owAnim = RP_ICON_ANIM_TWO,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_ROTOM_REALITY] =
    {
        .menuName = COMPOUND_STRING("Rotom Reality"),
        .rotomSpeech = COMPOUND_STRING("to enter Rotom Reality?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_RotomReality,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_RotomReality,
        .owIconPalSlot = PAL_ICON_BLUE,
        .owAnim = RP_ICON_ANIM_ONE,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_CLOCK] =
    {
        .menuName = COMPOUND_STRING("Clock"),
        .rotomSpeech = COMPOUND_STRING("to check the time?"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Clock,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Clock,
        .owIconPalSlot = PAL_ICON_GREEN,
        .owAnim = RP_ICON_ANIM_THREE,
        .rrAnim = RP_ICON_ANIM_ONE,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
    [RP_MENU_SHORTCUT] =
    {
        .menuName = COMPOUND_STRING("Shortcut"),
        .rotomSpeech = COMPOUND_STRING("Shortcut Action"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Shortcut,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Shortcut,
    },
    [RP_MENU_DAYCARE] =
    {
        .menuName = COMPOUND_STRING("Daycare"),
        .unlockedFunc = RotomPhone_StartMenu_UnlockedFunc_Unlocked_RotomReality,
        .selectedFunc = RotomPhone_StartMenu_SelectedFunc_Daycare,
        .rotomRealityPanel = TRUE,
        .rrAnim = RP_ICON_ANIM_NINE,
        .rrSpriteTemplate = &sSpriteTemplate_RotomRealityIcons_One,
    },
};
static enum RotomPhone_MenuItems RotomPhone_StartMenu_SetFirstSelectedMenu(void)
{
    // For flip phone, respect the actual display order
    if (!RP_CONFIG_USE_ROTOM_PHONE)
    {
        // If Party is unlocked, it's the first option; otherwise Clock is first
        if (sRotomPhoneOptions[RP_MENU_PARTY].unlockedFunc && sRotomPhoneOptions[RP_MENU_PARTY].unlockedFunc())
            return RP_MENU_PARTY;
        else if (sRotomPhoneOptions[RP_MENU_CLOCK].unlockedFunc && sRotomPhoneOptions[RP_MENU_CLOCK].unlockedFunc())
            return RP_MENU_CLOCK;
    }
    
    // Default behavior for Rotom phone: iterate through enum order
    for (enum RotomPhone_MenuItems menuOption = RP_MENU_FIRST_OPTION; menuOption < RP_MENU_COUNT; menuOption++)
    {
        if (sRotomPhoneOptions[menuOption].unlockedFunc && sRotomPhoneOptions[menuOption].unlockedFunc())
        {
            return menuOption;
        }
    }

    return RP_MENU_OPTIONS;
}


static const u8 *const sRotomPhone_Overworld_DayNames[] =
{
    COMPOUND_STRING("Friday"),
    COMPOUND_STRING("Saturday"),
    COMPOUND_STRING("Sunday"),
    COMPOUND_STRING("Monday"),
    COMPOUND_STRING("Tuesday"),
    COMPOUND_STRING("Wednesday"),
    COMPOUND_STRING("Thursday"),
};

static const u8 *const sRotomPhone_Overworld_WeatherActions[WEATHER_COUNT] =
{
    [WEATHER_NONE]               = COMPOUND_STRING("sunny"),
    [WEATHER_SUNNY_CLOUDS]       = COMPOUND_STRING("cloudy"),
    [WEATHER_SUNNY]              = COMPOUND_STRING("sunny"),
    [WEATHER_RAIN]               = COMPOUND_STRING("raining"),
    [WEATHER_SNOW]               = COMPOUND_STRING("snowing"),
    [WEATHER_RAIN_THUNDERSTORM]  = COMPOUND_STRING("thunderstorming"),
    [WEATHER_FOG_HORIZONTAL]     = COMPOUND_STRING("foggy"),
    [WEATHER_VOLCANIC_ASH]       = COMPOUND_STRING("ashen"),
    [WEATHER_SANDSTORM]          = COMPOUND_STRING("sandstorming"),
    [WEATHER_FOG_DIAGONAL]       = COMPOUND_STRING("foggy"),
    [WEATHER_UNDERWATER]         = COMPOUND_STRING("watery"),
    [WEATHER_SHADE]              = COMPOUND_STRING("shady"),
    [WEATHER_DROUGHT]            = COMPOUND_STRING("very hot"),
    [WEATHER_DOWNPOUR]           = COMPOUND_STRING("raining heavily"),
    [WEATHER_FOG]                = COMPOUND_STRING("foggy"),
    [WEATHER_UNDERWATER_BUBBLES] = COMPOUND_STRING("watery"),
};
static const u8 sText_WeatherDark[] = _("dark");
static const u8 *RotomPhone_OverworldMenu_GetWeatherAction(u32 weatherId)
{
    if ((weatherId == WEATHER_NONE || weatherId == WEATHER_SUNNY) && gTimeOfDay == TIME_NIGHT)
        return sText_WeatherDark;

    return sRotomPhone_Overworld_WeatherActions[weatherId];
}


// Rotom Phone Overworld Menu
#define tRotomUpdateTimer gTasks[taskId].data[0]
#define tRotomUpdateMessage gTasks[taskId].data[1]
#define tRotomMessageSoundEffect gTasks[taskId].data[2]
#define tRotomPanelComfyAnimId gTasks[taskId].data[3]
#define tRotomPanelLastY gTasks[taskId].data[4]
#define tPhoneY gTasks[taskId].data[5]
#define tPhoneComfyAnimId gTasks[taskId].data[6]
#define tPhoneCloseParameterSaveSafariFade gTasks[taskId].data[7]
#define tPhoneHighlightComfyAnimId gTasks[taskId].data[8]
#define tRotomHintActive gTasks[taskId].data[9]
#define tRotomHintPromptState gTasks[taskId].data[10]
static void RotomPhone_OverworldMenu_Init(bool32 firstInit)
{
    u8 taskId;

    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }

    HideMapNamePopUpWindow();
    ResetDexNavSearch();

    // Wait for VBlank to start and end in order to prevent graphical issues.
    while (REG_VCOUNT >= 160);
    while (REG_VCOUNT < 160);

    LockPlayerFieldControls();

    if (sRotomPhone_StartMenu == NULL)
    {
        sRotomPhone_StartMenu = AllocZeroed(sizeof(struct RotomPhone_StartMenu_State));
    }

    if (sRotomPhone_StartMenu == NULL)
    {
        if (sRotomPhone_StartMenuFromScript)
            RotomPhone_StartMenu_ClearScriptState();
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        return;
    }

    if (RP_CONFIG_ROTOM_ACTIVE && RP_CONFIG_UPDATE_MESSAGE_SOUND)
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x80);

    sRotomPhone_StartMenu->menuOverworldLoading = FALSE;
    sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId = 0;
    sRotomPhone_RotomReality = FALSE;

    sRotomPhone_StartMenu->menuRotomFaceSpriteId = SPRITE_NONE;
    sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId = SPRITE_NONE;
    for (enum RotomPhone_Overworld_Options overworldOptions = RP_OW_OPTION_1; overworldOptions < RP_OW_OPTION_COUNT; overworldOptions++)
    {
        sRotomPhone_StartMenu->menuOverworldIconSpriteId[overworldOptions] = SPRITE_NONE;
        sRotomPhone_StartMenu->menuOverworldIconFlashSpriteId[overworldOptions] = SPRITE_NONE;
    }

    sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId = WINDOW_NONE;
    sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId = WINDOW_NONE;
    sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId = WINDOW_NONE;

    RotomPhone_OverworldMenu_LoadBgGfx(firstInit);
    RotomPhone_OverworldMenu_LoadSprites();

    if (firstInit)
    {
        SetGpuReg(REG_OFFSET_BG0VOFS, -PHONE_OFFSCREEN_Y);
        taskId = CreateTask(Task_RotomPhone_OverworldMenu_PhoneSlideOpen, 0);
        tPhoneY = PHONE_OFFSCREEN_Y;
        return;
    }

    RotomPhone_OverworldMenu_ContinueInit(FALSE);
}

static void RotomPhone_OverworldMenu_ContinueInit(bool32 firstInit)
{
    u8 taskId = FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_PhoneSlideOpen);

    RotomPhone_OverworldMenu_CreateAllIconSprites();
    RotomPhone_StartMenu_CreateRotomFaceSprite(FALSE);
    RotomPhone_OverworldMenu_CreateSpeechWindows();
    RotomPhone_OverworldMenu_CreateFlipPhoneWindow();
    ScheduleBgCopyTilemapToVram(0);

    if (!sRotomPhoneOptions[menuSelectedOverworld].unlockedFunc || !sRotomPhoneOptions[menuSelectedOverworld].unlockedFunc())
        menuSelectedOverworld = RotomPhone_StartMenu_SetFirstSelectedMenu();

    if (sRotomPhone_StartMenuFromScript)
    {
        enum RotomPhone_MenuItems target = (enum RotomPhone_MenuItems)sRotomPhone_StartMenuScriptTarget;
        if (sRotomPhone_StartMenuScriptTarget != ROTOM_SCRIPT_MENU_NONE
         && RotomPhone_StartMenu_IsValidScriptTarget(sRotomPhone_StartMenuScriptTarget)
         && target < RP_MENU_COUNT)
            menuSelectedOverworld = target;
    }

    if (firstInit)
        gTasks[taskId].func = Task_RotomPhone_OverworldMenu_HandleMainInput;
    else
        taskId = CreateTask(Task_RotomPhone_OverworldMenu_HandleMainInput, 0);

    struct ComfyAnimSpringConfig config;
    InitComfyAnimConfig_Spring(&config);
    config.from = Q_24_8(FADE_COLOUR_MIN);
    config.to = Q_24_8(FADE_COLOUR_MAX);
    config.mass = Q_24_8(FACE_ICON_COMFY_SPRING_MASS);
    config.tension = Q_24_8(FACE_ICON_COMFY_SPRING_TENSION);
    config.friction = Q_24_8(FACE_ICON_COMFY_SPRING_FRICTION);
    config.clampAfter = FACE_ICON_COMFY_SPRING_CLAMP_AFTER;
    tPhoneHighlightComfyAnimId = CreateComfyAnim_Spring(&config);

    tRotomUpdateTimer = ROTOM_PHONE_OW_MESSGAGE_TIMER / RP_CONFIG_NUM_MINUTES_TO_UPDATE;
    tRotomUpdateMessage = RP_MESSAGE_TIME;
    tRotomHintActive = FALSE;
    tRotomHintPromptState = 0;

    if (GetSafariZoneFlag())
        tRotomUpdateMessage = RP_MESSAGE_SAFARI;

    if (firstInit)
        RotomPhone_OverworldMenu_PrintGreeting();
    else
        tRotomUpdateTimer = FALSE;

    if (sRotomPhone_StartMenuFromScript)
        tRotomUpdateTimer = 0x7FFF;

    RotomPhone_OverworldMenu_UpdateMenuPrompt(taskId);
}

static void RotomPhone_OverworldMenu_LoadIconSpritePalette(bool32 firstLoad)
{
#if RP_CONFIG_PALETTE_BUFFER
    if (firstLoad)
    {
        memcpy(menuLoadedSpritePalette_One, sRotomPhone_StartMenuRotomFaceIconsPal, PLTT_SIZE_4BPP);
        if (!RP_CONFIG_USE_ROTOM_PHONE || RP_CONFIG_MONOCHROME_ICONS)
        {
            for (enum RotomPhone_Overworld_FaceIconPaletteIndex colour = PAL_FACE_ICON_TRANSPARENT + 1; colour < PAL_ICON_WHITE; colour++)
            {
                memcpy(&menuLoadedSpritePalette_One[colour], &sRotomPhone_StartMenuRotomFaceIconsPal[PAL_ICON_MONOCHROME], sizeof(u16)); 
            }
        }

        memcpy(menuLoadedSpritePalette_Two, sRotomPhone_RotomRealityMenuIconsPal_Two, PLTT_SIZE_4BPP);
        if (!RP_CONFIG_USE_ROTOM_PHONE || RP_CONFIG_MONOCHROME_ICONS)
        {
            for (enum RotomPhone_Overworld_FaceIconPaletteIndex colour = PAL_FACE_ICON_TRANSPARENT + 1; colour < PAL_ICON_WHITE; colour++)
            {
                memcpy(&menuLoadedSpritePalette_Two[colour], &sRotomPhone_StartMenuRotomFaceIconsPal[PAL_ICON_MONOCHROME], sizeof(u16)); 
            }
        }
    }
    LoadPalette(menuLoadedSpritePalette_One, OBJ_PLTT_ID(IndexOfSpritePaletteTag(TAG_ROTOM_FACE_ICON_PAL)), PLTT_SIZE_4BPP);
#else
    u32 index = IndexOfSpritePaletteTag(TAG_ROTOM_FACE_ICON_PAL);
    LoadPalette(sRotomPhone_StartMenuRotomFaceIconsPal, OBJ_PLTT_ID(index), PLTT_SIZE_4BPP); 
    if (!RP_CONFIG_USE_ROTOM_PHONE || RP_CONFIG_MONOCHROME_ICONS)
    {
        for (enum RotomPhone_Overworld_FaceIconPaletteIndex colour = PAL_FACE_ICON_TRANSPARENT + 1; colour < PAL_ICON_WHITE; colour++)
        {
            LoadPalette(&sRotomPhone_StartMenuRotomFaceIconsPal[PAL_ICON_MONOCHROME], OBJ_PLTT_ID(index) + colour, sizeof(u16));
        }
    }
#endif
}

static void RotomPhone_OverworldMenu_LoadSprites(void)
{
    LoadSpritePalette(sSpritePal_RotomFaceIcons);
    LoadCompressedSpriteSheet(sSpriteSheet_OverworldIcons);
    RotomPhone_StartMenu_LoadRotomFaceSpritesheet();

    RotomPhone_OverworldMenu_LoadIconSpritePalette(TRUE);
}

static void RotomPhone_OverworldMenu_CreateIconSprite(enum RotomPhone_MenuItems menuItem, enum RotomPhone_Overworld_Options spriteId)
{
    bool32 flash = FALSE;
    s32 x = 190;
    s32 y = 58;
    s32 xAdd = 24;
    s32 yAdd = 22;
    u32 iconRow;
    u32 iconColumn;
    u32 animNum;
    if (menuItem != RP_MENU_SHORTCUT)
        animNum = sRotomPhoneOptions[menuItem].owAnim;
    else
        animNum = sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_OW].owAnim;

    if (!RP_CONFIG_USE_ROTOM_PHONE)
    {
        y += 24;
        yAdd = 25;
    }

    iconColumn = spriteId % 2;
    iconRow = spriteId / 2;

    if (GetFlashLevel() > 0 || InBattlePyramid_())
        flash = TRUE;

    if (flash)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
    }

    sRotomPhone_StartMenu->menuOverworldIconSpriteId[spriteId] = CreateSprite(
        &sSpriteTemplate_OverworldIcon,
        x + (iconColumn * xAdd),
        y + (iconRow * yAdd),
        0
    );
    StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuOverworldIconSpriteId[spriteId]], animNum);

    if (flash)
    {
        sRotomPhone_StartMenu->menuOverworldIconFlashSpriteId[spriteId] = CreateSprite(
            &sSpriteTemplate_OverworldIcon,
            x + (iconColumn * xAdd),
            y + (iconRow * yAdd),
            0
        );
        gSprites[sRotomPhone_StartMenu->menuOverworldIconFlashSpriteId[spriteId]].oam.objMode = ST_OAM_OBJ_WINDOW;
        StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuOverworldIconFlashSpriteId[spriteId]], animNum);
    }
}

static void RotomPhone_OverworldMenu_CreateAllIconSprites(void)
{
    enum RotomPhone_Overworld_Options drawn = RP_OW_OPTION_1;
    u32 drawnCount = RP_OW_OPTION_COUNT;
    if (!RP_CONFIG_USE_ROTOM_PHONE)
        drawnCount = 4; // flip-phone shows 4 icons

    if (!RP_CONFIG_USE_ROTOM_PHONE)
    {
        // If Party is unlocked, normal order: Party, Bag, Save, Options.
        // If Party is locked, put Clock at the beginning: Clock, Bag, Save, Options.
        enum RotomPhone_MenuItems desiredOrder[4];

        if (sRotomPhoneOptions[RP_MENU_PARTY].unlockedFunc && sRotomPhoneOptions[RP_MENU_PARTY].unlockedFunc())
        {
            desiredOrder[0] = RP_MENU_PARTY;
            desiredOrder[1] = RP_MENU_BAG;
            desiredOrder[2] = RP_MENU_SAVE;
            desiredOrder[3] = RP_MENU_OPTIONS;
        }
        else
        {
            desiredOrder[0] = RP_MENU_CLOCK;
            desiredOrder[1] = RP_MENU_BAG;
            desiredOrder[2] = RP_MENU_SAVE;
            desiredOrder[3] = RP_MENU_OPTIONS;
        }

        for (u32 i = 0; i < 4 && drawn < drawnCount; ++i)
        {
            enum RotomPhone_MenuItems menuId = desiredOrder[i];
            const struct RotomPhone_MenuOptions *menuOption = &sRotomPhoneOptions[menuId];

            if (menuOption->unlockedFunc && menuOption->unlockedFunc())
            {
                enum RotomPhone_Overworld_Options optionSlot = RP_OW_OPTION_1 + drawn;
                RotomPhone_OverworldMenu_CreateIconSprite(menuId, optionSlot);
                sRotomPhone_StartMenu->menuOverworldOptions[optionSlot] = menuId;
                drawn++;
            }
        }

        /* If fewer than 4 unlocked, fill remaining slots with first unlocked options in table order */
        if (drawn < drawnCount)
        {
            for (enum RotomPhone_MenuItems menuId = RP_MENU_FIRST_OPTION; menuId < RP_MENU_COUNT && drawn < drawnCount; ++menuId)
            {
                const struct RotomPhone_MenuOptions *menuOption = &sRotomPhoneOptions[menuId];
                if (menuOption->unlockedFunc && menuOption->unlockedFunc())
                {
                    enum RotomPhone_Overworld_Options optionSlot = RP_OW_OPTION_1 + drawn;
                    RotomPhone_OverworldMenu_CreateIconSprite(menuId, optionSlot);
                    sRotomPhone_StartMenu->menuOverworldOptions[optionSlot] = menuId;
                    drawn++;
                }
            }
        }
    }
    else
    {
        for (enum RotomPhone_MenuItems menuId = RP_MENU_FIRST_OPTION; menuId < RP_MENU_COUNT && drawn < drawnCount; menuId++)
        {
            const struct RotomPhone_MenuOptions *menuOption = &sRotomPhoneOptions[menuId];

            if (menuOption->unlockedFunc && menuOption->unlockedFunc())
            {
                enum RotomPhone_Overworld_Options optionSlot = RP_OW_OPTION_1 + drawn;
                RotomPhone_OverworldMenu_CreateIconSprite(menuId, optionSlot);
                sRotomPhone_StartMenu->menuOverworldOptions[optionSlot] = menuId;
                drawn++;
            }
        }
    }

    for (; drawn < RP_OW_OPTION_COUNT; drawn++)
        sRotomPhone_StartMenu->menuOverworldOptions[drawn] = RP_MENU_COUNT;
}

static void RotomPhone_OverworldMenu_LoadBgPalette(bool32 firstLoad)
{
#if RP_CONFIG_PALETTE_BUFFER
    if (firstLoad)
    {
        memcpy(menuLoadedBackgroundPalette, RotomPhone_StartMenu_GetPhoneColour(), PLTT_SIZE_4BPP);
    }
    LoadPalette(menuLoadedBackgroundPalette, BG_PLTT_ID(PHONE_BG_PAL_SLOT), PLTT_SIZE_4BPP);
#else
    LoadPalette(RotomPhone_StartMenu_GetPhoneColour(), BG_PLTT_ID(PHONE_BG_PAL_SLOT), PLTT_SIZE_4BPP);
#endif
}

static void RotomPhone_OverworldMenu_LoadBgGfx(bool32 firstInit)
{
    u8* buf = GetBgTilemapBuffer(0);
    const u32 *tilemap;
    LoadBgTilemap(0, 0, 0, 0);
    if (RP_CONFIG_USE_ROTOM_PHONE)
    {
        DecompressAndCopyTileDataToVram(0, sRotomPhone_OverworldTiles, 0, 0, 0);
        DecompressDataWithHeaderVram(sRotomPhone_OverworldTilemap, buf);
    }
    else
    {
        if (firstInit)
            tilemap = sFlipPhone_OverworldClosedTilemap;
        else
            tilemap = sFlipPhone_OverworldOpenTilemap;
        
        DecompressAndCopyTileDataToVram(0, sFlipPhone_OverworldTiles, 0, 0, 0);
        DecompressDataWithHeaderVram(tilemap, buf);
    }

    RotomPhone_OverworldMenu_LoadBgPalette(TRUE);
    ScheduleBgCopyTilemapToVram(0);
}

#define ROTOM_SPEECH_TOP_ROW_Y      1
#define ROTOM_SPEECH_BOTTOM_ROW_Y   1
static void RotomPhone_OverworldMenu_CreateSpeechWindows(void)
{
    if (!RP_CONFIG_ROTOM_ACTIVE)
        return;

    DecompressDataWithHeaderVram(sRotomPhone_OverworldSpeechTilemap, GetBgTilemapBuffer(0));

    sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId = AddWindow(&sWindowTemplate_RotomSpeech_Top);
    FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId, PIXEL_FILL(OW_ROTOM_PHONE_TEXT_BG_COLOUR));
    PutWindowTilemap(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId);

    sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId = AddWindow(&sWindowTemplate_RotomSpeech_Bottom);
    FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId, PIXEL_FILL(OW_ROTOM_PHONE_TEXT_BG_COLOUR));
    PutWindowTilemap(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId);
}

static void RotomPhone_OverworldMenu_CreateFlipPhoneWindow(void)
{
    if (RP_CONFIG_USE_ROTOM_PHONE)
        return;
    
    sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId = AddWindow(&sWindowTemplate_FlipPhone);
    FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, PIXEL_FILL(OW_FLIP_PHONE_TEXT_BG_COLOUR));
    PutWindowTilemap(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId);
}

static void RotomPhone_OverworldMenu_PrintRotomSpeech(u8 textBuffer[80], bool32 top, bool32 copy)
{
    u8 fontId = GetFontIdToFit(textBuffer, FONT_SHORT, 0, ROTOM_SPEECH_WINDOW_WIDTH_PXL);
    u32 windowId;
    windowId = (top == TRUE) ? sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId : sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(OW_ROTOM_PHONE_TEXT_BG_COLOUR));
    AddTextPrinterParameterized4(windowId, fontId,
        GetStringCenterAlignXOffset(fontId, textBuffer, ROTOM_SPEECH_WINDOW_WIDTH_PXL),
        ROTOM_SPEECH_TOP_ROW_Y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_OW_ROTOM_PHONE], TEXT_SKIP_DRAW, textBuffer);
    
    if (copy)
        CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void RotomPhone_OverworldMenu_PrintGreeting(void)
{
    if (!RP_CONFIG_ROTOM_ACTIVE)
        return;
    
    u8 textBuffer[80];
    enum RotomPhone_Overworld_MessagesGreeting messageRotom = Random() % RP_MESSAGE_GREETING_COUNT;

    switch (messageRotom)
    {
    default:
    case RP_MESSAGE_GREETING_GOOD_DAY:
        switch (gTimeOfDay)
        {
        case TIME_MORNING:
            StringCopy(textBuffer, COMPOUND_STRING("Good morning, "));
            break;

        default:
        case TIME_DAY:
            StringCopy(textBuffer, COMPOUND_STRING("Good day, "));
            break;

        case TIME_EVENING:
            StringCopy(textBuffer, COMPOUND_STRING("Good evening, "));
            break;

        case TIME_NIGHT:
            StringCopy(textBuffer, COMPOUND_STRING("Good night, "));
            break;
        }
        break;
    
    case RP_MESSAGE_GREETING_HELLO:
        StringCopy(textBuffer, COMPOUND_STRING("Hello there, "));
        break;
    
    case RP_MESSAGE_GREETING_HI:
        StringCopy(textBuffer, COMPOUND_STRING("Hi, "));
        break;
    
    case RP_MESSAGE_GREETING_HOW_ARE_YOU:
        StringCopy(textBuffer, COMPOUND_STRING("How are you, "));
        break;
    }

    StringAppend(textBuffer, gSaveBlock2Ptr->playerName);

    if (messageRotom != RP_MESSAGE_GREETING_HOW_ARE_YOU)
        StringAppend(textBuffer, COMPOUND_STRING("."));
    else
        StringAppend(textBuffer, COMPOUND_STRING("?"));

    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);
    PlaySE(SE_PC_ON);
}

static enum RotomPhone_Overworld_Messages RotomPhone_OverworldMenu_GetRandomMessage(void)
{
    enum RotomPhone_Overworld_Messages messageRandom;

    if (!RP_CONFIG_UPDATE_MESSAGE)
        return RP_MESSAGE_TIME;

    messageRandom = Random() % RP_MESSAGE_COUNT;
    while (messageRandom == RP_MESSAGE_GOODBYE
    || messageRandom == RP_MESSAGE_TIME
    || messageRandom == RP_MESSAGE_SAFARI
    || messageRandom == RP_MESSAGE_HINT_PROMPT)
    {
        messageRandom = Random() % RP_MESSAGE_COUNT;
    }

    return messageRandom;
}

static void RotomPhone_OverworldMenu_CheckUpdateMessage(u8 taskId)
{
    if (!tRotomUpdateTimer && RP_CONFIG_ROTOM_ACTIVE)
    {
        bool32 hadHintActive = tRotomHintActive;

        switch (tRotomUpdateMessage)
        {
        case RP_MESSAGE_GOODBYE:
            RotomPhone_OverworldMenu_PrintGoodbye(taskId);
            break;
        
        default:
        case RP_MESSAGE_TIME:
            RotomPhone_OverworldMenu_PrintTime(taskId);
            break;

        case RP_MESSAGE_SAFARI:
            RotomPhone_OverworldMenu_PrintSafari(taskId);
            break;
        
        case RP_MESSAGE_DATE_WEATHER:
            RotomPhone_OverworldMenu_PrintDateWeather(taskId);
            break;

        case RP_MESSAGE_PERSONALITY:
            RotomPhone_OverworldMenu_Personality(taskId);
            break;

        case RP_MESSAGE_FUN:
            RotomPhone_OverworldMenu_PrintHaveFun(taskId);
            break;

        case RP_MESSAGE_ADVENTURE:
            RotomPhone_OverworldMenu_PrintAdventure(taskId);
            break;

        case RP_MESSAGE_HINT_PROMPT:
            RotomPhone_OverworldMenu_PrintHintPrompt(taskId);
            break;
        }
        tRotomUpdateTimer = ROTOM_PHONE_OW_MESSGAGE_TIMER;
        if (!RP_CONFIG_UPDATE_MESSAGE && !GetSafariZoneFlag() && tRotomUpdateMessage != RP_MESSAGE_GOODBYE)
            tRotomUpdateTimer *= 2;
        
        if (RP_CONFIG_UPDATE_MESSAGE_SOUND && tRotomUpdateMessage != RP_MESSAGE_GOODBYE)
            tRotomMessageSoundEffect = SE_SELECT;
        
        if (hadHintActive)
        {
            tRotomHintActive = FALSE;
            RotomPhone_OverworldMenu_UpdateMenuPrompt(taskId);
        }

        RotomPhone_StartMenu_UpdateRotomFaceAnim(FALSE);
    }
}

static void RotomPhone_OverworldMenu_PrintGoodbye(u8 taskId)
{
    u8 textBuffer[80];
    enum RotomPhone_Overworld_MessagesGoodbye messageRotom = Random() % RP_MESSAGE_GOODBYE_COUNT;

    switch (messageRotom)
    {
    default:
    case RP_MESSAGE_GOODBYE_GOODBYE:
        StringCopy(textBuffer, COMPOUND_STRING("Goodbye, "));
        StringAppend(textBuffer, gSaveBlock2Ptr->playerName);
        StringAppend(textBuffer, COMPOUND_STRING("."));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, FALSE);

        StringCopy(textBuffer, COMPOUND_STRING("I'll see you later!"));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, FALSE, FALSE);
        break;
    
    case RP_MESSAGE_GOODBYE_SEE_YA:
        StringCopy(textBuffer, COMPOUND_STRING("See ya later, "));
        StringAppend(textBuffer, gSaveBlock2Ptr->playerName);
        StringAppend(textBuffer, COMPOUND_STRING("!"));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, FALSE);

        StringCopy(textBuffer, COMPOUND_STRING("Don't miss me too much."));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, FALSE, FALSE);
        break;
    
    case RP_MESSAGE_GOODBYE_LOGGING_OFF:
        StringCopy(textBuffer, COMPOUND_STRING("Logging off for now…"));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, FALSE);

        StringCopy(textBuffer, COMPOUND_STRING("Catch you later, "));
        StringAppend(textBuffer, gSaveBlock2Ptr->playerName);
        StringAppend(textBuffer, COMPOUND_STRING("."));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, FALSE, FALSE);
        break;
    
    case RP_MESSAGE_GOODBYE_POWERING_DOWN:
        StringCopy(textBuffer, COMPOUND_STRING("3… 2… 1… Powering down…"));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, FALSE);

        StringCopy(textBuffer, COMPOUND_STRING("Until next time, "));
        StringAppend(textBuffer, gSaveBlock2Ptr->playerName);
        StringAppend(textBuffer, COMPOUND_STRING("."));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, FALSE, FALSE);
        break;
    }

    if (FuncIsActiveTask(Task_RotomPhone_OverworldMenu_CloseAndSave))
    {
        StringCopy(textBuffer, COMPOUND_STRING("Preparing to record progress…"));
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, FALSE);
    }

    CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId, COPYWIN_GFX);
    CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId, COPYWIN_GFX);
}

static void RotomPhone_OverworldMenu_PrintTime(u8 taskId)
{
    u8 textBuffer[80];
    u8 time[24];

    RtcCalcLocalTime();
    FormatDecimalTimeWithoutSeconds(time, gLocalTime.hours, gLocalTime.minutes, RP_CONFIG_24_HOUR_MODE);
    StringCopy(textBuffer, COMPOUND_STRING("It is "));
    StringAppend(textBuffer, time);
    StringAppend(textBuffer, COMPOUND_STRING(" on "));
    StringAppend(textBuffer, sRotomPhone_Overworld_DayNames[(gLocalTime.days % WEEKDAY_COUNT)]);
    StringAppend(textBuffer, COMPOUND_STRING("."));
    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);

    if (tRotomHintPromptState == 1)
    {
        tRotomUpdateMessage = RP_MESSAGE_HINT_PROMPT;
        tRotomHintPromptState = 2;
    }
    else
    {
        tRotomUpdateMessage = RotomPhone_OverworldMenu_GetRandomMessage();
        if (tRotomHintPromptState == 0)
            tRotomHintPromptState = 1;
    }

    if (GetSafariZoneFlag())
        tRotomUpdateMessage = RP_MESSAGE_SAFARI;
}

static void RotomPhone_OverworldMenu_PrintSafari(u8 taskId)
{
    u8 textBuffer[80];
    u8 numBalls[2];
    u8 nameItem[20];

    ConvertIntToDecimalStringN(numBalls, gNumSafariBalls, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringCopy(textBuffer, COMPOUND_STRING("You have "));
    StringAppend(textBuffer, numBalls);
    StringAppend(textBuffer, COMPOUND_STRING(" "));
    CopyItemNameHandlePlural(ITEM_SAFARI_BALL, nameItem, gNumSafariBalls);
    StringAppend(textBuffer, nameItem);
    StringAppend(textBuffer, COMPOUND_STRING(" remaining."));
    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);
    tRotomUpdateMessage = RP_MESSAGE_TIME;
}

static void RotomPhone_OverworldMenu_PrintDateWeather(u8 taskId)
{
    u8 textBuffer[80];
    // enum RotomPhone_Overworld_MessagesDateWeather messageRotom = Random() % RP_MESSAGE_DATE_WEATHER_COUNT;

    // if (messageRotom == RP_MESSAGE_DATE_WEATHER_SEASON)
    // {
    //     switch (Ikigai_FetchSeason())
    //     {
    //     default:
    //     case SEASON_SPRING:
    //         StringCopy(textBuffer, COMPOUND_STRING("Everything's blooming, including you!"));
    //         break;
        
    //     case SEASON_SUMMER:
    //         StringCopy(textBuffer, COMPOUND_STRING("It's hot, it's bright, it's calling!"));
    //         break;
        
    //     case SEASON_AUTUMN:
    //         StringCopy(textBuffer, COMPOUND_STRING("Time for cozy vives and crunchy leaves!"));
    //         break;
        
    //     case SEASON_WINTER:
    //         StringCopy(textBuffer, COMPOUND_STRING("Bundle up! Even my pixels get chilly."));
    //         break;
    //     }
    // }
    // else if (messageRotom == RP_MESSAGE_DATE_WEATHER_CURRENT_WEATHER)
    // {
        StringCopy(textBuffer, COMPOUND_STRING("Looking like it is "));
        StringAppend(textBuffer, RotomPhone_OverworldMenu_GetWeatherAction(GetCurrentWeather()));
        StringAppend(textBuffer, COMPOUND_STRING(" right now."));
    // }
    // else if (messageRotom == RP_MESSAGE_DATE_WEATHER_NEXT_WEATHER && gTimeOfDay < TIME_NIGHT)
    // {
    //     StringCopy(textBuffer, COMPOUND_STRING("It feels like it will be "));
    //     StringAppend(textBuffer, RotomPhone_OverworldMenu_GetWeatherAction(Ikigai_GetCurrentVyratonWeather(gTimeOfDay + 1)));
    //     StringAppend(textBuffer, COMPOUND_STRING(" later."));
    // }
    // else
    // {
    //     u8 textDate[2];
    //     u8 textYear[3];

    //     RtcCalcLocalTime();
    //     StringCopy(textBuffer, COMPOUND_STRING("The date is "));
    //     ConvertIntToDecimalStringN(textDate, Ikigai_GetDateFromDays(gLocalTime.days), STR_CONV_MODE_LEADING_ZEROS, 2);
    //     StringAppend(textBuffer, textDate);
    //     StringAppend(textBuffer, COMPOUND_STRING(" "));
    //     StringAppend(textBuffer, gSeasonNames[Ikigai_FetchSeason()]);
    //     StringAppend(textBuffer, COMPOUND_STRING(", Year "));
    //     ConvertIntToDecimalStringN(textYear, Ikigai_GetYearFromDays(gLocalTime.days), STR_CONV_MODE_LEFT_ALIGN, 3);
    //     StringAppend(textBuffer, textYear);
    //     StringAppend(textBuffer, COMPOUND_STRING("."));
    // }

    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);
    tRotomUpdateMessage = RP_MESSAGE_TIME;
}

static void RotomPhone_OverworldMenu_Personality(u8 taskId)
{
    u8 textBuffer[80];
    enum RotomPhone_Overworld_MessagesPersonality messageRotom = Random() % RP_MESSAGE_PERSONALITY_COUNT;

    switch (messageRotom)
    {
    default:
    case RP_MESSAGE_PERSONALITY_MEEP_MORP:
        StringCopy(textBuffer, COMPOUND_STRING("Meep-morp!"));
        break;
    
    case RP_MESSAGE_PERSONALITY_HANDS:
        StringCopy(textBuffer, COMPOUND_STRING("If I had hands, I'd give you a high-five!"));
        break;
    
    case RP_MESSAGE_PERSONALITY_RINGTONE:
        StringCopy(textBuffer, COMPOUND_STRING("I've got a new ringtone to show you!"));
        break;
    
    case RP_MESSAGE_PERSONALITY_SCANNING:
        StringCopy(textBuffer, COMPOUND_STRING("Scanning… Yup, you're still awesome!"));
        break;
    }
    
    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);
    tRotomUpdateMessage = RP_MESSAGE_TIME;
}

static void RotomPhone_OverworldMenu_PrintHaveFun(u8 taskId)
{
    u8 textBuffer[80];
    enum RotomPhone_Overworld_MessagesFun messageRotom = Random() % RP_MESSAGE_FUN_COUNT;

    switch (messageRotom)
    {
    default:
    case RP_MESSAGE_FUN_WINNING_GRINNING:
        StringCopy(textBuffer, COMPOUND_STRING("If you're winning, I am grinning!"));
        break;
    
    case RP_MESSAGE_FUN_ANYMORE_BATTLES:
        StringCopy(textBuffer, COMPOUND_STRING("Do we have anymore battles today?"));
        break;
    
    case RP_MESSAGE_FUN_FUN_DETECTED:
        StringCopy(textBuffer, COMPOUND_STRING("Fun detected, AMPLIFYING!"));
        break;
    
    case RP_MESSAGE_FUN_SOMETHING_SILLY:
        StringCopy(textBuffer, COMPOUND_STRING("Wanna do something silly? I am in!"));
        break;
    }

    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);
    tRotomUpdateMessage = RP_MESSAGE_TIME;
}

static void RotomPhone_OverworldMenu_PrintAdventure(u8 taskId)
{
    u8 textBuffer[80];
    enum RotomPhone_Overworld_MessagesAdventure messageRotom = Random() % RP_MESSAGE_ADVENTURE_COUNT;

    switch (messageRotom)
    {
    default:
    case RP_MESSAGE_ADVENTURE_TO_DO:
        u8 location[16];
        StringCopy(textBuffer, COMPOUND_STRING("What's there to do in "));
        GetMapName(location, GetCurrentRegionMapSectionId(), 0);
        StringAppend(textBuffer, location);
        StringAppend(textBuffer, COMPOUND_STRING("?"));
        break;
    
    case RP_MESSAGE_ADVENTURE_GET_LOST:
        StringCopy(textBuffer, COMPOUND_STRING("Let's get lost, in the best way."));
        break;
    
    case RP_MESSAGE_ADVENTURE_STEP_STORY:
        StringCopy(textBuffer, COMPOUND_STRING("One more step, one more story."));
        break;
    
    case RP_MESSAGE_ADVENTURE_PACK_CURIOSITY:
        StringCopy(textBuffer, COMPOUND_STRING("Pack your curiosity, we're going exploring."));
        break;
    }

    
    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);
    tRotomUpdateMessage = RP_MESSAGE_TIME;
}

static void RotomPhone_OverworldMenu_PrintHintPrompt(u8 taskId)
{
    u8 textBuffer[80];
    static const u8 sRotomMenuRButtonIcon[] = {CHAR_KEYPAD_ICON, CHAR_R_BUTTON_ROTOM_MENU, EOS};

    StringCopy(textBuffer, COMPOUND_STRING("Feeling lost? Press "));
    StringAppend(textBuffer, sRotomMenuRButtonIcon);
    StringAppend(textBuffer, COMPOUND_STRING(" for a tip!"));
    RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, TRUE, TRUE);
    tRotomUpdateMessage = RP_MESSAGE_TIME;
}

static void RotomPhone_OverworldMenu_PrintHint(u8 taskId)
{
    u8 textBufferTop[80];
    u8 textBufferBottom[80];
    u16 ikiTownState;

    if (!RP_CONFIG_ROTOM_ACTIVE)
        return;

    ikiTownState = VarGet(VAR_IKITOWN_STATE);
    StringCopy(textBufferBottom, COMPOUND_STRING(""));

    if (GetSafariZoneFlag())
    {
        StringCopy(textBufferTop, COMPOUND_STRING("Focus on the Safari hunt"));
        StringCopy(textBufferBottom, COMPOUND_STRING("for now."));
    }
    else if (ikiTownState == 19)
    {
        StringCopy(textBufferTop, COMPOUND_STRING("Head to the Trainer's School."));
        StringCopy(textBufferBottom, COMPOUND_STRING("It's just west of your house!"));
    }
    else if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        StringCopy(textBufferTop, COMPOUND_STRING("Keep following Kukui."));
        StringCopy(textBufferBottom, COMPOUND_STRING("You are still early in the journey."));
    }
    else if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        StringCopy(textBufferTop, COMPOUND_STRING("Anywhere sounds good now."));
        StringCopy(textBufferBottom, COMPOUND_STRING("Pick a goal and chase it!"));
    }
    else
    {
        StringCopy(textBufferTop, COMPOUND_STRING("I don't have any tips right now."));
        StringCopy(textBufferBottom, COMPOUND_STRING("Continue exploring Alola!"));
    }

    RotomPhone_OverworldMenu_PrintRotomSpeech(textBufferTop, TRUE, FALSE);
    RotomPhone_OverworldMenu_PrintRotomSpeech(textBufferBottom, FALSE, FALSE);
    CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId, COPYWIN_GFX);
    CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId, COPYWIN_GFX);
    tRotomHintActive = TRUE;
    tRotomUpdateTimer = ROTOM_PHONE_OW_MESSGAGE_TIMER;
    tRotomMessageSoundEffect = SE_SELECT;
    RotomPhone_StartMenu_UpdateRotomFaceAnim(TRUE);
}

static void RotomPhone_OverworldMenu_UpdateMenuPrompt(u8 taskId)
{
    u8 fontId;
    if (sRotomPhone_StartMenuFromScript && sRotomPhone_StartMenuScriptPrompt != NULL)
    {
        const u8 *src = sRotomPhone_StartMenuScriptPrompt;
        u8 textBufferTop[80];
        u8 textBufferBottom[80];
        u8 i = 0;
        u8 j = 0;
        bool32 hasTopWindow = (sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId != WINDOW_NONE);
        bool32 hasBottomWindow = (sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId != WINDOW_NONE);

        while (src[i] != EOS && src[i] != CHAR_NEWLINE && i < sizeof(textBufferTop) - 1)
        {
            textBufferTop[i] = src[i];
            i++;
        }
        textBufferTop[i] = EOS;

        if (src[i] == CHAR_NEWLINE)
        {
            src = src + i + 1;
            while (src[j] != EOS && src[j] != CHAR_NEWLINE && j < sizeof(textBufferBottom) - 1)
            {
                textBufferBottom[j] = src[j];
                j++;
            }
            textBufferBottom[j] = EOS;

            if (hasTopWindow)
            {
                RotomPhone_OverworldMenu_PrintRotomSpeech(textBufferTop, TRUE, FALSE);
                CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId, COPYWIN_GFX);
            }

            if (hasBottomWindow)
            {
                RotomPhone_OverworldMenu_PrintRotomSpeech(textBufferBottom, FALSE, FALSE);
                CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId, COPYWIN_GFX);
            }
        }
        else
        {
            u8 textBufferTopDefault[80];

            if (sRotomPhoneOptions[menuSelectedOverworld].rotomSpeech == NULL)
            {
                StringCopy(textBufferTopDefault, COMPOUND_STRING("Invalid Option"));
            }
            else
            {
                if (Random() % 2 == TRUE)
                    StringCopy(textBufferTopDefault, COMPOUND_STRING("Would you like "));
                else
                    StringCopy(textBufferTopDefault, COMPOUND_STRING("Do you want "));

                if (menuSelectedOverworld == RP_MENU_SHORTCUT)
                    StringAppend(textBufferTopDefault, sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_OW].rotomSpeech);
                else
                    StringAppend(textBufferTopDefault, sRotomPhoneOptions[menuSelectedOverworld].rotomSpeech);
            }

            if (hasTopWindow)
            {
                RotomPhone_OverworldMenu_PrintRotomSpeech(textBufferTopDefault, TRUE, FALSE);
                CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId, COPYWIN_GFX);
            }

            if (hasBottomWindow)
            {
                RotomPhone_OverworldMenu_PrintRotomSpeech(textBufferTop, FALSE, FALSE);
                CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId, COPYWIN_GFX);
            }
        }
        return;
    }

    if (RP_CONFIG_ROTOM_ACTIVE)
    {
        u8 textBuffer[80];

        if (sRotomPhoneOptions[menuSelectedOverworld].rotomSpeech == NULL)
        {
            StringCopy(textBuffer, COMPOUND_STRING("Invalid Option"));
            RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, FALSE, TRUE);
            return;
        }

        if (Random() % 2 == TRUE)
            StringCopy(textBuffer, COMPOUND_STRING("Would you like "));
        else
            StringCopy(textBuffer, COMPOUND_STRING("Do you want "));
        
        if (menuSelectedOverworld == RP_MENU_SHORTCUT)
            StringAppend(textBuffer, sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_OW].rotomSpeech);
        else
            StringAppend(textBuffer, sRotomPhoneOptions[menuSelectedOverworld].rotomSpeech);
        RotomPhone_OverworldMenu_PrintRotomSpeech(textBuffer, FALSE, TRUE);
    }
    else if (!RP_CONFIG_USE_ROTOM_PHONE)
    {
        u8 menuName[24];
        StringCopy(menuName, sRotomPhoneOptions[menuSelectedOverworld].menuName);
        if (!StringCompare(menuName, sRotomPhoneOptions[RP_MENU_SHORTCUT].menuName))
            StringCopy(menuName, sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_OW].menuName);

        fontId = GetFontIdToFit(menuName, FONT_SHORT, 0, sWindowTemplate_FlipPhone.width * 8);
        FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, PIXEL_FILL(OW_FLIP_PHONE_TEXT_BG_COLOUR));
        AddTextPrinterParameterized4(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, fontId,
        GetStringCenterAlignXOffset(fontId, menuName, sWindowTemplate_FlipPhone.width * 8),
        ROTOM_SPEECH_BOTTOM_ROW_Y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_OW_FLIP_PHONE], TEXT_SKIP_DRAW, menuName);
        CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, COPYWIN_GFX);
        tRotomMessageSoundEffect = SE_BALL_TRAY_EXIT;
    }
}

static void RotomPhone_OverworldMenu_RemoveWindows(void)
{
    if (sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId);
        CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId, COPYWIN_GFX);
        RemoveWindow(sRotomPhone_StartMenu->menuOverworldRotomSpeechBottomWindowId);
    }

    if (sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId);
        CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId, COPYWIN_GFX);
        RemoveWindow(sRotomPhone_StartMenu->menuOverworldRotomSpeechTopWindowId);
    }

    if (sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId);
        CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, COPYWIN_GFX);
        RemoveWindow(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId);
    }
}

static void RotomPhone_OverworldMenu_DestroySprites(void)
{
    if (sRotomPhone_StartMenu->menuRotomFaceSpriteId != SPRITE_NONE)
    {
        FreeSpriteOamMatrix(&gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId]);
        DestroySprite(&gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId]);
    }
    if (sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId != SPRITE_NONE)
    {
        FreeSpriteOamMatrix(&gSprites[sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId]);
        DestroySprite(&gSprites[sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId]);
    }
    for (enum RotomPhone_Overworld_Options spriteId = RP_OW_OPTION_1; spriteId < RP_OW_OPTION_COUNT; spriteId++)
    {
        if (sRotomPhone_StartMenu->menuOverworldIconSpriteId[spriteId] != SPRITE_NONE)
        {
            FreeSpriteOamMatrix(&gSprites[sRotomPhone_StartMenu->menuOverworldIconSpriteId[spriteId]]);
            DestroySprite(&gSprites[sRotomPhone_StartMenu->menuOverworldIconSpriteId[spriteId]]);
        }
        if (sRotomPhone_StartMenu->menuOverworldIconFlashSpriteId[spriteId] != SPRITE_NONE)
        {
            FreeSpriteOamMatrix(&gSprites[sRotomPhone_StartMenu->menuOverworldIconFlashSpriteId[spriteId]]);
            DestroySprite(&gSprites[sRotomPhone_StartMenu->menuOverworldIconFlashSpriteId[spriteId]]);
        }
    }
}

static void RotomPhone_OverworldMenu_ExitAndClearTilemap(void)
{
    u32 i;
    u8 *buf = GetBgTilemapBuffer(0);

    RotomPhone_OverworldMenu_RemoveWindows();

    for (i=0; i<2048; i++)
    {
        buf[i] = 0;
    }
    ScheduleBgCopyTilemapToVram(0);

    RotomPhone_OverworldMenu_DestroySprites();

    if (sRotomPhone_StartMenu != NULL)
    {
        FreeSpriteTilesByTag(TAG_PHONE_OW_ICON_GFX); 
        FreeSpriteTilesByTag(TAG_ROTOM_FACE_GFX);  
        Free(sRotomPhone_StartMenu);
        sRotomPhone_StartMenu = NULL;
    }

    ReleaseComfyAnims();
    ScriptUnfreezeObjectEvents();  
    UnlockPlayerFieldControls();
}

static void RotomPhone_StartMenu_DoCleanUpAndChangeCallback(MainCallback callback)
{
    if (!gPaletteFade.active)
    {
        if (!RotomPhone_StartMenu_IsRotomReality())
            RotomPhone_StartMenu_DoCleanUpAndDestroyTask(FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_HandleMainInput), TRUE);
        else
            RotomPhone_StartMenu_DoCleanUpAndDestroyTask(FindTaskIdByFunc(Task_RotomPhone_RotomRealityMenu_WaitFadeForSelection), FALSE);
        
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;
        SetMainCallback2(callback);
    }
}

static u8 RotomPhone_StartMenu_DoCleanUpAndCreateTask(TaskFunc func, u8 priority)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        PlayRainStoppingSoundEffect();
        RotomPhone_OverworldMenu_ExitAndClearTilemap();
        CleanupOverworldWindowsAndTilemaps();
    }
    else
    {
        RotomPhone_RotomRealityMenu_SaveScreen_FreeResources();
    }
    return CreateTask(func, priority);
}

static void RotomPhone_StartMenu_DoCleanUpAndChangeTaskFunc(u8 taskId, TaskFunc func)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        PlayRainStoppingSoundEffect();
        RotomPhone_OverworldMenu_ExitAndClearTilemap();
        CleanupOverworldWindowsAndTilemaps();
    }
    else
    {
        RotomPhone_RotomRealityMenu_SaveScreen_FreeResources();
    }
    gTasks[taskId].func = func;
}

static void RotomPhone_StartMenu_DoCleanUpAndDestroyTask(u8 taskId, bool32 overworldCleanup)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        PlayRainStoppingSoundEffect();
        RotomPhone_OverworldMenu_ExitAndClearTilemap();

        if (overworldCleanup)
            CleanupOverworldWindowsAndTilemaps();
    }
    else
    {
        RotomPhone_RotomRealityMenu_SaveScreen_FreeResources();
    }
    if (taskId != TASK_NONE) DestroyTask(taskId);
}

static void Task_RotomPhone_StartMenu_WaitSaveGame(u8 taskId)
{
    if (!FuncIsActiveTask(SaveGameTask) && !RotomPhone_StartMenu_IsRotomReality())
    { 
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        SoftResetInBattlePyramid();
        if (taskId != TASK_NONE) DestroyTask(taskId);
    }
    else if (!FuncIsActiveTask(SaveGameTask) && RotomPhone_StartMenu_IsRotomReality())
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_RotomPhone_SaveScreen_WaitFadeAndExit;
    }   
}

static void RotomPhone_OverworldMenu_HandleDPAD(u8 taskId)
{
    enum RotomPhone_Overworld_Options optionCurrent = RP_OW_OPTION_1;
    s32 offset;
    u32 nextIndex;

    for (enum RotomPhone_Overworld_Options i = RP_OW_OPTION_1; i < RP_OW_OPTION_COUNT; i++)
    {
        if (sRotomPhone_StartMenu->menuOverworldOptions[i] == menuSelectedOverworld)
        {
            optionCurrent = i;
            break;
        }
    }

    if (JOY_NEW(DPAD_UP))
        offset = -2;
    else if (JOY_NEW(DPAD_LEFT))
        offset = (optionCurrent % 2 == 1) ? -1 : RP_OW_OPTION_COUNT;
    else  if (JOY_NEW(DPAD_RIGHT))
        offset = (optionCurrent % 2 == 0) ? 1 : RP_OW_OPTION_COUNT;
    else
        offset = 2;

    nextIndex = optionCurrent + offset;
    if (nextIndex >= RP_OW_OPTION_COUNT
        || nextIndex < RP_OW_OPTION_1
        || sRotomPhone_StartMenu->menuOverworldOptions[nextIndex] == RP_MENU_COUNT)
    {
        if (RP_CONFIG_USE_ROTOM_PHONE)
            tRotomMessageSoundEffect = SE_BOO;
        else
            tRotomMessageSoundEffect = SE_CLICK;
        return;
    }

    if (menuSelectedOverworld != sRotomPhone_StartMenu->menuOverworldOptions[nextIndex]
        && sRotomPhone_StartMenu->menuOverworldLoading == FALSE && !gPaletteFade.active)
        RotomPhone_OverworldMenu_LoadIconSpritePalette(FALSE);

    if (tRotomHintActive)
    {
        tRotomUpdateTimer = FALSE;
        RotomPhone_OverworldMenu_CheckUpdateMessage(taskId);
    }
    
    gComfyAnims[tPhoneHighlightComfyAnimId].config.data.spring.to = Q_24_8(FADE_COLOUR_MAX);
    gComfyAnims[tPhoneHighlightComfyAnimId].position = 0;
    menuSelectedOverworld = sRotomPhone_StartMenu->menuOverworldOptions[nextIndex];
    if (RP_CONFIG_USE_ROTOM_PHONE)
        tRotomMessageSoundEffect = SE_SELECT;
    else
        tRotomMessageSoundEffect = SE_CLICK;

    RotomPhone_StartMenu_UpdateRotomFaceAnim(TRUE);
    RotomPhone_OverworldMenu_UpdateMenuPrompt(taskId);
}

static void Task_RotomPhone_OverworldMenu_PhoneSlideOpen(u8 taskId)
{
    TryAdvanceComfyAnim(&gComfyAnims[tPhoneComfyAnimId]);
    if (tPhoneY == PHONE_OFFSCREEN_Y)
    {
        struct ComfyAnimEasingConfig config;
        InitComfyAnimConfig_Easing(&config);
        config.durationFrames = PHONE_COMFY_SLIDE_DURATION;
        config.from = Q_24_8(PHONE_OFFSCREEN_Y);
        config.to = Q_24_8(0);
        config.easingFunc = ComfyAnimEasing_EaseOutQuad;
        tPhoneComfyAnimId = CreateComfyAnim_Easing(&config);
        TryAdvanceComfyAnim(&gComfyAnims[tPhoneComfyAnimId]);

        tPhoneY = ReadComfyAnimValueSmooth(&gComfyAnims[tPhoneComfyAnimId]);
    }
    else if (GetEasingComfyAnim_CurrentFrame(&gComfyAnims[tPhoneComfyAnimId]) == PHONE_COMFY_SLIDE_DURATION / 2
        && !RP_CONFIG_USE_ROTOM_PHONE)
    {
        DecompressDataWithHeaderVram(sFlipPhone_OverworldOpenTilemap, GetBgTilemapBuffer(0));
        ScheduleBgCopyTilemapToVram(0);
    }
    else if (tPhoneY > 0)
    {
        tPhoneY = ReadComfyAnimValueSmooth(&gComfyAnims[tPhoneComfyAnimId]);
        SetGpuReg(REG_OFFSET_BG0VOFS, -tPhoneY);
    }
    else
    {
        ReleaseComfyAnim(tPhoneComfyAnimId);
        if (RP_CONFIG_ROTOM_ACTIVE)
            RotomPhone_StartMenu_CreateRotomFaceSprite(TRUE);
        else
            RotomPhone_OverworldMenu_ContinueInit(TRUE);
    }
}

static void Task_RotomPhone_OverworldMenu_PhoneSlideClose(u8 taskId)
{
    TryAdvanceComfyAnim(&gComfyAnims[tPhoneComfyAnimId]);
    if (tPhoneY == FALSE)
    {
        struct ComfyAnimEasingConfig config;
        InitComfyAnimConfig_Easing(&config);
        config.durationFrames = PHONE_COMFY_SLIDE_DURATION;
        config.from = Q_24_8(0);
        config.to = Q_24_8(PHONE_OFFSCREEN_Y);
        config.easingFunc = ComfyAnimEasing_EaseOutQuad;
        tPhoneComfyAnimId = CreateComfyAnim_Easing(&config);
        TryAdvanceComfyAnim(&gComfyAnims[tPhoneComfyAnimId]);

        RotomPhone_OverworldMenu_RemoveWindows();
        RotomPhone_OverworldMenu_DestroySprites();
        if (RP_CONFIG_USE_ROTOM_PHONE)
            DecompressDataWithHeaderVram(sRotomPhone_OverworldTilemap, GetBgTilemapBuffer(0));
        else
            DecompressDataWithHeaderVram(sFlipPhone_OverworldClosedTilemap, GetBgTilemapBuffer(0));
        ScheduleBgCopyTilemapToVram(0);
        tPhoneY = ReadComfyAnimValueSmooth(&gComfyAnims[tPhoneComfyAnimId]);
        SetGpuReg(REG_OFFSET_BG0VOFS, -tPhoneY);
    }
    else if (tPhoneY < PHONE_OFFSCREEN_Y)
    {
        tPhoneY = ReadComfyAnimValueSmooth(&gComfyAnims[tPhoneComfyAnimId]);
        SetGpuReg(REG_OFFSET_BG0VOFS, -tPhoneY);
    }
    else if (tPhoneY == PHONE_OFFSCREEN_Y)
    {
        tPhoneY++;
        RotomPhone_OverworldMenu_ExitAndClearTilemap();
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        ReleaseComfyAnim(tPhoneComfyAnimId);
        if (sRotomPhone_StartMenuFromScript)
            RotomPhone_StartMenu_ClearScriptState();
        if (taskId != TASK_NONE) DestroyTask(taskId);
    }
}

static void RotomPhone_OverworldMenu_UpdateIconPaletteFade(u8 taskId)
{
    if (gPaletteFade.active)
        return;
    
    u32 iconPal = sRotomPhoneOptions[menuSelectedOverworld].owIconPalSlot;

    if (menuSelectedOverworld == RP_MENU_SHORTCUT)
        iconPal = sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_OW].owIconPalSlot;

    // Flip-phone mode uses monochrome icon palettes, so keep the clock highlight consistent there.
    if (!RP_CONFIG_USE_ROTOM_PHONE && menuSelectedOverworld == RP_MENU_CLOCK)
        iconPal = PAL_ICON_MONOCHROME;
    
    TryAdvanceComfyAnim(&gComfyAnims[tPhoneHighlightComfyAnimId]);
    u32 frameNum = ReadComfyAnimValueSmooth(&gComfyAnims[tPhoneHighlightComfyAnimId]);
    RotomPhone_StartMenu_UpdateSpriteFadeColours(
        // Uses first option as all sprites will use the same palette
        &gSprites[sRotomPhone_StartMenu->menuOverworldIconSpriteId[RP_MENU_FIRST_OPTION]],
        iconPal, 
        frameNum
    );

    if (frameNum == FADE_COLOUR_MAX)
        gComfyAnims[tPhoneHighlightComfyAnimId].config.data.spring.to = Q_24_8(FADE_COLOUR_MIN);
    else if (frameNum == FADE_COLOUR_MIN)
        gComfyAnims[tPhoneHighlightComfyAnimId].config.data.spring.to = Q_24_8(FADE_COLOUR_MAX);
}

static void Task_RotomPhone_OverworldMenu_HandleMainInput(u8 taskId)
{
    tRotomMessageSoundEffect = MUS_DUMMY;
    RotomPhone_OverworldMenu_CheckUpdateMessage(taskId);
    RotomPhone_OverworldMenu_UpdateIconPaletteFade(taskId);

    if (sRotomPhone_StartMenuFromScript)
    {
        if (JOY_NEW(A_BUTTON | B_BUTTON) && sRotomPhone_StartMenu->menuOverworldLoading == FALSE)
        {
            if (RP_CONFIG_ROTOM_ACTIVE)
            {
                gTasks[taskId].func = Task_RotomPhone_OverworldMenu_RotomShutdown;
                RotomPhone_StartMenu_RotomShutdownPreparation(taskId, TRUE);
            }
            else
            {
                PlaySE(SE_BALL_TRAY_ENTER);
                tPhoneY = FALSE;
                gTasks[taskId].func = Task_RotomPhone_OverworldMenu_PhoneSlideClose;
            }
        }

        if (tRotomMessageSoundEffect && !IsSEPlaying())
            PlaySE(tRotomMessageSoundEffect);
        return;
    }

    if (tRotomUpdateTimer && sRotomPhone_StartMenu->menuOverworldLoading == FALSE && !gPaletteFade.active)
        tRotomUpdateTimer--;
    
    if (JOY_NEW(A_BUTTON))
    {
        if (sRotomPhone_StartMenu->menuOverworldLoading == FALSE)
        {
            if (menuSelectedOverworld == RP_MENU_ROTOM_REALITY)
                FadeScreen(FADE_TO_WHITE, 0);
            else if (menuSelectedOverworld != RP_MENU_SAVE && menuSelectedOverworld != RP_MENU_FLAG && menuSelectedOverworld != RP_MENU_CLOCK)
                FadeScreen(FADE_TO_BLACK, 0);
            
            PlaySE(SE_BALL_TRAY_ENTER);
            sRotomPhone_StartMenu->menuOverworldLoading = TRUE;
        }
    }
    else if (JOY_NEW(B_BUTTON) && sRotomPhone_StartMenu->menuOverworldLoading == FALSE)
    {
        if (RP_CONFIG_ROTOM_ACTIVE)
        {
            gTasks[taskId].func = Task_RotomPhone_OverworldMenu_RotomShutdown;
            RotomPhone_StartMenu_RotomShutdownPreparation(taskId, TRUE);
        }
        else
        {
            PlaySE(SE_BALL_TRAY_ENTER);
            tPhoneY = FALSE;
            gTasks[taskId].func = Task_RotomPhone_OverworldMenu_PhoneSlideClose;
        }
        return;
    }
    else if (JOY_NEW(R_BUTTON) && sRotomPhone_StartMenu->menuOverworldLoading == FALSE && RP_CONFIG_ROTOM_ACTIVE)
    {
        RotomPhone_OverworldMenu_PrintHint(taskId);
    }
    else if (gMain.newKeys & DPAD_ANY && sRotomPhone_StartMenu->menuOverworldLoading == FALSE)
    {
        RotomPhone_OverworldMenu_HandleDPAD(taskId);
    }
    else if (sRotomPhone_StartMenu->menuOverworldLoading == TRUE && sRotomPhoneOptions[menuSelectedOverworld].selectedFunc)
    {
        sRotomPhoneOptions[menuSelectedOverworld].selectedFunc();
    }

    if (tRotomMessageSoundEffect && !IsSEPlaying())
        PlaySE(tRotomMessageSoundEffect);
}

static void RotomPhone_StartMenu_RotomShutdownPreparation(u8 taskId, bool32 overworld)
{
    PlaySE(SE_PC_OFF);
    tRotomUpdateMessage = RP_MESSAGE_GOODBYE;
    tRotomUpdateTimer = FALSE;

    if (overworld)
        RotomPhone_OverworldMenu_CheckUpdateMessage(taskId);
    
    struct Sprite *sprite = &gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId];
    sprite->callback = SpriteCB_RotomPhone_OverworldMenu_RotomFace_Unload;

    enum RotomPhone_FaceExpressions rotomFace;
    if (sRotomPhone_StartMenu->rotomFaceLastLoaded >= RP_FACE_HAPPY_WITH)
        rotomFace = RP_FACE_HAPPY_WITH;
    else
        rotomFace = RP_FACE_HAPPY;
    
    StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId], rotomFace);
    if (sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId != SPRITE_NONE)
        StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId], rotomFace);
    
    struct ComfyAnimSpringConfig config;
    InitComfyAnimConfig_Spring(&config);
    config.from = Q_24_8(FADE_COLOUR_MID);
    config.to = Q_24_8(FADE_COLOUR_MAX);
    config.mass = Q_24_8(FACE_ICON_COMFY_SPRING_MASS);
    config.tension = Q_24_8(FACE_ICON_COMFY_SPRING_TENSION);
    config.friction = Q_24_8(FACE_ICON_COMFY_SPRING_FRICTION);
    config.clampAfter = FACE_ICON_COMFY_SPRING_CLAMP_AFTER;
    sFrameNumComfyAnimId = CreateComfyAnim_Spring(&config);
}

static void Task_RotomPhone_OverworldMenu_RotomShutdown(u8 taskId)
{
    if (gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].callback == SpriteCallbackDummy)
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        gTasks[taskId].func = Task_RotomPhone_OverworldMenu_PhoneSlideClose;
    }
}

static void Task_RotomPhone_OverworldMenu_CloseAndSave(u8 taskId)
{
    TaskFunc func;
    if (RP_CONFIG_ROTOM_ACTIVE)
        func = Task_RotomPhone_OverworldMenu_RotomShutdown;
    else
        func = Task_RotomPhone_OverworldMenu_PhoneSlideClose;

    if (!FuncIsActiveTask(Task_RotomPhone_OverworldMenu_RotomShutdown)
        && !FuncIsActiveTask(Task_RotomPhone_OverworldMenu_PhoneSlideClose)
        && tPhoneCloseParameterSaveSafariFade == FALSE)
    {
        CreateTask(func, 0);
        tPhoneCloseParameterSaveSafariFade = TRUE;
    }
    else if (!FuncIsActiveTask(Task_RotomPhone_OverworldMenu_RotomShutdown)
        && !FuncIsActiveTask(Task_RotomPhone_OverworldMenu_PhoneSlideClose)
        && tPhoneCloseParameterSaveSafariFade == TRUE)
    {
        LockPlayerFieldControls();
        LoadMessageBoxAndBorderGfx();
        SaveGame();
        gTasks[taskId].func = Task_RotomPhone_StartMenu_WaitSaveGame;
    }
}

static void Task_RotomPhone_OverworldMenu_CloseForSafari(u8 taskId)
{
    if (!FuncIsActiveTask(Task_RotomPhone_OverworldMenu_PhoneSlideClose)
        && tPhoneCloseParameterSaveSafariFade == FALSE)
    {
        CreateTask(Task_RotomPhone_OverworldMenu_PhoneSlideClose, 0);
        tPhoneCloseParameterSaveSafariFade = TRUE;
    }
    else if (!FuncIsActiveTask(Task_RotomPhone_OverworldMenu_PhoneSlideClose)
        && tPhoneCloseParameterSaveSafariFade == TRUE)
    {
        if (taskId != TASK_NONE) DestroyTask(taskId);
        SafariZoneRetirePrompt();
    }
}


// Rotom Phone Rotom Reality Menu
static void Task_RotomPhone_RotomRealityMenu_Open(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        RotomPhone_RotomRealityMenu_Init();
        if (taskId != TASK_NONE) DestroyTask(taskId);
    }
}

static void RotomPhone_RotomRealityMenu_Init(void)
{
    sRotomPhone_StartMenu = AllocZeroed(sizeof(struct RotomPhone_StartMenu_State));
    if (sRotomPhone_StartMenu == NULL)
    {
        sRotomPhone_RotomReality = FALSE;
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        return;
    }

    sRotomPhone_StartMenu->menuRotomRealityLoadState = 0;

    SetMainCallback2(RotomPhone_RotomRealityMenu_SetupCB);
}

static void RotomPhone_RotomRealityMenu_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        RotomPhone_RotomRealityMenu_SaveScreen_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (RotomPhone_RotomRealityMenu_InitBgs())
        {
            sRotomPhone_StartMenu->menuRotomRealityLoadState = 0;
            gMain.state++;
        }
        else
        {
            RotomPhone_RotomRealityMenu_FadeAndBail();
            return;
        }
        break;
    case 3:
        if (RotomPhone_RotomRealityMenu_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 4:
        RotomPhone_RotomRealityMenu_InitWindows();
        gMain.state++;
        break;
    case 5:
        sRotomPhone_StartMenu->menuRotomRealityPanelY = 0;
        sRotomPhone_StartMenu->menuRotomRealityPanelOpen = FALSE;
        for (enum RotomPhone_RotomReality_Options rotomRealityOptions = RP_OW_OPTION_1; rotomRealityOptions < RP_RR_OPTION_COUNT; rotomRealityOptions++)
        {
            sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[rotomRealityOptions] = SPRITE_NONE;
        }
        sRotomPhone_StartMenu->menuRotomFaceSpriteId = SPRITE_NONE;
        sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId = SPRITE_NONE;

        for (enum RotomPhone_RotomReality_SlidingPanelSprites spritePanel = RP_RR_PANEL_SPRITE_ONE; spritePanel < RP_RR_PANEL_SPRITE_COUNT; spritePanel++)
        {
            sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel] = SPRITE_NONE;
        }

        for (enum RotomPhone_RotomReality_SlidingPanelWindows windowPanel = RP_RR_PANEL_WIN_ONE; windowPanel < RP_RR_PANEL_WIN_COUNT; windowPanel++)
        {
            sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[windowPanel] = WINDOW_NONE;
        }

        CreateTask(Task_RotomPhone_RotomRealityMenu_WaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        if (!RotomPhone_StartMenu_IsRotomReality())
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);
        else
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        sRotomPhone_RotomReality = TRUE;
        if (!sRotomPhoneOptions[menuSelectedRotomReality].unlockedFunc || !sRotomPhoneOptions[menuSelectedRotomReality].unlockedFunc())
            menuSelectedRotomReality = RotomPhone_StartMenu_SetFirstSelectedMenu();

        sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption = RotomPhone_StartMenu_SetFirstSelectedMenu();

        RotomPhone_RotomRealityMenu_PrintTime();
        RotomPhone_RotomRealityMenu_PrintMenuName();
        RotomPhone_RotomRealityMenu_LoadSprites();
        RotomPhone_StartMenu_CreateRotomFaceSprite(FALSE);
        RotomPhone_RotomRealityMenu_CreateIconSprites();
        RotomPhone_RotomRealityMenu_CreateShortcutIcon();
        RotomPhone_RotomRealityMenu_CreateCursorSprite();
        gMain.state++;
        break;
    case 8:
        SetVBlankCallback(RotomPhone_RotomRealityMenu_SaveScreen_VBlankCB);
        SetMainCallback2(RotomPhone_RotomRealityMenu_SaveScreen_MainCB);
        break;
    }
}

static void Task_RotomPhone_RotomRealityMenu_WaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_HandleMainInput;
    }
}

static enum RotomPhone_MenuItems RotomPhone_RotomRealityMenu_GetNextUnlockedOffset(u32 startIndex, s32 direction)
{
    u32 unlockedCount = 0;
    u32 i = startIndex;

    while (i < RP_MENU_COUNT && i >= 0)
    {
        if (sRotomPhoneOptions[i].unlockedFunc && sRotomPhoneOptions[i].unlockedFunc())
        {
            unlockedCount++;
            if (unlockedCount == RP_RR_OPTION_COUNT)
                break;
        }
        i += direction;
    }
    return i;
}

static bool32 RotomPhone_RotomRealityMenu_CanScrollRight(void)
{
    u32 unlockedSeen = 0;
    for (u32 i = sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption; i < RP_MENU_COUNT; i++)
    {
        if (sRotomPhoneOptions[i].unlockedFunc && sRotomPhoneOptions[i].unlockedFunc())
        {
            unlockedSeen++;
            if (unlockedSeen > RP_RR_OPTION_COUNT)
                return TRUE;
        }
    }
    return FALSE;
}

static void RotomPhone_RotomRealityMenu_HandleScroll(u8 taskId, bool32 scrollRight)
{
    tRotomMessageSoundEffect = SE_PC_ON;
    for (enum RotomPhone_RotomReality_Options spriteId = RP_RR_OPTION_1; spriteId < RP_RR_OPTION_COUNT; spriteId++)
    {
        if (sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[spriteId] != SPRITE_NONE)
        {
            FreeSpriteOamMatrix(&gSprites[sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[spriteId]]);
            DestroySprite(&gSprites[sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[spriteId]]);
            sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[spriteId] = SPRITE_NONE;
        }
    }

    if (scrollRight)
    {
        sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption = RotomPhone_RotomRealityMenu_GetNextUnlockedOffset(
            sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption + 1, +1);
    }
    else
    {
        sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption = RotomPhone_RotomRealityMenu_GetNextUnlockedOffset(
            sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption - 1, -1);
    }

    RotomPhone_RotomRealityMenu_CreateIconSprites();
}


static void RotomPhone_RotomRealityMenu_HandleDPAD(u8 taskId)
{
    enum RotomPhone_RotomReality_Options optionCurrent = RP_RR_OPTION_1;
    enum RotomPhone_RotomReality_Options optionNew;

    for (enum RotomPhone_RotomReality_Options i = RP_RR_OPTION_1; i < RP_RR_OPTION_COUNT; i++)
    {
        if (sRotomPhone_StartMenu->menuRotomRealityOptions[i] == menuSelectedRotomReality)
        {
            optionCurrent = i;
            break;
        }
    }

    if (JOY_NEW(DPAD_UP))
        optionNew = sRotomRealityOptionInfo[optionCurrent].optionUp;
    else if (JOY_NEW(DPAD_LEFT))
        optionNew = sRotomRealityOptionInfo[optionCurrent].optionLeft;
    else  if (JOY_NEW(DPAD_RIGHT))
        optionNew = sRotomRealityOptionInfo[optionCurrent].optionRight;
    else
        optionNew = sRotomRealityOptionInfo[optionCurrent].optionDown;
    
    tRotomMessageSoundEffect = SE_SELECT;

    if (sRotomPhone_StartMenu->menuRotomRealityOptions[optionNew] == RP_MENU_COUNT)
    {
        tRotomMessageSoundEffect = SE_BOO;
        return;
    }

    if (optionNew == RP_RR_OPTION_COUNT)
    {
        if (JOY_NEW(DPAD_UP | DPAD_DOWN))
        {
            tRotomMessageSoundEffect = SE_BOO;
            return;
        }

        if (JOY_NEW(DPAD_LEFT))
        {
            if (sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption == RotomPhone_StartMenu_SetFirstSelectedMenu())
            {
                tRotomMessageSoundEffect = SE_BOO;
                return;
            }
            else
            {
                RotomPhone_RotomRealityMenu_HandleScroll(taskId, FALSE);
            }
        }

        if (JOY_NEW(DPAD_RIGHT))
        {
            if (!RotomPhone_RotomRealityMenu_CanScrollRight())
            {
                tRotomMessageSoundEffect = SE_BOO;
                return;
            }
            else
            {
                RotomPhone_RotomRealityMenu_HandleScroll(taskId, TRUE);
            }
        }
    }

    menuSelectedRotomReality = sRotomPhone_StartMenu->menuRotomRealityOptions[optionNew];
    RotomPhone_StartMenu_UpdateRotomFaceAnim(TRUE);
    RotomPhone_RotomRealityMenu_PrintMenuName();
}

static void Task_RotomPhone_RotomRealityMenu_HandleMainInput(u8 taskId)
{
    tRotomMessageSoundEffect = MUS_DUMMY;
    RotomPhone_RotomRealityMenu_TimerUpdates(taskId);
    
    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_WaitFadeAndExitGracefully;
        RotomPhone_StartMenu_RotomShutdownPreparation(taskId, FALSE);
        tPhoneCloseParameterSaveSafariFade = FALSE;
    }
    if (JOY_NEW(DPAD_ANY))
    {
        RotomPhone_RotomRealityMenu_HandleDPAD(taskId);
    }
    if (JOY_NEW(A_BUTTON | START_BUTTON))
    {
        if (JOY_NEW(START_BUTTON) && RP_CONFIG_ROTOM_REALITY_SHORTCUT)
        {
            menuSelectedRotomReality = RP_GET_SHORTCUT_OPTION_RR;
            RotomPhone_RotomRealityMenu_PrintMenuName();
        }
        else if (JOY_NEW(START_BUTTON) && !RP_CONFIG_ROTOM_REALITY_SHORTCUT)
        {
            return;
        }
        
        if (menuSelectedRotomReality != RP_MENU_SAVE)
        {
            PlaySE(SE_BALL_TRAY_ENTER);

            if (!sRotomPhoneOptions[menuSelectedRotomReality].rotomRealityPanel)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_WaitFadeForSelection;
            }
            else if (sRotomPhoneOptions[menuSelectedRotomReality].selectedFunc)
            {
                RotomPhone_RotomRealityMenu_StartPanelSlide();
                sRotomPhoneOptions[menuSelectedRotomReality].selectedFunc();
            }
        }
        else
        {
            sRotomPhoneOptions[menuSelectedRotomReality].selectedFunc();
        }
    }

    if (tRotomMessageSoundEffect && !IsSEPlaying())
        PlaySE(tRotomMessageSoundEffect);
}

static void Task_RotomPhone_RotomRealityMenu_PanelInput(u8 taskId)
{
    tRotomMessageSoundEffect = MUS_DUMMY;
    RotomPhone_RotomRealityMenu_TimerUpdates(taskId);

    if (JOY_NEW(START_BUTTON | A_BUTTON | B_BUTTON))
    {
        gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_PanelSlide;
        tRotomPanelComfyAnimId = INVALID_COMFY_ANIM;
        PlaySE(SE_DEX_PAGE);
    }

    if (tRotomMessageSoundEffect && !IsSEPlaying())
        PlaySE(tRotomMessageSoundEffect);
}

static void Task_RotomPhone_RotomRealityMenu_PanelSlide(u8 taskId)
{
    tRotomMessageSoundEffect = MUS_DUMMY;
    RotomPhone_RotomRealityMenu_TimerUpdates(taskId);

    #define PANEL_MIN_Y 0
    #define PANEL_MAX_Y 96
    #define PANEL_SLIDE_DOWN_FRAMES 50
    #define PANEL_SLIDE_UP_FRAMES 40
    
    SetGpuReg(REG_OFFSET_BG2VOFS, sRotomPhone_StartMenu->menuRotomRealityPanelY);

    if (sRotomPhone_StartMenu->menuRotomRealityPanelOpen)
    {
        if (sRotomPhone_StartMenu->menuRotomRealityPanelY > PANEL_MIN_Y)
        {
            if (tRotomPanelComfyAnimId == INVALID_COMFY_ANIM)
            {
                struct ComfyAnimEasingConfig config;
                InitComfyAnimConfig_Easing(&config);
                config.durationFrames = PANEL_SLIDE_DOWN_FRAMES;
                config.from = Q_24_8(PANEL_MAX_Y);
                config.to = Q_24_8(PANEL_MIN_Y);
                config.easingFunc = ComfyAnimEasing_EaseOutCubic;
                tRotomPanelComfyAnimId = CreateComfyAnim_Easing(&config);
            }
            
            tRotomPanelLastY = sRotomPhone_StartMenu->menuRotomRealityPanelY;
            sRotomPhone_StartMenu->menuRotomRealityPanelY = ReadComfyAnimValueSmooth(&gComfyAnims[tRotomPanelComfyAnimId]);
            s8 yDifference = tRotomPanelLastY - sRotomPhone_StartMenu->menuRotomRealityPanelY;
            for (enum RotomPhone_RotomReality_SlidingPanelSprites spritePanel = RP_RR_PANEL_SPRITE_ONE; spritePanel < RP_RR_PANEL_SPRITE_COUNT; spritePanel ++)
            {
                if (sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel] != SPRITE_NONE)
                    gSprites[sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel]].y += yDifference;
            }
        }
        else if (sRotomPhone_StartMenu->menuRotomRealityPanelY == PANEL_MIN_Y)
        {
            if (sRotomPhoneOptions[menuSelectedRotomReality].selectedFunc)
                sRotomPhoneOptions[menuSelectedRotomReality].selectedFunc();
            sRotomPhone_StartMenu->menuRotomRealityPanelOpen = FALSE;
            ReleaseComfyAnim(tRotomPanelComfyAnimId);
            gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_HandleMainInput;
        }
    }
    else
    {
        if (sRotomPhone_StartMenu->menuRotomRealityPanelY < PANEL_MAX_Y)
        {
            if (tRotomPanelComfyAnimId == INVALID_COMFY_ANIM)
            {
                struct ComfyAnimEasingConfig config;
                InitComfyAnimConfig_Easing(&config);
                config.durationFrames = PANEL_SLIDE_UP_FRAMES;
                config.from = Q_24_8(PANEL_MIN_Y);
                config.to = Q_24_8(PANEL_MAX_Y);
                config.easingFunc = ComfyAnimEasing_EaseInOutCubic;
                tRotomPanelComfyAnimId = CreateComfyAnim_Easing(&config);
            }
            
            tRotomPanelLastY = sRotomPhone_StartMenu->menuRotomRealityPanelY;
            sRotomPhone_StartMenu->menuRotomRealityPanelY = ReadComfyAnimValueSmooth(&gComfyAnims[tRotomPanelComfyAnimId]);
            s8 yDifference = tRotomPanelLastY - sRotomPhone_StartMenu->menuRotomRealityPanelY;
            for (enum RotomPhone_RotomReality_SlidingPanelSprites spritePanel = RP_RR_PANEL_SPRITE_ONE; spritePanel < RP_RR_PANEL_SPRITE_COUNT; spritePanel ++)
            {
                if (sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel] != SPRITE_NONE)
                    gSprites[sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel]].y += yDifference;
            }
        }
        else if (sRotomPhone_StartMenu->menuRotomRealityPanelY == PANEL_MAX_Y)
        {
            sRotomPhone_StartMenu->menuRotomRealityPanelOpen = TRUE;
            ReleaseComfyAnim(tRotomPanelComfyAnimId);
            gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_PanelInput;
        }
    }
    #undef PANEL_MIN_Y
    #undef PANEL_MAX_Y
    #undef PANEL_SLIDE_DOWN_FRAMES
    #undef PANEL_SLIDE_UP_FRAMES

    if (tRotomMessageSoundEffect && !IsSEPlaying())
        PlaySE(tRotomMessageSoundEffect);
}

static void RotomPhone_RotomRealityMenu_StartPanelSlide(void)
{
    u8 taskId = FindTaskIdByFunc(Task_RotomPhone_RotomRealityMenu_HandleMainInput);
    gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_PanelSlide;
    tRotomPanelComfyAnimId = INVALID_COMFY_ANIM;
}

static void Task_RotomPhone_RotomRealityMenu_WaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sRotomPhone_RotomReality = FALSE;
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        RotomPhone_StartMenu_DoCleanUpAndDestroyTask(taskId, FALSE);
    }
}

static void Task_RotomPhone_RotomRealityMenu_WaitFadeAndExitGracefully(u8 taskId)
{
    if (tPhoneCloseParameterSaveSafariFade == FALSE && gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].callback == SpriteCallbackDummy)
    {
        gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].invisible = TRUE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        tPhoneCloseParameterSaveSafariFade = TRUE;
        return;
    }
    
    if (!gPaletteFade.active && gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].callback == SpriteCallbackDummy)
    {
        m4aSongNumStop(SE_PC_OFF);
        sRotomPhone_RotomReality = FALSE;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        SetMainCallback2(CB2_ReturnToField);
        RotomPhone_StartMenu_DoCleanUpAndDestroyTask(taskId, FALSE);
    }
}

static void Task_RotomPhone_RotomRealityMenu_WaitFadeAndExitGracefullyForSave(u8 taskId)
{
    if (tPhoneCloseParameterSaveSafariFade == FALSE && gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].callback == SpriteCallbackDummy)
    {
        gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].invisible = TRUE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITE);
        tPhoneCloseParameterSaveSafariFade = TRUE;
        return;
    }
    
    if (!gPaletteFade.active && gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].callback == SpriteCallbackDummy)
    {
        m4aSongNumStop(SE_PC_OFF);
        sRotomPhone_RotomReality = FALSE;
        if (taskId != TASK_NONE) DestroyTask(taskId);
        RotomPhone_StartMenu_DoCleanUpAndChangeCallback(RotomPhone_SaveScreen_SetupCB);
    }
}

static void Task_RotomPhone_RotomRealityMenu_WaitFadeForSelection(u8 taskId)
{
    if (!gPaletteFade.active && sRotomPhoneOptions[menuSelectedRotomReality].selectedFunc)
    {
        if (taskId != TASK_NONE) DestroyTask(taskId);
        sRotomPhoneOptions[menuSelectedRotomReality].selectedFunc();
    }
}

static bool32 RotomPhone_RotomRealityMenu_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }
    sBg2TilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
    if (sBg2TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sRotomPhone_RotomRealityMenuBgTemplates, NELEMS(sRotomPhone_RotomRealityMenuBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    return TRUE;
}

static void RotomPhone_RotomRealityMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_RotomPhone_RotomRealityMenu_WaitFadeAndBail, 0);
    SetVBlankCallback(RotomPhone_RotomRealityMenu_SaveScreen_VBlankCB);
    SetMainCallback2(RotomPhone_RotomRealityMenu_SaveScreen_MainCB);
}

static void RotomPhone_RotomRealityMenu_LoadBgPalette(void)
{
#if RP_CONFIG_PALETTE_BUFFER
        LoadPalette(menuLoadedBackgroundPalette, BG_PLTT_ID(PHONE_BG_PAL_SLOT), PLTT_SIZE_4BPP);
#else
        LoadPalette(RotomPhone_StartMenu_GetPhoneColour(), BG_PLTT_ID(PHONE_BG_PAL_SLOT), PLTT_SIZE_4BPP);
#endif
}

static bool32 RotomPhone_RotomRealityMenu_LoadGraphics(void)
{
    switch (sRotomPhone_StartMenu->menuRotomRealityLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sRotomPhone_RotomRealityMenuTiles, 0, 0, 0);
        sRotomPhone_StartMenu->menuRotomRealityLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderVram(sRotomPhone_RotomRealityMenuTilemap, sBg1TilemapBuffer);
            DecompressDataWithHeaderVram(sRotomPhone_RotomRealityMenuPanelTilemap, sBg2TilemapBuffer);
            sRotomPhone_StartMenu->menuRotomRealityLoadState++;
        }
        break;
    case 2:
        RotomPhone_RotomRealityMenu_LoadBgPalette();
        sRotomPhone_StartMenu->menuRotomRealityLoadState++;
    default:
        sRotomPhone_StartMenu->menuRotomRealityLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void RotomPhone_RotomRealityMenu_CreateIconSprites(void)
{
    enum RotomPhone_RotomReality_Options drawn = RP_RR_OPTION_1;
    u32 drawnCount = RP_RR_OPTION_COUNT;
    u32 animNum;

    for (enum RotomPhone_MenuItems menuId = sRotomPhone_StartMenu->menuRotomRealityFirstOnScreenOption; menuId < RP_MENU_COUNT && drawn < drawnCount; menuId++)
    {
        const struct RotomPhone_MenuOptions *menuOption = &sRotomPhoneOptions[menuId];

        if (menuOption->unlockedFunc && menuOption->unlockedFunc())
        {
            enum RotomPhone_RotomReality_Options optionSlot = RP_RR_OPTION_1 + drawn;
            const struct SpriteTemplate *spriteTemplate;

            if (menuId != RP_MENU_SHORTCUT)
            {
                animNum = menuOption->rrAnim;
                spriteTemplate = menuOption->rrSpriteTemplate;
            }
            else
            {
                animNum = sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_RR].rrAnim;
                spriteTemplate = sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_RR].rrSpriteTemplate;
            }

            sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[optionSlot] = CreateSprite(
                spriteTemplate,
                sRotomRealityOptionInfo[optionSlot].x,
                sRotomRealityOptionInfo[optionSlot].y,
                1
            );
            sRotomPhone_StartMenu->menuRotomRealityOptions[optionSlot] = menuId;
            gSprites[sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[optionSlot]].oam.priority = 2;
            StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomRealityIconSpriteId[optionSlot]], animNum);
            drawn++;
        }
    }

    for (; drawn < RP_RR_OPTION_COUNT; drawn++)
    {
        sRotomPhone_StartMenu->menuRotomRealityOptions[drawn] = RP_MENU_COUNT;
    }
}

#define SHORTCUT_ICON_X_OFFSET 12
#define SHORTCUT_ICON_Y_OFFSET 11
static void RotomPhone_RotomRealityMenu_ShortcutIconCallback(struct Sprite *sprite)
{
    s32 xOffset;
    u32 optionCurrent;

    for (enum RotomPhone_RotomReality_Options i = RP_RR_OPTION_1; i < RP_RR_OPTION_COUNT; i++)
    {
        if (sRotomPhone_StartMenu->menuRotomRealityOptions[i] == RP_GET_SHORTCUT_OPTION_RR)
        {
            optionCurrent = i;

            switch (optionCurrent)
            {
                case RP_RR_OPTION_3:
                case RP_RR_OPTION_4:
                case RP_RR_OPTION_7:
                case RP_RR_OPTION_8:
                case RP_RR_OPTION_10:
                    xOffset = -SHORTCUT_ICON_X_OFFSET;
                    break;
                
                default:
                    xOffset = SHORTCUT_ICON_X_OFFSET;
                    break;
            }
            
            sprite->x = sRotomRealityOptionInfo[i].x + xOffset;
            sprite->y = sRotomRealityOptionInfo[i].y - SHORTCUT_ICON_Y_OFFSET;
            sprite->invisible = FALSE;

            return;
        }
    }

    sprite->invisible = TRUE;
}

static void RotomPhone_RotomRealityMenu_CreateShortcutIcon(void)
{
    if (!RP_CONFIG_ROTOM_REALITY_SHORTCUT)
        return;
    
    sRotomPhone_StartMenu->menuRotomRealityShortcutIconSpriteId = CreateSprite(&sSpriteTemplate_RotomRealityShortcutIcon, 0, 0, 1);
    gSprites[sRotomPhone_StartMenu->menuRotomRealityShortcutIconSpriteId].callback = RotomPhone_RotomRealityMenu_ShortcutIconCallback;
}
#undef SHORTCUT_ICON_X_OFFSET
#undef SHORTCUT_ICON_Y_OFFSET

#define ROTOM_CURSOR_X_OFFSET 10
#define ROTOM_CURSOR_Y_OFFSET 6
#define sComfyAnimIdX         sprite->data[0]
#define sComfyAnimIdY         sprite->data[1]
static void RotomPhone_RotomRealityMenu_CursorCallback(struct Sprite *sprite)
{
    struct ComfyAnim *xAnim = &gComfyAnims[sComfyAnimIdX];
    struct ComfyAnim *yAnim = &gComfyAnims[sComfyAnimIdY];
    struct ComfyAnimSpringConfig *xConfig = &xAnim->config.data.spring;
    struct ComfyAnimSpringConfig *yConfig = &yAnim->config.data.spring;
    enum RotomPhone_RotomReality_Options optionCurrent = RP_RR_OPTION_1;
    s32 xOffset;

    if (sprite->x > DISPLAY_WIDTH / 2)
    {
        sprite->hFlip = TRUE;
        xOffset = -ROTOM_CURSOR_X_OFFSET;
    }
    else
    {
        sprite->hFlip = FALSE;
        xOffset = ROTOM_CURSOR_X_OFFSET;
    }

    for (enum RotomPhone_RotomReality_Options i = RP_RR_OPTION_1; i < RP_RR_OPTION_COUNT; i++)
    {
        if (sRotomPhone_StartMenu->menuRotomRealityOptions[i] == menuSelectedRotomReality)
        {
            optionCurrent = i;
            break;
        }
    }

    xConfig->to = Q_24_8(sRotomRealityOptionInfo[optionCurrent].x + xOffset);
    yConfig->to = Q_24_8(sRotomRealityOptionInfo[optionCurrent].y + ROTOM_CURSOR_Y_OFFSET);

    sprite->x = ReadComfyAnimValueSmooth(xAnim);
    sprite->y = ReadComfyAnimValueSmooth(yAnim);

    UpdateMonIconFrame(sprite);
}

static void RotomPhone_RotomRealityMenu_CreateCursorSprite(void)
{
    struct Sprite *sprite;
    enum RotomPhone_RotomReality_Options optionCurrent = RP_RR_OPTION_1;
    u8 x;
    u8 y;
    u8 xOffset;
    LoadMonIconPalette(SPECIES_ROTOM);

    for (enum RotomPhone_RotomReality_Options i = RP_RR_OPTION_1; i < RP_RR_OPTION_COUNT; i++)
    {
        if (sRotomPhone_StartMenu->menuRotomRealityOptions[i] == menuSelectedRotomReality)
        {
            optionCurrent = i;
            break;
        }
    }

    switch (optionCurrent)
    {
        case RP_RR_OPTION_3:
        case RP_RR_OPTION_4:
        case RP_RR_OPTION_7:
        case RP_RR_OPTION_8:
        case RP_RR_OPTION_10:
            xOffset = -ROTOM_CURSOR_X_OFFSET;
            break;
        
        default:
            xOffset = ROTOM_CURSOR_X_OFFSET;
            break;
    }
    
    x = sRotomRealityOptionInfo[optionCurrent].x + xOffset;
    y = sRotomRealityOptionInfo[optionCurrent].y + ROTOM_CURSOR_Y_OFFSET;
    sRotomPhone_StartMenu->menuRotomRealityCursorSpriteId = CreateMonIcon(SPECIES_ROTOM, RotomPhone_RotomRealityMenu_CursorCallback,
        x,
        y,
        0, Random32()
    );
    sprite = &gSprites[sRotomPhone_StartMenu->menuRotomRealityCursorSpriteId];

    struct ComfyAnimSpringConfig xConfig;
    struct ComfyAnimSpringConfig yConfig;
    InitComfyAnimConfig_Spring(&xConfig);
    InitComfyAnimConfig_Spring(&yConfig);

    xConfig.from = Q_24_8(x);
    xConfig.to = Q_24_8(x);
    xConfig.mass = Q_24_8(CURSOR_COMFY_SPRING_MASS);
    xConfig.tension = Q_24_8(CURSOR_COMFY_SPRING_TENSION);
    xConfig.friction = Q_24_8(CURSOR_COMFY_SPRING_FRICTION);
    xConfig.clampAfter = CURSOR_COMFY_SPRING_CLAMP_AFTER;

    yConfig.from = Q_24_8(y);
    yConfig.to = Q_24_8(y);
    yConfig.mass = Q_24_8(CURSOR_COMFY_SPRING_MASS);
    yConfig.tension = Q_24_8(CURSOR_COMFY_SPRING_TENSION);
    yConfig.friction = Q_24_8(CURSOR_COMFY_SPRING_FRICTION);
    yConfig.clampAfter = CURSOR_COMFY_SPRING_CLAMP_AFTER;
    
    sComfyAnimIdX = CreateComfyAnim_Spring(&xConfig);
    sComfyAnimIdY = CreateComfyAnim_Spring(&yConfig);
}
#undef ROTOM_CURSOR_X_OFFSET
#undef ROTOM_CURSOR_Y_OFFSET

static void RotomPhone_RotomRealityMenu_InitWindows(void)
{
    InitWindows(sRotomPhone_RotomRealityMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(RP_RR_WIN_TIME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(RP_RR_WIN_TIME);
    CopyWindowToVram(RP_RR_WIN_TIME, COPYWIN_FULL);
    FillWindowPixelBuffer(RP_RR_WIN_MENU_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(RP_RR_WIN_MENU_NAME);
    CopyWindowToVram(RP_RR_WIN_MENU_NAME, COPYWIN_FULL);
}

static void RotomPhone_RotomRealityPanel_DestroyAssets(void)
{
    for (enum RotomPhone_RotomReality_SlidingPanelSprites spritePanel = RP_RR_PANEL_SPRITE_ONE; spritePanel < RP_RR_PANEL_SPRITE_COUNT; spritePanel++)
    {
        u8 spriteId = sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel];
        if (spriteId == SPRITE_NONE)
            continue;

        DestroySpriteAndFreeResources(&gSprites[spriteId]);
        sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel] = SPRITE_NONE;
    }

    for (enum RotomPhone_RotomReality_SlidingPanelWindows windowPanel = RP_RR_PANEL_WIN_ONE; windowPanel < RP_RR_PANEL_WIN_COUNT; windowPanel++)
    {
        u8 windowId = sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[windowPanel];
        if (windowId == WINDOW_NONE)
            continue;

        struct Window windowLocal = gWindows[windowId];
        FillBgTilemapBufferRect(
            windowLocal.window.bg,
            ROTOM_REALITY_PANEL_BG_TILE,
            windowLocal.window.tilemapLeft,
            windowLocal.window.tilemapTop,
            windowLocal.window.width,
            windowLocal.window.height,
            windowLocal.window.paletteNum);
        
        CopyWindowToVram(windowId, COPYWIN_FULL);
        RemoveWindow(windowId);
        sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[windowPanel] = WINDOW_NONE;
    }
}

static void RotomPhone_RotomRealityMenu_PrintTime(void)
{
    u8 time[24];
    RtcCalcLocalTime();
    FormatDecimalTimeWithoutSeconds(time, gLocalTime.hours, gLocalTime.minutes, RP_CONFIG_24_HOUR_MODE);

    FillWindowPixelBuffer(RP_RR_WIN_TIME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    AddTextPrinterParameterized4(RP_RR_WIN_TIME, FONT_NARROWER,
        GetStringCenterAlignXOffset(FONT_NARROWER, time, sRotomPhone_RotomRealityMenuWindowTemplates[RP_RR_WIN_TIME].width * 8),
        1, 0, 0,
        sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, time);

    CopyWindowToVram(RP_RR_WIN_TIME, COPYWIN_GFX);
}

static void RotomPhone_RotomRealityMenu_PrintMenuName(void)
{
    const u8 *menuName = sRotomPhoneOptions[menuSelectedRotomReality].menuName;

    if (menuSelectedRotomReality == RP_MENU_CLOCK)
        menuName = COMPOUND_STRING("Map");

    FillWindowPixelBuffer(RP_RR_WIN_MENU_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    AddTextPrinterParameterized4(RP_RR_WIN_MENU_NAME, FONT_SMALL_NARROWER,
        GetStringCenterAlignXOffset(FONT_SMALL_NARROWER, menuName, sRotomPhone_RotomRealityMenuWindowTemplates[RP_RR_WIN_MENU_NAME].width * 8),
        0, 0, 0,
        sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, menuName);

    CopyWindowToVram(RP_RR_WIN_MENU_NAME, COPYWIN_GFX);
}

static void RotomPhone_RotomRealityMenu_LoadIconSpritePalette(void)
{
#if RP_CONFIG_PALETTE_BUFFER
    LoadPalette(menuLoadedSpritePalette_One, OBJ_PLTT_ID(IndexOfSpritePaletteTag(TAG_ROTOM_FACE_ICON_PAL)), PLTT_SIZE_4BPP);
    LoadPalette(menuLoadedSpritePalette_Two, OBJ_PLTT_ID(IndexOfSpritePaletteTag(TAG_PHONE_RR_ICON_GFX_2)), PLTT_SIZE_4BPP);
#else
    u32 index;
    
    index = IndexOfSpritePaletteTag(TAG_ROTOM_FACE_ICON_PAL);
    LoadPalette(sRotomPhone_StartMenuRotomFaceIconsPal, OBJ_PLTT_ID(index), PLTT_SIZE_4BPP); 
    if (!RP_CONFIG_USE_ROTOM_PHONE || RP_CONFIG_MONOCHROME_ICONS)
    {
        for (enum RotomPhone_Overworld_FaceIconPaletteIndex colour = PAL_FACE_ICON_TRANSPARENT + 1; colour < PAL_ICON_WHITE; colour++)
        {
            LoadPalette(&sRotomPhone_StartMenuRotomFaceIconsPal[PAL_ICON_MONOCHROME], OBJ_PLTT_ID(index) + colour, sizeof(u16));
        }
    }

    index = IndexOfSpritePaletteTag(TAG_PHONE_RR_ICON_GFX_2);
    LoadPalette(sRotomPhone_RotomRealityMenuIconsPal_Two, OBJ_PLTT_ID(index), PLTT_SIZE_4BPP); 
    if (!RP_CONFIG_USE_ROTOM_PHONE || RP_CONFIG_MONOCHROME_ICONS)
    {
        for (enum RotomPhone_Overworld_FaceIconPaletteIndex colour = PAL_FACE_ICON_TRANSPARENT + 1; colour < 16; colour++)
        {
            LoadPalette(&sRotomPhone_StartMenuRotomFaceIconsPal[PAL_ICON_MONOCHROME], OBJ_PLTT_ID(index) + colour, sizeof(u16));
        }
    }
#endif
}

static void RotomPhone_RotomRealityMenu_LoadSprites(void)
{
    LoadSpritePalette(sSpritePal_RotomFaceIcons);
    LoadSpritePalette(sSpritePal_RotomRealityIcons_Two);
    LoadSpritePalette(sSpritePal_RotomRealityShortcutIcon);
    LoadCompressedSpriteSheet(sSpriteSheet_RotomRealityShortcutIcon);
    LoadCompressedSpriteSheet(sSpriteSheet_RotomRealityIcons_One);
    LoadCompressedSpriteSheet(sSpriteSheet_RotomRealityIcons_Two);
    RotomPhone_StartMenu_LoadRotomFaceSpritesheet();
    
    RotomPhone_RotomRealityMenu_LoadIconSpritePalette();
}


// Rotom Phone Save Screen
static void RotomPhone_SaveScreen_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        RotomPhone_RotomRealityMenu_SaveScreen_ResetGpuRegsAndBgs();
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (RotomPhone_SaveScreen_InitBgs())
        {
            gMain.state++;
        }
        else
        {
            RotomPhone_SaveScreen_FadeAndBail();
            return;
        }
        break;
    case 3:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sRotomPhone_SaveScreenTiles, 0, 0, 0);
        gMain.state++;
        break;
    case 4:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderVram(sRotomPhone_SaveScreenTilemap, sBg1TilemapBuffer);
            gMain.state++;
        }
        else
        {
            RotomPhone_SaveScreen_FadeAndBail();
            return;
        }
        break;
    case 5:
        LoadPalette(sRotomPhone_SaveScreenPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(GetTextWindowPalette(gSaveBlock2Ptr->optionsWindowFrameType), BG_PLTT_ID(DLG_WINDOW_PALETTE_NUM), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 6:
        RotomPhone_SaveScreen_InitWindows();
        gMain.state++;
        break;
    case 7:
        CreateTask(Task_RotomPhone_SaveScreen_WaitFadeIn, 0);
        gMain.state++;
        break;
    case 8:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);
        gMain.state++;
        break;
    case 9:
        SetVBlankCallback(RotomPhone_RotomRealityMenu_SaveScreen_VBlankCB);
        SetMainCallback2(RotomPhone_RotomRealityMenu_SaveScreen_MainCB);
        break;
    }
}

static void Task_RotomPhone_SaveScreen_WaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_RotomPhone_SaveScreen_WaitSaveGame;
        SaveGame();
    }
}

static void Task_RotomPhone_SaveScreen_WaitSaveGame(u8 taskId)
{
    if (!FuncIsActiveTask(SaveGameTask))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_RotomPhone_SaveScreen_WaitFadeAndExit;
    }
    
}

static void Task_RotomPhone_SaveScreen_WaitFadeAndExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToField);
        RotomPhone_RotomRealityMenu_SaveScreen_FreeResources();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        if (taskId != TASK_NONE) DestroyTask(taskId);
    }
}

static bool32 RotomPhone_SaveScreen_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sRotomPhone_RotomRealityMenuBgTemplates, NELEMS(sRotomPhone_RotomRealityMenuBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}

static void RotomPhone_SaveScreen_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_RotomPhone_SaveScreen_WaitFadeAndExit, 0);
    SetVBlankCallback(RotomPhone_RotomRealityMenu_SaveScreen_VBlankCB);
    SetMainCallback2(RotomPhone_RotomRealityMenu_SaveScreen_MainCB);
}

static void RotomPhone_SaveScreen_InitWindows(void)
{
    u8 windowId = AddWindow(&sRotomPhone_SaveScreen_Dialogue);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    LoadUserWindowBorderGfx(windowId + 1, STD_WINDOW_BASE_TILE_NUM, BG_PLTT_ID(STD_WINDOW_PALETTE_NUM));
}

static void RotomPhone_RotomRealityMenu_SaveScreen_FreeResources(void)
{
    if (sRotomPhone_StartMenu != NULL)
    {
        Free(sRotomPhone_StartMenu);
        sRotomPhone_StartMenu = NULL;
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    if (sBg2TilemapBuffer != NULL)
    {
        Free(sBg2TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ReleaseComfyAnims();
    ResetSpriteData();
}


// Common Rotom Phone Start Menu
static void RotomPhone_RotomRealityMenu_SaveScreen_MainCB(void)
{
    RunTasks();
    AdvanceComfyAnimations();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void RotomPhone_RotomRealityMenu_SaveScreen_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void RotomPhone_RotomRealityMenu_SaveScreen_ResetGpuRegsAndBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    CpuFill16(0, (void *)VRAM, VRAM_SIZE);
    CpuFill32(0, (void *)OAM, OAM_SIZE);
}

static void RotomPhone_RotomRealityMenu_TimerUpdates(u8 taskId)
{
    tRotomUpdateTimer++;
    if (tRotomUpdateTimer == ROTOM_PHONE_RR_MESSGAGE_TIMER)
    {
        tRotomUpdateTimer = 0;
        if (RP_CONFIG_UPDATE_MESSAGE_SOUND)
            tRotomMessageSoundEffect = SE_SELECT;
        RotomPhone_RotomRealityMenu_PrintTime();
        RotomPhone_StartMenu_UpdateRotomFaceAnim(FALSE);
    }
}

static void RotomPhone_StartMenu_LoadRotomFaceSpritesheet(void)
{
    struct CompressedSpriteSheet rotomFace;
    rotomFace.data = sRotomPhone_StartMenuRotomFaceGfx;
    rotomFace.size = 64 * 320 / 2;
    rotomFace.tag = TAG_ROTOM_FACE_GFX;
    LoadCompressedSpriteSheet(&rotomFace);
    sRotomPhone_StartMenu->rotomFaceLastLoaded = RP_FACE_COUNT - 1;
    
    if (GetSpriteTileStartByTag(rotomFace.tag) == TAG_NONE)
    {
        rotomFace.size = 64 * 384 / 2;
        LoadCompressedSpriteSheet(&rotomFace);
        sRotomPhone_StartMenu->rotomFaceLastLoaded = RP_FACE_SHOCKED_WITH;
    }
    
    if (GetSpriteTileStartByTag(rotomFace.tag) == TAG_NONE)
    {
        rotomFace.size = 64 * 192 / 2;
        LoadCompressedSpriteSheet(&rotomFace);
        sRotomPhone_StartMenu->rotomFaceLastLoaded = RP_FACE_HAPPY_WITH;
    }
    
    if (GetSpriteTileStartByTag(rotomFace.tag) == TAG_NONE)
    {
        rotomFace.size = 64 * 64 / 2;
        LoadCompressedSpriteSheet(&rotomFace);
        sRotomPhone_StartMenu->rotomFaceLastLoaded = RP_FACE_HAPPY;
    }

    if (GetSpriteTileStartByTag(rotomFace.tag) == TAG_NONE)
        sRotomPhone_StartMenu->rotomFaceLastLoaded = RP_FACE_COUNT;
}

static void RotomPhone_StartMenu_CreateRotomFaceSprite(bool32 rotomFade)
{
    if (!RP_CONFIG_ROTOM_ACTIVE || sRotomPhone_StartMenu->menuRotomFaceSpriteId != SPRITE_NONE)
        return;

    bool32 flash = FALSE;
    u32 x;
    u32 y;

    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        x = 196;
        y = 132;
    }
    else
    {
        x = 120;
        y = 136;
    }

    if ((GetFlashLevel() > 0 || InBattlePyramid_()) && !RotomPhone_StartMenu_IsRotomReality())
        flash = TRUE;

    if (flash)
    {
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
    }

    sRotomPhone_StartMenu->menuRotomFaceSpriteId = CreateSprite(
        &sSpriteTemplate_RotomFace,
        x,
        y,
        0
    );

    if (sRotomPhone_StartMenu->rotomFaceLastLoaded == RP_FACE_COUNT)
        gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].invisible = TRUE;

    if (rotomFade)
    {
        PlaySE(SE_RG_CARD_FLIP);
        struct Sprite *sprite = &gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId];
        sprite->callback = SpriteCB_RotomPhone_OverworldMenu_RotomFace_Load;
        rotomFaceExpression = RP_FACE_HAPPY;
        StartSpriteAnim(sprite, rotomFaceExpression);

        struct ComfyAnimSpringConfig config;
        InitComfyAnimConfig_Spring(&config);
        config.from = Q_24_8(FADE_COLOUR_MIN);
        config.to = Q_24_8(FADE_COLOUR_MID);
        config.mass = Q_24_8(FACE_ICON_COMFY_SPRING_MASS);
        config.tension = Q_24_8(FACE_ICON_COMFY_SPRING_TENSION);
        config.friction = Q_24_8(FACE_ICON_COMFY_SPRING_FRICTION);
        config.clampAfter = FACE_ICON_COMFY_SPRING_CLAMP_AFTER;
        sFrameNumComfyAnimId = CreateComfyAnim_Spring(&config);
    }

    if (RotomPhone_StartMenu_IsRotomReality())
    {
        StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId], rotomFaceExpression);
        gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].oam.priority = 1;
    }

    if (flash)
    {
        sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId = CreateSprite(
            &sSpriteTemplate_RotomFace,
            x,
            y,
            0
        );
        gSprites[sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId].oam.objMode = ST_OAM_OBJ_WINDOW;

        if (sRotomPhone_StartMenu->rotomFaceLastLoaded == RP_FACE_COUNT)
            gSprites[sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId].invisible = TRUE;
    }
}

static void RotomPhone_StartMenu_UpdateRotomFaceAnim(bool32 input)
{
    if (sRotomPhone_StartMenu->menuRotomFaceSpriteId == SPRITE_NONE)
        return;
    enum RotomPhone_FaceExpressions rotomFace = RP_FACE_HAPPY;
    u32 randMax = sRotomPhone_StartMenu->rotomFaceLastLoaded + 1;
    if (!input)
    {
        if ((Random() % 100) < RP_CONFIG_FACE_UPDATE_PERCENT)
        {
            if (sRotomPhone_StartMenu->rotomFaceLastLoaded != RP_FACE_HAPPY)
            {
                do {
                    rotomFace = Random() % randMax;
                } while (
                    rotomFace == gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].animNum ||
                    rotomFace == RP_FACE_HAPPY_UP || rotomFace == RP_FACE_SHOCKED_UP
                );
            }
            
            StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId], rotomFace);
            if (sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId != SPRITE_NONE)
                StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId], rotomFace);
            rotomFaceExpression = rotomFace;
        }
    }
    else
    {
        if (sRotomPhone_StartMenu->rotomFaceLastLoaded >= RP_FACE_SHOCKED_WITH)
        {
            do {
                rotomFace = Random() % randMax;
            } while (
                    rotomFace == gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId].animNum ||
                    (rotomFace != RP_FACE_HAPPY_UP && rotomFace != RP_FACE_SHOCKED_UP)
                );
        }
        else if (sRotomPhone_StartMenu->rotomFaceLastLoaded == RP_FACE_HAPPY_WITH)
        {
            rotomFace = RP_FACE_HAPPY_UP;
        }

        StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomFaceSpriteId], rotomFace);
        if (sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId != SPRITE_NONE)
            StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomFaceFlashSpriteId], rotomFace);
    }
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_Unlocked(void)
{
    return TRUE;
}

static bool32 UNUSED RotomPhone_StartMenu_UnlockedFunc_Unlocked_Overworld(void)
{
    return !RotomPhone_StartMenu_IsRotomReality();
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_Unlocked_RotomReality(void)
{
    return RotomPhone_StartMenu_IsRotomReality();
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_Pokedex(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality() && !GetSafariZoneFlag())
        return FALSE;
    else
        return FlagGet(FLAG_SYS_POKEDEX_GET);
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_Pokemon(void)
{
    return FlagGet(FLAG_SYS_POKEMON_GET);
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_PokeNav(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
        return FALSE;
    else
        return FlagGet(FLAG_SYS_POKENAV_GET);
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_RotomLog(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
        return FALSE;
    else
        return FlagGet(FLAG_SYS_QUEST_MENU_GET);
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_Save(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
        return !GetSafariZoneFlag();
    else
        return TRUE;
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_SafariFlag(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
        return GetSafariZoneFlag();
    else
        return FALSE;
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_RotomReality(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
        return RP_CONFIG_ROTOM_ACTIVE && !GetSafariZoneFlag();
    else
        return FALSE;
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_DexNav(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality() && !GetSafariZoneFlag())
        return FALSE;
    else
        return FlagGet(DN_FLAG_DEXNAV_GET);
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_Clock(void)
{
    if (!RP_CONFIG_USE_ROTOM_PHONE || (RotomPhone_StartMenu_IsRotomReality()))
        return TRUE;
    else
        return FALSE;
}

static bool32 RotomPhone_StartMenu_UnlockedFunc_Shortcut(void)
{
    if (RP_CONFIG_USE_ROTOM_PHONE && (!RotomPhone_StartMenu_IsRotomReality()) && !GetSafariZoneFlag())
        return TRUE;
    else
        return FALSE;
}


static void RotomPhone_StartMenu_SelectedFunc_Shortcut(void)
{
    if (RotomPhone_StartMenu_IsRotomReality())
        sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_RR].selectedFunc();
    else
        sRotomPhoneOptions[RP_GET_SHORTCUT_OPTION_OW].selectedFunc();
}

static void RotomPhone_StartMenu_SelectedFunc_Pokedex(void)
{
    RotomPhone_StartMenu_DoCleanUpAndChangeCallback(CB2_OpenPokedex);
}

static void RotomPhone_StartMenu_SelectedFunc_Pokemon(void)
{
    RotomPhone_StartMenu_DoCleanUpAndChangeCallback(CB2_PartyMenuFromStartMenu);
}

static void RotomPhone_StartMenu_SelectedFunc_Bag(void)
{
    RotomPhone_StartMenu_DoCleanUpAndChangeCallback(CB2_BagMenuFromStartMenu);
}

static void RotomPhone_StartMenu_SelectedFunc_PokeNav(void)
{
    RotomPhone_StartMenu_DoCleanUpAndChangeCallback(CB2_InitPokeNav);
}

static void RotomPhone_StartMenu_SelectedFunc_RotomLog(void)
{    
    RotomPhone_StartMenu_DoCleanUpAndCreateTask(Task_QuestMenu_OpenFromStartMenu, 0);
}
static void RotomPhone_StartMenu_ChooseTrainerCard(void)
{
    if (IsOverworldLinkActive() || InUnionRoom())
        ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
    else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
        ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
    else
        ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
}

static void RotomPhone_StartMenu_SelectedFunc_Trainer(void)
{
    if (!gPaletteFade.active)
    {
        RotomPhone_StartMenu_DoCleanUpAndDestroyTask(FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_HandleMainInput), TRUE);
        RotomPhone_StartMenu_ChooseTrainerCard();
    }
}

static void RotomPhone_StartMenu_SelectedFunc_Save(void)
{
    u8 taskId;
    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        taskId = FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_HandleMainInput);
        gTasks[taskId].func = Task_RotomPhone_OverworldMenu_CloseAndSave;
        if (RP_CONFIG_USE_ROTOM_PHONE)
            RotomPhone_StartMenu_RotomShutdownPreparation(taskId, TRUE);
    }
    else
    {
        taskId = FindTaskIdByFunc(Task_RotomPhone_RotomRealityMenu_HandleMainInput);
        gTasks[taskId].func = Task_RotomPhone_RotomRealityMenu_WaitFadeAndExitGracefullyForSave;
        RotomPhone_StartMenu_RotomShutdownPreparation(taskId, FALSE);
    }
    tPhoneCloseParameterSaveSafariFade = FALSE;
}

static void RotomPhone_StartMenu_SelectedFunc_Settings(void)
{
    RotomPhone_StartMenu_DoCleanUpAndChangeCallback(CB2_InitOptionMenu);
}

static void RotomPhone_StartMenu_SelectedFunc_SafariFlag(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        if (!gPaletteFade.active)
        {
            FreezeObjectEvents();
            LockPlayerFieldControls();
            u8 taskId = FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_HandleMainInput);
            gTasks[taskId].func = Task_RotomPhone_OverworldMenu_CloseForSafari;
            tPhoneCloseParameterSaveSafariFade = FALSE;
        }
    }
    else
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_RotomPhone_RotomRealityMenu_WaitFadeIn, 0);
    }
}

static void RotomPhone_StartMenu_SelectedFunc_RotomReality(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        if (!gPaletteFade.active)
            RotomPhone_StartMenu_DoCleanUpAndChangeTaskFunc(FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_HandleMainInput), Task_RotomPhone_RotomRealityMenu_Open);
    }
    else
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_RotomPhone_RotomRealityMenu_WaitFadeIn, 0);
    }
}

static void RotomPhone_StartMenu_SelectedFunc_DexNav(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
        RotomPhone_StartMenu_DoCleanUpAndChangeTaskFunc(FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_HandleMainInput), Task_OpenDexNavFromStartMenu);
    else
        RotomPhone_StartMenu_DoCleanUpAndCreateTask(Task_OpenDexNavFromStartMenu, 0);
}

static void RotomPhone_StartMenu_CB2_OpenRegionMapFromRotomReality(void)
{
    FieldInitRegionMap(RotomPhone_RotomRealityMenu_Init);
}

static void RotomPhone_StartMenu_SelectedFunc_Clock(void)
{
    if (!RotomPhone_StartMenu_IsRotomReality())
    {
        u8 taskId = FindTaskIdByFunc(Task_RotomPhone_OverworldMenu_HandleMainInput);
        if (taskId == TASK_NONE)
            return;
        
        u8 time[24];
        RtcCalcLocalTime();
        FormatDecimalTimeWithoutSeconds(time, gLocalTime.hours, gLocalTime.minutes, RP_CONFIG_24_HOUR_MODE);
        u8 fontId = GetFontIdToFit(time, FONT_SHORT, 0, sWindowTemplate_FlipPhone.width * 8);
        FillWindowPixelBuffer(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, PIXEL_FILL(OW_FLIP_PHONE_TEXT_BG_COLOUR));
        AddTextPrinterParameterized4(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, fontId,
        GetStringCenterAlignXOffset(fontId, time, sWindowTemplate_FlipPhone.width * 8),
        ROTOM_SPEECH_BOTTOM_ROW_Y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_OW_FLIP_PHONE], TEXT_SKIP_DRAW, time);
        CopyWindowToVram(sRotomPhone_StartMenu->menuOverworldFlipPhoneWindowId, COPYWIN_GFX);
        tRotomMessageSoundEffect = SE_BALL_TRAY_EXIT;
        tRotomUpdateTimer = ROTOM_PHONE_OW_MESSGAGE_TIMER;
        sRotomPhone_StartMenu->menuOverworldLoading = FALSE;
    }
    else
    {
        RotomPhone_StartMenu_DoCleanUpAndChangeCallback(RotomPhone_StartMenu_CB2_OpenRegionMapFromRotomReality);
    }
}

static void RotomPhone_StartMenu_SelectedFunc_Daycare(void)
{
    #define MON_ONE 0
    #define MON_TWO 1

    #define MON_ICON_Y 220
    #define EGG_COMPATABILITY_ICON_Y 210
    #define MON_ICON_ONE_X 60
    #define MON_ICON_TWO_X 180
    #define MON_COMPATABILITY_ICON_X (MON_ICON_ONE_X + MON_ICON_TWO_X) / 2
    #define MON_ICON_PAL_SLOT_COMPATABILITY_ICON 0

    #define WIN_WIDTH 8
    #define WIN_HEIGHT 4
    #define WIN_TOP 22

    #define WIN_WIDTH_NO_MONS 18
    #define WIN_HEIGHT_NO_MONS 4
    #define WIN_TOP_NO_MONS 23

    #define TEXT_LINE_SPACE 14
    
    u8 windowId;

    if (RotomPhone_StartMenu_IsRotomReality() && sRotomPhone_StartMenu->menuRotomRealityPanelOpen == FALSE)
    {
        u8 textBuffer[0x80];
        u8 fontId;
        u8 y;

        if (GetDaycareState() == DAYCARE_NO_MONS)
        {
            struct WindowTemplate winTemplate = CreateWindowTemplate(
                2,
                6,
                WIN_TOP_NO_MONS,
                WIN_WIDTH_NO_MONS,
                WIN_HEIGHT_NO_MONS,
                PHONE_BG_PAL_SLOT,
                ROTOM_ROTOM_REALITY_NEXT_WIN_BASE_BLOCK
            );
            sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[RP_RR_PANEL_WIN_ONE] = AddWindow(&winTemplate);
            windowId = sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[RP_RR_PANEL_WIN_ONE];
            FillWindowPixelBuffer(windowId, PIXEL_FILL(RR_ROTOM_PHONE_TEXT_BG_COLOUR));
            PutWindowTilemap(windowId);

            y = 0;
            StringCopy(textBuffer, COMPOUND_STRING("Leave a Pokémon in the Daycare"));
            fontId = GetFontIdToFit(textBuffer, FONT_SMALL_NARROW, 0, winTemplate.width * 8);
            AddTextPrinterParameterized4(windowId, fontId,
                GetStringCenterAlignXOffset(fontId, textBuffer, WIN_WIDTH_NO_MONS * 8),
                y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, textBuffer
            );

            y += TEXT_LINE_SPACE;
            StringCopy(textBuffer, COMPOUND_STRING("to use this app."));
            fontId = GetFontIdToFit(textBuffer, FONT_SMALL_NARROW, 0, winTemplate.width * 8);
            AddTextPrinterParameterized4(windowId, fontId,
                GetStringCenterAlignXOffset(fontId, textBuffer, WIN_WIDTH_NO_MONS * 8),
                y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, textBuffer
            );

            CopyWindowToVram(windowId, COPYWIN_FULL);
            return;
        }

        struct DaycareMon *daycareMonOne = &gSaveBlock1Ptr->daycare.mons[MON_ONE];
        struct DaycareMon *daycareMonTwo = &gSaveBlock1Ptr->daycare.mons[MON_TWO];
        struct BoxPokemon *daycareBoxMonOne = &daycareMonOne->mon;
        struct BoxPokemon *daycareBoxMonTwo = &daycareMonTwo->mon;
        u16 speciesOne = GetBoxMonData(daycareBoxMonOne, MON_DATA_SPECIES);
        u16 speciesTwo = GetBoxMonData(daycareBoxMonTwo, MON_DATA_SPECIES);
        u8 levelGain[2];
        u8 level[3];
        u8 nickname[POKEMON_NAME_LENGTH + 1];
        u8 animId;

        LoadMonIconPalettes();

        if (GetDaycareState() != DAYCARE_NO_MONS)
        {
            u32 monOneLevel = GetLevelAfterDaycareSteps(daycareBoxMonOne, daycareMonOne->steps);
            u32 monOneLevelGain = GetNumLevelsGainedFromSteps(daycareMonOne);
            GetBoxMonData(daycareBoxMonOne, MON_DATA_NICKNAME, nickname);

            sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_ONE] =
                CreateMonIcon(speciesOne, SpriteCB_MonIcon, MON_ICON_ONE_X, MON_ICON_Y, 4, 0);
            gSprites[sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_ONE]].oam.priority = 0;

            ConvertIntToDecimalStringN(level, monOneLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
            ConvertIntToDecimalStringN(levelGain, monOneLevelGain, STR_CONV_MODE_LEFT_ALIGN, 2);

            struct WindowTemplate winTemplate = CreateWindowTemplate(
                2,
                4,
                WIN_TOP,
                WIN_WIDTH,
                WIN_HEIGHT,
                PHONE_BG_PAL_SLOT,
                ROTOM_ROTOM_REALITY_NEXT_WIN_BASE_BLOCK
            );
            sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[RP_RR_PANEL_WIN_ONE] = AddWindow(&winTemplate);
            windowId = sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[RP_RR_PANEL_WIN_ONE];
            FillWindowPixelBuffer(windowId, PIXEL_FILL(RR_ROTOM_PHONE_TEXT_BG_COLOUR));
            PutWindowTilemap(windowId);

            y = 0;
            StringCopy(textBuffer, nickname);
            fontId = GetFontIdToFit(textBuffer, FONT_SHORT, 0, winTemplate.width * 8);
            AddTextPrinterParameterized4(windowId, fontId,
                0,
                y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, textBuffer
            );

            y += TEXT_LINE_SPACE;
            StringCopy(textBuffer, COMPOUND_STRING("Level: "));
            StringAppend(textBuffer, level);
            StringAppend(textBuffer, COMPOUND_STRING(" (+"));
            StringAppend(textBuffer, levelGain);
            StringAppend(textBuffer, COMPOUND_STRING(")"));
            fontId = GetFontIdToFit(textBuffer, FONT_SMALL_NARROW, 0, winTemplate.width * 8);
            AddTextPrinterParameterized4(windowId, fontId,
                0,
                y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, textBuffer
            );

            CopyWindowToVram(windowId, COPYWIN_FULL);
        }

        if (GetDaycareState() != DAYCARE_NO_MONS && GetDaycareState() != DAYCARE_ONE_MON)
        {
            u32 monTwoLevel = GetLevelAfterDaycareSteps(daycareBoxMonTwo, daycareMonTwo->steps);
            u32 monTwoLevelGain = GetNumLevelsGainedFromSteps(daycareMonTwo);
            GetBoxMonData(daycareBoxMonTwo, MON_DATA_NICKNAME, nickname);

            sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_TWO] =
                CreateMonIcon(speciesTwo, SpriteCB_MonIcon, MON_ICON_TWO_X, MON_ICON_Y, 4, 0);
            gSprites[sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_TWO]].oam.priority = 0;

            ConvertIntToDecimalStringN(level, monTwoLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
            ConvertIntToDecimalStringN(levelGain, monTwoLevelGain, STR_CONV_MODE_LEFT_ALIGN, 2);

            struct WindowTemplate winTemplate = CreateWindowTemplate(
                2,
                18,
                WIN_TOP,
                WIN_WIDTH,
                WIN_HEIGHT,
                PHONE_BG_PAL_SLOT,
                ROTOM_ROTOM_REALITY_NEXT_WIN_BASE_BLOCK + (WIN_WIDTH * WIN_HEIGHT)
            );
            sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[RP_RR_PANEL_WIN_TWO] = AddWindow(&winTemplate);
            windowId = sRotomPhone_StartMenu->menuRotomRealityPanelWindowId[RP_RR_PANEL_WIN_TWO];
            FillWindowPixelBuffer(windowId, PIXEL_FILL(RR_ROTOM_PHONE_TEXT_BG_COLOUR));
            PutWindowTilemap(windowId);

            y = 0;
            StringCopy(textBuffer, nickname);
            fontId = GetFontIdToFit(textBuffer, FONT_SHORT, 0, winTemplate.width * 8);
            AddTextPrinterParameterized4(windowId, fontId,
                GetStringRightAlignXOffset(fontId, textBuffer, WIN_WIDTH * 8),
                y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, textBuffer
            );

            y += TEXT_LINE_SPACE;
            StringCopy(textBuffer, COMPOUND_STRING("Level: "));
            StringAppend(textBuffer, level);
            StringAppend(textBuffer, COMPOUND_STRING(" (+"));
            StringAppend(textBuffer, levelGain);
            StringAppend(textBuffer, COMPOUND_STRING(")"));
            fontId = GetFontIdToFit(textBuffer, FONT_SMALL_NARROW, 0, winTemplate.width * 8);
            AddTextPrinterParameterized4(windowId, fontId,
                GetStringRightAlignXOffset(fontId, textBuffer, WIN_WIDTH * 8),
                y, 0, 0, sRotomPhone_StartMenu_FontColours[FONT_RR_ROTOM_PHONE], TEXT_SKIP_DRAW, textBuffer
            );

            CopyWindowToVram(windowId, COPYWIN_FULL);
        }

        if (GetDaycareState() == DAYCARE_TWO_MONS)
        {
            struct SpritePalette iconCompatatbilityPal =
            {
                .data = sRotomPhone_DaycareCompatability_Pal,
                .tag = gMonIconPaletteTable[MON_ICON_PAL_SLOT_COMPATABILITY_ICON].tag,
            };

            struct SpriteTemplate iconCompatatbility_SpriteTemplate =
            {
                .tileTag = TAG_PHONE_RR_DAYCARE_ICON,
                .paletteTag = gMonIconPaletteTable[MON_ICON_PAL_SLOT_COMPATABILITY_ICON].tag,
                .oam = &sOam_IconDaycareCompatatbility,
                .callback = SpriteCallbackDummy,
                .anims = sAnims_IconDaycareCompatatbility,
                .affineAnims = gDummySpriteAffineAnimTable,
            };

            LoadCompressedSpriteSheet(&sSpriteSheet_CompatabilityIcon);
            LoadSpritePalette(&iconCompatatbilityPal);
            sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_THREE] =
                CreateSprite(&iconCompatatbility_SpriteTemplate, MON_COMPATABILITY_ICON_X, EGG_COMPATABILITY_ICON_Y, 0);
            gSprites[sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_THREE]].oam.priority = 0;

            switch (GetDaycareCompatibilityScore(&gSaveBlock1Ptr->daycare))
            {
            case PARENTS_INCOMPATIBLE:
                animId = RP_DAYCARE_COMPATABILITY_ANIM_NON;
                break;
            
            case PARENTS_LOW_COMPATIBILITY:
                animId = RP_DAYCARE_COMPATABILITY_ANIM_LOW;
                break;
            
            case PARENTS_MED_COMPATIBILITY:
                animId = RP_DAYCARE_COMPATABILITY_ANIM_MED;
                break;
            
            case PARENTS_MAX_COMPATIBILITY:
            default:
                animId = RP_DAYCARE_COMPATABILITY_ANIM_MAX;
                break;
            }
            StartSpriteAnim(&gSprites[sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_THREE]], animId);
        }

        if (GetDaycareState() == DAYCARE_EGG_WAITING)
        {
            void (*spriteCB)(struct Sprite *sprite);
            if (Random() % 2 == TRUE)
                spriteCB = SpriteCB_MonIcon;
            else
                spriteCB = SpriteCB_MonIcon;

            sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_THREE] =
                CreateMonIcon(SPECIES_EGG, spriteCB, MON_COMPATABILITY_ICON_X, EGG_COMPATABILITY_ICON_Y, 4, 0);
            gSprites[sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[RP_RR_PANEL_SPRITE_THREE]].oam.priority = 0;
        }
    }
    else if (RotomPhone_StartMenu_IsRotomReality() && sRotomPhone_StartMenu->menuRotomRealityPanelOpen == TRUE)
    {
        FreeMonIconPalettes();
        for (enum RotomPhone_RotomReality_SlidingPanelSprites spritePanel = RP_RR_PANEL_SPRITE_ONE; spritePanel < RP_RR_PANEL_SPRITE_COUNT; spritePanel++)
        {
            u8 spriteId = sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel];
            if (spriteId == SPRITE_NONE)
                continue;

            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
            sRotomPhone_StartMenu->menuRotomRealityPanelSpriteId[spritePanel] = SPRITE_NONE;
        }
        RotomPhone_RotomRealityPanel_DestroyAssets();
        LoadMonIconPalette(SPECIES_ROTOM);
    }
    #undef MON_ONE
    #undef MON_TWO

    #undef MON_ICON_Y
    #undef EGG_COMPATABILITY_ICON_Y
    #undef MON_ICON_ONE_X
    #undef MON_ICON_TWO_X
    #undef MON_ICON_PAL_SLOT_COMPATABILITY_ICON
    
    #undef WIN_WIDTH
    #undef WIN_HEIGHT
    #undef WIN_TOP

    #undef WIN_WIDTH_NO_MONS
    #undef WIN_HEIGHT_NO_MONS
    #undef WIN_TOP_NO_MONS

    #undef TEXT_LINE_SPACE
}
#undef PHONE_OFFSCREEN_Y
#undef TAG_ROTOM_FACE_GFX
#undef TAG_PHONE_OW_ICON_GFX
#undef TAG_PHONE_RR_ICON_GFX
#undef TAG_PHONE_RR_ICON_GFX_2
#undef TAG_PHONE_RR_SHORTCUT_ICON
#undef TAG_PHONE_RR_DAYCARE_ICON
#undef TAG_ROTOM_FACE_ICON_PAL
#undef PHONE_BG_PAL_SLOT
#undef PHONE_BASE_COLOUR_INDEX
#undef ROTOM_REALITY_COLUMN_ONE_X
#undef ROTOM_REALITY_COLUMN_TWO_X
#undef ROTOM_REALITY_COLUMN_THREE_X
#undef ROTOM_REALITY_COLUMN_FOUR_X
#undef ROTOM_REALITY_ROW_ONE_Y
#undef ROTOM_REALITY_ROW_TWO_Y
#undef ROTOM_REALITY_ROW_THREE_Y

#undef PHONE_COMFY_SLIDE_DURATION
#undef FACE_ICON_COMFY_SPRING_MASS
#undef FACE_ICON_COMFY_SPRING_TENSION
#undef FACE_ICON_COMFY_SPRING_FRICTION
#undef FACE_ICON_COMFY_SPRING_CLAMP_AFTER

#undef CURSOR_COMFY_SPRING_MASS
#undef CURSOR_COMFY_SPRING_TENSION
#undef CURSOR_COMFY_SPRING_FRICTION
#undef CURSOR_COMFY_SPRING_CLAMP_AFTER

#undef FADE_COLOUR_MAX
#undef FADE_COLOUR_MID
#undef FADE_COLOUR_MIN

#undef RP_MENU_FIRST_OPTION
#undef RP_MENU_LAST_OPTION

#undef RP_FACE_LOOK_UP_ANIMS

#undef ROTOM_SPEECH_WINDOW_WIDTH
#undef ROTOM_SPEECH_WINDOW_WIDTH_PXL
#undef ROTOM_SPEECH_WINDOW_HEIGHT
#undef ROTOM_SPEECH_WINDOW_LEFT
#undef ROTOM_SPEECH_WINDOW_TOP
#undef PHONE_STARTING_BASE_BLOCK

#undef ROTOM_ROTOM_REALITY_NEXT_WIN_BASE_BLOCK

#undef OW_FLIP_PHONE_TEXT_BG_COLOUR
#undef OW_FLIP_PHONE_TEXT_FG_COLOUR
#undef OW_FLIP_PHONE_TEXT_SHADOW_COLOUR
#undef OW_ROTOM_PHONE_TEXT_BG_COLOUR
#undef OW_ROTOM_PHONE_TEXT_FG_COLOUR
#undef OW_ROTOM_PHONE_TEXT_SHADOW_COLOUR

#undef ROTOM_SPEECH_TOP_ROW_Y
#undef ROTOM_SPEECH_BOTTOM_ROW_Y

#undef tRotomUpdateTimer
#undef tRotomUpdateMessage
#undef tRotomMessageSoundEffect
#undef tRotomPanelComfyAnimId
#undef tRotomPanelLastY
#undef tPhoneY
#undef tPhoneCloseParameterSaveSafariFade
#undef tPhoneHighlightComfyAnimId
#undef tRotomHintActive
#undef tRotomHintPromptState
#undef sFrameNumComfyAnimId
#undef sComfyAnimIdX
#undef sComfyAnimIdY
