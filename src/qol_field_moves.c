#include "global.h"
#include "palette.h"
#include "field_control_avatar.h"
#include "event_scripts.h"
#include "field_screen_effect.h"
#include "field_player_avatar.h"
#include "fldeff_misc.h"
#include "item.h"
#include "field_control_avatar.h"
#include "map_name_popup.h"
#include "constants/items.h"
#include "fldeff.h"
#include "overworld.h"
#include "region_map.h"
#include "item_use.h"
#include "item.h"
#include "constants/items.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "party_menu.h"
#include "constants/party_menu.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "event_data.h"
#include "qol_field_moves.h"
#include "constants/songs.h"
#include "sound.h"
#include "script.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "field_weather.h"
#include "constants/field_effects.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "item_menu.h"
#include "constants/map_types.h"
#include "constants/party_menu.h"

#include "transform.h"
#include "surfable.h"

static u8 CreateUseToolTask(void);
static void Task_UseTool_Init(u8);
static void LockPlayerAndLoadMon(void);

static void FieldCallback_UseFlyTool(void);
static void Task_UseFlyTool(void);

static void SetUpFieldMove_UseFlash(u32);
static void UseFlash(u32 fieldMoveStatus);
static void FieldCallback_UseFlashTool(void);
static void FieldCallback_UseFlashMove(void);

static void Task_UseWaterfallTool(u8);
static bool8 IsPlayerFacingWaterfall(void);

static void Task_UseDiveTool(u8);

static bool32 PartyCanLearnMoveLevelUp(u16, u16);
static bool32 SetMonResultVariables(u32 partyIndex, u32 species);

#define tState      data[0]
#define tFallOffset data[1]
#define tTotalFall  data[2]

static u8 CreateUseToolTask(void)
{
    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    return CreateTask(Task_UseTool_Init, 8);
}

static void Task_UseTool_Init(u8 taskId)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;

        gFieldEffectArguments[1] = GetPlayerFacingDirection();
        if (gFieldEffectArguments[1] == DIR_SOUTH)
            gFieldEffectArguments[2] = 0;
        if (gFieldEffectArguments[1] == DIR_NORTH)
            gFieldEffectArguments[2] = 1;
        if (gFieldEffectArguments[1] == DIR_WEST)
            gFieldEffectArguments[2] = 2;
        if (gFieldEffectArguments[1] == DIR_EAST)
            gFieldEffectArguments[2] = 3;
        ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByCurrentState());
        StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], gFieldEffectArguments[2]);

    gTasks[taskId].func = Task_DoFieldMove_RunFunc;
}

static void LockPlayerAndLoadMon(void)
{
    LockPlayerFieldControls();
    gFieldEffectArguments[0] = gSpecialVar_Result;
}

// Cut
u32 CanUseCut(s16 x, s16 y)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM01);
    bool32 bagHasItem = CheckBagHasItem(ITEM_CUT_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE01_GET);

    if (
            CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_CUTTABLE_TREE)
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && ((monHasMove && playerHasBadge) || bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}

u32 UseCut(u32 fieldMoveStatus)
{
    HideMapNamePopUpWindow();
    LockPlayerAndLoadMon();
#ifdef QOL_NO_MESSAGING
    FlagSet(FLAG_SYS_USE_CUT);
#endif //QOL_NO_MESSAGING

    if (FlagGet(FLAG_SYS_USE_CUT))
        ScriptContext_SetupScript(EventScript_CutTreeDown);
    else if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseCut);
    else if(fieldMoveStatus == FIELD_MOVE_TOOL)
        ScriptContext_SetupScript(EventScript_UseCutTool);

    FlagSet(FLAG_SYS_USE_CUT);
    return COLLISION_START_CUT;
}

// Fly
static void FieldCallback_DetransformAfterFly(void);
static void Task_WaitForDetransformAfterFly(u8 taskId);
static void FieldCallback_DetransformOnCancel(void);
static void Task_DetransformAndReturnToBag(u8 taskId);
static void Task_DetransformAndUnlock(u8 taskId);
static void FieldCB_DetransformAndReturnToBag(void);
static void Task_WaitAndReturnToBag(u8 taskId);
static void FieldCB_DetransformAndUnlock(void);
static void Task_WaitAndUnlock(u8 taskId);

static u8 CreateUseToolTask(void);
static void Task_UseTool_Init(u8);
static void LockPlayerAndLoadMon(void);

static void FieldCallback_UseFlyTool(void);
static void Task_UseFlyTool(void);
static void Task_FlyUpAndWarp(u8 taskId);
static void FieldCallback_FlyUpAnimation(void);
static void Task_TransformThenFlyUp(u8 taskId);

void ReturnToFieldFromFlyToolMapSelect(void)
{
    // Return to field and start fly-up animation (ridemon/transform version)
    SetMainCallback2(CB2_ReturnToField);
    gFieldCallback = FieldCallback_FlyUpAnimation;
}

static void FieldCallback_FlyUpAnimation(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    
    // Lock controls immediately
    LockPlayerFieldControls();
    FreezeObjectEvents();
    
    CreateTask(Task_TransformThenFlyUp, 0);
    gFieldCallback = NULL;
}

static void Task_TransformThenFlyUp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ObjectEvent *playerObj;
    
    switch (task->data[0])
    {
        case 0: // Wait for fade in and ensure player object is ready
            if (!gPaletteFade.active)
            {
                // Ensure player object exists before trying to access it
                if (gPlayerAvatar.objectEventId < OBJECT_EVENTS_COUNT)
                {
                    playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
                    
                    // Turn player to face north using proper function
                    ObjectEventTurn(playerObj, DIR_NORTH);
                    
                    // Transform to Charizard
                    VarSet(VAR_TRANSFORM_MON, SPECIES_CHARIZARD);
                    ChooseMonForTransform();
                    
                    // Find the transform task and prevent it from unlocking controls
                    u8 transformTaskId = FindTaskIdByFunc(Task_UpdatePlayerTransformAnimation);
                    if (transformTaskId != TASK_NONE)
                    {
                        gTasks[transformTaskId].data[2] = FALSE; // tUnlockControls = FALSE
                    }
                    
                    task->data[0]++;
                }
            }
            break;
        case 1: // Wait for transform to complete
            task->data[1]++;
            if (task->data[1] >= 30) // Wait 30 frames
            {
                // Start the fly up task
                CreateTask(Task_FlyUpAndWarp, 0);
                DestroyTask(taskId);
            }
            break;
    }
}

static void Task_FlyUpAndWarp(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *playerSprite = &gSprites[playerObj->spriteId];
    
    switch (task->data[0])
    {
        case 0: // Start flying
            LockPlayerFieldControls();
            FreezeObjectEvents();
            PlaySE(SE_M_FLY);
            FadeScreen(FADE_TO_BLACK, 4); // Start fading
            task->data[0]++;
            break;
        case 1: // Move player up while fading
            // Use task data to track offset (can go beyond y2 limits)
            task->data[1] -= 4; // Decrease by 4 each frame (moving up)
            
            // Apply the offset to y2 (clamped to s8 range)
            if (task->data[1] > -128)
                playerSprite->y2 = task->data[1];
            else
                playerSprite->y2 = -128; // Max offset for y2
            
            // Check if fade is complete
            if (!gPaletteFade.active)
            {
                // Don't set transform here - already transformed
                // Do the actual warp (don't reset y2, player stays off screen)
                Overworld_ResetStateAfterFly();
                WarpIntoMap();
                SetMainCallback2(CB2_LoadMap);
                gFieldCallback = FieldCallback_DetransformAfterFly;
                DestroyTask(taskId);
            }
            break;
    }
}

static void FieldCallback_DetransformAfterFly(void)
{
    struct ObjectEvent *playerObj;
    struct Sprite *playerSprite;
    
    Overworld_PlaySpecialMapMusic();
    
    // Lock controls during descent and detransform
    LockPlayerFieldControls();
    FreezeObjectEvents();
    
    // Position player above ground BEFORE fade-in starts
    playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    playerSprite = &gSprites[playerObj->spriteId];
    playerSprite->y2 = -32; // Start 32 pixels above ground
    
    // Now start fade-in
    FadeInFromBlack();
    
    // Create task for descent animation
    CreateTask(Task_WaitForDetransformAfterFly, 0);
    gFieldCallback = NULL;
}

static void Task_WaitForDetransformAfterFly(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct ObjectEvent *playerObj;
    struct Sprite *playerSprite;
    
    switch (task->data[0])
    {
        case 0: // Initialize
            task->data[1] = -32; // Track descent position (starting high)
            task->data[0] = 1;
            break;
            
        case 1: // Descending animation
            playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
            playerSprite = &gSprites[playerObj->spriteId];
            
            // Move down 2 pixels per frame
            task->data[1] += 2;
            playerSprite->y2 = task->data[1];
            
            // When we reach ground level, start detransform
            if (task->data[1] >= 0)
            {
                playerSprite->y2 = 0;
                
                // Start detransform
                VarSet(VAR_TRANSFORM_MON, SPECIES_NONE);
                ChooseMonForTransform();
                
                // Find the transform task and prevent it from unlocking controls
                u8 transformTaskId = FindTaskIdByFunc(Task_UpdatePlayerTransformAnimation);
                if (transformTaskId != TASK_NONE)
                {
                    gTasks[transformTaskId].data[2] = FALSE; // tUnlockControls = FALSE
                }
                
                task->data[0] = 2;
            }
            break;
            
        case 2: // Wait for transform animation to finish
            if (!FuncIsActiveTask(Task_UpdatePlayerTransformAnimation))
            {
                // Force unlock the player avatar state
                gPlayerAvatar.preventStep = FALSE;
                gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_CONTROLLABLE;
                
                // Unlock controls and events
                UnlockPlayerFieldControls();
                UnfreezeObjectEvents();
                
                DestroyTask(taskId);
            }
            break;
    }
}

static void FieldCallback_DetransformOnCancel(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    
    // Check if we came from bag or field
    if (VarGet(VAR_FLY_TOOL_SOURCE) == FLY_SOURCE_BAG)
    {
        CreateTask(Task_DetransformAndReturnToBag, 0);
    }
    else
    {
        CreateTask(Task_DetransformAndUnlock, 0);
    }
    
    gFieldCallback = NULL;
}

static void Task_DetransformAndReturnToBag(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    
    // Wait for fade to complete first
    if (gPaletteFade.active)
        return;
    
    // Start detransform on first frame after fade
    if (task->data[0] == 0)
    {
        VarSet(VAR_TRANSFORM_MON, SPECIES_NONE);
        ChooseMonForTransform();
        task->data[0]++;
    }
    
    // Wait 20 frames for detransform animation
    if (task->data[0]++ >= 20)
    {
        // Return to bag after detransform
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKET_KEY_ITEMS, CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void Task_DetransformAndUnlock(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    
    // Wait for fade to complete first
    if (gPaletteFade.active)
        return;
    
    // Start detransform on first frame after fade
    if (task->data[0] == 0)
    {
        VarSet(VAR_TRANSFORM_MON, SPECIES_NONE);
        ChooseMonForTransform();
        task->data[0]++;
    }
    
    // Wait 20 frames for detransform animation
    if (task->data[0]++ >= 20)
    {
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        DestroyTask(taskId);
    }
}


static void Task_UseFlyTool(void)
{
    Overworld_ResetStateAfterFly();
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
    gFieldCallback = FieldCallback_UseFlyTool;
}

static void FieldCallback_UseFlyTool(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    if (gPaletteFade.active)
            return;

    UnlockPlayerFieldControls();
    UnfreezeObjectEvents();
    gFieldCallback = NULL;
}

bool32 IsFlyToolUsed(void)
{
    return (VarGet(VAR_FLY_TOOL_SOURCE));
}

void ReturnToFieldOrBagFromFlyTool(void)
{
    // No transform to undo, just return normally
    if (VarGet(VAR_FLY_TOOL_SOURCE) == FLY_SOURCE_BAG)
    {
        gFieldCallback = FieldCB_DetransformAndReturnToBag;
    }
    else
    {
        gFieldCallback = FieldCB_DetransformAndUnlock;
    }
    SetMainCallback2(CB2_ReturnToField);
}

static void FieldCB_DetransformAndReturnToBag(void)
{
    // No transform to wait for, just return to bag
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_WaitAndReturnToBag, 0);
    gFieldCallback = NULL;
}

static void Task_WaitAndReturnToBag(u8 taskId)
{
    // Wait for fade to complete
    if (!gPaletteFade.active)
    {
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKET_KEY_ITEMS, CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

static void FieldCB_DetransformAndUnlock(void)
{
    // No transform to wait for, just unlock
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    CreateTask(Task_WaitAndUnlock, 0);
    gFieldCallback = NULL;
}

static void Task_WaitAndUnlock(u8 taskId)
{
    // Wait for fade to complete
    if (!gPaletteFade.active)
    {
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        DestroyTask(taskId);
    }
}

void ResetFlyTool(void)
{
    VarSet(VAR_FLY_TOOL_SOURCE,0);
}

// Surf
u32 CanUseSurf(s16 x, s16 y, u8 collision)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM03);
    bool32 bagHasItem = CheckBagHasItem(ITEM_SURF_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE05_GET);
    bool32 collisionHasMismatch = (collision == COLLISION_ELEVATION_MISMATCH);

    if (
            IsPlayerFacingSurfableFishableWater2(collision)
            && collisionHasMismatch
            && (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && ((monHasMove && playerHasBadge) || bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}

u32 CanUseSurfFromInteractedWater()
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    return CanUseSurf(x,y,COLLISION_ELEVATION_MISMATCH);
}

u8 FldEff_UseSurfTool(void)
{
    CreateTask(Task_SurfToolFieldEffect, 0);
    Overworld_ClearSavedMusic();
    Overworld_ChangeMusicTo(MUS_SURF);
    return FALSE;
}

static void SurfToolFieldEffect_CheckHeldMovementStatus(struct Task *task)
{
    struct ObjectEvent *objectEvent;
    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (ObjectEventCheckHeldMovementStatus(objectEvent))
        task->tState++;
}

static void (*const sSurfToolFieldEffectFuncs[])(struct Task *) = {
    SurfFieldEffect_Init,
    SurfToolFieldEffect_CheckHeldMovementStatus,
    SurfFieldEffect_JumpOnSurfBlob,
    SurfFieldEffect_End,
};

void Task_SurfToolFieldEffect(u8 taskId)
{
    sSurfToolFieldEffectFuncs[gTasks[taskId].tState](&gTasks[taskId]);
}

u32 UseSurf(u32 fieldMoveStatus)
{
    HideMapNamePopUpWindow();
    
    // If using tool, handle detransform if needed, then surf
    if (fieldMoveStatus == FIELD_MOVE_TOOL)
    {
        // If already transformed (from land-based tool like Rock Smash), detransform first
        if (VarGet(VAR_TRANSFORM_MON) != SPECIES_NONE)
        {
            LockPlayerFieldControls();
            VarSet(VAR_0x8004, 1);
            VarSet(VAR_TRANSFORM_MON, SPECIES_NONE);
            FlagSet(FLAG_DETRANSFORM_NO_FOLLOWER);
            ChooseMonForTransform();
            
            // Set flag to surf after detransform completes
            FlagSet(FLAG_SYS_USE_SURF);
            VarSet(VAR_SURF_MON_SLOT, SURF_MON_LAPRAS);
            RefreshSurfablePaletteFromFlag();
            CreateTask(Task_DelayedAutoSurfInteraction, 0);
            return FIELD_MOVE_TOOL;
        }
        
        // Not transformed, just surf directly
        ForcePlayerToPerformMovementAction();
        LockPlayerAndLoadMon();
        VarSet(VAR_SURF_MON_SLOT, SURF_MON_LAPRAS);
        RefreshSurfablePaletteFromFlag();
        ScriptContext_SetupScript(EventScript_UseSurfTool);
        return FIELD_MOVE_TOOL;
    }
    
    // Original logic for Pokemon
    ForcePlayerToPerformMovementAction();
    LockPlayerAndLoadMon();
    
    if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseSurfMove);
    
    return fieldMoveStatus;
}

void UseSurfFromInteraction(void)
{
    HideMapNamePopUpWindow();
    
    // If already transformed (from land-based tool like Rock Smash), detransform first
    if (VarGet(VAR_TRANSFORM_MON) != SPECIES_NONE)
    {
        LockPlayerFieldControls();
        VarSet(VAR_0x8004, 1);
        VarSet(VAR_TRANSFORM_MON, SPECIES_NONE);
        FlagSet(FLAG_DETRANSFORM_NO_FOLLOWER);
        ChooseMonForTransform();
        
        // Set flag to surf after detransform completes
        FlagSet(FLAG_SYS_USE_SURF);
        VarSet(VAR_SURF_MON_SLOT, SURF_MON_LAPRAS);
        RefreshSurfablePaletteFromFlag();
        CreateTask(Task_DelayedAutoSurfInteraction, 0);
        return;
    }
    
    // Not transformed, just surf directly
    ForcePlayerToPerformMovementAction();
    LockPlayerAndLoadMon();
    VarSet(VAR_SURF_MON_SLOT, SURF_MON_LAPRAS);
    RefreshSurfablePaletteFromFlag();
    ScriptContext_SetupScript(EventScript_UseSurfTool);
}

static void Task_DelayedAutoSurfInteraction(u8 taskId)
{
    // Wait for detransform animation to complete (20 frames)
    if (gTasks[taskId].data[0]++ >= 20)
    {
        ForcePlayerToPerformMovementAction();
        ScriptContext_SetupScript(EventScript_UseSurfTool);
        DestroyTask(taskId);
    }
}

static void Task_DelayedAutoSurf(u8 taskId)
{
    // Wait for detransform animation to complete (20 frames)
    if (gTasks[taskId].data[0]++ >= 20)
    {
        ScriptContext_SetupScript(EventScript_UseSurfTool);
        DestroyTask(taskId);
    }
}

void RemoveRelevantSurfFieldEffect(void)
{
    if (FieldEffectActiveListContains(FLDEFF_USE_SURF))
    {
        FieldEffectActiveListRemove(FLDEFF_USE_SURF);
        DestroyTask(FindTaskIdByFunc(Task_SurfFieldEffect));
    }
    else if(FieldEffectActiveListContains(FLDEFF_USE_SURF_TOOL))
    {
        FieldEffectActiveListRemove(FLDEFF_USE_SURF_TOOL);
        DestroyTask(FindTaskIdByFunc(Task_SurfToolFieldEffect));
    }
}

// Strength

u32 CanUseStrength(u8 collision)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM04);
    bool32 bagHasItem = CheckBagHasItem(ITEM_STRENGTH_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE04_GET);
    bool32 playerUsedStrength = FlagGet(FLAG_SYS_USE_STRENGTH);
    bool32 collisionEvent = (collision == COLLISION_OBJECT_EVENT);

    if (
        CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER)
        && !playerUsedStrength
        && collisionEvent
        && (bagHasItem)
       )
    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }
    return FIELD_MOVE_FAIL;
}

static void Task_DelayedAutoStrength(u8 taskId)
{
    if (gTasks[taskId].data[0]++ >= 20)
    {
        // After transform completes, enable strength
        FlagSet(FLAG_SYS_USE_STRENGTH);
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        DestroyTask(taskId);
    }
}

void GetPlayerTransformSpecies(void)
{
    gSpecialVar_Result = VarGet(VAR_TRANSFORM_MON);
}

u32 UseStrength(u32 fieldMoveStatus, u8 x, u8 y, u8 direction)
{
    HideMapNamePopUpWindow();
    
    // If using tool, transform first if not already Machamp
    if (fieldMoveStatus == FIELD_MOVE_TOOL)
    {
        if (VarGet(VAR_TRANSFORM_MON) != SPECIES_MACHAMP)
        {
            LockPlayerFieldControls();
            VarSet(VAR_TRANSFORM_MON, SPECIES_MACHAMP);
            ChooseMonForTransform();
            PlayCry_Normal(SPECIES_MACHAMP, 0);
            
            CreateTask(Task_DelayedAutoStrength, 0);
            return COLLISION_PUSHED_BOULDER;
        }
        else
        {
            // Already Machamp, just enable strength
            FlagSet(FLAG_SYS_USE_STRENGTH);
            return COLLISION_PUSHED_BOULDER;
        }
    }
    
    // Original logic for Pokemon
#ifdef QOL_NO_MESSAGING
    FlagSet(FLAG_SYS_USE_STRENGTH);
#endif
    LockPlayerAndLoadMon();
    if (FlagGet(FLAG_SYS_USE_STRENGTH))
    {
        TryPushBoulder(x, y, direction);
        return COLLISION_PUSHED_BOULDER;
    }
    FlagSet(FLAG_SYS_USE_STRENGTH);
    if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseStrength);
    else
        ScriptContext_SetupScript(EventScript_UseStrengthTool);
    return COLLISION_PUSHED_BOULDER;
}

void PushBoulderFromScript(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;
    s16 direction = playerObjEvent->movementDirection;

    // 1. Check for transformation first
    if (VarGet(VAR_TRANSFORM_MON) != SPECIES_MACHAMP)
    {
        LockPlayerFieldControls();
        VarSet(VAR_TRANSFORM_MON, SPECIES_MACHAMP);
        ChooseMonForTransform();
        PlayCry_Normal(SPECIES_MACHAMP, 0);
        
        // Use your existing delay task to enable the flag and unlock controls
        CreateTask(Task_DelayedAutoStrength, 0);
    }

    // 2. Actually push the boulder
    MoveCoords(direction, &x, &y);
    TryPushBoulder(x, y, direction);
}

// Flash

static void SetUpFieldMove_UseFlash(u32 fieldMoveStatus)
{
    gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;

    if (fieldMoveStatus == FIELD_MOVE_POKEMON)
        gPostMenuFieldCallback = FieldCallback_UseFlashMove;
    else if (fieldMoveStatus == FIELD_MOVE_TOOL)
        gPostMenuFieldCallback = FieldCallback_UseFlashTool;
}

static void FieldCallback_UseFlashTool(void)
{
    u8 taskId = CreateUseToolTask();
    gTasks[taskId].data[8] = (uintptr_t)FldEff_UseFlashTool >> 16;
    gTasks[taskId].data[9] = (uintptr_t)FldEff_UseFlashTool;
}

static void FieldCallback_UseFlashMove(void)
{
    u8 taskId = CreateFieldMoveTask();
    PartyHasMonLearnsKnowsFieldMove(ITEM_HM05);
    gFieldEffectArguments[0] = gSpecialVar_Result;

    gTasks[taskId].data[8] = (uintptr_t)FldEff_UseFlash >> 16;
    gTasks[taskId].data[9] = (uintptr_t)FldEff_UseFlash;
}

void FldEff_UseFlashTool(void)
{
    HideMapNamePopUpWindow();
    PlaySE(SE_M_REFLECT);
    FlagSet(FLAG_SYS_USE_FLASH);
    ScriptContext_SetupScript(EventScript_UseFlashTool);
}

u32 CanUseFlash(void)
{
    bool32 playerIsInCave = (gMapHeader.cave == TRUE);
    bool32 mapIsNotLit = (GetFlashLevel() == (gMaxFlashLevel - 1));
    bool32 playerHasUsedFlash = FlagGet(FLAG_SYS_USE_FLASH);
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM05);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE02_GET);
    bool32 bagHasItem = CheckBagHasItem(ITEM_FLASH_TOOL,1);

    if(
            playerIsInCave
            && mapIsNotLit
            && !playerHasUsedFlash
            && ((monHasMove && playerHasBadge) || bagHasItem)
      )
    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }
    return FIELD_MOVE_FAIL;
}

static void UseFlash(u32 fieldMoveStatus)
{
    HideMapNamePopUpWindow();
    LockPlayerAndLoadMon();
    SetUpFieldMove_UseFlash(fieldMoveStatus);
}

void TryUseFlash(void)
{
    u32 fieldMoveStatus = CanUseFlash();
    if (fieldMoveStatus)
        UseFlash(fieldMoveStatus);
}

// Rock Smash

u32 CanUseRockSmash(s16 x, s16 y)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM06);
    bool32 bagHasItem = CheckBagHasItem(ITEM_ROCKSMASH_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE03_GET);

    if (
            CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_BREAKABLE_ROCK)
            && GetObjectEventIdByPosition(x, y, 1) == OBJECT_EVENTS_COUNT
            && (bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}

static void Task_DelayedAutoRockSmash(u8 taskId)
{
    // Wait for transform animation to complete (20 frames)
    if (gTasks[taskId].data[0]++ >= 20)
    {
        // Now execute the rock smash script
        ScriptContext_SetupScript(EventScript_SmashRock);
        DestroyTask(taskId);
    }
}

u32 UseRockSmash(u32 fieldMoveStatus)
{
    HideMapNamePopUpWindow();
    
    // If using tool, transform first
    if (fieldMoveStatus == FIELD_MOVE_TOOL)
    {
        if (VarGet(VAR_TRANSFORM_MON) != SPECIES_TAUROS)
        {
            LockPlayerFieldControls();
            VarSet(VAR_TRANSFORM_MON, SPECIES_TAUROS);
            ChooseMonForTransform();
            PlayCry_Normal(SPECIES_TAUROS, 0);
            
            // Set flag to indicate we need to smash after transform
            FlagSet(FLAG_SYS_USE_ROCK_SMASH);
            
            // Create delayed task to execute smash after transform
            CreateTask(Task_DelayedAutoRockSmash, 0);
            return COLLISION_START_ROCK_SMASH;
        }
        else
        {
            LockPlayerFieldControls();
            FlagSet(FLAG_SYS_USE_ROCK_SMASH);
            
            // Create delayed task to execute smash after transform
            CreateTask(Task_DelayedAutoRockSmash, 0);
            return COLLISION_START_ROCK_SMASH;
        }
        
    }
    
    // Original logic for Pokemon/non-tool cases
    LockPlayerAndLoadMon();
#ifdef QOL_NO_MESSAGING
    FlagSet(FLAG_SYS_USE_ROCK_SMASH);
#endif
    if (FlagGet(FLAG_SYS_USE_ROCK_SMASH))
        ScriptContext_SetupScript(EventScript_SmashRock);
    else if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseRockSmash);
    
    FlagSet(FLAG_SYS_USE_ROCK_SMASH);
    return COLLISION_START_ROCK_SMASH;
}
static u8 sRockToSmashLocalId = 0;

static void Task_DelayedRockSmashToolScript(u8 taskId)
{
    if (gTasks[taskId].data[0]++ >= 20)
    {
        // Restore the rock ID before re-running script
        VarSet(VAR_LAST_TALKED, sRockToSmashLocalId);
        ScriptContext_SetupScript(EventScript_UseRockSmashTool);
        DestroyTask(taskId);
    }
}

void PrepareRockSmashToolUse(void)
{
    // Store the rock we're about to smash
    sRockToSmashLocalId = VarGet(VAR_LAST_TALKED);
    
    // If not Tauros, transform first
    if (VarGet(VAR_TRANSFORM_MON) != SPECIES_TAUROS)
    {
        LockPlayerFieldControls();
        VarSet(VAR_TRANSFORM_MON, SPECIES_TAUROS);
        ChooseMonForTransform();
        PlayCry_Normal(SPECIES_TAUROS, 0);
        FlagSet(FLAG_SYS_USE_ROCK_SMASH);
        CreateTask(Task_DelayedRockSmashToolScript, 0);
        gSpecialVar_Result = TRUE; // Signal to exit script early
    }
    else
    {
        gSpecialVar_Result = FALSE; // Continue with script
    }
}



//Waterfall

u32 CanUseWaterfallFromInteractedWater(void)
{
    return CanUseWaterfall(DIR_SOUTH);
}

bool8 IsPlayerFacingWaterfall(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    MoveCoords(playerObjEvent->facingDirection, &x, &y);
    if (GetCollisionAtCoords(playerObjEvent, x, y, playerObjEvent->facingDirection) == COLLISION_NONE
     && MetatileBehavior_IsWaterfall(MapGridGetMetatileBehaviorAt(x, y)))
        return TRUE;
    else
       return FALSE;
}

u32 CanUseWaterfall(u8 direction)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM07);
    bool32 bagHasItem = CheckBagHasItem(ITEM_WATERFALL_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE08_GET);
    bool32 isPlayerPushedSouth = (direction == DIR_SOUTH);

    if (
            IsPlayerFacingWaterfall()
            && IsPlayerSurfingNorth()
            && isPlayerPushedSouth
            && ((monHasMove && playerHasBadge) || bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}

u32 CanUseWaterfallTool(void)
{
    return CanUseWaterfall(DIR_SOUTH);
}

u32 UseWaterfall(struct PlayerAvatar playerAvatar, u32 fieldMoveStatus)
{
    HideMapNamePopUpWindow();
    LockPlayerAndLoadMon();
#ifdef QOL_NO_MESSAGING
    FlagSet(FLAG_SYS_USE_WATERFALL);
#endif //QOL_NO_MESSAGING
    playerAvatar.runningState = MOVING;

    if (FlagGet(FLAG_SYS_USE_WATERFALL))
        FieldEffectStart(FLDEFF_USE_WATERFALL_TOOL);
    else if(fieldMoveStatus == FIELD_MOVE_POKEMON)
        ScriptContext_SetupScript(EventScript_UseWaterfallMon);
    else if(fieldMoveStatus == FIELD_MOVE_TOOL)
        ScriptContext_SetupScript(EventScript_UseWaterfallTool);

    FlagSet(FLAG_SYS_USE_WATERFALL);
    return TRUE;
}

static bool8 WaterfallToolFieldEffect_ContinueRideOrEnd(struct Task *task, struct ObjectEvent *objectEvent)
{
    if (!ObjectEventClearHeldMovementIfFinished(objectEvent))
        return FALSE;

    if (MetatileBehavior_IsWaterfall(objectEvent->currentMetatileBehavior))
    {
        // Still ascending waterfall, back to WaterfallFieldEffect_RideUp
        task->tState = 1;
        return TRUE;
    }

    UnlockPlayerFieldControls();
    gPlayerAvatar.preventStep = FALSE;
    DestroyTask(FindTaskIdByFunc(Task_UseWaterfallTool));
    FieldEffectActiveListRemove(FLDEFF_USE_WATERFALL_TOOL);
    return FALSE;
    return WaterfallFieldEffect_ContinueRideOrEnd(task, objectEvent);
}

static bool8 (*const sWaterfallToolFieldEffectFuncs[])(struct Task *, struct ObjectEvent *) =
{
    WaterfallFieldEffect_Init,
    WaterfallFieldEffect_RideUp,
    WaterfallToolFieldEffect_ContinueRideOrEnd,
};

static void Task_UseWaterfallTool(u8 taskId)
{
    while (sWaterfallToolFieldEffectFuncs[gTasks[taskId].tState](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]));
}

u8 FldEff_UseWaterfallTool(void)
{
    u8 taskId = CreateTask(Task_UseWaterfallTool, 0);
    Task_UseWaterfallTool(taskId);
    return FALSE;
}

void RemoveRelevantWaterfallFieldEffect(void)
{
    if (FieldEffectActiveListContains(FLDEFF_USE_WATERFALL))
    {
        FieldEffectActiveListRemove(FLDEFF_USE_WATERFALL);
        DestroyTask(FindTaskIdByFunc(Task_UseWaterfall));
    }
    else if(FieldEffectActiveListContains(FLDEFF_USE_WATERFALL_TOOL))
    {
        FieldEffectActiveListRemove(FLDEFF_USE_SURF_TOOL);
        DestroyTask(FindTaskIdByFunc(Task_UseWaterfallTool));
    }
}

// Dive

u32 CanUseDiveDown(void)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM08);
    bool32 bagHasItem = CheckBagHasItem(ITEM_DIVE_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE07_GET);
    bool32 diveWarpSuccessful = (TrySetDiveWarp() == 2);

    if (
            diveWarpSuccessful
            && ((monHasMove && playerHasBadge) || bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}

u32 CanUseDiveEmerge(void)
{
    bool32 monHasMove = PartyHasMonLearnsKnowsFieldMove(ITEM_HM08);
    bool32 bagHasItem = CheckBagHasItem(ITEM_DIVE_TOOL,1);
    bool32 playerHasBadge = FlagGet(FLAG_BADGE07_GET);
    bool32 diveWarpSuccessful = (TrySetDiveWarp() == 1);
    bool32 playerisUnderwater = (gMapHeader.mapType == MAP_TYPE_UNDERWATER);

    if (
            diveWarpSuccessful
            && playerisUnderwater
            && ((monHasMove && playerHasBadge) || bagHasItem)
       )

    {
        return bagHasItem ? FIELD_MOVE_TOOL : FIELD_MOVE_POKEMON;
    }

    return FIELD_MOVE_FAIL;
}


static bool8 (*const sDiveToolFieldEffectFuncs[])(struct Task *) =
{
    DiveFieldEffect_Init,
    DiveFieldEffect_TryWarp,
};

bool8 FldEff_UseDiveTool(void)
{
    u8 taskId;
    taskId = CreateTask(Task_UseDiveTool, 0xff);
    Task_UseDiveTool(taskId);
    return FALSE;
}

static void Task_UseDiveTool(u8 taskId)
{
    while (sDiveToolFieldEffectFuncs[gTasks[taskId].data[0]](&gTasks[taskId]));
}

void RemoveRelevantDiveFieldEffect(void)
{
    if (FieldEffectActiveListContains(FLDEFF_USE_DIVE))
    {
        FieldEffectActiveListRemove(FLDEFF_USE_DIVE);
        DestroyTask(FindTaskIdByFunc(Task_UseDive));
    }
    else if(FieldEffectActiveListContains(FLDEFF_USE_DIVE_TOOL))
    {
        FieldEffectActiveListRemove(FLDEFF_USE_SURF_TOOL);
        DestroyTask(FindTaskIdByFunc(Task_UseDiveTool));
    }
}

// Teleport

bool8 FldEff_UseTeleportTool(void)
{
    u8 taskId = CreateUseToolTask();
    gTasks[taskId].data[8] = (u32)StartTeleportFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartTeleportFieldEffect;
    SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    return FALSE;
}

// Sweet Scent

bool8 FldEff_SweetScentTool(void)
{
    u8 taskId;

    SetWeatherScreenFadeOut();
    taskId = CreateUseToolTask();
    gTasks[taskId].data[8] = (u32)StartSweetScentFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSweetScentFieldEffect;
    return FALSE;
}

void ClearFieldMoveFlags(void)
{
    FlagClear(FLAG_SYS_USE_CUT);
    FlagClear(FLAG_SYS_USE_SURF);
    FlagClear(FLAG_SYS_USE_ROCK_SMASH);
    FlagClear(FLAG_SYS_USE_WATERFALL);
}

static bool32 PartyCanLearnMoveLevelUp(u16 species, u16 moveId)
{
    u32 i = 0;
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if ((learnset[i].move & LEVEL_UP_MOVE_ID) == moveId)
            return TRUE;
    }
    return FALSE;
}

bool32 PartyHasMonLearnsKnowsFieldMove(u16 itemId)
{
    struct Pokemon *mon;
    u32 species, i, monCanLearnTM;
    u16 moveId = ItemIdToBattleMoveId(itemId);
    gSpecialVar_Result = PARTY_SIZE;
    gSpecialVar_0x8004 = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[i];
        species = GetMonData(mon,MON_DATA_SPECIES,NULL);

        if (species == SPECIES_NONE)
            break;

        monCanLearnTM = CanTeachMove(mon,moveId);
        if ((PartyCanLearnMoveLevelUp(species, moveId)
                || (monCanLearnTM) == ALREADY_KNOWS_MOVE)
                || (monCanLearnTM) == CAN_LEARN_MOVE)
            return SetMonResultVariables(i,species);

    }
    return FALSE;
}

static bool32 SetMonResultVariables(u32 partyIndex, u32 species)
{
    gSpecialVar_Result = partyIndex;
    gSpecialVar_0x8004 = species;
    return TRUE;
}

void TransformToMudsdale(void)
{
    VarSet(VAR_TRANSFORM_MON, SPECIES_MUDSDALE);
    ChooseMonForTransform();
}
