PlayerRoom_MapScripts::
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 4 "data/maps/PlayerRoom/scripts.pory"
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
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, RoomIntroSequence
	.2byte 0


RoomIntroSequence::
# 8 "data/maps/PlayerRoom/scripts.pory"
	lock
# 9 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 10 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 11 "data/maps/PlayerRoom/scripts.pory"
	showobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 12 "data/maps/PlayerRoom/scripts.pory"
	delay 30
# 13 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_0
# 14 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 15 "data/maps/PlayerRoom/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 16 "data/maps/PlayerRoom/scripts.pory"
	msgbox RoomIntroSequence_Text_0, MSGBOX_AUTOCLOSE
# 17 "data/maps/PlayerRoom/scripts.pory"
	waitmessage
# 18 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 19 "data/maps/PlayerRoom/scripts.pory"
	playse SE_PIN
# 20 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 21 "data/maps/PlayerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 22 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, RoomIntroSequence_Movement_1
# 23 "data/maps/PlayerRoom/scripts.pory"
	delay 60
# 24 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_2
# 25 "data/maps/PlayerRoom/scripts.pory"
	waitmovement PlayerRoomMeowth
# 26 "data/maps/PlayerRoom/scripts.pory"
	playse SE_DOOR
# 27 "data/maps/PlayerRoom/scripts.pory"
	hideobjectat PlayerRoomMeowth, MAP_PLAYER_ROOM
# 28 "data/maps/PlayerRoom/scripts.pory"
	waitse
# 29 "data/maps/PlayerRoom/scripts.pory"
	applymovement PlayerRoomMeowth, RoomIntroSequence_Movement_3
# 30 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 31 "data/maps/PlayerRoom/scripts.pory"
	setflag FLAG_LILLIE_INTRO_PLAYED
# 32 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 2 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 2 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 13 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_0:
# 13 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 13 "data/maps/PlayerRoom/scripts.pory"
	walk_up
# 13 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 13 "data/maps/PlayerRoom/scripts.pory"
	walk_right
# 13 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end

# 22 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_1:
# 22 "data/maps/PlayerRoom/scripts.pory"
	face_down
	step_end

# 24 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_2:
# 24 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 24 "data/maps/PlayerRoom/scripts.pory"
	walk_left
# 24 "data/maps/PlayerRoom/scripts.pory"
	walk_down
# 24 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

# 29 "data/maps/PlayerRoom/scripts.pory"
RoomIntroSequence_Movement_3:
# 29 "data/maps/PlayerRoom/scripts.pory"
	walk_down
	step_end

RoomIntroSequence_Text_0:
# 16 "data/maps/PlayerRoom/scripts.pory"
	.string "Mwaaawwwrrrrrrrr!!!$"
