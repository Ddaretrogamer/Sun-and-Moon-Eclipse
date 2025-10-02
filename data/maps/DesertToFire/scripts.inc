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
# 51 "data/maps/DesertToFire/scripts.pory"
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
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 24 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 25 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_0
# 26 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 27 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_1
# 28 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 29 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_2
# 30 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 31 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_0, MSGBOX_AUTOCLOSE
# 32 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_3
# 33 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 34 "data/maps/DesertToFire/scripts.pory"
	special SpawnCameraObject
# 35 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_4
# 36 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 37 "data/maps/DesertToFire/scripts.pory"
	delay 30
# 38 "data/maps/DesertToFire/scripts.pory"
	speakername BlockVolcano_Text_1
# 39 "data/maps/DesertToFire/scripts.pory"
	createfieldmugshot MUGSHOT_VOLCARONA, EMOTE_NORMAL
# 40 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_2, MSGBOX_AUTOCLOSE
# 41 "data/maps/DesertToFire/scripts.pory"
	waitmessage
# 42 "data/maps/DesertToFire/scripts.pory"
	removefieldmugshot
# 43 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_5
# 44 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 45 "data/maps/DesertToFire/scripts.pory"
	special RemoveCameraObject
# 46 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_6
# 47 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 48 "data/maps/DesertToFire/scripts.pory"
	release
	end

BlockVolcano_6:
# 53 "data/maps/DesertToFire/scripts.pory"
	lock
# 54 "data/maps/DesertToFire/scripts.pory"
	delay 15
# 55 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8004, 2
# 56 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8005, 6
# 57 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8006, 4
# 58 "data/maps/DesertToFire/scripts.pory"
	setvar VAR_0x8007, 4
# 59 "data/maps/DesertToFire/scripts.pory"
	special ShakeCamera
# 60 "data/maps/DesertToFire/scripts.pory"
	waitstate
# 61 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 62 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 63 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_0
# 64 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 65 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_1
# 66 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 67 "data/maps/DesertToFire/scripts.pory"
	applymovement LOCALID_PLAYER, BlockVolcano_Movement_2
# 68 "data/maps/DesertToFire/scripts.pory"
	waitmovement LOCALID_PLAYER
# 69 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_0, MSGBOX_AUTOCLOSE
# 70 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_3
# 71 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 72 "data/maps/DesertToFire/scripts.pory"
	special SpawnCameraObject
# 73 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_4
# 74 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 75 "data/maps/DesertToFire/scripts.pory"
	delay 30
# 76 "data/maps/DesertToFire/scripts.pory"
	speakername BlockVolcano_Text_1
# 77 "data/maps/DesertToFire/scripts.pory"
	createfieldmugshot MUGSHOT_VOLCARONA, EMOTE_NORMAL
# 78 "data/maps/DesertToFire/scripts.pory"
	msgbox BlockVolcano_Text_3, MSGBOX_AUTOCLOSE
# 79 "data/maps/DesertToFire/scripts.pory"
	waitmessage
# 80 "data/maps/DesertToFire/scripts.pory"
	removefieldmugshot
# 81 "data/maps/DesertToFire/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, BlockVolcano_Movement_5
# 82 "data/maps/DesertToFire/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 83 "data/maps/DesertToFire/scripts.pory"
	special RemoveCameraObject
# 84 "data/maps/DesertToFire/scripts.pory"
	applymovement Volcarona, BlockVolcano_Movement_6
# 85 "data/maps/DesertToFire/scripts.pory"
	waitmovement Volcarona
# 86 "data/maps/DesertToFire/scripts.pory"
	release
	end


# 25 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_0:
# 25 "data/maps/DesertToFire/scripts.pory"
	face_up
	step_end

# 27 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_1:
# 27 "data/maps/DesertToFire/scripts.pory"
	lock_facing_direction
	step_end

# 29 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_2:
# 29 "data/maps/DesertToFire/scripts.pory"
	walk_down
	step_end

# 32 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_3:
# 32 "data/maps/DesertToFire/scripts.pory"
	face_left
	step_end

# 35 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_4:
# 35 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 35 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 35 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 35 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 35 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
# 35 "data/maps/DesertToFire/scripts.pory"
	walk_fast_right
	step_end

# 43 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_5:
# 43 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 43 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 43 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 43 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 43 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
# 43 "data/maps/DesertToFire/scripts.pory"
	walk_fast_left
	step_end

# 46 "data/maps/DesertToFire/scripts.pory"
BlockVolcano_Movement_6:
# 46 "data/maps/DesertToFire/scripts.pory"
	walk_in_place_down
	step_end

BlockVolcano_Text_0:
# 31 "data/maps/DesertToFire/scripts.pory"
	.string "Stop!\n$"

BlockVolcano_Text_1:
# 38 "data/maps/DesertToFire/scripts.pory"
	.string "Volcarona$"

BlockVolcano_Text_2:
# 40 "data/maps/DesertToFire/scripts.pory"
	.string "You are not the one who may pass.\pThe Boss likes a challenge,\nso he only lets Water_types into\lthe Volcano.\p...\pYou say you are a Water_type?\pI've never seen a Water_type glow\nlike you...\pNo matter.\nYou may not pass.$"

BlockVolcano_Text_3:
# 78 "data/maps/DesertToFire/scripts.pory"
	.string "You are not the one who may pass.\pThe Boss likes a challenge,\nso he only lets Water_types into\lthe Volcano.$"
