IkiTown_MapScripts::
# 2 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 29 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 39 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 11 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 19 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
# 8 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 12 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
# 16 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 20 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
# 24 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LITTEN )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 5 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 13 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 21 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 29 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 6, IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 30 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 31 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_HALA
# 32 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 33 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 23, 5
# 34 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 35 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 32, 19
# 36 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 37 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 9, 14
	return

IkiTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 39 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 6, Ikitown_GetPokedex
# 40 "data/maps/IkiTown/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 13, Ikitown_StartFestival
	.2byte 0


Ikitown_Trigger_FestivalBattleleft::
# 44 "data/maps/IkiTown/scripts.pory"
	lock
# 45 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 46 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 47 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 48 "data/maps/IkiTown/scripts.pory"
	delay 30
# 49 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_1
# 50 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 51 "data/maps/IkiTown/scripts.pory"
	call Ikitown_Trigger_FestivalBattle
	return


Ikitown_Trigger_FestivalBattleRight::
# 55 "data/maps/IkiTown/scripts.pory"
	lock
# 56 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 57 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 58 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 59 "data/maps/IkiTown/scripts.pory"
	delay 30
# 60 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleRight_Movement_0
# 61 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 62 "data/maps/IkiTown/scripts.pory"
	call Ikitown_Trigger_FestivalBattle
	return


Ikitown_Trigger_FestivalBattleMiddle::
# 66 "data/maps/IkiTown/scripts.pory"
	lock
# 67 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 68 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 69 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 70 "data/maps/IkiTown/scripts.pory"
	delay 30
# 71 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattleMiddle_Movement_0
# 72 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 73 "data/maps/IkiTown/scripts.pory"
	call Ikitown_Trigger_FestivalBattle
	return


Ikitown_Trigger_FestivalBattle::
# 77 "data/maps/IkiTown/scripts.pory"
	delay 30
# 78 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_1
# 79 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 80 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 81 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 82 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_1, MSGBOX_AUTOCLOSE
# 99 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 100 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 101 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 102 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_Trigger_FestivalBattle_2
# 113 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_Trigger_FestivalBattle_3
# 124 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_Trigger_FestivalBattle_4
Ikitown_Trigger_FestivalBattle_1:
# 135 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 136 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_9, MSGBOX_AUTOCLOSE
# 138 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_kukui_festival
# 139 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_lillie_festival
# 140 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_2
# 141 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 142 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 143 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 144 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 145 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_11, MSGBOX_AUTOCLOSE
# 146 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_4
# 147 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 148 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 149 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 150 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_13, MSGBOX_AUTOCLOSE
# 151 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 152 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_6
# 153 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 154 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_14, MSGBOX_AUTOCLOSE
# 155 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 156 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 157 "data/maps/IkiTown/scripts.pory"
	delay 30
# 158 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 159 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_15, MSGBOX_AUTOCLOSE
# 166 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_7
# 167 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 168 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 169 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_16
# 176 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 177 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 178 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 179 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 180 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_17
# 185 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_8
# 186 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 187 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 188 "data/maps/IkiTown/scripts.pory"
	special HealPlayerParty
# 189 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_HEAL
# 190 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 191 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 192 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 193 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 194 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_18, MSGBOX_YESNO
# 195 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ikitown_Trigger_FestivalBattle_8
# 201 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 202 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_20, MSGBOX_AUTOCLOSE
# 204 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return

Ikitown_Trigger_FestivalBattle_2:
# 104 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_3, MSGBOX_AUTOCLOSE
# 106 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 107 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 108 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 109 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_4, MSGBOX_AUTOCLOSE
# 110 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 111 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_3:
# 115 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_5, MSGBOX_AUTOCLOSE
# 117 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 118 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_1
# 119 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 120 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_6, MSGBOX_AUTOCLOSE
# 121 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 122 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_4:
# 126 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_7, MSGBOX_AUTOCLOSE
# 128 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 129 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 130 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 131 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_8, MSGBOX_AUTOCLOSE
# 132 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 133 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_8:
# 196 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 197 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_19, MSGBOX_AUTOCLOSE
# 198 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage
	return


Ikitown_Trigger_FestivalBattleSkip1::
# 210 "data/maps/IkiTown/scripts.pory"
	closemessage
# 211 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 212 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 213 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 214 "data/maps/IkiTown/scripts.pory"
	special HealPlayerParty
# 215 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_kukui_festival
# 216 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_lillie_festival
# 217 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_kukui_festival, 32, 17
# 218 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_lillie_festival, 31, 17
# 219 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_hala_festival
# 220 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_hau_festival
# 221 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_hala_festival, 32, 15
# 222 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_hau_festival, 32, 14
# 223 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 224 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 225 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return


Ikitown_FestivalBattleSaidNo::
# 229 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 230 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_18, MSGBOX_YESNO
# 231 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ikitown_FestivalBattleSaidNo_1
# 237 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 238 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_20, MSGBOX_AUTOCLOSE
# 240 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return

Ikitown_FestivalBattleSaidNo_1:
# 232 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 233 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_19, MSGBOX_AUTOCLOSE
# 234 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage
	return


Ikitown_Trigger_FestivalBattleSkip2::
# 245 "data/maps/IkiTown/scripts.pory"
	closemessage
# 246 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 247 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 248 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 249 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 250 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 251 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage2
	return


Ikitown_FestivalBattleOnStage::
# 255 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 257 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_FestivalBattleOnStage_Movement_0
# 259 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_FestivalBattleOnStage_Movement_1
# 261 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_2
# 263 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_3
# 265 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_FestivalBattleOnStage_Movement_4
# 266 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 267 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_2
# 268 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 269 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_FestivalBattleOnStage_Movement_5
# 270 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 271 "data/maps/IkiTown/scripts.pory"
	hideobjectat ikitown_dynhaumon_festival, MAP_IKI_TOWN
# 272 "data/maps/IkiTown/scripts.pory"
	delay 30
# 273 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 274 "data/maps/IkiTown/scripts.pory"
	delay 30
# 275 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 276 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 277 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 278 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_0, MSGBOX_AUTOCLOSE
# 292 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 293 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 294 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_FestivalBattleOnStage_2
# 298 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_FestivalBattleOnStage_3
# 302 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_FestivalBattleOnStage_4
Ikitown_FestivalBattleOnStage_1:
# 306 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 307 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 308 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 309 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_4, MSGBOX_AUTOCLOSE
# 311 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 312 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_5, MSGBOX_AUTOCLOSE
# 316 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 317 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_mom_festival, Ikitown_FestivalBattleOnStage_Movement_7
# 318 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 319 "data/maps/IkiTown/scripts.pory"
	waitse
# 320 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 321 "data/maps/IkiTown/scripts.pory"
	waitse
# 322 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_FestivalBattleOnStage_Text_6
# 323 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 324 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_7, MSGBOX_AUTOCLOSE
# 326 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 327 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 328 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 329 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_8, MSGBOX_AUTOCLOSE
# 332 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 333 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 334 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 335 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 336 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage2
	return

Ikitown_FestivalBattleOnStage_2:
# 295 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 296 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_1, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1

Ikitown_FestivalBattleOnStage_3:
# 299 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 300 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_2, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1

Ikitown_FestivalBattleOnStage_4:
# 303 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 304 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_3, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1


Ikitown_FestivalBattleOnStage2::
# 340 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 341 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_0, MSGBOX_AUTOCLOSE
# 343 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_FestivalBattleOnStage2_2
# 353 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_FestivalBattleOnStage2_3
# 363 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_FestivalBattleOnStage2_4
Ikitown_FestivalBattleOnStage2_1:
# 373 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 374 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_3
# 375 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_2, MSGBOX_AUTOCLOSE
# 378 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 379 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 380 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 381 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 382 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_3
# 384 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage2_Movement_0
# 385 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 386 "data/maps/IkiTown/scripts.pory"
	waitse
# 387 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 388 "data/maps/IkiTown/scripts.pory"
	waitse
# 389 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_4, MSGBOX_AUTOCLOSE
# 391 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 392 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 393 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 394 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_5
# 396 "data/maps/IkiTown/scripts.pory"
	closemessage
# 397 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 398 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 399 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_6, MSGBOX_AUTOCLOSE
# 400 "data/maps/IkiTown/scripts.pory"
	waitmoncry
# 401 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 402 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 403 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 404 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 405 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_7, MSGBOX_AUTOCLOSE
# 407 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_1
# 408 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 409 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_8, MSGBOX_AUTOCLOSE
# 411 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 412 "data/maps/IkiTown/scripts.pory"
	giveitem ITEM_Z_POWER_RING
# 413 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 414 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 415 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_9, MSGBOX_AUTOCLOSE
# 436 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_FestivalBattleOnStage_Movement_7
# 437 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 438 "data/maps/IkiTown/scripts.pory"
	waitse
# 439 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 440 "data/maps/IkiTown/scripts.pory"
	waitse
# 441 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 442 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_10
# 447 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_FestivalBattleOnStage2_Text_11, Ikitown_FestivalBattleOnStage2_Text_12
# 448 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_FestivalBattleOnStage2_9
# 456 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 457 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_13
Ikitown_FestivalBattleOnStage2_8:
# 462 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 463 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_14, MSGBOX_AUTOCLOSE
# 466 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 467 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 468 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 469 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_15, MSGBOX_AUTOCLOSE
# 471 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 472 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 473 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 474 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_16, MSGBOX_AUTOCLOSE
# 485 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_2
# 486 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 487 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 488 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_17, MSGBOX_AUTOCLOSE
# 490 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 491 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 492 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 493 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_18, MSGBOX_AUTOCLOSE
# 499 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_3
# 500 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 501 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 502 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_19, MSGBOX_AUTOCLOSE
# 507 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 508 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 509 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_20, MSGBOX_AUTOCLOSE
# 511 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 512 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 513 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_FestivalBattleOnStage_Movement_7
# 514 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 515 "data/maps/IkiTown/scripts.pory"
	waitse
# 516 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 517 "data/maps/IkiTown/scripts.pory"
	waitse
# 518 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 519 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 520 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_21, MSGBOX_AUTOCLOSE
# 522 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 523 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 524 "data/maps/IkiTown/scripts.pory"
	call Ikitown_LeavingIkitownFestival
	return

Ikitown_FestivalBattleOnStage2_2:
# 344 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_12
# 350 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIO, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_3:
# 354 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_15
# 360 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLET, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_4:
# 364 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_18
# 370 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTEN, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_9:
# 449 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 450 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_13
	goto Ikitown_FestivalBattleOnStage2_8

Ikitown_FestivalBattleOnStage2_12:
# 346 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIOSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_15:
# 356 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLETSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_18:
# 366 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTENSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1


Ikitown_LeavingIkitownFestival::
# 528 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 529 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_LeavingIkitownFestival_Movement_0
# 530 "data/maps/IkiTown/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 531 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 532 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_LeavingIkitownFestival_Movement_1
# 533 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_2
# 534 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_3
# 535 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 536 "data/maps/IkiTown/scripts.pory"
	delay 15
# 537 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 538 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_4
# 539 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_4
# 540 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_4
# 541 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_LeavingIkitownFestival_Movement_4
# 542 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 543 "data/maps/IkiTown/scripts.pory"
	delay 30
# 544 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_5
# 545 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_4
# 546 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 547 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 548 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_0, MSGBOX_AUTOCLOSE
# 552 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 553 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_6
# 554 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 555 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_1
# 556 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 557 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 558 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_LeavingIkitownFestival_Text_2, Ikitown_LeavingIkitownFestival_Text_3
# 559 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_LeavingIkitownFestival_2
# 568 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 569 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_4, MSGBOX_AUTOCLOSE
Ikitown_LeavingIkitownFestival_1:
# 575 "data/maps/IkiTown/scripts.pory"
	delay 30
# 576 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattleMiddle_Movement_0
# 577 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_5
# 578 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_5
# 579 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 580 "data/maps/IkiTown/scripts.pory"
	delay 30
# 581 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 582 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_5, MSGBOX_AUTOCLOSE
# 584 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 585 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_6, MSGBOX_AUTOCLOSE
# 588 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 589 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_LeavingIkitownFestival_Movement_6
# 590 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_LeavingIkitownFestival_Movement_7
# 591 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_LeavingIkitownFestival_Movement_8
# 592 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 593 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownfestivalur4, 31, 20
# 594 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownfestivalur1, 33, 20
# 595 "data/maps/IkiTown/scripts.pory"
	delay 90
# 596 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_Trigger_FestivalBattle_Movement_3
# 597 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur4, Ikitown_LeavingIkitownFestival_Movement_9
# 598 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur1, Ikitown_LeavingIkitownFestival_Movement_9
# 599 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 600 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_LeavingIkitownFestival_Text_7
# 601 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_8
# 616 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur1, Ikitown_Trigger_FestivalBattle_Movement_4
# 617 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 618 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_9
# 621 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownfestivalur4, Ikitown_Trigger_FestivalBattle_Movement_0
# 622 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 623 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_10
# 629 "data/maps/IkiTown/scripts.pory"
	delay 30
# 630 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 631 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 15
# 632 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_IKITOWN_FESTIVAL_COMPLETE
# 633 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 634 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 635 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 636 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_SOUTH_YOUNGSTER
# 637 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 638 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_SOUTH_LASS
# 639 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 640 "data/maps/IkiTown/scripts.pory"
	waitstate
# 641 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_LeavingIkitownFestival_2:
# 560 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 561 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeavingIkitownFestival_Text_4, MSGBOX_AUTOCLOSE
	goto Ikitown_LeavingIkitownFestival_1


Ikitown_Trigger_FestivalBattleSkip3::
# 647 "data/maps/IkiTown/scripts.pory"
	closemessage
# 648 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 649 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 650 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 651 "data/maps/IkiTown/scripts.pory"
	call Ikitown_LeavingIkitownFestival
	return


Ikitown_Trigger_FestivalBattleSkip4::
# 655 "data/maps/IkiTown/scripts.pory"
	closemessage
# 656 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 657 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 658 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 659 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 660 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 661 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 662 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 15
# 663 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_IKITOWN_FESTIVAL_COMPLETE
# 664 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 665 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 666 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 667 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_SOUTH_YOUNGSTER
# 668 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 669 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_SOUTH_LASS
# 670 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 671 "data/maps/IkiTown/scripts.pory"
	waitstate
# 672 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_StartFestival::
# 677 "data/maps/IkiTown/scripts.pory"
	lockplayer
# 678 "data/maps/IkiTown/scripts.pory"
	special ShowCutsceneCinematicBars
# 679 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_0
# 680 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_exeggutor_festival, Ikitown_StartFestival_Movement_1
# 681 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_oldman_festival, Ikitown_StartFestival_Movement_2
# 682 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 683 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 684 "data/maps/IkiTown/scripts.pory"
	delay 30
# 685 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_exeggutor_festival
# 686 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_oldman_festival
# 687 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 688 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_4
# 689 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 690 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_3
# 691 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 692 "data/maps/IkiTown/scripts.pory"
	delay 30
# 693 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_woman_festival, Ikitown_StartFestival_Movement_4
# 694 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 695 "data/maps/IkiTown/scripts.pory"
	delay 30
# 696 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_5
# 697 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_6
# 698 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 699 "data/maps/IkiTown/scripts.pory"
	delay 30
# 700 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_rockruff_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 701 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_littlegirl_festival, Ikitown_FestivalBattleOnStage2_Movement_0
# 702 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 703 "data/maps/IkiTown/scripts.pory"
	waitse
# 704 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 705 "data/maps/IkiTown/scripts.pory"
	waitse
# 706 "data/maps/IkiTown/scripts.pory"
	delay 30
# 707 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_7
# 708 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 709 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 710 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 711 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 14
# 712 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_right::
# 718 "data/maps/IkiTown/scripts.pory"
	lock
# 719 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 720 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 721 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 725 "data/maps/IkiTown/scripts.pory"
	lock
# 726 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 727 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 728 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitownSkip::
# 732 "data/maps/IkiTown/scripts.pory"
	closemessage
# 733 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 734 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 735 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 736 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 737 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 738 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 739 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 740 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 741 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 742 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui, 33, 28
# 743 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 744 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 745 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau, MAP_IKI_TOWN
# 746 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 747 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 748 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_WecomeToIkitown::
# 753 "data/maps/IkiTown/scripts.pory"
	lock
# 754 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 755 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 756 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 757 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 758 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 759 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 760 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 761 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 762 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_WELCOME_TO_IKITOWN
# 763 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 764 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 765 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 766 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 767 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 768 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 769 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 770 "data/maps/IkiTown/scripts.pory"
	delay 30
# 771 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 772 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 773 "data/maps/IkiTown/scripts.pory"
	delay 30
# 774 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 775 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 776 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 777 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 778 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 779 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_0, MSGBOX_AUTOCLOSE
# 781 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 782 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_4
# 783 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 784 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_5
# 785 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 786 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 787 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1
# 793 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 794 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 795 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 796 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 797 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 798 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_7
# 799 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 800 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 801 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 807 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_Trigger_FestivalBattle_Movement_0
# 808 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 809 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 810 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 813 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_FestivalBattleOnStage_Movement_7
# 814 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 815 "data/maps/IkiTown/scripts.pory"
	waitse
# 816 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 817 "data/maps/IkiTown/scripts.pory"
	waitse
# 818 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 819 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 820 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 824 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 828 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 833 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_8
# 834 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 835 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 836 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 837 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 838 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 839 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7
# 851 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_FestivalBattleOnStage_Movement_7
# 852 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 853 "data/maps/IkiTown/scripts.pory"
	waitse
# 854 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 855 "data/maps/IkiTown/scripts.pory"
	waitse
# 856 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 857 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8
# 863 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 864 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 865 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 866 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 821 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_4, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 825 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 829 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 871 "data/maps/IkiTown/scripts.pory"
	lock
# 872 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 873 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 874 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 876 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 882 "data/maps/IkiTown/scripts.pory"
	lock
# 883 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 884 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 885 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 886 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 887 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 888 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 889 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 891 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 892 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 897 "data/maps/IkiTown/scripts.pory"
	lock
# 898 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 901 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 902 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 907 "data/maps/IkiTown/scripts.pory"
	lock
# 908 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 909 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 913 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 914 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 919 "data/maps/IkiTown/scripts.pory"
	lock
# 920 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 921 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 922 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 923 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 924 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 929 "data/maps/IkiTown/scripts.pory"
	lock
# 930 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 931 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 933 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 934 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 939 "data/maps/IkiTown/scripts.pory"
	lock
# 940 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 941 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 947 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 948 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 953 "data/maps/IkiTown/scripts.pory"
	lock
# 954 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 955 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 959 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 960 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 965 "data/maps/IkiTown/scripts.pory"
	lock
# 966 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 967 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 972 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 973 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 978 "data/maps/IkiTown/scripts.pory"
	lock
# 979 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 980 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 983 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 988 "data/maps/IkiTown/scripts.pory"
	lock
# 989 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 990 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 998 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 1003 "data/maps/IkiTown/scripts.pory"
	lock
# 1004 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1005 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 1006 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 1007 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1008 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 1013 "data/maps/IkiTown/scripts.pory"
	lock
# 1014 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 1015 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1016 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 1021 "data/maps/IkiTown/scripts.pory"
	lock
# 1022 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 1023 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 1024 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 1025 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1026 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1027 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 1028 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1029 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1030 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 1034 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 1035 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1036 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 1038 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1039 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1040 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1041 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_2
# 1048 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 1049 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 1058 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1059 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
Ikitown_GetPokedex_1:
# 1065 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_0
# 1066 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1067 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1068 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5, MSGBOX_AUTOCLOSE
# 1072 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 1073 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1075 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_4
# 1076 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1077 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_5
# 1078 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_5
# 1079 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1080 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1081 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1082 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 1089 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1090 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_6
# 1091 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_7
# 1092 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1093 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1094 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 1095 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_8
# 1096 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1097 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_5
# 1098 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1099 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1100 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_8
# 1102 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_9
# 1103 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1104 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1105 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1106 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1107 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9
# 1116 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1117 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1118 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1119 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 1133 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 1134 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1135 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1136 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 1138 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 1139 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1140 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1141 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 1145 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 1146 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1147 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13
# 1163 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_10
# 1164 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_7
# 1165 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1166 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1167 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14
# 1169 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 1170 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 1171 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1172 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1173 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 1174 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 1175 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1176 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1177 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1178 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 1188 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17, MSGBOX_AUTOCLOSE
# 1192 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 1193 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1194 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_11
# 1195 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1196 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1197 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1198 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1199 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 1050 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1051 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 1204 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1205 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1206 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1207 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1208 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1209 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 1210 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 1211 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 1212 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1214 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 1215 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 1220 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 1221 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 1222 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 1223 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 1224 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 1225 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 1226 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 1227 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 1228 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 1229 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 1230 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_5
# 1231 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1232 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_4
# 1233 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1234 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1235 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1236 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 1241 "data/maps/IkiTown/scripts.pory"
	lock
# 1242 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1243 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1244 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1245 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 1249 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1250 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 1255 "data/maps/IkiTown/scripts.pory"
	lock
# 1256 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1257 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1258 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 1261 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1262 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 1267 "data/maps/IkiTown/scripts.pory"
	lock
# 1268 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1269 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1270 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 1273 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1274 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 1279 "data/maps/IkiTown/scripts.pory"
	lock
# 1280 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE
# 1281 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1282 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 1284 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1285 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_7
# 1286 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1287 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1288 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 1289 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 1290 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1291 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1292 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1293 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1294 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 1295 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 1303 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 1311 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 1317 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 1323 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1324 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1325 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 1326 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1327 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 1328 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1329 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1330 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1331 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1332 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 1334 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1335 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1336 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1337 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 1343 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 1344 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 1345 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 1346 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 1347 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1348 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1349 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 1350 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1351 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1352 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 1353 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1354 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1355 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 1361 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_4
# 1362 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1363 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1364 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 1365 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1366 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1367 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1368 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 1369 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_0
# 1370 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1371 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1372 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 1375 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 1376 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 1397 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1398 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 1416 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 1417 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1418 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1419 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 1421 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_4
# 1422 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 1428 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1429 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1430 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1431 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 1433 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1434 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1435 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1436 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1437 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1438 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1439 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1440 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1441 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1442 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1443 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1444 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 1296 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 1297 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1298 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1299 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1300 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1301 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 1295 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 1304 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 1305 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1306 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1307 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1308 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1309 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 1303 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 1312 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 1313 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1314 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1315 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 1311 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 1318 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 1319 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1320 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1321 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 1317 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 1377 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1378 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


Ikitown_trigger_GiveHalaSparklingStoneSkip::
# 1448 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1449 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1450 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1451 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1452 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1453 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1454 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1455 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1456 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1457 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1458 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1459 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1460 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1461 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1462 "data/maps/IkiTown/scripts.pory"
	waitstate
# 1463 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyFestivalRockruffDialog::
# 1469 "data/maps/IkiTown/scripts.pory"
	lock
# 1470 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1471 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyFestivalRockruffDialog_Text_0
# 1473 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleGirlFestivalRockruffDialog::
# 1478 "data/maps/IkiTown/scripts.pory"
	lock
# 1479 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1480 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleGirlFestivalRockruffDialog_Text_0
# 1482 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC3Dialog::
# 1487 "data/maps/IkiTown/scripts.pory"
	lock
# 1488 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1489 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC3Dialog_Text_0
# 1491 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC4Dialog::
# 1496 "data/maps/IkiTown/scripts.pory"
	lock
# 1497 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1498 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC4Dialog_Text_0
# 1500 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC5Dialog::
# 1505 "data/maps/IkiTown/scripts.pory"
	lock
# 1506 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1507 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC5Dialog_Text_0
# 1510 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_FestivalNPC6Dialog::
# 1515 "data/maps/IkiTown/scripts.pory"
	lock
# 1516 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1517 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalNPC6Dialog_Text_0
# 1519 "data/maps/IkiTown/scripts.pory"
	release
	end


# 46 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleleft_Movement_0:
# 46 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 49 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleleft_Movement_1:
# 49 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 49 "data/maps/IkiTown/scripts.pory"
	walk_up
# 49 "data/maps/IkiTown/scripts.pory"
	walk_up
# 49 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 60 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleRight_Movement_0:
# 60 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 60 "data/maps/IkiTown/scripts.pory"
	walk_up
# 60 "data/maps/IkiTown/scripts.pory"
	walk_up
# 60 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 71 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattleMiddle_Movement_0:
# 71 "data/maps/IkiTown/scripts.pory"
	walk_up
# 71 "data/maps/IkiTown/scripts.pory"
	walk_up
# 71 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 79 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_0:
# 79 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 79 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 118 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_1:
# 118 "data/maps/IkiTown/scripts.pory"
	face_left
# 118 "data/maps/IkiTown/scripts.pory"
	face_up
# 118 "data/maps/IkiTown/scripts.pory"
	face_right
# 118 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 140 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_2:
# 140 "data/maps/IkiTown/scripts.pory"
	delay_16
# 140 "data/maps/IkiTown/scripts.pory"
	delay_16
# 140 "data/maps/IkiTown/scripts.pory"
	delay_16
# 140 "data/maps/IkiTown/scripts.pory"
	delay_16
# 140 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 141 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_3:
# 141 "data/maps/IkiTown/scripts.pory"
	walk_up
# 141 "data/maps/IkiTown/scripts.pory"
	walk_up
# 141 "data/maps/IkiTown/scripts.pory"
	walk_up
# 141 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 146 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_4:
# 146 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 147 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_5:
# 147 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 152 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_6:
# 152 "data/maps/IkiTown/scripts.pory"
	shake_horizontal
	step_end

# 166 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_7:
# 166 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 185 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_8:
# 185 "data/maps/IkiTown/scripts.pory"
	walk_left
# 185 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 257 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_0:
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 257 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 259 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_1:
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 259 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 259 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 261 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_2:
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 261 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 263 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_3:
# 263 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 263 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 263 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 263 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 263 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 263 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 263 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 263 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 265 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_4:
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 265 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 269 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_5:
# 269 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 269 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
	step_end

# 292 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_6:
# 292 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 292 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 317 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_7:
# 317 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 317 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 384 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_0:
# 384 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
# 384 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
	step_end

# 407 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_1:
# 407 "data/maps/IkiTown/scripts.pory"
	walk_down
# 407 "data/maps/IkiTown/scripts.pory"
	walk_down
# 407 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 485 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_2:
# 485 "data/maps/IkiTown/scripts.pory"
	walk_right
# 485 "data/maps/IkiTown/scripts.pory"
	walk_right
# 485 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 499 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_3:
# 499 "data/maps/IkiTown/scripts.pory"
	walk_left
# 499 "data/maps/IkiTown/scripts.pory"
	walk_left
# 499 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 529 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_0:
# 529 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 529 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
	step_end

# 532 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_1:
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 532 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 533 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_2:
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 533 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 534 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_3:
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 534 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 539 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_4:
# 539 "data/maps/IkiTown/scripts.pory"
	delay_16
# 539 "data/maps/IkiTown/scripts.pory"
	walk_down
# 539 "data/maps/IkiTown/scripts.pory"
	walk_down
# 539 "data/maps/IkiTown/scripts.pory"
	walk_down
# 539 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 577 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_5:
# 577 "data/maps/IkiTown/scripts.pory"
	delay_16
# 577 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 589 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_6:
# 589 "data/maps/IkiTown/scripts.pory"
	delay_16
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
# 589 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 590 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_7:
# 590 "data/maps/IkiTown/scripts.pory"
	delay_16
# 590 "data/maps/IkiTown/scripts.pory"
	delay_16
# 590 "data/maps/IkiTown/scripts.pory"
	delay_16
# 590 "data/maps/IkiTown/scripts.pory"
	delay_16
# 590 "data/maps/IkiTown/scripts.pory"
	delay_16
# 590 "data/maps/IkiTown/scripts.pory"
	delay_16
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
# 590 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 591 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_8:
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
# 591 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 597 "data/maps/IkiTown/scripts.pory"
Ikitown_LeavingIkitownFestival_Movement_9:
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	delay_16
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
# 597 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

# 679 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_0:
# 679 "data/maps/IkiTown/scripts.pory"
	walk_up
# 679 "data/maps/IkiTown/scripts.pory"
	walk_up
# 679 "data/maps/IkiTown/scripts.pory"
	walk_up
# 679 "data/maps/IkiTown/scripts.pory"
	walk_up
# 679 "data/maps/IkiTown/scripts.pory"
	delay_16
# 679 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 680 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_1:
# 680 "data/maps/IkiTown/scripts.pory"
	delay_16
# 680 "data/maps/IkiTown/scripts.pory"
	delay_16
# 680 "data/maps/IkiTown/scripts.pory"
	walk_up
# 680 "data/maps/IkiTown/scripts.pory"
	walk_up
# 680 "data/maps/IkiTown/scripts.pory"
	walk_up
# 680 "data/maps/IkiTown/scripts.pory"
	walk_up
# 680 "data/maps/IkiTown/scripts.pory"
	walk_up
# 680 "data/maps/IkiTown/scripts.pory"
	walk_up
# 680 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 681 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_2:
# 681 "data/maps/IkiTown/scripts.pory"
	delay_16
# 681 "data/maps/IkiTown/scripts.pory"
	walk_up
# 681 "data/maps/IkiTown/scripts.pory"
	walk_up
# 681 "data/maps/IkiTown/scripts.pory"
	walk_up
# 681 "data/maps/IkiTown/scripts.pory"
	walk_up
# 681 "data/maps/IkiTown/scripts.pory"
	walk_up
# 681 "data/maps/IkiTown/scripts.pory"
	walk_up
# 681 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 690 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_3:
# 690 "data/maps/IkiTown/scripts.pory"
	walk_left
# 690 "data/maps/IkiTown/scripts.pory"
	walk_left
# 690 "data/maps/IkiTown/scripts.pory"
	walk_left
# 690 "data/maps/IkiTown/scripts.pory"
	walk_left
# 690 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 693 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_4:
# 693 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 693 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 696 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_5:
# 696 "data/maps/IkiTown/scripts.pory"
	delay_16
# 696 "data/maps/IkiTown/scripts.pory"
	delay_16
# 696 "data/maps/IkiTown/scripts.pory"
	delay_16
# 696 "data/maps/IkiTown/scripts.pory"
	delay_16
# 696 "data/maps/IkiTown/scripts.pory"
	delay_16
# 696 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 697 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_6:
# 697 "data/maps/IkiTown/scripts.pory"
	walk_right
# 697 "data/maps/IkiTown/scripts.pory"
	walk_right
# 697 "data/maps/IkiTown/scripts.pory"
	walk_right
# 697 "data/maps/IkiTown/scripts.pory"
	walk_right
# 697 "data/maps/IkiTown/scripts.pory"
	walk_right
# 697 "data/maps/IkiTown/scripts.pory"
	walk_right
# 697 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 707 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_7:
# 707 "data/maps/IkiTown/scripts.pory"
	walk_left
# 707 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 719 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 719 "data/maps/IkiTown/scripts.pory"
	walk_left
# 719 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 726 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 726 "data/maps/IkiTown/scripts.pory"
	walk_right
# 726 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 743 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitownSkip_Movement_0:
# 743 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 763 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 763 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 763 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 764 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 764 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 767 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
# 767 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 768 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 768 "data/maps/IkiTown/scripts.pory"
	delay_16
# 768 "data/maps/IkiTown/scripts.pory"
	delay_16
# 768 "data/maps/IkiTown/scripts.pory"
	delay_16
# 768 "data/maps/IkiTown/scripts.pory"
	delay_16
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 768 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 782 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 782 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 784 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 784 "data/maps/IkiTown/scripts.pory"
	walk_up
# 784 "data/maps/IkiTown/scripts.pory"
	walk_up
# 784 "data/maps/IkiTown/scripts.pory"
	walk_up
# 784 "data/maps/IkiTown/scripts.pory"
	walk_up
# 784 "data/maps/IkiTown/scripts.pory"
	walk_up
# 784 "data/maps/IkiTown/scripts.pory"
	walk_up
# 784 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 794 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 794 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 798 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 798 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 833 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 833 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 886 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 886 "data/maps/IkiTown/scripts.pory"
	face_down
# 886 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 891 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 891 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 1023 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1023 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1023 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 1024 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 1024 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1024 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1024 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1024 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 1027 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 1027 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 1027 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1027 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1038 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 1038 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 1038 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 1075 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 1075 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 1077 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 1077 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 1077 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 1090 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 1090 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1090 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1090 "data/maps/IkiTown/scripts.pory"
	delay_16
# 1090 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 1091 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 1091 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1091 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1091 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1091 "data/maps/IkiTown/scripts.pory"
	walk_up
# 1091 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1095 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 1095 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1095 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1095 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1095 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1095 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1095 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1095 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1102 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1163 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1194 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 1194 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1194 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1194 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 1296 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 1296 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1296 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1296 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1296 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1300 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1300 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1304 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 1304 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1304 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1304 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1304 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1304 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1304 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1312 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 1312 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1312 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1312 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1312 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1312 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1312 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1312 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1312 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1318 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1318 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1318 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1325 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 1325 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1325 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1325 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1325 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 1327 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 1327 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1327 "data/maps/IkiTown/scripts.pory"
	delay_8
# 1327 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1416 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 1416 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_Trigger_FestivalBattle_Text_0:
# 81 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_Trigger_FestivalBattle_Text_1:
# 82 "data/maps/IkiTown/scripts.pory"
	.string "The Alola Region is made up of our\n"
	.string "four islands.\p"
	.string "And each island has its own guardian\n"
	.string "Pokémon.\p"
	.string "Our festival today is help to express\n"
	.string "our thanks to these great Pokémon\l"
	.string "guardian deities for always\l"
	.string "remaining by our sides.\p"
	.string "Well, we may call it a festival, but it's\n"
	.string "just this little thing you see here.\p"
	.string "There may not be many of us, but at\n"
	.string "least every last one of us here goes\l"
	.string "all out.$"

Ikitown_Trigger_FestivalBattle_Text_2:
# 101 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_Trigger_FestivalBattle_Text_3:
# 104 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Popplio've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_4:
# 109 "data/maps/IkiTown/scripts.pory"
	.string "Bwark!$"

Ikitown_Trigger_FestivalBattle_Text_5:
# 115 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Rowlet've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_6:
# 120 "data/maps/IkiTown/scripts.pory"
	.string "Hoo!$"

Ikitown_Trigger_FestivalBattle_Text_7:
# 126 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Litten've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_8:
# 131 "data/maps/IkiTown/scripts.pory"
	.string "Grrr!$"

Ikitown_Trigger_FestivalBattle_Text_9:
# 136 "data/maps/IkiTown/scripts.pory"
	.string "Hold on… Didn't anyone explain to\n"
	.string "you about tonight?!$"

Ikitown_Trigger_FestivalBattle_Text_10:
# 144 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_Trigger_FestivalBattle_Text_11:
# 145 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah, right on time!$"

Ikitown_Trigger_FestivalBattle_Text_12:
# 149 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_Trigger_FestivalBattle_Text_13:
# 150 "data/maps/IkiTown/scripts.pory"
	.string "But to what exactly?$"

Ikitown_Trigger_FestivalBattle_Text_14:
# 154 "data/maps/IkiTown/scripts.pory"
	.string "Pew!!$"

Ikitown_Trigger_FestivalBattle_Text_15:
# 159 "data/maps/IkiTown/scripts.pory"
	.string "A full-powered festival for Pokemon\n"
	.string "battling!\p"
	.string "We battle in the name of Tapu Koko,\n"
	.string "pitting our best move against one\l"
	.string "another in friendly competition to\l"
	.string "please our guardian. Woo!$"

Ikitown_Trigger_FestivalBattle_Text_16:
# 169 "data/maps/IkiTown/scripts.pory"
	.string "So, you two will be taking part in\n"
	.string "battle?\p"
	.string "I don't like seeing Pokémon fight one\n"
	.string "another…they often end up hurt.\p"
	.string "But…I'll be sure to watch you both.$"

Ikitown_Trigger_FestivalBattle_Text_17:
# 180 "data/maps/IkiTown/scripts.pory"
	.string "Your Pokémon have fought for you, so\n"
	.string "show them the same care in return,\l"
	.string "{PLAYER}.\p"
	.string "Allow me to heal them for you this time.$"

Ikitown_Trigger_FestivalBattle_Text_18:
# 194 "data/maps/IkiTown/scripts.pory"
	.string "Are you ready for this Pokémon battle?$"

Ikitown_Trigger_FestivalBattle_Text_19:
# 197 "data/maps/IkiTown/scripts.pory"
	.string "Then let's begin!$"

Ikitown_Trigger_FestivalBattle_Text_20:
# 202 "data/maps/IkiTown/scripts.pory"
	.string "Oh come on!\n"
	.string "It's the festival!$"

Ikitown_FestivalBattleOnStage_Text_0:
# 278 "data/maps/IkiTown/scripts.pory"
	.string "For all life on our islands…\p"
	.string "and for those who undertake the island\n"
	.string "challenge with joy in their hearts…\p"
	.string "we pray for your protection…\n"
	.string "for them and all Melemele.\p"
	.string "May this Pokémon battle be an offering\n"
	.string "to our island's guardian deity\l"
	.string "Tapu Koko!\p"
	.string "Before you stands Hau-grandson\n"
	.string "to the kahuna.$"

Ikitown_FestivalBattleOnStage_Text_1:
# 296 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Popplio!$"

Ikitown_FestivalBattleOnStage_Text_2:
# 300 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Rowlet!$"

Ikitown_FestivalBattleOnStage_Text_3:
# 304 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Litten!$"

Ikitown_FestivalBattleOnStage_Text_4:
# 309 "data/maps/IkiTown/scripts.pory"
	.string "Before him stands {PLAYER}-\n"
	.string "one who has met with Tapu Koko.$"

Ikitown_FestivalBattleOnStage_Text_5:
# 312 "data/maps/IkiTown/scripts.pory"
	.string "What?!\p"
	.string "What a curious thing Tapu Koko is!\n"
	.string "Hah, that's just typical of it!$"

Ikitown_FestivalBattleOnStage_Text_6:
# 322 "data/maps/IkiTown/scripts.pory"
	.string "Mom$"

Ikitown_FestivalBattleOnStage_Text_7:
# 324 "data/maps/IkiTown/scripts.pory"
	.string "{STR_VAR_1}!\n"
	.string "Take good care of my little {PLAYER}!$"

Ikitown_FestivalBattleOnStage_Text_8:
# 329 "data/maps/IkiTown/scripts.pory"
	.string "As long as we both have a good time,\n"
	.string "then I think we can call it a great\l"
	.string "battle, eh?$"

Ikitown_FestivalBattleOnStage2_Text_0:
# 341 "data/maps/IkiTown/scripts.pory"
	.string "{PLAYER}! Hau!\n"
	.string "Bring forth the power of your Pokémon!$"

Ikitown_FestivalBattleOnStage2_Text_1:
# 346 "data/maps/IkiTown/scripts.pory"
	.string "What? It's already over?!$"

Ikitown_FestivalBattleOnStage2_Text_2:
# 375 "data/maps/IkiTown/scripts.pory"
	.string "Hoo-ee! Another great battle this year.\p"
	.string "I bet Tapu Koko liked it, too.$"

Ikitown_FestivalBattleOnStage2_Text_3:
# 382 "data/maps/IkiTown/scripts.pory"
	.string "Phew…\n"
	.string "That was awesome, {PLAYER}!$"

Ikitown_FestivalBattleOnStage2_Text_4:
# 389 "data/maps/IkiTown/scripts.pory"
	.string "That was a really great battle!\n"
	.string "I had a blast fighting you!$"

Ikitown_FestivalBattleOnStage2_Text_5:
# 394 "data/maps/IkiTown/scripts.pory"
	.string "It was a good battle.\n"
	.string "With this, even Tapu Koko…$"

Ikitown_FestivalBattleOnStage2_Text_6:
# 399 "data/maps/IkiTown/scripts.pory"
	.string "Ko-ko-kooo!$"

Ikitown_FestivalBattleOnStage2_Text_7:
# 405 "data/maps/IkiTown/scripts.pory"
	.string "Ho! You heard it yourself!\n"
	.string "Tapu Koko's song of approval.$"

Ikitown_FestivalBattleOnStage2_Text_8:
# 409 "data/maps/IkiTown/scripts.pory"
	.string "Oh, I nearly forgot! I think its\n"
	.string "time you take this, {PLAYER}.$"

Ikitown_FestivalBattleOnStage2_Text_9:
# 415 "data/maps/IkiTown/scripts.pory"
	.string "Your {COLOR RED}Z-Power Ring{COLOR DARK_GRAY}, a mysterious armband\n"
	.string "that can draw out the power that\l"
	.string "lies deep within Pokémon…\p"
	.string "It can bring forth their {COLOR RED}Z-Power{COLOR DARK_GRAY}!\p"
	.string "We kahunas can make Z-Power rings\n"
	.string "using stones like the Sparkling\l"
	.string "Stone you received from Tapu Koko.\p"
	.string "Though you will need to undergo the\n"
	.string "island challenge and collect\l"
	.string "Z-Crystals for yourself, if you wish\l"
	.string "to draw forth Pokémon's Z-Power!\p"
	.string "And yet you have already received that\n"
	.string "Sparkling Stone…\p"
	.string "It seems that Tapu Koko took quite a\n"
	.string "liking to you…\l"
	.string "or perhaps it has a mission for you.$"

Ikitown_FestivalBattleOnStage2_Text_10:
# 442 "data/maps/IkiTown/scripts.pory"
	.string "Well, it's time for you to get out there\n"
	.string "and start your {COLOR RED}island challenge{COLOR DARK_GRAY}!\p"
	.string "If you visit every island, maybe you'll\n"
	.string "figure out what that mission is.$"

Ikitown_FestivalBattleOnStage2_Text_11:
# 447 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge?$"

Ikitown_FestivalBattleOnStage2_Text_12:
# 447 "data/maps/IkiTown/scripts.pory"
	.string "Every Island?$"

Ikitown_FestivalBattleOnStage2_Text_13:
# 450 "data/maps/IkiTown/scripts.pory"
	.string "Four Islands!\p"
	.string "You'll travel to each of the four\n"
	.string "islands here in the Alola Region.$"

Ikitown_FestivalBattleOnStage2_Text_14:
# 463 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge is about aiming to\n"
	.string "be the strongest Trainer-\l"
	.string "the {COLOR RED}island challenge champion{COLOR DARK_GRAY}. Woo!$"

Ikitown_FestivalBattleOnStage2_Text_15:
# 469 "data/maps/IkiTown/scripts.pory"
	.string "Sounds great, right?\n"
	.string "I can't wait to have a real adventure!$"

Ikitown_FestivalBattleOnStage2_Text_16:
# 474 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge Kukui spoke of…\p"
	.string "It is a journey to overcome your own\n"
	.string "limitations, as you travel the far\l"
	.string "corners of Alola and meet with\l"
	.string "others along the path.\p"
	.string "It's a great adventure that children\n"
	.string "in the Alola region embark upon,\l"
	.string "along with their Pokémon,\l"
	.string "once they reach 11 years of age!$"

Ikitown_FestivalBattleOnStage2_Text_17:
# 488 "data/maps/IkiTown/scripts.pory"
	.string "Allow me to give you both the island\n"
	.string "challenge amulets you will need.$"

Ikitown_FestivalBattleOnStage2_Text_18:
# 493 "data/maps/IkiTown/scripts.pory"
	.string "Awesome!\n"
	.string "Thanks, Tutu!\p"
	.string "I'm gonna make it through the island\n"
	.string "challenge to try to become an island\l"
	.string "challenge champion!$"

Ikitown_FestivalBattleOnStage2_Text_19:
# 502 "data/maps/IkiTown/scripts.pory"
	.string "There is one for you was well,\n"
	.string "{PLAYER}.\p"
	.string "Please do give the island challenge\n"
	.string "a try.$"

Ikitown_FestivalBattleOnStage2_Text_20:
# 509 "data/maps/IkiTown/scripts.pory"
	.string "You received the {COLOR RED}Island Challenge\n"
	.string "Amulet{COLOR DARK_GRAY}!$"

Ikitown_FestivalBattleOnStage2_Text_21:
# 520 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, doing the island challenge is the\n"
	.string "best way to really get to know Alola!$"

Ikitown_LeavingIkitownFestival_Text_0:
# 548 "data/maps/IkiTown/scripts.pory"
	.string "Tapu Koko is amazing, isn't it?\p"
	.string "I hope I can meet it again someday\n"
	.string "and thank it for saving Nebby…$"

Ikitown_LeavingIkitownFestival_Text_1:
# 555 "data/maps/IkiTown/scripts.pory"
	.string "Pew!$"

Ikitown_LeavingIkitownFestival_Text_2:
# 558 "data/maps/IkiTown/scripts.pory"
	.string "Me, too$"

Ikitown_LeavingIkitownFestival_Text_3:
# 558 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah?$"

Ikitown_LeavingIkitownFestival_Text_4:
# 561 "data/maps/IkiTown/scripts.pory"
	.string "It saved you as well, didn't it?\n"
	.string "And left you with that Sparkling\l"
	.string "Stone…\l"
	.string "even though you're a stranger to\l"
	.string "this place.$"

Ikitown_LeavingIkitownFestival_Text_5:
# 582 "data/maps/IkiTown/scripts.pory"
	.string "Suppose it's time we get you kids home,\n"
	.string "yeah?$"

Ikitown_LeavingIkitownFestival_Text_6:
# 585 "data/maps/IkiTown/scripts.pory"
	.string "Nebby…\n"
	.string "Alola is full of all kinds of wonders,\l"
	.string "isn't it?$"

Ikitown_LeavingIkitownFestival_Text_7:
# 600 "data/maps/IkiTown/scripts.pory"
	.string "???$"

Ikitown_LeavingIkitownFestival_Text_8:
# 601 "data/maps/IkiTown/scripts.pory"
	.string "Captain…\p"
	.string "I was able to detect high levels of\n"
	.string "aura at this full-powered festival.\p"
	.string "I suppose you would…\p"
	.string "According to our earlier research it\n"
	.string "seems that the Z-Power Ring and this\l"
	.string "Tapu Koko creature are bathed in a\l"
	.string "great deal of light.\p"
	.string "Alola overflows with the light that\n"
	.string "was released by the Blinding One…\l"
	.string "I find myself rather envious.$"

Ikitown_LeavingIkitownFestival_Text_9:
# 618 "data/maps/IkiTown/scripts.pory"
	.string "I wonder if we can't find some way\n"
	.string "to use the great power that fills\l"
	.string "Alola for ourselves…$"

Ikitown_LeavingIkitownFestival_Text_10:
# 623 "data/maps/IkiTown/scripts.pory"
	.string "That is precisely what we, the Ultra\n"
	.string "Recon Squad, are here to make clear.\p"
	.string "Onward! There is still so much of\n"
	.string "Alola we have not seen, and we must\l"
	.string "investigate it all!$"

Ikitown_trigger_WecomeToIkitown_Text_0:
# 779 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 787 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 801 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 810 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 821 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 825 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 829 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 839 "data/maps/IkiTown/scripts.pory"
	.string "Hey, I've got an idea for you,\n"
	.string "{PLAYER}.\p"
	.string "If you head through the village and\n"
	.string "up the hill, you can visit the ruins\l"
	.string "that belong to Tapu Koko.\p"
	.string "That's our island's guardian deity,\n"
	.string "yeah.\p"
	.string "Why don't you go and introduce\n"
	.string "yourself?$"

Ikitown_trigger_WecomeToIkitown_Text_8:
# 857 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 874 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 898 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 909 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 922 "data/maps/IkiTown/scripts.pory"
	.string "Wroof!$"

Ikitown_LeftSideGuy_Text_0:
# 931 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 941 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 955 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 967 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 980 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 990 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 1006 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 1014 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 1030 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 1036 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 1041 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_3:
# 1051 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_4:
# 1059 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 1068 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_6:
# 1082 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_7:
# 1094 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_8:
# 1100 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_9:
# 1107 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_10:
# 1119 "data/maps/IkiTown/scripts.pory"
	.string "Oh, um…\n"
	.string "Yes, Kahuna Hala…\p"
	.string "Nebby got attacked by some Wingull\n"
	.string "on the Plank Bridge.\p"
	.string "And {PLAYER} here helped protect it.\p"
	.string "But the bridge collapsed, and I thought\n"
	.string "both of them might fall to the\l"
	.string "bottom of the ravine…\p"
	.string "And that was when the island's guardian\n"
	.string "deity, swooped in to save them!$"

Ikitown_GetPokedex_Text_11:
# 1136 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_12:
# 1141 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_13:
# 1147 "data/maps/IkiTown/scripts.pory"
	.string "Kukui, my boy, I think we have\n"
	.string "cause to celebrate!\p"
	.string "Looks like we have a brave and kind new\n"
	.string "Pokémon Trainer in our midst!\p"
	.string "I'm glad to meet you, child.\n"
	.string "I'm Hala, the kahuna of Melemele\l"
	.string "Island.\p"
	.string "Welcome to Alola!\n"
	.string "Young Kukui had told me of your\l"
	.string "coming.\p"
	.string "I'm glad we had the chance to meet\n"
	.string "today.$"

Ikitown_GetPokedex_Text_14:
# 1167 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_15:
# 1173 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_16:
# 1178 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_17:
# 1188 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 1245 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 1258 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 1270 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 1282 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 1332 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 1337 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 1355 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 1364 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 1368 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 1372 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 1375 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 1375 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 1378 "data/maps/IkiTown/scripts.pory"
	.string "So it even deigned to give you a stone…\p"
	.string "Perhaps you are here in Alola,\n"
	.string "{PLAYER}, because this is where\l"
	.string "you are meant to be.\p"
	.string "Allow me to borrow this stone for now.\p"
	.string "Fret not, I will return it to you\n"
	.string "tomorrow evening.\p"
	.string "You have the makings of a brilliant\n"
	.string "Trainer.\l"
	.string "I can see that light within you, too.\p"
	.string "You must do us the honor of joining in\n"
	.string "our festival tomorrow!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_10:
# 1419 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 1422 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 1431 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will keep an eye on Nebby$"

Ikitown_LittleBoyFestivalRockruffDialog_Text_0:
# 1471 "data/maps/IkiTown/scripts.pory"
	.string "Woo-hoo, A festival!\n"
	.string "I wish everyday was a festival!$"

Ikitown_LittleGirlFestivalRockruffDialog_Text_0:
# 1480 "data/maps/IkiTown/scripts.pory"
	.string "What kinds of Pokémon are going to\n"
	.string "battle? I'm so excited!$"

Ikitown_FestivalNPC3Dialog_Text_0:
# 1489 "data/maps/IkiTown/scripts.pory"
	.string "If anyone can have a good battle that\n"
	.string "makes the Pokémon happy, it's Hau!$"

Ikitown_FestivalNPC4Dialog_Text_0:
# 1498 "data/maps/IkiTown/scripts.pory"
	.string "I ate every last bite of my Alola\n"
	.string "yakisoba!$"

Ikitown_FestivalNPC5Dialog_Text_0:
# 1507 "data/maps/IkiTown/scripts.pory"
	.string "Sometimes, I get this feeling…\n"
	.string "this sense of being watched over by\l"
	.string "the guardian deity.$"

Ikitown_FestivalNPC6Dialog_Text_0:
# 1517 "data/maps/IkiTown/scripts.pory"
	.string "Tapu Koko just loves Pokémon battles.\n"
	.string "Watching them and having them!$"
