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
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 79 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 80 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_1, MSGBOX_AUTOCLOSE
# 97 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 98 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 99 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 100 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_Trigger_FestivalBattle_2
# 112 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_Trigger_FestivalBattle_3
# 124 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_Trigger_FestivalBattle_4
Ikitown_Trigger_FestivalBattle_1:
# 136 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 137 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_9, MSGBOX_AUTOCLOSE
# 139 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_kukui_festival
# 140 "data/maps/IkiTown/scripts.pory"
	addobject ikitown_lillie_festival
# 141 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_2
# 142 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 143 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_3
# 144 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 145 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 146 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_11, MSGBOX_AUTOCLOSE
# 147 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_4
# 148 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 149 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 150 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 151 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_13, MSGBOX_AUTOCLOSE
# 152 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 153 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_6
# 154 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 155 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 156 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_14, MSGBOX_AUTOCLOSE
# 157 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 158 "data/maps/IkiTown/scripts.pory"
	delay 30
# 159 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 160 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_15, MSGBOX_AUTOCLOSE
# 167 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_Trigger_FestivalBattle_Movement_7
# 168 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 169 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 170 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_16
# 177 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 178 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 179 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 180 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 181 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_17
# 186 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_8
# 187 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 188 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 189 "data/maps/IkiTown/scripts.pory"
	special HealPlayerParty
# 190 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_HEAL
# 191 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 192 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
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
# 102 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_3, MSGBOX_AUTOCLOSE
# 104 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 105 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 106 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 107 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 108 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_4, MSGBOX_AUTOCLOSE
# 109 "data/maps/IkiTown/scripts.pory"
	waitmoncry
# 110 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
	goto Ikitown_Trigger_FestivalBattle_1

Ikitown_Trigger_FestivalBattle_3:
# 114 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_5, MSGBOX_AUTOCLOSE
# 116 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 117 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_dynhaumon_festival, Ikitown_Trigger_FestivalBattle_Movement_1
# 118 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 119 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 120 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_6, MSGBOX_AUTOCLOSE
# 121 "data/maps/IkiTown/scripts.pory"
	waitmoncry
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
	waitmovement 0
# 131 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 132 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_8, MSGBOX_AUTOCLOSE
# 133 "data/maps/IkiTown/scripts.pory"
	waitmoncry
# 134 "data/maps/IkiTown/scripts.pory"
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


Ikitown_FestivalBattleSaidNo::
# 210 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 211 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_18, MSGBOX_YESNO
# 212 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Ikitown_FestivalBattleSaidNo_1
# 218 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 219 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_20, MSGBOX_AUTOCLOSE
# 221 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleSaidNo
	return

Ikitown_FestivalBattleSaidNo_1:
# 213 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 214 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Trigger_FestivalBattle_Text_19, MSGBOX_AUTOCLOSE
# 215 "data/maps/IkiTown/scripts.pory"
	call Ikitown_FestivalBattleOnStage
	return


Ikitown_FestivalBattleOnStage::
# 226 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 228 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_FestivalBattleOnStage_Movement_0
# 230 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_lillie_festival, Ikitown_FestivalBattleOnStage_Movement_1
# 232 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_2
# 234 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_3
# 236 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_FestivalBattleOnStage_Movement_4
# 237 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 238 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 239 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_FestivalBattleOnStage_Movement_5
# 240 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 241 "data/maps/IkiTown/scripts.pory"
	hideobjectat ikitown_dynhaumon_festival, MAP_IKI_TOWN
# 242 "data/maps/IkiTown/scripts.pory"
	delay 30
# 243 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 244 "data/maps/IkiTown/scripts.pory"
	delay 30
# 245 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 246 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 247 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 248 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_0, MSGBOX_AUTOCLOSE
# 262 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 263 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 264 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_FestivalBattleOnStage_2
# 268 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_FestivalBattleOnStage_3
# 272 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_FestivalBattleOnStage_4
Ikitown_FestivalBattleOnStage_1:
# 276 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 277 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 278 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 279 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_4, MSGBOX_AUTOCLOSE
# 281 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 282 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_5, MSGBOX_AUTOCLOSE
# 286 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 287 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_mom_festival, Ikitown_FestivalBattleOnStage_Movement_7
# 288 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 289 "data/maps/IkiTown/scripts.pory"
	waitse
# 290 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 291 "data/maps/IkiTown/scripts.pory"
	waitse
# 292 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_FestivalBattleOnStage_Text_6
# 293 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 294 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_7, MSGBOX_AUTOCLOSE
# 296 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 297 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 298 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 299 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_8, MSGBOX_AUTOCLOSE
# 302 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 303 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 304 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 305 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_9, MSGBOX_AUTOCLOSE
# 307 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq Ikitown_FestivalBattleOnStage_9
# 317 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq Ikitown_FestivalBattleOnStage_10
# 327 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq Ikitown_FestivalBattleOnStage_11
Ikitown_FestivalBattleOnStage_8:
# 337 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 338 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 339 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_11, MSGBOX_AUTOCLOSE
# 342 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 343 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 344 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 345 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 346 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_12
# 348 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_8
# 349 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 350 "data/maps/IkiTown/scripts.pory"
	waitse
# 351 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 352 "data/maps/IkiTown/scripts.pory"
	waitse
# 353 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_13, MSGBOX_AUTOCLOSE
# 355 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 356 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 357 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 358 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_14
# 360 "data/maps/IkiTown/scripts.pory"
	closemessage
# 361 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 362 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_TAPU_KOKO, 0
# 363 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_15, MSGBOX_AUTOCLOSE
# 364 "data/maps/IkiTown/scripts.pory"
	waitmoncry
# 365 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 366 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 367 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 368 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 369 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_16, MSGBOX_AUTOCLOSE
# 371 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_9
# 372 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 373 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_17, MSGBOX_AUTOCLOSE
# 375 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 376 "data/maps/IkiTown/scripts.pory"
	giveitem ITEM_Z_POWER_RING
# 377 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 378 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 379 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_18, MSGBOX_AUTOCLOSE
# 400 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 401 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 402 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 403 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_19
# 408 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 20, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_FestivalBattleOnStage_Text_20, Ikitown_FestivalBattleOnStage_Text_21
# 409 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_FestivalBattleOnStage_16
# 417 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 418 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_22
Ikitown_FestivalBattleOnStage_15:
# 423 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 424 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_23, MSGBOX_AUTOCLOSE
# 427 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 428 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 429 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 430 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_24, MSGBOX_AUTOCLOSE
# 432 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 433 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 434 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 435 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_25
# 446 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_10
# 447 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 448 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 449 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_26, MSGBOX_AUTOCLOSE
# 451 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hau_festival, Ikitown_FestivalBattleOnStage_Movement_6
# 452 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 453 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 454 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_27, MSGBOX_AUTOCLOSE
# 460 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_hala_festival, Ikitown_FestivalBattleOnStage_Movement_11
# 461 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 462 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 463 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_28, MSGBOX_AUTOCLOSE
# 468 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 469 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_SYMBOL
# 470 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_29, MSGBOX_AUTOCLOSE
# 472 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 473 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 474 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_kukui_festival, Ikitown_Trigger_FestivalBattle_Movement_0
# 475 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 476 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 477 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_30
# 479 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_FestivalBattleOnStage_Movement_12
# 480 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 481 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 482 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_FestivalBattleOnStage_2:
# 265 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 266 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_1, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1

Ikitown_FestivalBattleOnStage_3:
# 269 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 270 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_2, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1

Ikitown_FestivalBattleOnStage_4:
# 273 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 274 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_3, MSGBOX_AUTOCLOSE
	goto Ikitown_FestivalBattleOnStage_1

Ikitown_FestivalBattleOnStage_9:
# 308 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage_19
# 314 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIO, Ikitown_FestivalBattleOnStage_Text_10
	goto Ikitown_FestivalBattleOnStage_8

Ikitown_FestivalBattleOnStage_10:
# 318 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage_22
# 324 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLET, Ikitown_FestivalBattleOnStage_Text_10
	goto Ikitown_FestivalBattleOnStage_8

Ikitown_FestivalBattleOnStage_11:
# 328 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, Ikitown_FestivalBattleOnStage_25
# 334 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTEN, Ikitown_FestivalBattleOnStage_Text_10
	goto Ikitown_FestivalBattleOnStage_8

Ikitown_FestivalBattleOnStage_16:
# 410 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 411 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_FestivalBattleOnStage_Text_22
	goto Ikitown_FestivalBattleOnStage_15

Ikitown_FestivalBattleOnStage_19:
# 310 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_POPPLIOSHINY, Ikitown_FestivalBattleOnStage_Text_10
	goto Ikitown_FestivalBattleOnStage_8

Ikitown_FestivalBattleOnStage_22:
# 320 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_ROWLETSHINY, Ikitown_FestivalBattleOnStage_Text_10
	goto Ikitown_FestivalBattleOnStage_8

Ikitown_FestivalBattleOnStage_25:
# 330 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWNFESTIVAL_LITTENSHINY, Ikitown_FestivalBattleOnStage_Text_10
	goto Ikitown_FestivalBattleOnStage_8


Ikitown_StartFestival::
# 488 "data/maps/IkiTown/scripts.pory"
	lockplayer
# 489 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_0
# 490 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_exeggutor_festival, Ikitown_StartFestival_Movement_1
# 491 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_oldman_festival, Ikitown_StartFestival_Movement_2
# 492 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 493 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 494 "data/maps/IkiTown/scripts.pory"
	delay 30
# 495 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_exeggutor_festival
# 496 "data/maps/IkiTown/scripts.pory"
	removeobject ikitown_oldman_festival
# 497 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 498 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_3
# 499 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 500 "data/maps/IkiTown/scripts.pory"
	delay 30
# 501 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_woman_festival, Ikitown_StartFestival_Movement_4
# 502 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 503 "data/maps/IkiTown/scripts.pory"
	delay 30
# 504 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_5
# 505 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 506 "data/maps/IkiTown/scripts.pory"
	delay 30
# 507 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_rockruff_festival, Ikitown_Trigger_FestivalBattle_Movement_5
# 508 "data/maps/IkiTown/scripts.pory"
	applymovement ikitown_littlegirl_festival, Ikitown_FestivalBattleOnStage_Movement_8
# 509 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 510 "data/maps/IkiTown/scripts.pory"
	waitse
# 511 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 512 "data/maps/IkiTown/scripts.pory"
	waitse
# 513 "data/maps/IkiTown/scripts.pory"
	delay 30
# 514 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_6
# 515 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 516 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 517 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 14
# 518 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_right::
# 524 "data/maps/IkiTown/scripts.pory"
	lock
# 525 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_right_Movement_0
# 526 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 527 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_left::
# 531 "data/maps/IkiTown/scripts.pory"
	lock
# 532 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_left_Movement_0
# 533 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 534 "data/maps/IkiTown/scripts.pory"
	call Ikitown_trigger_WecomeToIkitown
	return


Ikitown_trigger_WecomeToIkitownSkip::
# 538 "data/maps/IkiTown/scripts.pory"
	closemessage
# 539 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 540 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 541 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 542 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 543 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 544 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 545 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 546 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 547 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 548 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui, 33, 28
# 549 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 550 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 551 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau, MAP_IKI_TOWN
# 552 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 553 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 554 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_WecomeToIkitown::
# 559 "data/maps/IkiTown/scripts.pory"
	lock
# 560 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 561 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 562 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_KUKUI
# 563 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 564 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownhau, MAP_IKI_TOWN_SOUTH
# 565 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownkukui, MAP_IKI_TOWN_SOUTH
# 566 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 567 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui
# 568 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_WELCOME_TO_IKITOWN
# 569 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_0
# 570 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_1
# 571 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 572 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 573 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_2
# 574 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_3
# 575 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 576 "data/maps/IkiTown/scripts.pory"
	delay 30
# 577 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 578 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 579 "data/maps/IkiTown/scripts.pory"
	delay 30
# 580 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 581 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 582 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 583 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 584 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 585 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_0, MSGBOX_AUTOCLOSE
# 587 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 588 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_4
# 589 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 590 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_5
# 591 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 592 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 593 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_1
# 599 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 600 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_trigger_WecomeToIkitown_Movement_6
# 601 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 602 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 603 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 604 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_trigger_WecomeToIkitown_Movement_7
# 605 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 606 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 607 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_2
# 613 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_Trigger_FestivalBattle_Movement_0
# 614 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 615 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 616 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_3
# 619 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_FestivalBattleOnStage_Movement_7
# 620 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 621 "data/maps/IkiTown/scripts.pory"
	waitse
# 622 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 623 "data/maps/IkiTown/scripts.pory"
	waitse
# 624 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 625 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 626 "data/maps/IkiTown/scripts.pory"
	case 0, Ikitown_trigger_WecomeToIkitown_3
# 630 "data/maps/IkiTown/scripts.pory"
	case 1, Ikitown_trigger_WecomeToIkitown_4
# 634 "data/maps/IkiTown/scripts.pory"
	case 2, Ikitown_trigger_WecomeToIkitown_5
Ikitown_trigger_WecomeToIkitown_1:
# 639 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_WecomeToIkitown_Movement_8
# 640 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 641 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownintrohau
# 642 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_FestivalBattle_Movement_0
# 643 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 645 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_7
# 657 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_FestivalBattleOnStage_Movement_7
# 658 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 659 "data/maps/IkiTown/scripts.pory"
	waitse
# 660 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 661 "data/maps/IkiTown/scripts.pory"
	waitse
# 662 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 663 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_8
# 669 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 2
# 670 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 671 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 672 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_trigger_WecomeToIkitown_3:
# 627 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_4, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_4:
# 631 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_5, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1

Ikitown_trigger_WecomeToIkitown_5:
# 635 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_WecomeToIkitown_Text_6, MSGBOX_AUTOCLOSE
	goto Ikitown_trigger_WecomeToIkitown_1


Ikitown_KukuiSeeTapuKoko::
# 677 "data/maps/IkiTown/scripts.pory"
	lock
# 678 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 679 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 680 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 682 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_KukuiSeeTapuKoko::
# 688 "data/maps/IkiTown/scripts.pory"
	lock
# 689 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 690 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 691 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 692 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0
# 693 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 694 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 695 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiSeeTapuKoko_Text_0
# 697 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1
# 698 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MainSign::
# 703 "data/maps/IkiTown/scripts.pory"
	lock
# 704 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MainSign_Text_0
# 707 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 708 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LittleBoyWRockruff::
# 713 "data/maps/IkiTown/scripts.pory"
	lock
# 714 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 715 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LittleBoyWRockruff_Text_0
# 719 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 720 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Rockruff::
# 725 "data/maps/IkiTown/scripts.pory"
	lock
# 726 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 727 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 728 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Rockruff_Text_0
# 729 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 730 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_LeftSideGuy::
# 735 "data/maps/IkiTown/scripts.pory"
	lock
# 736 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 737 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_LeftSideGuy_Text_0
# 739 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 740 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_MomwithChild::
# 745 "data/maps/IkiTown/scripts.pory"
	lock
# 746 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 747 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_MomwithChild_Text_0
# 753 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 754 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ChildwithMom::
# 759 "data/maps/IkiTown/scripts.pory"
	lock
# 760 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 761 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ChildwithMom_Text_0
# 765 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 766 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_DontForgetToSave::
# 771 "data/maps/IkiTown/scripts.pory"
	lock
# 772 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 773 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_DontForgetToSave_Text_0
# 778 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 779 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KahunaGivesWisdom::
# 784 "data/maps/IkiTown/scripts.pory"
	lock
# 785 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 786 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KahunaGivesWisdom_Text_0
# 789 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_ManBlockingDoor::
# 794 "data/maps/IkiTown/scripts.pory"
	lock
# 795 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 796 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_ManBlockingDoor_Text_0
# 804 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Meowth::
# 809 "data/maps/IkiTown/scripts.pory"
	lock
# 810 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 811 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 812 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_Meowth_Text_0
# 813 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 814 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_sign_Ruinsofconflict::
# 819 "data/maps/IkiTown/scripts.pory"
	lock
# 820 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_sign_Ruinsofconflict_Text_0
# 821 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 822 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_GetPokedex::
# 827 "data/maps/IkiTown/scripts.pory"
	lock
# 828 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GET_POKEDEX
# 829 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_0
# 830 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_GetPokedex_Movement_1
# 831 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 832 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 833 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_2
# 834 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 835 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 836 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_0
# 840 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 841 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 842 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_1
# 844 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 845 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 846 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 847 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_2
# 854 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 855 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_GetPokedex_2
# 864 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 865 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_4
Ikitown_GetPokedex_1:
# 871 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_0
# 872 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 873 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 874 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_5, MSGBOX_AUTOCLOSE
# 878 "data/maps/IkiTown/scripts.pory"
	special SpawnCameraObject
# 879 "data/maps/IkiTown/scripts.pory"
	delay 30
# 881 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_4
# 882 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 883 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownman1, Ikitown_GetPokedex_Movement_5
# 884 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownoldman1, Ikitown_GetPokedex_Movement_5
# 885 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 886 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 887 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 888 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_6, MSGBOX_AUTOCLOSE
# 895 "data/maps/IkiTown/scripts.pory"
	delay 30
# 896 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_6
# 897 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_7
# 898 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 899 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 900 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_7, MSGBOX_AUTOCLOSE
# 901 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_GetPokedex_Movement_8
# 902 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 903 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_5
# 904 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 905 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 906 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_8
# 908 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_GetPokedex_Movement_9
# 909 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 910 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 911 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 912 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 913 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_9
# 922 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 923 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 924 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 925 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_10
# 939 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_FestivalBattleOnStage_Movement_6
# 940 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 941 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 942 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_11
# 944 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 945 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 946 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 947 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_12
# 951 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_FestivalBattleOnStage_Movement_6
# 952 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 953 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_13
# 969 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_10
# 970 "data/maps/IkiTown/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Ikitown_StartFestival_Movement_6
# 971 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 972 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 973 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_14
# 975 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 976 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 977 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 978 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 979 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_15
# 980 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 981 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 982 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 983 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 984 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_16
# 994 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_17, MSGBOX_AUTOCLOSE
# 998 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 999 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1000 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_GetPokedex_Movement_11
# 1001 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1002 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1003 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1004 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1005 "data/maps/IkiTown/scripts.pory"
	release
	end

Ikitown_GetPokedex_2:
# 856 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 857 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_GetPokedex_Text_3
	goto Ikitown_GetPokedex_1


Ikitown_GetPokedexSkip::
# 1010 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1011 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1012 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1013 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1014 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1015 "data/maps/IkiTown/scripts.pory"
	special RemoveCameraObject
# 1016 "data/maps/IkiTown/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
# 1017 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 1018 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 7
# 1020 "data/maps/IkiTown/scripts.pory"
	setobjectxy LOCALID_PLAYER, 21, 14
# 1021 "data/maps/IkiTown/scripts.pory"
	special SnapCameraToPlayer
# 1026 "data/maps/IkiTown/scripts.pory"
	addobject ikitownlillie
# 1027 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhala
# 1028 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrokukui2
# 1029 "data/maps/IkiTown/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_IKI_TOWN
# 1030 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownlillie, MAP_IKI_TOWN
# 1031 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownhala, MAP_IKI_TOWN
# 1032 "data/maps/IkiTown/scripts.pory"
	showobjectat ikitownintrokukui2, MAP_IKI_TOWN
# 1033 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownlillie, 21, 13
# 1034 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 14
# 1035 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 13
# 1036 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_5
# 1037 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1038 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_4
# 1039 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1040 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1041 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1042 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_lilliedialog2::
# 1047 "data/maps/IkiTown/scripts.pory"
	lock
# 1048 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1049 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 1050 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1051 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_lilliedialog2_Text_0
# 1055 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1056 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_kukuidialog2::
# 1061 "data/maps/IkiTown/scripts.pory"
	lock
# 1062 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1063 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1064 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_kukuidialog2_Text_0
# 1067 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1068 "data/maps/IkiTown/scripts.pory"
	release
	end


ikitown_haladialog2::
# 1073 "data/maps/IkiTown/scripts.pory"
	lock
# 1074 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 1075 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1076 "data/maps/IkiTown/scripts.pory"
	msgbox ikitown_haladialog2_Text_0
# 1079 "data/maps/IkiTown/scripts.pory"
	waitmessage
# 1080 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_trigger_GiveHalaSparklingStone::
# 1085 "data/maps/IkiTown/scripts.pory"
	lock
# 1086 "data/maps/IkiTown/scripts.pory"
	startcutscene CUTSCENE_IKITOWN_GIVE_HALA_SPARKLING_STONE
# 1087 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1088 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_0, MSGBOX_AUTOCLOSE
# 1090 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1091 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_WecomeToIkitown_Movement_7
# 1092 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1093 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1094 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownhala, 24, 12
# 1095 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrokukui2, 23, 12
# 1096 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1097 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1098 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1099 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1100 "data/maps/IkiTown/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 1101 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_3
Ikitown_trigger_GiveHalaSparklingStone_1:
# 1109 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 28
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_8
Ikitown_trigger_GiveHalaSparklingStone_6:
# 1117 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_13
Ikitown_trigger_GiveHalaSparklingStone_11:
# 1123 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_1, 17
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_18
Ikitown_trigger_GiveHalaSparklingStone_16:
# 1129 "data/maps/IkiTown/scripts.pory"
	delay 30
# 1130 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1131 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_5
# 1132 "data/maps/IkiTown/scripts.pory"
	delay 60
# 1133 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_GiveHalaSparklingStone_Movement_6
# 1134 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1135 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_Trigger_FestivalBattle_Movement_5
# 1136 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1137 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1138 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_1
# 1140 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1141 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1142 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1143 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_2
# 1149 "data/maps/IkiTown/scripts.pory"
	setvar VAR_RESULT, 1
# 1150 "data/maps/IkiTown/scripts.pory"
	playse SE_M_DETECT
# 1151 "data/maps/IkiTown/scripts.pory"
	dofieldeffectsparkle 24, 14, 0
# 1152 "data/maps/IkiTown/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 1153 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1154 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 1155 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattleleft_Movement_0
# 1156 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1157 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_trigger_WecomeToIkitownSkip_Movement_0
# 1158 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_FestivalBattle_Movement_7
# 1159 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1160 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1161 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_3
# 1167 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_StartFestival_Movement_4
# 1168 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1169 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1170 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_4
# 1171 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_GetPokedex_Movement_3
# 1172 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1173 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_2
# 1174 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_5
# 1175 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhala, Ikitown_Trigger_FestivalBattle_Movement_0
# 1176 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1177 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1178 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_6
# 1181 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, Ikitown_trigger_GiveHalaSparklingStone_Text_7, Ikitown_trigger_GiveHalaSparklingStone_Text_8
# 1182 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_22
# 1203 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1204 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
Ikitown_trigger_GiveHalaSparklingStone_21:
# 1222 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_trigger_GiveHalaSparklingStone_Movement_7
# 1223 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1224 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_10
# 1225 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_10
# 1227 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrokukui2, Ikitown_Trigger_FestivalBattle_Movement_4
# 1228 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_11
# 1234 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownlillie, Ikitown_GetPokedex_Movement_3
# 1235 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1236 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_12
# 1237 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_12
# 1239 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1240 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1241 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1242 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1243 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1244 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1245 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1246 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1247 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1248 "data/maps/IkiTown/scripts.pory"
	endcutscene
# 1249 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1250 "data/maps/IkiTown/scripts.pory"
	waitstate
	return

Ikitown_trigger_GiveHalaSparklingStone_2:
# 1102 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_0
# 1103 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1104 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1105 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1106 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1107 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_3:
# 1101 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_2
	goto Ikitown_trigger_GiveHalaSparklingStone_1

Ikitown_trigger_GiveHalaSparklingStone_7:
# 1110 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_2
# 1111 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1112 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1113 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 27, 15
# 1114 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownintrohau, Ikitown_trigger_GiveHalaSparklingStone_Movement_1
# 1115 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_8:
# 1109 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_7
	goto Ikitown_trigger_GiveHalaSparklingStone_6

Ikitown_trigger_GiveHalaSparklingStone_12:
# 1118 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_3
# 1119 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1120 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1121 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_13:
# 1117 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 14
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_12
	goto Ikitown_trigger_GiveHalaSparklingStone_11

Ikitown_trigger_GiveHalaSparklingStone_17:
# 1124 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_trigger_GiveHalaSparklingStone_Movement_4
# 1125 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 1126 "data/maps/IkiTown/scripts.pory"
	addobject ikitownintrohau
# 1127 "data/maps/IkiTown/scripts.pory"
	setobjectxy ikitownintrohau, 16, 15
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_18:
# 1123 "data/maps/IkiTown/scripts.pory"
	compare VAR_TEMP_2, 15
	goto_if_eq Ikitown_trigger_GiveHalaSparklingStone_17
	goto Ikitown_trigger_GiveHalaSparklingStone_16

Ikitown_trigger_GiveHalaSparklingStone_22:
# 1183 "data/maps/IkiTown/scripts.pory"
	speakername Ikitown_Trigger_FestivalBattle_Text_0
# 1184 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_trigger_GiveHalaSparklingStone_Text_9
	goto Ikitown_trigger_GiveHalaSparklingStone_21


Ikitown_trigger_GiveHalaSparklingStoneSkip::
# 1254 "data/maps/IkiTown/scripts.pory"
	closemessage
# 1255 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1256 "data/maps/IkiTown/scripts.pory"
	special StopAllObjectMovements
# 1257 "data/maps/IkiTown/scripts.pory"
	special CloseScriptMenus
# 1258 "data/maps/IkiTown/scripts.pory"
	special HideCutsceneCinematicBars
# 1259 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_HALA
# 1260 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_INTRO_HAU
# 1261 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 8
# 1262 "data/maps/IkiTown/scripts.pory"
	setvar VAR_HAUOLI_OUTSKIRTS_STATE, 1
# 1263 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HAUOLI_OUTSKIRTS_NEWGAME
# 1264 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_MOM_IN_HOUSE_INTRO
# 1265 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_HIDE_PLAYER_MOM3
# 1266 "data/maps/IkiTown/scripts.pory"
	removeitem ITEM_SPARKLING_STONE, 1
# 1267 "data/maps/IkiTown/scripts.pory"
	warp MAP_PLAYER_HOUSE, 8, 15
# 1268 "data/maps/IkiTown/scripts.pory"
	waitstate
# 1269 "data/maps/IkiTown/scripts.pory"
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

# 78 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_0:
# 78 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
# 78 "data/maps/IkiTown/scripts.pory"
	walk_in_place_down
	step_end

# 117 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_1:
# 117 "data/maps/IkiTown/scripts.pory"
	face_left
# 117 "data/maps/IkiTown/scripts.pory"
	face_up
# 117 "data/maps/IkiTown/scripts.pory"
	face_right
# 117 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 141 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_2:
# 141 "data/maps/IkiTown/scripts.pory"
	delay_16
# 141 "data/maps/IkiTown/scripts.pory"
	delay_16
# 141 "data/maps/IkiTown/scripts.pory"
	delay_16
# 141 "data/maps/IkiTown/scripts.pory"
	delay_16
# 141 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 142 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_3:
# 142 "data/maps/IkiTown/scripts.pory"
	walk_up
# 142 "data/maps/IkiTown/scripts.pory"
	walk_up
# 142 "data/maps/IkiTown/scripts.pory"
	walk_up
# 142 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 147 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_4:
# 147 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 148 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_5:
# 148 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 153 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_6:
# 153 "data/maps/IkiTown/scripts.pory"
	shake_horizontal
	step_end

# 167 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_7:
# 167 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 186 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_FestivalBattle_Movement_8:
# 186 "data/maps/IkiTown/scripts.pory"
	walk_left
# 186 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 228 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_0:
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 228 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 230 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_1:
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 230 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 230 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 232 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_2:
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 232 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 234 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_3:
# 234 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 234 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 234 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 234 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 234 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 234 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 234 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 234 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 236 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_4:
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 236 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 239 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_5:
# 239 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 239 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
	step_end

# 262 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_6:
# 262 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 262 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 287 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_7:
# 287 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 287 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 348 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_8:
# 348 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
# 348 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
	step_end

# 371 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_9:
# 371 "data/maps/IkiTown/scripts.pory"
	walk_down
# 371 "data/maps/IkiTown/scripts.pory"
	walk_down
# 371 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 446 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_10:
# 446 "data/maps/IkiTown/scripts.pory"
	walk_right
# 446 "data/maps/IkiTown/scripts.pory"
	walk_right
# 446 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 460 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_11:
# 460 "data/maps/IkiTown/scripts.pory"
	walk_left
# 460 "data/maps/IkiTown/scripts.pory"
	walk_left
# 460 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 479 "data/maps/IkiTown/scripts.pory"
Ikitown_FestivalBattleOnStage_Movement_12:
# 479 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 479 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 489 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_0:
# 489 "data/maps/IkiTown/scripts.pory"
	walk_up
# 489 "data/maps/IkiTown/scripts.pory"
	walk_up
# 489 "data/maps/IkiTown/scripts.pory"
	walk_up
# 489 "data/maps/IkiTown/scripts.pory"
	walk_up
# 489 "data/maps/IkiTown/scripts.pory"
	delay_16
# 489 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 490 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_1:
# 490 "data/maps/IkiTown/scripts.pory"
	delay_16
# 490 "data/maps/IkiTown/scripts.pory"
	delay_16
# 490 "data/maps/IkiTown/scripts.pory"
	walk_up
# 490 "data/maps/IkiTown/scripts.pory"
	walk_up
# 490 "data/maps/IkiTown/scripts.pory"
	walk_up
# 490 "data/maps/IkiTown/scripts.pory"
	walk_up
# 490 "data/maps/IkiTown/scripts.pory"
	walk_up
# 490 "data/maps/IkiTown/scripts.pory"
	walk_up
# 490 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 491 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_2:
# 491 "data/maps/IkiTown/scripts.pory"
	delay_16
# 491 "data/maps/IkiTown/scripts.pory"
	walk_up
# 491 "data/maps/IkiTown/scripts.pory"
	walk_up
# 491 "data/maps/IkiTown/scripts.pory"
	walk_up
# 491 "data/maps/IkiTown/scripts.pory"
	walk_up
# 491 "data/maps/IkiTown/scripts.pory"
	walk_up
# 491 "data/maps/IkiTown/scripts.pory"
	walk_up
# 491 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 498 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_3:
# 498 "data/maps/IkiTown/scripts.pory"
	walk_left
# 498 "data/maps/IkiTown/scripts.pory"
	walk_left
# 498 "data/maps/IkiTown/scripts.pory"
	walk_left
# 498 "data/maps/IkiTown/scripts.pory"
	walk_left
# 498 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 501 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_4:
# 501 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
# 501 "data/maps/IkiTown/scripts.pory"
	walk_in_place_up
	step_end

# 504 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_5:
# 504 "data/maps/IkiTown/scripts.pory"
	walk_right
# 504 "data/maps/IkiTown/scripts.pory"
	walk_right
# 504 "data/maps/IkiTown/scripts.pory"
	walk_right
# 504 "data/maps/IkiTown/scripts.pory"
	walk_right
# 504 "data/maps/IkiTown/scripts.pory"
	walk_right
# 504 "data/maps/IkiTown/scripts.pory"
	walk_right
# 504 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 514 "data/maps/IkiTown/scripts.pory"
Ikitown_StartFestival_Movement_6:
# 514 "data/maps/IkiTown/scripts.pory"
	walk_left
# 514 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 525 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_right_Movement_0:
# 525 "data/maps/IkiTown/scripts.pory"
	walk_left
# 525 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 532 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_left_Movement_0:
# 532 "data/maps/IkiTown/scripts.pory"
	walk_right
# 532 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 549 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitownSkip_Movement_0:
# 549 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 569 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_0:
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 569 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 569 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 570 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_1:
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 570 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 573 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_2:
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
# 573 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 574 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_3:
# 574 "data/maps/IkiTown/scripts.pory"
	delay_16
# 574 "data/maps/IkiTown/scripts.pory"
	delay_16
# 574 "data/maps/IkiTown/scripts.pory"
	delay_16
# 574 "data/maps/IkiTown/scripts.pory"
	delay_16
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 574 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 588 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_4:
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 588 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
	step_end

# 590 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_5:
# 590 "data/maps/IkiTown/scripts.pory"
	walk_up
# 590 "data/maps/IkiTown/scripts.pory"
	walk_up
# 590 "data/maps/IkiTown/scripts.pory"
	walk_up
# 590 "data/maps/IkiTown/scripts.pory"
	walk_up
# 590 "data/maps/IkiTown/scripts.pory"
	walk_up
# 590 "data/maps/IkiTown/scripts.pory"
	walk_up
# 590 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 600 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_6:
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
# 600 "data/maps/IkiTown/scripts.pory"
	walk_faster_down
	step_end

# 604 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_7:
# 604 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 639 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_WecomeToIkitown_Movement_8:
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
# 639 "data/maps/IkiTown/scripts.pory"
	walk_fast_up
	step_end

# 692 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_0:
# 692 "data/maps/IkiTown/scripts.pory"
	face_down
# 692 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 697 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_KukuiSeeTapuKoko_Movement_1:
# 697 "data/maps/IkiTown/scripts.pory"
	walk_up
	step_end

# 829 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_0:
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_left
# 829 "data/maps/IkiTown/scripts.pory"
	walk_left
# 829 "data/maps/IkiTown/scripts.pory"
	walk_left
# 829 "data/maps/IkiTown/scripts.pory"
	walk_left
# 829 "data/maps/IkiTown/scripts.pory"
	walk_left
# 829 "data/maps/IkiTown/scripts.pory"
	walk_left
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_down
# 829 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 829 "data/maps/IkiTown/scripts.pory"
	walk_right
# 829 "data/maps/IkiTown/scripts.pory"
	walk_right
# 829 "data/maps/IkiTown/scripts.pory"
	walk_right
# 829 "data/maps/IkiTown/scripts.pory"
	walk_up
# 829 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 830 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_1:
# 830 "data/maps/IkiTown/scripts.pory"
	delay_16
# 830 "data/maps/IkiTown/scripts.pory"
	delay_16
# 830 "data/maps/IkiTown/scripts.pory"
	delay_16
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_left
# 830 "data/maps/IkiTown/scripts.pory"
	walk_left
# 830 "data/maps/IkiTown/scripts.pory"
	walk_left
# 830 "data/maps/IkiTown/scripts.pory"
	walk_left
# 830 "data/maps/IkiTown/scripts.pory"
	walk_left
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_down
# 830 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 830 "data/maps/IkiTown/scripts.pory"
	walk_right
# 830 "data/maps/IkiTown/scripts.pory"
	walk_right
# 830 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 833 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_2:
# 833 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 833 "data/maps/IkiTown/scripts.pory"
	walk_down
# 833 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 844 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_3:
# 844 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 844 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 881 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_4:
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 881 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
	step_end

# 883 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_5:
# 883 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 883 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 896 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_6:
# 896 "data/maps/IkiTown/scripts.pory"
	walk_down
# 896 "data/maps/IkiTown/scripts.pory"
	delay_16
# 896 "data/maps/IkiTown/scripts.pory"
	delay_16
# 896 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 897 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_7:
# 897 "data/maps/IkiTown/scripts.pory"
	walk_up
# 897 "data/maps/IkiTown/scripts.pory"
	walk_up
# 897 "data/maps/IkiTown/scripts.pory"
	walk_up
# 897 "data/maps/IkiTown/scripts.pory"
	walk_up
# 897 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 901 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_8:
# 901 "data/maps/IkiTown/scripts.pory"
	walk_left
# 901 "data/maps/IkiTown/scripts.pory"
	walk_left
# 901 "data/maps/IkiTown/scripts.pory"
	walk_left
# 901 "data/maps/IkiTown/scripts.pory"
	walk_left
# 901 "data/maps/IkiTown/scripts.pory"
	walk_left
# 901 "data/maps/IkiTown/scripts.pory"
	walk_left
# 901 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 908 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_9:
# 908 "data/maps/IkiTown/scripts.pory"
	walk_left
# 908 "data/maps/IkiTown/scripts.pory"
	walk_left
# 908 "data/maps/IkiTown/scripts.pory"
	walk_left
# 908 "data/maps/IkiTown/scripts.pory"
	walk_left
# 908 "data/maps/IkiTown/scripts.pory"
	walk_diag_northwest
# 908 "data/maps/IkiTown/scripts.pory"
	walk_left
# 908 "data/maps/IkiTown/scripts.pory"
	walk_left
# 908 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 969 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_10:
# 969 "data/maps/IkiTown/scripts.pory"
	walk_down
# 969 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 1000 "data/maps/IkiTown/scripts.pory"
Ikitown_GetPokedex_Movement_11:
# 1000 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1000 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1000 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 1102 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_0:
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1102 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1106 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_1:
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1106 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
	step_end

# 1110 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_2:
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_faster_left
# 1110 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1110 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1118 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_3:
# 1118 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1118 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1118 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1118 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1118 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1118 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1118 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1118 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1124 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_4:
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_right
# 1124 "data/maps/IkiTown/scripts.pory"
	walk_faster_up
# 1124 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1131 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_5:
# 1131 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1131 "data/maps/IkiTown/scripts.pory"
	walk_diag_northeast
# 1131 "data/maps/IkiTown/scripts.pory"
	walk_right
# 1131 "data/maps/IkiTown/scripts.pory"
	walk_right
	step_end

# 1133 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_6:
# 1133 "data/maps/IkiTown/scripts.pory"
	walk_down
# 1133 "data/maps/IkiTown/scripts.pory"
	delay_8
# 1133 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 1222 "data/maps/IkiTown/scripts.pory"
Ikitown_trigger_GiveHalaSparklingStone_Movement_7:
# 1222 "data/maps/IkiTown/scripts.pory"
	walk_down
	step_end

Ikitown_Trigger_FestivalBattle_Text_0:
# 79 "data/maps/IkiTown/scripts.pory"
	.string "Hala$"

Ikitown_Trigger_FestivalBattle_Text_1:
# 80 "data/maps/IkiTown/scripts.pory"
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
# 99 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

Ikitown_Trigger_FestivalBattle_Text_3:
# 102 "data/maps/IkiTown/scripts.pory"
	.string "Man, I thought you'd never make it!\n"
	.string "Me and Popplio've been waiting for ages!$"

Ikitown_Trigger_FestivalBattle_Text_4:
# 108 "data/maps/IkiTown/scripts.pory"
	.string "Bwark!$"

Ikitown_Trigger_FestivalBattle_Text_5:
# 114 "data/maps/IkiTown/scripts.pory"
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
# 132 "data/maps/IkiTown/scripts.pory"
	.string "Grrr!$"

Ikitown_Trigger_FestivalBattle_Text_9:
# 137 "data/maps/IkiTown/scripts.pory"
	.string "Hold on… Didn't anyone explain to\n"
	.string "you about tonight?!$"

Ikitown_Trigger_FestivalBattle_Text_10:
# 145 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

Ikitown_Trigger_FestivalBattle_Text_11:
# 146 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah, right on time!$"

Ikitown_Trigger_FestivalBattle_Text_12:
# 150 "data/maps/IkiTown/scripts.pory"
	.string "Lillie$"

Ikitown_Trigger_FestivalBattle_Text_13:
# 151 "data/maps/IkiTown/scripts.pory"
	.string "But to what exactly?$"

Ikitown_Trigger_FestivalBattle_Text_14:
# 156 "data/maps/IkiTown/scripts.pory"
	.string "Pew!!$"

Ikitown_Trigger_FestivalBattle_Text_15:
# 160 "data/maps/IkiTown/scripts.pory"
	.string "A full-powered festival for Pokemon\n"
	.string "battling!\p"
	.string "We battle in the name of Tapu Koko,\n"
	.string "pitting our best move against one\l"
	.string "another in friendly competition to\l"
	.string "please our guardian. Woo!$"

Ikitown_Trigger_FestivalBattle_Text_16:
# 170 "data/maps/IkiTown/scripts.pory"
	.string "So, you two will be taking part in\n"
	.string "battle?\p"
	.string "I don't like seeing Pokémon fight one\n"
	.string "another…they often end up hurt.\p"
	.string "But…I'll be sure to watch you both.$"

Ikitown_Trigger_FestivalBattle_Text_17:
# 181 "data/maps/IkiTown/scripts.pory"
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
# 248 "data/maps/IkiTown/scripts.pory"
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
# 266 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Popplio!$"

Ikitown_FestivalBattleOnStage_Text_2:
# 270 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Rowlet!$"

Ikitown_FestivalBattleOnStage_Text_3:
# 274 "data/maps/IkiTown/scripts.pory"
	.string "Let's have fun with this, Litten!$"

Ikitown_FestivalBattleOnStage_Text_4:
# 279 "data/maps/IkiTown/scripts.pory"
	.string "Before him stands {PLAYER}-\n"
	.string "one who has met with Tapu Koko.$"

Ikitown_FestivalBattleOnStage_Text_5:
# 282 "data/maps/IkiTown/scripts.pory"
	.string "What?!\p"
	.string "What a curious thing Tapu Koko is!\n"
	.string "Hah, that's just typical of it!$"

Ikitown_FestivalBattleOnStage_Text_6:
# 292 "data/maps/IkiTown/scripts.pory"
	.string "Mom$"

Ikitown_FestivalBattleOnStage_Text_7:
# 294 "data/maps/IkiTown/scripts.pory"
	.string "{STR_VAR_1}!\n"
	.string "Take good care of my little {PLAYER}!$"

Ikitown_FestivalBattleOnStage_Text_8:
# 299 "data/maps/IkiTown/scripts.pory"
	.string "As long as we both have a good time,\n"
	.string "then I think we can call it a great\l"
	.string "battle, eh?$"

Ikitown_FestivalBattleOnStage_Text_9:
# 305 "data/maps/IkiTown/scripts.pory"
	.string "{PLAYER}! Hau!\n"
	.string "Bring forth the power of your Pokémon!$"

Ikitown_FestivalBattleOnStage_Text_10:
# 310 "data/maps/IkiTown/scripts.pory"
	.string "What? It's already over?!$"

Ikitown_FestivalBattleOnStage_Text_11:
# 339 "data/maps/IkiTown/scripts.pory"
	.string "Hoo-ee! Another great battle this year.\p"
	.string "I bet Tapu Koko liked it, too.$"

Ikitown_FestivalBattleOnStage_Text_12:
# 346 "data/maps/IkiTown/scripts.pory"
	.string "Phew…\n"
	.string "That was awesome, {PLAYER}!$"

Ikitown_FestivalBattleOnStage_Text_13:
# 353 "data/maps/IkiTown/scripts.pory"
	.string "That was a really great battle!\n"
	.string "I had a blast fighting you!$"

Ikitown_FestivalBattleOnStage_Text_14:
# 358 "data/maps/IkiTown/scripts.pory"
	.string "It was a good battle.\n"
	.string "With this, even Tapu Koko…$"

Ikitown_FestivalBattleOnStage_Text_15:
# 363 "data/maps/IkiTown/scripts.pory"
	.string "Ko-ko-kooo!$"

Ikitown_FestivalBattleOnStage_Text_16:
# 369 "data/maps/IkiTown/scripts.pory"
	.string "Ho! You heard it yourself!\n"
	.string "Tapu Koko's song of approval.$"

Ikitown_FestivalBattleOnStage_Text_17:
# 373 "data/maps/IkiTown/scripts.pory"
	.string "Oh, I nearly forgot! I think its\n"
	.string "time you take this, {PLAYER}.$"

Ikitown_FestivalBattleOnStage_Text_18:
# 379 "data/maps/IkiTown/scripts.pory"
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

Ikitown_FestivalBattleOnStage_Text_19:
# 403 "data/maps/IkiTown/scripts.pory"
	.string "Well, it's time for you to get out there\n"
	.string "and start your {COLOR RED}island challenge{COLOR DARK_GRAY}!\p"
	.string "If you visit every island, maybe you'll\n"
	.string "figure out what that mission is.$"

Ikitown_FestivalBattleOnStage_Text_20:
# 408 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge?$"

Ikitown_FestivalBattleOnStage_Text_21:
# 408 "data/maps/IkiTown/scripts.pory"
	.string "Every Island?$"

Ikitown_FestivalBattleOnStage_Text_22:
# 411 "data/maps/IkiTown/scripts.pory"
	.string "Four Islands!\p"
	.string "You'll travel to each of the four\n"
	.string "islands here in the Alola Region.$"

Ikitown_FestivalBattleOnStage_Text_23:
# 424 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge is about aiming to\n"
	.string "be the strongest Trainer-\l"
	.string "the {COLOR RED}island challenge champion{COLOR DARK_GRAY}. Woo!$"

Ikitown_FestivalBattleOnStage_Text_24:
# 430 "data/maps/IkiTown/scripts.pory"
	.string "Sounds great, right?\n"
	.string "I can't wait to have a real adventure!$"

Ikitown_FestivalBattleOnStage_Text_25:
# 435 "data/maps/IkiTown/scripts.pory"
	.string "The island challenge Kukui spoke of…\p"
	.string "It is a journey to overcome your own\n"
	.string "limitations, as you travel the far\l"
	.string "corners of Alola and meet with\l"
	.string "others along the path.\p"
	.string "It's a great adventure that children\n"
	.string "in the Alola region embark upon,\l"
	.string "along with their Pokémon,\l"
	.string "once they reach 11 years of age!$"

Ikitown_FestivalBattleOnStage_Text_26:
# 449 "data/maps/IkiTown/scripts.pory"
	.string "Allow me to give you both the island\n"
	.string "challenge amulets you will need.$"

Ikitown_FestivalBattleOnStage_Text_27:
# 454 "data/maps/IkiTown/scripts.pory"
	.string "Awesome!\n"
	.string "Thanks, Tutu!\p"
	.string "I'm gonna make it through the island\n"
	.string "challenge to try to become an island\l"
	.string "challenge champion!$"

Ikitown_FestivalBattleOnStage_Text_28:
# 463 "data/maps/IkiTown/scripts.pory"
	.string "There is one for you was well,\n"
	.string "{PLAYER}.\p"
	.string "Please do give the island challenge\n"
	.string "a try.$"

Ikitown_FestivalBattleOnStage_Text_29:
# 470 "data/maps/IkiTown/scripts.pory"
	.string "You received the {COLOR RED}Island Challenge\n"
	.string "Amulet{COLOR DARK_GRAY}!$"

Ikitown_FestivalBattleOnStage_Text_30:
# 477 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, doing the island challenge is the\n"
	.string "best way to really get to know Alola!$"

Ikitown_trigger_WecomeToIkitown_Text_0:
# 585 "data/maps/IkiTown/scripts.pory"
	.string "And we're here!\n"
	.string "This right here is Iki Town!$"

Ikitown_trigger_WecomeToIkitown_Text_1:
# 593 "data/maps/IkiTown/scripts.pory"
	.string "This town is where folks come to\n"
	.string "worship the Pokemon that watches\l"
	.string "over Melemele Island.\p"
	.string "Tapu Koko keeps us all safe and\n"
	.string "happy, see!$"

Ikitown_trigger_WecomeToIkitown_Text_2:
# 607 "data/maps/IkiTown/scripts.pory"
	.string "Looks like the kahuna's nowhere to be\n"
	.string "found, though…\p"
	.string "I guess there must be some trouble\n"
	.string "somewhere on the island that needs\l"
	.string "fixing, yeah?$"

Ikitown_trigger_WecomeToIkitown_Text_3:
# 616 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, the kahuna wandered off without\n"
	.string "a word to anybody, singing a little\l"
	.string "ditty or something.$"

Ikitown_trigger_WecomeToIkitown_Text_4:
# 627 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Popplio!$"

Ikitown_trigger_WecomeToIkitown_Text_5:
# 631 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Rowlet!$"

Ikitown_trigger_WecomeToIkitown_Text_6:
# 635 "data/maps/IkiTown/scripts.pory"
	.string "I'm gonna go stop by home for a sec.\n"
	.string "I've gotta show my mom Litten!$"

Ikitown_trigger_WecomeToIkitown_Text_7:
# 645 "data/maps/IkiTown/scripts.pory"
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
# 663 "data/maps/IkiTown/scripts.pory"
	.string "If you're really lucky, maybe you'll\n"
	.string "actually get a glimpse of the\l"
	.string "guardian deity yourself!\p"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_KukuiSeeTapuKoko_Text_0:
# 680 "data/maps/IkiTown/scripts.pory"
	.string "I'll stick around and see if the\n"
	.string "kahuna comes back.$"

Ikitown_MainSign_Text_0:
# 704 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town\n"
	.string "“The place where we give thanks to\l"
	.string "Pokémon.”$"

Ikitown_LittleBoyWRockruff_Text_0:
# 715 "data/maps/IkiTown/scripts.pory"
	.string "Hey, you've got a Pokémon! I want one,\n"
	.string "too!\p"
	.string "Where'd you get yours?$"

Ikitown_Rockruff_Text_0:
# 728 "data/maps/IkiTown/scripts.pory"
	.string "Ruff ruff!$"

Ikitown_LeftSideGuy_Text_0:
# 737 "data/maps/IkiTown/scripts.pory"
	.string "Welcome to Iki Town, the town watched\n"
	.string "over by Pokémon!$"

Ikitown_MomwithChild_Text_0:
# 747 "data/maps/IkiTown/scripts.pory"
	.string "If you treat your Pokémon wrong, the\n"
	.string "guardian deity will strike you down\l"
	.string "with lightning!\p"
	.string "But the children all laugh when I tell\n"
	.string "them that.$"

Ikitown_ChildwithMom_Text_0:
# 761 "data/maps/IkiTown/scripts.pory"
	.string "I want to meet the guardian deity!\p"
	.string "Maybe I should cause some mischief for\n"
	.string "a Pokémon…$"

Ikitown_DontForgetToSave_Text_0:
# 773 "data/maps/IkiTown/scripts.pory"
	.string "Don't forget to save!\p"
	.string "If you want to remember everything\n"
	.string "that's happened, you must not\l"
	.string "forget to save!$"

Ikitown_KahunaGivesWisdom_Text_0:
# 786 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna gives us wisdom and\n"
	.string "guidance and teaches us how to live\l"
	.string "with our Pokémon.$"

Ikitown_ManBlockingDoor_Text_0:
# 796 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala is the strongest Pokémon\n"
	.string "Trainer on all of Melemele!\p"
	.string "There must be some trouble going down\n"
	.string "somewhere on the island that needs\l"
	.string "a kahuna's touch, 'cause he said\l"
	.string "something about how it's “Time\l"
	.string "for old Hala!” and off he went…$"

Ikitown_Meowth_Text_0:
# 812 "data/maps/IkiTown/scripts.pory"
	.string "Hsss!$"

Ikitown_sign_Ruinsofconflict_Text_0:
# 820 "data/maps/IkiTown/scripts.pory"
	.string "Ruins of Conflict$"

Ikitown_GetPokedex_Text_0:
# 836 "data/maps/IkiTown/scripts.pory"
	.string "Oh, {PLAYER}!\n"
	.string "You already met Lillie, huh?\p"
	.string "She's my assistant, yeah!$"

Ikitown_GetPokedex_Text_1:
# 842 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, I thought you were with the\n"
	.string "kahuna?$"

Ikitown_GetPokedex_Text_2:
# 847 "data/maps/IkiTown/scripts.pory"
	.string "Kahuna Hala? He said that he had\n"
	.string "something to attend to, so he left\l"
	.string "town on his own.\p"
	.string "I was just, um, taking a little stroll\n"
	.string "up Mahalo Trail while I waited for\l"
	.string "him to return…$"

Ikitown_GetPokedex_Text_3:
# 857 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "He just got to Alola yesterday.\n"
	.string "Help him find his way around, yeah?$"

Ikitown_GetPokedex_Text_4:
# 865 "data/maps/IkiTown/scripts.pory"
	.string "And that's how you met our new neighbor\n"
	.string "{PLAYER}, huh?\p"
	.string "She just got to Alola yesterday.\n"
	.string "Help her find her way around, yeah?$"

Ikitown_GetPokedex_Text_5:
# 874 "data/maps/IkiTown/scripts.pory"
	.string "So…you're also one of\n"
	.string "the professor's acquaintances?\p"
	.string "It's nice to meet you.$"

Ikitown_GetPokedex_Text_6:
# 888 "data/maps/IkiTown/scripts.pory"
	.string "The kahuna is back!\n"
	.string "Kahuna Hala has returned!\p"
	.string "Our guardian's chosen one is back!\p"
	.string "Only one of the strongest Pokémon\n"
	.string "users in all Alola, yeah!$"

Ikitown_GetPokedex_Text_7:
# 900 "data/maps/IkiTown/scripts.pory"
	.string "Have I missed something?$"

Ikitown_GetPokedex_Text_8:
# 906 "data/maps/IkiTown/scripts.pory"
	.string "There you are, Kahuna Hala!\n"
	.string "Was there some kind of trouble?$"

Ikitown_GetPokedex_Text_9:
# 913 "data/maps/IkiTown/scripts.pory"
	.string "Ahaha! Just got caught up in the\n"
	.string "middle of some brawling Rockruff,\l"
	.string "that's all!\p"
	.string "Sorry, Lillie.\n"
	.string "What were you saying before?\p"
	.string "For some reason I thought I saw\n"
	.string "Tapu Koko flying about…$"

Ikitown_GetPokedex_Text_10:
# 925 "data/maps/IkiTown/scripts.pory"
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
# 942 "data/maps/IkiTown/scripts.pory"
	.string "Woo! That's something you don't hear\n"
	.string "every day!$"

Ikitown_GetPokedex_Text_12:
# 947 "data/maps/IkiTown/scripts.pory"
	.string "Ho! Although it is said to protect us,\n"
	.string "our Tapu Koko is a rather fickle\l"
	.string "creature.\l"
	.string "Yet our guardian was moved to save you.$"

Ikitown_GetPokedex_Text_13:
# 953 "data/maps/IkiTown/scripts.pory"
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
# 973 "data/maps/IkiTown/scripts.pory"
	.string "All right, here's a lovely gift to\n"
	.string "help make today special {PLAYER}!$"

Ikitown_GetPokedex_Text_15:
# 979 "data/maps/IkiTown/scripts.pory"
	.string "You obtained a {COLOR RED}Rotom Phone{COLOR DARK_GRAY}!$"

Ikitown_GetPokedex_Text_16:
# 984 "data/maps/IkiTown/scripts.pory"
	.string "The Rotom Phone comes equipped with a\n"
	.string "Pokédex, which is a really high-tech\l"
	.string "kinda tool, that can automatically\l"
	.string "record facts about any Pokémon that\l"
	.string "you meet.\p"
	.string "Your new partner, {STR_VAR_1} is\n"
	.string "already registered, oh yeah, so\l"
	.string "check it out!$"

Ikitown_GetPokedex_Text_17:
# 994 "data/maps/IkiTown/scripts.pory"
	.string "Well, you got to meet the kahuna\n"
	.string "at least.\p"
	.string "Ready to head home now, {PLAYER}?$"

ikitown_lilliedialog2_Text_0:
# 1051 "data/maps/IkiTown/scripts.pory"
	.string "I really, um, really appreciate what you\n"
	.string "did for us on the Plank Bridge.\p"
	.string "I won't forget you and {STR_VAR_1}…$"

ikitown_kukuidialog2_Text_0:
# 1064 "data/maps/IkiTown/scripts.pory"
	.string "Now that you met Tapu Koko, I can't\n"
	.string "wait to see how far you can go as a\l"
	.string "Pokémon Trainer!$"

ikitown_haladialog2_Text_0:
# 1076 "data/maps/IkiTown/scripts.pory"
	.string "If you two can work in harmony with\n"
	.string "each other, you can go anywhere\l"
	.string "together!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_0:
# 1088 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! {PLAYER}!\n"
	.string "Hold up a sec!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_1:
# 1138 "data/maps/IkiTown/scripts.pory"
	.string "What is it Hau? Did you forget\n"
	.string "something?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_2:
# 1143 "data/maps/IkiTown/scripts.pory"
	.string "You're seriously asking me that?!\p"
	.string "Who's the one here who forgot to tell\n"
	.string "anyone before wandering off for a\l"
	.string "little stroll and a sing without a\l"
	.string "word, huh?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_3:
# 1161 "data/maps/IkiTown/scripts.pory"
	.string "Hm?\n"
	.string "{PLAYER}…\p"
	.string "Would you be so kind as to give me a\n"
	.string "look at that {COLOR RED}Sparkling Stone{COLOR DARK_GRAY} you\l"
	.string "have there?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_4:
# 1170 "data/maps/IkiTown/scripts.pory"
	.string "Could it be?!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_5:
# 1174 "data/maps/IkiTown/scripts.pory"
	.string "Tutu, isn't that…$"

Ikitown_trigger_GiveHalaSparklingStone_Text_6:
# 1178 "data/maps/IkiTown/scripts.pory"
	.string "You were rescued by Tapu Koko at the\n"
	.string "bridge-isn't that what I heard,\l"
	.string "{PLAYER}?$"

Ikitown_trigger_GiveHalaSparklingStone_Text_7:
# 1181 "data/maps/IkiTown/scripts.pory"
	.string "Yeah, it rescued me$"

Ikitown_trigger_GiveHalaSparklingStone_Text_8:
# 1181 "data/maps/IkiTown/scripts.pory"
	.string "It gave me a stone$"

Ikitown_trigger_GiveHalaSparklingStone_Text_9:
# 1184 "data/maps/IkiTown/scripts.pory"
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
# 1225 "data/maps/IkiTown/scripts.pory"
	.string "First I'll make sure you get back home\n"
	.string "safe today, though, {PLAYER}.$"

Ikitown_trigger_GiveHalaSparklingStone_Text_11:
# 1228 "data/maps/IkiTown/scripts.pory"
	.string "Lillie, you two should come with us\n"
	.string "too, yeah.\p"
	.string "Wouldn't want to go losing you twice\n"
	.string "in one day.\l"
	.string "You or that precious Pokémon of yours!$"

Ikitown_trigger_GiveHalaSparklingStone_Text_12:
# 1237 "data/maps/IkiTown/scripts.pory"
	.string "Yes…\n"
	.string "I will key an eye on Nebby$"
