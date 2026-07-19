#include "global.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_item_wheel.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "gpu_regs.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "link.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "palette.h"
#include "rotom_start_menu.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "window.h"
#include "constants/items.h"
#include "constants/songs.h"

// Immune to blending; doesn't conflict with tags in event_object_movement
#define PAL_TAG_KEY_ITEM_WHEEL  0x9000
#define PAL_TAG_POKERIDE_ITEM_WHEEL  0x9001

static void Task_KeyItemWheel(u8 taskId);
static void Task_PokerideItemWheel(u8 taskId);

static const u32 sKeyItemBoxGfx[] = INCGFX_U32("graphics/bag/key_item_box.png", ".4bpp");
static const u16 sKeyItemBoxPal[] = INCGFX_U16("graphics/bag/key_item_box.png", ".gbapal");
static const u16 sKeyItemBoxBluePal[] = INCGFX_U16("graphics/bag/key_item_box_blue.pal", ".gbapal");
// static const u16 sKeyItemBoxGreenPal[] = INCGFX_U16("graphics/bag/key_item_box_green.pal", ".gbapal");
// static const u16 sKeyItemBoxPurplePal[] = INCGFX_U16("graphics/bag/key_item_box_purple.pal", ".gbapal");
static const u16 sKeyItemBoxOrangePal[] = INCGFX_U16("graphics/bag/key_item_box_orange.pal", ".gbapal");

// Label graphics (64x32 sprites) and tail (32x32 sprite)
static const u32 sKeyItemsLabelGfx[] = INCGFX_U32("graphics/bag/key_items_label.png", ".4bpp");
static const u32 sPokerideLabelGfx[] = INCGFX_U32("graphics/bag/pokeride_label.png", ".4bpp");
static const u32 sKeyItemBoxTailGfx[] = INCGFX_U32("graphics/bag/key_item_wheel_rotom_tail.png", ".4bpp");
// Palette loaded dynamically from rotom phone color scheme

static const struct SpritePalette sSpritePalette_KeyItemBox = {
    .data = sKeyItemBoxOrangePal,
    .tag = PAL_TAG_KEY_ITEM_WHEEL,
};

static const struct SpritePalette sSpritePalette_PokerideItemBox = {
    .data = sKeyItemBoxBluePal,
    .tag = PAL_TAG_POKERIDE_ITEM_WHEEL,
};

// Label palette tag - data loaded dynamically from rotom phone color scheme
#define LABEL_PALETTE_TAG 0xD000

static const struct SpriteFrameImage sPicTable_KeyItemBox[] = {
    obj_frame_tiles(sKeyItemBoxGfx),
};

static const struct SpriteFrameImage sPicTable_KeyItemsLabel[] = {
    obj_frame_tiles(sKeyItemsLabelGfx),
};

static const struct SpriteFrameImage sPicTable_PokerideLabel[] = {
    obj_frame_tiles(sPokerideLabelGfx),
};

static const struct SpriteFrameImage sPicTable_LabelTail[] = {
    obj_frame_tiles(sKeyItemBoxTailGfx),
};

const struct OamData sOam_KeyItemBox = {
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
    .objMode = ST_OAM_OBJ_BLEND,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
};

const struct OamData sOam_Label = {
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 0,  // Draw on top
};

const struct OamData sOam_LabelTail = {
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0,  // Draw on top
};

const struct OamData sOam_KeyItemBoxWin = {
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
    .objMode = ST_OAM_OBJ_WINDOW,
    .affineMode = ST_OAM_AFFINE_OFF,
};

static const union AnimCmd sSpriteAnim_KeyItemBox[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_KeyItemBox[] =
{
    sSpriteAnim_KeyItemBox
};

static const union AnimCmd sSpriteAnim_Label[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Label[] =
{
    sSpriteAnim_Label
};

static const union AffineAnimCmd sAffineAnim_KeyItemBox0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KeyItemBox1[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xC0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KeyItemBox2[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x80, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KeyItemBox3[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x40, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KeyItemBoxGrow0[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x120, 0, 0),
    AFFINEANIMCMD_FRAME(0x120, 0x120, 0, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x110, 0, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KeyItemBoxGrow1[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x120, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0x120, 0x120, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x110, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xC0, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0xC0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KeyItemBoxGrow2[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0x80, 0),
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0x80, 0),
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0x80, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x80, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x120, 0x80, 0),
    AFFINEANIMCMD_FRAME(0x120, 0x120, 0x80, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x110, 0x80, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x80, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x80, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KeyItemBoxGrow3[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0x40, 0),
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0x40, 0),
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0x40, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x40, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x120, 0x40, 0),
    AFFINEANIMCMD_FRAME(0x120, 0x120, 0x40, 0),
    AFFINEANIMCMD_FRAME(0x110, 0x110, 0x40, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x40, 0),
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0x40, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_KeyItemBox[] =
{
    sAffineAnim_KeyItemBox0,
    sAffineAnim_KeyItemBox1,
    sAffineAnim_KeyItemBox2,
    sAffineAnim_KeyItemBox3,
    sAffineAnim_KeyItemBoxGrow0,
    sAffineAnim_KeyItemBoxGrow1,
    sAffineAnim_KeyItemBoxGrow2,
    sAffineAnim_KeyItemBoxGrow3,
};

static const struct SpriteTemplate sSpriteTemplate_KeyItemBox = {
    .tileTag = PAL_TAG_KEY_ITEM_WHEEL,
    .paletteTag = PAL_TAG_KEY_ITEM_WHEEL,
    .oam = &sOam_KeyItemBox,
    .anims = sSpriteAnimTable_KeyItemBox,
    .images = sPicTable_KeyItemBox,
    .affineAnims = sAffineAnims_KeyItemBox,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_KeyItemBoxWin = {
    .tileTag = PAL_TAG_KEY_ITEM_WHEEL,
    .paletteTag = PAL_TAG_KEY_ITEM_WHEEL,
    .oam = &sOam_KeyItemBoxWin,
    .anims = sSpriteAnimTable_KeyItemBox,
    .images = sPicTable_KeyItemBox,
    .affineAnims = sAffineAnims_KeyItemBox,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_KeyItemsLabel = {
    .tileTag = 0xD001,  // Key items label tile tag
    .paletteTag = 0xD000,  // Label palette tag
    .oam = &sOam_Label,
    .anims = sSpriteAnimTable_Label,
    .images = sPicTable_KeyItemsLabel,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_PokerideLabel = {
    .tileTag = 0xD002,  // Pokeride label tile tag
    .paletteTag = 0xD000,  // Label palette tag (same as key items)
    .oam = &sOam_Label,
    .anims = sSpriteAnimTable_Label,
    .images = sPicTable_PokerideLabel,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_LabelTail = {
    .tileTag = 0xD003,  // Tail tile tag
    .paletteTag = 0xD000,  // Label palette tag (shared)
    .oam = &sOam_LabelTail,
    .anims = sSpriteAnimTable_Label,
    .images = sPicTable_LabelTail,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_PokerideItemBox = {
    .tileTag = PAL_TAG_KEY_ITEM_WHEEL,
    .paletteTag = PAL_TAG_POKERIDE_ITEM_WHEEL,
    .oam = &sOam_KeyItemBox,
    .anims = sSpriteAnimTable_KeyItemBox,
    .images = sPicTable_KeyItemBox,
    .affineAnims = sAffineAnims_KeyItemBox,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_PokerideItemBoxWin = {
    .tileTag = PAL_TAG_KEY_ITEM_WHEEL,
    .paletteTag = PAL_TAG_POKERIDE_ITEM_WHEEL,
    .oam = &sOam_KeyItemBoxWin,
    .anims = sSpriteAnimTable_KeyItemBox,
    .images = sPicTable_KeyItemBox,
    .affineAnims = sAffineAnims_KeyItemBox,
    .callback = SpriteCallbackDummy,
};

static const u8 sKeyItemBoxXPos[MAX_REGISTERED_ITEMS] = {(DISPLAY_WIDTH / 2), (DISPLAY_WIDTH / 2) + 32, (DISPLAY_WIDTH / 2), (DISPLAY_WIDTH / 2) - 32};
static const u8 sKeyItemBoxYPos[MAX_REGISTERED_ITEMS] = {(DISPLAY_HEIGHT / 2) - 32, (DISPLAY_HEIGHT / 2), (DISPLAY_HEIGHT / 2) + 32, (DISPLAY_HEIGHT / 2)};

static EWRAM_DATA ALIGNED(4) u16 sKeyItemWheelExtraPalette[16] = {0};

// Returns [1-4] based on dpad, or 0 otherwise
u32 DpadInputToRegisteredItemIndex(bool32 check) {
    u32 i = 0;
    if (JOY_NEW(DPAD_UP))
        i = 1;
    else if (JOY_NEW(DPAD_RIGHT))
        i = 2;
    else if (JOY_NEW(DPAD_DOWN))
        i = 3;
    else if (JOY_NEW(DPAD_LEFT))
        i = 4;
    // If `check`, verify that slot actually has an item registered
    if (i && check && gSaveBlock1Ptr->registeredItems[i-1] == ITEM_NONE)
        i = 0;
    return i;
}

// Returns [1-4] based on dpad, or 0 otherwise. Checks against a specific array.
u32 DpadInputToRegisteredItemIndexInArray(bool32 check, u16 *array) {
    u32 i = 0;
    if (JOY_NEW(DPAD_UP))
        i = 1;
    else if (JOY_NEW(DPAD_RIGHT))
        i = 2;
    else if (JOY_NEW(DPAD_DOWN))
        i = 3;
    else if (JOY_NEW(DPAD_LEFT))
        i = 4;
    // If `check`, verify that slot actually has an item registered
    if (i && check && array[i-1] == ITEM_NONE)
        i = 0;
    return i;
}

u32 CountRegisteredItemsInArray(u16 *array) {
    u32 i;
    u32 count = 0;
    for (i = 0; i < MAX_REGISTERED_ITEMS; i++)
        if (array[i] != ITEM_NONE)
            count++;
    return count;
}

// if passed ITEM_NONE, finds the first registered item's index in the given array
s32 RegisteredItemIndexInArray(u16 item, u16 *array) {
    s32 i;
    for (i = 0; i < MAX_REGISTERED_ITEMS; i++)
        if (array[i] && (!item || array[i] == item))
            return i;
    return -1;
}

u32 CountRegisteredItems(void) {
    u32 i;
    u32 count = 0;
    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->registeredItems); i++)
        if (gSaveBlock1Ptr->registeredItems[i] != ITEM_NONE)
            count++;
    // Fallback to vanilla registeredItem
    if (count == 0 && gSaveBlock1Ptr->registeredItemCompat) {
        gSaveBlock1Ptr->registeredItems[0] = gSaveBlock1Ptr->registeredItemCompat;
        count = 1;
    }
    return count;
}

// if passed ITEM_NONE, finds the first registered item's index
s32 RegisteredItemIndex(u16 item) {
    s32 i;
    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->registeredItems); i++)
        if (gSaveBlock1Ptr->registeredItems[i] && (!item || gSaveBlock1Ptr->registeredItems[i] == item))
            return i;
    if (item && item == gSaveBlock1Ptr->registeredItemCompat) {
        gSaveBlock1Ptr->registeredItems[0] = item;
        return 0;
    }
    return -1;
}

#define tUsingRegisteredKeyItem data[3] // See usage in item_use.c

bool8 UseRegisteredKeyItemOnField(void)
{
    u32 taskId;
    u32 i;
    ItemUseFunc func = NULL;

    if (InUnionRoom() == TRUE || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || InBattlePike() || InMultiPartnerRoom() == TRUE)
        return FALSE;
    HideMapNamePopUpWindow();
    ChangeBgY_ScreenOff(0, 0, BG_COORD_SET);
    i = CountRegisteredItems();
    // Show key item wheel
    if (i > 1) {
        func = Task_KeyItemWheel;
    // Use the only registered item
    } else if (i > 0) {
        if (CheckBagHasItem(gSaveBlock1Ptr->registeredItemCompat, 1) == TRUE) {
            gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItemCompat;
            func = GetItemFieldFunc(gSaveBlock1Ptr->registeredItemCompat);
        } else {
            gSaveBlock1Ptr->registeredItemCompat = ITEM_NONE;
        }
    }
    if (func) {
        LockPlayerFieldControls();
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
        taskId = CreateTask(func, 8);
        gTasks[taskId].tUsingRegisteredKeyItem = TRUE;
        return TRUE;
    }
    ScriptContext_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return TRUE;
}

bool8 UseRegisteredPokerideItemOnField(void)
{
    u32 taskId;
    u32 i;
    u32 j;
    ItemUseFunc func = NULL;

    if (InUnionRoom() == TRUE || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || InBattlePike() || InMultiPartnerRoom() == TRUE)
        return FALSE;

    HideMapNamePopUpWindow();
    ChangeBgY_ScreenOff(0, 0, BG_COORD_SET);
    i = CountRegisteredItemsInArray(gSaveBlock1Ptr->registeredPokerideItems);

    // Show pokeride item wheel
    if (i > 1) {
        func = Task_PokerideItemWheel;
    }
    // Use the only registered pokeride item
    else if (i > 0) {
        // Find first registered item
        for (j = 0; j < MAX_REGISTERED_ITEMS; j++) {
            if (gSaveBlock1Ptr->registeredPokerideItems[j] != ITEM_NONE) {
                if (CheckBagHasItem(gSaveBlock1Ptr->registeredPokerideItems[j], 1) == TRUE) {
                    gSpecialVar_ItemId = gSaveBlock1Ptr->registeredPokerideItems[j];
                    func = GetItemFieldFunc(gSaveBlock1Ptr->registeredPokerideItems[j]);
                } else {
                    gSaveBlock1Ptr->registeredPokerideItems[j] = ITEM_NONE;
                }
                break;
            }
        }
    }

    if (func) {
        LockPlayerFieldControls();
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
        taskId = CreateTask(func, 8);
        gTasks[taskId].tUsingRegisteredKeyItem = TRUE;
        return TRUE;
    }

    ScriptContext_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return TRUE;
}

static void HBlankCB_KeyItemWheel(void) {
    u32 vCount = REG_VCOUNT;
    if (vCount >= DISPLAY_HEIGHT) {
        sKeyItemWheelExtraPalette[0] = 0;
        return;
    }
    // Copy item 3
    if (vCount >= 64 && sKeyItemWheelExtraPalette[0] == 0) {
        CpuFastCopy(sKeyItemWheelExtraPalette, (u32*)(BG_PLTT + PLTT_ID(13)*2), PLTT_SIZE_4BPP);
        sKeyItemWheelExtraPalette[0] = 0x8000;
    }
}

#define tState data[0]
// MAX_REGISTERED_ITEMS box sprites
#define tBoxSprite (data + 1)
#define tBoxWinSprite (data + 1 + MAX_REGISTERED_ITEMS)
// MAX_REGISTERED_ITEMS icon windows
#define tIconWindow (data + 1 + 2*MAX_REGISTERED_ITEMS)
#define tLabelSprite data[13]
#define tLabelTailSprite data[14]

// Create label sprite from pre-rendered graphics and tail sprite
static u8 CreateLabelSprite(const struct SpriteTemplate *template, s16 x, s16 y, s16 *outTailSpriteId)
{
    u8 spriteId;
    struct SpriteSheet sheet;

    // Load palette dynamically from rotom phone color (if not already loaded)
    if (IndexOfSpritePaletteTag(LABEL_PALETTE_TAG) == 0xFF) {
        struct SpritePalette labelPalette = {
            .data = RotomPhone_StartMenu_GetPhoneColour(),
            .tag = LABEL_PALETTE_TAG,
        };
        LoadSpritePalette(&labelPalette);
    }

    // Load the specific label's graphics
    sheet.data = template->images->data;
    sheet.size = 1024;  // 64x32 = 32 tiles (8 wide × 4 tall) × 32 bytes = 1024 bytes
    sheet.tag = template->tileTag;

    if (IndexOfSpriteTileTag(sheet.tag) == 0xFF)
        LoadSpriteSheet(&sheet);

    // Create label sprite
    spriteId = CreateSprite(template, x, y, 0);
    if (spriteId == MAX_SPRITES)
        return MAX_SPRITES;

    // Load tail graphics if not already loaded
    if (IndexOfSpriteTileTag(0xD003) == 0xFF) {
        sheet.data = sKeyItemBoxTailGfx;
        sheet.size = 512;  // 32x32 = 16 tiles × 32 bytes = 512 bytes
        sheet.tag = 0xD003;
        LoadSpriteSheet(&sheet);
    }

    // Create tail sprite immediately to the right of the label
    // Label is 64 wide, so tail starts at x + 32 (label center) + 32 (half label width) + 16 (half tail width)
    *outTailSpriteId = CreateSprite(&sSpriteTemplate_LabelTail, x + 48, y, 0);

    return spriteId;
}

// Free key item wheel gfx using sprites & windows from task data
static void FreeKeyItemWheelGfx(s16 *data, u16 paletteTag) {
    u32 i;
    struct Sprite *sprite;
    FreeSpriteTilesByTag(PAL_TAG_KEY_ITEM_WHEEL);
    FreeSpritePaletteByTag(paletteTag);
    // free box sprites
    for (i = 0; i < 2 * MAX_REGISTERED_ITEMS; i++) {
        if (tBoxSprite[i] >= MAX_SPRITES)
            continue;
        sprite = &gSprites[tBoxSprite[i]];
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
    // free item windows
    for (i = 0; i < MAX_REGISTERED_ITEMS; i++) {
        if (tIconWindow[i] == WINDOW_NONE)
            continue;
        FillWindowPixelBuffer(tIconWindow[i], 0);
        ClearWindowTilemap(tIconWindow[i]);
        CopyWindowToVram(tIconWindow[i], COPYWIN_MAP);
        RemoveWindow(tIconWindow[i]);
    }
    // free label sprites (label + tail)
    if (tLabelSprite != MAX_SPRITES) {
        DestroySprite(&gSprites[tLabelSprite]);
        // Free the tile tags to prevent ghost labels from appearing
        FreeSpriteTilesByTag(0xD001);  // Key items label tiles
        FreeSpriteTilesByTag(0xD002);  // Pokeride label tiles
        FreeSpritePaletteByTag(0xD000); // Shared label palette
    }
    if (tLabelTailSprite != MAX_SPRITES) {
        DestroySprite(&gSprites[tLabelTailSprite]);
        FreeSpriteTilesByTag(0xD003);  // Tail tiles
    }
    SetHBlankCallback(NULL);
    DisableInterrupts(INTR_FLAG_HBLANK);
}

static void Task_KeyItemWheel(u8 taskId) {
    u32 i, j;
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
    {
        LoadSpritePalette(&sSpritePalette_KeyItemBox);
        LoadSpriteSheetByTemplateKeyItem(&sSpriteTemplate_KeyItemBox, 0);

        // Create label sprite in top left corner with tail
        tLabelSprite = CreateLabelSprite(&sSpriteTemplate_KeyItemsLabel, 120, 20, &tLabelTailSprite);
        if (tLabelSprite == MAX_SPRITES) {
            tLabelSprite = MAX_SPRITES;  // Ensure it's set for cleanup
            tLabelTailSprite = MAX_SPRITES;
        }

        for (i = 0; i < MAX_REGISTERED_ITEMS; i++) {
            // Create box sprite
            tBoxSprite[i] = j = CreateSprite(&sSpriteTemplate_KeyItemBox, sKeyItemBoxXPos[i], sKeyItemBoxYPos[i], 0);
            if (j < MAX_SPRITES)
                StartSpriteAffineAnim(&gSprites[j], i);
            tBoxWinSprite[i] = MAX_SPRITES;
            // For each registered item the player has, create a window and blit its icon to it
            tIconWindow[i] = WINDOW_NONE;
            if (!gSaveBlock1Ptr->registeredItems[i] || !CheckBagHasItem(gSaveBlock1Ptr->registeredItems[i], 1))
                continue;
            tIconWindow[i] = j = AddWindowParameterized(0, sKeyItemBoxXPos[i] / 8 - 2, sKeyItemBoxYPos[i] / 8 - 2, 4, 4, i == 3 ? 13 : 13 + i, 16*(i+9));
            if (j == WINDOW_NONE)
                continue;
            PutWindowTilemap(j);
            BlitItemIconToWindow(gSaveBlock1Ptr->registeredItems[i], j, 4, 4, i == 3 ? sKeyItemWheelExtraPalette : NULL);
            CopyWindowToVram(j, COPYWIN_FULL);
        }
        SetHBlankCallback(HBlankCB_KeyItemWheel);
        EnableInterrupts(INTR_FLAG_HBLANK);
        PlaySE(SE_WIN_OPEN);
        // in dark caves, we need to spawn OBJWIN sprites to show the boxes
        tState = (gSaveBlock1Ptr->flashLevel > 1) ? 4 : 1;
        break;
    }
    case 1: // process input
    {
        if (JOY_NEW(B_BUTTON) || JOY_NEW(SELECT_BUTTON)) {
            PlaySE(SE_SELECT);
            tState = 3; // destroy and unfreeze
            break;
        }
        i = DpadInputToRegisteredItemIndexInArray(TRUE, gSaveBlock1Ptr->registeredItems);
        if (i == 0 || data[i] == MAX_SPRITES)
            break;
        // use item as if it was registered
        gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItemCompat = gSaveBlock1Ptr->registeredItems[i - 1];
        PlaySE(SE_SELECT);
        StartSpriteAffineAnim(&gSprites[data[i]], i + 4 - 1);
        data[15] = data[i];
        tState = 2; // wait for anim
        break;
    }
    case 2:
        if (!gSprites[data[15]].affineAnimEnded)
            break;
        FreeKeyItemWheelGfx(data, PAL_TAG_KEY_ITEM_WHEEL);
        i = CreateTask(GetItemFieldFunc(gSaveBlock1Ptr->registeredItemCompat), 8);
        gTasks[i].tUsingRegisteredKeyItem = TRUE;
        DestroyTask(taskId);
        break;
    case 3:
        FreeKeyItemWheelGfx(data, PAL_TAG_KEY_ITEM_WHEEL);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
        break;
    case 4:
        // Enable sprites to be shown inside WINOBJ
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
        // Create box sprites, but in OBJWIN mode
        for (i = 0; i < MAX_REGISTERED_ITEMS; i++)
            tBoxWinSprite[i] = CreateSprite(&sSpriteTemplate_KeyItemBoxWin, sKeyItemBoxXPos[i], sKeyItemBoxYPos[i], 0);
        tState = 1;
        break;
    }
}

#undef tState
#undef tBoxSprite
#undef tIconWindow
#undef tLabelSprite
#undef tLabelTailSprite
#undef tUsingRegisteredKeyItem

static void Task_PokerideItemWheel(u8 taskId) {
    u32 i, j;
    s16 *data = gTasks[taskId].data;

    // Redefine task data macros locally for this function
    #define tState data[0]
    #define tBoxSprite (data + 1)
    #define tBoxWinSprite (data + 1 + MAX_REGISTERED_ITEMS)
    #define tIconWindow (data + 1 + 2*MAX_REGISTERED_ITEMS)
    #define tLabelSprite data[13]
    #define tLabelTailSprite data[14]
    #define tUsingRegisteredKeyItem data[3]

    switch (tState)
    {
    case 0:
    {
        LoadSpritePalette(&sSpritePalette_PokerideItemBox);
        LoadSpriteSheetByTemplateKeyItem(&sSpriteTemplate_PokerideItemBox, 0);

        // Create label sprite centered with tail
        tLabelSprite = CreateLabelSprite(&sSpriteTemplate_PokerideLabel, 120, 20, &tLabelTailSprite);
        if (tLabelSprite == MAX_SPRITES) {
            tLabelSprite = MAX_SPRITES;  // Ensure it's set for cleanup
            tLabelTailSprite = MAX_SPRITES;
        }

        for (i = 0; i < MAX_REGISTERED_ITEMS; i++) {
            // Create box sprite
            tBoxSprite[i] = j = CreateSprite(&sSpriteTemplate_PokerideItemBox, sKeyItemBoxXPos[i], sKeyItemBoxYPos[i], 0);
            if (j < MAX_SPRITES)
                StartSpriteAffineAnim(&gSprites[j], i);
            tBoxWinSprite[i] = MAX_SPRITES;
            // For each registered pokeride item the player has, create a window and blit its icon to it
            tIconWindow[i] = WINDOW_NONE;
            if (!gSaveBlock1Ptr->registeredPokerideItems[i] || !CheckBagHasItem(gSaveBlock1Ptr->registeredPokerideItems[i], 1))
                continue;
            tIconWindow[i] = j = AddWindowParameterized(0, sKeyItemBoxXPos[i] / 8 - 2, sKeyItemBoxYPos[i] / 8 - 2, 4, 4, i == 3 ? 13 : 13 + i, 16*(i+9));
            if (j == WINDOW_NONE)
                continue;
            PutWindowTilemap(j);
            BlitItemIconToWindow(gSaveBlock1Ptr->registeredPokerideItems[i], j, 4, 4, i == 3 ? sKeyItemWheelExtraPalette : NULL);
            CopyWindowToVram(j, COPYWIN_FULL);
        }
        SetHBlankCallback(HBlankCB_KeyItemWheel);
        EnableInterrupts(INTR_FLAG_HBLANK);
        PlaySE(SE_WIN_OPEN);
        // in dark caves, we need to spawn OBJWIN sprites to show the boxes
        tState = (gSaveBlock1Ptr->flashLevel > 1) ? 4 : 1;
        break;
    }
    case 1: // process input
    {
        if (JOY_NEW(B_BUTTON) || JOY_NEW(L_BUTTON)) {
            PlaySE(SE_SELECT);
            tState = 3; // destroy and unfreeze
            break;
        }
        i = DpadInputToRegisteredItemIndexInArray(TRUE, gSaveBlock1Ptr->registeredPokerideItems);
        if (i == 0 || data[i] == MAX_SPRITES)
            break;
        // use item as if it was registered
        gSpecialVar_ItemId = gSaveBlock1Ptr->registeredPokerideItems[i - 1];
        PlaySE(SE_SELECT);
        StartSpriteAffineAnim(&gSprites[data[i]], i + 4 - 1);
        data[15] = data[i];
        tState = 2; // wait for anim
        break;
    }
    case 2:
        if (!gSprites[data[15]].affineAnimEnded)
            break;
        FreeKeyItemWheelGfx(data, PAL_TAG_POKERIDE_ITEM_WHEEL);
        i = CreateTask(GetItemFieldFunc(gSpecialVar_ItemId), 8);
        gTasks[i].tUsingRegisteredKeyItem = TRUE;
        DestroyTask(taskId);
        break;
    case 3:
        FreeKeyItemWheelGfx(data, PAL_TAG_POKERIDE_ITEM_WHEEL);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
        break;
    case 4:
        // Enable sprites to be shown inside WINOBJ
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
        // Create box sprites, but in OBJWIN mode
        for (i = 0; i < MAX_REGISTERED_ITEMS; i++)
            tBoxWinSprite[i] = CreateSprite(&sSpriteTemplate_PokerideItemBoxWin, sKeyItemBoxXPos[i], sKeyItemBoxYPos[i], 0);
        tState = 1;
        break;
    }

    #undef tState
    #undef tBoxSprite
    #undef tBoxWinSprite
    #undef tIconWindow
    #undef tLabelSprite
    #undef tLabelTailSprite
    #undef tUsingRegisteredKeyItem
}
