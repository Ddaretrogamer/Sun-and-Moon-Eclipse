#include "global.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "constants/event_objects.h"
#include "event_data.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "overworld.h"
#include "script.h"
#include "sprite.h"
#include "transform.h"
#include "event_object_movement.h"
#include "follower_npc.h"
#include "overworld.h"
#include "gpu_regs.h"
#include "trig.h"
#include "task.h"
#include "sound.h"
#include "constants/songs.h"


enum
{
    RIDE_SPRITE_DIR_DOWN, // Now 0
    RIDE_SPRITE_DIR_UP,   // Now 1
    RIDE_SPRITE_DIR_WEST, // Now 2
    RIDE_SPRITE_DIR_EAST, // Now 3
    RIDE_SPRITE_DIR_COUNT,
};

enum
{
    RIDER_SHOW_INFRONT,
    RIDER_SHOW_BEHIND,
};

struct RideSpriteInfo
{
    s8 playerX;
    s8 playerY;
    u8 playerRendersInFront;
};

struct RideMonInfo
{
    u16 riderGfxId[GENDER_COUNT];
    struct RideSpriteInfo spriteInfo[RIDE_SPRITE_DIR_COUNT];
};

#include "data/rogue_ridemon_infos_converted.h"

/*
 * ============================================================================
 *  CONFIG
 * ============================================================================
 */

#define MOSAIC_MAX 8
#define MOSAIC_FRAMES_PER_STEP 1

#define STEP_FRAME_DURATION 8

#define RIDER_CENTER_X_OFFSET   0   // (32 - 16) / 2
#define RIDER_CENTER_Y_OFFSET  -10 // sits slightly above center

// Transform animation configuration
#define TRANSFORM_TOTAL_FRAMES 20  // 16 for animation + 4 safety frames
#define TRANSFORM_MIDPOINT 8

// Task data indices for transform animation
#define tFrame          data[0]
#define tSpecies        data[1]
#define tUnlockControls data[2]
/*
 * ============================================================================
 *  STATE
 * ============================================================================
 */
#define gPlayerTransformSpecies (gSaveBlock2Ptr->pokemonAvatarSpecies)
EWRAM_DATA struct PlayerAvatarBobState gPlayerAvatarBobState = {0};
EWRAM_DATA s16 sPlayerMountSpriteId;

/*
 * ============================================================================
 *  INTERNAL HELPERS
 * ============================================================================
 */

static void ResetPlayerAvatar(void);
static void SetPlayerTransformFlags(void);
static void ClearPlayerTransformFlags(void);
static void ExecutePlayerTransformation(u16 species);
static void EndPlayerTransformAnimation(struct Sprite *playerSprite, u8 taskId);

static void UpdatePlayerMountSpritePosition(struct Sprite *sprite);

static u16 GetTransformGraphicsIdFromSpecies(void)
{
    u16 gfxId = gPlayerTransformSpecies + OBJ_EVENT_MON;

    // Check both the global shiny ride flag and the Ride Pager specific flag
    if (FlagGet(FLAG_SHINY_RIDE) || FlagGet(FLAG_RIDE_PAGER_SHINY))
        gfxId += OBJ_EVENT_MON_SHINY;

    return gfxId;
}

// Check if a species can be ridden (has valid ride data)
bool8 CanRideOnSpecies(u16 species)
{
    u8 gender;
    
    if (species == SPECIES_NONE || species >= NUM_SPECIES)
        return FALSE;
    
    gender = gSaveBlock2Ptr->playerGender;
    return sRideMonInfo[species].riderGfxId[gender] != 0;
}

/*
 * ============================================================================
 *  PUBLIC API (used by graphics hook)
 * ============================================================================
 */

struct TransformTaskData
{
    u8 mosaic;      // current mosaic size
    u8 frameCounter; // sub-frame counter
    u8 state;       // 0=grow mosaic, 1=transform, 2=shrink mosaic
    u16 species;    // species to transform into
};

// 1. Update the helper to set the hardware register AND the sprite bit
static void SetPlayerMosaic(u8 size)
{
    // 1. Set the Hardware Register (Size of blocks)
    // Bits 8-11: OBJ Horizontal, Bits 12-15: OBJ Vertical
    u16 objMosaic = (size & 0xF) | ((size & 0xF) << 4);
    SetGpuReg(REG_OFFSET_MOSAIC, (objMosaic << 8));

    // 2. Enable the Mosaic bit on the current player sprite
    if (gSprites[gPlayerAvatar.spriteId].inUse)
        gSprites[gPlayerAvatar.spriteId].oam.mosaic = TRUE;
}

static void ResetPlayerMosaic(void)
{
    struct Sprite *sprite = &gSprites[gPlayerAvatar.spriteId];
    if (sprite->inUse)
        sprite->oam.mosaic = FALSE;
    
    // Clear OBJ bits in the hardware register
    SetGpuReg(REG_OFFSET_MOSAIC, GetGpuReg(REG_OFFSET_MOSAIC) & 0x00FF);
}

void Task_UpdatePlayerTransformAnimation(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct Sprite *playerSprite = NULL;
    u8 frames = task->tFrame;
    u8 stretch;
    
    // Get player sprite
    if (gPlayerAvatar.spriteId < MAX_SPRITES &&
        gSprites[gPlayerAvatar.spriteId].inUse)
    {
        playerSprite = &gSprites[gPlayerAvatar.spriteId];
    }
    
    // Enforce locks EVERY frame
    gPlayerAvatar.preventStep = TRUE;
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_CONTROLLABLE;
    
    // Check if animation is complete
    if (frames >= TRANSFORM_TOTAL_FRAMES)
    {
        EndPlayerTransformAnimation(playerSprite, taskId);
        return;
    }
    
    // Apply mosaic effect (only during frames 0-15)
    if (frames < 16)
    {
        if (frames < TRANSFORM_MIDPOINT)
            stretch = frames >> 1;
        else
            stretch = (16 - frames) >> 1;
        
        if (playerSprite)
            playerSprite->oam.mosaic = TRUE;
        
        u16 mosaic = GetGpuReg(REG_OFFSET_MOSAIC) & 0x00FF;
        mosaic |= (stretch << 12) | (stretch << 8);
        SetGpuReg(REG_OFFSET_MOSAIC, mosaic);
    }
    else
    {
        // Frames 16-19: Animation done, clear mosaic but stay locked
        if (playerSprite)
            playerSprite->oam.mosaic = FALSE;
        SetGpuReg(REG_OFFSET_MOSAIC, GetGpuReg(REG_OFFSET_MOSAIC) & 0x00FF);
    }
    
    // Midpoint: Perform the actual transformation
    if (frames == TRANSFORM_MIDPOINT)
    {
        ExecutePlayerTransformation(task->tSpecies);
    }
    
    task->tFrame++;
}
static void ExecutePlayerTransformation(u16 species)
{
    // Play appropriate sound for transformation
    if (species == SPECIES_NONE)
        PlaySE(SE_M_TELEPORT);  // Detransforming - use teleport sound
    else if (!IsCryPlaying())
        PlayCry_Normal(species, 0);  // Transforming - use mon's cry
    
    gPlayerTransformSpecies = species;
    DestroyPlayerMountSprite();
    
    if (species == SPECIES_NONE)
    {
        // Detransforming back to player
        ClearPlayerTransformFlags();
        ResetPlayerAvatar();
        
        // Restore follower if appropriate
        if (!FlagGet(FLAG_DISABLE_FOLLOWERS) && !FlagGet(FLAG_DETRANSFORM_NO_FOLLOWER))
        {
            UpdateFollowingPokemon();
        }
    }
    else
    {
        // Transforming into a Pokémon
        SetPlayerTransformFlags();
        ResetPlayerAvatar();
        CreatePlayerMountSprite(species);
    }
    
    // CRITICAL: Re-lock after ResetPlayerAvatar
    gPlayerAvatar.preventStep = TRUE;
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_CONTROLLABLE;
    LockPlayerFieldControls();
    FreezeObjectEvents();
}

static void EndPlayerTransformAnimation(struct Sprite *playerSprite, u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    
    // Clear mosaic
    if (playerSprite)
        playerSprite->oam.mosaic = FALSE;
    SetGpuReg(REG_OFFSET_MOSAIC, GetGpuReg(REG_OFFSET_MOSAIC) & 0x00FF);
    
    // Unlock controls if requested
    if (task->tUnlockControls)
    {
        gPlayerAvatar.preventStep = FALSE;
        gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_CONTROLLABLE;
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
    }
    
    DestroyTask(taskId);
}


/*
static void Task_TransformMosaic(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 frames = task->tCounter;
    u8 stretch;
    struct Sprite *playerSprite = NULL;
    
    if (gPlayerAvatar.spriteId < MAX_SPRITES &&
        gSprites[gPlayerAvatar.spriteId].inUse)
    {
        playerSprite = &gSprites[gPlayerAvatar.spriteId];
    }
    
    // end condition
    if (frames >= 16)
    {
        if (playerSprite)
            playerSprite->oam.mosaic = FALSE;
        
        // Clear OBJ mosaic bits only 
        SetGpuReg(REG_OFFSET_MOSAIC, GetGpuReg(REG_OFFSET_MOSAIC) & 0x00FF);
        
        // Unlock controls after transformation completes
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        
        DestroyTask(taskId);
        return;
    }
    
    // Compute mosaic stretch
    if (frames < 8)
        stretch = frames >> 1;
    else
        stretch = (16 - frames) >> 1;
    
    if (playerSprite)
        playerSprite->oam.mosaic = TRUE;
    
    // Apply OBJ mosaic safely
    {
        u16 mosaic = GetGpuReg(REG_OFFSET_MOSAIC) & 0x00FF;
        mosaic |= (stretch << 12) | (stretch << 8);
        SetGpuReg(REG_OFFSET_MOSAIC, mosaic);
    }
    
    // Midpoint: ACTUAL transform 
    if (frames == 8)
    {
        PlaySE(SE_M_TELEPORT);
        //Prevent movement for ONE frame only
        gPlayerAvatar.preventStep = TRUE;
        gPlayerTransformSpecies = task->tSpecies;
        DestroyPlayerMountSprite();
        
        if (task->tSpecies == SPECIES_NONE)
        {
            // Detransforming back to player
            ClearPlayerTransformFlags();
            ResetPlayerAvatar();
            
            // Restore follower if appropriate
            if (!FlagGet(FLAG_DISABLE_FOLLOWERS) && !FlagGet(FLAG_DETRANSFORM_NO_FOLLOWER))
            {
                UpdateFollowingPokemon();
            }
        }
        else
        {
            // Transforming into a Pokémon
            SetPlayerTransformFlags();
            ResetPlayerAvatar();
            CreatePlayerMountSprite(task->tSpecies);
        }
    }
    
    task->tCounter++;
}*/


static u8 GetRideSpriteDir(void)
{
    u8 direction = GetPlayerFacingDirection();
    
    switch (direction)
    {
        case DIR_NORTH:
            return RIDE_SPRITE_DIR_UP;

        case DIR_SOUTH:
            return RIDE_SPRITE_DIR_DOWN;

        case DIR_WEST:
        case DIR_NORTHWEST: // Stair diagonal
        case DIR_SOUTHWEST: // Stair diagonal
            return RIDE_SPRITE_DIR_WEST;

        case DIR_EAST:
        case DIR_NORTHEAST: // Stair diagonal
        case DIR_SOUTHEAST: // Stair diagonal
            return RIDE_SPRITE_DIR_EAST;
    }
    return RIDE_SPRITE_DIR_DOWN;
}

bool32 IsPlayerTransformed(void)
{
    return FlagGet(FLAG_PLAYER_IS_POKEMON) && gPlayerTransformSpecies != SPECIES_NONE;
}

u16 GetPlayerTransformGraphicsId(void)
{
    if (gPlayerTransformSpecies == SPECIES_NONE)
        return GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL);

    u16 gfxId = gPlayerTransformSpecies + OBJ_EVENT_MON;
    // Check both the global shiny ride flag and the Ride Pager specific flag
    if (FlagGet(FLAG_SHINY_RIDE) || FlagGet(FLAG_RIDE_PAGER_SHINY))
        gfxId += OBJ_EVENT_MON_SHINY;

    return gfxId;
}

void SanitizePlayerTransformOnLoad(void)
{
    if (!FlagGet(FLAG_PLAYER_IS_POKEMON))
    {
        gPlayerTransformSpecies = SPECIES_NONE;
        sPlayerMountSpriteId = -1; // Only reset if not transformed
    }
}

/*
 * ============================================================================
 *  AVATAR RESET
 * ============================================================================
 */

static void ResetPlayerAvatar(void)
{
    u16 x, y;
    u8 direction;
    struct ObjectEvent *playerObj;

    GetCameraFocusCoords(&x, &y);
    direction = GetPlayerFacingDirection();

    playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    RemoveObjectEvent(playerObj);

    ClearPlayerAvatarInfo();
    InitPlayerAvatar(x, y, direction, gSaveBlock2Ptr->playerGender);

    gSprites[gPlayerAvatar.spriteId].x2 = 0;
    gSprites[gPlayerAvatar.spriteId].y2 = 0;
}

/*
 * ============================================================================
 *  FLAG MANAGEMENT
 * ============================================================================
 */

static void SetPlayerTransformFlags(void)
{
    FlagSet(FLAG_PLAYER_IS_POKEMON);
    FlagSet(FLAG_DISABLE_FOLLOWERS);
    FlagSet(FLAG_DEFER_TRANSFORM);
}

static void ClearPlayerTransformFlags(void)
{
    FlagClear(FLAG_PLAYER_IS_POKEMON);
    
    if (!FlagGet(FLAG_DETRANSFORM_NO_FOLLOWER) && FlagGet(FLAG_FOLLOWERS_MENU_TOGGLE))
    {
        FlagClear(FLAG_DISABLE_FOLLOWERS);
    }
    
    FlagClear(FLAG_DEFER_TRANSFORM);
    gPlayerTransformSpecies = SPECIES_NONE;
    
    DestroyPlayerMountSprite();
}
/*
 * ============================================================================
 *  TRANSFORM ENTRY POINTS
 * ============================================================================
 */

/*
 * Script command:
 *  - VAR_TRANSFORM_MON holds species
 *  - SPECIES_NONE = detransform
 */
void TransformPlayerToSpeciesScript(u16 species, bool8 unlockControls)
{
    struct ObjectEvent *follower = GetFollowerObject();
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    u8 taskId;
    
    // Lock controls HARD
    LockPlayerFieldControls();
    FreezeObjectEvents();
    
    // Force player to stop
    if (playerObj)
    {
        ObjectEventClearHeldMovementIfFinished(playerObj);
    }
    
    gPlayerAvatar.preventStep = TRUE;
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_CONTROLLABLE;
    
    // Handle follower
    if (follower)
    {
        if (VarGet(VAR_0x8004)) // surf-initiated detransform
            HideFollowerForFieldEffect();  // CHANGED THIS LINE
        else
            RemoveObjectEvent(follower);
    }
    
    // Create the animation task
    taskId = CreateTask(Task_UpdatePlayerTransformAnimation, 0);
    gTasks[taskId].tFrame = 0;
    gTasks[taskId].tSpecies = (species >= NUM_SPECIES) ? SPECIES_NONE : species;
    gTasks[taskId].tUnlockControls = unlockControls;
}

void ChooseMonForTransform(void)
{
    u16 species = VarGet(VAR_TRANSFORM_MON);
    struct ObjectEvent *follower = GetFollowerObject();
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    u8 taskId;
    
    // Lock controls HARD
    LockPlayerFieldControls();
    FreezeObjectEvents();
    
    // Force player to stop
    if (playerObj)
    {
        ObjectEventClearHeldMovementIfFinished(playerObj);
    }
    
    gPlayerAvatar.preventStep = TRUE;
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_CONTROLLABLE;
    
    // Handle follower
    if (follower)
    {
        if (VarGet(VAR_0x8004)) // surf-initiated detransform
            HideFollowerForFieldEffect();
        else
            RemoveObjectEvent(follower);
    }
    
    // Create the animation task
    taskId = CreateTask(Task_UpdatePlayerTransformAnimation, 0);
    gTasks[taskId].tFrame = 0;
    gTasks[taskId].tSpecies = (species >= NUM_SPECIES) ? SPECIES_NONE : species;
    gTasks[taskId].tUnlockControls = TRUE;
}

/*
 * Script command version with explicit defer flag
 */
void TransformPlayer(struct ScriptContext *ctx)
{
    bool32 defer = ScriptReadByte(ctx);
    u16 species = VarGet(VAR_TRANSFORM_MON);

    if (species == SPECIES_NONE || species >= NUM_SPECIES)
        return;

    gPlayerTransformSpecies = species;

    if (defer)
    {
        FlagSet(FLAG_PLAYER_IS_POKEMON);
        FlagSet(FLAG_DEFER_TRANSFORM);
        FlagSet(FLAG_DISABLE_FOLLOWERS);
    }
    else
    {
        SetPlayerTransformFlags();
        ResetPlayerAvatar();
    }
}
/*
void TransformPlayerToSpeciesSimple(u16 species)
{
    u8 taskId;

    struct ObjectEvent *follower = GetFollowerObject();
    if (follower)
        RemoveObjectEvent(follower);

    taskId = CreateTask(Task_TransformMosaic, 0);
    gTasks[taskId].tCounter = 0;
    gTasks[taskId].tSpecies = species;
}*/
void DetransformPlayer(struct ScriptContext *ctx)
{
    bool32 defer = ScriptReadByte(ctx);

    if (defer)
    {
        ClearPlayerTransformFlags();
    }
    else
    {
        ClearPlayerTransformFlags();
        ResetPlayerAvatar();

        // Respect the menu toggle
        if (!FlagGet(FLAG_DISABLE_FOLLOWERS)
            && !FlagGet(FLAG_DETRANSFORM_NO_FOLLOWER))
        {
            UpdateFollowingPokemon();
        }

        /* Ensure any mount sprite is removed */
        DestroyPlayerMountSprite();
    }
}

void CreatePlayerMountSprite(u16 species)
{
    s16 spriteId;
    struct Sprite *playerSpr;
    struct Sprite *mountSpr;
    const struct RideMonInfo *info;
    u8 gender = gSaveBlock2Ptr->playerGender;

    DestroyPlayerMountSprite();

    info = &sRideMonInfo[species];
    if (info->riderGfxId[gender] == 0)
        return;

    spriteId = CreateObjectGraphicsSpriteWithTag(
        info->riderGfxId[gender],
        UpdatePlayerMountSpritePosition, // The callback
        0, 0,
        0,
        TAG_NONE
    );

    if (spriteId == MAX_SPRITES)
        return;

    sPlayerMountSpriteId = spriteId;

    playerSpr = &gSprites[gPlayerAvatar.spriteId];
    mountSpr  = &gSprites[spriteId];

    mountSpr->coordOffsetEnabled = TRUE;
    mountSpr->oam.priority = playerSpr->oam.priority;
    mountSpr->images = GetObjectEventGraphicsInfo(info->riderGfxId[gender])->images;
    
    // Set initial visibility
    mountSpr->invisible = playerSpr->invisible;
    
    UpdatePlayerMountSpritePosition(mountSpr);
}

static void UpdateRiderGraphics(void)
{
    struct Sprite *mountSpr;
    u8 dir;

    if (sPlayerMountSpriteId < 0)
        return;

    mountSpr = &gSprites[sPlayerMountSpriteId];
    dir = GetRideSpriteDir(); // Now returns 0, 1, 2, or 3
    
    // We no longer need actualAnim logic. 
    // We just pass the direction (0-3) directly to the animation system.
    if (mountSpr->animNum != dir)
    {
        StartSpriteAnim(mountSpr, dir);
    }

    // REMOVED: All hFlip and matrixNum logic.
    // The 4th frame in your PNG handles the facing direction naturally.

    mountSpr->animPaused = TRUE;
    mountSpr->animCmdIndex = 0;
    mountSpr->animDelayCounter = 0;
}

void DestroyPlayerMountSprite(void)
{
    if (sPlayerMountSpriteId >= 0)
    {
        if (gSprites[sPlayerMountSpriteId].inUse)
            DestroySprite(&gSprites[sPlayerMountSpriteId]);
        sPlayerMountSpriteId = -1;
    }
}

static void UpdatePlayerMountSpritePosition(struct Sprite *mountSpr)
{
    struct Sprite *playerSpr;
    const struct RideMonInfo *info;
    const struct RideSpriteInfo *dirInfo;
    u8 dir;

    if (!IsPlayerTransformed() || sPlayerMountSpriteId < 0)
    {
        DestroyPlayerMountSprite();
        return;
    }

    playerSpr = &gSprites[gPlayerAvatar.spriteId];
    if (!playerSpr->inUse) return;

    // 1. Sync basic visibility and Priority
    mountSpr->invisible = playerSpr->invisible;
    
    // CRITICAL: Sync the OAM priority (0-3) which changes with elevation
    mountSpr->oam.priority = playerSpr->oam.priority;

    dir = GetRideSpriteDir();
    info = &sRideMonInfo[gPlayerTransformSpecies];
    dirInfo = &info->spriteInfo[dir];

    mountSpr->x = playerSpr->x;
    mountSpr->y = playerSpr->y;

    mountSpr->x2 = playerSpr->x2 + dirInfo->playerX;
    mountSpr->y2 = playerSpr->y2 + dirInfo->playerY;

    // 2. Handle Subpriority (Z-index within the same priority level)
    // We use a slightly larger offset to ensure it's definitely above/below
    if (dirInfo->playerRendersInFront == RIDER_SHOW_INFRONT)
    {
        mountSpr->subpriority = (playerSpr->subpriority > 0) ? playerSpr->subpriority - 1 : 0;
    }
    else
    {
        mountSpr->subpriority = playerSpr->subpriority + 1;
    }
}




/*
 * ============================================================================
 *  BOB ANIMATION
 * ============================================================================
 */

void PlayerAvatarHandleBob(void)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *playerSprite = &gSprites[playerObj->spriteId];
    
    if (!IsPlayerTransformed())
    {
        playerSprite->y2 = 0;
        gPlayerAvatarBobState.frameCounter = 0;
        return;
    }

    // Check if player is actually in a walking movement action
    switch (playerObj->movementActionId)
    {
        case MOVEMENT_ACTION_WALK_NORMAL_DOWN:
        case MOVEMENT_ACTION_WALK_NORMAL_UP:
        case MOVEMENT_ACTION_WALK_NORMAL_LEFT:
        case MOVEMENT_ACTION_WALK_NORMAL_RIGHT:
        case MOVEMENT_ACTION_WALK_FAST_DOWN:
        case MOVEMENT_ACTION_WALK_FAST_UP:
        case MOVEMENT_ACTION_WALK_FAST_LEFT:
        case MOVEMENT_ACTION_WALK_FAST_RIGHT:
            // Continue to bobbing logic below
            break;
        default:
            // Idle state: reset to a slight natural sink (optional)
            playerSprite->y2 = 0;
            gPlayerAvatarBobState.frameCounter = 0;
            UpdateRiderGraphics();
            return;
    }

    // Your logic translated to the global state variable
    if (gPlayerAvatarBobState.frameCounter == 0)
        playerSprite->y2 = 1;
    else if (gPlayerAvatarBobState.frameCounter == STEP_FRAME_DURATION)
        playerSprite->y2 = 0; // Sink
    else if (gPlayerAvatarBobState.frameCounter >= (STEP_FRAME_DURATION * 2))
    {
        playerSprite->y2 = 1; // Rise back
        gPlayerAvatarBobState.frameCounter = 0;
        UpdateRiderGraphics();
        return;
    }

    gPlayerAvatarBobState.frameCounter++;
    UpdateRiderGraphics();
}

bool32 PlayerHasMountSprite(void)
{
    return sPlayerMountSpriteId >= 0
        && sPlayerMountSpriteId < MAX_SPRITES
        && gSprites[sPlayerMountSpriteId].inUse;
}

void UpdatePlayerMountSprite(void)
{
    struct Sprite *player = &gSprites[gPlayerAvatar.spriteId];
    struct Sprite *mount  = &gSprites[sPlayerMountSpriteId];

    // Position sync
    mount->x = player->x;
    mount->y = player->y;

    // Direction / anim sync
    if (mount->animNum != player->animNum)
        StartSpriteAnim(mount, player->animNum);

    // Advance frames (THIS fixes your frozen animation)
    AnimateSprite(mount);
}

void OnResetSpriteData(void)
{
    sPlayerMountSpriteId = -1;
}

// Clean up the task data macros
#undef tFrame
#undef tSpecies
#undef tUnlockControls