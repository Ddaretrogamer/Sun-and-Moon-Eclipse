TapuKokoBridge_MapScripts::
# 2 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/TapuKokoBridge/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 19 "data/maps/TapuKokoBridge/scripts.pory"
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
	.2byte 0

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 15 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 16 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 17 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgelillie, 21, 30
	return

TapuKokoBridge_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 19 "data/maps/TapuKokoBridge/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 3, TapuKokoBridge_LillieCosmogEvent
	.2byte 0


TapuKokoBridge_LillieCosmogEvent::
# 23 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 24 "data/maps/TapuKokoBridge/scripts.pory"
	special SpawnCameraObject
# 25 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_0
# 26 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 27 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 28 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_1
# 29 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 30 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 31 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 32 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 33 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 34 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 35 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 36 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 37 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 38 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 39 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 40 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 41 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 42 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 43 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 44 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 45 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 46 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 47 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 48 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_4
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_5
# 51 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 52 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 53 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 54 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 55 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_3
# 56 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 57 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 58 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_LEDGE
# 59 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 60 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 61 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 62 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 63 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog
# 64 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 65 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_6
# 67 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 68 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 69 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 70 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull1, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 72 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 73 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull3, TapuKokoBridge_LillieCosmogEvent_Movement_7
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 75 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 76 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 77 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 78 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull1
# 79 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 80 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull3
# 81 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 82 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_HIDE_CIRCLING_WINGULLS
# 83 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull4, MAP_TAPU_KOKO_BRIDGE
# 84 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull5, MAP_TAPU_KOKO_BRIDGE
# 85 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull6, MAP_TAPU_KOKO_BRIDGE
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_9
# 87 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 88 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 89 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 90 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 4
# 91 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 92 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 93 "data/maps/TapuKokoBridge/scripts.pory"
	delay 15
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 95 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_10
# 96 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 97 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 98 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 99 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 100 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_0
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_1, TapuKokoBridge_LillieCosmogEvent_Text_2
# 103 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_2
TapuKokoBridge_LillieCosmogEvent_1:
# 109 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_LillieCosmogEvent_5
TapuKokoBridge_LillieCosmogEvent_4:
# 115 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 116 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 117 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_13
# 119 "data/maps/TapuKokoBridge/scripts.pory"
	delay 240
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 121 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 122 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_4, MSGBOX_AUTOCLOSE
# 123 "data/maps/TapuKokoBridge/scripts.pory"
	delay 120
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, TapuKokoBridge_LillieCosmogEvent_Movement_15
# 125 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 126 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 127 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 128 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 129 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_5, MSGBOX_AUTOCLOSE
# 133 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 134 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_17
# 135 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 136 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_6, MSGBOX_AUTOCLOSE
# 141 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 142 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 143 "data/maps/TapuKokoBridge/scripts.pory"
	special HealPlayerParty
# 144 "data/maps/TapuKokoBridge/scripts.pory"
	playfanfare MUS_HEAL
# 145 "data/maps/TapuKokoBridge/scripts.pory"
	waitfanfare
# 146 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 147 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 148 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 149 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 150 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_LillieCosmogEvent_2:
# 105 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_1

TapuKokoBridge_LillieCosmogEvent_5:
# 111 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_LillieCosmogEvent_Text_3, MSGBOX_AUTOCLOSE
	goto TapuKokoBridge_LillieCosmogEvent_4


TapuKokoBridge_InteractLillie::
# 155 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 156 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 157 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0
# 160 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_TryLeave::
# 165 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 166 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 167 "data/maps/TapuKokoBridge/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 168 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_2, 29
	goto_if_eq TapuKokoBridge_trigger_TryLeave_2
TapuKokoBridge_trigger_TryLeave_1:
# 179 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 19
	goto_if_eq TapuKokoBridge_trigger_TryLeave_5
TapuKokoBridge_trigger_TryLeave_4:
# 190 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_TEMP_1, 23
	goto_if_eq TapuKokoBridge_trigger_TryLeave_8
TapuKokoBridge_trigger_TryLeave_7:
# 201 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end

TapuKokoBridge_trigger_TryLeave_2:
# 169 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_0
# 170 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 171 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 172 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 173 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 177 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_1

TapuKokoBridge_trigger_TryLeave_5:
# 180 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 181 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 182 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 183 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 184 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 187 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_4
# 188 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_4

TapuKokoBridge_trigger_TryLeave_8:
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_5
# 192 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 193 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_6
# 194 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 195 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_InteractLillie_Text_0, MSGBOX_AUTOCLOSE
# 198 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_7
# 199 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
	goto TapuKokoBridge_trigger_TryLeave_7


TapuKokoBridge_Trigger_StartWingullBattle::
# 206 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 207 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgewingull2
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_0
# 209 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 210 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 211 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 212 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_WINGULL, 0
# 213 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 214 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_LillieCosmogEvent_Movement_8
# 215 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 216 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_CATCHING
# 217 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_NO_WILD_RUNNING
# 218 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_FORCE_NO_SHINY
# 219 "data/maps/TapuKokoBridge/scripts.pory"
	setwildbattle SPECIES_WINGULL, 3, 0, FALSE
# 220 "data/maps/TapuKokoBridge/scripts.pory"
	dowildbattle
# 221 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_CATCHING
# 222 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_NO_WILD_RUNNING
# 223 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_FORCE_NO_SHINY
# 224 "data/maps/TapuKokoBridge/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 225 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq TapuKokoBridge_Trigger_StartWingullBattle_1
	return

TapuKokoBridge_Trigger_StartWingullBattle_1:
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgewingull2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_1
# 228 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 229 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgewingull2
# 230 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 231 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull2
# 232 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 5
# 233 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 235 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 236 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_Trigger_StartWingullBattle_Text_0, MSGBOX_AUTOCLOSE
# 245 "data/maps/TapuKokoBridge/scripts.pory"
	waitmessage
# 246 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end


TapuKokoBridge_Trigger_StartWingullBattleleft::
# 252 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 253 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0
# 254 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 255 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_Trigger_StartWingullBattleRight::
# 259 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0
# 261 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 262 "data/maps/TapuKokoBridge/scripts.pory"
	call TapuKokoBridge_Trigger_StartWingullBattle
	return


TapuKokoBridge_trigger_TryLeave2::
# 266 "data/maps/TapuKokoBridge/scripts.pory"
	lock
# 267 "data/maps/TapuKokoBridge/scripts.pory"
	faceplayer
# 268 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 269 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 270 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_TryLeave2_Text_0, MSGBOX_AUTOCLOSE
# 273 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_1
# 274 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 275 "data/maps/TapuKokoBridge/scripts.pory"
	release
	end


TapuKokoBridge_trigger_BridgeShake::
# 280 "data/maps/TapuKokoBridge/scripts.pory"
	lockplayer
# 281 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 282 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 283 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 284 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 285 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 286 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 287 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_0
# 289 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement LOCALID_PLAYER
# 290 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog, MAP_TAPU_KOKO_BRIDGE
# 291 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_COSMOG
# 292 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8004, 2
# 293 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8005, 6
# 294 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8006, 4
# 295 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_0x8007, 4
# 296 "data/maps/TapuKokoBridge/scripts.pory"
	special ShakeCamera
# 297 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 298 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 300 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 301 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 302 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 21, 20, 0
# 303 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 304 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 306 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 307 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_2
# 308 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 309 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 310 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 3
# 311 "data/maps/TapuKokoBridge/scripts.pory"
	delay 20
# 312 "data/maps/TapuKokoBridge/scripts.pory"
	special RemoveCameraObject
# 314 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_ORB
# 315 "data/maps/TapuKokoBridge/scripts.pory"
	special DoOrbEffect
# 316 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 317 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreen FADE_TO_BLACK
# 318 "data/maps/TapuKokoBridge/scripts.pory"
	special FadeOutOrbEffect
# 319 "data/maps/TapuKokoBridge/scripts.pory"
	waitstate
# 320 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BANG
# 321 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 322 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_MAHALO_BRIDGE_BROKEN
# 323 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
# 324 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 25, METATILE_TapuKokoBridge_Water, TRUE
# 325 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 25, METATILE_TapuKokoBridge_Water, TRUE
# 326 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 25, METATILE_TapuKokoBridge_Water, TRUE
# 327 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 24, METATILE_TapuKokoBridge_Water, TRUE
# 328 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 24, METATILE_TapuKokoBridge_Water, TRUE
# 329 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 24, METATILE_TapuKokoBridge_Water, TRUE
# 330 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 23, METATILE_TapuKokoBridge_Water, TRUE
# 331 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 23, METATILE_TapuKokoBridge_Water, TRUE
# 332 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 23, METATILE_TapuKokoBridge_Water, TRUE
# 333 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 22, METATILE_TapuKokoBridge_Water, TRUE
# 334 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 22, METATILE_TapuKokoBridge_Water, TRUE
# 335 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 22, METATILE_TapuKokoBridge_Water, TRUE
# 336 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 21, METATILE_TapuKokoBridge_Water, TRUE
# 337 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 21, METATILE_TapuKokoBridge_Water, TRUE
# 338 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 21, METATILE_TapuKokoBridge_Water, TRUE
# 339 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 20, METATILE_TapuKokoBridge_Water, TRUE
# 340 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 20, METATILE_TapuKokoBridge_Water, TRUE
# 341 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 20, METATILE_TapuKokoBridge_Water, TRUE
# 342 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, METATILE_TapuKokoBridge_Water, TRUE
# 343 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 14, 0x03E, TRUE
# 344 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 14, 0x03E, TRUE
# 345 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 14, 0x03E, TRUE
# 346 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 15, 0x03E, TRUE
# 347 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 15, 0x03E, TRUE
# 348 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 15, 0x03E, TRUE
# 349 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 16, 0x03E, TRUE
# 350 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 16, 0x03E, TRUE
# 351 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 17, 0x03E, TRUE
# 352 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 16, 0x14F, TRUE
# 353 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 17, 0x14F, TRUE
# 354 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 18, 0x14F, TRUE
# 355 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 17, 0x03F, TRUE
# 356 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 18, 0x03F, TRUE
# 357 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 22, 19, 0x924, TRUE
# 358 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 18, 0x03E, TRUE
# 359 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 21, 19, 0x03E, TRUE
# 360 "data/maps/TapuKokoBridge/scripts.pory"
	setmetatile 20, 19, 0x03E, TRUE
# 361 "data/maps/TapuKokoBridge/scripts.pory"
	special DrawWholeMapView
# 362 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull4
# 363 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull5
# 364 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgewingull6
# 365 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_FLYOVER_WINGULLS
# 366 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 367 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 368 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 369 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 370 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_LillieCosmogEvent_Movement_11
# 371 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_1
# 373 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 374 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_2
# 375 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_FALL
# 376 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 377 "data/maps/TapuKokoBridge/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 378 "data/maps/TapuKokoBridge/scripts.pory"
	delay 60
# 379 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreen FADE_TO_BLACK
# 380 "data/maps/TapuKokoBridge/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_TAPU_KOKO_BRIDGE
# 381 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgetapukoko, 21, 27
# 382 "data/maps/TapuKokoBridge/scripts.pory"
	addobject bridgecosmog2, MAP_TAPU_KOKO_BRIDGE
# 383 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectxy bridgecosmog2, 20, 30
# 384 "data/maps/TapuKokoBridge/scripts.pory"
	setobjectmovementtype bridgecosmog2, MOVEMENT_TYPE_NONE
# 385 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 386 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_3
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_4
# 389 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 390 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 391 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 392 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_IKITOWN_STATE, 6
# 393 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 394 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_LillieCosmogEvent_Movement_14
# 395 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 396 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_5
# 398 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_5
# 399 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 400 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 401 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 402 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 403 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_FLY
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgetapukoko, TapuKokoBridge_trigger_BridgeShake_Movement_6
# 405 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 406 "data/maps/TapuKokoBridge/scripts.pory"
	delay 39
# 407 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_6
# 408 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_TryLeave_Movement_3
# 409 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 410 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 411 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_7
# 412 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 414 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 415 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 416 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_8
# 417 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 418 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_1
# 440 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_trigger_BridgeShake_Movement_9
# 441 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 442 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_0, MSGBOX_AUTOCLOSE
# 443 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 444 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 445 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 446 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_10
# 447 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 448 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_2, MSGBOX_AUTOCLOSE
# 450 "data/maps/TapuKokoBridge/scripts.pory"
	setvar VAR_RESULT, 1
# 451 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_M_DETECT
# 452 "data/maps/TapuKokoBridge/scripts.pory"
	dofieldeffectsparkle 23, 30, 0
# 453 "data/maps/TapuKokoBridge/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 454 "data/maps/TapuKokoBridge/scripts.pory"
	closemessage
# 455 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_LillieCosmogEvent_Movement_12
# 456 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 457 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_3, MSGBOX_AUTOCLOSE
# 459 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_4, MSGBOX_AUTOCLOSE
# 462 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_PIN
# 463 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_2
# 464 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 465 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_5
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, TapuKokoBridge_LillieCosmogEvent_Text_2, TapuKokoBridge_trigger_BridgeShake_Text_6
# 470 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_2
TapuKokoBridge_trigger_BridgeShake_1:
# 475 "data/maps/TapuKokoBridge/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq TapuKokoBridge_trigger_BridgeShake_5
TapuKokoBridge_trigger_BridgeShake_4:
# 482 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 483 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_10, MSGBOX_AUTOCLOSE
# 485 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 486 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 487 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_TryLeave_Movement_7
# 488 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 489 "data/maps/TapuKokoBridge/scripts.pory"
	finditem ITEM_Z_POWER_RING, 1
# 490 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 491 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_11, MSGBOX_AUTOCLOSE
# 497 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_LillieCosmogEvent_Movement_16
# 498 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 499 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 500 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_12, MSGBOX_AUTOCLOSE
# 501 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 502 "data/maps/TapuKokoBridge/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 503 "data/maps/TapuKokoBridge/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 504 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgecosmog2, TapuKokoBridge_Trigger_StartWingullBattle_Movement_2
# 505 "data/maps/TapuKokoBridge/scripts.pory"
	waitmoncry
# 506 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_13, MSGBOX_AUTOCLOSE
# 507 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgecosmog2
# 508 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 509 "data/maps/TapuKokoBridge/scripts.pory"
	playse SE_BALL_OPEN
# 510 "data/maps/TapuKokoBridge/scripts.pory"
	removeobject bridgecosmog2
# 511 "data/maps/TapuKokoBridge/scripts.pory"
	waitse
# 512 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 513 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_11
# 515 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement bridgelillie
# 516 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 517 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_14
# 527 "data/maps/TapuKokoBridge/scripts.pory"
	delay 30
# 528 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement bridgelillie, TapuKokoBridge_trigger_BridgeShake_Movement_12
# 529 "data/maps/TapuKokoBridge/scripts.pory"
	applymovement LOCALID_PLAYER, TapuKokoBridge_trigger_BridgeShake_Movement_13
# 530 "data/maps/TapuKokoBridge/scripts.pory"
	waitmovement 0
# 531 "data/maps/TapuKokoBridge/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 532 "data/maps/TapuKokoBridge/scripts.pory"
	setflag FLAG_HIDE_BRIDGE_LILLIE
# 533 "data/maps/TapuKokoBridge/scripts.pory"
	warp MAP_IKI_TOWN, 5
# 534 "data/maps/TapuKokoBridge/scripts.pory"
	release
# 535 "data/maps/TapuKokoBridge/scripts.pory"
	releaseplayer
	end

TapuKokoBridge_trigger_BridgeShake_2:
# 472 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_8
	goto TapuKokoBridge_trigger_BridgeShake_1

TapuKokoBridge_trigger_BridgeShake_5:
# 477 "data/maps/TapuKokoBridge/scripts.pory"
	speakername TapuKokoBridge_trigger_BridgeShake_Text_7
# 478 "data/maps/TapuKokoBridge/scripts.pory"
	msgbox TapuKokoBridge_trigger_BridgeShake_Text_9
	goto TapuKokoBridge_trigger_BridgeShake_4


TapuKokoBridge_SetBrokenBridge::
# 540 "data/maps/TapuKokoBridge/scripts.pory"
	setmaplayoutindex LAYOUT_TAPU_KOKO_BRIDGE_BROKEN
	return


# 25 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_0:
# 25 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 25 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 27 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_1:
# 27 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 27 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 27 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 31 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_2:
# 31 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 43 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_3:
# 43 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
# 43 "data/maps/TapuKokoBridge/scripts.pory"
	jump_in_place_up
	step_end

# 49 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_4:
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 49 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 50 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_5:
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 50 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 66 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_6:
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
# 66 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_up
	step_end

# 71 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_7:
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 71 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 74 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_8:
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 74 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
	step_end

# 86 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_9:
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 86 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 94 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_10:
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 94 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 99 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_11:
# 99 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 99 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 115 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_12:
# 115 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 118 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_13:
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
# 118 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 120 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_14:
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
# 120 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_down
	step_end

# 124 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_15:
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 124 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 127 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_16:
# 127 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 134 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_LillieCosmogEvent_Movement_17:
# 134 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 134 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 169 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_0:
# 169 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
# 169 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 176 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_1:
# 176 "data/maps/TapuKokoBridge/scripts.pory"
	walk_up
	step_end

# 180 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_2:
# 180 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
# 180 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 182 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_3:
# 182 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 187 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_4:
# 187 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 191 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_5:
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
# 191 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
	step_end

# 193 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_6:
# 193 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 198 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_TryLeave_Movement_7:
# 198 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
	step_end

# 208 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_0:
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
# 208 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_down
	step_end

# 227 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_1:
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
# 227 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_right
	step_end

# 234 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattle_Movement_2:
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
# 234 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_up
	step_end

# 253 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleleft_Movement_0:
# 253 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 253 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 260 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_Trigger_StartWingullBattleRight_Movement_0:
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 260 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 288 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_0:
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
# 288 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_up
	step_end

# 372 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_1:
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
# 372 "data/maps/TapuKokoBridge/scripts.pory"
	walk_faster_left
	step_end

# 374 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_2:
# 374 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 374 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
# 374 "data/maps/TapuKokoBridge/scripts.pory"
	slide_down
	step_end

# 387 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_3:
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	walk_fast_down
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	walk_left
# 387 "data/maps/TapuKokoBridge/scripts.pory"
	face_right
	step_end

# 388 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_4:
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 388 "data/maps/TapuKokoBridge/scripts.pory"
	face_left
	step_end

# 397 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_5:
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	emote_exclamation_mark
# 397 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 404 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_6:
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
# 404 "data/maps/TapuKokoBridge/scripts.pory"
	slide_up
	step_end

# 411 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_7:
# 411 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
# 411 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_right
	step_end

# 416 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_8:
# 416 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
# 416 "data/maps/TapuKokoBridge/scripts.pory"
	walk_in_place_left
	step_end

# 440 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_9:
# 440 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
# 440 "data/maps/TapuKokoBridge/scripts.pory"
	walk_right
	step_end

# 446 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_10:
# 446 "data/maps/TapuKokoBridge/scripts.pory"
	emote_question_mark
# 446 "data/maps/TapuKokoBridge/scripts.pory"
	face_down
	step_end

# 514 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_11:
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 514 "data/maps/TapuKokoBridge/scripts.pory"
	face_up
	step_end

# 528 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_12:
# 528 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 528 "data/maps/TapuKokoBridge/scripts.pory"
	delay_16
# 528 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

# 529 "data/maps/TapuKokoBridge/scripts.pory"
TapuKokoBridge_trigger_BridgeShake_Movement_13:
# 529 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 529 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
# 529 "data/maps/TapuKokoBridge/scripts.pory"
	walk_down
	step_end

TapuKokoBridge_LillieCosmogEvent_Text_0:
# 101 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Ah…$"

TapuKokoBridge_LillieCosmogEvent_Text_1:
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What's wrong?$"

TapuKokoBridge_LillieCosmogEvent_Text_2:
# 102 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Who are you?$"

TapuKokoBridge_LillieCosmogEvent_Text_3:
# 105 "data/maps/TapuKokoBridge/scripts.pory"
	.string "H-help…\p"
	.string "Save Nebby!$"

TapuKokoBridge_LillieCosmogEvent_Text_4:
# 122 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pe-e-ew…$"

TapuKokoBridge_LillieCosmogEvent_Text_5:
# 129 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Those Wingull are attacking it!\p"
	.string "But…I'm not a Trainer.\n"
	.string "I can't…$"

TapuKokoBridge_LillieCosmogEvent_Text_6:
# 136 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!\p"
	.string "I'll heal your Pokémon for you, so…$"

TapuKokoBridge_InteractLillie_Text_0:
# 157 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please!\p"
	.string "Please save Nebby!$"

TapuKokoBridge_Trigger_StartWingullBattle_Text_0:
# 236 "data/maps/TapuKokoBridge/scripts.pory"
	.string "You managed to chase off one of the\n"
	.string "Wingull, but…oh, there are still more!\p"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…\p"
	.string "It looks like that attack may have\n"
	.string "damaged the Plank Bridge, too…$"

TapuKokoBridge_trigger_TryLeave2_Text_0:
# 270 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…please help Nebby if you can!\p"
	.string "But be careful…$"

TapuKokoBridge_trigger_BridgeShake_Text_0:
# 413 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_1:
# 418 "data/maps/TapuKokoBridge/scripts.pory"
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
# 448 "data/maps/TapuKokoBridge/scripts.pory"
	.string "What…\n"
	.string "What is that?$"

TapuKokoBridge_trigger_BridgeShake_Text_3:
# 458 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew pew!$"

TapuKokoBridge_trigger_BridgeShake_Text_4:
# 460 "data/maps/TapuKokoBridge/scripts.pory"
	.string "A sparkling…stone?\n"
	.string "It feels almost warm somehow…$"

TapuKokoBridge_trigger_BridgeShake_Text_5:
# 465 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please, forgive me…\p"
	.string "I am so grateful to you for helping us\n"
	.string "out of that dangerous spot.$"

TapuKokoBridge_trigger_BridgeShake_Text_6:
# 469 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Are you the kahuna?$"

TapuKokoBridge_trigger_BridgeShake_Text_7:
# 472 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Lillie$"

TapuKokoBridge_trigger_BridgeShake_Text_8:
# 473 "data/maps/TapuKokoBridge/scripts.pory"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_9:
# 478 "data/maps/TapuKokoBridge/scripts.pory"
	.string "No no.\p"
	.string "I'm…I'm Lillie.$"

TapuKokoBridge_trigger_BridgeShake_Text_10:
# 483 "data/maps/TapuKokoBridge/scripts.pory"
	.string "And I suppose…this stone must belong\n"
	.string "to you.$"

TapuKokoBridge_trigger_BridgeShake_Text_11:
# 491 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Please…\p"
	.string "Don't tell anyone about this…\n"
	.string "About seeing Nebby…\p"
	.string "It's…it's a secret, OK?$"

TapuKokoBridge_trigger_BridgeShake_Text_12:
# 500 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Come on, Into the bag, Nebby.$"

TapuKokoBridge_trigger_BridgeShake_Text_13:
# 506 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Pew…$"

TapuKokoBridge_trigger_BridgeShake_Text_14:
# 517 "data/maps/TapuKokoBridge/scripts.pory"
	.string "Um…\p"
	.string "I'm worried we might get attacked again\n"
	.string "by some wild Pokémon or…or something.\p"
	.string "I know it's too much for me to ask it,\n"
	.string "but…\p"
	.string "Do you think you could see us back to\n"
	.string "town?$"
