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
	playse SE_PIN
# 29 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement LOCALID_PLAYER, PathToTapuKokoShrine_Trigger_Lillie_Movement_0
# 30 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 60
# 31 "data/maps/PathToTapuKokoShrine/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 32 "data/maps/PathToTapuKokoShrine/scripts.pory"
	compare VAR_TEMP_2, 19
	goto_if_eq PathToTapuKokoShrine_Trigger_Lillie_2
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_5
# 59 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
# 60 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 61 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_2
# 62 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 63 "data/maps/PathToTapuKokoShrine/scripts.pory"
	msgbox PathToTapuKokoShrine_Trigger_Lillie_Text_0, MSGBOX_AUTOCLOSE
# 69 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmessage
# 70 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_3
# 71 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 72 "data/maps/PathToTapuKokoShrine/scripts.pory"
	playse SE_EXIT
# 73 "data/maps/PathToTapuKokoShrine/scripts.pory"
	setflag FLAG_HIDE_PATHTORUINS_LILLIE
# 74 "data/maps/PathToTapuKokoShrine/scripts.pory"
	removeobject pathtoruinslillie
# 75 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitse
# 76 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 77 "data/maps/PathToTapuKokoShrine/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 78 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 60
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_6
# 80 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
# 81 "data/maps/PathToTapuKokoShrine/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
PathToTapuKokoShrine_Trigger_Lillie_1:
# 83 "data/maps/PathToTapuKokoShrine/scripts.pory"
	special RemoveCameraObject
# 84 "data/maps/PathToTapuKokoShrine/scripts.pory"
	setvar VAR_IKITOWN_STATE, 3
# 85 "data/maps/PathToTapuKokoShrine/scripts.pory"
	release
	end

PathToTapuKokoShrine_Trigger_Lillie_2:
# 33 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_1
# 34 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
# 35 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 36 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_2
# 37 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 38 "data/maps/PathToTapuKokoShrine/scripts.pory"
	msgbox PathToTapuKokoShrine_Trigger_Lillie_Text_0, MSGBOX_AUTOCLOSE
# 44 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmessage
# 45 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement pathtoruinslillie, PathToTapuKokoShrine_Trigger_Lillie_Movement_3
# 46 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement pathtoruinslillie
# 47 "data/maps/PathToTapuKokoShrine/scripts.pory"
	playse SE_EXIT
# 48 "data/maps/PathToTapuKokoShrine/scripts.pory"
	removeobject pathtoruinslillie
# 49 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitse
# 50 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 30
# 51 "data/maps/PathToTapuKokoShrine/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 52 "data/maps/PathToTapuKokoShrine/scripts.pory"
	delay 60
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, PathToTapuKokoShrine_Trigger_Lillie_Movement_4
# 54 "data/maps/PathToTapuKokoShrine/scripts.pory"
	waitmovement 0
# 55 "data/maps/PathToTapuKokoShrine/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto PathToTapuKokoShrine_Trigger_Lillie_1


# 29 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_0:
# 29 "data/maps/PathToTapuKokoShrine/scripts.pory"
	emote_question_mark
	step_end

# 33 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_1:
# 33 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 33 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 33 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 33 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 33 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
	step_end

# 36 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_2:
# 36 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_in_place_up
# 36 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_in_place_up
	step_end

# 45 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_3:
# 45 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 45 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 45 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 45 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
# 45 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
	step_end

# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_4:
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 53 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
	step_end

# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_5:
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_diag_northwest
# 58 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_up
	step_end

# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
PathToTapuKokoShrine_Trigger_Lillie_Movement_6:
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_right
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
# 79 "data/maps/PathToTapuKokoShrine/scripts.pory"
	walk_faster_down
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
# 38 "data/maps/PathToTapuKokoShrine/scripts.pory"
	.string "I know! I know.\n"
	.string "I'll take you to the ruins.\p"
	.string "So, please stay in the bag.\n"
	.string "We could get in trouble if anyone\l"
	.string "sees you.$"
