/*  Rotom Phone Start Menu by HashtagMarky


        --  Credits & Requirements  --

This Rotom Start Menu was built upon two public resources.
Vol's Start Menu and the Sample UI (Sliding Panel) provided
by Ghoulslash & Grant-Lucas both provided a basis for the two
aspects of this start menu Many thanks, and a lot of credit
must go to them all.
Vol Start Menu:
    https://github.com/volromhacking/pokeemerald/tree/start_menu_1
Ghoulslash & Grant-Lucas Sample UI:
    https://github.com/grunt-lucas/pokeemerald-expansion/tree/sample-ui

Another aspect that I must provide credit for was Bivurnum's
guide on Title Screen Easy Fade Colors. This implementation
provided a code efficient way to create the cursor highlighting.
    https://github.com/Bivurnum/decomps-resources/wiki/Title-Screen-Easy-Fade-Colors

The Rotom Start Menu uses ShantyTown's ComfyAnim Library,
many thanks to them for creating this public resource.
It will need to be added to your project in order to use
this if not already:
    https://github.com/huderlem/pokeemerald/tree/comfy_anims

Additional credit must go to Phantonomy for creating the
various coloured palettes for the phones, and helping with
some other graphical improvements.



        --    Tips & Stipulations   --

1.  No two overworld icons that appear on screen at the same
    time should have the same colour.
2.  A shortcut option can be selected by using the function
    called RotomPhone_StartMenu_GetShortcutOption, and can be
    more easily accessed by RP_GET_SHORTCUT_OPTION. These can
    be set by the developer, or the function can be made to
    dynamically change based on player selection.
3.  The black save screen that is shown when saving the game
    from the Rotom Reality Menu recreates the vanilla system,
    however the background can be changed by updating the tiles,
    tilemap and palette in graphics/rotom_start_menu/save_screen.



        --   Configuration Options  --

In rotom_start_menu.h (this file) and rotom_start_menu.c there
are multiple defines that are used to control differing aspects
of the start menu. The defines in rotom_start_menu.c are able to
be tweaked by the developer to adjust how the menu works, but
some of the defines in rotom_start_menu.h are made to allow for
player adjustment. This can be done in game through a scripting
flag, or save game options.

    RP_CONFIG_USE_ROTOM_PHONE
    Whether or not to use the Rotom Phone or a Generic Flip
    Phone, potentially an early game option due to story
    purposes.

    RP_CONFIG_PHONE_COLOUR
    The colour of the Rotom Phone that is displayed.

    RP_CONFIG_MONOCHROME_ICONS
    Whether each icon uses it's individual colours when on the
    menu. Works better with RP_CONFIG_PALETTE_BUFFER set to TRUE.

    RP_CONFIG_PALETTE_BUFFER
    Uses two bytes of EWRAM in order to store the background and
    sprite palettes used in the Rotom Phone. It is recommended to
    turn this on if you want to have various colour phone icons or
    change the monochrome sprite colour in code. When doing so you
    will only have to make adjustments to these palettes once. To see
    how the palettes are initialised, see these functions,
    particularly the ones with bool32 firstLoad as a parameter:
        RotomPhone_OverworldMenu_LoadIconSpritePalette
        RotomPhone_OverworldMenu_LoadBgPalette
        RotomPhone_RotomRealityMenu_LoadIconSpritePalette
        RotomPhone_RotomRealityMenu_LoadBgPalette

    RP_CONFIG_ROTOM_REALITY_SHORTCUT
    Allows for the START BUTTON to be used on the rotom reality
    menu to automatically open the shortcut. This menu option
    is denoted with a star.

    RP_CONFIG_24_HOUR_MODE
    A boolean option to display 24 hour time when TRUE, and
    12 hour time when FALSE.

    RP_CONFIG_NUM_MINUTES_TO_UPDATE
    An integer of how many in game minutes to update the time.
    In the overworld, this time update is interrupted by a
    message from Rotom exactly halfway through, unless
    RP_CONFIG_UPDATE_MESSAGE is set to FALSE. Due to task data
    being saved as an s16, this has to have a value less than:
        (32767 / (60 * FakeRtc_GetSecondsRatio()))

    RP_CONFIG_UPDATE_MESSAGE
    A boolean option that allows Rotom's Overworld messages
    if set to TRUE.

    RP_CONFIG_UPDATE_MESSAGE_SOUND
    A boolean option that plays a sound when Rotom provides
    a message or update.

    RP_CONFIG_FACE_UPDATE_PERCENT
    A percent chance to update Rotom's facial expressions
    when giving a message or update. Rotom's facial
    expression is currently guarenteed to change on a
    menu input, but this can easily be changed in
    RotomPhone_StartMenu_UpdateRotomFaceAnim(bool32 input).


    
        --  How to Add a New Option --

1.  When adding a new menu option, the first thing you must do
    is to ‘define’ it. Add the new option in enum RotomPhone_MenuOptions,
    the order of which will determine where your option appears.
    Only the first four unlocked menu options will appear on the
    generic flip phone, six on the overworld Rotom Phone and up
    to ten on each page of the Rotom Reality Menu.

2.  Next create the Overworld (20x20 on a 32x32 canvas) and the
    Rotom Reality Icons (32x32). This can be done easily by adding
    to the respection 'icons.png' in graphics/rotom_start_menu/overworld
    or graphics/rotom_start_menu/rotom_reality. In the current setup,
    the palettes of the overworld icons are important, and their
    indexes have been defined in enum RotomPhone_Overworld_FaceIconPaletteIndex.
    Each overworld icon should use PAL_ICON_WHITE (index 10) and one
    other colour in the indexes 1 - 9. For the Rotom Reality there,
    are two icon files, 'icons_1.png' and 'icons_2.png'. These have
    a lot more freedom and can use any combination of colours, apart
    from PAL_ROTOM_OUTLINE (index 11) upwards in 'icons_1.png'.
    
    Then define a new animation for this icon, and add it to
    sAnims_StartMenu_Icons making sure you keep track of what
    icon belongs to what animation.

3.  Then give this option an entry in sRotomPhoneOptions, see below
    for a brief overview of each field in struct RotomPhone_MenuOptions:

    const u8 *menuName;
    The name of the menu option.

    const u8 *rotomSpeech;
    The words Rotom will use to describe opening/entering the menu option.
    These words will be automatically appended to either "Do you want" or
    "Would you like".

    bool32 (*unlockedFunc)(void);
    A boolean function that determines whether the menu option is unlocked.
    Custom functions can be made but some pre-existing generic ones exist.
    Note the ones marked as UNUSED will need to have it removed:
        RotomPhone_StartMenu_UnlockedFunc_Unlocked
        UNUSED RotomPhone_StartMenu_UnlockedFunc_Unlocked_Overworld
        RotomPhone_StartMenu_UnlockedFunc_Unlocked_RotomReality

    void (*selectedFunc)(void);
    The function that is run in order to open the menu option. These usually
    will have an if (RotomPhone_StartMenu_IsRotomReality()) statement as the
    function will need to be different whether on the overworld or not. There
    are different clean up functions depending on how the menu option needs to
    be opened. The functions included are:
        RotomPhone_StartMenu_DoCleanUpAndChangeCallback
        RotomPhone_StartMenu_DoCleanUpAndCreateTask
        RotomPhone_StartMenu_DoCleanUpAndChangeTaskFunc
        RotomPhone_StartMenu_DoCleanUpAndDestroyTask
    
    u32 owIconPalSlot;
    The palette index the icon uses other than PAL_ICON_WHITE in it's overworld
    icon. enum RotomPhone_Overworld_FaceIconPaletteIndex exists to help facilitate
    this.

    bool32 rotomRealityPanel;
    A boolean value that determines whether the menu option will use the sliding
    panel in the Rotom Reality Menu rather than opening a new UI Screen. If this is
    TRUE, the selectedFunc will have to include some variation of the
    if (RotomPhone_StartMenu_IsRotomReality() && sRotomPhone_StartMenu->menuRotomRealityPanelOpen)
    statement. See RotomPhone_StartMenu_SelectedFunc_Daycare for an example of a
    selectedFunc for an option that exists exists only on the Rotom Reality Menu and
    uses the sliding panel for its selectedFunc.

    enum RotomPhone_IconAnims owAnim;
    The value that denotes what index the animation for the menu option's Overworld
    icon is in sAnims_StartMenu_Icons.

    enum RotomPhone_IconAnims rrAnim;
    The value that denotes what index the animation for the menu option's Rotom Reality
    icon is in sAnims_StartMenu_Icons.
*/

#ifndef GUARD_ROTOM_START_MENU_H
#define GUARD_ROTOM_START_MENU_H

#include "global.h"

enum RotomPhone_Colours
{
    ROTOM_PHONE_OG,
    ROTOM_PHONE_BLACK,
    ROTOM_PHONE_RED,
    ROTOM_PHONE_YELLOW,
    ROTOM_PHONE_GREEN,
    ROTOM_PHONE_PURPLE,
    ROTOM_PHONE_BLUE,
    ROTOM_PHONE_TURQUOISE,
    ROTOM_PHONE_ROSE,
    ROTOM_PHONE_BROWN,
    ROTOM_PHONE_DARK_GREEN,
    ROTOM_PHONE_WINE_RED,
    ROTOM_PHONE_NAVY,
    ROTOM_PHONE_WHITE,
    ROTOM_PHONE_LAVENDER,
    ROTOM_PHONE_GOLD,
    ROTOM_PHONE_COLOUR_COUNT
};

#define RP_CONFIG_PHONE_COLOUR            ROTOM_PHONE_BLACK
#define RP_CONFIG_USE_ROTOM_PHONE         (VarGet(VAR_ROTOM_PHONE_ENABLE) > 0)
#define RP_CONFIG_ROTOM_ACTIVE            (VarGet(VAR_ROTOM_PHONE_ENABLE) > 1)
#define RP_CONFIG_MONOCHROME_ICONS        FALSE
#define RP_CONFIG_PALETTE_BUFFER          FALSE
#define RP_CONFIG_ROTOM_REALITY_SHORTCUT  TRUE
#define RP_CONFIG_24_HOUR_MODE            FALSE
#define RP_CONFIG_NUM_MINUTES_TO_UPDATE   3
#define RP_CONFIG_UPDATE_MESSAGE          TRUE
#define RP_CONFIG_UPDATE_MESSAGE_SOUND    TRUE
#define RP_CONFIG_FACE_UPDATE_PERCENT     100

enum RotomPhoneScriptMenuItems
{
    ROTOM_SCRIPT_MENU_NONE = 0xFFFF,
    ROTOM_SCRIPT_MENU_ROTOM_REALITY = 0,
    ROTOM_SCRIPT_MENU_FLAG = 1,
    ROTOM_SCRIPT_MENU_SHORTCUT = 2,
    ROTOM_SCRIPT_MENU_CLOCK = 3,
    ROTOM_SCRIPT_MENU_POKEDEX = 4,
    ROTOM_SCRIPT_MENU_PARTY = 5,
    ROTOM_SCRIPT_MENU_BAG = 7,
    ROTOM_SCRIPT_MENU_DEXNAV = 8,
    ROTOM_SCRIPT_MENU_SAVE = 12,
    ROTOM_SCRIPT_MENU_OPTIONS = 13,
};

void RotomPhone_StartMenu_Open(bool32 firstInit);
void RotomPhone_StartMenu_OpenForScript(u16 menuItem, const u8 *customPromptText);
bool32 RotomPhone_StartMenu_IsScriptDisplayActive(void);

const u16 *RotomPhone_StartMenu_GetPhoneColour(void);

#endif // GUARD_ROTOM_START_MENU_H