PlayerRoom_MapScripts::
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 6 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 11 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/PlayerRoom/scripts.pory"
	call_if_set FLAG_LILLIE_INTRO_PLAYED, PlayerRoom_SetBoxOpen
	end

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
# 10 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 9, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	.2byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 6 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
# 7 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 8 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 9 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_HIDE_PLAYER_MOM3
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
# 10 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 0, RoomIntroSequence
# 12 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 9, PlayerRoomDoorbell
	.2byte 0


PlayerRoom_Wii::
# 16 "data/maps/PlayerRoom/scripts.pory"
	lock
# 17 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Wii_Text_0
# 19 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_AdventureGuide::
# 24 "data/maps/PlayerRoom/scripts.pory"
	lock
# 25 "data/maps/PlayerRoom/scripts.pory"
	helpwindow HELP_ADVENTURE_GUIDE
# 26 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_SetBoxOpen::
# 31 "data/maps/PlayerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_PLAYER_ROOM_OPEN_BOX
	return


RoomIntroSequence::
# 36 "data/maps/PlayerRoom/scripts.pory"
	lock
# 37 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_0
# 38 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 39 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 40 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 41 "data/maps/PlayerRoom/scripts.pory"
	showobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 42 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 43 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_1
# 44 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 45 "data/maps/PlayerRoom/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 46 "data/maps/PlayerRoom/scripts.pory"
	msgbox RoomIntroSequence_Text_0, MSGBOX_AUTOCLOSE
# 47 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 48 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 49 "data/maps/PlayerRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 51 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 52 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, RoomIntroSequence_Movement_2
# 53 "data/maps/PlayerRoom/scripts.pory"
	delay 60
# 54 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_3
# 55 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 56 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 57 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 58 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 59 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_4
# 60 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 61 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 1
# 62 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_CheckBox::
# 67 "data/maps/PlayerRoom/scripts.pory"
	lock
# 68 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerRoom_CheckBox_2
# 72 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_CheckBox_3
# 87 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_3
PlayerRoom_CheckBox_1:
# 90 "data/maps/PlayerRoom/scripts.pory"
	release
	end

PlayerRoom_CheckBox_2:
# 69 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_0
	goto PlayerRoom_CheckBox_1

PlayerRoom_CheckBox_3:
# 73 "data/maps/PlayerRoom/scripts.pory"
	setmetatile 15, 12, METATILE_PlayerHouse2_OpenBox, TRUE
# 74 "data/maps/PlayerRoom/scripts.pory"
	special DrawWholeMapView
# 75 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_1
# 76 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 77 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 78 "data/maps/PlayerRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 79 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_2, MSGBOX_AUTOCLOSE
# 80 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 81 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_LILLIE_INTRO_PLAYED
# 82 "data/maps/PlayerRoom/scripts.pory"
	clearflag FLAG_MOM_IN_HOUSE_INTRO
# 83 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 3
# 84 "data/maps/PlayerRoom/scripts.pory"
	removeobject PlayerRoomMeowth
	goto PlayerRoom_CheckBox_1


PlayerRoom_Trigger_TryingToLeaveWithoutShoes::
# 95 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2
	end

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2:
# 96 "data/maps/PlayerRoom/scripts.pory"
	lock
# 97 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0
# 99 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 100 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 101 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoomDoorbell::
# 108 "data/maps/PlayerRoom/scripts.pory"
	lock
# 109 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DING_DONG
# 110 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoomDoorbell_Movement_0
# 111 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 112 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 113 "data/maps/PlayerRoom/scripts.pory"
	delay 150
# 114 "data/maps/PlayerRoom/scripts.pory"
	speakername PlayerRoomDoorbell_Text_0
# 115 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoomDoorbell_Text_1
# 117 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_IKITOWN_STATE, 10
# 118 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 119 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 6 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 6 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 37 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_0:
# 37 "data/maps/PlayerRoom/scripts.pory"
	walk_faster_up
	step_end

# 43 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_1:
# 43 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 43 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 43 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 43 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 43 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 52 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_2:
# 52 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

# 54 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_3:
# 54 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 54 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 54 "data/maps/PlayerRoom/scripts.pory"
	walk_down
# 54 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 59 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_4:
# 59 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 99 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 99 "data/maps/PlayerRoom/scripts.pory"
	walk_up
	step_end

# 110 "data/maps/PlayerRoom/scripts.pory"
PlayerRoomDoorbell_Movement_0:
# 110 "data/maps/PlayerRoom/scripts.pory"
	emote_exclamation_mark
# 110 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

PlayerRoom_Wii_Text_0:
# 17 "data/maps/PlayerRoom/scripts.pory"
	.string "A Wii console…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}\n"
	.string "but now isn't the time for games!$"

RoomIntroSequence_Text_0:
# 46 "data/maps/PlayerRoom/scripts.pory"
	.string "Mwaaawwwrrrrrrrr!!!$"

PlayerRoom_CheckBox_Text_0:
# 69 "data/maps/PlayerRoom/scripts.pory"
	.string "A box of stuff brought from Kanto.\n"
	.string "You should probably unpack it.$"

PlayerRoom_CheckBox_Text_1:
# 75 "data/maps/PlayerRoom/scripts.pory"
	.string "You checked the box…$"

PlayerRoom_CheckBox_Text_2:
# 79 "data/maps/PlayerRoom/scripts.pory"
	.string "And grabbed your running shoes!$"

PlayerRoom_CheckBox_Text_3:
# 87 "data/maps/PlayerRoom/scripts.pory"
	.string "The box is empty.\n"
	.string "You unpacked it already.$"

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 97 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom said you should unpack the box\n"
	.string "in your room to find your shoes!$"

PlayerRoomDoorbell_Text_0:
# 114 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom$"

PlayerRoomDoorbell_Text_1:
# 115 "data/maps/PlayerRoom/scripts.pory"
	.string "Was that the doorbell?\n"
	.string "Go see who it is, {PLAYER}.$"
