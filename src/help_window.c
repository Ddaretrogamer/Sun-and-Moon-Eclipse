#include "global.h"
#include "main.h"
#include "menu.h"
#include "string_util.h"
#include "sound.h"
#include "text.h"
#include "window.h"
#include "help_window.h"
#include "constants/songs.h"
#include "data/help_window.h"

static u8 helpWindowId = 0;
static const struct WindowTemplate sHelpWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 3,
    .width = 26,
    .height = 14,
    .paletteNum = 15,
    .baseBlock = 8
};
static bool8 sHelpWindowIsOpen = FALSE;
static bool8 sHelpWindowPlaySelectSound;

static bool8 WaitForHelpWindowAorBPress(void)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        if (sHelpWindowPlaySelectSound)
            PlaySE(SE_SELECT);
        return TRUE;
    }

    return FALSE;
}

static void DrawHelpInfoWindowText(u16 helpTutorialId)
{
    u32 xOffset = 0;
    u32 yOffset = 1;
    u8 headerColor[3] = {0, 8, 3};
    u8 headerFont = FONT_NORMAL;
    u8 descFont = FONT_SMALL;

    // Set non-default values if any
    if (gHelpWindowInfo[helpTutorialId].headerFont)
        headerFont = gHelpWindowInfo[helpTutorialId].headerFont;
    if (gHelpWindowInfo[helpTutorialId].descFont)
        descFont = gHelpWindowInfo[helpTutorialId].descFont;

    FillWindowPixelBuffer(helpWindowId, PIXEL_FILL(1));
    PutWindowTilemap(helpWindowId);
    DrawStdWindowFrame(helpWindowId, FALSE);

    // Header Text
    StringCopy(gStringVar4, gHelpWindowInfo[helpTutorialId].header);
    AddTextPrinterParameterized4(helpWindowId, headerFont, xOffset, yOffset, 0, 0, headerColor, 0, gStringVar4);
    yOffset += 16;

    // Description (can fiddle with text fonts and what not)
    StringCopy(gStringVar4, gHelpWindowInfo[helpTutorialId].desc);
    AddTextPrinterParameterized(helpWindowId, descFont, gStringVar4, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(helpWindowId, COPYWIN_FULL);
}

void ShowHelpInfoWindow(struct ScriptContext *ctx)
{
    u16 helpTutorialId = ScriptReadHalfword(ctx);
    u8 mode = ScriptReadByte(ctx);
    bool8 replace = (mode != 0);

    sHelpWindowPlaySelectSound = (mode == 1);

    if (!sHelpWindowIsOpen)
    {
        PlaySE(SE_RG_HELP_OPEN);
        helpWindowId = AddWindow(&sHelpWindowTemplate);
        sHelpWindowIsOpen = TRUE;
    }
    else if (!replace)
    {
        HideHelpInfoWindow();
        PlaySE(SE_RG_HELP_OPEN);
        helpWindowId = AddWindow(&sHelpWindowTemplate);
        sHelpWindowIsOpen = TRUE;
    }

    DrawHelpInfoWindowText(helpTutorialId);
}

void WaitForHelpWindowButtonPress(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    SetupNativeScript(ctx, WaitForHelpWindowAorBPress);
    ctx->waitAfterCallNative = TRUE;
}

void HideHelpInfoWindow(void)
{
    if (!sHelpWindowIsOpen)
        return;

    PlaySE(SE_RG_HELP_CLOSE);
    ClearStdWindowAndFrame(helpWindowId, FALSE);
    RemoveWindow(helpWindowId);
    sHelpWindowIsOpen = FALSE;
}
