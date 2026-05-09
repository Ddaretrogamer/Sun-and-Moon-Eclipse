TapuKokoBridge_MapScripts::
# 2 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 10 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 15 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/TapuKokoBridge/scripts.pory"
	goto_if_set FLAG_SHINY_COSMOG, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 7 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( COSMOG )
	return

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 4 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( COSMOG )
	return

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 10 "data/maps/TapuKokoBridge/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 3, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 11 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 12 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 13 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgelillie, 21, 30
	return

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/TapuKokoBridge/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 3, TapuKokoBridge_LillieCosmogEvent
	.2byte 0


TapuKokoBridge_LillieCosmogEvent::
# 19 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 20 "data/maps/TapuKokoBridge/scripts.pory"
	special SpawnCameraObject
# 21 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_0
# 22 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 23 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 24 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 25 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 26 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 27 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 28 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 29 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 30 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 31 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 32 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 33 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 34 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 35 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 36 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 37 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 38 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 39 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 40 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 41 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 42 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 43 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 44 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_4
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_5
# 47 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 48 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 51 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 52 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 53 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 54 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 58 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 59 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 60 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 61 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_6
# 63 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 64 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 65 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull1, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 68 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 69 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull3, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 75 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull1
# 76 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull3
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 79 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_HIDE_CIRCLING_WINGULLS
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull4, MAP_TAPU_KOKO_BRIDGE
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull5, MAP_TAPU_KOKO_BRIDGE
# 82 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull6, MAP_TAPU_KOKO_BRIDGE
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_9
# 84 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 85 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 87 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 4
# 88 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 89 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 91 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 95 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 96 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 97 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_0
# 98 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_1, TapuKokoBridge_LillieCosmogEvent_Text_2
# 99 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_2
TapuKokoBridge_LillieCosmogEvent_1:
# 105 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_5
TapuKokoBridge_LillieCosmogEvent_4:
# 111 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 112 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 113 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_13
# 115 "data/maps/TapuKokoBridge/scripts.pory"
	delay 240
# 116 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 117 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_4, MSGBOX_AUTOCLOSE
# 119 "data/maps/TapuKokoBridge/scripts.pory"
	delay 120
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_15
# 121 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 122 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 123 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_5, MSGBOX_AUTOCLOSE
# 129 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 130 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_17
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_6, MSGBOX_AUTOCLOSE
# 137 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 138 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 139 "data/maps/TapuKokoBridge/scripts.pory"
	special HealPlayerParty
# 140 "data/maps/TapuKokoBridge/scripts.pory"
	playfanfare MUS_HEAL
# 141 "data/maps/TapuKokoBridge/scripts.pory"
	waitfanfare
# 142 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 143 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 144 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 145 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 146 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_LillieCosmogEvent_2:
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_1

TapuKokoBridge_LillieCosmogEvent_5:
# 107 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_4


TapuKokoBridge_InteractLillie::
# 151 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 152 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 153 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 156 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_TryLeave::
# 161 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 162 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 163 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 164 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_2, 29
	goto_if_eq TapuKokoBridge_trigger_TryLeave_2
TapuKokoBridge_trigger_TryLeave_1:
# 174 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 19
	goto_if_eq TapuKokoBridge_trigger_TryLeave_5
TapuKokoBridge_trigger_TryLeave_4:
# 184 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 23
	goto_if_eq TapuKokoBridge_trigger_TryLeave_8
TapuKokoBridge_trigger_TryLeave_7:
# 194 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_trigger_TryLeave_2:
# 165 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_0
# 166 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 167 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 168 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 171 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 172 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_1

TapuKokoBridge_trigger_TryLeave_5:
# 175 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 177 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 178 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 181 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 182 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_4

TapuKokoBridge_trigger_TryLeave_8:
# 185 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_4
# 186 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 187 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 188 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_5
# 192 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_7


# 21 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_0:
# 21 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 21 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 23 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_1:
# 23 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 23 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 23 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 27 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_2:
# 27 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 39 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_3:
# 39 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
# 39 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
	step_end

# 45 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_4:
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 46 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_5:
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 62 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_6:
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
	step_end

# 67 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_7:
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 70 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_8:
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 83 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_9:
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 90 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_10:
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 95 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_11:
# 95 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 95 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 111 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_12:
# 111 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 114 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_13:
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 114 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 116 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_14:
# 116 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
# 116 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
	step_end

# 120 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_15:
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 123 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_16:
# 123 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 130 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_17:
# 130 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 130 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 165 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_0:
# 165 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
# 165 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 171 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_1:
# 171 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 175 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_2:
# 175 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
# 175 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 181 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_3:
# 181 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 185 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_4:
# 185 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
# 185 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 191 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_5:
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
	step_end

TapuKokoBridge_LillieCosmogEvent_Text_0:
# 97 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Ah…$"

TapuKokoBridge_LillieCosmogEvent_Text_1:
# 98 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What's wrong?$"

TapuKokoBridge_LillieCosmogEvent_Text_2:
# 98 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Who are you?$"

TapuKokoBridge_LillieCosmogEvent_Text_3:
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	.string "H-help…\p"
	.string "Save Nebby!$"

TapuKokoBridge_LillieCosmogEvent_Text_4:
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pe-e-ew…$"

TapuKokoBridge_LillieCosmogEvent_Text_5:
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Those Wingull are attacking it!\p"
	.string "But…I'm not a Trainer.\n"
	.string "I can't…$"

TapuKokoBridge_LillieCosmogEvent_Text_6:
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!\p"
	.string "I'll heal your Pokémon for you, so…$"

TapuKokoBridge_InteractLillie_Text_0:
# 153 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!$"
