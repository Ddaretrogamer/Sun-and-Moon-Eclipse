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
# 14 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 16, PlayerRoomDoorbell2
	.2byte 0


PlayerRoom_Wii::
# 18 "data/maps/PlayerRoom/scripts.pory"
	lock
# 19 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Wii_Text_0
# 21 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_AdventureGuide::
# 26 "data/maps/PlayerRoom/scripts.pory"
	lock
# 27 "data/maps/PlayerRoom/scripts.pory"
	helpwindow HELP_ADVENTURE_GUIDE
# 28 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_SetBoxOpen::
# 33 "data/maps/PlayerRoom/scripts.pory"
	setmaplayoutindex LAYOUT_PLAYER_ROOM_OPEN_BOX
	return


RoomIntroSequence::
# 38 "data/maps/PlayerRoom/scripts.pory"
	lock
# 39 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_0
# 40 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 41 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 42 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 43 "data/maps/PlayerRoom/scripts.pory"
	showobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 44 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 45 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_1
# 46 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 47 "data/maps/PlayerRoom/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 48 "data/maps/PlayerRoom/scripts.pory"
	msgbox RoomIntroSequence_Text_0, MSGBOX_AUTOCLOSE
# 49 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 50 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 51 "data/maps/PlayerRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 53 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 54 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, RoomIntroSequence_Movement_2
# 55 "data/maps/PlayerRoom/scripts.pory"
	delay 60
# 56 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_3
# 57 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 58 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 59 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 60 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 61 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_4
# 62 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 63 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 1
# 64 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoom_CheckBox::
# 69 "data/maps/PlayerRoom/scripts.pory"
	lock
# 70 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 1
	goto_if_eq PlayerRoom_CheckBox_2
# 74 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_CheckBox_3
# 89 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_3
PlayerRoom_CheckBox_1:
# 92 "data/maps/PlayerRoom/scripts.pory"
	release
	end

PlayerRoom_CheckBox_2:
# 71 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_0
	goto PlayerRoom_CheckBox_1

PlayerRoom_CheckBox_3:
# 75 "data/maps/PlayerRoom/scripts.pory"
	setmetatile 15, 12, METATILE_PlayerHouse2_OpenBox, TRUE
# 76 "data/maps/PlayerRoom/scripts.pory"
	special DrawWholeMapView
# 77 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_1
# 78 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 79 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 80 "data/maps/PlayerRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 81 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_CheckBox_Text_2, MSGBOX_AUTOCLOSE
# 82 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 83 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_LILLIE_INTRO_PLAYED
# 84 "data/maps/PlayerRoom/scripts.pory"
	clearflag FLAG_MOM_IN_HOUSE_INTRO
# 85 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_MOM_IN_HOUSE_INTRO, 3
# 86 "data/maps/PlayerRoom/scripts.pory"
	removeobject PlayerRoomMeowth
	goto PlayerRoom_CheckBox_1


PlayerRoom_Trigger_TryingToLeaveWithoutShoes::
# 97 "data/maps/PlayerRoom/scripts.pory"
	compare VAR_MOM_IN_HOUSE_INTRO, 2
	goto_if_eq PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2
	end

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_2:
# 98 "data/maps/PlayerRoom/scripts.pory"
	lock
# 99 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0
# 101 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0
# 102 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 103 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoomDoorbell::
# 110 "data/maps/PlayerRoom/scripts.pory"
	lock
# 111 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DING_DONG
# 112 "data/maps/PlayerRoom/scripts.pory"
	playbgm MUS_USUM_IKITOWN_DAY, FALSE
# 113 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoomDoorbell_Movement_0
# 114 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 115 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 116 "data/maps/PlayerRoom/scripts.pory"
	delay 90
# 117 "data/maps/PlayerRoom/scripts.pory"
	speakername PlayerRoomDoorbell_Text_0
# 118 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoomDoorbell_Text_1
# 120 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_IKITOWN_STATE, 10
# 121 "data/maps/PlayerRoom/scripts.pory"
	clearflag FLAG_KUKUI_CATCHING_TUTORIAL1
# 122 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 123 "data/maps/PlayerRoom/scripts.pory"
	release
	end


PlayerRoomDoorbell2::
# 127 "data/maps/PlayerRoom/scripts.pory"
	lock
# 128 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DING_DONG
# 129 "data/maps/PlayerRoom/scripts.pory"
	playbgm MUS_USUM_IKITOWN_DAY, FALSE
# 130 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoomDoorbell_Movement_0
# 131 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 132 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 133 "data/maps/PlayerRoom/scripts.pory"
	delay 90
# 134 "data/maps/PlayerRoom/scripts.pory"
	speakername PlayerRoomDoorbell_Text_0
# 135 "data/maps/PlayerRoom/scripts.pory"
	msgbox PlayerRoomDoorbell2_Text_0
# 140 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_IKITOWN_STATE, 17
# 141 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 142 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 6 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 6 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 39 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_0:
# 39 "data/maps/PlayerRoom/scripts.pory"
	walk_faster_up
	step_end

# 45 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_1:
# 45 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 45 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 45 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 45 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 45 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 54 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_2:
# 54 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

# 56 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_3:
# 56 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 56 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 56 "data/maps/PlayerRoom/scripts.pory"
	walk_down
# 56 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 61 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_4:
# 61 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 101 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Movement_0:
# 101 "data/maps/PlayerRoom/scripts.pory"
	walk_up
	step_end

# 113 "data/maps/PlayerRoom/scripts.pory"
PlayerRoomDoorbell_Movement_0:
# 113 "data/maps/PlayerRoom/scripts.pory"
	emote_exclamation_mark
# 113 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

PlayerRoom_Wii_Text_0:
# 19 "data/maps/PlayerRoom/scripts.pory"
	.string "A Wii console…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}\n"
	.string "but now isn't the time for games!$"

RoomIntroSequence_Text_0:
# 48 "data/maps/PlayerRoom/scripts.pory"
	.string "Mwaaawwwrrrrrrrr!!!$"

PlayerRoom_CheckBox_Text_0:
# 71 "data/maps/PlayerRoom/scripts.pory"
	.string "A box of stuff brought from Kanto.\n"
	.string "You should probably unpack it.$"

PlayerRoom_CheckBox_Text_1:
# 77 "data/maps/PlayerRoom/scripts.pory"
	.string "You checked the box…$"

PlayerRoom_CheckBox_Text_2:
# 81 "data/maps/PlayerRoom/scripts.pory"
	.string "And grabbed your running shoes!$"

PlayerRoom_CheckBox_Text_3:
# 89 "data/maps/PlayerRoom/scripts.pory"
	.string "The box is empty.\n"
	.string "You unpacked it already.$"

PlayerRoom_Trigger_TryingToLeaveWithoutShoes_Text_0:
# 99 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom said you should unpack the box\n"
	.string "in your room to find your shoes!$"

PlayerRoomDoorbell_Text_0:
# 117 "data/maps/PlayerRoom/scripts.pory"
	.string "Mom$"

PlayerRoomDoorbell_Text_1:
# 118 "data/maps/PlayerRoom/scripts.pory"
	.string "Was that the doorbell?\n"
	.string "Go see who it is, {PLAYER}.$"

PlayerRoomDoorbell2_Text_0:
# 135 "data/maps/PlayerRoom/scripts.pory"
	.string "A visitor!\p"
	.string "If it was Kukui, he'd probably let\n"
	.string "himself in without even waiting for\l"
	.string "us to open the door!$"
