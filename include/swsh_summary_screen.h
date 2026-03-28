#ifndef GUARD_SWSH_SUMMARY_SCREEN_H
#define GUARD_SWSH_SUMMARY_SCREEN_H

#include "main.h"

// turn on and off the SwSh summary screen
#define SWSH_SUMMARY_SCREEN                           TRUE

// constants
#define SWSH_MAX_MOVE_DESCRIPTION_LENGTH              100       // this only needs to be updated if you use auto-formatting
#define SWSH_SUMMARY_MON_IDLE_ANIMS_FRAMES            300       // number of frames between each idle anim IF SWSH_SUMMARY_MON_IDLE_ANIMS is true.
                                                                // for reference, Emerald runs at 60FPS by default

// configs
#define SWSH_SUMMARY_AUTO_FORMAT_MOVE_DESCRIPTIONS    TRUE      // automatically formats move descriptions to fit the new box size. disable if you want to format them manually
#define SWSH_SUMMARY_NATURE_COLORS                    TRUE      // color stats increased or reduced by nature, red = boosted, blue = reduced
#define SWSH_SUMMARY_CATEGORY_ICONS                   TRUE      // determines whether category (split) icons are shown or not
#define SWSH_SUMMARY_SHOW_IV_EV                       TRUE      // determines how to show IVs and EVs
#define SWSH_SUMMARY_SHOW_FRIENDSHIP                  TRUE      // show a heart that fills up to indicate friendship value
#define SWSH_SUMMARY_SWSH_STATUS_ICONS                TRUE      // use Gen 8 style status icons instead of default ones.
#define SWSH_SUMMARY_SWSH_TYPE_ICONS                  TRUE      // use Gen 8 style type icons instead of the default ones
#define SWSH_SUMMARY_SWSH_TYPE_ICONS_SV_PAL           FALSE     // use Scarlet/Violet palette for type icons
                                                                // out of the box the vanilla icons don't fit well, this is mostly a compatibility
#define SWSH_SUMMARY_SCROLLING_BG                     TRUE      // enables scrolling animated background
#define SWSH_SUMMARY_BG_BLEND                         FALSE     // enables alpha blending for the main UI (semi-transparency)
#define SWSH_SUMMARY_MON_IDLE_ANIMS                   TRUE      // loops the mon animations regularly as an "idle" anim
#define SWSH_SUMMARY_MON_SHADOWS                      TRUE      // displays a shadow for the mon sprite
#define SWSH_SUMMARY_SHOW_DYNAMAX_LEVEL               FALSE     // show dynamax level
#define SWSH_SUMMARY_SHOW_GIGANTAMAX                  FALSE     // show gigantamax icon
#define SWSH_SUMMARY_SHOW_TERA_TYPE                   FALSE     // show tera type icons

// Looking for configs for renaming mons and relearning moves? Those use the standard expansion configs
// P_SUMMARY_SCREEN_RENAME and P_SUMMARY_SCREEN_MOVE_RELEARNER in include/config/pokemon.h
// Same with showing dynamic types:
// P_SHOW_DYNAMIC_TYPES

/* Info for users

General tilemap setup
BG3 - scrolling grid background (or not scrolling if you turned the config off) 
BG2 - main UI overlayed on scrolling BG
BG1 - pop in move effect windows
BG0 - text windows

Mosaic effect used when transitioning between screens and actvating
effect windows is controlled by tMosaicStrength in the relevant
task functions.

BG scrolling speed can be modified by altering the value parameter
of the ChangeBgX and ChangeBgY functions in VBlank()

Main UI and shadow transparency levels can be adjusted by changing the
value written to the alpha blend register in this line in swsh_summary_screen.c:

static void InitBGs(void)
...
SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(14, 6));
...
}

*/

/* ravetodo in future updates
- extended move desc window
- ribbons
*/

extern const struct SpriteTemplate sSpriteTemplate_MoveTypes;
extern const struct CompressedSpriteSheet sSpriteSheet_MoveTypes;
extern const u16 sMoveTypes_Pal[];

void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
void ShowSelectMovePokemonSummaryScreen(struct Pokemon *mons, u8 monIndex, void (*callback)(void), u16 newMove);
u8 GetMoveSlotToReplace(void);
void SummaryScreen_SetAnimDelayTaskId(u8 taskId);
void SummaryScreen_SetShadowAnimDelayTaskId(u8 taskId);

#endif // GUARD_SWSH_SUMMARY_SCREEN_H