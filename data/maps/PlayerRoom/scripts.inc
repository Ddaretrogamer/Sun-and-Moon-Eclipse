PlayerRoom_MapScripts::
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PlayerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 6 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 12 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/PlayerRoom/scripts.pory"
	call_if_set FLAG_LILLIE_INTRO_PLAYED, PlayerRoom_SetBoxOpen
	end

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
# 11 "data/maps/PlayerRoom/scripts.pory"
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
# 10 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_HIDE_PLAYERHOUSE_STARTER
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
# 11 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_MOM_IN_HOUSE_INTRO, 0, RoomIntroSequence
# 13 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 9, PlayerRoomDoorbell
	.2byte 0


PlayerRoom_Wii::
# 17 "data/maps/PlayerRoom/scripts.pory"
	lock
# 18 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Wii_Text_0
# 20 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_AdventureGuide::
# 25 "data/maps/PlayerRoom/scripts.pory"
	lock
# 26 "data/maps/PlayerRoom/scripts.pory"
	helpwindow HELP_ADVENTURE_GUIDE
# 27 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_SetBoxOpen::
# 32 "data/maps/PlayerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_PLAYER_ROOM_OPEN_BOX
	return


RoomIntroSequence::
# 37 "data/maps/PlayerRoom/scripts.pory"
	lock
# 38 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_0
# 39 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 41 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 42 "data/maps/PlayerRoom/scripts.pory"
	showobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 43 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 44 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_1
# 45 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 46 "data/maps/PlayerRoom/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 47 "data/maps/PlayerRoom/scripts.pory"
	msgbox RoomIntroSequence_Text_0, MSGBOX_AUTOCLOSE
# 48 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 49 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 50 "data/maps/PlayerRoom/scripts.pory"
	playse SE_PIN
# 51 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 52 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 53 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, RoomIntroSequence_Movement_2
# 54 "data/maps/PlayerRoom/scripts.pory"
	delay 60
# 55 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_3
# 56 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 57 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 58 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 59 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 60 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_4
# 61 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 62 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 1
# 63 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_CheckBox::
# 68 "data/maps/PlayerRoom/scripts.pory"
	lock
# 69 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerRoom_CheckBox_2
# 73 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_CheckBox_3
# 88 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_3
PlayerRoom_CheckBox_1:
# 91 "data/maps/PlayerRoom/scripts.pory"
	release
	end

PlayerRoom_CheckBox_2:
# 70 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_0
	goto PlayerRoom_CheckBox_1

PlayerRoom_CheckBox_3:
# 74 "data/maps/PlayerRoom/scripts.pory"
	setmetatile 15, 12, METATILE_PlayerHouse2_OpenBox, TRUE
# 75 "data/maps/PlayerRoom/scripts.pory"
	special DrawWholeMapView
# 76 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_1
# 77 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 78 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 79 "data/maps/PlayerRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 80 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_2, MSGBOX_AUTOCLOSE
# 81 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 82 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_LILLIE_INTRO_PLAYED
# 83 "data/maps/PlayerRoom/scripts.pory"
	clearflag FLAG_MOM_IN_HOUSE_INTRO
# 84 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 3
# 85 "data/maps/PlayerRoom/scripts.pory"
	removeobject PlayerRoomMeowth
	goto PlayerRoom_CheckBox_1


PlayerRoom_Trigger_TryingToLeaveWithoutShoes::
# 96 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2
	end

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2:
# 97 "data/maps/PlayerRoom/scripts.pory"
	lock
# 98 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0
# 100 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 101 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 102 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoomDoorbell::
# 109 "data/maps/PlayerRoom/scripts.pory"
	lock
# 110 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DING_DONG
# 111 "data/maps/PlayerRoom/scripts.pory"
	playbgm MUS_USUM_IKITOWN_DAY, FALSE
# 112 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoomDoorbell_Movement_0
# 113 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 114 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 115 "data/maps/PlayerRoom/scripts.pory"
	delay 90
# 116 "data/maps/PlayerRoom/scripts.pory"
	speakername PlayerRoomDoorbell_Text_0
# 117 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoomDoorbell_Text_1
# 119 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_IKITOWN_STATE, 10
# 120 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 121 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 6 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 6 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 38 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_0:
# 38 "data/maps/PlayerRoom/scripts.pory"
	walk_faster_up
	step_end

# 44 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_1:
# 44 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 44 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 44 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 44 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 44 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 53 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_2:
# 53 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

# 55 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_3:
# 55 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 55 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 55 "data/maps/PlayerRoom/scripts.pory"
	walk_down
# 55 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 60 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_4:
# 60 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 100 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 100 "data/maps/PlayerRoom/scripts.pory"
	walk_up
	step_end

# 112 "data/maps/PlayerRoom/scripts.pory"
PlayerRoomDoorbell_Movement_0:
# 112 "data/maps/PlayerRoom/scripts.pory"
	emote_exclamation_mark
# 112 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

PlayerRoom_Wii_Text_0:
# 18 "data/maps/PlayerRoom/scripts.pory"
	.string "A Wii console…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}\n"
	.string "but now isn't the time for games!$"

RoomIntroSequence_Text_0:
# 47 "data/maps/PlayerRoom/scripts.pory"
	.string "Mwaaawwwrrrrrrrr!!!$"

PlayerRoom_CheckBox_Text_0:
# 70 "data/maps/PlayerRoom/scripts.pory"
	.string "A box of stuff brought from Kanto.\n"
	.string "You should probably unpack it.$"

PlayerRoom_CheckBox_Text_1:
# 76 "data/maps/PlayerRoom/scripts.pory"
	.string "You checked the box…$"

PlayerRoom_CheckBox_Text_2:
# 80 "data/maps/PlayerRoom/scripts.pory"
	.string "And grabbed your running shoes!$"

PlayerRoom_CheckBox_Text_3:
# 88 "data/maps/PlayerRoom/scripts.pory"
	.string "The box is empty.\n"
	.string "You unpacked it already.$"

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 98 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom said you should unpack the box\n"
	.string "in your room to find your shoes!$"

PlayerRoomDoorbell_Text_0:
# 116 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom$"

PlayerRoomDoorbell_Text_1:
# 117 "data/maps/PlayerRoom/scripts.pory"
	.string "Was that the doorbell?\n"
	.string "Go see who it is, {PLAYER}.$"
