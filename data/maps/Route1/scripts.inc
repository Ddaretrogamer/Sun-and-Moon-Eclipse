Route1_MapScripts::
# 2 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 12 "data/maps/Route1/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route1/scripts.pory"
	call_if_unset FLAG_IKITOWN_FESTIVAL_COMPLETE, Route1CloseGates
# 4 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_IKITOWN_FESTIVAL_COMPLETE, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 8 "data/maps/Route1/scripts.pory"
	setrespawn HEAL_LOCATION_PLAYER_HOUSE
	end

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 6 "data/maps/Route1/scripts.pory"
	call_if_unset FLAG_OPEN_TRAINER_SCHOOL, Route1CloseGates2
	goto Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 11 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 11 "data/maps/Route1/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_ROUTE1
	return

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/Route1/scripts.pory"
	map_script_2 FLAG_LILLIE_INTRO_PLAYED, FALSE, LittleGirlChasesMeowthIntro
# 13 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 10, Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
# 14 "data/maps/Route1/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 17, Route1_LillieWalkToLab
	.2byte 0

Route1_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 13 "data/maps/Route1/scripts.pory"
	call Route1_KukuiCatchingTutorial
	return


Route1_LillieWalkToLab::
# 18 "data/maps/Route1/scripts.pory"
	lock
# 19 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 20 "data/maps/Route1/scripts.pory"
	hideobjectat route1_mom, MAP_ROUTE1
# 21 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_0
# 22 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 23 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_1
# 24 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_2
# 25 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_3
# 26 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 27 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 28 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_1
# 31 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_4
# 32 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 33 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_2
# 35 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 36 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 37 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_3, MSGBOX_AUTOCLOSE
# 41 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 42 "data/maps/Route1/scripts.pory"
	waitdooranim
# 43 "data/maps/Route1/scripts.pory"
	showobjectat route1_mom, MAP_ROUTE1
# 44 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_6
# 45 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 46 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 47 "data/maps/Route1/scripts.pory"
	waitdooranim
# 48 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_7
# 49 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_7
# 50 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 52 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_5, MSGBOX_AUTOCLOSE
# 53 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_3
# 54 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 55 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_6
# 57 "data/maps/Route1/scripts.pory"
	addmoney 1000
# 58 "data/maps/Route1/scripts.pory"
	delay 30
# 59 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_8
# 60 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 61 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_7
# 67 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_9
# 68 "data/maps/Route1/scripts.pory"
	waitmovement route1_lillie
# 69 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_0
# 70 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_8, MSGBOX_AUTOCLOSE
# 74 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_10
# 75 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 76 "data/maps/Route1/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 77 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_9, MSGBOX_AUTOCLOSE
# 83 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 84 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 85 "data/maps/Route1/scripts.pory"
	opendoor 16, 20
# 86 "data/maps/Route1/scripts.pory"
	waitdooranim
# 87 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_12
# 88 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 89 "data/maps/Route1/scripts.pory"
	hideobjectat route1_mom, MAP_ROUTE1
# 90 "data/maps/Route1/scripts.pory"
	closedoor 16, 20
# 91 "data/maps/Route1/scripts.pory"
	waitdooranim
# 92 "data/maps/Route1/scripts.pory"
	applymovement route1_mom, Route1_LillieWalkToLab_Movement_11
# 93 "data/maps/Route1/scripts.pory"
	waitmovement route1_mom
# 94 "data/maps/Route1/scripts.pory"
	delay 30
# 95 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_5
# 96 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_13
# 97 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 98 "data/maps/Route1/scripts.pory"
	msgbox Route1_LillieWalkToLab_Text_10, MSGBOX_AUTOCLOSE
# 104 "data/maps/Route1/scripts.pory"
	applymovement route1_lillie, Route1_LillieWalkToLab_Movement_14
# 105 "data/maps/Route1/scripts.pory"
	removeobject route1_lillie
# 106 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_ROUTE1_LILLIE
# 107 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 108 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 18
# 109 "data/maps/Route1/scripts.pory"
	release
	end


Route1_AlolanMeowthNPC::
# 114 "data/maps/Route1/scripts.pory"
	lock
# 115 "data/maps/Route1/scripts.pory"
	faceplayer
# 116 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 117 "data/maps/Route1/scripts.pory"
	msgbox Route1_AlolanMeowthNPC_Text_0
# 118 "data/maps/Route1/scripts.pory"
	release
	end


Route1_LittleGirlPressB::
# 123 "data/maps/Route1/scripts.pory"
	lock
# 124 "data/maps/Route1/scripts.pory"
	faceplayer
# 125 "data/maps/Route1/scripts.pory"
	msgbox Route1_LittleGirlPressB_Text_0
# 129 "data/maps/Route1/scripts.pory"
	release
	return


Route1_Trigger_BlockRightPath::
# 134 "data/maps/Route1/scripts.pory"
	lock
# 135 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_4
# 136 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 137 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_0
# 142 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_4
# 143 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 144 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_ROCKRUFF, 0
# 145 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_Trigger_BlockRightPath_Movement_0
# 146 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 147 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_BlockRightPath_Text_1, MSGBOX_AUTOCLOSE
# 148 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_LillieWalkToLab_Movement_6
# 149 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 150 "data/maps/Route1/scripts.pory"
	applymovement route1blockingboy, Route1_LillieWalkToLab_Movement_7
# 151 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingboy
# 152 "data/maps/Route1/scripts.pory"
	applymovement route1blockingrockruff, Route1_LillieWalkToLab_Movement_7
# 153 "data/maps/Route1/scripts.pory"
	waitmovement route1blockingrockruff
# 154 "data/maps/Route1/scripts.pory"
	release
	end


Route1CloseGates::
# 159 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_closed
	return


Route1CloseGates2::
# 164 "data/maps/Route1/scripts.pory"
	setmaplayoutindex LAYOUT_ROUTE1_leftclosed
	return


LittleGirlChasesMeowthIntro::
# 169 "data/maps/Route1/scripts.pory"
	lock
# 170 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 171 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 172 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_0
# 173 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_0
# 174 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 175 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_1
# 176 "data/maps/Route1/scripts.pory"
	applymovement chasedmeowth, LittleGirlChasesMeowthIntro_Movement_2
# 177 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 178 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH_ALOLA, 0
# 179 "data/maps/Route1/scripts.pory"
	delay 60
# 180 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_3
# 181 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 182 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, LittleGirlChasesMeowthIntro_Movement_4
# 183 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 184 "data/maps/Route1/scripts.pory"
	gettimeofday
# 185 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_NIGHT
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 185 "data/maps/Route1/scripts.pory"
	compare VAR_0x8000, TIME_EVENING
	goto_if_eq LittleGirlChasesMeowthIntro_2
# 195 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 196 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_1
LittleGirlChasesMeowthIntro_1:
# 202 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_2
# 204 "data/maps/Route1/scripts.pory"
	applymovement momintro, Route1_LillieWalkToLab_Movement_7
# 205 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 206 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_3
# 208 "data/maps/Route1/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 209 "data/maps/Route1/scripts.pory"
	waitmessage
# 210 "data/maps/Route1/scripts.pory"
	playmoncry SPECIES_MEOWTH, 0
# 211 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_4
# 212 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 213 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 214 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 215 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_FESTIVALNPCS3
# 216 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_INTRO_UR
# 217 "data/maps/Route1/scripts.pory"
	warp MAP_PLAYER_ROOM, 12, 10
# 218 "data/maps/Route1/scripts.pory"
	waitstate
# 219 "data/maps/Route1/scripts.pory"
	release
	end

LittleGirlChasesMeowthIntro_2:
# 186 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 187 "data/maps/Route1/scripts.pory"
	msgbox LittleGirlChasesMeowthIntro_Text_0
	goto LittleGirlChasesMeowthIntro_1


Route1_KukuiCatchingTutorial::
# 224 "data/maps/Route1/scripts.pory"
	lock
# 225 "data/maps/Route1/scripts.pory"
	playse SE_PIN
# 226 "data/maps/Route1/scripts.pory"
	special SpawnCameraObject
# 227 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_0
# 228 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_1
# 229 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 230 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 231 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_1, MSGBOX_AUTOCLOSE
# 242 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_2
# 243 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 244 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 245 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2, MSGBOX_AUTOCLOSE
# 250 "data/maps/Route1/scripts.pory"
	applymovement catchingintrokukui, Route1_KukuiCatchingTutorial_Movement_3
# 251 "data/maps/Route1/scripts.pory"
	waitmovement catchingintrokukui
# 252 "data/maps/Route1/scripts.pory"
	removeobject catchingintrokukui
# 253 "data/maps/Route1/scripts.pory"
	delay 30
# 254 "data/maps/Route1/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, Route1_KukuiCatchingTutorial_Movement_4
# 255 "data/maps/Route1/scripts.pory"
	waitmovement 0
# 256 "data/maps/Route1/scripts.pory"
	special RemoveCameraObject
# 257 "data/maps/Route1/scripts.pory"
	setvar VAR_IKITOWN_STATE, 11
# 258 "data/maps/Route1/scripts.pory"
	setflag FLAG_KUKUI_CATCHING_TUTORIAL1
# 259 "data/maps/Route1/scripts.pory"
	clearflag FLAG_KUKUI_CATCHING_TUTORIAL2
# 260 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS
# 261 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_IKITOWN_FESTIVALNPCS2
# 262 "data/maps/Route1/scripts.pory"
	setflag FLAG_HIDE_IKITOWN_REGULARNPCS
# 263 "data/maps/Route1/scripts.pory"
	clearflag FLAG_HIDE_INTRO_UR
# 264 "data/maps/Route1/scripts.pory"
	release
	end


Route1_trigger_kukui_catching_tutorial::
# 269 "data/maps/Route1/scripts.pory"
	lock
# 270 "data/maps/Route1/scripts.pory"
	speakername Route1_KukuiCatchingTutorial_Text_0
# 271 "data/maps/Route1/scripts.pory"
	msgbox Route1_KukuiCatchingTutorial_Text_2
# 276 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 277 "data/maps/Route1/scripts.pory"
	release
	end


MomSaysHi::
# 282 "data/maps/Route1/scripts.pory"
	lock
# 283 "data/maps/Route1/scripts.pory"
	faceplayer
# 284 "data/maps/Route1/scripts.pory"
	speakername Route1_LillieWalkToLab_Text_4
# 285 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_0
# 286 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 287 "data/maps/Route1/scripts.pory"
	playfanfare MUS_HEAL
# 288 "data/maps/Route1/scripts.pory"
	waitfanfare
# 289 "data/maps/Route1/scripts.pory"
	special HealPlayerParty
# 290 "data/maps/Route1/scripts.pory"
	setflag FLAG_DN_FLAG_DEXNAV_GET
# 291 "data/maps/Route1/scripts.pory"
	setflag FLAG_ENABLE_STAT_EDITOR
# 292 "data/maps/Route1/scripts.pory"
	setflag FLAG_PORTABLE_PC_TOGGLE
# 293 "data/maps/Route1/scripts.pory"
	setflag FLAG_RECEIVED_SUPER_ROD
# 294 "data/maps/Route1/scripts.pory"
	setflag FLAG_EGG_MOVES
# 295 "data/maps/Route1/scripts.pory"
	setflag FLAG_TUTOR_MOVES
# 296 "data/maps/Route1/scripts.pory"
	goto_if_set FLAG_SHINY_RIDE, MomSaysHi_2
# 302 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_RIDE
# 303 "data/maps/Route1/scripts.pory"
	setflag FLAG_SHINY_SURF
MomSaysHi_1:
# 305 "data/maps/Route1/scripts.pory"
	compare VAR_ROTOM_PHONE_ENABLE, 1
	goto_if_lt MomSaysHi_6
# 310 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 0
MomSaysHi_5:
# 312 "data/maps/Route1/scripts.pory"
	release
# 313 "data/maps/Route1/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 314 "data/maps/Route1/scripts.pory"
	msgbox MomSaysHi_Text_1
# 315 "data/maps/Route1/scripts.pory"
	release
	end

MomSaysHi_2:
# 298 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_RIDE
# 299 "data/maps/Route1/scripts.pory"
	clearflag FLAG_SHINY_SURF
	goto MomSaysHi_1

MomSaysHi_6:
# 307 "data/maps/Route1/scripts.pory"
	setvar VAR_ROTOM_PHONE_ENABLE, 1
	goto MomSaysHi_5


Mailbox::
# 320 "data/maps/Route1/scripts.pory"
	lock
# 321 "data/maps/Route1/scripts.pory"
	msgbox Mailbox_Text_0
# 322 "data/maps/Route1/scripts.pory"
	release
	end


Route1LittleBoyNPC::
# 327 "data/maps/Route1/scripts.pory"
	msgbox Route1LittleBoyNPC_Text_0, MSGBOX_NPC
	end


testscript::
# 332 "data/maps/Route1/scripts.pory"
	msgbox testscript_Text_0, MSGBOX_NPC
	end


Route1_Trigger_HeadEastToIkiTown::
# 352 "data/maps/Route1/scripts.pory"
	lock
# 353 "data/maps/Route1/scripts.pory"
	msgbox Route1_Trigger_HeadEastToIkiTown_Text_0, MSGBOX_AUTOCLOSE
# 355 "data/maps/Route1/scripts.pory"
	applymovement LOCALID_PLAYER, Route1_trigger_kukui_catching_tutorial_Movement_0
# 356 "data/maps/Route1/scripts.pory"
	waitmovement LOCALID_PLAYER
# 357 "data/maps/Route1/scripts.pory"
	release
	end


# 21 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_0:
# 21 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
# 21 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 23 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_1:
# 23 "data/maps/Route1/scripts.pory"
	walk_down
# 23 "data/maps/Route1/scripts.pory"
	walk_down
# 23 "data/maps/Route1/scripts.pory"
	walk_down
# 23 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 24 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_2:
# 24 "data/maps/Route1/scripts.pory"
	delay_16
# 24 "data/maps/Route1/scripts.pory"
	delay_16
# 24 "data/maps/Route1/scripts.pory"
	delay_16
# 24 "data/maps/Route1/scripts.pory"
	face_right
	step_end

# 25 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_3:
# 25 "data/maps/Route1/scripts.pory"
	walk_down
# 25 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 31 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_4:
# 31 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 35 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_5:
# 35 "data/maps/Route1/scripts.pory"
	face_right
	step_end

# 44 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_6:
# 44 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 48 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_7:
# 48 "data/maps/Route1/scripts.pory"
	face_up
	step_end

# 59 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_8:
# 59 "data/maps/Route1/scripts.pory"
	walk_left
# 59 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 67 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_9:
# 67 "data/maps/Route1/scripts.pory"
	walk_in_place_up
# 67 "data/maps/Route1/scripts.pory"
	walk_in_place_up
	step_end

# 74 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_10:
# 74 "data/maps/Route1/scripts.pory"
	walk_right
# 74 "data/maps/Route1/scripts.pory"
	face_down
	step_end

# 83 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_11:
# 83 "data/maps/Route1/scripts.pory"
	walk_up
# 83 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 87 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_12:
# 87 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 96 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_13:
# 96 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 104 "data/maps/Route1/scripts.pory"
Route1_LillieWalkToLab_Movement_14:
# 104 "data/maps/Route1/scripts.pory"
	walk_left
# 104 "data/maps/Route1/scripts.pory"
	walk_left
# 104 "data/maps/Route1/scripts.pory"
	walk_left
# 104 "data/maps/Route1/scripts.pory"
	walk_left
# 104 "data/maps/Route1/scripts.pory"
	walk_left
# 104 "data/maps/Route1/scripts.pory"
	walk_left
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
# 104 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 145 "data/maps/Route1/scripts.pory"
Route1_Trigger_BlockRightPath_Movement_0:
# 145 "data/maps/Route1/scripts.pory"
	walk_in_place_down
# 145 "data/maps/Route1/scripts.pory"
	walk_in_place_down
	step_end

# 172 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_0:
# 172 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 172 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 172 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 172 "data/maps/Route1/scripts.pory"
	walk_fast_down
# 172 "data/maps/Route1/scripts.pory"
	walk_fast_down
	step_end

# 175 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_1:
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 175 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 176 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_2:
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
# 176 "data/maps/Route1/scripts.pory"
	walk_fast_left
	step_end

# 180 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_3:
# 180 "data/maps/Route1/scripts.pory"
	walk_slow_up
# 180 "data/maps/Route1/scripts.pory"
	walk_slow_up
	step_end

# 182 "data/maps/Route1/scripts.pory"
LittleGirlChasesMeowthIntro_Movement_4:
# 182 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 182 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
# 182 "data/maps/Route1/scripts.pory"
	walk_slow_diag_northeast
	step_end

# 227 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_0:
# 227 "data/maps/Route1/scripts.pory"
	emote_exclamation_mark
	step_end

# 228 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_1:
# 228 "data/maps/Route1/scripts.pory"
	delay_16
# 228 "data/maps/Route1/scripts.pory"
	delay_16
# 228 "data/maps/Route1/scripts.pory"
	delay_16
# 228 "data/maps/Route1/scripts.pory"
	walk_down
# 228 "data/maps/Route1/scripts.pory"
	walk_down
# 228 "data/maps/Route1/scripts.pory"
	walk_down
	step_end

# 242 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_2:
# 242 "data/maps/Route1/scripts.pory"
	walk_down
# 242 "data/maps/Route1/scripts.pory"
	walk_right
# 242 "data/maps/Route1/scripts.pory"
	walk_right
# 242 "data/maps/Route1/scripts.pory"
	walk_right
# 242 "data/maps/Route1/scripts.pory"
	walk_right
# 242 "data/maps/Route1/scripts.pory"
	walk_right
# 242 "data/maps/Route1/scripts.pory"
	walk_right
# 242 "data/maps/Route1/scripts.pory"
	face_left
	step_end

# 250 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_3:
# 250 "data/maps/Route1/scripts.pory"
	walk_right
# 250 "data/maps/Route1/scripts.pory"
	walk_right
# 250 "data/maps/Route1/scripts.pory"
	walk_right
# 250 "data/maps/Route1/scripts.pory"
	walk_right
# 250 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

# 254 "data/maps/Route1/scripts.pory"
Route1_KukuiCatchingTutorial_Movement_4:
# 254 "data/maps/Route1/scripts.pory"
	walk_up
# 254 "data/maps/Route1/scripts.pory"
	walk_up
# 254 "data/maps/Route1/scripts.pory"
	walk_up
	step_end

# 276 "data/maps/Route1/scripts.pory"
Route1_trigger_kukui_catching_tutorial_Movement_0:
# 276 "data/maps/Route1/scripts.pory"
	walk_right
	step_end

Route1_LillieWalkToLab_Text_0:
# 27 "data/maps/Route1/scripts.pory"
	.string "Lillie$"

Route1_LillieWalkToLab_Text_1:
# 28 "data/maps/Route1/scripts.pory"
	.string "Oh, Um…\p"
	.string "The professor said…$"

Route1_LillieWalkToLab_Text_2:
# 33 "data/maps/Route1/scripts.pory"
	.string "“Hey there, Lillie!\n"
	.string "Bring me that great new Trainer. Woo!”$"

Route1_LillieWalkToLab_Text_3:
# 37 "data/maps/Route1/scripts.pory"
	.string "So I'm here to show you the way to his\n"
	.string "Pokémon Lab, if you'll come with me!\p"
	.string "It's, um… It's this way.$"

Route1_LillieWalkToLab_Text_4:
# 51 "data/maps/Route1/scripts.pory"
	.string "Mom$"

Route1_LillieWalkToLab_Text_5:
# 52 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!$"

Route1_LillieWalkToLab_Text_6:
# 55 "data/maps/Route1/scripts.pory"
	.string "Here. A little pocket money for you.\n"
	.string "Don't go wasting it on anything silly!$"

Route1_LillieWalkToLab_Text_7:
# 61 "data/maps/Route1/scripts.pory"
	.string "Oh! Well done, {PLAYER}.\n"
	.string "You're already making friends?\l"
	.string "And what a cute friend you've found!\p"
	.string "I knew Alola would be a great place for\n"
	.string "us. We keep meeting wonderful people!$"

Route1_LillieWalkToLab_Text_8:
# 70 "data/maps/Route1/scripts.pory"
	.string "M-me? Well, thank you…\p"
	.string "My name is Lillie.\n"
	.string "It's very nice to meet you.$"

Route1_LillieWalkToLab_Text_9:
# 77 "data/maps/Route1/scripts.pory"
	.string "Looks like its finally your time to\n"
	.string "shine, sweetie!\p"
	.string "Enjoy yourself out there with\n"
	.string "{STR_VAR_1}.\l"
	.string "And don't be gone too long!$"

Route1_LillieWalkToLab_Text_10:
# 98 "data/maps/Route1/scripts.pory"
	.string "You…have a very nice mother, don't you?\p"
	.string "We should get going.\p"
	.string "It's just south to the Pokémon\n"
	.string "Research Lab.$"

Route1_AlolanMeowthNPC_Text_0:
# 117 "data/maps/Route1/scripts.pory"
	.string "Hsss!$"

Route1_LittleGirlPressB_Text_0:
# 125 "data/maps/Route1/scripts.pory"
	.string "You can go with me!\n"
	.string "If you can dash with {B_BUTTON}!\p"
	.string "What do you think of my song?$"

Route1_Trigger_BlockRightPath_Text_0:
# 137 "data/maps/Route1/scripts.pory"
	.string "Watch it, cuz!\p"
	.string "It's dangerous to get too close to\n"
	.string "a Pokémon while it's using one of\l"
	.string "its moves!$"

Route1_Trigger_BlockRightPath_Text_1:
# 147 "data/maps/Route1/scripts.pory"
	.string "Ruff!$"

LittleGirlChasesMeowthIntro_Text_0:
# 187 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Could anything be more soothing?\n"
	.string "The first evening spent under\l"
	.string "Alola's calm moon!\p"
	.string "I feel like I could stay out here all\n"
	.string "night!$"

LittleGirlChasesMeowthIntro_Text_1:
# 196 "data/maps/Route1/scripts.pory"
	.string "Ahhh! Can't you just feel that warmth?\n"
	.string "The first day spent under Alola's\l"
	.string "sun!\p"
	.string "It's so warm and bright here!$"

LittleGirlChasesMeowthIntro_Text_2:
# 202 "data/maps/Route1/scripts.pory"
	.string "But that's enough of that!\n"
	.string "Time to unpack all these boxes!$"

LittleGirlChasesMeowthIntro_Text_3:
# 206 "data/maps/Route1/scripts.pory"
	.string "Meowth?\n"
	.string "Go get {PLAYER} for me, would you?$"

LittleGirlChasesMeowthIntro_Text_4:
# 211 "data/maps/Route1/scripts.pory"
	.string "Meow?$"

Route1_KukuiCatchingTutorial_Text_0:
# 230 "data/maps/Route1/scripts.pory"
	.string "Kukui$"

Route1_KukuiCatchingTutorial_Text_1:
# 231 "data/maps/Route1/scripts.pory"
	.string "Hey there, {PLAYER}!\n"
	.string "It's about time we set out for the\l"
	.string "festival, yeah!\p"
	.string "But first…\n"
	.string "I've got something to teach you,\l"
	.string "yeah, now that you're a real\l"
	.string "Pokémon Trainer.\p"
	.string "It's the most basic of all the basics.\n"
	.string "Come on-to Route 1!$"

Route1_KukuiCatchingTutorial_Text_2:
# 245 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}!\n"
	.string "Hurry it up, cousin!\p"
	.string "Pretend you're a Pokémon and use your\n"
	.string "Agility!$"

MomSaysHi_Text_0:
# 285 "data/maps/Route1/scripts.pory"
	.string "How are you doing, honey?\n"
	.string "You look a little tired.\p"
	.string "You should take a rest.$"

MomSaysHi_Text_1:
# 314 "data/maps/Route1/scripts.pory"
	.string "Take care, honey!$"

Mailbox_Text_0:
# 321 "data/maps/Route1/scripts.pory"
	.string "{PLAYER}'s House$"

Route1LittleBoyNPC_Text_0:
# 327 "data/maps/Route1/scripts.pory"
	.string "I gotta catch more Pokémon!\nPokémon with cool knees are so neat.$"

testscript_Text_0:
# 332 "data/maps/Route1/scripts.pory"
	.string "okay this is a test.\n"
	.string "It seems this is a suitable line lengthc\l"
	.string "for scripting. This is working well.\p"
	.string "Do I need to do anything to compile\n"
	.string "this?\p"
	.string "10-4, good buddy! I'll let everybody out\n"
	.string "here know you're on your way!\p"
	.string "Yeah, that's a name that hits you like a\n"
	.string "Trop Kick right to the head! Woo!\p"
	.string "Can't wait to see you here in person then,\n"
	.string "cousin!$"

Route1_Trigger_HeadEastToIkiTown_Text_0:
# 353 "data/maps/Route1/scripts.pory"
	.string "The Iki Town Festival awaits!\n"
	.string "Head east, cousin!$"
