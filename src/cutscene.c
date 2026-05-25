#include "global.h"
#include "gba/gba.h"
#include "cutscene.h"
#include "constants/cutscene.h"
#include "constants/flags.h"
#include "data/cutscene.h"
#include "event_data.h"
#include "main.h"
#include "script.h"
#include "sprite.h"
#include "task.h"

#define TAG_CUTSCENE_SKIP_BUTTON 5550

static const u16 sCutsceneSkipButton_Gfx[] = INCBIN_U16("graphics/cutscene/skip_button.4bpp");
static const u16 sCutsceneSkipButton_Pal[] = INCBIN_U16("graphics/cutscene/skip_button.gbapal");

static const struct SpriteSheet sCutsceneSkipButtonSpriteSheets[] = {
    {(const void *)sCutsceneSkipButton_Gfx, sizeof(sCutsceneSkipButton_Gfx), TAG_CUTSCENE_SKIP_BUTTON},
    {0}
};

static const union AnimCmd sCutsceneSkipButtonAnim[] = {
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(8, 16),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sCutsceneSkipButtonAnimTable[] = {
    sCutsceneSkipButtonAnim
};

static const struct SpritePalette sCutsceneSkipButtonPalette = {sCutsceneSkipButton_Pal, TAG_CUTSCENE_SKIP_BUTTON};

static const struct OamData sCutsceneSkipButtonOamData = {
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2
};

static const struct SpriteTemplate sCutsceneSkipButtonTemplate = {
    TAG_CUTSCENE_SKIP_BUTTON,
    TAG_CUTSCENE_SKIP_BUTTON,
    &sCutsceneSkipButtonOamData,
    sCutsceneSkipButtonAnimTable,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static void Task_SkippableCutscene(u8 taskId);
static bool32 TaskHelper_CheckCutsceneFlag(u32 cutscene);
static void TaskHelper_SetCutsceneFlag(u32 cutscene);
#if CUTSCENE_FLAG_TRACKING == FALSE
static bool32 TaskHelper_GetSetCutsceneFlagSaveStruct(u32 cutscene, bool32 setFlag);
#endif

#define tCutscene data[0]
#define tSpriteId data[1]

void StartSkippableCutscene(struct ScriptContext *ctx)
{
    u32 cutscene = gSpecialVar_0x8004;

    if (TaskHelper_CheckCutsceneFlag(cutscene))
    {
        u8 taskId = CreateTask(Task_SkippableCutscene, 64);
        u8 spriteId;

        gTasks[taskId].tCutscene = cutscene;

        if (!FlagGet(FLAG_CUTSCENE_SKIP_BUTTON_TOGGLE))
        {
            LoadSpriteSheets(sCutsceneSkipButtonSpriteSheets);
            LoadSpritePalette(&sCutsceneSkipButtonPalette);
            spriteId = CreateSprite(&sCutsceneSkipButtonTemplate, 20, 30, 0xFF);
            gSprites[spriteId].oam.priority = 0;
            gTasks[taskId].tSpriteId = spriteId;
        }
        else
        {
            gTasks[taskId].tSpriteId = MAX_SPRITES; // sentinel: no sprite
        }
    }
    else
    {
        TaskHelper_SetCutsceneFlag(cutscene);
    }
}

static void Task_SkippableCutscene(u8 taskId)
{
    u32 cutscene = gTasks[taskId].tCutscene;

    if (cutscene >= CUTSCENE_COUNT)
        return;

    if (JOY_NEW(START_BUTTON))
    {
        ScriptContext_SetupScript(sCutsceneSkipScripts[cutscene].scriptCutsceneSkipPtr);
        EndSkippableCutscene(NULL);
    }
}

void EndSkippableCutscene(struct ScriptContext *ctx)
{
    u8 taskId = FindTaskIdByFunc(Task_SkippableCutscene);
    if (taskId != TASK_NONE)
    {
        if (gTasks[taskId].tSpriteId != MAX_SPRITES)
        {
            DestroySprite(&gSprites[gTasks[taskId].tSpriteId]);
            FreeSpriteTilesByTag(TAG_CUTSCENE_SKIP_BUTTON);
            FreeSpritePaletteByTag(TAG_CUTSCENE_SKIP_BUTTON);
        }
        DestroyTask(taskId);
    }
}

static bool32 TaskHelper_CheckCutsceneFlag(u32 cutscene)
{
    if (cutscene >= CUTSCENE_COUNT)
        return FALSE;

#if CUTSCENE_FLAG_TRACKING == TRUE
    // flag = 0 means always skippable; flag != 0 means only skippable after first viewing
    if (sCutsceneSkipScripts[cutscene].flag == 0
        || FlagGet(sCutsceneSkipScripts[cutscene].flag))
    {
        return TRUE;
    }
#else
    if (TaskHelper_GetSetCutsceneFlagSaveStruct(cutscene, FALSE))
        return TRUE;
#endif
    return FALSE;
}

static void TaskHelper_SetCutsceneFlag(u32 cutscene)
{
    if (cutscene >= CUTSCENE_COUNT)
        return;

#if CUTSCENE_FLAG_TRACKING == TRUE
    if (sCutsceneSkipScripts[cutscene].flag != 0)
        FlagSet(sCutsceneSkipScripts[cutscene].flag);
#else
    TaskHelper_GetSetCutsceneFlagSaveStruct(cutscene, TRUE);
#endif
}

#if CUTSCENE_FLAG_TRACKING == FALSE
static bool32 TaskHelper_GetSetCutsceneFlagSaveStruct(u32 cutscene, bool32 setFlag)
{
    u32 index, bit, mask;
    bool32 retVal = FALSE;

    if (cutscene >= CUTSCENE_COUNT)
        return retVal;

    index = cutscene / 8;
    bit = cutscene % 8;
    mask = 1 << bit;

    if (setFlag)
        gSaveBlock2Ptr->flagCutscenes[index] |= mask;
    else
        retVal = ((gSaveBlock2Ptr->flagCutscenes[index] & mask) != 0);

    return retVal;
}
#endif

#undef tCutscene
#undef tSpriteId
