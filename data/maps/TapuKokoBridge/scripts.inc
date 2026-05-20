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
# 283 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 284 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 285 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_BridgeShake::
# 290 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 291 "data/maps/TapuKokoBridge/scripts.pory"
	special ShowCutsceneCinematicBars
# 292 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 293 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 294 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 295 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 296 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 298 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 299 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 300 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 301 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 20
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_2
TapuKokoBridge_trigger_BridgeShake_1:
# 306 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 22
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_5
TapuKokoBridge_trigger_BridgeShake_4:
# 311 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 21
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_8
TapuKokoBridge_trigger_BridgeShake_7:
# 315 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 316 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_COSMOG
# 317 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 318 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 319 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 320 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 321 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 322 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 323 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 325 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 326 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 327 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 21, 20, 0
# 328 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 329 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 331 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 334 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 335 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 3
# 336 "data/maps/TapuKokoBridge/scripts.pory"
	delay 20
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 339 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_ORB
# 340 "data/maps/TapuKokoBridge/scripts.pory"
	special DoOrbEffect
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	special OrbFadeToBlack
# 343 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 345 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 346 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BANG
# 347 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 348 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_MAHALO_BRIDGE_BROKEN
# 349 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
# 350 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 25, METATILE_TapuKokoBridge_Water, TRUE
# 351 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 25, METATILE_TapuKokoBridge_Water, TRUE
# 352 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 25, METATILE_TapuKokoBridge_Water, TRUE
# 353 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 24, METATILE_TapuKokoBridge_Water, TRUE
# 354 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 24, METATILE_TapuKokoBridge_Water, TRUE
# 355 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 24, METATILE_TapuKokoBridge_Water, TRUE
# 356 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 23, METATILE_TapuKokoBridge_Water, TRUE
# 357 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 23, METATILE_TapuKokoBridge_Water, TRUE
# 358 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 23, METATILE_TapuKokoBridge_Water, TRUE
# 359 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 22, METATILE_TapuKokoBridge_Water, TRUE
# 360 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 22, METATILE_TapuKokoBridge_Water, TRUE
# 361 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 22, METATILE_TapuKokoBridge_Water, TRUE
# 362 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 21, METATILE_TapuKokoBridge_Water, TRUE
# 363 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 21, METATILE_TapuKokoBridge_Water, TRUE
# 364 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 21, METATILE_TapuKokoBridge_Water, TRUE
# 365 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 20, METATILE_TapuKokoBridge_Water, TRUE
# 366 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 20, METATILE_TapuKokoBridge_Water, TRUE
# 367 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 20, METATILE_TapuKokoBridge_Water, TRUE
# 368 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, METATILE_TapuKokoBridge_Water, TRUE
# 369 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 14, 0x03E, TRUE
# 370 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 14, 0x03E, TRUE
# 371 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 14, 0x03E, TRUE
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 15, 0x03E, TRUE
# 373 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 15, 0x03E, TRUE
# 374 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 15, 0x03E, TRUE
# 375 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 16, 0x03E, TRUE
# 376 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 16, 0x03E, TRUE
# 377 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 17, 0x03E, TRUE
# 378 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 16, 0x14F, TRUE
# 379 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 17, 0x14F, TRUE
# 380 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 18, 0x14F, TRUE
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 17, 0x03F, TRUE
# 382 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 18, 0x03F, TRUE
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, 0x924, TRUE
# 384 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 18, 0x03E, TRUE
# 385 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 19, 0x03E, TRUE
# 386 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 19, 0x03E, TRUE
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	special DrawWholeMapView
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull4
# 389 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull5
# 390 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull6
# 391 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 392 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 393 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 394 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 395 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_3
# 399 "data/maps/TapuKokoBridge/scripts.pory"
	delay 28
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_4
# 401 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_FALL
# 402 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 403 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 405 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 406 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 407 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgetapukoko, 21, 27
# 408 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgecosmog2, MAP_TAPU_KOKO_BRIDGE
# 409 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog2, 20, 30
# 410 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectmovementtype bridgecosmog2, MOVEMENT_TYPE_NONE
# 411 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 412 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_5
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_6
# 415 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 416 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 417 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 418 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 6
# 419 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 420 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 421 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 422 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 423 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 424 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 425 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 426 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_8
# 429 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 430 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_9
# 432 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 433 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 434 "data/maps/TapuKokoBridge/scripts.pory"
	delay 39
# 435 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_6
# 436 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 437 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 438 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 439 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_10
# 440 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 441 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_11
# 445 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 446 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_1
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_12
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 470 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 471 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 472 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_13
# 475 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 476 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_2, MSGBOX_AUTOCLOSE
# 478 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 479 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 480 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 23, 30, 0
# 481 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 482 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 483 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 484 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 485 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 486 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_3, MSGBOX_AUTOCLOSE
# 487 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 488 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_4, MSGBOX_AUTOCLOSE
# 490 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 491 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 492 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 493 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_5
# 497 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_2, TapuKokoBridge_trigger_BridgeShake_Text_6
# 498 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_11
TapuKokoBridge_trigger_BridgeShake_10:
# 503 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_14
TapuKokoBridge_trigger_BridgeShake_13:
# 510 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 511 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_10, MSGBOX_AUTOCLOSE
# 513 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 515 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_7
# 516 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 517 "data/maps/TapuKokoBridge/scripts.pory"
	giveitem ITEM_SPARKLING_STONE, 1
# 518 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 519 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_11, MSGBOX_AUTOCLOSE
# 525 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 526 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 527 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 528 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_12, MSGBOX_AUTOCLOSE
# 529 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 530 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 531 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 532 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 533 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 534 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_13, MSGBOX_AUTOCLOSE
# 535 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 536 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 537 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 538 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog2
# 539 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 540 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 541 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 542 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_14
# 544 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 545 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_14, MSGBOX_AUTOCLOSE
# 556 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 557 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_15
# 558 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 559 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 560 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 561 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 562 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 563 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 564 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_16
# 565 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_17
# 566 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 567 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 568 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_LILLIE
# 569 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 570 "data/maps/TapuKokoBridge/scripts.pory"
	warp MAP_IKI_TOWN, 5
# 571 "data/maps/TapuKokoBridge/scripts.pory"
	release
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end

TapuKokoBridge_trigger_BridgeShake_2:
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_0
# 304 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_1

TapuKokoBridge_trigger_BridgeShake_5:
# 308 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_1
# 309 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_4

TapuKokoBridge_trigger_BridgeShake_8:
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_2
# 313 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_7

TapuKokoBridge_trigger_BridgeShake_11:
# 500 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 501 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_8
	goto TapuKokoBridge_trigger_BridgeShake_10

TapuKokoBridge_trigger_BridgeShake_14:
# 505 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 506 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_9
	goto TapuKokoBridge_trigger_BridgeShake_13


TapuKokoBridge_SetBrokenBridge::
# 577 "data/maps/TapuKokoBridge/scripts.pory"
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

# 303 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_0:
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 308 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_1:
# 308 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_left
# 308 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 308 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 308 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 312 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_2:
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 398 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_3:
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
	step_end

# 400 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_4:
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
	step_end

# 413 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_5:
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 414 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_6:
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 423 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_7:
# 423 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 423 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 428 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_8:
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	shake_horizontal
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	shake_horizontal
	step_end

# 431 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_9:
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
	step_end

# 439 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_10:
# 439 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
# 439 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
	step_end

# 444 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_11:
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
	step_end

# 468 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_12:
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 474 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_13:
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	emote_question_mark
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 543 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_14:
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 557 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_15:
# 557 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
# 557 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
	step_end

# 564 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_16:
# 564 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 564 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 564 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 565 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_17:
# 565 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 565 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 565 "data/maps/TapuKokoBridge/scripts.pory"
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
	.string "But be careful…\p"
	.string "It looks like that attack may have\n"
	.string "damaged the Plank Bridge, too…$"

TapuKokoBridge_trigger_BridgeShake_Text_0:
# 441 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_1:
# 446 "data/maps/TapuKokoBridge/scripts.pory"
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
# 476 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What…\n"
	.string "What is that?$"

TapuKokoBridge_trigger_BridgeShake_Text_3:
# 486 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_4:
# 488 "data/maps/TapuKokoBridge/scripts.pory"
	.string "A sparkling…stone?\n"
	.string "It feels almost warm somehow…$"

TapuKokoBridge_trigger_BridgeShake_Text_5:
# 493 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please, forgive me…\p"
	.string "I am so grateful to you for helping us\n"
	.string "out of that dangerous spot.$"

TapuKokoBridge_trigger_BridgeShake_Text_6:
# 497 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Are you the kahuna?$"

TapuKokoBridge_trigger_BridgeShake_Text_7:
# 500 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Lillie$"

TapuKokoBridge_trigger_BridgeShake_Text_8:
# 501 "data/maps/TapuKokoBridge/scripts.pory"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_9:
# 506 "data/maps/TapuKokoBridge/scripts.pory"
	.string "No no.\p"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_10:
# 511 "data/maps/TapuKokoBridge/scripts.pory"
	.string "And I suppose…this stone must belong\n"
	.string "to you.$"

TapuKokoBridge_trigger_BridgeShake_Text_11:
# 519 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…\p"
	.string "Don't tell anyone about this…\n"
	.string "About seeing Nebby…\p"
	.string "It's…it's a secret, OK?$"

TapuKokoBridge_trigger_BridgeShake_Text_12:
# 528 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Come on, Into the bag, Nebby.$"

TapuKokoBridge_trigger_BridgeShake_Text_13:
# 534 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew…$"

TapuKokoBridge_trigger_BridgeShake_Text_14:
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Um…\p"
	.string "I'm worried we might get attacked again\n"
	.string "by some wild Pokémon or…or something.\p"
	.string "I know it's too much for me to ask it,\n"
	.string "but…\p"
	.string "Do you think you could see us back to\n"
	.string "town?$"
