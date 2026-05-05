IkiTown_MapScripts::
# 2 "data/maps/IkiTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 17 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 31 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	end

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9
# 8 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 10 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
# 14 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( LITTEN )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 18 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13
# 22 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_12:
# 24 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23
# 28 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( POPPLIO )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 32 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
# 36 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES ( LITTEN )
IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 38 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_KUKUI_SHINY, IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26
# 42 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES ( ROWLET )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_9:
# 5 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 19 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_12

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 33 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 11 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( LITTEN )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 25 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES_SHINY ( POPPLIO )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 39 "data/maps/IkiTown/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES_SHINY ( ROWLET )
	goto IkiTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1


IkiTown_Trigger_HauGetStarter::
# 51 "data/maps/IkiTown/scripts.pory"
	lock
# 52 "data/maps/IkiTown/scripts.pory"
	addobject ikitownmon1
# 53 "data/maps/IkiTown/scripts.pory"
	addobject ikitownmon2
# 54 "data/maps/IkiTown/scripts.pory"
	addobject ikitownhau
# 55 "data/maps/IkiTown/scripts.pory"
	addobject ikitownkukui
# 56 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_HIDE_KUKUI_STARTERS
# 57 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 58 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_0
# 59 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_1
# 60 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 61 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 62 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_2
# 63 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 64 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_3
# 65 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 66 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_0
# 67 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_1
# 71 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 72 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 73 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_4
# 74 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 75 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_3
# 80 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 81 "data/maps/IkiTown/scripts.pory"
	dynmultichoice 18, 8, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, IkiTown_Trigger_HauGetStarter_Text_4, IkiTown_Trigger_HauGetStarter_Text_5
# 82 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_2
# 90 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_3
IkiTown_Trigger_HauGetStarter_1:
# 96 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_6
# 97 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_6
# 98 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_6
# 99 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 100 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 101 "data/maps/IkiTown/scripts.pory"
	checkplayergender
# 102 "data/maps/IkiTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_7
# 110 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_10
IkiTown_Trigger_HauGetStarter_6:
# 116 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 117 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 118 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 119 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_11
# 123 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 124 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownkukui
# 125 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 126 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_12
# 128 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 129 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 130 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 131 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 132 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq IkiTown_Trigger_HauGetStarter_11
# 195 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq IkiTown_Trigger_HauGetStarter_12
# 258 "data/maps/IkiTown/scripts.pory"
	compare VAR_STARTER_MON, 2
	goto_if_eq IkiTown_Trigger_HauGetStarter_13
IkiTown_Trigger_HauGetStarter_10:
# 320 "data/maps/IkiTown/scripts.pory"
	release
	end

IkiTown_Trigger_HauGetStarter_2:
# 83 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 84 "data/maps/IkiTown/scripts.pory"
	waitmovement LOCALID_PLAYER
# 85 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_6
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_3:
# 91 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_HauGetStarter_Movement_5
# 92 "data/maps/IkiTown/scripts.pory"
	waitmovement LOCALID_PLAYER
# 93 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_7
	goto IkiTown_Trigger_HauGetStarter_1

IkiTown_Trigger_HauGetStarter_7:
# 103 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_9
	goto IkiTown_Trigger_HauGetStarter_6

IkiTown_Trigger_HauGetStarter_11:
# 133 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 134 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_9
# 135 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 136 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 137 "data/maps/IkiTown/scripts.pory"
	delay 30
# 138 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 139 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 140 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 141 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 142 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 143 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 144 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_15
# 146 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 147 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 148 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 149 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 150 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14, MSGBOX_AUTOCLOSE
# 151 "data/maps/IkiTown/scripts.pory"
	delay 30
# 152 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 153 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 154 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 155 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 156 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 166 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 167 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 168 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 169 "data/maps/IkiTown/scripts.pory"
	delay 30
# 170 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 171 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 172 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_17
# 174 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 175 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 176 "data/maps/IkiTown/scripts.pory"
	waitse
# 177 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 178 "data/maps/IkiTown/scripts.pory"
	waitse
# 179 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 180 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 181 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 182 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 183 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_19
# 185 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 186 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 187 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 188 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 189 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_20
# 191 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 192 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 193 "data/maps/IkiTown/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_12:
# 196 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 197 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 198 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 199 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 200 "data/maps/IkiTown/scripts.pory"
	delay 30
# 201 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_POPPLIO, 0
# 202 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_14
# 203 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 204 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 205 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 206 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 207 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_22
# 209 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 210 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 211 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21, MSGBOX_AUTOCLOSE
# 212 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 213 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 214 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 215 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_8
# 216 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 217 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 218 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 228 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 229 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_10
# 230 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 231 "data/maps/IkiTown/scripts.pory"
	delay 30
# 232 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_11
# 233 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 234 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_23
# 236 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 237 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 238 "data/maps/IkiTown/scripts.pory"
	waitse
# 239 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 240 "data/maps/IkiTown/scripts.pory"
	waitse
# 241 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 242 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 243 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_16
# 244 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 245 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_24
# 247 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 248 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 249 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 250 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 251 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_25
# 253 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 254 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 255 "data/maps/IkiTown/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10

IkiTown_Trigger_HauGetStarter_13:
# 259 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_ROWLET, 0
# 260 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_21
# 261 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_15
# 262 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 263 "data/maps/IkiTown/scripts.pory"
	delay 30
# 264 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 265 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13
# 266 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 267 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 268 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 269 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 270 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_26
# 272 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 273 "data/maps/IkiTown/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 274 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_13, MSGBOX_AUTOCLOSE
# 275 "data/maps/IkiTown/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 276 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_9
# 277 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 278 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_8
# 279 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 280 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 281 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_16
# 291 "data/maps/IkiTown/scripts.pory"
	playmoncry SPECIES_LITTEN, 0
# 292 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_10
# 293 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 294 "data/maps/IkiTown/scripts.pory"
	delay 30
# 295 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon2, IkiTown_Trigger_HauGetStarter_Movement_11
# 296 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon2
# 297 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_27
# 299 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_12
# 300 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 301 "data/maps/IkiTown/scripts.pory"
	waitse
# 302 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 303 "data/maps/IkiTown/scripts.pory"
	waitse
# 304 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 305 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_18
# 306 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownmon1, IkiTown_Trigger_HauGetStarter_Movement_13
# 307 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownmon1
# 308 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_28
# 310 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 311 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 312 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 313 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 314 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_Trigger_HauGetStarter_Text_29
# 316 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_7
# 317 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 318 "data/maps/IkiTown/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	goto IkiTown_Trigger_HauGetStarter_10


Ikitown_RivalBattleYesNo::
# 325 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 326 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_RivalBattleYesNo_Text_0, MSGBOX_YESNO
# 328 "data/maps/IkiTown/scripts.pory"
	goto_if_eq VAR_RESULT, YES, IkiTown_StartRivalBattle
# 329 "data/maps/IkiTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RivalBattleNo
	end


RivalBattleNo::
# 334 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 335 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 336 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_Trigger_HauGetStarter_Movement_14
# 337 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 338 "data/maps/IkiTown/scripts.pory"
	msgbox RivalBattleNo_Text_0
# 340 "data/maps/IkiTown/scripts.pory"
	goto Ikitown_RivalBattleYesNo
	return


IkiTown_StartRivalBattle::
# 343 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 344 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 345 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownkukui
# 346 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 347 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_0
# 352 "data/maps/IkiTown/scripts.pory"
	special HealPlayerParty
# 353 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 354 "data/maps/IkiTown/scripts.pory"
	playfanfare MUS_HEAL
# 355 "data/maps/IkiTown/scripts.pory"
	waitfanfare
# 356 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 357 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 358 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_1
# 360 "data/maps/IkiTown/scripts.pory"
	switch VAR_STARTER_MON
# 361 "data/maps/IkiTown/scripts.pory"
	case 0, IkiTown_StartRivalBattle_3
# 369 "data/maps/IkiTown/scripts.pory"
	case 1, IkiTown_StartRivalBattle_4
# 377 "data/maps/IkiTown/scripts.pory"
	case 2, IkiTown_StartRivalBattle_5
IkiTown_StartRivalBattle_1:
# 386 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 387 "data/maps/IkiTown/scripts.pory"
	playse SE_BALL_OPEN
# 388 "data/maps/IkiTown/scripts.pory"
	delay 60
# 389 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownmon1
# 390 "data/maps/IkiTown/scripts.pory"
	removeobject ikitownmon2
# 391 "data/maps/IkiTown/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 392 "data/maps/IkiTown/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 393 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_0
# 394 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 395 "data/maps/IkiTown/scripts.pory"
	waitse
# 396 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 397 "data/maps/IkiTown/scripts.pory"
	waitse
# 398 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 399 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_5
# 409 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, IkiTown_Trigger_HauGetStarter_Movement_5
# 410 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownkukui
# 411 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 412 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_6, MSGBOX_AUTOCLOSE
# 420 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_1
# 421 "data/maps/IkiTown/scripts.pory"
	waitmovement ikitownhau
# 422 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownhau, IkiTown_StartRivalBattle_Movement_2
# 423 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 424 "data/maps/IkiTown/scripts.pory"
	waitse
# 425 "data/maps/IkiTown/scripts.pory"
	playse SE_LEDGE
# 426 "data/maps/IkiTown/scripts.pory"
	waitse
# 427 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 428 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_7
# 429 "data/maps/IkiTown/scripts.pory"
	setvar VAR_IKITOWN_STATE, 1
# 430 "data/maps/IkiTown/scripts.pory"
	release
	end

IkiTown_StartRivalBattle_3:
# 362 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_7
# 366 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_POPPLIO, IkiTown_StartRivalBattle_Text_2
IkiTown_StartRivalBattle_6:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_4:
# 370 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_11
# 374 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_ROWLET, IkiTown_StartRivalBattle_Text_3
IkiTown_StartRivalBattle_10:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_5:
# 378 "data/maps/IkiTown/scripts.pory"
	goto_if_set FLAG_RIVAL_SHINY, IkiTown_StartRivalBattle_15
# 382 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_LITTEN, IkiTown_StartRivalBattle_Text_4
IkiTown_StartRivalBattle_14:
	goto IkiTown_StartRivalBattle_1

IkiTown_StartRivalBattle_7:
# 363 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_POPPLIOSHINY, IkiTown_StartRivalBattle_Text_2
	goto IkiTown_StartRivalBattle_6

IkiTown_StartRivalBattle_11:
# 371 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_ROWLETSHINY, IkiTown_StartRivalBattle_Text_3
	goto IkiTown_StartRivalBattle_10

IkiTown_StartRivalBattle_15:
# 379 "data/maps/IkiTown/scripts.pory"
	trainerbattle_no_intro TRAINER_HAU_IKITOWN1_LITTENSHINY, IkiTown_StartRivalBattle_Text_4
	goto IkiTown_StartRivalBattle_14


IkiTown_Trigger_BottomGetStarters::
# 435 "data/maps/IkiTown/scripts.pory"
	lock
# 436 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_BottomGetStarters_Movement_0
# 437 "data/maps/IkiTown/scripts.pory"
	waitmovement LOCALID_PLAYER
# 438 "data/maps/IkiTown/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


IkiTown_Trigger_TopGetStarters::
# 441 "data/maps/IkiTown/scripts.pory"
	lock
# 442 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, IkiTown_Trigger_TopGetStarters_Movement_0
# 443 "data/maps/IkiTown/scripts.pory"
	waitmovement LOCALID_PLAYER
# 444 "data/maps/IkiTown/scripts.pory"
	call IkiTown_Trigger_HauGetStarter
	return


Ikitown_HauAfterBattle::
# 448 "data/maps/IkiTown/scripts.pory"
	lock
# 449 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 450 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_2
# 451 "data/maps/IkiTown/scripts.pory"
	msgbox IkiTown_StartRivalBattle_Text_7
# 452 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_KukuiAfterBattle::
# 457 "data/maps/IkiTown/scripts.pory"
	lock
# 458 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 459 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 460 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 462 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_Trigger_LeaveIkitownEarly::
# 467 "data/maps/IkiTown/scripts.pory"
	lock
# 468 "data/maps/IkiTown/scripts.pory"
	playse SE_PIN
# 469 "data/maps/IkiTown/scripts.pory"
	applymovement ikitownkukui, Ikitown_Trigger_LeaveIkitownEarly_Movement_0
# 470 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_Movement_1
# 471 "data/maps/IkiTown/scripts.pory"
	waitmovement 0
# 472 "data/maps/IkiTown/scripts.pory"
	speakername IkiTown_Trigger_HauGetStarter_Text_8
# 473 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_KukuiAfterBattle_Text_0
# 475 "data/maps/IkiTown/scripts.pory"
	applymovement LOCALID_PLAYER, Ikitown_Trigger_LeaveIkitownEarly_Movement_2
# 476 "data/maps/IkiTown/scripts.pory"
	waitmovement LOCALID_PLAYER
# 477 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_TrainerTipsSign::
# 482 "data/maps/IkiTown/scripts.pory"
	lock
# 483 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_TrainerTipsSign_Text_0
# 492 "data/maps/IkiTown/scripts.pory"
	release
	end


Ikitown_lassNPC::
# 497 "data/maps/IkiTown/scripts.pory"
	lock
# 498 "data/maps/IkiTown/scripts.pory"
	faceplayer
# 499 "data/maps/IkiTown/scripts.pory"
	msgbox Ikitown_lassNPC_Text_0
# 504 "data/maps/IkiTown/scripts.pory"
	release
	end


# 58 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_0:
# 58 "data/maps/IkiTown/scripts.pory"
	emote_question_mark
	step_end

# 59 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_1:
# 59 "data/maps/IkiTown/scripts.pory"
	walk_fast_down
# 59 "data/maps/IkiTown/scripts.pory"
	walk_fast_down
# 59 "data/maps/IkiTown/scripts.pory"
	walk_fast_down
# 59 "data/maps/IkiTown/scripts.pory"
	walk_fast_down
# 59 "data/maps/IkiTown/scripts.pory"
	walk_fast_down
# 59 "data/maps/IkiTown/scripts.pory"
	walk_fast_down
# 59 "data/maps/IkiTown/scripts.pory"
	walk_fast_down
# 59 "data/maps/IkiTown/scripts.pory"
	delay_16
# 59 "data/maps/IkiTown/scripts.pory"
	delay_16
# 59 "data/maps/IkiTown/scripts.pory"
	delay_16
# 59 "data/maps/IkiTown/scripts.pory"
	face_left
# 59 "data/maps/IkiTown/scripts.pory"
	delay_16
# 59 "data/maps/IkiTown/scripts.pory"
	delay_16
# 59 "data/maps/IkiTown/scripts.pory"
	delay_16
# 59 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 62 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_2:
# 62 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
# 62 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 64 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_3:
# 64 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 64 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
# 64 "data/maps/IkiTown/scripts.pory"
	walk_fast_right
	step_end

# 73 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_4:
# 73 "data/maps/IkiTown/scripts.pory"
	emote_x
	step_end

# 83 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_5:
# 83 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
# 83 "data/maps/IkiTown/scripts.pory"
	walk_in_place_left
	step_end

# 96 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_6:
# 96 "data/maps/IkiTown/scripts.pory"
	walk_fast_left
# 96 "data/maps/IkiTown/scripts.pory"
	walk_left
# 96 "data/maps/IkiTown/scripts.pory"
	walk_left
# 96 "data/maps/IkiTown/scripts.pory"
	walk_left
# 96 "data/maps/IkiTown/scripts.pory"
	walk_left
# 96 "data/maps/IkiTown/scripts.pory"
	walk_left
# 96 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 116 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_7:
# 116 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
# 116 "data/maps/IkiTown/scripts.pory"
	walk_in_place_right
	step_end

# 128 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_8:
# 128 "data/maps/IkiTown/scripts.pory"
	walk_left
# 128 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

# 134 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_9:
# 134 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
	step_end

# 167 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_10:
# 167 "data/maps/IkiTown/scripts.pory"
	emote_heart
	step_end

# 170 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_11:
# 170 "data/maps/IkiTown/scripts.pory"
	walk_left
# 170 "data/maps/IkiTown/scripts.pory"
	face_right
	step_end

# 174 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_12:
# 174 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
# 174 "data/maps/IkiTown/scripts.pory"
	jump_in_place_left
	step_end

# 181 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_13:
# 181 "data/maps/IkiTown/scripts.pory"
	walk_right
# 181 "data/maps/IkiTown/scripts.pory"
	face_down
	step_end

# 186 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_14:
# 186 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 198 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_15:
# 198 "data/maps/IkiTown/scripts.pory"
	face_up
# 198 "data/maps/IkiTown/scripts.pory"
	delay_16
# 198 "data/maps/IkiTown/scripts.pory"
	face_right
# 198 "data/maps/IkiTown/scripts.pory"
	delay_16
# 198 "data/maps/IkiTown/scripts.pory"
	face_down
# 198 "data/maps/IkiTown/scripts.pory"
	delay_16
# 198 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 243 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_HauGetStarter_Movement_16:
# 243 "data/maps/IkiTown/scripts.pory"
	walk_right
# 243 "data/maps/IkiTown/scripts.pory"
	face_up
	step_end

# 393 "data/maps/IkiTown/scripts.pory"
IkiTown_StartRivalBattle_Movement_0:
# 393 "data/maps/IkiTown/scripts.pory"
	jump_in_place_right
# 393 "data/maps/IkiTown/scripts.pory"
	jump_in_place_right
	step_end

# 420 "data/maps/IkiTown/scripts.pory"
IkiTown_StartRivalBattle_Movement_1:
# 420 "data/maps/IkiTown/scripts.pory"
	walk_left
# 420 "data/maps/IkiTown/scripts.pory"
	walk_left
# 420 "data/maps/IkiTown/scripts.pory"
	walk_left
# 420 "data/maps/IkiTown/scripts.pory"
	walk_up
# 420 "data/maps/IkiTown/scripts.pory"
	walk_up
# 420 "data/maps/IkiTown/scripts.pory"
	delay_16
# 420 "data/maps/IkiTown/scripts.pory"
	face_down
# 420 "data/maps/IkiTown/scripts.pory"
	delay_16
# 420 "data/maps/IkiTown/scripts.pory"
	delay_16
	step_end

# 422 "data/maps/IkiTown/scripts.pory"
IkiTown_StartRivalBattle_Movement_2:
# 422 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
# 422 "data/maps/IkiTown/scripts.pory"
	jump_in_place_down
	step_end

# 436 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_BottomGetStarters_Movement_0:
# 436 "data/maps/IkiTown/scripts.pory"
	walk_up
# 436 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 442 "data/maps/IkiTown/scripts.pory"
IkiTown_Trigger_TopGetStarters_Movement_0:
# 442 "data/maps/IkiTown/scripts.pory"
	walk_down
# 442 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 469 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_0:
# 469 "data/maps/IkiTown/scripts.pory"
	face_right
# 469 "data/maps/IkiTown/scripts.pory"
	emote_exclamation_mark
	step_end

# 470 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_1:
# 470 "data/maps/IkiTown/scripts.pory"
	face_left
	step_end

# 475 "data/maps/IkiTown/scripts.pory"
Ikitown_Trigger_LeaveIkitownEarly_Movement_2:
# 475 "data/maps/IkiTown/scripts.pory"
	walk_left
	step_end

IkiTown_Trigger_HauGetStarter_Text_0:
# 66 "data/maps/IkiTown/scripts.pory"
	.string "???$"

IkiTown_Trigger_HauGetStarter_Text_1:
# 67 "data/maps/IkiTown/scripts.pory"
	.string "Hey, hey!\p"
	.string "Which Pokémon are you gonna choose as\n"
	.string "your partner? {PAUSE 30} Have you decided?$"

IkiTown_Trigger_HauGetStarter_Text_2:
# 71 "data/maps/IkiTown/scripts.pory"
	.string "Hau$"

IkiTown_Trigger_HauGetStarter_Text_3:
# 75 "data/maps/IkiTown/scripts.pory"
	.string "Oh yeah! I'm Hau!\p"
	.string "I couldn't wait for us to pick our\n"
	.string "partners together, so I came to find\l"
	.string "you myself!$"

IkiTown_Trigger_HauGetStarter_Text_4:
# 81 "data/maps/IkiTown/scripts.pory"
	.string "I chose {STR_VAR_1}!$"

IkiTown_Trigger_HauGetStarter_Text_5:
# 81 "data/maps/IkiTown/scripts.pory"
	.string "You're too late.$"

IkiTown_Trigger_HauGetStarter_Text_6:
# 85 "data/maps/IkiTown/scripts.pory"
	.string "Whoa! {STR_VAR_1} is so cool!\p"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_7:
# 93 "data/maps/IkiTown/scripts.pory"
	.string "Hey wait!\n"
	.string "You already picked your Pokémon?!$"

IkiTown_Trigger_HauGetStarter_Text_8:
# 100 "data/maps/IkiTown/scripts.pory"
	.string "Kukui$"

IkiTown_Trigger_HauGetStarter_Text_9:
# 103 "data/maps/IkiTown/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose his partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_10:
# 110 "data/maps/IkiTown/scripts.pory"
	.string "Sorry about that, Hau.\p"
	.string "We had a little accident on the way\n"
	.string "here, so I ended up letting {PLAYER}\l"
	.string "choose her partner first without you.$"

IkiTown_Trigger_HauGetStarter_Text_11:
# 119 "data/maps/IkiTown/scripts.pory"
	.string "Fair enough.\p"
	.string "I guess it was just fate for you guys\n"
	.string "to meet!$"

IkiTown_Trigger_HauGetStarter_Text_12:
# 126 "data/maps/IkiTown/scripts.pory"
	.string "But you can choose one of the\n"
	.string "remaining two, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_13:
# 136 "data/maps/IkiTown/scripts.pory"
	.string "Mrawr!$"

IkiTown_Trigger_HauGetStarter_Text_14:
# 141 "data/maps/IkiTown/scripts.pory"
	.string "Bwark!$"

IkiTown_Trigger_HauGetStarter_Text_15:
# 144 "data/maps/IkiTown/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Popplio! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_16:
# 156 "data/maps/IkiTown/scripts.pory"
	.string "Alola, friend!\p"
	.string "I decided ages ago that you're the\n"
	.string "one I wanted to have an adventure\l"
	.string "with!\p"
	.string "We're gonna do so much awesome stuff\n"
	.string "together!\p"
	.string "Just you wait and see!$"

IkiTown_Trigger_HauGetStarter_Text_17:
# 172 "data/maps/IkiTown/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Litten, right?$"

IkiTown_Trigger_HauGetStarter_Text_18:
# 180 "data/maps/IkiTown/scripts.pory"
	.string "You better believe I will, Hau!$"

IkiTown_Trigger_HauGetStarter_Text_19:
# 183 "data/maps/IkiTown/scripts.pory"
	.string "All right then. Litten! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_20:
# 189 "data/maps/IkiTown/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Popplio have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_21:
# 197 "data/maps/IkiTown/scripts.pory"
	.string "Hoo!$"

IkiTown_Trigger_HauGetStarter_Text_22:
# 207 "data/maps/IkiTown/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Rowlet! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_23:
# 234 "data/maps/IkiTown/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Popplio, right?$"

IkiTown_Trigger_HauGetStarter_Text_24:
# 245 "data/maps/IkiTown/scripts.pory"
	.string "All right then. Popplio! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_25:
# 251 "data/maps/IkiTown/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Rowlet have a favor to ask.$"

IkiTown_Trigger_HauGetStarter_Text_26:
# 270 "data/maps/IkiTown/scripts.pory"
	.string "Then my partner will be…{PAUSE 30}\n"
	.string "Litten! I chose you!$"

IkiTown_Trigger_HauGetStarter_Text_27:
# 297 "data/maps/IkiTown/scripts.pory"
	.string "Professor!\n"
	.string "You'll take good care of Rowlet, right?$"

IkiTown_Trigger_HauGetStarter_Text_28:
# 308 "data/maps/IkiTown/scripts.pory"
	.string "All right then. Rowlet! Everybody!\n"
	.string "Time to get back in your balls for now!$"

IkiTown_Trigger_HauGetStarter_Text_29:
# 314 "data/maps/IkiTown/scripts.pory"
	.string "Wait up!\n"
	.string "Me and Litten have a favor to ask.$"

Ikitown_RivalBattleYesNo_Text_0:
# 326 "data/maps/IkiTown/scripts.pory"
	.string "Be our opponents in our first ever\n"
	.string "Pokémon battle together!$"

RivalBattleNo_Text_0:
# 338 "data/maps/IkiTown/scripts.pory"
	.string "Come on, don't be like that!\n"
	.string "It'll be fun!$"

IkiTown_StartRivalBattle_Text_0:
# 347 "data/maps/IkiTown/scripts.pory"
	.string "Hold on!\p"
	.string "Before you two step into the ring,\n"
	.string "let's make sure little {STR_VAR_1} is up\l"
	.string "to it!$"

IkiTown_StartRivalBattle_Text_1:
# 358 "data/maps/IkiTown/scripts.pory"
	.string "All right, I'm surely going to enjoy\n"
	.string "this!$"

IkiTown_StartRivalBattle_Text_2:
# 363 "data/maps/IkiTown/scripts.pory"
	.string "Our first defeat! Sorry, Popplio!$"

IkiTown_StartRivalBattle_Text_3:
# 371 "data/maps/IkiTown/scripts.pory"
	.string "Our first defeat! Sorry, Rowlet!$"

IkiTown_StartRivalBattle_Text_4:
# 379 "data/maps/IkiTown/scripts.pory"
	.string "Our first defeat! Sorry, Litten!$"

IkiTown_StartRivalBattle_Text_5:
# 399 "data/maps/IkiTown/scripts.pory"
	.string "Whoa! That was awesome, {PLAYER}!\p"
	.string "You and {STR_VAR_1} were both so\n"
	.string "cool!\p"
	.string "You've gotta have the kinda battles\n"
	.string "where everyone has fun.\p"
	.string "You and your partner Pokémon, too,\n"
	.string "you know?$"

IkiTown_StartRivalBattle_Text_6:
# 412 "data/maps/IkiTown/scripts.pory"
	.string "Right on {PLAYER}!\p"
	.string "You and Hau both brought out the\n"
	.string "best in your partners and pulled\l"
	.string "off some spectacular moves, yeah!\p"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

IkiTown_StartRivalBattle_Text_7:
# 428 "data/maps/IkiTown/scripts.pory"
	.string "You should totally check out Iki Town!$"

Ikitown_KukuiAfterBattle_Text_0:
# 460 "data/maps/IkiTown/scripts.pory"
	.string "Iki Town is right up those stairs.\n"
	.string "Come on, {PLAYER}!$"

Ikitown_TrainerTipsSign_Text_0:
# 483 "data/maps/IkiTown/scripts.pory"
	.string "Trainer Tips\p"
	.string "Pokémon can gain Exp. Points by\n"
	.string "battling other Pokémon.\p"
	.string "Exp. Points help them grow stronger.\n"
	.string "And your Pokémon will still get Exp.\l"
	.string "Points even if you catch a Pokémon\l"
	.string "you are battling against!$"

Ikitown_lassNPC_Text_0:
# 499 "data/maps/IkiTown/scripts.pory"
	.string "If you happen to pick up a Potion\n"
	.string "anywhere, use it on your Pokémon\l"
	.string "when it's low on HP…\l"
	.string "and it'll be feeling better before\\l"
	.string "you know it!$"
