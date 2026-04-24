PlayerRoom_MapScripts::
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 3 "data/maps/PlayerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 2 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_INTRO_PLAYED, 0, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 2 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
	return

PlayerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/PlayerRoom/scripts.pory"
	map_script_2 VAR_INTRO_PLAYED, 0, RoomIntroSequence
	.2byte 0


RoomIntroSequence::
# 7 "data/maps/PlayerRoom/scripts.pory"
	lock
# 8 "data/maps/PlayerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0
# 9 "data/maps/PlayerRoom/scripts.pory"
	delay 160
# 10 "data/maps/PlayerRoom/scripts.pory"
	waitmovement 0
# 11 "data/maps/PlayerRoom/scripts.pory"
	setvar VAR_INTRO_PLAYED, 1
# 12 "data/maps/PlayerRoom/scripts.pory"
	release
	end


# 2 "data/maps/PlayerRoom/scripts.pory"
PlayerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_Movement_0:
# 2 "data/maps/PlayerRoom/scripts.pory"
	face_up
	step_end
