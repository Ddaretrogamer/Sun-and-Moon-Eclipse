TapuKokoBridge_MapScripts::
# 2 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 23 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/TapuKokoBridge/scripts.pory"
	call_if_set FLAG_MAHALO_BRIDGE_BROKEN, TapuKokoBridge_SetBrokenBridge
# 4 "data/maps/TapuKokoBridge/scripts.pory"
	goto_if_set FLAG_SHINY_COSMOG, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 9 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( COSMOG )
# 10 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( COSMOG )
TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 5 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( COSMOG )
# 6 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( COSMOG )
	goto TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 14 "data/maps/TapuKokoBridge/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 3, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
# 19 "data/maps/TapuKokoBridge/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 4, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	.2byte 0

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 15 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 16 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 17 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgelillie, 21, 30
	return

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
# 20 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgelillie, 22, 27
# 21 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog, 21, 20
	return

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 23 "data/maps/TapuKokoBridge/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 3, TapuKokoBridge_LillieCosmogEvent
	.2byte 0


TapuKokoBridge_LillieCosmogEvent::
# 27 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 28 "data/maps/TapuKokoBridge/scripts.pory"
	special SpawnCameraObject
# 29 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_0
# 30 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 31 "data/maps/TapuKokoBridge/scripts.pory"
	special ShowCutsceneCinematicBars
# 32 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 33 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 34 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 35 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 36 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 37 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 38 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 39 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 40 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 41 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 42 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 43 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 44 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 47 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 48 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 51 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 52 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 53 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 54 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_4
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_5
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 58 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 59 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 60 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 61 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 63 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 64 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 65 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 68 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 69 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_6
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 75 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 76 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull1, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 79 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull3, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 82 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 84 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull1
# 85 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull3
# 87 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 88 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_HIDE_CIRCLING_WINGULLS
# 89 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull4, MAP_TAPU_KOKO_BRIDGE
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull5, MAP_TAPU_KOKO_BRIDGE
# 91 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull6, MAP_TAPU_KOKO_BRIDGE
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_9
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 95 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 96 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 4
# 97 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 98 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 99 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 100 "data/maps/TapuKokoBridge/scripts.pory"
	delay 15
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 103 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 104 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 105 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 106 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 107 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 108 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_0
# 109 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_1, TapuKokoBridge_LillieCosmogEvent_Text_2
# 110 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_2
TapuKokoBridge_LillieCosmogEvent_1:
# 116 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_5
TapuKokoBridge_LillieCosmogEvent_4:
# 122 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 123 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_13
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	delay 240
# 127 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 128 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 129 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_4, MSGBOX_AUTOCLOSE
# 130 "data/maps/TapuKokoBridge/scripts.pory"
	delay 120
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_15
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 133 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 134 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 135 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 136 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_5, MSGBOX_AUTOCLOSE
# 140 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 141 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_17
# 142 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 143 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_6, MSGBOX_AUTOCLOSE
# 148 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 149 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 150 "data/maps/TapuKokoBridge/scripts.pory"
	special HealPlayerParty
# 151 "data/maps/TapuKokoBridge/scripts.pory"
	playfanfare MUS_HEAL
# 152 "data/maps/TapuKokoBridge/scripts.pory"
	waitfanfare
# 153 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 154 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 155 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 156 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 157 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_LillieCosmogEvent_2:
# 112 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_1

TapuKokoBridge_LillieCosmogEvent_5:
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_4


TapuKokoBridge_InteractLillie::
# 162 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 163 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 164 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 167 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_TryLeave::
# 172 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 173 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 174 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 175 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_2, 29
	goto_if_eq TapuKokoBridge_trigger_TryLeave_2
TapuKokoBridge_trigger_TryLeave_1:
# 186 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 19
	goto_if_eq TapuKokoBridge_trigger_TryLeave_5
TapuKokoBridge_trigger_TryLeave_4:
# 197 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 23
	goto_if_eq TapuKokoBridge_trigger_TryLeave_8
TapuKokoBridge_trigger_TryLeave_7:
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_trigger_TryLeave_2:
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_0
# 177 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 178 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 179 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 180 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 183 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 184 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_1

TapuKokoBridge_trigger_TryLeave_5:
# 187 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 188 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 189 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 190 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 194 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_4
# 195 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_4

TapuKokoBridge_trigger_TryLeave_8:
# 198 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_5
# 199 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 200 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_6
# 201 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 202 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 205 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_7
# 206 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_7


TapuKokoBridge_Trigger_StartWingullBattle::
# 213 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 214 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull2
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_0
# 216 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 217 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 218 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 219 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 220 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 221 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 222 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 223 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_CATCHING
# 224 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_RUNNING
# 225 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_FORCE_NO_SHINY
# 226 "data/maps/TapuKokoBridge/scripts.pory"
	setwildbattle SPECIES_WINGULL, 3, 0, FALSE
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	dowildbattle
# 228 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_CATCHING
# 229 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_RUNNING
# 230 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_FORCE_NO_SHINY
# 231 "data/maps/TapuKokoBridge/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 232 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq TapuKokoBridge_Trigger_StartWingullBattle_1
	return

TapuKokoBridge_Trigger_StartWingullBattle_1:
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_1
# 235 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 236 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 237 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 238 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 239 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 5
# 240 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 241 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 242 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_Trigger_StartWingullBattle_Text_0, MSGBOX_AUTOCLOSE
# 252 "data/maps/TapuKokoBridge/scripts.pory"
	waitmessage
# 253 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end


TapuKokoBridge_Trigger_StartWingullBattleleft::
# 259 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0
# 261 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_Trigger_StartWingullBattleRight::
# 266 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 267 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0
# 268 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 269 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_trigger_TryLeave2::
# 273 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 274 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 275 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 276 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 277 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_TryLeave2_Text_0, MSGBOX_AUTOCLOSE
# 280 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 281 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 282 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_BridgeShake::
# 287 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	special ShowCutsceneCinematicBars
# 289 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 290 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 291 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 292 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 293 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 294 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 295 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 296 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_0
# 298 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 299 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 300 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_COSMOG
# 301 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 302 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 304 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 305 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 306 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 307 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 309 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 310 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 311 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 21, 20, 0
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 313 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 315 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 316 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 317 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 318 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 319 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 3
# 320 "data/maps/TapuKokoBridge/scripts.pory"
	delay 20
# 321 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 323 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_ORB
# 324 "data/maps/TapuKokoBridge/scripts.pory"
	special DoOrbEffect
# 325 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 326 "data/maps/TapuKokoBridge/scripts.pory"
	special FadeOutOrbEffect
# 327 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 328 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 329 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BANG
# 330 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 331 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_MAHALO_BRIDGE_BROKEN
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 25, METATILE_TapuKokoBridge_Water, TRUE
# 334 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 25, METATILE_TapuKokoBridge_Water, TRUE
# 335 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 25, METATILE_TapuKokoBridge_Water, TRUE
# 336 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 24, METATILE_TapuKokoBridge_Water, TRUE
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 24, METATILE_TapuKokoBridge_Water, TRUE
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 24, METATILE_TapuKokoBridge_Water, TRUE
# 339 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 23, METATILE_TapuKokoBridge_Water, TRUE
# 340 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 23, METATILE_TapuKokoBridge_Water, TRUE
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 23, METATILE_TapuKokoBridge_Water, TRUE
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 22, METATILE_TapuKokoBridge_Water, TRUE
# 343 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 22, METATILE_TapuKokoBridge_Water, TRUE
# 344 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 22, METATILE_TapuKokoBridge_Water, TRUE
# 345 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 21, METATILE_TapuKokoBridge_Water, TRUE
# 346 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 21, METATILE_TapuKokoBridge_Water, TRUE
# 347 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 21, METATILE_TapuKokoBridge_Water, TRUE
# 348 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 20, METATILE_TapuKokoBridge_Water, TRUE
# 349 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 20, METATILE_TapuKokoBridge_Water, TRUE
# 350 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 20, METATILE_TapuKokoBridge_Water, TRUE
# 351 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, METATILE_TapuKokoBridge_Water, TRUE
# 352 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 14, 0x03E, TRUE
# 353 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 14, 0x03E, TRUE
# 354 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 14, 0x03E, TRUE
# 355 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 15, 0x03E, TRUE
# 356 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 15, 0x03E, TRUE
# 357 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 15, 0x03E, TRUE
# 358 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 16, 0x03E, TRUE
# 359 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 16, 0x03E, TRUE
# 360 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 17, 0x03E, TRUE
# 361 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 16, 0x14F, TRUE
# 362 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 17, 0x14F, TRUE
# 363 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 18, 0x14F, TRUE
# 364 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 17, 0x03F, TRUE
# 365 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 18, 0x03F, TRUE
# 366 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, 0x924, TRUE
# 367 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 18, 0x03E, TRUE
# 368 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 19, 0x03E, TRUE
# 369 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 19, 0x03E, TRUE
# 370 "data/maps/TapuKokoBridge/scripts.pory"
	special DrawWholeMapView
# 371 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull4
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull5
# 373 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull6
# 374 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 375 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 376 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 377 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 378 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 379 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 380 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_1
# 382 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_2
# 384 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_FALL
# 385 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 386 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 389 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 390 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgetapukoko, 21, 27
# 391 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgecosmog2, MAP_TAPU_KOKO_BRIDGE
# 392 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog2, 20, 30
# 393 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectmovementtype bridgecosmog2, MOVEMENT_TYPE_NONE
# 394 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 395 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_3
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_4
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 399 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 401 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 6
# 402 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 403 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 405 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 406 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_5
# 407 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_5
# 408 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 409 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 410 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 411 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 412 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_6
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 415 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 416 "data/maps/TapuKokoBridge/scripts.pory"
	delay 39
# 417 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_6
# 418 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 419 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 420 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 421 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 422 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 423 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 424 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 425 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 426 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_8
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_1
# 450 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_9
# 451 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 452 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 453 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 454 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 455 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 456 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_10
# 457 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_2, MSGBOX_AUTOCLOSE
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 462 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 23, 30, 0
# 463 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 464 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 465 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 466 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 467 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_3, MSGBOX_AUTOCLOSE
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 470 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_4, MSGBOX_AUTOCLOSE
# 472 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 475 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_5
# 479 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_2, TapuKokoBridge_trigger_BridgeShake_Text_6
# 480 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_2
TapuKokoBridge_trigger_BridgeShake_1:
# 485 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_5
TapuKokoBridge_trigger_BridgeShake_4:
# 492 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 493 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_10, MSGBOX_AUTOCLOSE
# 495 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 496 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 497 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_7
# 498 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 499 "data/maps/TapuKokoBridge/scripts.pory"
	giveitem ITEM_Z_POWER_RING, 1
# 500 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 501 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_11, MSGBOX_AUTOCLOSE
# 507 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 508 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 509 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 510 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_12, MSGBOX_AUTOCLOSE
# 511 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 512 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 513 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 515 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 516 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_13, MSGBOX_AUTOCLOSE
# 517 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 518 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 519 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 520 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog2
# 521 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 522 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 523 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 524 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_11
# 525 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 526 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 527 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_14, MSGBOX_AUTOCLOSE
# 537 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 538 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_12
# 539 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 540 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 541 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 542 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 544 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 545 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_13
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_14
# 547 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 548 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 549 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_LILLIE
# 550 "data/maps/TapuKokoBridge/scripts.pory"
	warp MAP_IKI_TOWN, 5
# 551 "data/maps/TapuKokoBridge/scripts.pory"
	release
# 552 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end

TapuKokoBridge_trigger_BridgeShake_2:
# 482 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 483 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_8
	goto TapuKokoBridge_trigger_BridgeShake_1

TapuKokoBridge_trigger_BridgeShake_5:
# 487 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 488 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_9
	goto TapuKokoBridge_trigger_BridgeShake_4


TapuKokoBridge_SetBrokenBridge::
# 557 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
	return


# 29 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_0:
# 29 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 29 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 33 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_1:
# 33 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 33 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 33 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 37 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_2:
# 37 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 49 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_3:
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
	step_end

# 55 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_4:
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 56 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_5:
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 72 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_6:
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
	step_end

# 77 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_7:
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 80 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_8:
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 92 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_9:
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 101 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_10:
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 106 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_11:
# 106 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 106 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 122 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_12:
# 122 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 125 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_13:
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 127 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_14:
# 127 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
# 127 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
	step_end

# 131 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_15:
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 134 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_16:
# 134 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 141 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_17:
# 141 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 141 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 176 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_0:
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 183 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_1:
# 183 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 187 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_2:
# 187 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
# 187 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 189 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_3:
# 189 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 194 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_4:
# 194 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 198 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_5:
# 198 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
# 198 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 200 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_6:
# 200 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 205 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_7:
# 205 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
	step_end

# 215 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_0:
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 234 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_1:
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
	step_end

# 241 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_2:
# 241 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
# 241 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
	step_end

# 260 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0:
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 267 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0:
# 267 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 267 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 297 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_0:
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 381 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_1:
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
	step_end

# 383 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_2:
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
	step_end

# 396 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_3:
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 397 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_4:
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 406 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_5:
# 406 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 406 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 413 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_6:
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
	step_end

# 421 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_7:
# 421 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
# 421 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
	step_end

# 426 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_8:
# 426 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
# 426 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
	step_end

# 450 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_9:
# 450 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 450 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 456 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_10:
# 456 "data/maps/TapuKokoBridge/scripts.pory"
	emote_question_mark
# 456 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 524 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_11:
# 524 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 524 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 524 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 524 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 524 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 524 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 538 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_12:
# 538 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
# 538 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
	step_end

# 545 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_13:
# 545 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 545 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 545 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 546 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_14:
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

TapuKokoBridge_LillieCosmogEvent_Text_0:
# 108 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Ah…$"

TapuKokoBridge_LillieCosmogEvent_Text_1:
# 109 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What's wrong?$"

TapuKokoBridge_LillieCosmogEvent_Text_2:
# 109 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Who are you?$"

TapuKokoBridge_LillieCosmogEvent_Text_3:
# 112 "data/maps/TapuKokoBridge/scripts.pory"
	.string "H-help…\p"
	.string "Save Nebby!$"

TapuKokoBridge_LillieCosmogEvent_Text_4:
# 129 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pe-e-ew…$"

TapuKokoBridge_LillieCosmogEvent_Text_5:
# 136 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Those Wingull are attacking it!\p"
	.string "But…I'm not a Trainer.\n"
	.string "I can't…$"

TapuKokoBridge_LillieCosmogEvent_Text_6:
# 143 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!\p"
	.string "I'll heal your Pokémon for you, so…$"

TapuKokoBridge_InteractLillie_Text_0:
# 164 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!$"

TapuKokoBridge_Trigger_StartWingullBattle_Text_0:
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	.string "You managed to chase off one of the\n"
	.string "Wingull, but…oh, there are still more!\p"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…\p"
	.string "It looks like that attack may have\n"
	.string "damaged the Plank Bridge, too…$"

TapuKokoBridge_trigger_TryLeave2_Text_0:
# 277 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…$"

TapuKokoBridge_trigger_BridgeShake_Text_0:
# 423 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_1:
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Oh…\n"
	.string "Oh thank goodness!\p"
	.string "You tried using your power again…\n"
	.string "didn't you…?\p"
	.string "Oh, Nebby…\p"
	.string "You know what happened last time you\n"
	.string "used it.\p"
	.string "You couldnt move for ages after that.\p"
	.string "I don't want to see you like that again!\p"
	.string "No… I shouldn't say that.\n"
	.string "I'm sorry, Nebby…\p"
	.string "I know you were trying to save me that\n"
	.string "time…\p"
	.string "And I couldn't even help you in return…$"

TapuKokoBridge_trigger_BridgeShake_Text_2:
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What…\n"
	.string "What is that?$"

TapuKokoBridge_trigger_BridgeShake_Text_3:
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_4:
# 470 "data/maps/TapuKokoBridge/scripts.pory"
	.string "A sparkling…stone?\n"
	.string "It feels almost warm somehow…$"

TapuKokoBridge_trigger_BridgeShake_Text_5:
# 475 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please, forgive me…\p"
	.string "I am so grateful to you for helping us\n"
	.string "out of that dangerous spot.$"

TapuKokoBridge_trigger_BridgeShake_Text_6:
# 479 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Are you the kahuna?$"

TapuKokoBridge_trigger_BridgeShake_Text_7:
# 482 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Lillie$"

TapuKokoBridge_trigger_BridgeShake_Text_8:
# 483 "data/maps/TapuKokoBridge/scripts.pory"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_9:
# 488 "data/maps/TapuKokoBridge/scripts.pory"
	.string "No no.\p"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_10:
# 493 "data/maps/TapuKokoBridge/scripts.pory"
	.string "And I suppose…this stone must belong\n"
	.string "to you.$"

TapuKokoBridge_trigger_BridgeShake_Text_11:
# 501 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…\p"
	.string "Don't tell anyone about this…\n"
	.string "About seeing Nebby…\p"
	.string "It's…it's a secret, OK?$"

TapuKokoBridge_trigger_BridgeShake_Text_12:
# 510 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Come on, Into the bag, Nebby.$"

TapuKokoBridge_trigger_BridgeShake_Text_13:
# 516 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew…$"

TapuKokoBridge_trigger_BridgeShake_Text_14:
# 527 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Um…\p"
	.string "I'm worried we might get attacked again\n"
	.string "by some wild Pokémon or…or something.\p"
	.string "I know it's too much for me to ask it,\n"
	.string "but…\p"
	.string "Do you think you could see us back to\n"
	.string "town?$"
