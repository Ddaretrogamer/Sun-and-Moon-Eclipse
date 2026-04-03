#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "main.h"
#include "party_menu.h"
#include "sound.h"
#include "sprite.h"
#include "surfable.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
extern const struct OamData gObjectEventBaseOam_32x32;
extern const struct OamData gObjectEventBaseOam_64x64;
extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

extern void SynchroniseSurfAnim(struct ObjectEvent *playerObj, struct Sprite *sprite);
extern void SynchroniseSurfPosition(struct ObjectEvent *playerObj, struct Sprite *sprite);

static void CreateOverlaySprite(void);
static void UpdateSurfMonOverlay(struct Sprite *sprite);
extern void UpdateBobbingEffect(struct ObjectEvent *playerObj, struct Sprite *playerSprite, struct Sprite *sprite);


struct RideablePokemon
{
    u16 species;
    u8 trainerPose;
};

#include "data/object_events/surfable/surfable_pokemon.h"
#include "data/object_events/surfable/surfable_pokemon_graphics.h"
#include "data/object_events/surfable/surfable_pokemon_pic_tables.h"
#include "data/object_events/surfable/surfable_pokemon_templates.h"

static EWRAM_DATA u16 sCurrentSurfMon = {0};



static u16 GetSurfMonSpecies(void)
{
    u8 surfMonChoice = VarGet(VAR_SURF_MON_SLOT);

    switch (surfMonChoice)
    {
    case SURF_MON_LAPRAS: // If surfMonChoice is 0
        return SPECIES_LAPRAS;
    case SURF_MON_SHARPEDO: // If surfMonChoice is 1
        return SPECIES_SHARPEDO;
    default:
        // This is the correct way to default to Lapras:
        return SPECIES_LAPRAS; // Return the actual species ID of Lapras
    }
}

static u16 GetSurfablePokemonSprite(void)
{
    u8 i;
    u16 mon = GetSurfMonSpecies();

    for (i = 0; i < ARRAY_COUNT(gSurfablePokemon); i++)
    {
        if (mon == gSurfablePokemon[i].species)
            return i;
    }
    return 0xFFFF;
}

static void LoadSurfOverworldPalette(void)
{
    // sCurrentSurfMon is already correctly determined elsewhere (0 for Lapras, 1 for Sharpedo)
    // and tells us which sprite/palette entry to use.
    u8 paletteNum;
    u16 paletteTag;

    // Check if the FIRST Pokémon in the party (gPlayerParty[0]) is shiny.
    // This assumes gPlayerParty[0] always exists and holds a valid Pokémon data structure.
    if (FlagGet(FLAG_SHINY_SURF))
    {
        // If the first Pokémon is shiny, load the shiny palette for the current surf mon
        paletteTag = sSurfablePokemonShinyPalettes[sCurrentSurfMon].tag;
        LoadSpritePalette(&sSurfablePokemonShinyPalettes[sCurrentSurfMon]);
    }
    else
    {
        // Otherwise, load the normal palette for the current surf mon
        paletteTag = sSurfablePokemonPalettes[sCurrentSurfMon].tag;
        LoadSpritePalette(&sSurfablePokemonPalettes[sCurrentSurfMon]);
    }
    
    // Apply DNS (Day/Night System) tinting immediately
    paletteNum = IndexOfSpritePaletteTag(paletteTag);
    if (paletteNum != 0xFF)
        UpdateSpritePaletteWithWeather(paletteNum, FALSE);
}

void RefreshSurfablePaletteFromFlag(void)
{
    // Ensure the current surf index is up to date
    sCurrentSurfMon = GetSurfablePokemonSprite();

    // This loads either the shiny or normal palette based on FLAG_SHINY_SURF
    LoadSurfOverworldPalette();
}

u32 CreateSurfablePokemonSprite(void)
{
    u8 spriteId;
    struct Sprite *sprite;
    RefreshSurfablePaletteFromFlag();
    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);

    sCurrentSurfMon = GetSurfablePokemonSprite();
    if (sCurrentSurfMon != 0xFFFF)
    {
        LoadSurfOverworldPalette();
        spriteId = CreateSpriteAtEnd(&gSurfablePokemonOverworldSprites[sCurrentSurfMon], gFieldEffectArguments[0], gFieldEffectArguments[1], 0x96);
        if (gSurfablePokemonOverlaySprites[sCurrentSurfMon].tileTag == 0xFFFF)
        {
            CreateOverlaySprite();
        }
    }
    else
    { // Create surf blob
        LoadObjectEventPalette(FLDEFFOBJ_SURF_BLOB);
        spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SURF_BLOB], gFieldEffectArguments[0], gFieldEffectArguments[1], 0x96);
    }

    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[2] = gFieldEffectArguments[2];
        sprite->data[3] = -1;
        sprite->data[6] = -1;
        sprite->data[7] = -1;
    }
    FieldEffectActiveListRemove(FLDEFF_SURF_BLOB);
    if(IsCryPlaying())
        StopCry();
    if(VarGet(VAR_SURF_MON_SLOT) == SURF_MON_SHARPEDO)
    {
        PlayCry_Normal(SPECIES_SHARPEDO, 0);
    }
    else
    {
        PlayCry_Normal(SPECIES_LAPRAS, 0);
    }
    return spriteId;
}

static void CreateOverlaySprite(void)
{
    u8 overlaySprite;
    u8 subpriority;
    struct Sprite *sprite;

    subpriority = gSprites[gPlayerAvatar.spriteId].subpriority - 1;
    overlaySprite = CreateSpriteAtEnd(&gSurfablePokemonOverlaySprites[sCurrentSurfMon], gFieldEffectArguments[0], gFieldEffectArguments[1], subpriority);

    if (overlaySprite != MAX_SPRITES)
    {
        sprite = &gSprites[overlaySprite];
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[2] = gFieldEffectArguments[2];
        sprite->data[3] = -1;
        sprite->data[6] = -1;
        sprite->data[7] = -1;
        sprite->oam.priority = 2;
    }
    SetSurfBlob_BobState(overlaySprite, BOB_PLAYER_AND_MON);
}

static void UpdateSurfMonOverlay(struct Sprite *sprite)
{
    struct ObjectEvent *playerObj;
    struct Sprite *linkedSprite;
    u8 subpriority;
	
    playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    linkedSprite = &gSprites[playerObj->spriteId];

    SynchroniseSurfAnim(playerObj, sprite);
    SynchroniseSurfPosition(playerObj, sprite);

    if (VarGet(VAR_FREEZESURFBLOB) == 0)
	{
        UpdateBobbingEffect(playerObj, linkedSprite, sprite);
    }

    // Reset the subpriority for the overlay sprite so it shows on top of the player
    // We need this here so the subprio is correct after a screen transition (e.g. after exiting a battle)
    subpriority = gSprites[gPlayerAvatar.spriteId].subpriority - 1;
    sprite->subpriority = subpriority;

if (linkedSprite->animNum < MOVEMENT_ACTION_DELAY_16)
    if (linkedSprite->animNum < MOVEMENT_ACTION_DELAY_16)
    {
        sprite->x = linkedSprite->x;
        sprite->y = linkedSprite->y + 8;
        sprite->y2 = linkedSprite->y2;
    }
    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING))
        DestroySprite(sprite);
}

// Store the task data indices for clarity
#define tFrames      data[0]
#define tNewSpecies  data[1]

void BeginSurfTransformEffect(u8 newSlot)
{
    // Find the sprite ID for the surfing blob/mon
    // In the surf system, this is usually stored or can be found via field effect
    u8 taskId = CreateTask(UpdateSurfTransformAnimation, 0xFF);
    gTasks[taskId].tFrames = 0;
    gTasks[taskId].tNewSpecies = newSlot;
}

static void UpdateSurfMonBase(struct Sprite *sprite)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *playerSprite = &gSprites[gPlayerAvatar.spriteId];

    // Follow the player's map movement
    SynchroniseSurfAnim(playerObj, sprite);
    SynchroniseSurfPosition(playerObj, sprite);

    // PRIORITY: Keep it behind the player
    sprite->subpriority = playerSprite->subpriority + 1;
    sprite->oam.priority = playerSprite->oam.priority;

    // POSITION SYNC: Match player pixel coordinates exactly.
    // Note: We do NOT add +8 here because this is the base, not the saddle.
    if (playerSprite->animNum < MOVEMENT_ACTION_DELAY_16)
    {
        sprite->x = playerSprite->x;
        sprite->y = playerSprite->y + 8;
        sprite->y2 = playerSprite->y2;
    }

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING))
        DestroySprite(sprite);
}

void UpdateSurfTransformAnimation(u8 taskId)
{
    u8 i;
    u8 stretch;
    u16 frames = gTasks[taskId].tFrames;
    struct Sprite *playerSprite = &gSprites[gPlayerAvatar.spriteId];
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];

    // Mosaic Logic
    if (frames < 8)
        stretch = frames >> 1;
    else if (frames < 16)
        stretch = (16 - frames) >> 1;
    else 
    {
        playerSprite->oam.mosaic = FALSE;
        for (i = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].inUse && (gSprites[i].callback == UpdateSurfMonOverlay || gSprites[i].callback == UpdateSurfMonBase))
                gSprites[i].oam.mosaic = FALSE;
        }
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        DestroyTask(taskId);
        return;
    }

    SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 12) | (stretch << 8));
    playerSprite->oam.mosaic = TRUE;

    // THE SWAP (Frame 8)
    if (frames == 8)
    {
        // A. DESTROY: Targets both potential callbacks
        for (i = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].inUse)
            {
                if (gSprites[i].callback == UpdateSurfMonOverlay || 
                    gSprites[i].callback == UpdateSurfMonBase ||
                    (gSprites[i].template >= &gSurfablePokemonOverworldSprites[0] && 
                     gSprites[i].template <= &gSurfablePokemonOverworldSprites[ARRAY_COUNT(gSurfablePokemonOverworldSprites) - 1]))
                {
                    FreeSpriteTilesByTag(gSprites[i].template->tileTag);
                    FreeSpritePaletteByTag(gSprites[i].template->paletteTag);
                    DestroySprite(&gSprites[i]);
                }
            }
        }

        // B. PREP ARGS: Map coordinates
        gFieldEffectArguments[0] = playerObj->currentCoords.x;
        gFieldEffectArguments[1] = playerObj->currentCoords.y;
        gFieldEffectArguments[2] = gPlayerAvatar.spriteId; 

        // C. CREATE: New sprite
        sCurrentSurfMon = GetSurfablePokemonSprite();
        u8 newSpriteId = CreateSurfablePokemonSprite();

        if (newSpriteId != MAX_SPRITES)
        {
            struct Sprite *baseMon = &gSprites[newSpriteId];
            
            // D. SYNC BASE: Use the correct callback and snap to player
            baseMon->callback = UpdateSurfMonBase;
            baseMon->x = playerSprite->x;
            baseMon->y = playerSprite->y + 8;
            baseMon->coordOffsetEnabled = TRUE;
            baseMon->oam.mosaic = TRUE;
            baseMon->data[2] = gPlayerAvatar.spriteId; 

            // E. SYNC OVERLAYS: Only apply Mosaic, don't change their callback/pos
            for (i = 0; i < MAX_SPRITES; i++)
            {
                if (gSprites[i].inUse && gSprites[i].callback == UpdateSurfMonOverlay && &gSprites[i] != baseMon)
                {
                    gSprites[i].oam.mosaic = TRUE;
                }
            }
        }
    }

    gTasks[taskId].tFrames++;
}

void SwapSurfMonRealTime(void)
{
    if (FuncIsActiveTask(UpdateSurfTransformAnimation))
        return;

    u8 oldSlot = VarGet(VAR_SURF_MON_SLOT);
    u8 newSlot = (oldSlot == SURF_MON_LAPRAS) ? SURF_MON_SHARPEDO : SURF_MON_LAPRAS;
    
    VarSet(VAR_SURF_MON_SLOT, newSlot);
    RefreshSurfablePaletteFromFlag();
    PlaySE(SE_M_TELEPORT);

    BeginSurfTransformEffect(newSlot);
}