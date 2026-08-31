#include "global.h"
#include "ui_screenshots.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gba/isagbprint.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "comfy_anim.h"
#include "random.h"

/*
 *
 */

//==========DEFINES==========//
struct ScreenshotsResources
{
    MainCallback savedCallback;
    u8 gfxLoadState;
    u16 screenshotId;
    u8 fadeInMode;
    u8 fadeOutMode;
    u8 screenshotMode;
    u16 soundId;
    bool8 textBoxShown;
    bool8 sequenceActive;
    const u8 *messageText;
    u16 playerIconSpriteId;
    u16 nameplateSpriteId[2];
    u16 cursorIconSpriteId;
    u16 selectedSeaSectionId;
};

struct ScreenshotRequest
{
    u16 screenshotId;
    u8 fadeInMode;
    u8 fadeOutMode;
    u8 screenshotMode;
    u16 soundId;
    const u8 *messageText;
};

enum WindowIds
{
    WINDOW_1,
};

//==========EWRAM==========//
static EWRAM_DATA struct ScreenshotsResources *sScreenshotsDataPtr = NULL;
static EWRAM_DATA u8 *sBg0TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA const u8 *sPendingMessageText = NULL;
static EWRAM_DATA struct ScreenshotRequest sPendingScreenshot;
static EWRAM_DATA bool8 sQueuedScreenshotReload = FALSE;

//==========STATIC=DEFINES==========//
static void Screenshots_RunSetup(void);
static void Screenshots_FadeToOpenCB(void);
static bool8 Screenshots_DoGfxSetup(void);
static bool8 Screenshots_InitBgs(void);
static void Screenshots_FadeAndBail(void);
static bool8 Screenshots_LoadGraphics(void);
static void Screenshots_InitWindows(void);
static void Screenshots_UpdateWindowsForReload(void);
static void Screenshots_BeginFadeIn(void);
static void Screenshots_BeginFadeToOpen(void);
static void Screenshots_BeginSequenceFade(u32 mode);
static void Screenshots_PlaySound(void);
static bool8 Screenshots_ShouldFadeIn(void);
static u16 Screenshots_GetRequestedFadeInColor(void);
static u16 Screenshots_GetFadeInColor(void);
static u16 Screenshots_GetFadeOutColor(void);
static u32 Screenshots_GetFadePaletteMask(void);
static void PrintToWindow(void);
static void Task_ScreenshotsWaitFadeIn(u8 taskId);
static void Task_ScreenshotsTurnOff(u8 taskId);
static void Task_ScreenshotsMain(u8 taskId);
static void Task_ScreenshotsFadeToFieldExit(u8 taskId);
static void Task_ScreenshotsFadeToNext(u8 taskId);
static void Task_ScreenshotsReload(u8 taskId);

#define SCREENSHOT_TILE_OFFSET 0
#define SCREENSHOT_TEXTBOX_BASE_TILE 0

//==========CONST=DATA==========//
static const struct BgTemplate sScreenshotsBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .priority = 1,
        .paletteMode = 1,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }
};

static const struct WindowTemplate sScreenshotsWindowTemplates[] =
{
    [WINDOW_1] =
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 17,
        .width = 10,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static const u32 sUELogoScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/ultra_eclipse_logo.png", ".8bpp.lz");
static const u32 sUELogoScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/ultra_eclipse_logo.bin", ".lz");
static const u16 sUELogoScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/ultra_eclipse_logo.png", ".gbapal");

static const u32 sThreeMonthsLaterScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/ThreeMonthsLater_Tiles.png", ".8bpp.lz");
static const u32 sThreeMonthsLaterScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/ThreeMonthsLater_Tiles.bin", ".lz");
static const u16 sThreeMonthsLaterScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/ThreeMonthsLater_Tiles.png", ".gbapal");

static const u32 sSurfingPikachuScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/surfingpikachu_tiles.png", ".8bpp.lz");
static const u32 sSurfingPikachuScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/surfingpikachu_tiles.bin", ".lz");
static const u16 sSurfingPikachuScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/surfingpikachu_tiles.png", ".gbapal");

static const u32 sTheNextDayScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/TheNextDay_tiles.png", ".8bpp.lz");
static const u32 sTheNextDayScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/TheNextDay_tiles.bin", ".lz");
static const u16 sTheNextDayScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/TheNextDay_tiles.png", ".gbapal");

static const u32 sEclipseOutsideLab2ScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/eclipse_at_lab_tiles2.png", ".8bpp.lz");
static const u32 sEclipseOutsideLab2ScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/eclipse_at_lab_tiles2.bin", ".lz");
static const u16 sEclipseOutsideLab2ScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/eclipse_at_lab_tiles2.png", ".gbapal");

static const u32 sEclipseOutsideLabScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/eclipse_at_lab_tiles.png", ".8bpp.lz");
static const u32 sEclipseOutsideLabScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/eclipse_at_lab_tiles.bin", ".lz");
static const u16 sEclipseOutsideLabScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/eclipse_at_lab_tiles.png", ".gbapal");

static const u32 sRotomPhoneIntro1ScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/rotom_phone_intro_1_tiles.png", ".8bpp.lz");
static const u32 sRotomPhoneIntro1ScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/rotom_phone_intro_1_tiles.bin", ".lz");
static const u16 sRotomPhoneIntro1ScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/rotom_phone_intro_1_tiles.png", ".gbapal");

static const u32 sRotomPhoneIntro2ScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/rotom_phone_intro_2_tiles.png", ".8bpp.lz");
static const u32 sRotomPhoneIntro2ScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/rotom_phone_intro_2_tiles.bin", ".lz");
static const u16 sRotomPhoneIntro2ScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/rotom_phone_intro_2_tiles.png", ".gbapal");

static const u32 sRotomPhoneIntro3ScreenshotsTiles[] = INCGFX_U32("graphics/ui_screenshots/rotom_phone_intro_3_tiles.png", ".8bpp.lz");
static const u32 sRotomPhoneIntro3ScreenshotsTilemap[] = INCGFX_U32("graphics/ui_screenshots/rotom_phone_intro_3_tiles.bin", ".lz");
static const u16 sRotomPhoneIntro3ScreenshotsPalette[] = INCGFX_U16("graphics/ui_screenshots/rotom_phone_intro_3_tiles.png", ".gbapal");

struct Screenshot
{
    const u32 *screenshotTiles;
    const u32 *screenshotTilemap;
    const u16 *screenshotPalette;
};

static const struct Screenshot sScreenshotData[] =
{
    [SCREENSHOT_ULTRA_ECLIPSE_LOGO] = {
        .screenshotTiles = sUELogoScreenshotsTiles,
        .screenshotTilemap = sUELogoScreenshotsTilemap,
        .screenshotPalette = sUELogoScreenshotsPalette,
    },
    [SCREENSHOT_THREE_MONTHS_LATER] = {
        .screenshotTiles = sThreeMonthsLaterScreenshotsTiles,
        .screenshotTilemap = sThreeMonthsLaterScreenshotsTilemap,
        .screenshotPalette = sThreeMonthsLaterScreenshotsPalette,
    },
    [SCREENSHOT_SURFING_PIKACHU] = {
        .screenshotTiles = sSurfingPikachuScreenshotsTiles,
        .screenshotTilemap = sSurfingPikachuScreenshotsTilemap,
        .screenshotPalette = sSurfingPikachuScreenshotsPalette,
    },
    [SCREENSHOT_THE_NEXT_DAY] = {
        .screenshotTiles = sTheNextDayScreenshotsTiles,
        .screenshotTilemap = sTheNextDayScreenshotsTilemap,
        .screenshotPalette = sTheNextDayScreenshotsPalette,
    },
    [SCREENSHOT_ECLIPSE_OUTSIDE_LAB] = {
        .screenshotTiles = sEclipseOutsideLabScreenshotsTiles,
        .screenshotTilemap = sEclipseOutsideLabScreenshotsTilemap,
        .screenshotPalette = sEclipseOutsideLabScreenshotsPalette,
    },
    [SCREENSHOT_ECLIPSE_OUTSIDE_LAB2] = {
        .screenshotTiles = sEclipseOutsideLab2ScreenshotsTiles,
        .screenshotTilemap = sEclipseOutsideLab2ScreenshotsTilemap,
        .screenshotPalette = sEclipseOutsideLab2ScreenshotsPalette,
    },
    [SCREENSHOT_ROTOM_PHONE_INTRO_1] = {
        .screenshotTiles = sRotomPhoneIntro1ScreenshotsTiles,
        .screenshotTilemap = sRotomPhoneIntro1ScreenshotsTilemap,
        .screenshotPalette = sRotomPhoneIntro1ScreenshotsPalette,
    },
    [SCREENSHOT_ROTOM_PHONE_INTRO_2] = {
        .screenshotTiles = sRotomPhoneIntro2ScreenshotsTiles,
        .screenshotTilemap = sRotomPhoneIntro2ScreenshotsTilemap,
        .screenshotPalette = sRotomPhoneIntro2ScreenshotsPalette,
    },
    [SCREENSHOT_ROTOM_PHONE_INTRO_3] = {
        .screenshotTiles = sRotomPhoneIntro3ScreenshotsTiles,
        .screenshotTilemap = sRotomPhoneIntro3ScreenshotsTilemap,
        .screenshotPalette = sRotomPhoneIntro3ScreenshotsPalette,
    },
};

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};

static const u8 sScreenshotsWindowFontColors[][3] =
{
    [FONT_BLACK] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GRAY},
};

void OpenScreenshotsFromScript(struct ScriptContext *ctx)
{
    u16 soundId = 0;

    DebugPrintf("SS open id=%u mode=%u active=%u", gSpecialVar_0x8003, VarGet(VAR_RESULT), sScreenshotsDataPtr != NULL);

    if (ctx != NULL)
    {
        u32 content = ScriptReadWord(ctx);

        ctx->waitAfterCallNative = TRUE;
        if (content >= 0x08000000)
        {
            sPendingMessageText = (const u8 *)content;
            soundId = gSpecialVar_0x8006;
        }
        else
        {
            sPendingMessageText = NULL;
            soundId = content != 0 ? content : gSpecialVar_0x8006;
        }
    }
    else
    {
        sPendingMessageText = NULL;
    }

    if (sScreenshotsDataPtr != NULL)
    {
        DebugPrintf("SS queue id=%u mode=%u", gSpecialVar_0x8003, VarGet(VAR_RESULT));
        sScreenshotsDataPtr->gfxLoadState = 0;
        sScreenshotsDataPtr->screenshotId = gSpecialVar_0x8003;
        sScreenshotsDataPtr->fadeInMode = gSpecialVar_0x8004;
        sScreenshotsDataPtr->fadeOutMode = gSpecialVar_0x8005;
        sScreenshotsDataPtr->screenshotMode = VarGet(VAR_RESULT);
        sScreenshotsDataPtr->soundId = soundId;
        if (sScreenshotsDataPtr->screenshotMode == START)
            sScreenshotsDataPtr->sequenceActive = TRUE;
        sScreenshotsDataPtr->messageText = sPendingMessageText;
        sQueuedScreenshotReload = TRUE;
        return;
    }

    sPendingScreenshot.screenshotId = gSpecialVar_0x8003;
    sPendingScreenshot.fadeInMode = gSpecialVar_0x8004;
    sPendingScreenshot.fadeOutMode = gSpecialVar_0x8005;
    sPendingScreenshot.screenshotMode = VarGet(VAR_RESULT);
    sPendingScreenshot.soundId = soundId;
    sPendingScreenshot.messageText = sPendingMessageText;
    Screenshots_BeginFadeToOpen();
    SetMainCallback2(Screenshots_FadeToOpenCB);
}

void Screenshots_Init(MainCallback callback)
{
    if ((sScreenshotsDataPtr = AllocZeroed(sizeof(struct ScreenshotsResources))) == NULL)
    {
        DebugPrintf("SS alloc failed");
        SetMainCallback2(callback);
        return;
    }

    DebugPrintf("SS init id=%u mode=%u", sPendingScreenshot.screenshotId, sPendingScreenshot.screenshotMode);

    sScreenshotsDataPtr->gfxLoadState = 0;
    sScreenshotsDataPtr->screenshotId = sPendingScreenshot.screenshotId;
    sScreenshotsDataPtr->fadeInMode = sPendingScreenshot.fadeInMode;
    sScreenshotsDataPtr->fadeOutMode = sPendingScreenshot.fadeOutMode;
    sScreenshotsDataPtr->screenshotMode = sPendingScreenshot.screenshotMode;
    sScreenshotsDataPtr->soundId = sPendingScreenshot.soundId;
    sScreenshotsDataPtr->textBoxShown = FALSE;
    sScreenshotsDataPtr->sequenceActive = (sScreenshotsDataPtr->screenshotMode == START
                                        || sScreenshotsDataPtr->screenshotMode == CONTINUE);
    sScreenshotsDataPtr->savedCallback = callback;
    sScreenshotsDataPtr->messageText = sPendingScreenshot.messageText;
    sQueuedScreenshotReload = FALSE;

    SetMainCallback2(Screenshots_RunSetup);
}

static void Screenshots_RunSetup(void)
{
    while (1)
    {
        if (Screenshots_DoGfxSetup() == TRUE)
            break;
    }
}

// Keep rendering the field fade without allowing its script context to advance.
static void Screenshots_FadeToOpenCB(void)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Screenshots_Init(CB2_ReturnToFieldContinueScript);
        return;
    }

    UpdatePaletteFade();
}

static void Screenshots_MainCB(void)
{
    RunTasks();
    RunTextPrinters();
    AdvanceComfyAnimations();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Screenshots_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 Screenshots_DoGfxSetup(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        ResetVramOamAndBgCntRegs();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        // OrbFadeToBlack leaves a hardware black fade active. Preserve black in
        // the software palette before clearing those registers for this screen.
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        ResetSpriteData();
        ResetTasks();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        gMain.state++;
        break;
    case 2:
        if (Screenshots_InitBgs())
        {
            sScreenshotsDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            DebugPrintf("SS bg init failed");
            Screenshots_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Screenshots_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        Screenshots_InitWindows();
        gMain.state++;
        break;
    case 5:
        Screenshots_PlaySound();
        if (Screenshots_ShouldFadeIn())
        {
            CreateTask(Task_ScreenshotsWaitFadeIn, 0);
            BlendPalettes(Screenshots_GetFadePaletteMask(), 16, Screenshots_GetFadeInColor());
            gMain.state++;
        }
        else
        {
            CreateTask(Task_ScreenshotsMain, 0);
            gMain.state = 7;
        }
        break;
    case 6:
        Screenshots_BeginFadeIn();
        gMain.state++;
        break;
    default:
        DebugPrintf("SS ready id=%u mode=%u", sScreenshotsDataPtr->screenshotId, sScreenshotsDataPtr->screenshotMode);
        DebugPrintf("SS regs ready disp=%04X cnt=%04X y=%u", GetGpuReg(REG_OFFSET_DISPCNT), GetGpuReg(REG_OFFSET_BLDCNT), GetGpuReg(REG_OFFSET_BLDY));
        SetVBlankCallback(Screenshots_VBlankCB);
        SetMainCallback2(Screenshots_MainCB);
        return TRUE;
    }

    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
    {                                  \
        Free(*ptr__);                  \
        *ptr__ = NULL;                 \
    }                                  \
})

static void Screenshots_FreeResources(void)
{
    try_free(sScreenshotsDataPtr);
    try_free(sBg0TilemapBuffer);
    try_free(sBg1TilemapBuffer);
    try_free(sBg2TilemapBuffer);
    ReleaseComfyAnims();
    FreeAllWindowBuffers();
}

static void Task_ScreenshotsWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sScreenshotsDataPtr->savedCallback);
        Screenshots_FreeResources();
        DestroyTask(taskId);
    }
}

static void Screenshots_FadeAndBail(void)
{
    DebugPrintf("SS bail");
    BeginNormalPaletteFade(Screenshots_GetFadePaletteMask(), 0, 0, 16, Screenshots_GetFadeOutColor());
    CreateTask(Task_ScreenshotsWaitFadeAndBail, 0);
    SetVBlankCallback(Screenshots_VBlankCB);
    SetMainCallback2(Screenshots_MainCB);
}

static void Screenshots_BeginFadeIn(void)
{
    BeginNormalPaletteFade(Screenshots_GetFadePaletteMask(), 0, 16, 0, Screenshots_GetFadeInColor());

    // BeginNormalPaletteFade advances immediately, so restore the first blend level
    // and then advance one level per normal fade tick.
    if (gPaletteFade.active && sScreenshotsDataPtr->fadeInMode != QUICK)
    {
        gPaletteFade.y = 15;
        gPaletteFade.deltaY = 1;
    }
    else if (gPaletteFade.active)
    {
        gPaletteFade.deltaY = 4;
    }
}

static void Screenshots_BeginFadeToOpen(void)
{
    u16 fadeColor = Screenshots_GetRequestedFadeInColor();

    if (sPendingScreenshot.fadeInMode == NONE)
        return;

    // A preceding script fade may already own the fully black/white field.
    // Restarting a time-of-day fade from level 0 would briefly restore its tint.
    if (gPaletteFade.y == 16 && gPaletteFade.blendColor == fadeColor)
        return;

    if (MapHasNaturalLight(gMapHeader.mapType))
    {
        BeginTimeOfDayPaletteFade(PALETTES_ALL, 0, 0, 16,
            &gTimeBlend.startBlend, &gTimeBlend.endBlend, gTimeBlend.weight,
            fadeColor);
    }
    else
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, fadeColor);
    }

}

// Preserve a visible dialogue window on BG0; textless sequences use the
// standard full-screen fade.
static void Screenshots_BeginSequenceFade(u32 mode)
{
    u32 blendCnt = (GetGpuReg(REG_OFFSET_BLDCNT) & BLDCNT_TGT2_ALL) | BLDCNT_TGT1_BG1;

    if (!sScreenshotsDataPtr->textBoxShown)
    {
        FadeScreenHardware(mode, 0);
        return;
    }

    SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR | WININ_WIN1_CLR);
    SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WIN01_CLR);

    switch (mode)
    {
    case FADE_FROM_BLACK:
        BeginHardwarePaletteFade(blendCnt | BLDCNT_EFFECT_DARKEN, 0, 16, 0, TRUE);
        break;
    case FADE_TO_BLACK:
        BeginHardwarePaletteFade(blendCnt | BLDCNT_EFFECT_DARKEN, 0, 0, 16, FALSE);
        break;
    case FADE_FROM_WHITE:
        BeginHardwarePaletteFade(blendCnt | BLDCNT_EFFECT_LIGHTEN, 0, 16, 0, TRUE);
        break;
    case FADE_TO_WHITE:
        BeginHardwarePaletteFade(blendCnt | BLDCNT_EFFECT_LIGHTEN, 0, 0, 16, FALSE);
        break;
    }
}

static void Screenshots_PlaySound(void)
{
    if (sScreenshotsDataPtr->soundId != 0)
        PlaySE(sScreenshotsDataPtr->soundId);
}

static bool8 Screenshots_ShouldFadeIn(void)
{
    return sScreenshotsDataPtr->fadeInMode != NONE;
}

static u16 Screenshots_GetRequestedFadeInColor(void)
{
    if (sPendingScreenshot.screenshotMode == START)
        return RGB_BLACK;

    return sPendingScreenshot.fadeInMode == WHITE ? RGB_WHITE : RGB_BLACK;
}

static u16 Screenshots_GetFadeInColor(void)
{
    if (sScreenshotsDataPtr != NULL
     && sScreenshotsDataPtr->screenshotMode == START)
        return RGB_BLACK;

    if (sScreenshotsDataPtr != NULL && sScreenshotsDataPtr->fadeInMode == WHITE)
        return RGB_WHITE;

    return RGB_BLACK;
}

static u16 Screenshots_GetFadeOutColor(void)
{
    if (sScreenshotsDataPtr != NULL
     && sScreenshotsDataPtr->sequenceActive
     && sScreenshotsDataPtr->screenshotMode == END)
        return RGB_BLACK;

    if (sScreenshotsDataPtr != NULL && sScreenshotsDataPtr->fadeOutMode == WHITE)
        return RGB_WHITE;

    return RGB_BLACK;
}

static u32 Screenshots_GetFadePaletteMask(void)
{
    // Keep the text window steady during normal and sequence transitions, but
    // fade it out with the final screenshot before returning to the field.
    if (sScreenshotsDataPtr != NULL
     && sScreenshotsDataPtr->messageText != NULL
     && sScreenshotsDataPtr->screenshotMode != END)
        return 0x7FFF;

    return 0xFFFF;
}

static bool8 Screenshots_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg0TilemapBuffer = Alloc(0x800);
    if (sBg0TilemapBuffer == NULL)
        return FALSE;
    memset(sBg0TilemapBuffer, 0, 0x800);

    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    memset(sBg1TilemapBuffer, 0, 0x800);

    sBg2TilemapBuffer = Alloc(0x800);
    if (sBg2TilemapBuffer == NULL)
        return FALSE;
    memset(sBg2TilemapBuffer, 0, 0x800);

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sScreenshotsBgTemplates, NELEMS(sScreenshotsBgTemplates));
    SetBgTilemapBuffer(0, sBg0TilemapBuffer);
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    HideBg(0);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(1);
    return TRUE;
}

static bool8 Screenshots_LoadGraphics(void)
{
    switch (sScreenshotsDataPtr->gfxLoadState)
    {
    case 0:
        DebugPrintf("SS gfx tiles id=%u", sScreenshotsDataPtr->screenshotId);
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sScreenshotData[sScreenshotsDataPtr->screenshotId].screenshotTiles, 0, SCREENSHOT_TILE_OFFSET, 0);
        sScreenshotsDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DebugPrintf("SS gfx tilemap id=%u", sScreenshotsDataPtr->screenshotId);
            DecompressDataWithHeaderWram(sScreenshotData[sScreenshotsDataPtr->screenshotId].screenshotTilemap, sBg1TilemapBuffer);
            if (SCREENSHOT_TILE_OFFSET != 0)
                AddValToTilemapBuffer(sBg1TilemapBuffer, SCREENSHOT_TILE_OFFSET, 32, 20, FALSE);
            ScheduleBgCopyTilemapToVram(1);
            sScreenshotsDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        DebugPrintf("SS gfx palette id=%u", sScreenshotsDataPtr->screenshotId);
        LoadPalette(sScreenshotData[sScreenshotsDataPtr->screenshotId].screenshotPalette, 0, PLTT_SIZE_8BPP);
        // A screenshot palette spans all BG palette banks, including the live
        // textbox bank. Restore it before this frame reaches VBlank.
        if (sScreenshotsDataPtr->textBoxShown)
            LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(DLG_WINDOW_PALETTE_NUM), PLTT_SIZE_4BPP);
        sScreenshotsDataPtr->gfxLoadState++;
        break;
    default:
        sScreenshotsDataPtr->gfxLoadState = 0;
        return TRUE;
    }

    return FALSE;
}

static void Screenshots_InitWindows(void)
{
    if (sScreenshotsDataPtr->messageText == NULL)
    {
        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
        CopyBgTilemapBufferToVram(0);
        HideBg(0);
        sScreenshotsDataPtr->textBoxShown = FALSE;
        return;
    }

    InitStandardTextBoxWindows();
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    DeactivateAllTextPrinters();
    LoadMessageBoxGfx(0, SCREENSHOT_TEXTBOX_BASE_TILE, BG_PLTT_ID(DLG_WINDOW_PALETTE_NUM));
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
    CopyBgTilemapBufferToVram(0);
    DrawDialogFrameWithCustomTileAndPalette(0, TRUE, SCREENSHOT_TEXTBOX_BASE_TILE, DLG_WINDOW_PALETTE_NUM);
    PrintToWindow();
    CopyWindowToVram(0, COPYWIN_FULL);
    ShowBg(0);
    sScreenshotsDataPtr->textBoxShown = TRUE;
}

static void Screenshots_UpdateWindowsForReload(void)
{
    if (sScreenshotsDataPtr->messageText == NULL)
    {
        if (sScreenshotsDataPtr->textBoxShown)
        {
            FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
            CopyBgTilemapBufferToVram(0);
            HideBg(0);
            sScreenshotsDataPtr->textBoxShown = FALSE;
        }
        return;
    }

    if (!sScreenshotsDataPtr->textBoxShown)
    {
        Screenshots_InitWindows();
        return;
    }

    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(DLG_WINDOW_PALETTE_NUM), PLTT_SIZE_4BPP);
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    PrintToWindow();
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void PrintToWindow(void)
{
    StringExpandPlaceholders(gStringVar4, sScreenshotsDataPtr->messageText);
    AddTextPrinterForMessage(TRUE);
}

static void Task_ScreenshotsWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DebugPrintf("SS visible mode=%u", sScreenshotsDataPtr->screenshotMode);
        DebugPrintf("SS regs visible disp=%04X cnt=%04X y=%u", GetGpuReg(REG_OFFSET_DISPCNT), GetGpuReg(REG_OFFSET_BLDCNT), GetGpuReg(REG_OFFSET_BLDY));
        gTasks[taskId].func = Task_ScreenshotsMain;
    }
}

static void Task_ScreenshotsTurnOff(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DebugPrintf("SS return normal");
        SetMainCallback2(sScreenshotsDataPtr->savedCallback);
        Screenshots_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_ScreenshotsMain(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    bool8 hasMessage = (sScreenshotsDataPtr->messageText != NULL);

    #define AUTOCLOSE_TIMER data[0]
    #define AUTOCLOSE_DURATION 240

    if (hasMessage && IsTextPrinterActiveOnWindow(0))
        return;

    if (!hasMessage)
        AUTOCLOSE_TIMER++;

    if (JOY_NEW(B_BUTTON) || JOY_NEW(A_BUTTON) || (!hasMessage && AUTOCLOSE_TIMER >= AUTOCLOSE_DURATION))
    {
        DebugPrintf("SS close mode=%u timer=%d", sScreenshotsDataPtr->screenshotMode, AUTOCLOSE_TIMER);
        switch (sScreenshotsDataPtr->screenshotMode)
        {
        case WARP:
            BeginNormalPaletteFade(Screenshots_GetFadePaletteMask(), 0, 0, 16, Screenshots_GetFadeOutColor());
            gTasks[taskId].func = Task_ScreenshotsFadeToFieldExit;
            break;
        case CONTINUE:
        case START:
            gTasks[taskId].data[1] = (Screenshots_GetFadeOutColor() == RGB_WHITE);
            Screenshots_BeginSequenceFade(gTasks[taskId].data[1] ? FADE_TO_WHITE : FADE_TO_BLACK);
            gTasks[taskId].func = Task_ScreenshotsFadeToNext;
            break;
        case END:
        default:
            BeginNormalPaletteFade(Screenshots_GetFadePaletteMask(), 0, 0, 16, Screenshots_GetFadeOutColor());
            gTasks[taskId].func = Task_ScreenshotsTurnOff;
            break;
        }
    }

    #undef AUTOCLOSE_TIMER
    #undef AUTOCLOSE_DURATION
}

static void Task_ScreenshotsFadeToFieldExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DebugPrintf("SS return direct");
        BlendPalettes(Screenshots_GetFadePaletteMask(), 16, Screenshots_GetFadeOutColor());
        *(vu16 *)PLTT = Screenshots_GetFadeOutColor();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ScriptContext_Enable();
        SetMainCallback2(CB2_Overworld);
        Screenshots_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_ScreenshotsFadeToNext(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DebugPrintf("SS sequence next");
        sQueuedScreenshotReload = FALSE;
        ScriptContext_RunScript();
        if (sQueuedScreenshotReload)
        {
            gTasks[taskId].func = Task_ScreenshotsReload;
        }
        else
        {
            gTasks[taskId].func = Task_ScreenshotsTurnOff;
        }
    }
}

static void Task_ScreenshotsReload(u8 taskId)
{
    if (Screenshots_LoadGraphics() == TRUE)
    {
        gTasks[taskId].data[0] = 0;
        Screenshots_UpdateWindowsForReload();
        Screenshots_PlaySound();
        Screenshots_BeginSequenceFade(gTasks[taskId].data[1] ? FADE_FROM_WHITE : FADE_FROM_BLACK);
        gTasks[taskId].func = Task_ScreenshotsWaitFadeIn;
    }
}
