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
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_6
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
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
	endcutscene
# 158 "data/maps/TapuKokoBridge/scripts.pory"
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


TapuKokoBridge_LillieCosmogSkip::
# 163 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 164 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 165 "data/maps/TapuKokoBridge/scripts.pory"
	special CloseScriptMenus
# 166 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 28
# 167 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 168 "data/maps/TapuKokoBridge/scripts.pory"
	special SnapCameraToPlayer
# 169 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 170 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 171 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 172 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgelillie, 22, 27
# 173 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog, 21, 20
# 174 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull1
# 175 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull3
# 177 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull4, MAP_TAPU_KOKO_BRIDGE
# 178 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull5, MAP_TAPU_KOKO_BRIDGE
# 179 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull6, MAP_TAPU_KOKO_BRIDGE
# 180 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 181 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_HIDE_CIRCLING_WINGULLS
# 182 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 4
# 183 "data/maps/TapuKokoBridge/scripts.pory"
	special HealPlayerParty
# 184 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 185 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_InteractLillie::
# 190 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 192 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 195 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_TryLeave::
# 200 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 201 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 202 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 203 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_2, 29
	goto_if_eq TapuKokoBridge_trigger_TryLeave_2
TapuKokoBridge_trigger_TryLeave_1:
# 214 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 19
	goto_if_eq TapuKokoBridge_trigger_TryLeave_5
TapuKokoBridge_trigger_TryLeave_4:
# 225 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 23
	goto_if_eq TapuKokoBridge_trigger_TryLeave_8
TapuKokoBridge_trigger_TryLeave_7:
# 236 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_trigger_TryLeave_2:
# 204 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_0
# 205 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 206 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 207 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 211 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 212 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_1

TapuKokoBridge_trigger_TryLeave_5:
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 216 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 217 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 218 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 219 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 222 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_4
# 223 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_4

TapuKokoBridge_trigger_TryLeave_8:
# 226 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_5
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 228 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_6
# 229 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 230 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 233 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_7
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_7


TapuKokoBridge_Trigger_StartWingullBattle::
# 241 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 242 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull2
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_0
# 244 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 245 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 246 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 247 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 248 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 249 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 250 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 251 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_CATCHING
# 252 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_RUNNING
# 253 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_FORCE_NO_SHINY
# 254 "data/maps/TapuKokoBridge/scripts.pory"
	setwildbattle SPECIES_WINGULL, 3, 0, FALSE
# 255 "data/maps/TapuKokoBridge/scripts.pory"
	dowildbattle
# 256 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_CATCHING
# 257 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_RUNNING
# 258 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_FORCE_NO_SHINY
# 259 "data/maps/TapuKokoBridge/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq TapuKokoBridge_Trigger_StartWingullBattle_1
	return

TapuKokoBridge_Trigger_StartWingullBattle_1:
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_1
# 263 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 264 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 265 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 266 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 267 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 5
# 268 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 269 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 270 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 271 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_Trigger_StartWingullBattle_Text_0, MSGBOX_AUTOCLOSE
# 280 "data/maps/TapuKokoBridge/scripts.pory"
	waitmessage
# 281 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end


TapuKokoBridge_Trigger_StartWingullBattleleft::
# 287 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0
# 289 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 290 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_Trigger_StartWingullBattleRight::
# 294 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 295 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0
# 296 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_trigger_TryLeave2::
# 301 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 302 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 304 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 305 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_TryLeave2_Text_0, MSGBOX_AUTOCLOSE
# 311 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 313 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_BridgeShake::
# 318 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 319 "data/maps/TapuKokoBridge/scripts.pory"
	startcutscene CUTSCENE_TAPUKOKO_BRIDGE_SHAKE
# 320 "data/maps/TapuKokoBridge/scripts.pory"
	special ShowCutsceneCinematicBars
# 321 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 322 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 323 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 324 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 325 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 326 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 327 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 328 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 329 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 330 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 20
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_2
TapuKokoBridge_trigger_BridgeShake_1:
# 335 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 22
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_5
TapuKokoBridge_trigger_BridgeShake_4:
# 340 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 21
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_8
TapuKokoBridge_trigger_BridgeShake_7:
# 344 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 345 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_COSMOG
# 346 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 347 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 348 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 349 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 350 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 351 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 352 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 354 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 355 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 356 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 21, 20, 0
# 357 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 358 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 360 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 361 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 362 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 363 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 364 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 3
# 365 "data/maps/TapuKokoBridge/scripts.pory"
	delay 20
# 366 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 368 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_ORB
# 369 "data/maps/TapuKokoBridge/scripts.pory"
	special DoOrbEffect
# 370 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 371 "data/maps/TapuKokoBridge/scripts.pory"
	special OrbFadeToBlack
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 374 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 375 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BANG
# 376 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 377 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_MAHALO_BRIDGE_BROKEN
# 378 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
# 379 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 25, METATILE_TapuKokoBridge_Water, TRUE
# 380 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 25, METATILE_TapuKokoBridge_Water, TRUE
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 25, METATILE_TapuKokoBridge_Water, TRUE
# 382 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 24, METATILE_TapuKokoBridge_Water, TRUE
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 24, METATILE_TapuKokoBridge_Water, TRUE
# 384 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 24, METATILE_TapuKokoBridge_Water, TRUE
# 385 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 23, METATILE_TapuKokoBridge_Water, TRUE
# 386 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 23, METATILE_TapuKokoBridge_Water, TRUE
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 23, METATILE_TapuKokoBridge_Water, TRUE
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 22, METATILE_TapuKokoBridge_Water, TRUE
# 389 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 22, METATILE_TapuKokoBridge_Water, TRUE
# 390 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 22, METATILE_TapuKokoBridge_Water, TRUE
# 391 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 21, METATILE_TapuKokoBridge_Water, TRUE
# 392 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 21, METATILE_TapuKokoBridge_Water, TRUE
# 393 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 21, METATILE_TapuKokoBridge_Water, TRUE
# 394 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 20, METATILE_TapuKokoBridge_Water, TRUE
# 395 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 20, METATILE_TapuKokoBridge_Water, TRUE
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 20, METATILE_TapuKokoBridge_Water, TRUE
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, METATILE_TapuKokoBridge_Water, TRUE
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 14, 0x03E, TRUE
# 399 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 14, 0x03E, TRUE
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 14, 0x03E, TRUE
# 401 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 15, 0x03E, TRUE
# 402 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 15, 0x03E, TRUE
# 403 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 15, 0x03E, TRUE
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 16, 0x03E, TRUE
# 405 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 16, 0x03E, TRUE
# 406 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 17, 0x03E, TRUE
# 407 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 16, 0x14F, TRUE
# 408 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 17, 0x14F, TRUE
# 409 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 18, 0x14F, TRUE
# 410 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 17, 0x03F, TRUE
# 411 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 18, 0x03F, TRUE
# 412 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, 0x924, TRUE
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 18, 0x03E, TRUE
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 19, 0x03E, TRUE
# 415 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 19, 0x03E, TRUE
# 416 "data/maps/TapuKokoBridge/scripts.pory"
	special DrawWholeMapView
# 417 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull4
# 418 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull5
# 419 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull6
# 420 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 421 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 422 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 423 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 424 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 425 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 426 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_3
# 428 "data/maps/TapuKokoBridge/scripts.pory"
	delay 28
# 429 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_4
# 430 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_FALL
# 431 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 432 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 433 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 434 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 435 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 436 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgetapukoko, 21, 27
# 437 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgecosmog2, MAP_TAPU_KOKO_BRIDGE
# 438 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog2, 20, 30
# 439 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectmovementtype bridgecosmog2, MOVEMENT_TYPE_NONE
# 440 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 441 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_5
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_6
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 445 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 446 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 447 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 6
# 448 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 449 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 450 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 451 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 452 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 453 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 454 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 455 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 456 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 457 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_8
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 459 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_9
# 461 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 462 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 463 "data/maps/TapuKokoBridge/scripts.pory"
	delay 39
# 464 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_6
# 465 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 466 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 467 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_10
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 470 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 471 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 472 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_11
# 474 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 475 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_1
# 497 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_12
# 498 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 499 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 500 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 501 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 502 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 503 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_13
# 504 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 505 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_2, MSGBOX_AUTOCLOSE
# 507 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 508 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 509 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 23, 30, 0
# 510 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 511 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 512 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 513 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 515 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_3, MSGBOX_AUTOCLOSE
# 516 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 517 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_4, MSGBOX_AUTOCLOSE
# 519 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 520 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 521 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 522 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_5
# 526 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_2, TapuKokoBridge_trigger_BridgeShake_Text_6
# 527 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_11
TapuKokoBridge_trigger_BridgeShake_10:
# 532 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_14
TapuKokoBridge_trigger_BridgeShake_13:
# 539 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 540 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_10, MSGBOX_AUTOCLOSE
# 542 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 543 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 544 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_7
# 545 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 546 "data/maps/TapuKokoBridge/scripts.pory"
	giveitem ITEM_SPARKLING_STONE, 1
# 547 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 548 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_11, MSGBOX_AUTOCLOSE
# 554 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 555 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 556 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 557 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_12, MSGBOX_AUTOCLOSE
# 558 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 559 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 560 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 561 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 562 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 563 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_13, MSGBOX_AUTOCLOSE
# 564 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 565 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 566 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 567 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog2
# 568 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 569 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 570 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 571 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_14
# 573 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 574 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 575 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_14, MSGBOX_AUTOCLOSE
# 585 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 586 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_15
# 587 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 588 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 589 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 590 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 591 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 592 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 593 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_16
# 594 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_17
# 595 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 596 "data/maps/TapuKokoBridge/scripts.pory"
	endcutscene
# 597 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 598 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_LILLIE
# 599 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 600 "data/maps/TapuKokoBridge/scripts.pory"
	warp MAP_IKI_TOWN, 5
# 601 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 602 "data/maps/TapuKokoBridge/scripts.pory"
	release
# 603 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end

TapuKokoBridge_trigger_BridgeShake_2:
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_0
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_1

TapuKokoBridge_trigger_BridgeShake_5:
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_1
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_4

TapuKokoBridge_trigger_BridgeShake_8:
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_2
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_BridgeShake_7

TapuKokoBridge_trigger_BridgeShake_11:
# 529 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 530 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_8
	goto TapuKokoBridge_trigger_BridgeShake_10

TapuKokoBridge_trigger_BridgeShake_14:
# 534 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 535 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_9
	goto TapuKokoBridge_trigger_BridgeShake_13


TapuKokoBridge_BridgeShakeSkip::
# 608 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 609 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 610 "data/maps/TapuKokoBridge/scripts.pory"
	special CloseScriptMenus
# 611 "data/maps/TapuKokoBridge/scripts.pory"
	special HideCutsceneCinematicBars
# 612 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_MAHALO_BRIDGE_BROKEN
# 613 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_COSMOG
# 614 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 615 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 6
# 616 "data/maps/TapuKokoBridge/scripts.pory"
	checkitem ITEM_SPARKLING_STONE, 1
# 617 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TapuKokoBridge_BridgeShakeSkip_2
TapuKokoBridge_BridgeShakeSkip_1:
# 620 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_LILLIE
# 621 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 622 "data/maps/TapuKokoBridge/scripts.pory"
	warp MAP_IKI_TOWN, 5
# 623 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 624 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end

TapuKokoBridge_BridgeShakeSkip_2:
# 618 "data/maps/TapuKokoBridge/scripts.pory"
	additem ITEM_SPARKLING_STONE, 1
	goto TapuKokoBridge_BridgeShakeSkip_1


TapuKokoBridge_SetBrokenBridge::
# 629 "data/maps/TapuKokoBridge/scripts.pory"
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
	walk_fast_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
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

# 204 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_0:
# 204 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
# 204 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 211 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_1:
# 211 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 215 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_2:
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 217 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_3:
# 217 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 222 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_4:
# 222 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 226 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_5:
# 226 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
# 226 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 228 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_6:
# 228 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 233 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_7:
# 233 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
	step_end

# 243 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_0:
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 243 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 262 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_1:
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
	step_end

# 269 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_2:
# 269 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
# 269 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
	step_end

# 288 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0:
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 295 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0:
# 295 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 295 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 332 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_0:
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 337 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_1:
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_left
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 341 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_2:
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 427 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_3:
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 427 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
	step_end

# 429 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_4:
# 429 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 429 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 429 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
	step_end

# 442 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_5:
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 443 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_6:
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 452 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_7:
# 452 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 452 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 457 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_8:
# 457 "data/maps/TapuKokoBridge/scripts.pory"
	shake_horizontal
# 457 "data/maps/TapuKokoBridge/scripts.pory"
	shake_horizontal
	step_end

# 460 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_9:
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
	step_end

# 468 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_10:
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
# 468 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
	step_end

# 473 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_11:
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
	step_end

# 497 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_12:
# 497 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 497 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 503 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_13:
# 503 "data/maps/TapuKokoBridge/scripts.pory"
	emote_question_mark
# 503 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 572 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_14:
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 572 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 586 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_15:
# 586 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
# 586 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_down
	step_end

# 593 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_16:
# 593 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 593 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 593 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 594 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_17:
# 594 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 594 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 594 "data/maps/TapuKokoBridge/scripts.pory"
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
# 192 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!$"

TapuKokoBridge_Trigger_StartWingullBattle_Text_0:
# 271 "data/maps/TapuKokoBridge/scripts.pory"
	.string "You managed to chase off one of the\n"
	.string "Wingull, but…oh, there are still more!\p"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…\p"
	.string "It looks like that attack may have\n"
	.string "damaged the Plank Bridge, too…$"

TapuKokoBridge_trigger_TryLeave2_Text_0:
# 305 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…\p"
	.string "It looks like that attack may have\n"
	.string "damaged the Plank Bridge, too…$"

TapuKokoBridge_trigger_BridgeShake_Text_0:
# 470 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_1:
# 475 "data/maps/TapuKokoBridge/scripts.pory"
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
# 505 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What…\n"
	.string "What is that?$"

TapuKokoBridge_trigger_BridgeShake_Text_3:
# 515 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_4:
# 517 "data/maps/TapuKokoBridge/scripts.pory"
	.string "A sparkling…stone?\n"
	.string "It feels almost warm somehow…$"

TapuKokoBridge_trigger_BridgeShake_Text_5:
# 522 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please, forgive me…\p"
	.string "I am so grateful to you for helping us\n"
	.string "out of that dangerous spot.$"

TapuKokoBridge_trigger_BridgeShake_Text_6:
# 526 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Are you the kahuna?$"

TapuKokoBridge_trigger_BridgeShake_Text_7:
# 529 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Lillie$"

TapuKokoBridge_trigger_BridgeShake_Text_8:
# 530 "data/maps/TapuKokoBridge/scripts.pory"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_9:
# 535 "data/maps/TapuKokoBridge/scripts.pory"
	.string "No no.\p"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_10:
# 540 "data/maps/TapuKokoBridge/scripts.pory"
	.string "And I suppose…this stone must belong\n"
	.string "to you.$"

TapuKokoBridge_trigger_BridgeShake_Text_11:
# 548 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…\p"
	.string "Don't tell anyone about this…\n"
	.string "About seeing Nebby…\p"
	.string "It's…it's a secret, OK?$"

TapuKokoBridge_trigger_BridgeShake_Text_12:
# 557 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Come on, Into the bag, Nebby.$"

TapuKokoBridge_trigger_BridgeShake_Text_13:
# 563 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew…$"

TapuKokoBridge_trigger_BridgeShake_Text_14:
# 575 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Um…\p"
	.string "I'm worried we might get attacked again\n"
	.string "by some wild Pokémon or…or something.\p"
	.string "I know it's too much for me to ask it,\n"
	.string "but…\p"
	.string "Do you think you could see us back to\n"
	.string "town?$"
