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
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 81 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_1, MSGBOX_AUTOCLOSE
# 98 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 99 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 100 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 101 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_Trigger_FestivalBattle_2
# 113 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_Trigger_FestivalBattle_3
# 125 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_Trigger_FestivalBattle_4
Ikitown_Trigger_FestivalBattle_1:
# 137 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 138 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_9, MSGBOX_AUTOCLOSE
# 140 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_kukui_festival
# 141 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_lillie_festival
# 142 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_2
# 143 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 144 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 145 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 146 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 147 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_11, MSGBOX_AUTOCLOSE
# 148 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_4
# 149 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 150 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 151 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 152 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_13, MSGBOX_AUTOCLOSE
# 153 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 154 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_6
# 155 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 156 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 157 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_14, MSGBOX_AUTOCLOSE
# 158 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 159 "data/maps/IkiTown/scripts.pory"
	delay 30
# 160 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 161 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_15, MSGBOX_AUTOCLOSE
# 168 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_7
# 169 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 170 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 171 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_16
# 178 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 179 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 180 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 181 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 182 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_17
# 187 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_8
# 188 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 189 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 190 "data/maps/IkiTown/scripts.pory"
	special HealPlayerParty
# 191 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_HEAL
# 192 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 193 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 194 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 195 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 196 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_18, MSGBOX_YESNO
# 197 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ikitown_Trigger_FestivalBattle_8
# 203 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 204 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_20, MSGBOX_AUTOCLOSE
# 206 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return

Ikitown_Trigger_FestivalBattle_2:
# 103 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_3, MSGBOX_AUTOCLOSE
# 105 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 106 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 107 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 108 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 109 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_4, MSGBOX_AUTOCLOSE
# 110 "data/maps/IkiTown/scripts.pory"
	waitmoncry
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
	waitmovement 0
# 120 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 121 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_6, MSGBOX_AUTOCLOSE
# 122 "data/maps/IkiTown/scripts.pory"
	waitmoncry
# 123 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_4:
# 127 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_7, MSGBOX_AUTOCLOSE
# 129 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 130 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 131 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 132 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 133 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_8, MSGBOX_AUTOCLOSE
# 134 "data/maps/IkiTown/scripts.pory"
	waitmoncry
# 135 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_8:
# 198 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 199 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_19, MSGBOX_AUTOCLOSE
# 200 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage
	return


Ikitown_Trigger_FestivalBattleSkip1::
# 212 "data/maps/IkiTown/scripts.pory"
	closemessage
# 213 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 214 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 215 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 216 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_kukui_festival
# 217 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_lillie_festival
# 218 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_kukui_festival, 32, 17
# 219 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_lillie_festival, 31, 17
# 220 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_hala_festival
# 221 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_hau_festival
# 222 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_hala_festival, 32, 15
# 223 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitown_hau_festival, 32, 14
# 224 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 225 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 226 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return


Ikitown_FestivalBattleSaidNo::
# 230 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 231 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_18, MSGBOX_YESNO
# 232 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ikitown_FestivalBattleSaidNo_1
# 238 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 239 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_20, MSGBOX_AUTOCLOSE
# 241 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return

Ikitown_FestivalBattleSaidNo_1:
# 233 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 234 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_19, MSGBOX_AUTOCLOSE
# 235 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage
	return


Ikitown_Trigger_FestivalBattleSkip2::
# 246 "data/maps/IkiTown/scripts.pory"
	closemessage
# 247 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 248 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 249 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
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
	endcutscene
# 335 "data/maps/IkiTown/scripts.pory"
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
# 339 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 340 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_0, MSGBOX_AUTOCLOSE
# 342 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_FestivalBattleOnStage2_2
# 352 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_FestivalBattleOnStage2_3
# 362 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_FestivalBattleOnStage2_4
Ikitown_FestivalBattleOnStage2_1:
# 372 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 373 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_FESTIVAL_BATTLE_3
# 374 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
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
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 437 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 438 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 439 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_10
# 444 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_FestivalBattleOnStage2_Text_11, Ikitown_FestivalBattleOnStage2_Text_12
# 445 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_FestivalBattleOnStage2_9
# 453 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 454 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_13
Ikitown_FestivalBattleOnStage2_8:
# 459 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 460 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_14, MSGBOX_AUTOCLOSE
# 463 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 464 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 465 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 466 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_15, MSGBOX_AUTOCLOSE
# 468 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 469 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 470 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 471 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_16
# 482 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_2
# 483 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 484 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 485 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_17, MSGBOX_AUTOCLOSE
# 487 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 488 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 489 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 490 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_18, MSGBOX_AUTOCLOSE
# 496 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage2_Movement_3
# 497 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 498 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 499 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_19, MSGBOX_AUTOCLOSE
# 504 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 505 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 506 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_20, MSGBOX_AUTOCLOSE
# 508 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 509 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 510 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 511 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 512 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 513 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_21
# 515 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_FestivalBattleOnStage2_Movement_4
# 516 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 517 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 518 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 519 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 15
# 520 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 521 "data/maps/IkiTown/scripts.pory"
	waitstate
# 522 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_FestivalBattleOnStage2_2:
# 343 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_12
# 349 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIO, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_3:
# 353 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_15
# 359 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLET, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_4:
# 363 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage2_18
# 369 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTEN, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_9:
# 446 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 447 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage2_Text_13
	goto Ikitown_FestivalBattleOnStage2_8

Ikitown_FestivalBattleOnStage2_12:
# 345 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIOSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_15:
# 355 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLETSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1

Ikitown_FestivalBattleOnStage2_18:
# 365 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTENSHINY, Ikitown_FestivalBattleOnStage2_Text_1
	goto Ikitown_FestivalBattleOnStage2_1


Ikitown_Trigger_FestivalBattleSkip3::
# 528 "data/maps/IkiTown/scripts.pory"
	closemessage
# 529 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 530 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 531 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 532 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 533 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 534 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 535 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 15
# 536 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 537 "data/maps/IkiTown/scripts.pory"
	waitstate
# 538 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_StartFestival::
# 543 "data/maps/IkiTown/scripts.pory"
	lockplayer
# 544 "data/maps/IkiTown/scripts.pory"
	special ShowCutsceneCinematicBars
# 545 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_0
# 546 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_exeggutor_festival, Ikitown_StartFestival_Movement_1
# 547 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_oldman_festival, Ikitown_StartFestival_Movement_2
# 548 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 549 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 550 "data/maps/IkiTown/scripts.pory"
	delay 30
# 551 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_exeggutor_festival
# 552 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_oldman_festival
# 553 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 554 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_3
# 555 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 556 "data/maps/IkiTown/scripts.pory"
	delay 30
# 557 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_woman_festival, Ikitown_StartFestival_Movement_4
# 558 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 559 "data/maps/IkiTown/scripts.pory"
	delay 30
# 560 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_5
# 561 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 562 "data/maps/IkiTown/scripts.pory"
	delay 30
# 563 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_rockruff_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 564 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_littlegirl_festival, Ikitown_FestivalBattleOnStage2_Movement_0
# 565 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 566 "data/maps/IkiTown/scripts.pory"
	waitse
# 567 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 568 "data/maps/IkiTown/scripts.pory"
	waitse
# 569 "data/maps/IkiTown/scripts.pory"
	delay 30
# 570 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_6
# 571 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 572 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 573 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 574 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 14
# 575 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_right::
# 581 "data/maps/IkiTown/scripts.pory"
	lock
# 582 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 583 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 584 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 588 "data/maps/IkiTown/scripts.pory"
	lock
# 589 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 590 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 591 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitownSkip::
# 595 "data/maps/IkiTown/scripts.pory"
	closemessage
# 596 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 597 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 598 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 599 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 600 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 601 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 602 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 603 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 604 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 605 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui, 33, 28
# 606 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 607 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 608 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau, MAP_IKI_TOWN
# 609 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 610 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 611 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_WecomeToIkitown::
# 616 "data/maps/IkiTown/scripts.pory"
	lock
# 617 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 618 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 619 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 620 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 621 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 622 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 623 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 624 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 625 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_WELCOME_TO_IKITOWN
# 626 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 627 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 628 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 629 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 630 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 631 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 632 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 633 "data/maps/IkiTown/scripts.pory"
	delay 30
# 634 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 635 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 636 "data/maps/IkiTown/scripts.pory"
	delay 30
# 637 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 638 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 639 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 640 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 641 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 642 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_0, MSGBOX_AUTOCLOSE
# 644 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 645 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_4
# 646 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 647 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_5
# 648 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 649 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 650 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1
# 656 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 657 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 658 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 659 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 660 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 661 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_7
# 662 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 663 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 664 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 670 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_Trigger_FestivalBattle_Movement_0
# 671 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 672 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 673 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 676 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_FestivalBattleOnStage_Movement_7
# 677 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 678 "data/maps/IkiTown/scripts.pory"
	waitse
# 679 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 680 "data/maps/IkiTown/scripts.pory"
	waitse
# 681 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 682 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 683 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 687 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 691 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 696 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_8
# 697 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 698 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 699 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 700 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 701 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 702 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7
# 714 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_FestivalBattleOnStage_Movement_7
# 715 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 716 "data/maps/IkiTown/scripts.pory"
	waitse
# 717 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 718 "data/maps/IkiTown/scripts.pory"
	waitse
# 719 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 720 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8
# 726 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 727 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 728 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 729 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 684 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_4, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 688 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 692 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 734 "data/maps/IkiTown/scripts.pory"
	lock
# 735 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 736 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 737 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 739 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 745 "data/maps/IkiTown/scripts.pory"
	lock
# 746 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 747 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 748 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 749 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 750 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 751 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 752 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 754 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 755 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 760 "data/maps/IkiTown/scripts.pory"
	lock
# 761 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 764 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 765 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 770 "data/maps/IkiTown/scripts.pory"
	lock
# 771 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 772 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 776 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 777 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 782 "data/maps/IkiTown/scripts.pory"
	lock
# 783 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 784 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 785 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 786 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 787 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 792 "data/maps/IkiTown/scripts.pory"
	lock
# 793 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 794 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 796 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 797 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 802 "data/maps/IkiTown/scripts.pory"
	lock
# 803 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 804 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 810 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 811 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 816 "data/maps/IkiTown/scripts.pory"
	lock
# 817 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 818 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 822 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 823 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 828 "data/maps/IkiTown/scripts.pory"
	lock
# 829 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 830 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 835 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 836 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 841 "data/maps/IkiTown/scripts.pory"
	lock
# 842 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 843 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 846 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 851 "data/maps/IkiTown/scripts.pory"
	lock
# 852 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 853 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 861 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 866 "data/maps/IkiTown/scripts.pory"
	lock
# 867 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 868 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 869 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 870 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 871 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 876 "data/maps/IkiTown/scripts.pory"
	lock
# 877 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 878 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 879 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 884 "data/maps/IkiTown/scripts.pory"
	lock
# 885 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 886 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 887 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 888 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 889 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 890 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 891 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 892 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 893 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 897 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 898 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 899 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 901 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 902 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 903 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 904 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_2
# 911 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 912 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 921 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 922 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
Ikitown_GetPokedex_1:
# 928 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_0
# 929 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 930 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 931 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5, MSGBOX_AUTOCLOSE
# 935 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 936 "data/maps/IkiTown/scripts.pory"
	delay 30
# 938 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_4
# 939 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 940 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_5
# 941 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_5
# 942 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 943 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 944 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 945 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 952 "data/maps/IkiTown/scripts.pory"
	delay 30
# 953 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_6
# 954 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_7
# 955 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 956 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 957 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 958 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_8
# 959 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 960 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_5
# 961 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 962 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 963 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_8
# 965 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_9
# 966 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 967 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 968 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 969 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 970 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9
# 979 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 980 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 981 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 982 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 996 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 997 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 998 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 999 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 1001 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 1002 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1003 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1004 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 1008 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 1009 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1010 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13
# 1026 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_10
# 1027 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_6
# 1028 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1029 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1030 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14
# 1032 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 1033 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 1034 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1035 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1036 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 1037 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 1038 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1039 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1040 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1041 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 1051 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17, MSGBOX_AUTOCLOSE
# 1055 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 1056 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1057 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_11
# 1058 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1059 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1060 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1061 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1062 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 913 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 914 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 1067 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1068 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1069 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1070 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1071 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1072 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 1073 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 1074 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 1075 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1077 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 1078 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 1083 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 1084 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 1085 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 1086 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 1087 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 1088 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 1089 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 1090 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 1091 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 1092 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 1093 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_5
# 1094 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1095 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_4
# 1096 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1097 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1098 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1099 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 1104 "data/maps/IkiTown/scripts.pory"
	lock
# 1105 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1106 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1107 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1108 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 1112 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1113 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 1118 "data/maps/IkiTown/scripts.pory"
	lock
# 1119 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1120 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1121 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 1124 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1125 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 1130 "data/maps/IkiTown/scripts.pory"
	lock
# 1131 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1132 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1133 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 1136 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1137 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 1142 "data/maps/IkiTown/scripts.pory"
	lock
# 1143 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE
# 1144 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1145 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 1147 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1148 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_7
# 1149 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1150 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1151 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 1152 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 1153 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1154 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1155 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1156 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1157 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 1158 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 1166 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 1174 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 1180 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 1186 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1187 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1188 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 1189 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1190 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 1191 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1192 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1193 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1194 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1195 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 1197 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1198 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1199 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1200 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 1206 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 1207 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 1208 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 1209 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 1210 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1211 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1212 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 1213 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1214 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1215 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 1216 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1217 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1218 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 1224 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_4
# 1225 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1226 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1227 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 1228 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1229 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1230 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1231 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 1232 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_0
# 1233 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1234 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1235 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 1238 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 1239 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 1260 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1261 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 1279 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 1280 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1281 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1282 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 1284 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_4
# 1285 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 1291 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1292 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1293 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1294 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 1296 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1297 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1298 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1299 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1300 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1301 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1302 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1303 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1304 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1305 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1306 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1307 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 1159 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 1160 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1161 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1162 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1163 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1164 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 1158 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 1167 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 1168 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1169 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1170 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1171 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1172 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 1166 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 1175 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 1176 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1177 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1178 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 1174 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 1181 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 1182 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1183 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1184 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 1180 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 1240 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1241 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


Ikitown_trigger_GiveHalaSparklingStoneSkip::
# 1311 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1312 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1313 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1314 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1315 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1316 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1317 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1318 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1319 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1320 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1321 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1322 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1323 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1324 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1325 "data/maps/IkiTown/scripts.pory"
	waitstate
# 1326 "data/maps/IkiTown/scripts.pory"
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

# 142 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_2:
# 142 "data/maps/IkiTown/scripts.pory"
	delay_16
# 142 "data/maps/IkiTown/scripts.pory"
	delay_16
# 142 "data/maps/IkiTown/scripts.pory"
	delay_16
# 142 "data/maps/IkiTown/scripts.pory"
	delay_16
# 142 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 143 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_3:
# 143 "data/maps/IkiTown/scripts.pory"
	walk_up
# 143 "data/maps/IkiTown/scripts.pory"
	walk_up
# 143 "data/maps/IkiTown/scripts.pory"
	walk_up
# 143 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 148 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_4:
# 148 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 149 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_5:
# 149 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 154 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_6:
# 154 "data/maps/IkiTown/scripts.pory"
	shake_horizontal
	step_end

# 168 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_7:
# 168 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 187 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_8:
# 187 "data/maps/IkiTown/scripts.pory"
	walk_left
# 187 "data/maps/IkiTown/scripts.pory"
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

# 482 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_2:
# 482 "data/maps/IkiTown/scripts.pory"
	walk_right
# 482 "data/maps/IkiTown/scripts.pory"
	walk_right
# 482 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 496 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_3:
# 496 "data/maps/IkiTown/scripts.pory"
	walk_left
# 496 "data/maps/IkiTown/scripts.pory"
	walk_left
# 496 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 515 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage2_Movement_4:
# 515 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 515 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 545 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_0:
# 545 "data/maps/IkiTown/scripts.pory"
	walk_up
# 545 "data/maps/IkiTown/scripts.pory"
	walk_up
# 545 "data/maps/IkiTown/scripts.pory"
	walk_up
# 545 "data/maps/IkiTown/scripts.pory"
	walk_up
# 545 "data/maps/IkiTown/scripts.pory"
	delay_16
# 545 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 546 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_1:
# 546 "data/maps/IkiTown/scripts.pory"
	delay_16
# 546 "data/maps/IkiTown/scripts.pory"
	delay_16
# 546 "data/maps/IkiTown/scripts.pory"
	walk_up
# 546 "data/maps/IkiTown/scripts.pory"
	walk_up
# 546 "data/maps/IkiTown/scripts.pory"
	walk_up
# 546 "data/maps/IkiTown/scripts.pory"
	walk_up
# 546 "data/maps/IkiTown/scripts.pory"
	walk_up
# 546 "data/maps/IkiTown/scripts.pory"
	walk_up
# 546 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 547 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_2:
# 547 "data/maps/IkiTown/scripts.pory"
	delay_16
# 547 "data/maps/IkiTown/scripts.pory"
	walk_up
# 547 "data/maps/IkiTown/scripts.pory"
	walk_up
# 547 "data/maps/IkiTown/scripts.pory"
	walk_up
# 547 "data/maps/IkiTown/scripts.pory"
	walk_up
# 547 "data/maps/IkiTown/scripts.pory"
	walk_up
# 547 "data/maps/IkiTown/scripts.pory"
	walk_up
# 547 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 554 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_3:
# 554 "data/maps/IkiTown/scripts.pory"
	walk_left
# 554 "data/maps/IkiTown/scripts.pory"
	walk_left
# 554 "data/maps/IkiTown/scripts.pory"
	walk_left
# 554 "data/maps/IkiTown/scripts.pory"
	walk_left
# 554 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 557 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_4:
# 557 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 557 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 560 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_5:
# 560 "data/maps/IkiTown/scripts.pory"
	walk_right
# 560 "data/maps/IkiTown/scripts.pory"
	walk_right
# 560 "data/maps/IkiTown/scripts.pory"
	walk_right
# 560 "data/maps/IkiTown/scripts.pory"
	walk_right
# 560 "data/maps/IkiTown/scripts.pory"
	walk_right
# 560 "data/maps/IkiTown/scripts.pory"
	walk_right
# 560 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 570 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_6:
# 570 "data/maps/IkiTown/scripts.pory"
	walk_left
# 570 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 582 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 582 "data/maps/IkiTown/scripts.pory"
	walk_left
# 582 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 589 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 589 "data/maps/IkiTown/scripts.pory"
	walk_right
# 589 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 606 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitownSkip_Movement_0:
# 606 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 626 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 626 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 626 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 627 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 627 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 630 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
# 630 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 631 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 631 "data/maps/IkiTown/scripts.pory"
	delay_16
# 631 "data/maps/IkiTown/scripts.pory"
	delay_16
# 631 "data/maps/IkiTown/scripts.pory"
	delay_16
# 631 "data/maps/IkiTown/scripts.pory"
	delay_16
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 631 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 645 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 645 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 647 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 647 "data/maps/IkiTown/scripts.pory"
	walk_up
# 647 "data/maps/IkiTown/scripts.pory"
	walk_up
# 647 "data/maps/IkiTown/scripts.pory"
	walk_up
# 647 "data/maps/IkiTown/scripts.pory"
	walk_up
# 647 "data/maps/IkiTown/scripts.pory"
	walk_up
# 647 "data/maps/IkiTown/scripts.pory"
	walk_up
# 647 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 657 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 657 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 661 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 661 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 696 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 749 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 749 "data/maps/IkiTown/scripts.pory"
	face_down
# 749 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 754 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 754 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 886 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_left
# 886 "data/maps/IkiTown/scripts.pory"
	walk_left
# 886 "data/maps/IkiTown/scripts.pory"
	walk_left
# 886 "data/maps/IkiTown/scripts.pory"
	walk_left
# 886 "data/maps/IkiTown/scripts.pory"
	walk_left
# 886 "data/maps/IkiTown/scripts.pory"
	walk_left
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_down
# 886 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 886 "data/maps/IkiTown/scripts.pory"
	walk_right
# 886 "data/maps/IkiTown/scripts.pory"
	walk_right
# 886 "data/maps/IkiTown/scripts.pory"
	walk_right
# 886 "data/maps/IkiTown/scripts.pory"
	walk_up
# 886 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 887 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 887 "data/maps/IkiTown/scripts.pory"
	delay_16
# 887 "data/maps/IkiTown/scripts.pory"
	delay_16
# 887 "data/maps/IkiTown/scripts.pory"
	delay_16
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_left
# 887 "data/maps/IkiTown/scripts.pory"
	walk_left
# 887 "data/maps/IkiTown/scripts.pory"
	walk_left
# 887 "data/maps/IkiTown/scripts.pory"
	walk_left
# 887 "data/maps/IkiTown/scripts.pory"
	walk_left
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_down
# 887 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 887 "data/maps/IkiTown/scripts.pory"
	walk_right
# 887 "data/maps/IkiTown/scripts.pory"
	walk_right
# 887 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 890 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 890 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 890 "data/maps/IkiTown/scripts.pory"
	walk_down
# 890 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 901 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 901 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 901 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 938 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 938 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 940 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 940 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 940 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 953 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 953 "data/maps/IkiTown/scripts.pory"
	walk_down
# 953 "data/maps/IkiTown/scripts.pory"
	delay_16
# 953 "data/maps/IkiTown/scripts.pory"
	delay_16
# 953 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 954 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 954 "data/maps/IkiTown/scripts.pory"
	walk_up
# 954 "data/maps/IkiTown/scripts.pory"
	walk_up
# 954 "data/maps/IkiTown/scripts.pory"
	walk_up
# 954 "data/maps/IkiTown/scripts.pory"
	walk_up
# 954 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 958 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 958 "data/maps/IkiTown/scripts.pory"
	walk_left
# 958 "data/maps/IkiTown/scripts.pory"
	walk_left
# 958 "data/maps/IkiTown/scripts.pory"
	walk_left
# 958 "data/maps/IkiTown/scripts.pory"
	walk_left
# 958 "data/maps/IkiTown/scripts.pory"
	walk_left
# 958 "data/maps/IkiTown/scripts.pory"
	walk_left
# 958 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 965 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 965 "data/maps/IkiTown/scripts.pory"
	walk_left
# 965 "data/maps/IkiTown/scripts.pory"
	walk_left
# 965 "data/maps/IkiTown/scripts.pory"
	walk_left
# 965 "data/maps/IkiTown/scripts.pory"
	walk_left
# 965 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 965 "data/maps/IkiTown/scripts.pory"
	walk_left
# 965 "data/maps/IkiTown/scripts.pory"
	walk_left
# 965 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1026 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 1026 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1026 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1057 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 1057 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1057 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1057 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 1159 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 1159 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1159 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1159 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1159 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1163 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1163 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1167 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 1167 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1167 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1167 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1167 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1167 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1167 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1175 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 1175 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1175 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1175 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1175 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1175 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1175 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1175 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1175 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1181 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1181 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1181 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1188 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 1188 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1188 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1188 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1188 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 1190 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 1190 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1190 "data/maps/IkiTown/scripts.pory"
	delay_8
# 1190 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1279 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 1279 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_Trigger_FestivalBattle_Text_0:
# 80 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_Trigger_FestivalBattle_Text_1:
# 81 "data/maps/IkiTown/scripts.pory"
	.string "The Alola Region is made up of our\n"
	.string "four islands.\p"
	.string "And each island has its own guardian\n"
	.string "Pokémon.\p"
	.string "Our festival today is help to express\n"
	.string "our thanks to these great Pokémon\l"
	.string "guardian dieties for always\l"
	.string "remaining by our sides.\p"
	.string "Well, we may call it a festival, but it's\n"
	.string "just this little thing you see here.\p"
	.string "There may not be many of us, but at\n"
	.string "least every last one of us here goes\l"
	.string "all out.$"

Ikitown_Trigger_FestivalBattle_Text_2:
# 100 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_Trigger_FestivalBattle_Text_3:
# 103 "data/maps/IkiTown/scripts.pory"
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
# 121 "data/maps/IkiTown/scripts.pory"
	.string "Hoo!$"

Ikitown_Trigger_FestivalBattle_Text_7:
# 127 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Litten've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_8:
# 133 "data/maps/IkiTown/scripts.pory"
	.string "Grrr!$"

Ikitown_Trigger_FestivalBattle_Text_9:
# 138 "data/maps/IkiTown/scripts.pory"
	.string "Hold on… Didn't anyone explain to\n"
	.string "you about tonight?!$"

Ikitown_Trigger_FestivalBattle_Text_10:
# 146 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_Trigger_FestivalBattle_Text_11:
# 147 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah, right on time!$"

Ikitown_Trigger_FestivalBattle_Text_12:
# 151 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_Trigger_FestivalBattle_Text_13:
# 152 "data/maps/IkiTown/scripts.pory"
	.string "But to what exactly?$"

Ikitown_Trigger_FestivalBattle_Text_14:
# 157 "data/maps/IkiTown/scripts.pory"
	.string "Pew!!$"

Ikitown_Trigger_FestivalBattle_Text_15:
# 161 "data/maps/IkiTown/scripts.pory"
	.string "A full-powered festival for Pokemon\n"
	.string "battling!\p"
	.string "We battle in the name of Tapu Koko,\n"
	.string "pitting our best move against one\l"
	.string "another in friendly competition to\l"
	.string "please our guardian. Woo!$"

Ikitown_Trigger_FestivalBattle_Text_16:
# 171 "data/maps/IkiTown/scripts.pory"
	.string "So, you two will be taking part in\n"
	.string "battle?\p"
	.string "I don't like seeing Pokémon fight one\n"
	.string "another…they often end up hurt.\p"
	.string "But…I'll be sure to watch you both.$"

Ikitown_Trigger_FestivalBattle_Text_17:
# 182 "data/maps/IkiTown/scripts.pory"
	.string "Your Pokémon have fought for you, so\n"
	.string "show them the same care in return,\l"
	.string "{PLAYER}.\p"
	.string "Allow me to heal them for you this time.$"

Ikitown_Trigger_FestivalBattle_Text_18:
# 196 "data/maps/IkiTown/scripts.pory"
	.string "Are you ready for this Pokémon battle?$"

Ikitown_Trigger_FestivalBattle_Text_19:
# 199 "data/maps/IkiTown/scripts.pory"
	.string "Then let's begin!$"

Ikitown_Trigger_FestivalBattle_Text_20:
# 204 "data/maps/IkiTown/scripts.pory"
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
# 340 "data/maps/IkiTown/scripts.pory"
	.string "{PLAYER}! Hau!\n"
	.string "Bring forth the power of your Pokémon!$"

Ikitown_FestivalBattleOnStage2_Text_1:
# 345 "data/maps/IkiTown/scripts.pory"
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
# 439 "data/maps/IkiTown/scripts.pory"
	.string "Well, it's time for you to get out there\n"
	.string "and start your {COLOR RED}island challenge{COLOR DARK_GRAY}!\p"
	.string "If you visit every island, maybe you'll\n"
	.string "figure out what that mission is.$"

Ikitown_FestivalBattleOnStage2_Text_11:
# 444 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge?$"

Ikitown_FestivalBattleOnStage2_Text_12:
# 444 "data/maps/IkiTown/scripts.pory"
	.string "Every Island?$"

Ikitown_FestivalBattleOnStage2_Text_13:
# 447 "data/maps/IkiTown/scripts.pory"
	.string "Four Islands!\p"
	.string "You'll travel to each of the four\n"
	.string "islands here in the Alola Region.$"

Ikitown_FestivalBattleOnStage2_Text_14:
# 460 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge is about aiming to\n"
	.string "be the strongest Trainer-\l"
	.string "the {COLOR RED}island challenge champion{COLOR DARK_GRAY}. Woo!$"

Ikitown_FestivalBattleOnStage2_Text_15:
# 466 "data/maps/IkiTown/scripts.pory"
	.string "Sounds great, right?\n"
	.string "I can't wait to have a real adventure!$"

Ikitown_FestivalBattleOnStage2_Text_16:
# 471 "data/maps/IkiTown/scripts.pory"
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
# 485 "data/maps/IkiTown/scripts.pory"
	.string "Allow me to give you both the island\n"
	.string "challenge amulets you will need.$"

Ikitown_FestivalBattleOnStage2_Text_18:
# 490 "data/maps/IkiTown/scripts.pory"
	.string "Awesome!\n"
	.string "Thanks, Tutu!\p"
	.string "I'm gonna make it through the island\n"
	.string "challenge to try to become an island\l"
	.string "challenge champion!$"

Ikitown_FestivalBattleOnStage2_Text_19:
# 499 "data/maps/IkiTown/scripts.pory"
	.string "There is one for you was well,\n"
	.string "{PLAYER}.\p"
	.string "Please do give the island challenge\n"
	.string "a try.$"

Ikitown_FestivalBattleOnStage2_Text_20:
# 506 "data/maps/IkiTown/scripts.pory"
	.string "You received the {COLOR RED}Island Challenge\n"
	.string "Amulet{COLOR DARK_GRAY}!$"

Ikitown_FestivalBattleOnStage2_Text_21:
# 513 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, doing the island challenge is the\n"
	.string "best way to really get to know Alola!$"

Ikitown_trigger_WecomeToIkitown_Text_0:
# 642 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 650 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 664 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 673 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 684 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 688 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 692 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 702 "data/maps/IkiTown/scripts.pory"
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
# 720 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 737 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 761 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 772 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 785 "data/maps/IkiTown/scripts.pory"
	.string "Ruff ruff!$"

Ikitown_LeftSideGuy_Text_0:
# 794 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 804 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 818 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 830 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 843 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 853 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 869 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 877 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 893 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 899 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 904 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_3:
# 914 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_4:
# 922 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 931 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_6:
# 945 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_7:
# 957 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_8:
# 963 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_9:
# 970 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_10:
# 982 "data/maps/IkiTown/scripts.pory"
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
# 999 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_12:
# 1004 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_13:
# 1010 "data/maps/IkiTown/scripts.pory"
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
# 1030 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_15:
# 1036 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_16:
# 1041 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_17:
# 1051 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 1108 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 1121 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 1133 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 1145 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 1195 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 1200 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 1218 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 1227 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 1231 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 1235 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 1238 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 1238 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 1241 "data/maps/IkiTown/scripts.pory"
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
# 1282 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 1285 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 1294 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will key an eye on Nebby$"
