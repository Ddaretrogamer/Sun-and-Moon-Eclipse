IkiTownSouth_MapScripts::
# 2 "data/maps/IkiTownSouth/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 17 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 31 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
# 8 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 10 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
# 14 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LITTEN )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 18 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_13
# 22 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_12:
# 24 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_23
# 28 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 32 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
# 36 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( LITTEN )
IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 38 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_26
# 42 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
# 5 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_8

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 19 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_12

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 33 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 11 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 25 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 39 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTownSouth_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


IkiTown_Trigger_HauGetStarter::
# 50 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 51 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownmon1
# 52 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownmon2
# 53 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownhau
# 54 "data/maps/IkiTownSouth/scripts.pory"
	addobject ikitownkukui
# 55 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_HIDE_KUKUI_STARTERS
# 56 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 57 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_0
# 58 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_1
# 59 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 60 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 61 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_2
# 62 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 63 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_3
# 64 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 65 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_0
# 66 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_1
# 70 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 71 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 72 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_4
# 73 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 74 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_3
# 79 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 80 "data/maps/IkiTownSouth/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, IkiTown_Trigger_HauGetStarter_Text_4, IkiTown_Trigger_HauGetStarter_Text_5
# 81 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_2
# 89 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_3
IkiTown_Trigger_HauGetStarter_1:
# 95 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_6
# 96 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_6
# 97 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_6
# 98 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 99 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 100 "data/maps/IkiTownSouth/scripts.pory"
	checkplayergender
# 101 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_7
# 109 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_10
IkiTown_Trigger_HauGetStarter_6:
# 115 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 116 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 117 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 118 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_11
# 122 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 123 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 124 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 125 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_12
# 127 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 128 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 129 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 130 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 131 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_11
# 194 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_12
# 257 "data/maps/IkiTownSouth/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_Trigger_HauGetStarter_13
IkiTown_Trigger_HauGetStarter_10:
# 319 "data/maps/IkiTownSouth/scripts.pory"
	release
	end

IkiTown_Trigger_HauGetStarter_2:
# 82 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 83 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 84 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_6
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_3:
# 90 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 91 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 92 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_7
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_7:
# 102 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_9
	goto IkiTown_Trigger_HauGetStarter_6

IkiTown_Trigger_HauGetStarter_11:
# 132 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 133 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_9
# 134 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 135 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 136 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 137 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 138 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 139 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 140 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 141 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 142 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 143 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_15
# 145 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 146 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 147 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 148 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 149 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14, MSGBOX_AUTOCLOSE
# 150 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 151 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 152 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 153 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 154 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 155 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 165 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 166 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 167 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 168 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 169 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 170 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 171 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_17
# 173 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 174 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 175 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 176 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 177 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 178 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 179 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 180 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 181 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 182 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_19
# 184 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 185 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 186 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 187 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 188 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_20
# 190 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 191 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 192 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_12:
# 195 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 196 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 197 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 198 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 199 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 200 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 201 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 202 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 203 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 204 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 205 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 206 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_22
# 208 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 209 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 210 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21, MSGBOX_AUTOCLOSE
# 211 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 212 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 213 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 214 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 215 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 216 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 217 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 227 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 228 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_10
# 229 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 230 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 231 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_11
# 232 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 233 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_23
# 235 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 236 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 237 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 238 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 239 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 240 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 241 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 242 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_16
# 243 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 244 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_24
# 246 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 247 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 248 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 249 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 250 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_25
# 252 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 253 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 254 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_13:
# 258 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 259 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 260 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 261 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 262 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 263 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 264 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 265 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 266 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 267 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 268 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 269 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_26
# 271 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 272 "data/maps/IkiTownSouth/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 273 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13, MSGBOX_AUTOCLOSE
# 274 "data/maps/IkiTownSouth/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 275 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 276 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 277 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 278 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 279 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 280 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 290 "data/maps/IkiTownSouth/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 291 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 292 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 293 "data/maps/IkiTownSouth/scripts.pory"
	delay 30
# 294 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 295 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon2
# 296 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_27
# 298 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 299 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 300 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 301 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 302 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 303 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 304 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 305 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 306 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownmon1
# 307 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_28
# 309 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 310 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 311 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 312 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 313 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_29
# 315 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 316 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 317 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10


Ikitown_RivalBattleYesNo::
# 324 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 325 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_RivalBattleYesNo_Text_0, MSGBOX_YESNO
# 327 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_eq VAR_RESULT, YES, IkiTown_StartRivalBattle
# 328 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RivalBattleNo
	end


RivalBattleNo::
# 333 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 334 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 335 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 336 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 337 "data/maps/IkiTownSouth/scripts.pory"
	msgbox RivalBattleNo_Text_0
# 339 "data/maps/IkiTownSouth/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	return


IkiTown_StartRivalBattle::
# 342 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 343 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 344 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 345 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 346 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_0
# 351 "data/maps/IkiTownSouth/scripts.pory"
	special HealPlayerParty
# 352 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 353 "data/maps/IkiTownSouth/scripts.pory"
	playfanfare MUS_HEAL
# 354 "data/maps/IkiTownSouth/scripts.pory"
	waitfanfare
# 355 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 356 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 357 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_1
# 359 "data/maps/IkiTownSouth/scripts.pory"
	switch VAR_STARTER_MON
# 360 "data/maps/IkiTownSouth/scripts.pory"
	case 0, IkiTown_StartRivalBattle_3
# 368 "data/maps/IkiTownSouth/scripts.pory"
	case 1, IkiTown_StartRivalBattle_4
# 376 "data/maps/IkiTownSouth/scripts.pory"
	case 2, IkiTown_StartRivalBattle_5
IkiTown_StartRivalBattle_1:
# 385 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 386 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_BALL_OPEN
# 387 "data/maps/IkiTownSouth/scripts.pory"
	delay 60
# 388 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitownmon1
# 389 "data/maps/IkiTownSouth/scripts.pory"
	removeobject ikitownmon2
# 390 "data/maps/IkiTownSouth/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 391 "data/maps/IkiTownSouth/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 392 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_0
# 393 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 394 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 395 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 396 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 397 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 398 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_5
# 408 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 409 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownkukui
# 410 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 411 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_6, MSGBOX_AUTOCLOSE
# 419 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_1
# 420 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement ikitownhau
# 421 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_2
# 422 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 423 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 424 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_LEDGE
# 425 "data/maps/IkiTownSouth/scripts.pory"
	waitse
# 426 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 427 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_7
# 428 "data/maps/IkiTownSouth/scripts.pory"
	setvar VAR_IKITOWN_STATE, 1
# 429 "data/maps/IkiTownSouth/scripts.pory"
	release
	end

IkiTown_StartRivalBattle_3:
# 361 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_7
# 365 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_POPPLIO, IkiTown_StartRivalBattle_Text_2
IkiTown_StartRivalBattle_6:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_4:
# 369 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_11
# 373 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_ROWLET, IkiTown_StartRivalBattle_Text_3
IkiTown_StartRivalBattle_10:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_5:
# 377 "data/maps/IkiTownSouth/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_15
# 381 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_LITTEN, IkiTown_StartRivalBattle_Text_4
IkiTown_StartRivalBattle_14:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_7:
# 362 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_POPPLIOSHINY, IkiTown_StartRivalBattle_Text_2
	goto IkiTown_StartRivalBattle_6

IkiTown_StartRivalBattle_11:
# 370 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_ROWLETSHINY, IkiTown_StartRivalBattle_Text_3
	goto IkiTown_StartRivalBattle_10

IkiTown_StartRivalBattle_15:
# 378 "data/maps/IkiTownSouth/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_LITTENSHINY, IkiTown_StartRivalBattle_Text_4
	goto IkiTown_StartRivalBattle_14


IkiTown_Trigger_BottomGetStarters::
# 434 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 435 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_BottomGetStarters_Movement_0
# 436 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 437 "data/maps/IkiTownSouth/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


IkiTown_Trigger_TopGetStarters::
# 440 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 441 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_TopGetStarters_Movement_0
# 442 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 443 "data/maps/IkiTownSouth/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


Ikitown_HauAfterBattle::
# 447 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 448 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 449 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 450 "data/maps/IkiTownSouth/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_7
# 451 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_KukuiAfterBattle::
# 456 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 457 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 458 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 459 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 461 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_Trigger_LeaveIkitownEarly::
# 466 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 467 "data/maps/IkiTownSouth/scripts.pory"
	playse SE_PIN
# 468 "data/maps/IkiTownSouth/scripts.pory"
	applymovement ikitownkukui, Ikitown_Trigger_LeaveIkitownEarly_Movement_0
# 469 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_Movement_1
# 470 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement 0
# 471 "data/maps/IkiTownSouth/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 472 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 474 "data/maps/IkiTownSouth/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_Movement_2
# 475 "data/maps/IkiTownSouth/scripts.pory"
	waitmovement LOCALID_PLAYER
# 476 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_TrainerTipsSign::
# 481 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 482 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_TrainerTipsSign_Text_0
# 491 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


Ikitown_lassNPC::
# 496 "data/maps/IkiTownSouth/scripts.pory"
	lock
# 497 "data/maps/IkiTownSouth/scripts.pory"
	faceplayer
# 498 "data/maps/IkiTownSouth/scripts.pory"
	msgbox Ikitown_lassNPC_Text_0
# 503 "data/maps/IkiTownSouth/scripts.pory"
	release
	end


# 57 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_0:
# 57 "data/maps/IkiTownSouth/scripts.pory"
	emote_question_mark
	step_end

# 58 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_1:
# 58 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 58 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 58 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 58 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 58 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 58 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 58 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_down
# 58 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 58 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 58 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 58 "data/maps/IkiTownSouth/scripts.pory"
	face_left
# 58 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 58 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 58 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 58 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 61 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_2:
# 61 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
# 61 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
	step_end

# 63 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_3:
# 63 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
# 63 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
# 63 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_right
	step_end

# 72 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_4:
# 72 "data/maps/IkiTownSouth/scripts.pory"
	emote_x
	step_end

# 82 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_5:
# 82 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_left
# 82 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_left
	step_end

# 95 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_6:
# 95 "data/maps/IkiTownSouth/scripts.pory"
	walk_fast_left
# 95 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 95 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 95 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 95 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 95 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 95 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 115 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_7:
# 115 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_right
# 115 "data/maps/IkiTownSouth/scripts.pory"
	walk_in_place_right
	step_end

# 127 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_8:
# 127 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 127 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

# 133 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_9:
# 133 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
	step_end

# 166 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_10:
# 166 "data/maps/IkiTownSouth/scripts.pory"
	emote_heart
	step_end

# 169 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_11:
# 169 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 169 "data/maps/IkiTownSouth/scripts.pory"
	face_right
	step_end

# 173 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_12:
# 173 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
# 173 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_left
	step_end

# 180 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_13:
# 180 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 180 "data/maps/IkiTownSouth/scripts.pory"
	face_down
	step_end

# 185 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_14:
# 185 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
	step_end

# 197 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_15:
# 197 "data/maps/IkiTownSouth/scripts.pory"
	face_up
# 197 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 197 "data/maps/IkiTownSouth/scripts.pory"
	face_right
# 197 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 197 "data/maps/IkiTownSouth/scripts.pory"
	face_down
# 197 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 197 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 242 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_16:
# 242 "data/maps/IkiTownSouth/scripts.pory"
	walk_right
# 242 "data/maps/IkiTownSouth/scripts.pory"
	face_up
	step_end

# 392 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_0:
# 392 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_right
# 392 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_right
	step_end

# 419 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_1:
# 419 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 419 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 419 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
# 419 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
# 419 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
# 419 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 419 "data/maps/IkiTownSouth/scripts.pory"
	face_down
# 419 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
# 419 "data/maps/IkiTownSouth/scripts.pory"
	delay_16
	step_end

# 421 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_StartRivalBattle_Movement_2:
# 421 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_down
# 421 "data/maps/IkiTownSouth/scripts.pory"
	jump_in_place_down
	step_end

# 435 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_BottomGetStarters_Movement_0:
# 435 "data/maps/IkiTownSouth/scripts.pory"
	walk_up
# 435 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 441 "data/maps/IkiTownSouth/scripts.pory"
IkiTown_Trigger_TopGetStarters_Movement_0:
# 441 "data/maps/IkiTownSouth/scripts.pory"
	walk_down
# 441 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 468 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_0:
# 468 "data/maps/IkiTownSouth/scripts.pory"
	face_right
# 468 "data/maps/IkiTownSouth/scripts.pory"
	emote_exclamation_mark
	step_end

# 469 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_1:
# 469 "data/maps/IkiTownSouth/scripts.pory"
	face_left
	step_end

# 474 "data/maps/IkiTownSouth/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_2:
# 474 "data/maps/IkiTownSouth/scripts.pory"
	walk_left
	step_end

IkiTown_Trigger_HauGetStarter_Text_0:
# 65 "data/maps/IkiTownSouth/scripts.pory"
	.string "???$"

IkiTown_Trigger_HauGetStarter_Text_1:
# 66 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hey, hey!\p"
	.string "Which Pokémon are you gonna choose as\n"
	.string "your partner? {PAUSE 30} Have you decided?$"

IkiTown_Trigger_HauGetStarter_Text_2:
# 70 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hau$"

IkiTown_Trigger_HauGetStarter_Text_3:
# 74 "data/maps/IkiTownSouth/scripts.pory"
	.string "Oh yeah! I'm Hau!\p"
	.string "I couldn't wait for us to pick our\n"
	.string "partners together, so I came to find\l"
	.string "you myself!$"

IkiTown_Trigger_HauGetStarter_Text_4:
# 80 "data/maps/IkiTownSouth/scripts.pory"
	.string "I chose {STR_VAR_1}!$"

IkiTown_Trigger_HauGetStarter_Text_5:
# 80 "data/maps/IkiTownSouth/scripts.pory"
	.string "You're too late.$"

IkiTown_Trigger_HauGetStarter_Text_6:
# 84 "data/maps/IkiTownSouth/scripts.pory"
	.string "Whoa! {STR_VAR_1} is so cool!\p"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_7:
# 92 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_8:
# 99 "data/maps/IkiTownSouth/scripts.pory"
	.string "Kukui$"

IkiTown_Trigger_HauGetStarter_Text_9:
# 102 "data/maps/IkiTownSouth/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose his partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_10:
# 109 "data/maps/IkiTownSouth/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose her partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_11:
# 118 "data/maps/IkiTownSouth/scripts.pory"
	.string "Fair enough.\p"
	.string "I guess it was just fate for you guys\n"
	.string "to meet!$"

IkiTown_Trigger_HauGetStarter_Text_12:
# 125 "data/maps/IkiTownSouth/scripts.pory"
	.string "But you can choose one of the\n"
	.string "remaining two, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_13:
# 135 "data/maps/IkiTownSouth/scripts.pory"
	.string "Mrawr!$"

IkiTown_Trigger_HauGetStarter_Text_14:
# 140 "data/maps/IkiTownSouth/scripts.pory"
	.string "Bwark!$"

IkiTown_Trigger_HauGetStarter_Text_15:
# 143 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Popplio! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_16:
# 155 "data/maps/IkiTownSouth/scripts.pory"
	.string "Alola, friend!\p"
	.string "I decided ages ago that you're the\n"
	.string "one I wanted to have an adventure\l"
	.string "with!\p"
	.string "We're gonna do so much awesome stuff\n"
	.string "together!\p"
	.string "Just you wait and see!$"

IkiTown_Trigger_HauGetStarter_Text_17:
# 171 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Litten, right?$"

IkiTown_Trigger_HauGetStarter_Text_18:
# 179 "data/maps/IkiTownSouth/scripts.pory"
	.string "You better believe I will, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_19:
# 182 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Litten! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_20:
# 188 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Popplio have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_21:
# 196 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hoo!$"

IkiTown_Trigger_HauGetStarter_Text_22:
# 206 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Rowlet! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_23:
# 233 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Popplio, right?$"

IkiTown_Trigger_HauGetStarter_Text_24:
# 244 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Popplio! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_25:
# 250 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Rowlet have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_26:
# 269 "data/maps/IkiTownSouth/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Litten! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_27:
# 296 "data/maps/IkiTownSouth/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Rowlet, right?$"

IkiTown_Trigger_HauGetStarter_Text_28:
# 307 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right then. Rowlet! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_29:
# 313 "data/maps/IkiTownSouth/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Litten have a favor to ask.$"

Ikitown_RivalBattleYesNo_Text_0:
# 325 "data/maps/IkiTownSouth/scripts.pory"
	.string "Be our opponents in our first ever\n"
	.string "Pokémon battle together!$"

RivalBattleNo_Text_0:
# 337 "data/maps/IkiTownSouth/scripts.pory"
	.string "Come on, don't be like that!\n"
	.string "It'll be fun!$"

IkiTown_StartRivalBattle_Text_0:
# 346 "data/maps/IkiTownSouth/scripts.pory"
	.string "Hold on!\p"
	.string "Before you two step into the ring,\n"
	.string "let's make sure little {STR_VAR_1} is up\l"
	.string "to it!$"

IkiTown_StartRivalBattle_Text_1:
# 357 "data/maps/IkiTownSouth/scripts.pory"
	.string "All right, I'm surely going to enjoy\n"
	.string "this!$"

IkiTown_StartRivalBattle_Text_2:
# 362 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Popplio!$"

IkiTown_StartRivalBattle_Text_3:
# 370 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Rowlet!$"

IkiTown_StartRivalBattle_Text_4:
# 378 "data/maps/IkiTownSouth/scripts.pory"
	.string "Our first defeat! Sorry, Litten!$"

IkiTown_StartRivalBattle_Text_5:
# 398 "data/maps/IkiTownSouth/scripts.pory"
	.string "Whoa! That was awesome, {PLAYER}!\p"
	.string "You and {STR_VAR_1} were both so\n"
	.string "cool!\p"
	.string "You've gotta have the kinda battles\n"
	.string "where everyone has fun.\p"
	.string "You and your partner Pokémon, too,\n"
	.string "you know?$"

IkiTown_StartRivalBattle_Text_6:
# 411 "data/maps/IkiTownSouth/scripts.pory"
	.string "Right on {PLAYER}!\p"
	.string "You and Hau both brought out the\n"
	.string "best in your partners and pulled\l"
	.string "off some spectacular moves, yeah!\p"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

IkiTown_StartRivalBattle_Text_7:
# 427 "data/maps/IkiTownSouth/scripts.pory"
	.string "You should totally check out Iki Town!$"

Ikitown_KukuiAfterBattle_Text_0:
# 459 "data/maps/IkiTownSouth/scripts.pory"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

Ikitown_TrainerTipsSign_Text_0:
# 482 "data/maps/IkiTownSouth/scripts.pory"
	.string "Trainer Tips\p"
	.string "Pokémon can gain Exp. Points by\n"
	.string "battling other Pokémon.\p"
	.string "Exp. Points help them grow stronger.\n"
	.string "And your Pokémon will still get Exp.\l"
	.string "Points even if you catch a Pokémon\l"
	.string "you are battling against!$"

Ikitown_lassNPC_Text_0:
# 498 "data/maps/IkiTownSouth/scripts.pory"
	.string "If you happen to pick up a Potion\n"
	.string "anywhere, use it on your Pokémon\l"
	.string "when it's low on HP…\l"
	.string "and it'll be feeling better before\l"
	.string "you know it!$"
