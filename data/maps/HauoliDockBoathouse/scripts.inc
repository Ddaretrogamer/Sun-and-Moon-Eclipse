HauoliDockBoathouse_MapScripts::
	.byte 0


HauoliDockBoathouse_Trigger::
# 4 "data/maps/HauoliDockBoathouse/scripts.pory"
	lock
# 5 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement receptionist, Common_Movement_ExclamationMark
# 6 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement receptionist
# 7 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement receptionist, HauoliDockBoathouse_Trigger_Movement_0
# 8 "data/maps/HauoliDockBoathouse/scripts.pory"
	playse SE_PIN
# 9 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement receptionist
# 10 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliDockBoathouse_Trigger_Movement_1
# 11 "data/maps/HauoliDockBoathouse/scripts.pory"
	playse SE_LEDGE
# 12 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 13 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliDockBoathouse_Trigger_Movement_2
# 14 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 15 "data/maps/HauoliDockBoathouse/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliDockBoathouse_Trigger_Movement_3
# 16 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 17 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmovement receptionist
# 18 "data/maps/HauoliDockBoathouse/scripts.pory"
	msgbox HauoliDockBoathouse_Trigger_Text_0
# 25 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmessage
# 26 "data/maps/HauoliDockBoathouse/scripts.pory"
	release
	end


HauoliDockBoathouse_Receptionist::
# 31 "data/maps/HauoliDockBoathouse/scripts.pory"
	lock
# 32 "data/maps/HauoliDockBoathouse/scripts.pory"
	faceplayer
# 33 "data/maps/HauoliDockBoathouse/scripts.pory"
	msgbox HauoliDockBoathouse_Receptionist_Text_0, MSGBOX_YESNO
# 37 "data/maps/HauoliDockBoathouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq HauoliDockBoathouse_Receptionist_1
# 44 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmessage
# 45 "data/maps/HauoliDockBoathouse/scripts.pory"
	releaseall
	end

HauoliDockBoathouse_Receptionist_1:
# 38 "data/maps/HauoliDockBoathouse/scripts.pory"
	warp MAP_AETHER_CONSERVATORY, 29, 32
# 39 "data/maps/HauoliDockBoathouse/scripts.pory"
	waitmessage
# 40 "data/maps/HauoliDockBoathouse/scripts.pory"
	release
	end


# 7 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_0:
# 7 "data/maps/HauoliDockBoathouse/scripts.pory"
	face_player
	step_end

# 10 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_1:
# 10 "data/maps/HauoliDockBoathouse/scripts.pory"
	jump_in_place_up
	step_end

# 13 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_2:
# 13 "data/maps/HauoliDockBoathouse/scripts.pory"
	walk_down
	step_end

# 15 "data/maps/HauoliDockBoathouse/scripts.pory"
HauoliDockBoathouse_Trigger_Movement_3:
# 15 "data/maps/HauoliDockBoathouse/scripts.pory"
	face_up
	step_end

HauoliDockBoathouse_Trigger_Text_0:
# 18 "data/maps/HauoliDockBoathouse/scripts.pory"
	.string "Hey!\p"
	.string "The ship is not ready to board.\p"
	.string "Please be patient while we finish our \n"
	.string "preparations.$"

HauoliDockBoathouse_Receptionist_Text_0:
# 33 "data/maps/HauoliDockBoathouse/scripts.pory"
	.string "Welcome to the Hau'oli Dock!\p"
	.string "Would you like to visit the Aether\n"
	.string "Conservatory?$"
