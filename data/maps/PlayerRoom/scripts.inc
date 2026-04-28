PlayerRoom_MapScripts::
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 5 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 2 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
# 3 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 4 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 0, RoomIntroSequence
	.2byte 0


RoomIntroSequence::
# 9 "data/maps/PlayerRoom/scripts.pory"
	lock
# 10 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_0
# 11 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 12 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 13 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 14 "data/maps/PlayerRoom/scripts.pory"
	showobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 15 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 16 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_1
# 17 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 18 "data/maps/PlayerRoom/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 19 "data/maps/PlayerRoom/scripts.pory"
	msgbox RoomIntroSequence_Text_0, MSGBOX_AUTOCLOSE
# 20 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 21 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 22 "data/maps/PlayerRoom/scripts.pory"
	playse SE_PIN
# 23 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 24 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 25 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, RoomIntroSequence_Movement_2
# 26 "data/maps/PlayerRoom/scripts.pory"
	delay 60
# 27 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_3
# 28 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 29 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 30 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 31 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 32 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_4
# 33 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 34 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 1
# 35 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_CheckBox::
# 40 "data/maps/PlayerRoom/scripts.pory"
	lock
# 41 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerRoom_CheckBox_2
# 45 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_CheckBox_3
# 59 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_3
PlayerRoom_CheckBox_1:
# 62 "data/maps/PlayerRoom/scripts.pory"
	release
	end

PlayerRoom_CheckBox_2:
# 42 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_0
	goto PlayerRoom_CheckBox_1

PlayerRoom_CheckBox_3:
# 46 "data/maps/PlayerRoom/scripts.pory"
	setmetatile 15, 12, METATILE_PlayerHouse2_OpenBox, TRUE
# 47 "data/maps/PlayerRoom/scripts.pory"
	special DrawWholeMapView
# 48 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_1
# 49 "data/maps/PlayerRoom/scripts.pory"
	waitbuttonpress
# 50 "data/maps/PlayerRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 51 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_2, MSGBOX_AUTOCLOSE
# 52 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 53 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_LILLIE_INTRO_PLAYED
# 54 "data/maps/PlayerRoom/scripts.pory"
	clearflag FLAG_MOM_IN_HOUSE_INTRO
# 55 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 3
# 56 "data/maps/PlayerRoom/scripts.pory"
	removeobject PlayerRoomMeowth
	goto PlayerRoom_CheckBox_1


PlayerRoom_Trigger_TryingToLeaveWithoutShoes::
# 67 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2
	end

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2:
# 68 "data/maps/PlayerRoom/scripts.pory"
	lock
# 69 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0
# 71 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 72 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 73 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 2 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 2 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 10 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_0:
# 10 "data/maps/PlayerRoom/scripts.pory"
	walk_faster_up
	step_end

# 16 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_1:
# 16 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 16 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 16 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 16 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 16 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 25 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_2:
# 25 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

# 27 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_3:
# 27 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 27 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 27 "data/maps/PlayerRoom/scripts.pory"
	walk_down
# 27 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 32 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_4:
# 32 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 71 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 71 "data/maps/PlayerRoom/scripts.pory"
	walk_up
	step_end

RoomIntroSequence_Text_0:
# 19 "data/maps/PlayerRoom/scripts.pory"
	.string "Mwaaawwwrrrrrrrr!!!$"

PlayerRoom_CheckBox_Text_0:
# 42 "data/maps/PlayerRoom/scripts.pory"
	.string "A box of stuff brought from Kanto.\n"
	.string "You should probably unpack it.$"

PlayerRoom_CheckBox_Text_1:
# 48 "data/maps/PlayerRoom/scripts.pory"
	.string "You checked the box…$"

PlayerRoom_CheckBox_Text_2:
# 51 "data/maps/PlayerRoom/scripts.pory"
	.string "And grabbed your running shoes!$"

PlayerRoom_CheckBox_Text_3:
# 59 "data/maps/PlayerRoom/scripts.pory"
	.string "The box is empty.\n"
	.string "You unpacked it already.$"

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 69 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom said you should unpack the box\n"
	.string "in your room to find your shoes!$"
