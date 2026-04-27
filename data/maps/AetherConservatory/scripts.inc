AetherConservatory_MapScripts::
# 2 "data/maps/AetherConservatory/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AetherConservatory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 3 "data/maps/AetherConservatory/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AetherConservatory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AetherConservatory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/AetherConservatory/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, AetherConservatory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

AetherConservatory_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 2 "data/maps/AetherConservatory/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_AETHER_CONSERVATORY
	return

AetherConservatory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/AetherConservatory/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, AetherIntroSequence
	.2byte 0


UseElevator::
# 7 "data/maps/AetherConservatory/scripts.pory"
	lockall
# 8 "data/maps/AetherConservatory/scripts.pory"
	msgbox UseElevator_Text_0, MSGBOX_YESNO
# 12 "data/maps/AetherConservatory/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq UseElevator_1
# 21 "data/maps/AetherConservatory/scripts.pory"
	waitmessage
# 22 "data/maps/AetherConservatory/scripts.pory"
	releaseall
	end

UseElevator_1:
# 13 "data/maps/AetherConservatory/scripts.pory"
	setflag FLAG_WARP_TO_BOATHOUSE
# 14 "data/maps/AetherConservatory/scripts.pory"
	warp MAP_HAUOLI_DOCK_BOATHOUSE, 10, 6
# 15 "data/maps/AetherConservatory/scripts.pory"
	waitstate
# 16 "data/maps/AetherConservatory/scripts.pory"
	delay 30
# 17 "data/maps/AetherConservatory/scripts.pory"
	release
	end


AetherIntroSequence::
# 29 "data/maps/AetherConservatory/scripts.pory"
	lock
# 30 "data/maps/AetherConservatory/scripts.pory"
	special ShowCutsceneCinematicBars
# 31 "data/maps/AetherConservatory/scripts.pory"
	special SpawnCameraObject
# 32 "data/maps/AetherConservatory/scripts.pory"
	delay 60
# 33 "data/maps/AetherConservatory/scripts.pory"
	clearflag FLAG_SHOW_LILLIE_INTRO
# 34 "data/maps/AetherConservatory/scripts.pory"
	addobject LillieIntro
# 35 "data/maps/AetherConservatory/scripts.pory"
	addobject aetherintrogrunt1
# 36 "data/maps/AetherConservatory/scripts.pory"
	addobject aetherintrogrunt2
# 37 "data/maps/AetherConservatory/scripts.pory"
	playse SE_WARP_IN
# 38 "data/maps/AetherConservatory/scripts.pory"
	waitse
# 39 "data/maps/AetherConservatory/scripts.pory"
	delay 60
# 41 "data/maps/AetherConservatory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AetherIntroSequence_Movement_0
# 42 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, AetherIntroSequence_Movement_0
# 43 "data/maps/AetherConservatory/scripts.pory"
	waitmovement LillieIntro
# 44 "data/maps/AetherConservatory/scripts.pory"
	delay 30
# 46 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, AetherIntroSequence_Movement_1
# 47 "data/maps/AetherConservatory/scripts.pory"
	waitmovement LillieIntro
# 48 "data/maps/AetherConservatory/scripts.pory"
	delay 15
# 50 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, Common_Movement_ExclamationMark
# 51 "data/maps/AetherConservatory/scripts.pory"
	waitmovement LillieIntro
# 52 "data/maps/AetherConservatory/scripts.pory"
	playse SE_PIN
# 53 "data/maps/AetherConservatory/scripts.pory"
	waitse
# 54 "data/maps/AetherConservatory/scripts.pory"
	playbgm MUS_HELP, FALSE
# 55 "data/maps/AetherConservatory/scripts.pory"
	delay 20
# 57 "data/maps/AetherConservatory/scripts.pory"
	playse SE_FLEE
# 58 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, AetherIntroSequence_Movement_2
# 59 "data/maps/AetherConservatory/scripts.pory"
	waitmovement LillieIntro
# 60 "data/maps/AetherConservatory/scripts.pory"
	waitse
# 62 "data/maps/AetherConservatory/scripts.pory"
	playse SE_FLEE
# 63 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt1, AetherIntroSequence_Movement_3
# 64 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt2, AetherIntroSequence_Movement_4
# 65 "data/maps/AetherConservatory/scripts.pory"
	waitse
# 66 "data/maps/AetherConservatory/scripts.pory"
	waitmovement 0
# 68 "data/maps/AetherConservatory/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 69 "data/maps/AetherConservatory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AetherIntroSequence_Movement_5
# 70 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, AetherIntroSequence_Movement_5
# 71 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt1, AetherIntroSequence_Movement_5
# 72 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt2, AetherIntroSequence_Movement_5
# 73 "data/maps/AetherConservatory/scripts.pory"
	waitmovement 0
# 74 "data/maps/AetherConservatory/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 76 "data/maps/AetherConservatory/scripts.pory"
	playse SE_FLEE
# 77 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, AetherIntroSequence_Movement_6
# 78 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt1, AetherIntroSequence_Movement_7
# 79 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt2, AetherIntroSequence_Movement_8
# 80 "data/maps/AetherConservatory/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, AetherIntroSequence_Movement_9
# 81 "data/maps/AetherConservatory/scripts.pory"
	waitmovement 0
# 82 "data/maps/AetherConservatory/scripts.pory"
	waitse
# 83 "data/maps/AetherConservatory/scripts.pory"
	delay 15
# 85 "data/maps/AetherConservatory/scripts.pory"
	playse SE_PIN
# 86 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, Common_Movement_ExclamationMark
# 87 "data/maps/AetherConservatory/scripts.pory"
	waitmovement LillieIntro
# 88 "data/maps/AetherConservatory/scripts.pory"
	delay 20
# 90 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, AetherIntroSequence_Movement_10
# 91 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt1, AetherIntroSequence_Movement_11
# 92 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt2, AetherIntroSequence_Movement_11
# 93 "data/maps/AetherConservatory/scripts.pory"
	applymovement aetherintrogrunt3, AetherIntroSequence_Movement_12
# 94 "data/maps/AetherConservatory/scripts.pory"
	waitmovement 0
# 95 "data/maps/AetherConservatory/scripts.pory"
	delay 60
# 97 "data/maps/AetherConservatory/scripts.pory"
	setvar VAR_RESULT, 1
# 98 "data/maps/AetherConservatory/scripts.pory"
	playse SE_M_DETECT
# 99 "data/maps/AetherConservatory/scripts.pory"
	dofieldeffectsparkle 16, 17, 0
# 100 "data/maps/AetherConservatory/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 101 "data/maps/AetherConservatory/scripts.pory"
	closemessage
# 103 "data/maps/AetherConservatory/scripts.pory"
	playse SE_PIN
# 104 "data/maps/AetherConservatory/scripts.pory"
	applymovement LillieIntro, Common_Movement_ExclamationMark
# 105 "data/maps/AetherConservatory/scripts.pory"
	waitmovement 0
# 106 "data/maps/AetherConservatory/scripts.pory"
	delay 30
# 107 "data/maps/AetherConservatory/scripts.pory"
	setvar VAR_RESULT, 3
# 108 "data/maps/AetherConservatory/scripts.pory"
	delay 20
# 109 "data/maps/AetherConservatory/scripts.pory"
	special RemoveCameraObject
# 111 "data/maps/AetherConservatory/scripts.pory"
	playse SE_ORB
# 112 "data/maps/AetherConservatory/scripts.pory"
	special DoOrbEffect
# 113 "data/maps/AetherConservatory/scripts.pory"
	delay 120
# 114 "data/maps/AetherConservatory/scripts.pory"
	fadescreen FADE_TO_BLACK
# 115 "data/maps/AetherConservatory/scripts.pory"
	waitstate
# 116 "data/maps/AetherConservatory/scripts.pory"
	special HideCutsceneCinematicBars
# 117 "data/maps/AetherConservatory/scripts.pory"
	fadenewbgm MUS_NONE
# 118 "data/maps/AetherConservatory/scripts.pory"
	setvar VAR_0x8000, 0
# 119 "data/maps/AetherConservatory/scripts.pory"
	delay 90
# 120 "data/maps/AetherConservatory/scripts.pory"
	setflag FLAG_SHOW_LILLIE_INTRO
# 121 "data/maps/AetherConservatory/scripts.pory"
	setvar VAR_RESULT, 1
# 122 "data/maps/AetherConservatory/scripts.pory"
	playse SE_M_COSMIC_POWER
# 123 "data/maps/AetherConservatory/scripts.pory"
	callnative OpenScreenshotsFromScript
# 124 "data/maps/AetherConservatory/scripts.pory"
	delay 30
# 125 "data/maps/AetherConservatory/scripts.pory"
	warp MAP_ROUTE1, 27, 19
# 126 "data/maps/AetherConservatory/scripts.pory"
	waitstate
# 127 "data/maps/AetherConservatory/scripts.pory"
	release
	end


# 41 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_0:
# 41 "data/maps/AetherConservatory/scripts.pory"
	walk_down
# 41 "data/maps/AetherConservatory/scripts.pory"
	walk_down
# 41 "data/maps/AetherConservatory/scripts.pory"
	walk_down
# 41 "data/maps/AetherConservatory/scripts.pory"
	walk_down
	step_end

# 46 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_1:
# 46 "data/maps/AetherConservatory/scripts.pory"
	face_right
# 46 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 46 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 46 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 46 "data/maps/AetherConservatory/scripts.pory"
	face_left
	step_end

# 58 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_2:
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
# 58 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_right
	step_end

# 63 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_3:
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 63 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
	step_end

# 64 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_4:
# 64 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
# 64 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_right
	step_end

# 69 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_5:
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
# 69 "data/maps/AetherConservatory/scripts.pory"
	walk_faster_up
	step_end

# 77 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_6:
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 77 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
	step_end

# 78 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_7:
# 78 "data/maps/AetherConservatory/scripts.pory"
	delay_8
# 78 "data/maps/AetherConservatory/scripts.pory"
	delay_8
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 78 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
	step_end

# 79 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_8:
# 79 "data/maps/AetherConservatory/scripts.pory"
	delay_8
# 79 "data/maps/AetherConservatory/scripts.pory"
	delay_8
# 79 "data/maps/AetherConservatory/scripts.pory"
	delay_8
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 79 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
	step_end

# 80 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_9:
# 80 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 80 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 80 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 80 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
# 80 "data/maps/AetherConservatory/scripts.pory"
	walk_fast_left
	step_end

# 90 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_10:
# 90 "data/maps/AetherConservatory/scripts.pory"
	face_right
# 90 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 90 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 90 "data/maps/AetherConservatory/scripts.pory"
	face_left
# 90 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 90 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 90 "data/maps/AetherConservatory/scripts.pory"
	face_right
# 90 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 90 "data/maps/AetherConservatory/scripts.pory"
	face_left
	step_end

# 91 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_11:
# 91 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 91 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 91 "data/maps/AetherConservatory/scripts.pory"
	walk_left
	step_end

# 93 "data/maps/AetherConservatory/scripts.pory"
AetherIntroSequence_Movement_12:
# 93 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 93 "data/maps/AetherConservatory/scripts.pory"
	delay_16
# 93 "data/maps/AetherConservatory/scripts.pory"
	walk_right
	step_end

UseElevator_Text_0:
# 8 "data/maps/AetherConservatory/scripts.pory"
	.string "This elevator will take you back to the\n"
	.string "Hau'oli City Docks.\p"
	.string "Would you like to use it?$"
