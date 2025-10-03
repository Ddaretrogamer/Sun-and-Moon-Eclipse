DesertToFire_MapScripts::
# 2 "data/maps/DesertToFire/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareDesertToFire_OnTransition
	.byte 0


DaycareDesertToFire_OnTransition::
# 6 "data/maps/DesertToFire/scripts.pory"
	clearflag FLAG_DISABLE_XFORM_MENU
	end


BlockVolcano::
# 11 "data/maps/DesertToFire/scripts.pory"
	goto_if_unset FLAG_TRANS_ARCANINE, BlockVolcano_1
	return

BlockVolcano_1:
# 13 "data/maps/DesertToFire/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CHINCHOU
	goto_if_eq BlockVolcano_4
# 59 "data/maps/DesertToFire/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_MARILL
	goto_if_ne BlockVolcano_6
	return

BlockVolcano_4:
# 15 "data/maps/DesertToFire/scripts.pory"
	lock
# 16 "data/maps/DesertToFire/scripts.pory"
	delay 15
# 17 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8004, 2
# 18 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8005, 6
# 19 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8006, 4
# 20 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8007, 4
# 21 "data/maps/DesertToFire/scripts.pory"
	special ShakeCamera
# 22 "data/maps/DesertToFire/scripts.pory"
	waitstate
# 23 "data/maps/DesertToFire/scripts.pory"
	playse SE_PIN
# 24 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 25 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 26 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_0
# 27 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 28 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_1
# 29 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 30 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_2
# 31 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 32 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_0, MSGBOX_AUTOCLOSE
# 33 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_3
# 34 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 35 "data/maps/DesertToFire/scripts.pory"
	special SpawnCameraObject
# 36 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_4
# 37 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 38 "data/maps/DesertToFire/scripts.pory"
	delay 30
# 39 "data/maps/DesertToFire/scripts.pory"
	speakername BlockVolcano_Text_1
# 40 "data/maps/DesertToFire/scripts.pory"
	createfieldmugshot MUGSHOT_VOLCARONA, EMOTE_NORMAL
# 41 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_2, MSGBOX_AUTOCLOSE
# 42 "data/maps/DesertToFire/scripts.pory"
	playse SE_PIN
# 43 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, Common_Movement_ExclamationMark
# 44 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 45 "data/maps/DesertToFire/scripts.pory"
	delay 30
# 46 "data/maps/DesertToFire/scripts.pory"
	speakername BlockVolcano_Text_1
# 47 "data/maps/DesertToFire/scripts.pory"
	createfieldmugshot MUGSHOT_VOLCARONA, EMOTE_NORMAL
# 48 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_3, MSGBOX_AUTOCLOSE
# 49 "data/maps/DesertToFire/scripts.pory"
	waitmessage
# 50 "data/maps/DesertToFire/scripts.pory"
	removefieldmugshot
# 51 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_5
# 52 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 53 "data/maps/DesertToFire/scripts.pory"
	special RemoveCameraObject
# 54 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_6
# 55 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 56 "data/maps/DesertToFire/scripts.pory"
	release
	end

BlockVolcano_6:
# 61 "data/maps/DesertToFire/scripts.pory"
	lock
# 62 "data/maps/DesertToFire/scripts.pory"
	delay 15
# 63 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8004, 2
# 64 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8005, 6
# 65 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8006, 4
# 66 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8007, 4
# 67 "data/maps/DesertToFire/scripts.pory"
	special ShakeCamera
# 68 "data/maps/DesertToFire/scripts.pory"
	waitstate
# 69 "data/maps/DesertToFire/scripts.pory"
	playse SE_PIN
# 70 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 71 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 72 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_0
# 73 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 74 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_1
# 75 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 76 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_2
# 77 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 78 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_0, MSGBOX_AUTOCLOSE
# 79 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_3
# 80 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 81 "data/maps/DesertToFire/scripts.pory"
	special SpawnCameraObject
# 82 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_4
# 83 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 84 "data/maps/DesertToFire/scripts.pory"
	delay 30
# 85 "data/maps/DesertToFire/scripts.pory"
	speakername BlockVolcano_Text_1
# 86 "data/maps/DesertToFire/scripts.pory"
	createfieldmugshot MUGSHOT_VOLCARONA, EMOTE_NORMAL
# 87 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_2, MSGBOX_AUTOCLOSE
# 88 "data/maps/DesertToFire/scripts.pory"
	waitmessage
# 89 "data/maps/DesertToFire/scripts.pory"
	removefieldmugshot
# 90 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_5
# 91 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 92 "data/maps/DesertToFire/scripts.pory"
	special RemoveCameraObject
# 93 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_6
# 94 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 95 "data/maps/DesertToFire/scripts.pory"
	release
	end


# 26 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_0:
# 26 "data/maps/DesertToFire/scripts.pory"
	face_up
	step_end

# 28 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_1:
# 28 "data/maps/DesertToFire/scripts.pory"
	lock_facing_direction
	step_end

# 30 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_2:
# 30 "data/maps/DesertToFire/scripts.pory"
	walk_down
	step_end

# 33 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_3:
# 33 "data/maps/DesertToFire/scripts.pory"
	face_left
	step_end

# 36 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_4:
# 36 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 36 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 36 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 36 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 36 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 36 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
	step_end

# 51 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_5:
# 51 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 51 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 51 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 51 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 51 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 51 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
	step_end

# 54 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_6:
# 54 "data/maps/DesertToFire/scripts.pory"
	walk_in_place_down
	step_end

BlockVolcano_Text_0:
# 32 "data/maps/DesertToFire/scripts.pory"
	.string "Stop!\n$"

BlockVolcano_Text_1:
# 39 "data/maps/DesertToFire/scripts.pory"
	.string "Volcarona$"

BlockVolcano_Text_2:
# 41 "data/maps/DesertToFire/scripts.pory"
	.string "You are not the one who may pass.\pThe Boss likes a challenge,\nso he only lets Water_types into\lthe Volcano.$"

BlockVolcano_Text_3:
# 48 "data/maps/DesertToFire/scripts.pory"
	.string "...\pYou say you are a Water_type?\pI've never seen a Water_type glow\nlike you...\pNo matter.\nYou may not pass.$"
