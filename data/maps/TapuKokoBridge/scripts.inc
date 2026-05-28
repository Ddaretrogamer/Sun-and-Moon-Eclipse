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
	startcutscene CUTSCENE_TAPUKOKO_BRIDGE
# 32 "data/maps/TapuKokoBridge/scripts.pory"
	special ShowCutsceneCinematicBars
# 33 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 34 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 35 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 36 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 37 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 38 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 39 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 40 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 41 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 42 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 43 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 44 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 47 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 48 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 51 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 52 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 53 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 54 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_4
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_5
# 58 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 59 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 60 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 61 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 63 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 64 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 65 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 68 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 69 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_6
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 75 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 76 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull1, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 79 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull3, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 82 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 84 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 85 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull1
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 87 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull3
# 88 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 89 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_HIDE_CIRCLING_WINGULLS
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull4, MAP_TAPU_KOKO_BRIDGE
# 91 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull5, MAP_TAPU_KOKO_BRIDGE
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull6, MAP_TAPU_KOKO_BRIDGE
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_9
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 95 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 96 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 97 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 4
# 98 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 99 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 100 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	delay 15
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 103 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 104 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 105 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 106 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 107 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 108 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 109 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_0
# 110 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_1, TapuKokoBridge_LillieCosmogEvent_Text_2
# 111 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_2
TapuKokoBridge_LillieCosmogEvent_1:
# 117 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_5
TapuKokoBridge_LillieCosmogEvent_4:
# 123 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_13
# 127 "data/maps/TapuKokoBridge/scripts.pory"
	delay 240
# 128 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 129 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 130 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_4, MSGBOX_AUTOCLOSE
# 131 "data/maps/TapuKokoBridge/scripts.pory"
	delay 120
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_15
# 133 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 134 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 135 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 136 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 137 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_5, MSGBOX_AUTOCLOSE
# 141 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 142 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_17
# 143 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 144 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_6, MSGBOX_AUTOCLOSE
# 149 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 150 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 151 "data/maps/TapuKokoBridge/scripts.pory"
	special HealPlayerParty
# 152 "data/maps/TapuKokoBridge/scripts.pory"
	playfanfare MUS_HEAL
# 153 "data/maps/TapuKokoBridge/scripts.pory"
	waitfanfare
# 154 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 155 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 156 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 157 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 158 "data/maps/TapuKokoBridge/scripts.pory"
	endcutscene
# 159 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_LillieCosmogEvent_2:
# 113 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_1

TapuKokoBridge_LillieCosmogEvent_5:
# 119 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_4


TapuKokoBridge_LillieCosmogSkip::
# 164 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 165 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 166 "data/maps/TapuKokoBridge/scripts.pory"
	special CloseScriptMenus
# 167 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 28
# 168 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 169 "data/maps/TapuKokoBridge/scripts.pory"
	special SnapCameraToPlayer
# 170 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 171 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 172 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 173 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgelillie, 22, 27
# 174 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog, 21, 20
# 175 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull1
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 177 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull3
# 178 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull4, MAP_TAPU_KOKO_BRIDGE
# 179 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull5, MAP_TAPU_KOKO_BRIDGE
# 180 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull6, MAP_TAPU_KOKO_BRIDGE
# 181 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 182 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_HIDE_CIRCLING_WINGULLS
# 183 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 4
# 184 "data/maps/TapuKokoBridge/scripts.pory"
	special HealPlayerParty
# 185 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 186 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_InteractLillie::
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 192 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 193 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 196 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_TryLeave::
# 201 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 202 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 203 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 204 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_2, 29
	goto_if_eq TapuKokoBridge_trigger_TryLeave_2
TapuKokoBridge_trigger_TryLeave_1:
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 19
	goto_if_eq TapuKokoBridge_trigger_TryLeave_5
TapuKokoBridge_trigger_TryLeave_4:
# 226 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 23
	goto_if_eq TapuKokoBridge_trigger_TryLeave_8
TapuKokoBridge_trigger_TryLeave_7:
# 237 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_trigger_TryLeave_2:
# 205 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_0
# 206 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 207 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 209 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 212 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 213 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_1

TapuKokoBridge_trigger_TryLeave_5:
# 216 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 217 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 218 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 219 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 220 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 223 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_4
# 224 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_4

TapuKokoBridge_trigger_TryLeave_8:
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_5
# 228 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 229 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_6
# 230 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 231 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_7
# 235 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_7


TapuKokoBridge_Trigger_StartWingullBattle::
# 242 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull2
# 244 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_0
# 245 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 246 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 247 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 248 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 249 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 250 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 251 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 252 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_CATCHING
# 253 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_RUNNING
# 254 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_FORCE_NO_SHINY
# 255 "data/maps/TapuKokoBridge/scripts.pory"
	setwildbattle SPECIES_WINGULL, 3, 0, FALSE
# 256 "data/maps/TapuKokoBridge/scripts.pory"
	dowildbattle
# 257 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_CATCHING
# 258 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_RUNNING
# 259 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_FORCE_NO_SHINY
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 261 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq TapuKokoBridge_Trigger_StartWingullBattle_1
	return

TapuKokoBridge_Trigger_StartWingullBattle_1:
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_1
# 264 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 265 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 266 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 267 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 268 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 5
# 269 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 270 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 271 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 272 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_Trigger_StartWingullBattle_Text_0, MSGBOX_AUTOCLOSE
# 281 "data/maps/TapuKokoBridge/scripts.pory"
	waitmessage
# 282 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end


TapuKokoBridge_Trigger_StartWingullBattleleft::
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 289 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0
# 290 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 291 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_Trigger_StartWingullBattleRight::
# 295 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 296 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 298 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_trigger_TryLeave2::
# 302 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 304 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 305 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 306 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_TryLeave2_Text_0, MSGBOX_AUTOCLOSE
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 313 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 314 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_BridgeShake::
# 319 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 320 "data/maps/TapuKokoBridge/scripts.pory"
	startcutscene CUTSCENE_TAPUKOKO_BRIDGE_SHAKE
# 321 "data/maps/TapuKokoBridge/scripts.pory"
	special ShowCutsceneCinematicBars
# 322 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 323 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 324 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 325 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 326 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 327 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 328 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 329 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 330 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 331 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 20
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_2
TapuKokoBridge_trigger_BridgeShake_1:
# 336 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 22
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_5
TapuKokoBridge_trigger_BridgeShake_4:
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 21
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_8
TapuKokoBridge_trigger_BridgeShake_7:
# 345 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 346 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_COSMOG
# 347 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 348 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 349 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 350 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 351 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 352 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 353 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 355 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 356 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 357 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 21, 20, 0
# 358 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 359 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 361 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 362 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 363 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 364 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 365 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 3
# 366 "data/maps/TapuKokoBridge/scripts.pory"
	delay 20
# 367 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 369 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_ORB
# 370 "data/maps/TapuKokoBridge/scripts.pory"
	special DoOrbEffect
# 371 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	special OrbFadeToBlack
# 373 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 375 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 376 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BANG
# 377 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 378 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_MAHALO_BRIDGE_BROKEN
# 379 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
# 380 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 25, METATILE_TapuKokoBridge_Water, TRUE
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 25, METATILE_TapuKokoBridge_Water, TRUE
# 382 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 25, METATILE_TapuKokoBridge_Water, TRUE
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 24, METATILE_TapuKokoBridge_Water, TRUE
# 384 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 24, METATILE_TapuKokoBridge_Water, TRUE
# 385 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 24, METATILE_TapuKokoBridge_Water, TRUE
# 386 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 23, METATILE_TapuKokoBridge_Water, TRUE
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 23, METATILE_TapuKokoBridge_Water, TRUE
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 23, METATILE_TapuKokoBridge_Water, TRUE
# 389 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 22, METATILE_TapuKokoBridge_Water, TRUE
# 390 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 22, METATILE_TapuKokoBridge_Water, TRUE
# 391 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 22, METATILE_TapuKokoBridge_Water, TRUE
# 392 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 21, METATILE_TapuKokoBridge_Water, TRUE
# 393 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 21, METATILE_TapuKokoBridge_Water, TRUE
# 394 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 21, METATILE_TapuKokoBridge_Water, TRUE
# 395 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 20, METATILE_TapuKokoBridge_Water, TRUE
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 20, METATILE_TapuKokoBridge_Water, TRUE
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 20, METATILE_TapuKokoBridge_Water, TRUE
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, METATILE_TapuKokoBridge_Water, TRUE
# 399 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 14, 0x03E, TRUE
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 14, 0x03E, TRUE
# 401 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 14, 0x03E, TRUE
# 402 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 15, 0x03E, TRUE
# 403 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 15, 0x03E, TRUE
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 15, 0x03E, TRUE
# 405 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 16, 0x03E, TRUE
# 406 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 16, 0x03E, TRUE
# 407 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 17, 0x03E, TRUE
# 408 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 16, 0x14F, TRUE
# 409 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 17, 0x14F, TRUE
# 410 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 18, 0x14F, TRUE
# 411 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 17, 0x03F, TRUE
# 412 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 18, 0x03F, TRUE
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, 0x924, TRUE
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 18, 0x03E, TRUE
# 415 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 19, 0x03E, TRUE
# 416 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 19, 0x03E, TRUE
# 417 "data/maps/TapuKokoBridge/scripts.pory"
	special DrawWholeMapView
# 418 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull4
# 419 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull5
# 420 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull6
# 421 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 422 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 423 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 424 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 425 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 426 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_3
# 429 "data/maps/TapuKokoBridge/scripts.pory"
	delay 28
# 430 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_4
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_FALL
# 432 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 433 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 434 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 435 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 436 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 437 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgetapukoko, 21, 27
# 438 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgecosmog2, MAP_TAPU_KOKO_BRIDGE
# 439 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog2, 20, 30
# 440 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectmovementtype bridgecosmog2, MOVEMENT_TYPE_NONE
# 441 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_5
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_6
# 445 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 446 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 447 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 448 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 6
# 449 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 450 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 451 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 452 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 453 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 454 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 455 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 456 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 457 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_8
# 459 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_9
# 462 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 463 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 464 "data/maps/TapuKokoBridge/scripts.pory"
	delay 39
# 465 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_6
# 466 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 467 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_10
# 470 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 471 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 472 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_11
# 475 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 476 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_1
# 498 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_12
# 499 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 500 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 501 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 502 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 503 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 504 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_13
# 505 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 506 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_2, MSGBOX_AUTOCLOSE
# 508 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 509 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 510 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 23, 30, 0
# 511 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 512 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 513 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 515 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 516 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_3, MSGBOX_AUTOCLOSE
# 517 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 518 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_4, MSGBOX_AUTOCLOSE
# 520 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 521 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 522 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 523 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_5
# 527 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_2, TapuKokoBridge_trigger_BridgeShake_Text_6
# 528 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_11
TapuKokoBridge_trigger_BridgeShake_10:
# 533 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_14
TapuKokoBridge_trigger_BridgeShake_13:
# 540 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 541 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_10, MSGBOX_AUTOCLOSE
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 544 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 545 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_7
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 547 "data/maps/TapuKokoBridge/scripts.pory"
	giveitem ITEM_SPARKLING_STONE, 1
# 548 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 549 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_11, MSGBOX_AUTOCLOSE
# 555 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 556 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 557 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 558 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_12, MSGBOX_AUTOCLOSE
# 559 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 560 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 561 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 562 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 563 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 564 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_13, MSGBOX_AUTOCLOSE
# 565 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 566 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 567 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 568 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog2
# 569 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 570 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 571 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_14
# 574 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 575 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 576 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_14, MSGBOX_AUTOCLOSE
# 586 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 587 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_15
# 588 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 589 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 590 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 591 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 592 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 593 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 594 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_16
# 595 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_17
# 596 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 597 "data/maps/TapuKokoBridge/scripts.pory"
	endcutscene
# 598 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 599 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_LILLIE
# 600 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 601 "data/maps/TapuKokoBridge/scripts.pory"
	warp MAP_IKI_TOWN, 5
# 602 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 603 "data/maps/TapuKokoBridge/scripts.pory"
	release
# 604 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end

TapuKokoBridge_trigger_BridgeShake_2:
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_0
# 334 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_1

TapuKokoBridge_trigger_BridgeShake_5:
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_1
# 339 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_4

TapuKokoBridge_trigger_BridgeShake_8:
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_2
# 343 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_7

TapuKokoBridge_trigger_BridgeShake_11:
# 530 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 531 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_8
	goto TapuKokoBridge_trigger_BridgeShake_10

TapuKokoBridge_trigger_BridgeShake_14:
# 535 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 536 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_9
	goto TapuKokoBridge_trigger_BridgeShake_13


TapuKokoBridge_BridgeShakeSkip::
# 609 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 610 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 611 "data/maps/TapuKokoBridge/scripts.pory"
	special CloseScriptMenus
# 612 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 613 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_MAHALO_BRIDGE_BROKEN
# 614 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_COSMOG
# 615 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 616 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 6
# 617 "data/maps/TapuKokoBridge/scripts.pory"
	checkitem ITEM_SPARKLING_STONE, 1
# 618 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TapuKokoBridge_BridgeShakeSkip_2
TapuKokoBridge_BridgeShakeSkip_1:
# 621 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_LILLIE
# 622 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 623 "data/maps/TapuKokoBridge/scripts.pory"
	warp MAP_IKI_TOWN, 5
# 624 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 625 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end

TapuKokoBridge_BridgeShakeSkip_2:
# 619 "data/maps/TapuKokoBridge/scripts.pory"
	additem ITEM_SPARKLING_STONE, 1
	goto TapuKokoBridge_BridgeShakeSkip_1


TapuKokoBridge_SetBrokenBridge::
# 630 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
	return


# 29 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_0:
# 29 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 29 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 34 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_1:
# 34 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 34 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 34 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 38 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_2:
# 38 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 50 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_3:
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
	step_end

# 56 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_4:
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

# 57 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_5:
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 73 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_6:
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
	step_end

# 78 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_7:
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 81 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_8:
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 93 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_9:
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 102 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_10:
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 107 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_11:
# 107 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 107 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 123 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_12:
# 123 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 126 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_13:
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 128 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_14:
# 128 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
# 128 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
	step_end

# 132 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_15:
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 132 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 135 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_16:
# 135 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 142 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_17:
# 142 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 142 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 205 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_0:
# 205 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
# 205 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 212 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_1:
# 212 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 216 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_2:
# 216 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
# 216 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 218 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_3:
# 218 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 223 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_4:
# 223 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 227 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_5:
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 229 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_6:
# 229 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 234 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_7:
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
	step_end

# 244 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_0:
# 244 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 244 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 244 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 244 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 244 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 263 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_1:
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
	step_end

# 270 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_2:
# 270 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
# 270 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
	step_end

# 289 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0:
# 289 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 289 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 296 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0:
# 296 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 296 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 333 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_0:
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 338 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_1:
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_left
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 342 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_2:
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 428 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_3:
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
	step_end

# 430 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_4:
# 430 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 430 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 430 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
	step_end

# 443 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_5:
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 444 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_6:
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 453 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_7:
# 453 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 453 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 458 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_8:
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	shake_horizontal
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	shake_horizontal
	step_end

# 461 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_9:
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
	step_end

# 469 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_10:
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
	step_end

# 474 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_11:
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
	step_end

# 498 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_12:
# 498 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 498 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 504 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_13:
# 504 "data/maps/TapuKokoBridge/scripts.pory"
	emote_question_mark
# 504 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 573 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_14:
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 587 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_15:
# 587 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
# 587 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
	step_end

# 594 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_16:
# 594 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 594 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 594 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 595 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_17:
# 595 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 595 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 595 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

TapuKokoBridge_LillieCosmogEvent_Text_0:
# 109 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Ah…$"

TapuKokoBridge_LillieCosmogEvent_Text_1:
# 110 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What's wrong?$"

TapuKokoBridge_LillieCosmogEvent_Text_2:
# 110 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Who are you?$"

TapuKokoBridge_LillieCosmogEvent_Text_3:
# 113 "data/maps/TapuKokoBridge/scripts.pory"
	.string "H-help…\p"
	.string "Save Nebby!$"

TapuKokoBridge_LillieCosmogEvent_Text_4:
# 130 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pe-e-ew…$"

TapuKokoBridge_LillieCosmogEvent_Text_5:
# 137 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Those Wingull are attacking it!\p"
	.string "But…I'm not a Trainer.\n"
	.string "I can't…$"

TapuKokoBridge_LillieCosmogEvent_Text_6:
# 144 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!\p"
	.string "I'll heal your Pokémon for you, so…$"

TapuKokoBridge_InteractLillie_Text_0:
# 193 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!$"

TapuKokoBridge_Trigger_StartWingullBattle_Text_0:
# 272 "data/maps/TapuKokoBridge/scripts.pory"
	.string "You managed to chase off one of the\n"
	.string "Wingull, but…oh, there are still more!\p"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…\p"
	.string "It looks like that attack may have\n"
	.string "damaged the Plank Bridge, too…$"

TapuKokoBridge_trigger_TryLeave2_Text_0:
# 306 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…\p"
	.string "It looks like that attack may have\n"
	.string "damaged the Plank Bridge, too…$"

TapuKokoBridge_trigger_BridgeShake_Text_0:
# 471 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_1:
# 476 "data/maps/TapuKokoBridge/scripts.pory"
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
# 506 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What…\n"
	.string "What is that?$"

TapuKokoBridge_trigger_BridgeShake_Text_3:
# 516 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_4:
# 518 "data/maps/TapuKokoBridge/scripts.pory"
	.string "A sparkling…stone?\n"
	.string "It feels almost warm somehow…$"

TapuKokoBridge_trigger_BridgeShake_Text_5:
# 523 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please, forgive me…\p"
	.string "I am so grateful to you for helping us\n"
	.string "out of that dangerous spot.$"

TapuKokoBridge_trigger_BridgeShake_Text_6:
# 527 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Are you the kahuna?$"

TapuKokoBridge_trigger_BridgeShake_Text_7:
# 530 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Lillie$"

TapuKokoBridge_trigger_BridgeShake_Text_8:
# 531 "data/maps/TapuKokoBridge/scripts.pory"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_9:
# 536 "data/maps/TapuKokoBridge/scripts.pory"
	.string "No no.\p"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_10:
# 541 "data/maps/TapuKokoBridge/scripts.pory"
	.string "And I suppose…this stone must belong\n"
	.string "to you.$"

TapuKokoBridge_trigger_BridgeShake_Text_11:
# 549 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…\p"
	.string "Don't tell anyone about this…\n"
	.string "About seeing Nebby…\p"
	.string "It's…it's a secret, OK?$"

TapuKokoBridge_trigger_BridgeShake_Text_12:
# 558 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Come on, Into the bag, Nebby.$"

TapuKokoBridge_trigger_BridgeShake_Text_13:
# 564 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew…$"

TapuKokoBridge_trigger_BridgeShake_Text_14:
# 576 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Um…\p"
	.string "I'm worried we might get attacked again\n"
	.string "by some wild Pokémon or…or something.\p"
	.string "I know it's too much for me to ask it,\n"
	.string "but…\p"
	.string "Do you think you could see us back to\n"
	.string "town?$"
