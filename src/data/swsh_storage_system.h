// ============================================================================
// PC Storage System - Data
// ============================================================================

// Wallpaper IDs
enum {
    WALLPAPER_BASE,
    WALLPAPER_NORMAL,
    WALLPAPER_FIGHTING,
    WALLPAPER_FLYING,
    WALLPAPER_POISON,
    WALLPAPER_GROUND,
    WALLPAPER_ROCK,
    WALLPAPER_BUG,
    WALLPAPER_GHOST,
    WALLPAPER_STEEL,
    WALLPAPER_FIRE,
    WALLPAPER_WATER,
    WALLPAPER_GRASS,
    WALLPAPER_ELECTRIC,
    WALLPAPER_PSYCHIC,
    WALLPAPER_ICE,
    WALLPAPER_DRAGON,
    WALLPAPER_DARK,
    WALLPAPER_FAIRY,
    WALLPAPER_STELLAR,
    WALLPAPER_COUNT
};
#define MAX_DEFAULT_WALLPAPER WALLPAPER_FLYING

// ============================================================================
// Structs
// ============================================================================

struct Wallpaper
{
    const u32 *tiles;
    const u32 *tilemap;
    const u16 *palettes;
};

struct StorageMessage
{
    const u8 *text;
    u8 format;
};

// ============================================================================
// Graphics - Storage System UI
// ============================================================================

static const u32 sSwShStorage_Gfx[]           = INCBIN_U32("graphics/pokemon_storage/swsh/tiles.4bpp.smol");
static const u16 sSwShStorage_Pal[]           = INCBIN_U16("graphics/pokemon_storage/swsh/tiles.gbapal");
static const u32 sSwShStorage_BG1_Tilemap[]   = INCBIN_U32("graphics/pokemon_storage/swsh/bg1.bin.smolTM");
static const u32 sSwShStorage_BG2_Tilemap[]   = INCBIN_U32("graphics/pokemon_storage/swsh/bg2.bin.smolTM");
static const u32 sMonInfo_Gfx[]               = INCBIN_U32("graphics/pokemon_storage/swsh/mon_info.4bpp.smol");
static const u32 sMonInfo_Tilemap[]           = INCBIN_U32("graphics/pokemon_storage/swsh/mon_info.bin.smolTM");
static const u16 sTextWindows_Pal[]           = INCBIN_U16("graphics/pokemon_storage/swsh/text_windows.gbapal");

static const u32 sBoxTitleFrame_Gfx[]         = INCBIN_U32("graphics/pokemon_storage/swsh/box_title_frame.4bpp.smol");
static const u32 sBoxTitleArrow_Gfx[]         = INCBIN_U32("graphics/pokemon_storage/swsh/box_title_arrow.4bpp.smol");
static const u32 sChooseBoxMenu_Gfx[]         = INCBIN_U32("graphics/pokemon_storage/swsh/choose_box_menu.4bpp.smol");
static const u32 sCursor_Gfx[]                = INCBIN_U32("graphics/pokemon_storage/swsh/cursor.4bpp.smol");
static const u16 sCursor_Pal[]                = INCBIN_U16("graphics/pokemon_storage/swsh/cursor.gbapal");
static const u32 sGenderIcons_Gfx[]           = INCBIN_U32("graphics/pokemon_storage/swsh/gender_icons.4bpp.smol");
static const u16 sMarkings_Pal[]              = INCBIN_U16("graphics/pokemon_storage/swsh/markings.gbapal");
static const u32 sMarkingsMenu_Gfx[]          = INCBIN_U32("graphics/pokemon_storage/swsh/markings_menu.4bpp.smol");
static const u32 sMessageWindow_Gfx[]         = INCBIN_U32("graphics/pokemon_storage/swsh/message_window.4bpp.smol");
static const u32 sShinyIcon_Gfx[]             = INCBIN_U32("graphics/pokemon_storage/swsh/shiny_icon.4bpp.smol");
static const u32 sStatLabels_Gfx[]            = INCBIN_U32("graphics/pokemon_storage/swsh/stat_labels.4bpp.smol");
static const ALIGNED(4) u8 sTypeIcons_Gfx[]   = INCBIN_U8("graphics/pokemon_storage/swsh/type_icons.4bpp");
static const u16 sTypeIcons_Pal[]             = INCBIN_U16("graphics/pokemon_storage/swsh/type_icons.gbapal");

// ============================================================================
// Graphics - Wallpapers
// ============================================================================

static const u32 sWallpaperTiles_Base[]       = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/base.4bpp.smol");
static const u32 sWallpaperTilemap_Base[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/base.bin.smolTM");
static const u16 sWallpaperPalette_Base[]     = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/base.gbapal");

static const u32 sWallpaperTiles_Normal[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/normal.4bpp.smol");
static const u32 sWallpaperTilemap_Normal[]   = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/normal.bin.smolTM");
static const u16 sWallpaperPalette_Normal[]   = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/normal.gbapal");

static const u32 sWallpaperTiles_Fighting[]   = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/fighting.4bpp.smol");
static const u32 sWallpaperTilemap_Fighting[] = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/fighting.bin.smolTM");
static const u16 sWallpaperPalette_Fighting[] = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/fighting.gbapal");

static const u32 sWallpaperTiles_Flying[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/flying.4bpp.smol");
static const u32 sWallpaperTilemap_Flying[]   = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/flying.bin.smolTM");
static const u16 sWallpaperPalette_Flying[]   = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/flying.gbapal");

static const u32 sWallpaperTiles_Poison[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/poison.4bpp.smol");
static const u32 sWallpaperTilemap_Poison[]   = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/poison.bin.smolTM");
static const u16 sWallpaperPalette_Poison[]   = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/poison.gbapal");

static const u32 sWallpaperTiles_Ground[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/ground.4bpp.smol");
static const u32 sWallpaperTilemap_Ground[]   = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/ground.bin.smolTM");
static const u16 sWallpaperPalette_Ground[]   = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/ground.gbapal");

static const u32 sWallpaperTiles_Rock[]       = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/rock.4bpp.smol");
static const u32 sWallpaperTilemap_Rock[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/rock.bin.smolTM");
static const u16 sWallpaperPalette_Rock[]     = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/rock.gbapal");

static const u32 sWallpaperTiles_Bug[]        = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/bug.4bpp.smol");
static const u32 sWallpaperTilemap_Bug[]      = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/bug.bin.smolTM");
static const u16 sWallpaperPalette_Bug[]      = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/bug.gbapal");

static const u32 sWallpaperTiles_Ghost[]      = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/ghost.4bpp.smol");
static const u32 sWallpaperTilemap_Ghost[]    = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/ghost.bin.smolTM");
static const u16 sWallpaperPalette_Ghost[]    = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/ghost.gbapal");

static const u32 sWallpaperTiles_Steel[]      = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/steel.4bpp.smol");
static const u32 sWallpaperTilemap_Steel[]    = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/steel.bin.smolTM");
static const u16 sWallpaperPalette_Steel[]    = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/steel.gbapal");

static const u32 sWallpaperTiles_Fire[]       = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/fire.4bpp.smol");
static const u32 sWallpaperTilemap_Fire[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/fire.bin.smolTM");
static const u16 sWallpaperPalette_Fire[]     = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/fire.gbapal");

static const u32 sWallpaperTiles_Water[]      = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/water.4bpp.smol");
static const u32 sWallpaperTilemap_Water[]    = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/water.bin.smolTM");
static const u16 sWallpaperPalette_Water[]    = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/water.gbapal");

static const u32 sWallpaperTiles_Grass[]      = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/grass.4bpp.smol");
static const u32 sWallpaperTilemap_Grass[]    = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/grass.bin.smolTM");
static const u16 sWallpaperPalette_Grass[]    = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/grass.gbapal");

static const u32 sWallpaperTiles_Electric[]   = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/electric.4bpp.smol");
static const u32 sWallpaperTilemap_Electric[] = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/electric.bin.smolTM");
static const u16 sWallpaperPalette_Electric[] = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/electric.gbapal");

static const u32 sWallpaperTiles_Psychic[]    = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/psychic.4bpp.smol");
static const u32 sWallpaperTilemap_Psychic[]  = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/psychic.bin.smolTM");
static const u16 sWallpaperPalette_Psychic[]  = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/psychic.gbapal");

static const u32 sWallpaperTiles_Ice[]        = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/ice.4bpp.smol");
static const u32 sWallpaperTilemap_Ice[]      = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/ice.bin.smolTM");
static const u16 sWallpaperPalette_Ice[]      = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/ice.gbapal");

static const u32 sWallpaperTiles_Dragon[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/dragon.4bpp.smol");
static const u32 sWallpaperTilemap_Dragon[]   = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/dragon.bin.smolTM");
static const u16 sWallpaperPalette_Dragon[]   = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/dragon.gbapal");

static const u32 sWallpaperTiles_Dark[]       = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/dark.4bpp.smol");
static const u32 sWallpaperTilemap_Dark[]     = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/dark.bin.smolTM");
static const u16 sWallpaperPalette_Dark[]     = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/dark.gbapal");

static const u32 sWallpaperTiles_Fairy[]      = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/fairy.4bpp.smol");
static const u32 sWallpaperTilemap_Fairy[]    = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/fairy.bin.smolTM");
static const u16 sWallpaperPalette_Fairy[]    = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/fairy.gbapal");

static const u32 sWallpaperTiles_Stellar[]    = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/stellar.4bpp.smol");
static const u32 sWallpaperTilemap_Stellar[]  = INCBIN_U32("graphics/pokemon_storage/swsh/wallpapers/stellar.bin.smolTM");
static const u16 sWallpaperPalette_Stellar[]  = INCBIN_U16("graphics/pokemon_storage/swsh/wallpapers/stellar.gbapal");

#define WALLPAPER_ENTRY(name) {sWallpaperTiles_##name, sWallpaperTilemap_##name, sWallpaperPalette_##name}

static const struct Wallpaper sSwShWallpapers[] =
{
    [WALLPAPER_BASE]     = WALLPAPER_ENTRY(Base),
    [WALLPAPER_NORMAL]   = WALLPAPER_ENTRY(Normal),
    [WALLPAPER_FIGHTING] = WALLPAPER_ENTRY(Fighting),
    [WALLPAPER_FLYING]   = WALLPAPER_ENTRY(Flying),
    [WALLPAPER_POISON]   = WALLPAPER_ENTRY(Poison),
    [WALLPAPER_GROUND]   = WALLPAPER_ENTRY(Ground),
    [WALLPAPER_ROCK]     = WALLPAPER_ENTRY(Rock),
    [WALLPAPER_BUG]      = WALLPAPER_ENTRY(Bug),
    [WALLPAPER_GHOST]    = WALLPAPER_ENTRY(Ghost),
    [WALLPAPER_STEEL]    = WALLPAPER_ENTRY(Steel),
    [WALLPAPER_FIRE]     = WALLPAPER_ENTRY(Fire),
    [WALLPAPER_WATER]    = WALLPAPER_ENTRY(Water),
    [WALLPAPER_GRASS]    = WALLPAPER_ENTRY(Grass),
    [WALLPAPER_ELECTRIC] = WALLPAPER_ENTRY(Electric),
    [WALLPAPER_PSYCHIC]  = WALLPAPER_ENTRY(Psychic),
    [WALLPAPER_ICE]      = WALLPAPER_ENTRY(Ice),
    [WALLPAPER_DRAGON]   = WALLPAPER_ENTRY(Dragon),
    [WALLPAPER_DARK]     = WALLPAPER_ENTRY(Dark),
    [WALLPAPER_FAIRY]    = WALLPAPER_ENTRY(Fairy),
    [WALLPAPER_STELLAR]  = WALLPAPER_ENTRY(Stellar),
};

// ============================================================================
// Text Strings
// ============================================================================

static const u8 gText_JustOnePkmn[]   = _("There is just one Pokémon with you.");
static const u8 gText_PartyFull[]     = _("Your party is full!");
static const u8 sText_Lv[]            = _("Lv");
static const u8 gPCText_Give[]        = _("Give");

struct {
    const u8 *text;
    const u8 *desc;
} static const sMainMenuTexts[OPTIONS_COUNT] =
{
    [OPTION_WITHDRAW]   = {COMPOUND_STRING("Withdraw Pokémon"), COMPOUND_STRING("Move Pokémon stored in boxes to\nyour party.")},
    [OPTION_DEPOSIT]    = {COMPOUND_STRING("Deposit Pokémon"),  COMPOUND_STRING("Store Pokémon in your party in boxes.")},
    [OPTION_MOVE_MONS]  = {COMPOUND_STRING("Move Pokémon"),     COMPOUND_STRING("Organize the Pokémon in boxes and\nin your party.")},
    [OPTION_MOVE_ITEMS] = {COMPOUND_STRING("Move Items"),       COMPOUND_STRING("Move items held by any Pokémon\nin a box or your party.")},
    [OPTION_EXIT]       = {COMPOUND_STRING("See ya!"),          COMPOUND_STRING("Return to the previous menu.")}
};

static const u8 *const sMenuTexts[] =
{
    [MENU_CANCEL]     = COMPOUND_STRING("Cancel"),
    [MENU_STORE]      = COMPOUND_STRING("Store"),
    [MENU_WITHDRAW]   = COMPOUND_STRING("Withdraw"),
    [MENU_MOVE]       = COMPOUND_STRING("Move"),
    [MENU_SHIFT]      = COMPOUND_STRING("Shift"),
    [MENU_PLACE]      = COMPOUND_STRING("Place"),
    [MENU_SUMMARY]    = COMPOUND_STRING("Summary"),
    [MENU_RELEASE]    = COMPOUND_STRING("Release"),
    [MENU_MARK]       = COMPOUND_STRING("Mark"),
    [MENU_JUMP]       = COMPOUND_STRING("Jump"),
    [MENU_WALLPAPER]  = COMPOUND_STRING("Wallpaper"),
    [MENU_NAME]       = COMPOUND_STRING("Name"),
    [MENU_TAKE]       = COMPOUND_STRING("Take"),
    [MENU_GIVE]       = gPCText_Give,
    [MENU_GIVE_2]     = gPCText_Give,
    [MENU_SWITCH]     = COMPOUND_STRING("Switch"),
    [MENU_BAG]        = COMPOUND_STRING("Bag"),
    [MENU_SELECT]     = COMPOUND_STRING("Select"),
    [MENU_BASE]       = COMPOUND_STRING("Default"),
    [MENU_NORMAL]     = COMPOUND_STRING("Normal"),
    [MENU_FIGHTING]   = COMPOUND_STRING("Fighting"),
    [MENU_FLYING]     = COMPOUND_STRING("Flying"),
    [MENU_POISON]     = COMPOUND_STRING("Poison"),
    [MENU_GROUND]     = COMPOUND_STRING("Ground"),
    [MENU_ROCK]       = COMPOUND_STRING("Rock"),
    [MENU_BUG]        = COMPOUND_STRING("Bug"),
    [MENU_GHOST]      = COMPOUND_STRING("Ghost"),
    [MENU_STEEL]      = COMPOUND_STRING("Steel"),
    [MENU_FIRE]       = COMPOUND_STRING("Fire"),
    [MENU_WATER]      = COMPOUND_STRING("Water"),
    [MENU_GRASS]      = COMPOUND_STRING("Grass"),
    [MENU_ELECTRIC]   = COMPOUND_STRING("Electric"),
    [MENU_PSYCHIC]    = COMPOUND_STRING("Psychic"),
    [MENU_ICE]        = COMPOUND_STRING("Ice"),
    [MENU_DRAGON]     = COMPOUND_STRING("Dragon"),
    [MENU_DARK]       = COMPOUND_STRING("Dark"),
    [MENU_FAIRY]      = COMPOUND_STRING("Fairy"),
    [MENU_STELLAR]    = COMPOUND_STRING("Stellar"),
    [MENU_COUNT]      = gText_EmptyString2,
};

// ============================================================================
// Messages
// ============================================================================

static const struct StorageMessage sMessages[] =
{
    [MSG_BOX_IS_FULL]          = {COMPOUND_STRING("The box is full."),           MSG_VAR_NONE},
    [MSG_RELEASE_POKE]         = {COMPOUND_STRING("Release this Pokémon?"),      MSG_VAR_NONE},
    [MSG_WAS_RELEASED]         = {COMPOUND_STRING("{DYNAMIC 0} was released."),  MSG_VAR_RELEASE_MON_1},
    [MSG_BYE_BYE]              = {COMPOUND_STRING("Bye-bye, {DYNAMIC 0}!"),      MSG_VAR_RELEASE_MON_3},
    [MSG_LAST_POKE]            = {COMPOUND_STRING("That's your last Pokémon!"),  MSG_VAR_NONE},
    [MSG_PARTY_FULL]           = {gText_YourPartysFull,                          MSG_VAR_NONE},
    [MSG_HOLDING_POKE]         = {COMPOUND_STRING("You're holding a Pokémon!"),  MSG_VAR_NONE},
    [MSG_WHICH_ONE_WILL_TAKE]  = {COMPOUND_STRING("Which one will you take?"),   MSG_VAR_NONE},
    [MSG_CANT_RELEASE_EGG]     = {COMPOUND_STRING("You can't release an egg."),  MSG_VAR_NONE},
    [MSG_CONTINUE_BOX]         = {COMPOUND_STRING("Continue P.C. operations?"),  MSG_VAR_NONE},
    [MSG_CAME_BACK]            = {COMPOUND_STRING("{DYNAMIC 0} came back!"),     MSG_VAR_MON_NAME_1},
    [MSG_WORRIED]              = {COMPOUND_STRING("Was it worried about you?"),  MSG_VAR_NONE},
    [MSG_SURPRISE]             = {COMPOUND_STRING("… … … … !"),                  MSG_VAR_NONE},
    [MSG_PLEASE_REMOVE_MAIL]   = {COMPOUND_STRING("Please remove the mail."),    MSG_VAR_NONE},
    [MSG_PLACED_IN_BAG]        = {COMPOUND_STRING("Placed item in the bag."),    MSG_VAR_ITEM_NAME},
    [MSG_BAG_FULL]             = {COMPOUND_STRING("The bag is full."),           MSG_VAR_NONE},
    [MSG_PUT_IN_BAG]           = {COMPOUND_STRING("Put this item in the bag?"),  MSG_VAR_NONE},
    [MSG_CANT_STORE_MAIL]      = {COMPOUND_STRING("Mail can't be stored!"),      MSG_VAR_NONE},
};

// ============================================================================
// Window Templates
// ============================================================================

static const struct WindowTemplate sWindowTemplate_MainMenu =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x1,
};

static const struct WindowTemplate sYesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 11,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x5C,
};

static const struct WindowTemplate sWindowTemplate_MultiMove =
{
    .bg = 0,
    .tilemapLeft = 10,
    .tilemapTop = 3,
    .width = 19,
    .height = 16,
    .paletteNum = 9,
    .baseBlock = 0x1,
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_MESSAGE] = {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 17,
        .width = 20,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 44,
    },
    [WIN_ITEM_DESC] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = 21,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 44,
    },
    [WIN_MON_INFO_NICKNAME_LEFT] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 23,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 202
    },
    [WIN_MON_INFO_LEVEL_LEFT] = {
        .bg = 0,
        .tilemapLeft = 9,
        .tilemapTop = 23,
        .width = 4,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 218
    },
    [WIN_MON_INFO_STATS_COL1_LEFT] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 27,
        .width = 3,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 226
    },
    [WIN_MON_INFO_STATS_COL2_LEFT] = {
        .bg = 0,
        .tilemapLeft = 10,
        .tilemapTop = 27,
        .width = 3,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 244
    },
    [WIN_MON_INFO_ABILITY_LEFT] = {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 34,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 262
    },
    [WIN_MON_INFO_ITEM_LEFT] = {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 36,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 280
    },
    [WIN_MON_INFO_NICKNAME_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 43,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 202
    },
    [WIN_MON_INFO_LEVEL_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 26,
        .tilemapTop = 43,
        .width = 4,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 218
    },
    [WIN_MON_INFO_STATS_COL1_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 47,
        .width = 3,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 226
    },
    [WIN_MON_INFO_STATS_COL2_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 27,
        .tilemapTop = 47,
        .width = 3,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 244
    },
    [WIN_MON_INFO_ABILITY_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 54,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 262
    },
    [WIN_MON_INFO_ITEM_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 56,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 280
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sTextColors[][3] =
{
    {1, 2, 3}, // Standard menus, mon info (stats, ability, item)
    {4, 2, 5}, // Mon info (nickname and level) (grey BG)
    {0, 4, 7}, // Choose box menu - actually uses PALTAG_MISC_3 and not bg pal 15
    {0, 1, 6}, // Main message window
};


// ============================================================================
// BG Templates
// ============================================================================

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

// ============================================================================
// Choose Box Menu Sprites
// ============================================================================

static const struct OamData sOamData_ChooseBoxMenu =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .size = SPRITE_SIZE(32x32),
    .x = 0,
    .matrixNum = 0,
    .shape = SPRITE_SHAPE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_ChooseBoxMenu =
{
    .data = sChooseBoxMenu_Gfx,
    .size = (32 * 32) / 2,
    .tag = GFXTAG_BOX_SELECTION,
};
    
static const struct SpriteTemplate sSpriteTemplate_ChooseBoxMenu =
{
    .tileTag = GFXTAG_BOX_SELECTION,
    .paletteTag = PALTAG_MISC_3,
    .oam = &sOamData_ChooseBoxMenu,
};

// ============================================================================
// Box Selection Mon Count Sprite (loaded dynamically)
// ============================================================================

static const struct OamData sOamData_ChooseBoxMenu_MonCount =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .size = SPRITE_SIZE(16x16),
    .x = 0,
    .matrixNum = 0,
    .shape = SPRITE_SHAPE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_ChooseBoxMenu_MonCount =
{
    .tileTag = GFXTAG_BOX_SELECTION_PER_30,
    .paletteTag = PALTAG_MISC_3,
    .oam = &sOamData_ChooseBoxMenu_MonCount,
};

// ============================================================================
// Box Title Frame Sprites
// ============================================================================

static const struct OamData sOamData_BoxTitleFrame =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .size = SPRITE_SIZE(32x16),
    .x = 0,
    .matrixNum = 0,
    .shape = SPRITE_SHAPE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_BoxTitleFrame_0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_BoxTitleFrame_1[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_BoxTitleFrame_2[] = {
    ANIMCMD_FRAME(0, 0, TRUE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_BoxTitleFrame[] = {
    sSpriteAnim_BoxTitleFrame_0,
    sSpriteAnim_BoxTitleFrame_1,
    sSpriteAnim_BoxTitleFrame_2,
};

static const u8 sBoxTitleFrameAnims[4] = {0, 1, 1, 2};

static const struct CompressedSpriteSheet sSpriteSheet_BoxTitleFrame =
{
    .data = sBoxTitleFrame_Gfx,
    .size = (32 * 16 * 2) / 2,
    .tag = GFXTAG_BOX_TITLE_FRAME,
};

static const struct SpriteTemplate sSpriteTemplate_BoxTitleFrame =
{
    .tileTag = GFXTAG_BOX_TITLE_FRAME,
    .paletteTag = PALTAG_MISC_1,
    .oam = &sOamData_BoxTitleFrame,
    .anims = sSpriteAnimTable_BoxTitleFrame,
};

// ============================================================================
// Box Title Arrow Sprites
// ============================================================================

static const struct OamData sOamData_BoxTitleArrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .size = SPRITE_SIZE(8x8),
    .x = 0,
    .matrixNum = 0,
    .shape = SPRITE_SHAPE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_BoxTitleArrow_Left[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_BoxTitleArrow_Right[] = {
    ANIMCMD_FRAME(0, 0, TRUE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_BoxTitleArrow[] = {
    sSpriteAnim_BoxTitleArrow_Left,
    sSpriteAnim_BoxTitleArrow_Right,
};

static const struct CompressedSpriteSheet sSpriteSheet_BoxTitleArrow =
{
    .data = sBoxTitleArrow_Gfx,
    .size = (8 * 8) / 2,
    .tag = GFXTAG_BOX_TITLE_ARROW,
};

static const struct SpriteTemplate sSpriteTemplate_BoxTitleArrow =
{
    .tileTag = GFXTAG_BOX_TITLE_ARROW,
    .paletteTag = PALTAG_MISC_1,
    .oam = &sOamData_BoxTitleArrow,
    .anims = sSpriteAnimTable_BoxTitleArrow,
    .callback = SpriteCB_Arrow,
};

// ============================================================================
// Box Title Sprites
// ============================================================================

static const u16 sUnusedColor = RGB(26, 29, 8);

#define BOX_TITLE_SHADOW_HOVER  RGB(12, 12, 12)
#define BOX_TITLE_TEXT_HOVER    RGB_WHITE
#define BOX_TITLE_FRAME_HOVER   RGB_BLACK
#define BOX_TITLE_SHADOW_MAIN   RGB(26, 26, 25)
#define BOX_TITLE_TEXT_MAIN     RGB_BLACK
#define BOX_TITLE_FRAME_MAIN    RGB_WHITE

static const struct OamData sOamData_BoxTitle =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2
};

static const union AnimCmd sAnim_BoxTitle_Left[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_BoxTitle_Right[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_BoxTitle[] =
{
    sAnim_BoxTitle_Left,
    sAnim_BoxTitle_Right
};

static const struct SpriteTemplate sSpriteTemplate_BoxTitle =
{
    .tileTag = GFXTAG_BOX_TITLE,
    .paletteTag = PALTAG_MISC_1,
    .oam = &sOamData_BoxTitle,
    .anims = sAnims_BoxTitle,
};

// ============================================================================
// Cursor Sprites
// ============================================================================

static const struct CompressedSpriteSheet sSpriteSheet_Cursor[] =
{
    {
        .data = sCursor_Gfx,
        .size = (16 * 16 * 3) / 2,
        .tag = GFXTAG_CURSOR,
    },
    {},
};

static const struct SpritePalette sSpritePal_Cursor[] =
{
    {
        .data = sCursor_Pal,
        .tag = PALTAG_MISC_1,
    },
    {
        .data = sCursor_Pal + 16,
        .tag = PALTAG_MISC_2,
    },
    {
        .data = sCursor_Pal + 32,
        .tag = PALTAG_MISC_3,
    },
    {},
};

static const struct OamData sOamData_Cursor =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static const union AnimCmd sAnim_Cursor_Bouncing[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_Cursor_Main[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Cursor[] =
{
    [CURSOR_ANIM_BOUNCE] = sAnim_Cursor_Bouncing,
    [CURSOR_ANIM_MAIN]   = sAnim_Cursor_Main,
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_MISC_1,
    .oam = &sOamData_Cursor,
    .anims = sAnims_Cursor,
};

// ============================================================================
// Mon Icon Sprites
// ============================================================================

static const struct OamData sOamData_MonIcon;
static const struct SpriteTemplate sSpriteTemplate_MonIcon =
{
    .tileTag = GFXTAG_MON_ICON,
    .paletteTag = PALTAG_MON_ICON_0,
    .oam = &sOamData_MonIcon,
};

static const struct OamData sOamData_MonIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sAffineAnim_ReleaseMon_Release[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 120),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_ReleaseMon_CameBack[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(16, 16, 0, 15),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_ReleaseMon[] =
{
    [RELEASE_ANIM_RELEASE]   = sAffineAnim_ReleaseMon_Release,
    [RELEASE_ANIM_CAME_BACK] = sAffineAnim_ReleaseMon_CameBack
};

// ============================================================================
// Gender Icon Sprites
// ============================================================================

static const struct OamData sOamData_GenderIcons =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 7,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_GenderFemale[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_GenderMale[] = {
    ANIMCMD_FRAME(2, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_GenderIcons[] = {
    sSpriteAnim_GenderFemale,
    sSpriteAnim_GenderMale,
};

static const struct CompressedSpriteSheet sSpriteSheet_GenderIcons =
{
    .data = sGenderIcons_Gfx,
    .size = (8 * 16 * 2) / 2,
    .tag = GFXTAG_GENDER_ICON
};

static const struct SpriteTemplate sSpriteTemplate_GenderIcons =
{
    .tileTag = GFXTAG_GENDER_ICON,
    .paletteTag = PALTAG_MISC_2,
    .oam = &sOamData_GenderIcons,
    .anims = sSpriteAnimTable_GenderIcons,
    .images = NULL,
};

// ============================================================================
// Shiny Icon Sprites
// ============================================================================

static const struct OamData sOamData_ShinyIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_ShinyIcon =
{
    .data = sShinyIcon_Gfx,
    .size = (8 * 8) / 2,
    .tag = GFXTAG_SHINY_ICON
};

static const struct SpriteTemplate sSpriteTemplate_ShinyIcon =
{
    .tileTag = GFXTAG_SHINY_ICON,
    .paletteTag = PALTAG_MISC_2,
    .oam = &sOamData_ShinyIcon,
};

// ============================================================================
// Stat Label Sprites
// ============================================================================

static const struct OamData sOamData_StatLabels =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
};

static const union AnimCmd sSpriteAnim_StatAtk[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatDef[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatSpAtk[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatSpDef[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_StatSpeed[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_StatLabels[] = {
    sSpriteAnim_StatAtk,
    sSpriteAnim_StatDef,
    sSpriteAnim_StatSpAtk,
    sSpriteAnim_StatSpDef,
    sSpriteAnim_StatSpeed,
};

static const struct CompressedSpriteSheet sSpriteSheet_StatLabels =
{
    .data = sStatLabels_Gfx,
    .size = (16 * 16 * 5) / 2,
    .tag = GFXTAG_STAT_LABELS
};

static const struct SpriteTemplate sSpriteTemplate_StatLabels =
{
    .tileTag = GFXTAG_STAT_LABELS,
    .paletteTag = PALTAG_MISC_2,
    .oam = &sOamData_StatLabels,
    .anims = sSpriteAnimTable_StatLabels,
};

// ============================================================================
// Type Icon Sprites
// ============================================================================

static const struct OamData sOamData_TypeIcons =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// Type icons now use DMA copy instead of animations to save VRAM (only loads 2 slots instead of all 21 types)
// Uncompressed sprite sheet (only 2 slots loaded to save VRAM)
static const struct SpriteSheet sSpriteSheet_TypeIcons =
{
    .data = sTypeIcons_Gfx,
    .size = 2 * 0x100, // Only load 2 type icon slots (saves 4.75 KB VRAM)
    .tag = GFXTAG_TYPE_ICON,
};

static const struct SpriteTemplate sSpriteTemplate_TypeIcons =
{
    .tileTag = GFXTAG_TYPE_ICON,
    .paletteTag = PALTAG_TYPE_ICON,
    .oam = &sOamData_TypeIcons,
};

// ============================================================================
// Markings Menu Sprites
// ============================================================================

static const struct CompressedSpriteSheet sSpriteSheet_MarkingsMenu =
{
    .data = sMarkingsMenu_Gfx,
    .size = (
        32 * 32 * 2 + // marking menu window
        8 * 8 * 8 +   // marking menu marks
        16 * 16 * 3   // marking menu cursor
    ) / 2,
    .tag = GFXTAG_MARKING_MENU,
};

static const struct OamData sOamData_MarkingsMenu_Window =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_MarkingsMenu_Window_0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_Window_1[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_Window_2[] = {
    ANIMCMD_FRAME(0, 0, TRUE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_MarkingsMenu_Window[] = {
    sAnim_MarkingsMenu_Window_0,
    sAnim_MarkingsMenu_Window_1,
    sAnim_MarkingsMenu_Window_2,
};

static const u8 sMarkingsMenu_WindowAnims[3] = {0, 1, 2};

static const struct SpriteTemplate sSpriteTemplate_MarkingsMenu_Window =
{
    .tileTag = GFXTAG_MARKING_MENU,
    .paletteTag = PALTAG_MISC_3,
    .oam = &sOamData_MarkingsMenu_Window,
    .anims = sAnims_MarkingsMenu_Window,
};

static const struct OamData sOamData_MarkingsMenu_Marks =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_MarkingsMenu_CircleOff[] = {
    ANIMCMD_FRAME(32, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_CircleOn[] = {
    ANIMCMD_FRAME(33, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_SquareOff[] = {
    ANIMCMD_FRAME(34, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_SquareOn[] = {
    ANIMCMD_FRAME(35, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_TriangleOff[] = {
    ANIMCMD_FRAME(36, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_TriangleOn[] = {
    ANIMCMD_FRAME(37, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_HeartOff[] = {
    ANIMCMD_FRAME(38, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MarkingsMenu_HeartOn[] = {
    ANIMCMD_FRAME(39, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_MarkingsMenu_Marks[] = {
    sAnim_MarkingsMenu_CircleOff,
    sAnim_MarkingsMenu_CircleOn,
    sAnim_MarkingsMenu_SquareOff,
    sAnim_MarkingsMenu_SquareOn,
    sAnim_MarkingsMenu_TriangleOff,
    sAnim_MarkingsMenu_TriangleOn,
    sAnim_MarkingsMenu_HeartOff,
    sAnim_MarkingsMenu_HeartOn,
};

static const struct SpriteTemplate sSpriteTemplate_MarkingsMenu_Marks =
{
    .tileTag = GFXTAG_MARKING_MENU,
    .paletteTag = PALTAG_MISC_3,
    .oam = &sOamData_MarkingsMenu_Marks,
    .anims = sAnims_MarkingsMenu_Marks,
};

// Marking menu cursor (16x16, 3 frames)
static const struct OamData sOamData_MarkingsMenu_Cursor =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_MarkingsMenu_Cursor_Bouncing[] = {
    ANIMCMD_FRAME(40, 8, FALSE, FALSE),
    ANIMCMD_FRAME(44, 8, FALSE, FALSE),
    ANIMCMD_FRAME(48, 8, FALSE, FALSE),
    ANIMCMD_FRAME(44, 8, FALSE, FALSE),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_MarkingsMenu_Cursor_Main[] = {
    ANIMCMD_FRAME(44, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_MarkingsMenu_Cursor[] = {
    sAnim_MarkingsMenu_Cursor_Bouncing,
    sAnim_MarkingsMenu_Cursor_Main,
};

static const struct SpriteTemplate sSpriteTemplate_MarkingsMenu_Cursor =
{
    .tileTag = GFXTAG_MARKING_MENU,
    .paletteTag = PALTAG_MISC_3,
    .oam = &sOamData_MarkingsMenu_Cursor,
    .anims = sAnims_MarkingsMenu_Cursor,
};

// ============================================================================
// Message window sprites
// ============================================================================

static const struct OamData sOamData_MessageWindow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .size = SPRITE_SIZE(32x32),
    .x = 0,
    .matrixNum = 0,
    .shape = SPRITE_SHAPE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_MessageWindow_0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MessageWindow_1[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MessageWindow_2[] = {
    ANIMCMD_FRAME(0, 0, TRUE, TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_MessageWindow[] = {
    sSpriteAnim_MessageWindow_0,
    sSpriteAnim_MessageWindow_1,
    sSpriteAnim_MessageWindow_2,
};

static const u8 sMessageWindowAnims[6] = {0, 1, 1, 1, 1, 2};

static const struct CompressedSpriteSheet sSpriteSheet_MessageWindow =
{
    .data = sMessageWindow_Gfx,
    .size = (32 * 32 * 2) / 2,
    .tag = GFXTAG_MESSAGE_WINDOW,
};

static const struct SpriteTemplate sSpriteTemplate_MessageWindow =
{
    .tileTag = GFXTAG_MESSAGE_WINDOW,
    .paletteTag = PALTAG_MISC_3,
    .oam = &sOamData_MessageWindow,
    .anims = sSpriteAnimTable_MessageWindow,
};

// ============================================================================
// Item Icon Sprites
// ============================================================================

static const struct OamData sOamData_ItemIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sAffineAnim_ItemIcon_Small[] =
{
    AFFINEANIMCMD_FRAME(192, 192, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_ItemIcon_Appear[] =
{
    AFFINEANIMCMD_FRAME(152, 152, 0, 0),
    AFFINEANIMCMD_FRAME(5, 5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_ItemIcon_Disappear[] =
{
    AFFINEANIMCMD_FRAME(192, 192, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_ItemIcon_PickUp[] =
{
    AFFINEANIMCMD_FRAME(192, 192, 0, 0),
    AFFINEANIMCMD_FRAME(6, 6, 0, 12),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_ItemIcon_PutDown[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-6, -6, 0, 12),
    AFFINEANIMCMD_FRAME(192, 192, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_ItemIcon_PutAway[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, 0, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_ItemIcon_Large[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_ItemIcon[] =
{
    [ITEM_ANIM_NONE]      = sAffineAnim_ItemIcon_Small,
    [ITEM_ANIM_APPEAR]    = sAffineAnim_ItemIcon_Appear,
    [ITEM_ANIM_DISAPPEAR] = sAffineAnim_ItemIcon_Disappear,
    [ITEM_ANIM_PICK_UP]   = sAffineAnim_ItemIcon_PickUp,
    [ITEM_ANIM_PUT_DOWN]  = sAffineAnim_ItemIcon_PutDown,
    [ITEM_ANIM_PUT_AWAY]  = sAffineAnim_ItemIcon_PutAway,
    [ITEM_ANIM_LARGE]     = sAffineAnim_ItemIcon_Large
};

static const struct SpriteTemplate sSpriteTemplate_ItemIcon =
{
    .tileTag = GFXTAG_ITEM_ICON_0,
    .paletteTag = PALTAG_ITEM_ICON_0,
    .oam = &sOamData_ItemIcon,
    .affineAnims = sAffineAnims_ItemIcon,
};
