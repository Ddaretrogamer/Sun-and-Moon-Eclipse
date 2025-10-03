const u32 gItemIcon_TransformDitto[] = INCBIN_U32("graphics/items/icons/transformditto.4bpp.lz");
const u16 gItemIconPalette_TransformDitto[] = INCBIN_U16("graphics/items/icon_palettes/transformditto.gbapal");
const u32 gItemIcon_TransformSurf[] = INCBIN_U32("graphics/items/icons/transformsurf3.4bpp.lz");
const u16 gItemIconPalette_TransformSurf[] = INCBIN_U16("graphics/items/icon_palettes/transformsurf3.gbapal");
const u32 gItemIcon_TransformStrength[] = INCBIN_U32("graphics/items/icons/transformstrength.4bpp.lz");
const u16 gItemIconPalette_TransformStrength[] = INCBIN_U16("graphics/items/icon_palettes/transformstrength.gbapal");
const u32 gItemIcon_TransformShrink[] = INCBIN_U32("graphics/items/icons/transformshrink2.4bpp.lz");
const u16 gItemIconPalette_TransformShrink[] = INCBIN_U16("graphics/items/icon_palettes/transformshrink2.gbapal");
const u32 gItemIcon_TransformFly[] = INCBIN_U32("graphics/items/icons/transformfly.4bpp.lz");
const u16 gItemIconPalette_TransformFly[] = INCBIN_U16("graphics/items/icon_palettes/transformfly.gbapal");
const u32 gItemIcon_TransformCut[] = INCBIN_U32("graphics/items/icons/transformcut.4bpp.lz");
const u16 gItemIconPalette_TransformCut[] = INCBIN_U16("graphics/items/icon_palettes/transformcut.gbapal");
const u32 gItemIcon_TransformMachBike[] = INCBIN_U32("graphics/items/icons/transformmachbike.4bpp.lz");
const u16 gItemIconPalette_TransformMachBike[] = INCBIN_U16("graphics/items/icon_palettes/transformmachbike.gbapal");
const u32 gItemIcon_TransformRockSmash[] = INCBIN_U32("graphics/items/icons/transformrocksmash.4bpp.lz");
const u16 gItemIconPalette_TransformRockSmash[] = INCBIN_U16("graphics/items/icon_palettes/transformrocksmash.gbapal"); 
const u32 gItemIcon_TransformAcrobike[] = INCBIN_U32("graphics/items/icons/transformacrobike.4bpp.lz");
const u16 gItemIconPalette_TransformAcrobike[] = INCBIN_U16("graphics/items/icon_palettes/transformacrobike.gbapal");
const u32 gItemIcon_TransformFlash[] = INCBIN_U32("graphics/items/icons/transformflash.4bpp.lz");
const u16 gItemIconPalette_TransformFlash[] = INCBIN_U16("graphics/items/icon_palettes/transformflash.gbapal");
const u32 gItemIcon_TransformWaterfall[] = INCBIN_U32("graphics/items/icons/transformwaterfall.4bpp.lz");
const u16 gItemIconPalette_TransformWaterfall[] = INCBIN_U16("graphics/items/icon_palettes/transformwaterfall.gbapal");
const u32 gItemIcon_TransformDive[] = INCBIN_U32("graphics/items/icons/transformdive.4bpp.lz");
const u16 gItemIconPalette_TransformDive[] = INCBIN_U16("graphics/items/icon_palettes/transformdive.gbapal");

const struct Transformation gTransformations[] =
{
    [SPECIES_DITTO] =
    {
        .name = _("Ditto"),
        .fieldUseFunc = ItemUseOutOfBattle_DittoTransform,
        .iconPic = gItemIcon_TransformDitto,
        .iconPalette = gItemIconPalette_TransformDitto,
        .battleSpecies = SPECIES_DITTO,
        .ability = ABILITY_LIMBER,
        .moves = {
            MOVE_TRANSFORM,
            MOVE_NONE,
            MOVE_NONE,
            MOVE_NONE,
        },
    },

    [SPECIES_NOIVERN] =
    {
        .name = _("Noivern"),
        .fieldUseFunc = ItemUseOutOfBattle_FlyTransform,
        .iconPic = gItemIcon_TransformFly,
        .iconPalette = gItemIconPalette_TransformFly,
        .battleSpecies = SPECIES_DITTO_NOIVERN,
        .ability = ABILITY_INFILTRATOR,
        .moves = {
            MOVE_AIR_CUTTER,
            MOVE_DRAGON_BREATH,
            MOVE_SUPERSONIC,
            MOVE_SUPER_FANG,
        },
    },

    [SPECIES_MARILL] =
    {
        .name = _("MARILL"),
        .fieldUseFunc = ItemUseOutOfBattle_SurfTransform,
        .iconPic = gItemIcon_TransformSurf,
        .iconPalette = gItemIconPalette_TransformSurf,
        .battleSpecies = SPECIES_DITTO_MARILL,
        .ability = ABILITY_HUGE_POWER,
        .moves = {
            MOVE_SURF,
            MOVE_AQUA_JET,
            MOVE_COVET,
            MOVE_RAIN_DANCE,
        },
    },

    [SPECIES_RHYHORN] =
    {
        .name = _("Rhyhorn"),
        .fieldUseFunc = ItemUseOutOfBattle_RockSmashTransform,
        .iconPic = gItemIcon_TransformRockSmash,
        .iconPalette = gItemIconPalette_TransformRockSmash,   
        .battleSpecies = SPECIES_DITTO_RHYHORN,
        .ability = ABILITY_LIGHTNING_ROD,
        .moves = {
            MOVE_ROCK_THROW,
            MOVE_HORN_ATTACK,
            MOVE_ROCK_POLISH,
            MOVE_ROCK_SMASH,
        },
    },

    [SPECIES_CUTIEFLY] =
    {
        .name = _("Cutiefly"),
        .fieldUseFunc = ItemUseOutOfBattle_ShrinkTransform,
        .iconPic = gItemIcon_TransformShrink,
        .iconPalette = gItemIconPalette_TransformShrink,
        .battleSpecies = SPECIES_DITTO_CUTIEFLY,
        .ability = ABILITY_SHIELD_DUST,
        .moves = {
            MOVE_BUG_BUZZ,
            MOVE_DAZZLING_GLEAM,
            MOVE_STICKY_WEB,
            MOVE_PSYCHIC,
        },
    },
    [SPECIES_ARCANINE] =
    {
        .name = _("Arcanine"),
        .fieldUseFunc = ItemUseOutOfBattle_MachBikeTransform,
        .iconPic = gItemIcon_TransformMachBike,
        .iconPalette = gItemIconPalette_TransformMachBike,
        .battleSpecies = SPECIES_DITTO_ARCANINE,
        .ability = ABILITY_INTIMIDATE,
        .moves = {
            MOVE_FIRE_FANG,
            MOVE_BITE,
            MOVE_AERIAL_ACE,
            MOVE_THUNDER_FANG,
        },
    },
    [SPECIES_WEAVILE] =
    {
        .name = _("Weavile"),
        .fieldUseFunc = ItemUseOutOfBattle_AcroBikeTransform,
        .iconPic = gItemIcon_TransformAcrobike,
        .iconPalette = gItemIconPalette_TransformAcrobike,
        .battleSpecies = SPECIES_DITTO_WEAVILE,
        .ability = ABILITY_PRESSURE,
        .moves = {
            MOVE_ICE_SHARD,
            MOVE_ICE_PUNCH,
            MOVE_SHADOW_CLAW,
            MOVE_BRICK_BREAK,
        },
    },
    [SPECIES_LURANTIS] =
    {
        .name = _("Lurantis"),
        .fieldUseFunc = ItemUseOutOfBattle_CutTransform,
        .iconPic = gItemIcon_TransformCut,
        .iconPalette = gItemIconPalette_TransformCut,
        .battleSpecies = SPECIES_DITTO_LURANTIS,
        .ability = ABILITY_SWARM,
        .moves = {
            MOVE_AERIAL_ACE,
            MOVE_BUG_BITE,
            MOVE_TRAILBLAZE,
            MOVE_CUT,
        },
    },
    [SPECIES_CHINCHOU] =
    {
        .name = _("Chinchou"),
        .fieldUseFunc = ItemUseOutOfBattle_DiveTransform,
        .iconPic = gItemIcon_TransformDive,
        .iconPalette = gItemIconPalette_TransformDive,
        .battleSpecies = SPECIES_DITTO_CHINCHOU,
        .ability = ABILITY_VOLT_ABSORB,
        .moves = {
            MOVE_THUNDER_WAVE,
            MOVE_DISCHARGE,
            MOVE_DIVE,
            MOVE_DAZZLING_GLEAM,
        },
    },
    [SPECIES_DRAGONAIR] =
    {
        .name = _("Dragonair"),
        .fieldUseFunc = ItemUseOutOfBattle_WaterfallTransform,
        .iconPic = gItemIcon_TransformWaterfall,
        .iconPalette = gItemIconPalette_TransformWaterfall,
        .battleSpecies = SPECIES_DITTO_DRAGONAIR,
        .ability = ABILITY_SHED_SKIN,
        .moves = {
            MOVE_OUTRAGE,
            MOVE_WATERFALL,
            MOVE_IRON_HEAD,
            MOVE_SAFEGUARD,
        },
    },
    [SPECIES_MACHAMP] =
    {
        .name = _("Machamp"),
        .fieldUseFunc = ItemUseOutOfBattle_StrengthTransform,
        .iconPic = gItemIcon_TransformStrength,
        .iconPalette = gItemIconPalette_TransformStrength,
        .battleSpecies = SPECIES_DITTO_MACHAMP,
        .ability = ABILITY_NO_GUARD,
        .moves = {
            MOVE_STRENGTH,
            MOVE_FIRE_PUNCH,
            MOVE_CROSS_CHOP,
            MOVE_THUNDER_PUNCH,
        },
    },
    [SPECIES_PIKACHU] =
    {
        .name = _("Pikachu"),
        .fieldUseFunc = ItemUseOutOfBattle_FlashTransform,
        .iconPic = gItemIcon_TransformFlash,
        .iconPalette = gItemIconPalette_TransformFlash,
        .battleSpecies = SPECIES_DITTO_PIKACHU,
        .ability = ABILITY_STATIC,
        .moves = {
            MOVE_NUZZLE,
            MOVE_IRON_TAIL,
            MOVE_SPARK,
            MOVE_FLASH,
        },
    },
    [SPECIES_GUMSHOOS] =
    {
        .name = _("MARILL"),
        .fieldUseFunc = ItemUseOutOfBattle_SurfStateTransform,
        .iconPic = gItemIcon_TransformSurf,
        .iconPalette = gItemIconPalette_TransformSurf,
        .battleSpecies = SPECIES_DITTO_MARILL,
        .ability = ABILITY_HUGE_POWER,
        .moves = {
            MOVE_SURF,
            MOVE_AQUA_JET,
            MOVE_COVET,
            MOVE_RAIN_DANCE,
        },
    },
    
};
