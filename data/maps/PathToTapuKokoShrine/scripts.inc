PathToTapuKokoShrine_MapScripts::
	.byte 0


PathToTapuKokoShrine_Woman::
# 4 "data/maps/PathToTapuKokoShrine/scripts.pory"
	lock
# 5 "data/maps/PathToTapuKokoShrine/scripts.pory"
	faceplayer
# 6 "data/maps/PathToTapuKokoShrine/scripts.pory"
	msgbox PathToTapuKokoShrine_Woman_Text_0
# 11 "data/maps/PathToTapuKokoShrine/scripts.pory"
	release
	end


PathToTapuKokoShrine_Meowth::
# 16 "data/maps/PathToTapuKokoShrine/scripts.pory"
	lock
# 17 "data/maps/PathToTapuKokoShrine/scripts.pory"
	faceplayer
# 18 "data/maps/PathToTapuKokoShrine/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 19 "data/maps/PathToTapuKokoShrine/scripts.pory"
	msgbox PathToTapuKokoShrine_Meowth_Text_0
# 20 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmessage
# 21 "data/maps/PathToTapuKokoShrine/scripts.pory"
	release
	end


PathToTapuKokoShrine_Trigger_Lillie::
# 26 "data/maps/PathToTapuKokoShrine/scripts.pory"
	lock
# 27 "data/maps/PathToTapuKokoShrine/scripts.pory"
	special SpawnCameraObject
# 28 "data/maps/PathToTapuKokoShrine/scripts.pory"
	setflag FLAG_HIDE_CIRCLING_WINGULLS
# 29 "data/maps/PathToTapuKokoShrine/scripts.pory"
	callnative Script_RollShiny
# 30 "data/maps/PathToTapuKokoShrine/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 31 "data/maps/PathToTapuKokoShrine/scripts.pory"
	compare VAR_TEMP_1, SHINY_MODE_ALWAYS
	goto_if_eq PathToTapuKokoShrine_Trigger_Lillie_2
PathToTapuKokoShrine_Trigger_Lillie_1:
# 34 "data/maps/PathToTapuKokoShrine/scripts.pory"
	playse SE_PIN
# 35 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement LOCALID_PLAYER, PathToTapuKokoShrine_Trigger_Lillie_Movement_0
# 36 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 60
# 37 "data/maps/PathToTapuKokoShrine/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 38 "data/maps/PathToTapuKokoShrine/scripts.pory"
	compare VAR_TEMP_2, 19
	goto_if_eq PathToTapuKokoShrine_Trigger_Lillie_5
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_5
# 62 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
# 63 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 64 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_2
# 65 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 66 "data/maps/PathToTapuKokoShrine/scripts.pory"
	msgbox PathToTapuKokoShrine_Trigger_Lillie_Text_0, MSGBOX_AUTOCLOSE
# 72 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmessage
# 73 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_3
# 74 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 75 "data/maps/PathToTapuKokoShrine/scripts.pory"
	playse SE_EXIT
# 76 "data/maps/PathToTapuKokoShrine/scripts.pory"
	setflag FLAG_HIDE_PATHTORUINS_LILLIE
# 77 "data/maps/PathToTapuKokoShrine/scripts.pory"
	removeobject pathtoruinslillie
# 78 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitse
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_6
# 81 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
PathToTapuKokoShrine_Trigger_Lillie_4:
# 83 "data/maps/PathToTapuKokoShrine/scripts.pory"
	special RemoveCameraObject
# 84 "data/maps/PathToTapuKokoShrine/scripts.pory"
	setvar VAR_IKITOWN_STATE, 3
# 85 "data/maps/PathToTapuKokoShrine/scripts.pory"
	release
	end

PathToTapuKokoShrine_Trigger_Lillie_2:
# 32 "data/maps/PathToTapuKokoShrine/scripts.pory"
	setflag FLAG_SHINY_COSMOG
	goto PathToTapuKokoShrine_Trigger_Lillie_1

PathToTapuKokoShrine_Trigger_Lillie_5:
# 39 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_1
# 40 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
# 41 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 42 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_2
# 43 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 44 "data/maps/PathToTapuKokoShrine/scripts.pory"
	msgbox PathToTapuKokoShrine_Trigger_Lillie_Text_0, MSGBOX_AUTOCLOSE
# 50 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmessage
# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_3
# 52 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	playse SE_EXIT
# 54 "data/maps/PathToTapuKokoShrine/scripts.pory"
	removeobject pathtoruinslillie
# 55 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitse
# 56 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 57 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_4
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
	goto PathToTapuKokoShrine_Trigger_Lillie_4


# 35 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_0:
# 35 "data/maps/PathToTapuKokoShrine/scripts.pory"
	emote_question_mark
	step_end

# 39 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_1:
# 39 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 39 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 39 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 39 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 39 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
	step_end

# 42 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_2:
# 42 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_in_place_up
# 42 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_in_place_up
	step_end

# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_3:
# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
	step_end

# 57 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_4:
# 57 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 57 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 57 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 57 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 57 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
	step_end

# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_5:
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
	step_end

# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_6:
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_down
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_southeast
	step_end

PathToTapuKokoShrine_Woman_Text_0:
# 6 "data/maps/PathToTapuKokoShrine/scripts.pory"
	.string "Going to pay your respects to the\n"
	.string "guardian deity?\p"
	.string "It's a fickle one, but I hope you meet\n"
	.string "it!$"

PathToTapuKokoShrine_Meowth_Text_0:
# 19 "data/maps/PathToTapuKokoShrine/scripts.pory"
	.string "Hsss!$"

PathToTapuKokoShrine_Trigger_Lillie_Text_0:
# 44 "data/maps/PathToTapuKokoShrine/scripts.pory"
	.string "I know! I know.\n"
	.string "I'll take you to the ruins.\p"
	.string "So, please stay in the bag.\n"
	.string "We could get in trouble if anyone\l"
	.string "sees you.$"
