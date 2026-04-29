PlayerRoom_MapScripts::
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 6 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 9 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/PlayerRoom/scripts.pory"
	call_if_set FLAG_LILLIE_INTRO_PLAYED, PlayerRoom_SetBoxOpen
	end

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 6 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
# 7 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 8 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 0, RoomIntroSequence
	.2byte 0


PlayerRoom_SetBoxOpen::
# 13 "data/maps/PlayerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_PLAYER_ROOM_OPEN_BOX
	return


RoomIntroSequence::
# 18 "data/maps/PlayerRoom/scripts.pory"
	lock
# 19 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_0
# 20 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 21 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 22 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 23 "data/maps/PlayerRoom/scripts.pory"
	showobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 24 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 25 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_1
# 26 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 27 "data/maps/PlayerRoom/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 28 "data/maps/PlayerRoom/scripts.pory"
	msgbox RoomIntroSequence_Text_0, MSGBOX_AUTOCLOSE
# 29 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 30 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 31 "data/maps/PlayerRoom/scripts.pory"
	playse SE_PIN
# 32 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 33 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 34 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, RoomIntroSequence_Movement_2
# 35 "data/maps/PlayerRoom/scripts.pory"
	delay 60
# 36 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_3
# 37 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 38 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 39 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 40 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 41 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_4
# 42 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 43 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 1
# 44 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_CheckBox::
# 49 "data/maps/PlayerRoom/scripts.pory"
	lock
# 50 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerRoom_CheckBox_2
# 54 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_CheckBox_3
# 68 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_3
PlayerRoom_CheckBox_1:
# 71 "data/maps/PlayerRoom/scripts.pory"
	release
	end

PlayerRoom_CheckBox_2:
# 51 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_0
	goto PlayerRoom_CheckBox_1

PlayerRoom_CheckBox_3:
# 55 "data/maps/PlayerRoom/scripts.pory"
	setmetatile 15, 12, METATILE_PlayerHouse2_OpenBox, TRUE
# 56 "data/maps/PlayerRoom/scripts.pory"
	special DrawWholeMapView
# 57 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_1
# 58 "data/maps/PlayerRoom/scripts.pory"
	waitbuttonpress
# 59 "data/maps/PlayerRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 60 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_2, MSGBOX_AUTOCLOSE
# 61 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 62 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_LILLIE_INTRO_PLAYED
# 63 "data/maps/PlayerRoom/scripts.pory"
	clearflag FLAG_MOM_IN_HOUSE_INTRO
# 64 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 3
# 65 "data/maps/PlayerRoom/scripts.pory"
	removeobject PlayerRoomMeowth
	goto PlayerRoom_CheckBox_1


PlayerRoom_Trigger_TryingToLeaveWithoutShoes::
# 76 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2
	end

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2:
# 77 "data/maps/PlayerRoom/scripts.pory"
	lock
# 78 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0
# 80 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 81 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 82 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 6 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 6 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 19 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_0:
# 19 "data/maps/PlayerRoom/scripts.pory"
	walk_faster_up
	step_end

# 25 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_1:
# 25 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 25 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 25 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 25 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 25 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 34 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_2:
# 34 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

# 36 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_3:
# 36 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 36 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 36 "data/maps/PlayerRoom/scripts.pory"
	walk_down
# 36 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 41 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_4:
# 41 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 80 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 80 "data/maps/PlayerRoom/scripts.pory"
	walk_up
	step_end

RoomIntroSequence_Text_0:
# 28 "data/maps/PlayerRoom/scripts.pory"
	.string "Mwaaawwwrrrrrrrr!!!$"

PlayerRoom_CheckBox_Text_0:
# 51 "data/maps/PlayerRoom/scripts.pory"
	.string "A box of stuff brought from Kanto.\n"
	.string "You should probably unpack it.$"

PlayerRoom_CheckBox_Text_1:
# 57 "data/maps/PlayerRoom/scripts.pory"
	.string "You checked the box…$"

PlayerRoom_CheckBox_Text_2:
# 60 "data/maps/PlayerRoom/scripts.pory"
	.string "And grabbed your running shoes!$"

PlayerRoom_CheckBox_Text_3:
# 68 "data/maps/PlayerRoom/scripts.pory"
	.string "The box is empty.\n"
	.string "You unpacked it already.$"

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 78 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom said you should unpack the box\n"
	.string "in your room to find your shoes!$"
