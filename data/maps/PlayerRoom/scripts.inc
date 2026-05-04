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


PlayerRoom_Wii::
# 13 "data/maps/PlayerRoom/scripts.pory"
	lock
# 14 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Wii_Text_0
# 16 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_AdventureGuide::
# 21 "data/maps/PlayerRoom/scripts.pory"
	lock
# 22 "data/maps/PlayerRoom/scripts.pory"
	helpwindow HELP_ADVENTURE_GUIDE
# 23 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_SetBoxOpen::
# 28 "data/maps/PlayerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_PLAYER_ROOM_OPEN_BOX
	return


RoomIntroSequence::
# 33 "data/maps/PlayerRoom/scripts.pory"
	lock
# 34 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_0
# 35 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 36 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 37 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 38 "data/maps/PlayerRoom/scripts.pory"
	showobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 39 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 40 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_1
# 41 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 42 "data/maps/PlayerRoom/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 43 "data/maps/PlayerRoom/scripts.pory"
	msgbox RoomIntroSequence_Text_0, MSGBOX_AUTOCLOSE
# 44 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 45 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 46 "data/maps/PlayerRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 48 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 49 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, RoomIntroSequence_Movement_2
# 50 "data/maps/PlayerRoom/scripts.pory"
	delay 60
# 51 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_3
# 52 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 53 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 54 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 55 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 56 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_4
# 57 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 1
# 59 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_CheckBox::
# 64 "data/maps/PlayerRoom/scripts.pory"
	lock
# 65 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerRoom_CheckBox_2
# 69 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_CheckBox_3
# 83 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_3
PlayerRoom_CheckBox_1:
# 86 "data/maps/PlayerRoom/scripts.pory"
	release
	end

PlayerRoom_CheckBox_2:
# 66 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_0
	goto PlayerRoom_CheckBox_1

PlayerRoom_CheckBox_3:
# 70 "data/maps/PlayerRoom/scripts.pory"
	setmetatile 15, 12, METATILE_PlayerHouse2_OpenBox, TRUE
# 71 "data/maps/PlayerRoom/scripts.pory"
	special DrawWholeMapView
# 72 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_1
# 73 "data/maps/PlayerRoom/scripts.pory"
	waitbuttonpress
# 74 "data/maps/PlayerRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 75 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_2, MSGBOX_AUTOCLOSE
# 76 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 77 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_LILLIE_INTRO_PLAYED
# 78 "data/maps/PlayerRoom/scripts.pory"
	clearflag FLAG_MOM_IN_HOUSE_INTRO
# 79 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 3
# 80 "data/maps/PlayerRoom/scripts.pory"
	removeobject PlayerRoomMeowth
	goto PlayerRoom_CheckBox_1


PlayerRoom_Trigger_TryingToLeaveWithoutShoes::
# 91 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2
	end

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2:
# 92 "data/maps/PlayerRoom/scripts.pory"
	lock
# 93 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0
# 95 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 96 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 97 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 6 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 6 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 34 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_0:
# 34 "data/maps/PlayerRoom/scripts.pory"
	walk_faster_up
	step_end

# 40 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_1:
# 40 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 40 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 40 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 40 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 40 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 49 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_2:
# 49 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

# 51 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_3:
# 51 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 51 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 51 "data/maps/PlayerRoom/scripts.pory"
	walk_down
# 51 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 56 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_4:
# 56 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 95 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 95 "data/maps/PlayerRoom/scripts.pory"
	walk_up
	step_end

PlayerRoom_Wii_Text_0:
# 14 "data/maps/PlayerRoom/scripts.pory"
	.string "A Wii console…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}\n"
	.string "but now isn't the time for games!$"

RoomIntroSequence_Text_0:
# 43 "data/maps/PlayerRoom/scripts.pory"
	.string "Mwaaawwwrrrrrrrr!!!$"

PlayerRoom_CheckBox_Text_0:
# 66 "data/maps/PlayerRoom/scripts.pory"
	.string "A box of stuff brought from Kanto.\n"
	.string "You should probably unpack it.$"

PlayerRoom_CheckBox_Text_1:
# 72 "data/maps/PlayerRoom/scripts.pory"
	.string "You checked the box…$"

PlayerRoom_CheckBox_Text_2:
# 75 "data/maps/PlayerRoom/scripts.pory"
	.string "And grabbed your running shoes!$"

PlayerRoom_CheckBox_Text_3:
# 83 "data/maps/PlayerRoom/scripts.pory"
	.string "The box is empty.\n"
	.string "You unpacked it already.$"

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 93 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom said you should unpack the box\n"
	.string "in your room to find your shoes!$"
