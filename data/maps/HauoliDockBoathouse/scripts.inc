HauoliDockBoathouse_MapScripts::
# 2 "data/maps/HauoliDockBoathouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HauoliDockBoathouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HauoliDockBoathouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 2 "data/maps/HauoliDockBoathouse/scripts.pory"
	map_script_2 VAR_WARP_TO_BOATHOUSE, 1, ReturnFromElevator
	.2byte 0


ReturnFromElevator::
# 6 "data/maps/HauoliDockBoathouse/scripts.pory"
	lock
# 7 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement LOCALID_PLAYER, ReturnFromElevator_Movement_0
# 8 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 9 "data/maps/HauoliDockBoathouse/scripts.pory"
	setvar VAR_WARP_TO_BOATHOUSE, 0
# 10 "data/maps/HauoliDockBoathouse/scripts.pory"
	release
	end


HauoliDockBoathouse_Trigger::
# 16 "data/maps/HauoliDockBoathouse/scripts.pory"
	lock
# 17 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement receptionist, Common_Movement_ExclamationMark
# 18 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement receptionist
# 19 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement receptionist, HauoliDockBoathouse_Trigger_Movement_0
# 20 "data/maps/HauoliDockBoathouse/scripts.pory"
	playse SE_PIN
# 21 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement receptionist
# 22 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliDockBoathouse_Trigger_Movement_1
# 23 "data/maps/HauoliDockBoathouse/scripts.pory"
	playse SE_LEDGE
# 24 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 25 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliDockBoathouse_Trigger_Movement_2
# 26 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 27 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliDockBoathouse_Trigger_Movement_3
# 28 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 29 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement receptionist
# 30 "data/maps/HauoliDockBoathouse/scripts.pory"
	msgbox HauoliDockBoathouse_Trigger_Text_0
# 37 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmessage
# 38 "data/maps/HauoliDockBoathouse/scripts.pory"
	release
	end


HauoliDockBoathouse_Receptionist::
# 43 "data/maps/HauoliDockBoathouse/scripts.pory"
	lockall
# 44 "data/maps/HauoliDockBoathouse/scripts.pory"
	faceplayer
# 45 "data/maps/HauoliDockBoathouse/scripts.pory"
	msgbox HauoliDockBoathouse_Receptionist_Text_0, MSGBOX_YESNO
# 49 "data/maps/HauoliDockBoathouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HauoliDockBoathouse_Receptionist_1
# 56 "data/maps/HauoliDockBoathouse/scripts.pory"
	releaseall
	end

HauoliDockBoathouse_Receptionist_1:
# 50 "data/maps/HauoliDockBoathouse/scripts.pory"
	warp MAP_AETHER_CONSERVATORY, 29, 32
# 51 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitstate
# 52 "data/maps/HauoliDockBoathouse/scripts.pory"
	releaseall
	end


# 7 "data/maps/HauoliDockBoathouse/scripts.pory"
ReturnFromElevator_Movement_0:
# 7 "data/maps/HauoliDockBoathouse/scripts.pory"
	walk_down
# 7 "data/maps/HauoliDockBoathouse/scripts.pory"
	walk_down
	step_end

# 19 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_0:
# 19 "data/maps/HauoliDockBoathouse/scripts.pory"
	face_player
	step_end

# 22 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_1:
# 22 "data/maps/HauoliDockBoathouse/scripts.pory"
	jump_in_place_up
	step_end

# 25 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_2:
# 25 "data/maps/HauoliDockBoathouse/scripts.pory"
	walk_down
	step_end

# 27 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_3:
# 27 "data/maps/HauoliDockBoathouse/scripts.pory"
	face_up
	step_end

HauoliDockBoathouse_Trigger_Text_0:
# 30 "data/maps/HauoliDockBoathouse/scripts.pory"
	.string "Hey!\p"
	.string "The ship is not ready to board.\p"
	.string "Please be patient while we finish our \n"
	.string "preparations.$"

HauoliDockBoathouse_Receptionist_Text_0:
# 45 "data/maps/HauoliDockBoathouse/scripts.pory"
	.string "Welcome to the Hau'oli Dock!\p"
	.string "Would you like to visit the Aether\n"
	.string "Conservatory?$"
