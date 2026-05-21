#include "global.h"
#include "option_plus_menu.h"
#include "main.h"
#include "menu.h"
#include "scanline_effect.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "malloc.h"
#include "bg.h"
#include "gpu_regs.h"
#include "window.h"
#include "text.h"
#include "text_window.h"
#include "international_string_util.h"
#include "strings.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "menu_helpers.h"
#include "decompress.h"
#include "heat_start_menu.h"
#include "event_data.h"
#include "followmon.h"
#include "rotom_start_menu.h"
#include "transform.h"

enum
{
    MENU_VANILLA, // General - non battle and non sound related, basically everything else
    MENU_CUSTOM,  // Battle - anything that affects battles
    MENU_COUNT,
};

// Menu items
// Vanilla options
enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

// Custom options
enum
{
    MENUITEM_MENUPAL,
    MENUITEM_FOLLOWER,
    MENUITEM_BATTLESPEED,
    MENUITEM_OW_ENCOUNTERS,
    MENUITEM_AUTORUN,
    MENUITEM_TITLESCREEN,
    MENUITEM_CANCEL_PG2,
    MENUITEM_COUNT_PG2,
};


// Window Ids
enum
{
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {//WIN_TOPBAR
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 2,
        .baseBlock = 2
    },
    {//WIN_OPTIONS
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62
    },
    {//WIN_DESCRIPTION
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
    },
    {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
    },
    {
       .bg = 2,
       .charBaseIndex = 0,
       .mapBaseIndex = 29,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
    },
    {
       .bg = 3,
       .charBaseIndex = 3,
       .mapBaseIndex = 28,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
    },
};

struct OptionMenu
{
    u8 submenu;
    u8 sel_vanilla[MENUITEM_COUNT];
    u8 sel_custom[MENUITEM_COUNT_PG2];
    int menuCursor[MENU_COUNT];
    int visibleCursor[MENU_COUNT];
    u8 arrowTaskId;
    u8 gfxLoadState;
};

#define Y_DIFF 16 // Difference in pixels between items.
#define OPTIONS_ON_SCREEN 5
#define NUM_OPTIONS_FROM_BORDER 1

// local functions
static void MainCB2(void);
static void VBlankCB(void);
static void DrawTopBarText(void); //top Option text
static void DrawLeftSideOptionText(int selection, int y);
static void DrawRightSideChoiceText(const u8 *str, int x, int y, bool8 choosen, bool8 active);
static void DrawOptionMenuTexts(void); //left side text;
static void DrawChoices(u32 id, int y); //right side draw function
static void HighlightOptionMenuItem(void);
static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void ScrollMenu(int direction);
static void ScrollAll(int direction); // to bottom or top
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3);
static int XOptions_ProcessInput(int x, int selection);
static int TwoOptions_ProcessInput(int selection);
static int ThreeOptions_ProcessInput(int selection);
static int FourOptions_ProcessInput(int selection);
static int FiveOptions_ProcessInput(int selection);
static int SixteenOptions_ProcessInput(int selection);
static int UNUSED ElevenOptions_ProcessInput(int selection);
static int Sound_ProcessInput(int selection);
static int FrameType_ProcessInput(int selection);
static const u8 *const OptionTextDescription(void);
static const u8 *const OptionTextRight(u8 menuItem);
static u8 MenuItemCount(void);
static u8 MenuItemCancel(void);
static void DrawDescriptionText(void);
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active);
static void UNUSED DrawChoices_Options_Three(const u8 *const *const strings, int selection, int y, bool8 active);
static void ReDrawAll(void);
static void TextSpeed_DrawChoicesTwo(int selection, int y);
static void FrameType_DrawChoices(int selection, int y);
static void BattleScene_DrawChoices(int selection, int y);
static void BattleStyle_DrawChoices(int selection, int y);
static void SoundMode_DrawChoices(int selection, int y);
static void DrawChoices_Follower(int selection, int y);
static void BattleSpeed_DrawChoices(int selection, int y);
static void DrawChoices_AutoRun(int selection, int y);
static int ProcessInput_AutoRun(int selection);
static int UNUSED ProcessInput_MenuPal(int selection);
static void DrawChoices_MenuPal(int selection, int y);
static void DrawChoices_OW_Encounters(int selection, int y);
static void DrawChoices_TitleScreen(int selection, int y);
static int BattleSpeed_ProcessInput_New(int selection);
static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active);
static void DrawChoices_TextSpeed(int selection, int y);
static void DrawBgWindowFrames(void);

EWRAM_DATA static u8 sCurrPage = 0;

// EWRAM vars
EWRAM_DATA static struct OptionMenu *sOptions = NULL;
static EWRAM_DATA u8 *sBg2TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg3TilemapBuffer = NULL;

// const data
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp"); // note: this is only used in the Japanese release
static const u16 sOptionMenuBg_Pal[] = {RGB(0, 0, 0)};
static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

static const u32 sOptionsPlusTiles[] = INCBIN_U32("graphics/ui_options_plus/options_plus_tiles.4bpp.lz");
static const u16 sOptionsPlusPalette[] = INCBIN_U16("graphics/ui_options_plus/options_plus_tiles.gbapal");
static const u32 sOptionsPlusTilemap[] = INCBIN_U32("graphics/ui_options_plus/options_plus_tiles.bin.lz");

// Scrolling Background
static const u32 sScrollBgTiles[] = INCBIN_U32("graphics/ui_options_plus/waterscrollscaletwo.4bpp.lz");
static const u32 sScrollBgTilemap[] = INCBIN_U32("graphics/ui_options_plus/waterscrollscaletwo.bin.lz");
static const u16 sScrollBgPalette[] = INCBIN_U16("graphics/ui_options_plus/waterscrollscaletwo.gbapal");

#define TEXT_COLOR_OPTIONS_WHITE                1
#define TEXT_COLOR_OPTIONS_GRAY_FG              2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW          3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG        4
#define TEXT_COLOR_OPTIONS_ORANGE_FG            5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW        6
#define TEXT_COLOR_OPTIONS_RED_FG               7
#define TEXT_COLOR_OPTIONS_RED_SHADOW           8
#define TEXT_COLOR_OPTIONS_GREEN_FG             9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW         10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG        11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW    12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG          13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW      14

// Menu draw and input functions
typedef struct {
    void (*drawChoices)(int selection, int y);
    int (*processInput)(int selection);
} MenuItemFunctions;


static const MenuItemFunctions sItemFunctionsVanilla[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]  = {DrawChoices_TextSpeed,   FourOptions_ProcessInput},
    [MENUITEM_BATTLESCENE]   = {BattleScene_DrawChoices,    TwoOptions_ProcessInput},
    [MENUITEM_BATTLESTYLE]    = {BattleStyle_DrawChoices,     TwoOptions_ProcessInput},
    [MENUITEM_SOUND]    = {SoundMode_DrawChoices,     Sound_ProcessInput},
    [MENUITEM_FRAMETYPE]    = {FrameType_DrawChoices,     FrameType_ProcessInput},
    [MENUITEM_CANCEL]       = {NULL, NULL},
};

static const MenuItemFunctions sItemFunctionsCustom[MENUITEM_COUNT_PG2] =
{
    [MENUITEM_MENUPAL]       = {DrawChoices_MenuPal,   SixteenOptions_ProcessInput},
    [MENUITEM_FOLLOWER]  = {DrawChoices_Follower,    TwoOptions_ProcessInput},
    [MENUITEM_BATTLESPEED]  = {BattleSpeed_DrawChoices,    BattleSpeed_ProcessInput_New},
    [MENUITEM_OW_ENCOUNTERS] = {DrawChoices_OW_Encounters,    TwoOptions_ProcessInput},
    [MENUITEM_AUTORUN]  = {DrawChoices_AutoRun,    ProcessInput_AutoRun},
    [MENUITEM_TITLESCREEN] = {DrawChoices_TitleScreen,    FiveOptions_ProcessInput},
    [MENUITEM_CANCEL_PG2]       = {NULL, NULL},
};


static const u8 *const sOptionMenuItemsNamesVanilla[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = gText_TextSpeed,
    [MENUITEM_BATTLESCENE] = gText_BattleScene,
    [MENUITEM_BATTLESTYLE] = gText_BattleStyle,
    [MENUITEM_SOUND]       = gText_Sound,
    [MENUITEM_FRAMETYPE]   = gText_Frame,
    [MENUITEM_CANCEL]       = gText_OptionMenuSave,
};

static const u8 *const sOptionMenuItemsNamesCustom[MENUITEM_COUNT_PG2] =
{
    [MENUITEM_MENUPAL]        = gText_MenuColor,
    [MENUITEM_FOLLOWER]        = gText_Follower,
    [MENUITEM_BATTLESPEED]     = gText_BattleSpeed,
    [MENUITEM_OW_ENCOUNTERS]   = gText_OW_Encounter,
    [MENUITEM_AUTORUN]         = gText_AutoRun,
    [MENUITEM_TITLESCREEN]     = gText_TitleScreen,
    [MENUITEM_CANCEL_PG2]        = gText_OptionMenuSave,
};

static const u8 *const OptionTextRight(u8 menuItem)
{
    switch (sOptions->submenu)
    {
    case MENU_CUSTOM:
        return sOptionMenuItemsNamesCustom[menuItem];
    default:
    case MENU_VANILLA:
        return sOptionMenuItemsNamesVanilla[menuItem];
    }
}

// Menu left side text conditions
static bool8 CheckConditions(int selection)
{
    switch (sOptions->submenu)
    {  
    case MENU_VANILLA:
        switch(selection)
        {  
        case MENUITEM_TEXTSPEED:
        case MENUITEM_BATTLESCENE:
        case MENUITEM_BATTLESTYLE:
        case MENUITEM_SOUND:
        case MENUITEM_FRAMETYPE:
        case MENUITEM_CANCEL:
        case MENUITEM_COUNT:
            return TRUE;
        }
    case MENU_CUSTOM:
        switch(selection)
        {  
        case MENUITEM_OW_ENCOUNTERS:
            return FlagGet(FLAG_ENABLE_OW_MON_OPTION);
        case MENUITEM_MENUPAL:
        case MENUITEM_FOLLOWER:
        case MENUITEM_BATTLESPEED:
        case MENUITEM_AUTORUN:
        case MENUITEM_TITLESCREEN:
        case MENUITEM_CANCEL_PG2:
        case MENUITEM_COUNT_PG2:
            return TRUE;
        }
    }
    return FALSE;
}


// Descriptions
static const u8 sText_Empty[]                   = _("");
static const u8 sText_Desc_Save[]               = _("Save your settings.");

static const u8 sText_Desc_InstantTextOn[]      = _("Instant text is enabled.");
static const u8 sText_Desc_InstantTextOff[]     = _("Instant text is disabled.");
static const u8 sText_Desc_TextSpeedSlow[]     = _("Text will be displayed slowly.");
static const u8 sText_Desc_TextSpeedMedium[]      = _("Text will be displayed at a\nmedium speed.");
static const u8 sText_Desc_TextSpeedFast[]      = _("Text will be displayed quickly.");
static const u8 sText_Desc_TextSpeedFaster[]    = _("Text will be displayed at the\nfastest speed possible.");
static const u8 sText_Desc_MenuPal[]            = _("Choose the color of your\nRotom Phone.");
static const u8 sText_Desc_Follower_On[]         = _("Your POKéMON will follow you\nin the overworld.");
static const u8 sText_Desc_Follower_Off[]        = _("Your POKéMON will not follow you\nin the overworld.");
static const u8 sText_Desc_OW_On[]            = _("Wild POKéMON will appear in the\noverworld.");
static const u8 sText_Desc_OW_Off[]           = _("Wild POKéMON will not appear in the\noverworld.");
static const u8 sText_Desc_TS_Solgaleo[]       = _("The title screen will display\nSOLGALEO.");
static const u8 sText_Desc_TS_Lunala[]         = _("The title screen will display\nLUNALA.");
static const u8 sText_Desc_TS_Necrozma[]       = _("The title screen will display\nNECROZMA.");
static const u8 sText_Desc_TS_Time[]            = _("The title screen will change\nbased on the time of day.");
static const u8 sText_Desc_TS_Random[]          = _("The title screen will change\nrandomly each time you start the game.");
static const u8 sText_Desc_FrameType[]          = _("Choose the frame surrounding the\nwindows.");
static const u8 sText_Desc_MatchCallOn[]        = _("TRAINERs will be able to call you,\noffering rematches and info.");
static const u8 sText_Desc_MatchCallOff[]       = _("You will not receive calls.\nSpecial events will still occur.");
static const u8 sText_Desc_Autorun_Toggle[]     = _("Toggle between running and walking\nby pressing the {B_BUTTON} button.");
static const u8 sText_Desc_Autorun_Hold[]       = _("Hold the {B_BUTTON} button to run.");
static const u8 sText_Desc_BattleScene_On[]     = _("Show the POKéMON battle animations.");
static const u8 sText_Desc_BattleScene_Off[]    = _("Skip the POKéMON battle animations.");
static const u8 sText_Desc_BattleStyle_Shift[]  = _("Get the option to switch your\nPOKéMON after the enemies faints.");
static const u8 sText_Desc_BattleStyle_Set[]    = _("No free switch after fainting the\nenemies POKéMON.");
static const u8 sText_Desc_BagUse_On[]          = _("Enables the use of items from the\nbag.");
static const u8 sText_Desc_BagUse_Off[]         = _("Disables the use of items from the\nbag.");
static const u8 sText_Desc_QuickRunOptionR[]    = _("Run from wild battles by pressing\nthe {R_BUTTON} button.");
static const u8 sText_Desc_QuickRunOptionBA[]   = _("Move the cursor to RUN by pressing\nthe {B_BUTTON} button.");
static const u8 sText_Desc_QuickRunOptionOff[]  = _("Disables quick running from wild\nbattles.");
static const u8 sText_Desc_DoubleBattles_On[]   = _("All Trainer battles will be double\nbattles.");
static const u8 sText_Desc_DoubleBattles_Off[]  = _("All Trainer battles will be single\nbattles, unless forced.");
static const u8 sText_Desc_MoveInfo_On[]        = _("Shows a window with information of\nmoves.");
static const u8 sText_Desc_MoveInfo_Off[]       = _("Disables move information window.");
static const u8 sText_Desc_BattleSpeed_1x[]     = _("Battle animations will play at default\nspeed.");
static const u8 sText_Desc_BattleSpeed_2x[]     = _("Battle animations will play at 2x\nspeed.");
static const u8 sText_Desc_BattleSpeed_3x[]     = _("Battle animations will play at 3x\nspeed.");
static const u8 sText_Desc_BattleSpeed_4x[]     = _("Battle animations will play at 4x\nspeed.");

static const u8 sText_Desc_SoundMono[]          = _("Sound is the same in all speakers.\nRecommended for original hardware.");
static const u8 sText_Desc_SoundStereo[]        = _("Play the left and right audio channel\nseperatly. Great with headphones.");
static const u8 sText_Desc_BikeMusicOn[]        = _("Bike theme music will play\nwhile cycling.");
static const u8 sText_Desc_BikeMusicOff[]       = _("Normal route music continues\nwhile cycling.");
static const u8 sText_Desc_SurfMusicOn[]        = _("Surf theme music will play\nwhile on water.");
static const u8 sText_Desc_SurfMusicOff[]       = _("Normal water route music continues\nwhile surfing.");

static const u8 *const sOptionMenuItemDescriptionsVanilla[MENUITEM_COUNT][4] =
{
    [MENUITEM_TEXTSPEED] = {sText_Desc_TextSpeedSlow, sText_Desc_TextSpeedMedium,  sText_Desc_TextSpeedFast, sText_Desc_TextSpeedFaster},
    [MENUITEM_BATTLESCENE]  = {sText_Desc_BattleScene_On,       sText_Desc_BattleScene_Off,       sText_Empty, sText_Empty},
    [MENUITEM_BATTLESTYLE]  = {sText_Desc_BattleStyle_Shift,    sText_Desc_BattleStyle_Set,       sText_Empty, sText_Empty},
    [MENUITEM_SOUND]     = {sText_Desc_SoundMono,            sText_Desc_SoundStereo,            sText_Empty, sText_Empty},
    [MENUITEM_FRAMETYPE]   = {sText_Desc_FrameType,            sText_Empty,                     sText_Empty, sText_Empty},
    [MENUITEM_CANCEL]      = {sText_Desc_Save,                 sText_Empty,                     sText_Empty, sText_Empty},
};

static const u8 *const sOptionMenuItemDescriptionsCustom[MENUITEM_COUNT_PG2][5] =
{

    [MENUITEM_MENUPAL] = {sText_Desc_MenuPal,            sText_Empty,                      sText_Empty,                    sText_Empty, sText_Empty,},
    [MENUITEM_FOLLOWER] = {sText_Desc_Follower_On,        sText_Desc_Follower_Off,          sText_Empty,                    sText_Empty, sText_Empty,},
    [MENUITEM_BATTLESPEED]  = {sText_Desc_BattleSpeed_1x,       sText_Desc_BattleSpeed_2x,        sText_Desc_BattleSpeed_3x,      sText_Desc_BattleSpeed_4x, sText_Empty,},
    [MENUITEM_OW_ENCOUNTERS] = {sText_Desc_OW_On,            sText_Desc_OW_Off,                sText_Empty,                    sText_Empty, sText_Empty,},
    [MENUITEM_AUTORUN] = {sText_Desc_Autorun_Hold,     sText_Desc_Autorun_Toggle,          sText_Empty,                    sText_Empty, sText_Empty,},
    [MENUITEM_TITLESCREEN] = {sText_Desc_TS_Necrozma,            sText_Desc_TS_Solgaleo,              sText_Desc_TS_Lunala,                    sText_Desc_TS_Random, sText_Desc_TS_Time,},
    [MENUITEM_CANCEL_PG2]       = {sText_Desc_Save,                 sText_Empty,                      sText_Empty,                    sText_Empty, sText_Empty,},
};



// Disabled Descriptions
static const u8 sText_Desc_Disabled_Textspeed[]     = _("Only active if xyz.");
static const u8 *const sOptionMenuItemDescriptionsDisabledVanilla[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = sText_Empty,
    [MENUITEM_BATTLESCENE] = sText_Empty,
    [MENUITEM_BATTLESTYLE] = sText_Empty,
    [MENUITEM_SOUND]       = sText_Empty,
    [MENUITEM_FRAMETYPE]   = sText_Empty,
    [MENUITEM_CANCEL]      = sText_Empty,
};

static const u8 *const sOptionMenuItemDescriptionsDisabledCustom[MENUITEM_COUNT_PG2] =
{
    [MENUITEM_MENUPAL]     = sText_Empty,
    [MENUITEM_FOLLOWER]    = sText_Empty,
    [MENUITEM_BATTLESPEED] = sText_Empty,
    [MENUITEM_OW_ENCOUNTERS] = sText_Empty,
    [MENUITEM_AUTORUN]     = sText_Empty,
    [MENUITEM_TITLESCREEN] = sText_Empty,
    [MENUITEM_CANCEL_PG2]      = sText_Empty,
};



static const u8 *const OptionTextDescription(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu];
    u8 selection;

    switch (sOptions->submenu)
    {
    case MENU_CUSTOM:
        if (menuItem >= MENUITEM_COUNT_PG2 || !CheckConditions(menuItem))
            return sOptionMenuItemDescriptionsDisabledCustom[menuItem];
        selection = sOptions->sel_custom[menuItem];
        if (menuItem == MENUITEM_MENUPAL)
            selection = 0; 
        return sOptionMenuItemDescriptionsCustom[menuItem][selection];
    default:
    case MENU_VANILLA:
        if (menuItem >= MENUITEM_COUNT || !CheckConditions(menuItem))
            return sOptionMenuItemDescriptionsDisabledVanilla[menuItem];
        selection = sOptions->sel_vanilla[menuItem];
        if (menuItem == MENUITEM_FRAMETYPE)
            selection = 0;
        return sOptionMenuItemDescriptionsVanilla[menuItem][selection];
    }
}

static u8 MenuItemCount(void)
{
    switch (sOptions->submenu)
    {
    case MENU_CUSTOM:
        return MENUITEM_COUNT_PG2;
    default:
    case MENU_VANILLA:
        return MENUITEM_COUNT;
    }
}

static u8 MenuItemCancel(void)
{
    switch (sOptions->submenu)
    {
    case MENU_CUSTOM:
        return MENUITEM_CANCEL_PG2;
    default:
    case MENU_VANILLA:
        return MENUITEM_CANCEL;
    }
}

// Main code
static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ChangeBgY(3, 96, BG_COORD_SUB);
}

static const u8 sText_TopBar_Vanilla[]         = _("VANILLA");
static const u8 sText_TopBar_General_Right[]   = _("{R_BUTTON}CUSTOM");
static const u8 sText_TopBar_General_Left[]    = _("{L_BUTTON}CUSTOM");
static const u8 sText_TopBar_Custom[]          = _("CUSTOM");
static const u8 sText_TopBar_Battle_Left[]     = _("{L_BUTTON}VANILLA");
static const u8 sText_TopBar_Battle_Right[]    = _("{R_BUTTON}VANILLA");
static const u8 sText_TopBar_Sound[]           = _("SOUND");
static const u8 sText_TopBar_Sound_Left[]      = _("{L_BUTTON}BATTLE");
static const u8 sText_TopBar_Sound_Right[]     = _("{R_BUTTON}GENERAL");
static void DrawTopBarText(void)
{
    const u8 color[3] = { 0, TEXT_COLOR_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(7));
    switch (sOptions->submenu)
    {
        case MENU_VANILLA:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 105, 1, color, 0, sText_TopBar_Vanilla);
            //AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 2, 1, color, 0, sText_TopBar_General_Left);  // Show L to go to SOUND
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 190, 1, color, 0, sText_TopBar_General_Right);
            break;
        case MENU_CUSTOM:
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 105, 1, color, 0, sText_TopBar_Custom);
            AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 2, 1, color, 0, sText_TopBar_Battle_Left);
            //AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 190, 1, color, 0, sText_TopBar_Battle_Right);
            break;
    }
    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void) //left side text
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(0));
    for (i = 0; i < MenuItemCount(); i++)
        DrawLeftSideOptionText(i, (i * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawDescriptionText(void)
{
    u8 color_gray[3];
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;
        
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL, 8, 1, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextDescription());
    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawLeftSideOptionText(int selection, int y)
{
    u8 color_yellow[3];
    u8 color_gray[3];

    color_yellow[0] = TEXT_COLOR_TRANSPARENT;
    color_yellow[1] = TEXT_COLOR_WHITE;
    color_yellow[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
    color_gray[0] = TEXT_COLOR_TRANSPARENT;
    color_gray[1] = TEXT_COLOR_WHITE;
    color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_SHADOW;

    if (CheckConditions(selection))
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_yellow, TEXT_SKIP_DRAW, OptionTextRight(selection));
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, 8, y, 0, 0, color_gray, TEXT_SKIP_DRAW, OptionTextRight(selection));
}

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 choosen, bool8 active)
{
    u8 color_red[3];
    u8 color_gray[3];

    if (active)
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_ORANGE_FG;
        color_red[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_WHITE;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
    }
    else
    {
        color_red[0] = TEXT_COLOR_TRANSPARENT;
        color_red[1] = TEXT_COLOR_OPTIONS_WHITE;
        color_red[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
        color_gray[0] = TEXT_COLOR_TRANSPARENT;
        color_gray[1] = TEXT_COLOR_OPTIONS_WHITE;
        color_gray[2] = TEXT_COLOR_OPTIONS_GRAY_FG;
    }

    if (choosen)
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_red, TEXT_SKIP_DRAW, text);
    else
        AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color_gray, TEXT_SKIP_DRAW, text);
}

static void DrawChoices(u32 id, int y) //right side draw function
{
    switch (sOptions->submenu)
    {
        case MENU_VANILLA:
            if (sItemFunctionsVanilla[id].drawChoices != NULL)
                sItemFunctionsVanilla[id].drawChoices(sOptions->sel_vanilla[id], y);
            break;
        case MENU_CUSTOM:
            if (sItemFunctionsCustom[id].drawChoices != NULL)
                sItemFunctionsCustom[id].drawChoices(sOptions->sel_custom[id], y);
            break;
    }
}

static void HighlightOptionMenuItem(void)
{
    int cursor = sOptions->visibleCursor[sOptions->submenu];

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(8, 232));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(cursor * Y_DIFF + 24, cursor * Y_DIFF + 40));
}

static bool8 OptionsMenu_LoadGraphics(void) // Load all the tilesets, tilemaps, spritesheets, and palettes
{
    switch (sOptions->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sOptionsPlusTiles, 0, 0, 0);
        sOptions->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderVram(sOptionsPlusTilemap, sBg2TilemapBuffer);
            sOptions->gfxLoadState++;
        }
        break;
    case 2:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(3, sScrollBgTiles, 0, 0, 0);
        sOptions->gfxLoadState++;
        break;
    case 3:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderVram(sScrollBgTilemap, sBg3TilemapBuffer);
            sOptions->gfxLoadState++;
        }
        break;
    case 4:
        LoadPalette(sOptionsPlusPalette, 64, 32);
        LoadPalette(sScrollBgPalette, 32, 32);
        sOptions->gfxLoadState++;
        break;
    default:
        sOptions->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

void CB2_InitOptionPlusMenu(void)
{
    u32 i;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        ResetVramOamAndBgCntRegs();
        sOptions = AllocZeroed(sizeof(*sOptions));
        FreeAllSpritePalettes();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        ResetBgPositions();
        
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG2);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);
        
        ResetAllBgsCoordinates();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, NELEMS(sOptionMenuBgTemplates));
        InitWindows(sOptionMenuWinTemplates);

        sBg2TilemapBuffer = Alloc(0x800);
        memset(sBg2TilemapBuffer, 0, 0x800);
        SetBgTilemapBuffer(2, sBg2TilemapBuffer);
        ScheduleBgCopyTilemapToVram(2);

        sBg3TilemapBuffer = Alloc(0x800);
        memset(sBg3TilemapBuffer, 0, 0x800);
        SetBgTilemapBuffer(3, sBg3TilemapBuffer);
        ScheduleBgCopyTilemapToVram(3);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        gMain.state++;
        sOptions->gfxLoadState = 0;
        break;
    case 3:
        if (OptionsMenu_LoadGraphics() == TRUE)
        {
            gMain.state++;
            LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        }
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, 0, sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, 16, sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        sOptions->sel_vanilla[MENUITEM_TEXTSPEED]   = gSaveBlock2Ptr->optionsTextSpeed;
        sOptions->sel_vanilla[MENUITEM_BATTLESCENE] = gSaveBlock2Ptr->optionsBattleSceneOff;
        sOptions->sel_vanilla[MENUITEM_BATTLESTYLE] = gSaveBlock2Ptr->optionsBattleStyle;
        sOptions->sel_vanilla[MENUITEM_SOUND]       = gSaveBlock2Ptr->optionsSound;
        sOptions->sel_vanilla[MENUITEM_FRAMETYPE]   = gSaveBlock2Ptr->optionsWindowFrameType;
    
        sOptions->sel_custom[MENUITEM_MENUPAL]       = gSaveBlock2Ptr->optionsRotomPhonePalette;
        sOptions->sel_custom[MENUITEM_FOLLOWER]     = !FlagGet(FLAG_FOLLOWERS_MENU_TOGGLE);
        sOptions->sel_custom[MENUITEM_BATTLESPEED]  = gSaveBlock2Ptr->optionsBattleSpeed;
        sOptions->sel_custom[MENUITEM_OW_ENCOUNTERS] = FlagGet(FLAG_ENABLE_OW_MON_OPTION)
            ? !(FlagGet(OW_FLAG_SPAWN_OVERWORLD_MON) && FlagGet(FLAG_OW_NO_ENCOUNTER))
            : 1;
        sOptions->sel_custom[MENUITEM_AUTORUN]      = FlagGet(FLAG_AUTORUN_MENU_TOGGLE) ? 0 : 1;
        sOptions->sel_custom[MENUITEM_TITLESCREEN]  = gSaveBlock2Ptr->optionsTitleScreenPokemon;

        sOptions->submenu = sCurrPage; // Restore last page

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        DrawTopBarText();
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawDescriptionText();
        gMain.state++;
        break;
    case 9:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
        break;
    case 10:
        u8 UNUSED taskId = CreateTask(Task_OptionMenuFadeIn, 0); // No idea, but sure, ig
        
        sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MENUITEM_COUNT - 1, 110, 110, 0);

        for (i = 0; i < min(OPTIONS_ON_SCREEN, MenuItemCount()); i++)
            DrawChoices(i, i * Y_DIFF);

        HighlightOptionMenuItem();

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    case 11:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 12:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_OptionMenuProcessInput;
        SetGpuReg(REG_OFFSET_WIN0H, 0); // Idk man Im just trying to stop this stupid graphical bug from happening dont judge me
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG2);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        HighlightOptionMenuItem();
        return;
    }
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN , MenuItemCount());
    if (JOY_NEW(A_BUTTON))
    {
        if (sOptions->menuCursor[sOptions->submenu] == MenuItemCancel())
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == NUM_OPTIONS_FROM_BORDER) // don't advance visible cursor until scrolled to the bottom
        {
            if (--sOptions->menuCursor[sOptions->submenu] == 0)
                sOptions->visibleCursor[sOptions->submenu]--;
            else
                ScrollMenu(1);
        }
        else
        {
            if (--sOptions->menuCursor[sOptions->submenu] < 0) // Scroll all the way to the bottom.
            {
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = optionsToDraw-2;
                ScrollAll(0);
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-1;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - 1;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]--;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOptions->visibleCursor[sOptions->submenu] == optionsToDraw-2) // don't advance visible cursor until scrolled to the bottom
        {
            if (++sOptions->menuCursor[sOptions->submenu] == MenuItemCount() - 1)
                sOptions->visibleCursor[sOptions->submenu]++;
            else
                ScrollMenu(0);
        }
        else
        {
            if (++sOptions->menuCursor[sOptions->submenu] >= MenuItemCount()-1) // Scroll all the way to the top.
            {
                sOptions->visibleCursor[sOptions->submenu] = optionsToDraw-2;
                sOptions->menuCursor[sOptions->submenu] = MenuItemCount() - optionsToDraw-1;
                ScrollAll(1);
                sOptions->visibleCursor[sOptions->submenu] = sOptions->menuCursor[sOptions->submenu] = 0;
            }
            else
            {
                sOptions->visibleCursor[sOptions->submenu]++;
            }
        }
        HighlightOptionMenuItem();
        DrawDescriptionText();
    }
    else if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        switch (sOptions->submenu)
        {
            case MENU_VANILLA:
            {
                int cursor = sOptions->menuCursor[sOptions->submenu];
                u8 previousOption = sOptions->sel_vanilla[cursor];
                if (CheckConditions(cursor))
                {
                    if (sItemFunctionsVanilla[cursor].processInput != NULL)
                    {
                        sOptions->sel_vanilla[cursor] = sItemFunctionsVanilla[cursor].processInput(previousOption);
                        ReDrawAll();
                        DrawDescriptionText();
                    }

                    if (previousOption != sOptions->sel_vanilla[cursor])
                        DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
                }
                break;
            }
            case MENU_CUSTOM:
            {
                int cursor = sOptions->menuCursor[sOptions->submenu];
                u8 previousOption = sOptions->sel_custom[cursor];   
                if (CheckConditions(cursor))
                {
                    if (sItemFunctionsCustom[cursor].processInput != NULL)
                    {
                        sOptions->sel_custom[cursor] = sItemFunctionsCustom[cursor].processInput(previousOption);
                        ReDrawAll();
                        DrawDescriptionText();
                    }

                    if (previousOption != sOptions->sel_custom[cursor])
                        DrawChoices(cursor, sOptions->visibleCursor[sOptions->submenu] * Y_DIFF);
                }
                break;
            }
        }
    }
    else if (JOY_NEW(R_BUTTON))
    {
        // Move from VANILLA to CUSTOM only
        if (sOptions->submenu == MENU_VANILLA)
        {
            sOptions->submenu = MENU_CUSTOM;
            sCurrPage = MENU_CUSTOM; // Remember last page
            DrawTopBarText();
            ReDrawAll();
            HighlightOptionMenuItem();
            DrawDescriptionText();
        }
        // If already MENU_CUSTOM, do nothing.
    }
    else if (JOY_NEW(L_BUTTON))
    {
        // Move from CUSTOM to VANILLA only
        if (sOptions->submenu == MENU_CUSTOM)
        {
            sOptions->submenu = MENU_VANILLA;
            sCurrPage = MENU_VANILLA;
            DrawTopBarText();
            ReDrawAll();
            HighlightOptionMenuItem();
            DrawDescriptionText();
        }
        // If already MENU_VANILLA, do nothing.
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    // These options are part of the original vanilla set,
    // and are mapped from sOptions->sel_vanilla to gSaveBlock2Ptr.
    gSaveBlock2Ptr->optionsTextSpeed        = sOptions->sel_vanilla[MENUITEM_TEXTSPEED];
    gSaveBlock2Ptr->optionsBattleSceneOff   = sOptions->sel_vanilla[MENUITEM_BATTLESCENE];
    gSaveBlock2Ptr->optionsBattleStyle      = sOptions->sel_vanilla[MENUITEM_BATTLESTYLE];
    gSaveBlock2Ptr->optionsSound            = sOptions->sel_vanilla[MENUITEM_SOUND];
    gSaveBlock2Ptr->optionsWindowFrameType  = sOptions->sel_vanilla[MENUITEM_FRAMETYPE];

    // These options (BattleSpeed and StartMenuPalette) are now
    // explicitly mapped from sOptions->sel_custom to gSaveBlock2Ptr.
    gSaveBlock2Ptr->optionsBattleSpeed      = sOptions->sel_custom[MENUITEM_BATTLESPEED];
    gSaveBlock2Ptr->optionsRotomPhonePalette = sOptions->sel_custom[MENUITEM_MENUPAL];
    gSaveBlock2Ptr->optionsTitleScreenPokemon = sOptions->sel_custom[MENUITEM_TITLESCREEN];

    // Handle Follower option (flag-based)
    // If sOptions->sel_custom[MENUITEM_FOLLOWER] is 0 (ON), clear the disable flag.
    // If it's 1 (OFF), set the disable flag.
    // BUT: Don't change FLAG_DISABLE_FOLLOWERS if player is transformed - let transform system manage it
    if (sOptions->sel_custom[MENUITEM_FOLLOWER] == 0) // Assuming 0 means Followers are ON
    {
        FlagSet(FLAG_FOLLOWERS_MENU_TOGGLE);
        if (!IsPlayerTransformed())  // Only enable if not transformed
        {
            FlagClear(FLAG_DISABLE_FOLLOWERS); // Enable followers
        }
    }
    else // sOptions->sel_custom[MENUITEM_FOLLOWER] == 1, meaning OFF
    {
        FlagClear(FLAG_FOLLOWERS_MENU_TOGGLE); 
        FlagSet(FLAG_DISABLE_FOLLOWERS);   // Disable followers (always disable when menu says off)
    }

    // Handle AutoRun option (another flag-based example, if you have it)
    if (sOptions->sel_custom[MENUITEM_AUTORUN] == 0) // Assuming 0 means Autorun is off
    {
        FlagSet(FLAG_AUTORUN_MENU_TOGGLE); // Set flag to ENABLE autorun (if your flag means enable when set)
    }
    else // sOptions->sel_custom[MENUITEM_AUTORUN] == 1, meaning on
    {
        FlagClear(FLAG_AUTORUN_MENU_TOGGLE); // Clear flag to DISABLE autorun
    }

    if (FlagGet(FLAG_ENABLE_OW_MON_OPTION) && sOptions->sel_custom[MENUITEM_OW_ENCOUNTERS] == 0) // Assuming 0 means Overworld Encounters are ON
    {
        FlagSet(OW_FLAG_SPAWN_OVERWORLD_MON); // Enable overworld encounters
        FlagSet(FLAG_OW_NO_ENCOUNTER); // Set the no encounter flag
    }
    else // sOptions->sel_custom[MENUITEM_OW_ENCOUNTERS] == 1, meaning OFF (or flag not set)
    {
        FlagClear(OW_FLAG_SPAWN_OVERWORLD_MON);   // Disable overworld encounters
        FlagClear(FLAG_OW_NO_ENCOUNTER); // Clear the no encounter flag
    }

    // The fade-out and task function assignment remain the same.
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sOptions);
        try_free(sBg2TilemapBuffer);
        try_free(sBg3TilemapBuffer);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        HideBg(2);
        HideBg(3);
        SetMainCallback2(gMain.savedCallback);
    }
}

static void ScrollMenu(int direction)
{
    int menuItem, pos;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (direction == 0) // scroll down
        menuItem = sOptions->menuCursor[sOptions->submenu] + NUM_OPTIONS_FROM_BORDER, pos = optionsToDraw - 1;
    else
        menuItem = sOptions->menuCursor[sOptions->submenu] - NUM_OPTIONS_FROM_BORDER, pos = 0;

    // Hide one
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF, PIXEL_FILL(0));
    // Show one
    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(0), 0, Y_DIFF * pos, 26 * 8, Y_DIFF);
    // Print
    DrawChoices(menuItem, pos * Y_DIFF);
    DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}
static void ScrollAll(int direction) // to bottom or top
{
    int i, y, menuItem, pos;
    int scrollCount;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    scrollCount = MenuItemCount() - optionsToDraw;

    // Move items up/down
    ScrollWindow(WIN_OPTIONS, direction, Y_DIFF * scrollCount, PIXEL_FILL(1));

    // Clear moved items
    if (direction == 0)
    {
        y = optionsToDraw - scrollCount;
        if (y < 0)
            y = optionsToDraw;
        y *= Y_DIFF;
    }
    else
    {
        y = 0;
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(0), 0, y, 26 * 8, Y_DIFF * scrollCount);
    // Print new texts
    for (i = 0; i < scrollCount; i++)
    {
        if (direction == 0) // From top to bottom
            menuItem = MenuItemCount() - 1 - i, pos = optionsToDraw - 1 - i;
        else // From bottom to top
            menuItem = i, pos = i;
        DrawChoices(menuItem, pos * Y_DIFF);
        DrawLeftSideOptionText(menuItem, (pos * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****GENERIC****
static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int xMid;
    int widthLeft = GetStringWidth(1, txt1, 0);
    int widthMid = GetStringWidth(1, txt2, 0);
    int widthRight = GetStringWidth(1, txt3, 0);

    widthMid -= (198 - 104);
    xMid = (widthLeft - widthMid - widthRight) / 2 + 104;
    return xMid;
}

static int XOptions_ProcessInput(int x, int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (++selection > (x - 1))
            selection = 0;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (--selection < 0)
            selection = (x - 1);
    }
    return selection;
}

static int TwoOptions_ProcessInput(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1;

    return selection;
}

static int ThreeOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(3, selection);
}

static int FourOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(4, selection);
}

static int FiveOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(5, selection);
}

static int SixteenOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(16, selection);
}

static int UNUSED ElevenOptions_ProcessInput(int selection)
{
    return XOptions_ProcessInput(11, selection);
}

// Process Input functions ****SPECIFIC****
static int Sound_ProcessInput(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
    }

    return selection;
}

static int FrameType_ProcessInput(int selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, 0x70, 0x20);
    }
    return selection;
}

// Draw Choices functions ****GENERIC****
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style, bool8 active)
{
    bool8 choosen = FALSE;
    if (style != 0)
        choosen = TRUE;

    DrawRightSideChoiceText(text, x, y+1, choosen, active);
}

static void UNUSED DrawChoices_Options_Three(const u8 *const *const strings, int selection, int y, bool8 active)
{
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {0, 1, 2},
    };
    u8 styles[3] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];

    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], active);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], active);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], active);
}

static void ReDrawAll(void)
{
    u8 menuItem = sOptions->menuCursor[sOptions->submenu] - sOptions->visibleCursor[sOptions->submenu];
    u8 i;
    u8 optionsToDraw = min(OPTIONS_ON_SCREEN, MenuItemCount());

    if (MenuItemCount() <= OPTIONS_ON_SCREEN) // Draw or delete the scrolling arrows based on options in the menu
    {
        if (sOptions->arrowTaskId != TASK_NONE)
        {
            RemoveScrollIndicatorArrowPair(sOptions->arrowTaskId);
            sOptions->arrowTaskId = TASK_NONE;
        }
    }
    else
    {
        if (sOptions->arrowTaskId == TASK_NONE)
            sOptions->arrowTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 240 / 2, 20, 110, MenuItemCount() - 1, 110, 110, 0);

    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(0));
    for (i = 0; i < optionsToDraw; i++)
    {
        DrawChoices(menuItem+i, i * Y_DIFF);
        DrawLeftSideOptionText(menuItem+i, (i * Y_DIFF) + 1);
    }
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

// Process Input functions ****SPECIFIC****
static const u8 sText_Faster[] = _("FASTER");
static const u8 *const sTextSpeedStrings[] = {gText_TextSpeedSlow ,gText_TextSpeedMid, gText_TextSpeedFast, sText_Faster};
static void DrawChoices_TextSpeed(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_TEXTSPEED);
    DrawChoices_Options_Four(sTextSpeedStrings, selection, y, active);
}

static void TextSpeed_DrawChoicesTwo(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_TEXTSPEED);
    u8 styles[3] = {0};
    int xMid = GetMiddleX(gText_TextSpeedMid, gText_TextSpeedFast, gText_TextSpeedFaster);
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_TextSpeedMid, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_TextSpeedFast, xMid, y, styles[1], active);
    DrawOptionMenuChoice(gText_TextSpeedFaster, GetStringRightAlignXOffset(1, gText_TextSpeedFaster, 198), y, styles[2], active);
}

static void DrawChoices_Options_Four(const u8 *const *const strings, int selection, int y, bool8 active)
{
    static const u8 choiceOrders[][3] =
    {
        {0, 1, 2},
        {0, 1, 2},
        {1, 2, 3},
        {1, 2, 3},
    };
    u8 styles[4] = {0};
    int xMid;
    const u8 *order = choiceOrders[selection];

    styles[selection] = 1;
    xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);

    DrawOptionMenuChoice(strings[order[0]], 104, y, styles[order[0]], active);
    DrawOptionMenuChoice(strings[order[1]], xMid, y, styles[order[1]], active);
    DrawOptionMenuChoice(strings[order[2]], GetStringRightAlignXOffset(1, strings[order[2]], 198), y, styles[order[2]], active);
}

static void FrameType_DrawChoices(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_FRAMETYPE);
    u8 text[16];
    u8 n = selection + 1;
    u16 i;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = 0x77;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, y, 0, active);
    DrawOptionMenuChoice(text, 128, y, 1, active);
}



static void BattleScene_DrawChoices(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_BATTLESCENE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSceneOn, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), y, styles[1], active);
}

static void BattleStyle_DrawChoices(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_BATTLESTYLE);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleStyleShift, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), y, styles[1], active);
}

static void BattleSpeed_DrawChoices(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_BATTLESPEED);
    u8 styles[4] = {0};
    s32 width1x, width2x, width3x, width4x, xMid, gap;

    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSpeed1x, 104, y, styles[0], active);

    width1x = GetStringWidth(1, gText_BattleSpeed1x, 0);
    width2x = GetStringWidth(1, gText_BattleSpeed2x, 0);
    width3x = GetStringWidth(1, gText_BattleSpeed3x, 0);
    width4x = GetStringWidth(1, gText_BattleSpeed4x, 0);
    gap = ((198 - 104 - width1x - width2x - width3x - width4x) / 3) + 1;

    xMid = 104 + width1x + gap;
    DrawOptionMenuChoice(gText_BattleSpeed2x, xMid, y, styles[1], active);
    DrawOptionMenuChoice(gText_BattleSpeed3x, xMid + width2x + gap, y, styles[2], active);
    DrawOptionMenuChoice(gText_BattleSpeed4x, 198 - width4x, y, styles[3], active);
}


// Define the new BattleSpeed_ProcessInput
static int BattleSpeed_ProcessInput_New(int selection) // Changed name to avoid conflict
{
    // Get the new selection from the generic input handler
    int newSelection = XOptions_ProcessInput(4, selection);

    // Save the new battle speed
    VarSet(VAR_BATTLE_SPEED, newSelection); 

    return newSelection;
}


static void SoundMode_DrawChoices(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_SOUND);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_SoundMono, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), y, styles[1], active);
}

/* static void  TextSpeed_DrawChoices(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_TEXTSPEED);
    DrawChoices_Options_Three(sTextSpeedStrings, selection, y, active);
} */

static void DrawChoices_Follower(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_FOLLOWER);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_FollowerOn, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_FollowerOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_FollowerOff, 198), y, styles[1], active);
}

static void DrawChoices_OW_Encounters(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_OW_ENCOUNTERS);
    u8 styles[2] = {0};
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_OW_Encounter_On, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_OW_Encounter_Off, GetStringRightAlignXOffset(FONT_NORMAL, gText_OW_Encounter_Off, 198), y, styles[1], active);
}

static void DrawChoices_AutoRun(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_AUTORUN);
    u8 styles[2] = {0};
    styles[selection] = 1;


    DrawOptionMenuChoice(gText_AutoRunOff, 104, y, styles[0], active);
    DrawOptionMenuChoice(gText_AutoRunOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_AutoRunOn, 198), y, styles[1], active);
}

static int ProcessInput_AutoRun(int selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
        selection ^= 1; // Toggle between 0 and 1

    if (selection == 0) 
    {
        FlagSet(FLAG_AUTORUN_MENU_TOGGLE);
        FlagClear(FLAG_RUNNING_SHOES_TOGGLE);
    }
    else
    {
        FlagClear(FLAG_AUTORUN_MENU_TOGGLE);
    }

    return selection;
}

static const u8 *const sTitleScreenStrings[] = {
    gText_TS_Necrozma,
    gText_TS_Solgaleo,
    gText_TS_Lunala,
    gText_TS_Random,
    gText_TS_Time,
};

static void DrawChoices_TitleScreen(int selection, int y)
{
    bool8 active = CheckConditions(MENUITEM_TITLESCREEN);
    // Draw the option string at the desired position
    DrawOptionMenuChoice(sTitleScreenStrings[selection], 104, y, 1, active);
}

static const u8 *const sRotomPhoneStrings[] = {
    gText_RP_Original,
    gText_RP_Black,
    gText_RP_Red,
    gText_RP_Yellow,
    gText_RP_Green,
    gText_RP_Purple,
    gText_RP_Blue,
    gText_RP_Turquoise,
    gText_RP_Rose,
    gText_RP_Brown,
    gText_RP_DarkGreen,
    gText_RP_WineRed,
    gText_RP_DarkBlue,
    gText_RP_White,
    gText_RP_Lavender,
    gText_RP_Gold,
};

static void DrawChoices_MenuPal(int selection, int y) 
{
    bool8 active = CheckConditions(MENUITEM_MENUPAL);
    // Draw the option string at the desired position
    DrawOptionMenuChoice(sRotomPhoneStrings[selection], 104, y, 1, active);
}
static int UNUSED ProcessInput_MenuPal(int selection) 
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < ROTOM_PHONE_COLOUR_COUNT - 1)
        {
            selection++;
        }
        else
        {
            selection = 0;
        }
      
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
        {
            selection--;
        }
        else
        {
            selection = ROTOM_PHONE_COLOUR_COUNT - 1;
        }
        
    }

    return selection;
}

// Background tilemap
#define TILE_TOP_CORNER_L 0x1A2 // 418
#define TILE_TOP_EDGE     0x1A3 // 419
#define TILE_TOP_CORNER_R 0x1A4 // 420
#define TILE_LEFT_EDGE    0x1A5 // 421
#define TILE_RIGHT_EDGE   0x1A7 // 423
#define TILE_BOT_CORNER_L 0x1A8 // 424
#define TILE_BOT_EDGE     0x1A9 // 425
#define TILE_BOT_CORNER_R 0x1AA // 426

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Option Texts window
    //FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    //FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);
    //FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    //FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);

    // Description window
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1, 15,  1,  4,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28, 15,  1,  4,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
