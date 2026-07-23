#include "global.h"
#include "ui_screenshots.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
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
    const u8 *messageText;
    u16 playerIconSpriteId;
    u16 nameplateSpriteId[2];
    u16 cursorIconSpriteId;
    u16 selectedSeaSectionId;
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

//==========STATIC=DEFINES==========//
static void Screenshots_RunSetup(void);
static bool8 Screenshots_DoGfxSetup(void);
static bool8 Screenshots_InitBgs(void);
static void Screenshots_FadeAndBail(void);
static bool8 Screenshots_LoadGraphics(void);
static void Screenshots_InitWindows(void);
static void PrintToWindow(void);
static void Task_ScreenshotsWaitFadeIn(u8 taskId);
static void Task_ScreenshotsTurnOff(u8 taskId);
static void Task_ScreenshotsMain(u8 taskId);
static void Task_ScreenshotsFadeToBlackExit(u8 taskId);

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
    if (ctx != NULL)
    {
        ctx->waitAfterCallNative = TRUE;
        sPendingMessageText = (const u8 *)ScriptReadWord(ctx);
    }
    else
    {
        sPendingMessageText = NULL;
    }

    CleanupOverworldWindowsAndTilemaps();
    Screenshots_Init(CB2_ReturnToFieldContinueScript);
}

void Screenshots_Init(MainCallback callback)
{
    if ((sScreenshotsDataPtr = AllocZeroed(sizeof(struct ScreenshotsResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sScreenshotsDataPtr->gfxLoadState = 0;
    sScreenshotsDataPtr->savedCallback = callback;
    sScreenshotsDataPtr->messageText = sPendingMessageText;

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
        CreateTask(Task_ScreenshotsWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Screenshots_VBlankCB);
        SetMainCallback2(Screenshots_MainCB);
        return TRUE;
    }

    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
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
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_ScreenshotsWaitFadeAndBail, 0);
    SetVBlankCallback(Screenshots_VBlankCB);
    SetMainCallback2(Screenshots_MainCB);
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
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sScreenshotData[gSpecialVar_0x8003].screenshotTiles, 0, SCREENSHOT_TILE_OFFSET, 0);
        sScreenshotsDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(sScreenshotData[gSpecialVar_0x8003].screenshotTilemap, sBg1TilemapBuffer);
            if (SCREENSHOT_TILE_OFFSET != 0)
                AddValToTilemapBuffer(sBg1TilemapBuffer, SCREENSHOT_TILE_OFFSET, 32, 20, FALSE);
            ScheduleBgCopyTilemapToVram(1);
            sScreenshotsDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sScreenshotData[gSpecialVar_0x8003].screenshotPalette, 0, PLTT_SIZE_8BPP);
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
}

static void PrintToWindow(void)
{
    StringExpandPlaceholders(gStringVar4, sScreenshotsDataPtr->messageText);
    AddTextPrinterForMessage(TRUE);
}

static void Task_ScreenshotsWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_ScreenshotsMain;
}

static void Task_ScreenshotsTurnOff(u8 taskId)
{
    if (!gPaletteFade.active)
    {
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
        switch (VarGet(VAR_RESULT))
        {
        case 1:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_ScreenshotsFadeToBlackExit;
            break;
        default:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_ScreenshotsTurnOff;
            break;
        }
    }

    #undef AUTOCLOSE_TIMER
    #undef AUTOCLOSE_DURATION
}

static void Task_ScreenshotsFadeToBlackExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        *(u16 *)PLTT = RGB_BLACK;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ScriptContext_Enable();
        SetMainCallback2(CB2_Overworld);
        Screenshots_FreeResources();
        DestroyTask(taskId);
    }
}
