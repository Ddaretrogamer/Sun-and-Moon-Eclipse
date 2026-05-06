IkiTown_MapScripts::
# 2 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	end


Ikitown_trigger_right::
# 8 "data/maps/IkiTown/scripts.pory"
	lock
# 9 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 10 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 11 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 15 "data/maps/IkiTown/scripts.pory"
	lock
# 16 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 17 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 18 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitown::
# 22 "data/maps/IkiTown/scripts.pory"
	lock
# 23 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 24 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 25 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 26 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 27 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 28 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 29 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 30 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 31 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 32 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 33 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 34 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 35 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 36 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 37 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 38 "data/maps/IkiTown/scripts.pory"
	delay 30
# 39 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_4
# 40 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 41 "data/maps/IkiTown/scripts.pory"
	delay 30
# 42 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_4
# 43 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 44 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_5
# 45 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 46 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 47 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1, MSGBOX_AUTOCLOSE
# 49 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 50 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 51 "data/maps/IkiTown/scripts.pory"
	delay 120
# 52 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 53 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 54 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 55 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 61 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 62 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_7
# 63 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 64 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 65 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 66 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_8
# 67 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 68 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 69 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 75 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_5
# 76 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 77 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_4
# 78 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5
# 81 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_9
# 82 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 83 "data/maps/IkiTown/scripts.pory"
	waitse
# 84 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 85 "data/maps/IkiTown/scripts.pory"
	waitse
# 86 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 87 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 88 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 92 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 96 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 101 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_10
# 102 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 103 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 104 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_5
# 105 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 106 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 107 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_9
# 119 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_9
# 120 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 121 "data/maps/IkiTown/scripts.pory"
	waitse
# 122 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 123 "data/maps/IkiTown/scripts.pory"
	waitse
# 124 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 125 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_10
# 131 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 132 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 133 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 89 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 93 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 97 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 138 "data/maps/IkiTown/scripts.pory"
	lock
# 139 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 140 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_trigger_WecomeToIkitown_Text_0
# 141 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 143 "data/maps/IkiTown/scripts.pory"
	release
	end


# 9 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 9 "data/maps/IkiTown/scripts.pory"
	walk_left
# 9 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 16 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 16 "data/maps/IkiTown/scripts.pory"
	walk_right
# 16 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 31 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 31 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 31 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 31 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 31 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 31 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 31 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 31 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 31 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 32 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 32 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 35 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
# 35 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 36 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 36 "data/maps/IkiTown/scripts.pory"
	delay_16
# 36 "data/maps/IkiTown/scripts.pory"
	delay_16
# 36 "data/maps/IkiTown/scripts.pory"
	delay_16
# 36 "data/maps/IkiTown/scripts.pory"
	delay_16
# 36 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 36 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 36 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 36 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 36 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 36 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 36 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 39 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 39 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 44 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 44 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 44 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 50 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_up
# 50 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 62 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 62 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 66 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 66 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 81 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_9:
# 81 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 81 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 101 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_10:
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 101 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

Ikitown_trigger_WecomeToIkitown_Text_0:
# 46 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 47 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 55 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 69 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 77 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 78 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 89 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 93 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 97 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_9:
# 107 "data/maps/IkiTown/scripts.pory"
	.string "Hey, I've got an idea for you,\n"
	.string "{PLAYER}.\p"
	.string "If you head through the village and\n"
	.string "up the hill, you can visit the ruins\l"
	.string "that belong to Tapu Koko.\p"
	.string "That's our island's guardian deity,\n"
	.string "yeah.\p"
	.string "Why don't you go and introduce\n"
	.string "yourself?$"

Ikitown_trigger_WecomeToIkitown_Text_10:
# 125 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 141 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"
