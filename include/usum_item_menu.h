#ifndef GUARD_USUM_ITEM_MENU_H
#define GUARD_USUM_ITEM_MENU_H

#define USUM_ITEM_MENU                  TRUE  // Use USUM bag menu

#define USUM_ITEM_MENU_CONTEST_INFO     (USUM_ITEM_MENU && FALSE)               // Show contest info for TMs/HMs in the item menu
#define USUM_ITEM_MENU_BERRY_STAT       (USUM_ITEM_MENU && FALSE)               // Show berry stat (flavors, size, etc.) in the item menu
#define USUM_ITEM_MENU_BERRY_TAG        (USUM_ITEM_MENU_BERRY_STAT && FALSE)    // Show berry tag info
#define USUM_ITEM_MENU_SCROLLING_BG     (USUM_ITEM_MENU && FALSE)               // Enable scrolling background (BG3)

#define USUM_ITEM_MENU_IN_BAG_USE       (USUM_ITEM_MENU && TRUE)                // Perform item actions (Use/Give) in bag (skip party menu)
#define USUM_ITEM_MENU_IN_BAG_REUSE     (USUM_ITEM_MENU_IN_BAG_USE && TRUE)     // Keep item cursor in party after use/give
#define USUM_ITEM_MENU_IN_BATTLE_USE    (USUM_ITEM_MENU_IN_BAG_USE && TRUE)     // Use items in bag during battle (skip party menu)
#define USUM_ITEM_MENU_PARTY_HP_BAR     (USUM_ITEM_MENU_IN_BAG_USE && TRUE)     // Show HP bar in party slot for certain items usage

#define USUM_ITEM_MENU_PYRAMID          (USUM_ITEM_MENU && TRUE)                // Use USUM bag menu for the Battle Pyramid
#define USUM_ITEM_MENU_PYRAMID_ACTION   (USUM_ITEM_MENU_PYRAMID && USUM_ITEM_MENU_IN_BAG_USE)   // Perform inline Use/Give in the pyramid bag

#define USUM_ITEM_MENU_BATTLE_POCKETS   (USUM_ITEM_MENU && TRUE)                // In battle, show battle pockets (Medicine/Poké Balls/Battle Items/Berries) instead of the field pockets

#if USUM_ITEM_MENU_IN_BAG_USE
void BagMenu_OpenPartySelect(u8 taskId);
#if USUM_ITEM_MENU_IN_BATTLE_USE
void BagMenu_OpenPartySelectBattle(u8 taskId);
#endif // USUM_ITEM_MENU_IN_BATTLE_USE
#endif // USUM_ITEM_MENU_IN_BAG_USE

#endif // GUARD_USUM_ITEM_MENU_H
