#ifndef GUARD_FIELD_ITEM_WHEEL_H
#define GUARD_FIELD_ITEM_WHEEL_H

// Registered item helpers shared by the bag menus and the field wheels
u32 CountRegisteredItemsInArray(u16 *array);
s32 RegisteredItemIndexInArray(u16 item, u16 *array);
u32 CountRegisteredItems(void);
s32 RegisteredItemIndex(u16 item);
u32 DpadInputToRegisteredItemIndex(bool32 check);
u32 DpadInputToRegisteredItemIndexInArray(bool32 check, u16 *array);

// Field-side registered item use (key item / pokeride wheels)
bool8 UseRegisteredKeyItemOnField(void);
bool8 UseRegisteredPokerideItemOnField(void);

#endif // GUARD_FIELD_ITEM_WHEEL_H
