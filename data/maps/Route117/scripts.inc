Route117_MapScripts::
# 2 "data/maps/Route117/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route117_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route117_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 2 "data/maps/Route117/scripts.pory"
	map_script_2 VAR_SECRET_ENDING, 0, Route117_secretscript
	.2byte 0


Route117_secretscript::
# 6 "data/maps/Route117/scripts.pory"
	lock
# 7 "data/maps/Route117/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE117_POKEMON_DAY_CARE
# 8 "data/maps/Route117/scripts.pory"
	special SpawnCameraObject
# 9 "data/maps/Route117/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route117_secretscript_Movement_0
# 10 "data/maps/Route117/scripts.pory"
	applymovement SecretEndingBrenden, Route117_secretscript_Movement_0
# 11 "data/maps/Route117/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 12 "data/maps/Route117/scripts.pory"
	waitmovement SecretEndingBrenden
# 13 "data/maps/Route117/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route117_secretscript_Movement_1
# 14 "data/maps/Route117/scripts.pory"
	applymovement SecretEndingBrenden, Route117_secretscript_Movement_1
# 15 "data/maps/Route117/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 16 "data/maps/Route117/scripts.pory"
	waitmovement SecretEndingBrenden
# 17 "data/maps/Route117/scripts.pory"
	playse SE_PIN
# 18 "data/maps/Route117/scripts.pory"
	applymovement SecretEndingBrenden, Common_Movement_ExclamationMark
# 19 "data/maps/Route117/scripts.pory"
	waitmovement SecretEndingBrenden
# 20 "data/maps/Route117/scripts.pory"
	msgbox Route117_secretscript_Text_0
# 21 "data/maps/Route117/scripts.pory"
	special EggHatch
# 22 "data/maps/Route117/scripts.pory"
	waitstate
# 23 "data/maps/Route117/scripts.pory"
	playfanfare MUS_OBTAIN_TMHM
# 24 "data/maps/Route117/scripts.pory"
	msgbox Route117_secretscript_Text_1, MSGBOX_AUTOCLOSE
# 25 "data/maps/Route117/scripts.pory"
	msgbox Route117_secretscript_Text_2, MSGBOX_AUTOCLOSE
# 26 "data/maps/Route117/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 27 "data/maps/Route117/scripts.pory"
	delay 60
# 28 "data/maps/Route117/scripts.pory"
	special GameClear
	return


# 9 "data/maps/Route117/scripts.pory"
Route117_secretscript_Movement_0:
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
# 9 "data/maps/Route117/scripts.pory"
	walk_fast_right
	step_end

# 13 "data/maps/Route117/scripts.pory"
Route117_secretscript_Movement_1:
# 13 "data/maps/Route117/scripts.pory"
	walk_fast_left
# 13 "data/maps/Route117/scripts.pory"
	walk_fast_left
# 13 "data/maps/Route117/scripts.pory"
	walk_fast_left
# 13 "data/maps/Route117/scripts.pory"
	walk_fast_left
# 13 "data/maps/Route117/scripts.pory"
	walk_fast_left
	step_end

Route117_secretscript_Text_0:
# 20 "data/maps/Route117/scripts.pory"
	.string "Huh?$"

Route117_secretscript_Text_1:
# 24 "data/maps/Route117/scripts.pory"
	.string "You can now play as a shiny Ditto!$"

Route117_secretscript_Text_2:
# 25 "data/maps/Route117/scripts.pory"
	.string "Start a new save to play through\nthe game completely as a shiny!\pEnjoy the new shiny Ditto themed\nUI elements as well!$"
