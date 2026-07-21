HauoliOutskirts_MapScripts::
# 3 "data/maps/HauoliOutskirts/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

HauoliOutskirts_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/HauoliOutskirts/scripts.pory"
	map_script_2 VAR_IKITOWN_STATE, 20, HauoliOutskirts_ExitLabEclipse
	.2byte 0


HauoliOutskirts_ExitLabEclipse::
# 8 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 9 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_0
# 11 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 12 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 13 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_1
# 14 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 15 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 16 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_2
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_3
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	delay 30
# 20 "data/maps/HauoliOutskirts/scripts.pory"
	opendoor 25, 12
# 21 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 22 "data/maps/HauoliOutskirts/scripts.pory"
	showobjectat kukui_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 23 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement kukui_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_4
# 24 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement kukui_outside_lab
# 25 "data/maps/HauoliOutskirts/scripts.pory"
	closedoor 25, 12
# 26 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 27 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_5
# 28 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
# 29 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 30 "data/maps/HauoliOutskirts/scripts.pory"
	delay 60
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_ExitLabEclipse_Movement_6
# 32 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
# 33 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 34 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 35 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_ExitLabEclipse_Text_1, MSGBOX_AUTOCLOSE
# 37 "data/maps/HauoliOutskirts/scripts.pory"
	setweather WEATHER_SHADE
# 38 "data/maps/HauoliOutskirts/scripts.pory"
	doweather
# 39 "data/maps/HauoliOutskirts/scripts.pory"
	special WaitWeather
# 40 "data/maps/HauoliOutskirts/scripts.pory"
	delay 120
# 41 "data/maps/HauoliOutskirts/scripts.pory"
	openscreenshot 4
# 42 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 48 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_IKITOWN_STATE, 21
# 49 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirts_LillieOutsideLab::
# 54 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 55 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_LILLIE_OUTSIDE_LAB
# 56 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 57 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 58 "data/maps/HauoliOutskirts/scripts.pory"
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
# 59 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 60 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_0, MSGBOX_AUTOCLOSE
# 75 "data/maps/HauoliOutskirts/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 76 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_1
# 77 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 78 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_1, MSGBOX_AUTOCLOSE
# 79 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 80 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 81 "data/maps/HauoliOutskirts/scripts.pory"
	waitmessage
# 82 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 83 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_2, MSGBOX_AUTOCLOSE
# 102 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 103 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 104 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 105 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 106 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 107 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 108 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 109 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 110 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 111 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 112 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_LillieOutsideLab_Text_3
# 113 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_4, MSGBOX_AUTOCLOSE
# 116 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 117 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_3
HauoliOutskirts_LillieOutsideLab_1:
# 120 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_9
HauoliOutskirts_LillieOutsideLab_8:
# 124 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
HauoliOutskirts_LillieOutsideLab_6:
# 126 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 127 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 128 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_5, MSGBOX_AUTOCLOSE
# 144 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 145 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 146 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 147 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 148 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 149 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 150 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 151 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 152 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 153 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 154 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 155 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_6, MSGBOX_AUTOCLOSE
# 156 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 157 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 158 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_14
HauoliOutskirts_LillieOutsideLab_12:
# 161 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_20
HauoliOutskirts_LillieOutsideLab_19:
# 165 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_7
HauoliOutskirts_LillieOutsideLab_17:
# 167 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 168 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_ExitLabEclipse_Text_0
# 169 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_7, MSGBOX_AUTOCLOSE
# 186 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_3
# 187 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 188 "data/maps/HauoliOutskirts/scripts.pory"
	opendoor 25, 12
# 189 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 190 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_4
# 191 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 192 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat lillie_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 193 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 194 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 195 "data/maps/HauoliOutskirts/scripts.pory"
	closedoor 25, 12
# 196 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 197 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 198 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOutskirts_LillieOutsideLab_2:
# 118 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_6
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_3:
# 117 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_2
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_7:
# 121 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
	goto HauoliOutskirts_LillieOutsideLab_6

HauoliOutskirts_LillieOutsideLab_9:
# 120 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_7
	goto HauoliOutskirts_LillieOutsideLab_8

HauoliOutskirts_LillieOutsideLab_13:
# 159 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_6
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_14:
# 158 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_13
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_18:
# 162 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_ExitLabEclipse_Movement_5
	goto HauoliOutskirts_LillieOutsideLab_17

HauoliOutskirts_LillieOutsideLab_20:
# 161 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_18
	goto HauoliOutskirts_LillieOutsideLab_19


HauoliOutskirts_LillieOutsideLabSkip::
# 203 "data/maps/HauoliOutskirts/scripts.pory"
	closemessage
# 204 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 205 "data/maps/HauoliOutskirts/scripts.pory"
	special StopAllObjectMovements
# 206 "data/maps/HauoliOutskirts/scripts.pory"
	special CloseScriptMenus
# 207 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 208 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 209 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 210 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


LabSign::
# 215 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 216 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox LabSign_Text_0
# 217 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


OutsideTenCarrotHill::
# 222 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 223 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 224 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox OutsideTenCarrotHill_Text_0
# 225 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


TenCarrotHillSign::
# 229 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 230 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox TenCarrotHillSign_Text_0
# 231 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLittleGirlNPC::
# 235 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 236 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 237 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLittleGirlNPC_Text_0
# 238 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOustkirtsTrainerTipsSign::
# 243 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 244 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsTrainerTipsSign_Text_0
# 245 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLassNPC::
# 250 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLassNPC_Text_0, MSGBOX_NPC
	end


HauoliOustkirtsFishingSpot1::
# 255 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 256 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_SURF_MON_SLOT, 0
	goto_if_eq HauoliOustkirtsFishingSpot1_2
# 277 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_2
HauoliOustkirtsFishingSpot1_1:
# 279 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_2:
# 258 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_0, MSGBOX_YESNO
# 259 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_5
# 271 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_5:
# 261 "data/maps/HauoliOutskirts/scripts.pory"
	checkitem ITEM_SUPER_ROD
# 262 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_8
# 267 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_1
	goto HauoliOustkirtsFishingSpot1_1

HauoliOustkirtsFishingSpot1_8:
# 264 "data/maps/HauoliOutskirts/scripts.pory"
	startfishing
	goto HauoliOustkirtsFishingSpot1_1


# 10 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_0:
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
	step_end

# 13 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_1:
# 13 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
# 13 "data/maps/HauoliOutskirts/scripts.pory"
	emote_exclamation_mark
	step_end

# 16 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_2:
# 16 "data/maps/HauoliOutskirts/scripts.pory"
	delay_8
# 16 "data/maps/HauoliOutskirts/scripts.pory"
	walk_left
# 16 "data/maps/HauoliOutskirts/scripts.pory"
	face_right
	step_end

# 17 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_3:
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	delay_16
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	face_left
	step_end

# 23 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_4:
# 23 "data/maps/HauoliOutskirts/scripts.pory"
	walk_down
	step_end

# 27 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_5:
# 27 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 31 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_6:
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	face_right
	step_end

# 32 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_ExitLabEclipse_Movement_7:
# 32 "data/maps/HauoliOutskirts/scripts.pory"
	face_left
	step_end

# 56 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_0:
# 56 "data/maps/HauoliOutskirts/scripts.pory"
	face_player
	step_end

# 76 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_1:
# 76 "data/maps/HauoliOutskirts/scripts.pory"
	shake_horizontal
	step_end

# 109 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_2:
# 109 "data/maps/HauoliOutskirts/scripts.pory"
	emote_exclamation_mark
# 109 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 186 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_3:
# 186 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
# 186 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

# 190 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_4:
# 190 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

HauoliOutskirts_ExitLabEclipse_Text_0:
# 34 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Lillie$"

HauoliOutskirts_ExitLabEclipse_Text_1:
# 35 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon Center is practically right\n"
	.string "next to your house, isn't it?$"

HauoliOutskirts_LillieOutsideLab_Text_0:
# 60 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Hey {PLAYER}.\n"
	.string "You made it.\p"
	.string "Since I'm not a Trainer, I have to rely\n"
	.string "on using Repels all the time.\p"
	.string "You do know that using a Repel keeps\n"
	.string "Pokémon from attacking, right?\p"
	.string "A-and about Nebby…\p"
	.string "Oh. I mean…Cosmog.\p"
	.string "Cosmog seems to be a very rare Pokémon.\n"
	.string "It came from far, far away.$"

HauoliOutskirts_LillieOutsideLab_Text_1:
# 78 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pew!$"

HauoliOutskirts_LillieOutsideLab_Text_2:
# 83 "data/maps/HauoliOutskirts/scripts.pory"
	.string "It seems to have a very strange power…\p"
	.string "It used that power to save me once\n"
	.string "when I was in danger.\p"
	.string "But some…other people want Cosmog for\n"
	.string "themselves, to use that power.\p"
	.string "That's why only the professor and\n"
	.string "Kahuna Hala and other people I can\l"
	.string "trust know about it…\p"
	.string "Can you keep a secret?\p"
	.string "Can you not tell anyone else about\n"
	.string "Nebby or what happened on that\l"
	.string "Bridge?\p"
	.string "Please…$"

HauoliOutskirts_LillieOutsideLab_Text_3:
# 112 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Kukui$"

HauoliOutskirts_LillieOutsideLab_Text_4:
# 113 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Oh yeah, Rockruff! Lets go!\n"
	.string "Give it everything you've got!\l"
	.string "My body is ready. Woo!$"

HauoliOutskirts_LillieOutsideLab_Text_5:
# 128 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ah…\n"
	.string "There they go again…\p"
	.string "The Pokémon Research Lab has its own\n"
	.string "unique charm, as you might agree.\p"
	.string "I've actually been, um, imposing on\n"
	.string "the professor here for the last few\l"
	.string "months.\p"
	.string "I'm not much of an assistant, but it's\n"
	.string "the least I can do to pay him back\l"
	.string "for letting me stay.\p"
	.string "Maybe I'd be more help if I were a real\n"
	.string "Pokémon Trainer, too.$"

HauoliOutskirts_LillieOutsideLab_Text_6:
# 155 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Raaaa-oooooohhh! Raff ruff!$"

HauoliOutskirts_LillieOutsideLab_Text_7:
# 169 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The professor…\p"
	.string "He never stops researching moves.\n"
	.string "Not even…{PAUSE 30}inside the lab itself.\p"
	.string "Looks like we'll have to patch up\n"
	.string "the roof again…  \p"
	.string "And I had just washed his lab coat\n"
	.string "and finally gotten it clean, too.\l"
	.string "Now it'll be in shreds…\l"
	.string "and I'm no good at mending clothes…\p"
	.string "He'll just have to buy another new one…\p"
	.string "We should probably go in before he does\n"
	.string "any more damage…$"

LabSign_Text_0:
# 216 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pokémon Research Lab$"

OutsideTenCarrotHill_Text_0:
# 224 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Wa ha ha!\n"
	.string "You're a strong Trainer, all right!\l"
	.string "Go on! You take on Ten Carrot Hill,\l"
	.string "friend!\p"
	.string "Even stronger Pokémon await you\n"
	.string "within!$"

TenCarrotHillSign_Text_0:
# 230 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ten Carrot Hill$"

HauoliOutskirtLittleGirlNPC_Text_0:
# 237 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon I've got with me are all\n"
	.string "Grass-type.\p"
	.string "I'm looking for Water-type Pokémon\l"
	.string "for my team so I can beat Fire types,\l"
	.string "too.$"

HauoliOustkirtsTrainerTipsSign_Text_0:
# 244 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Trainer Tips\p"
	.string "The Pokémon that will appear first in\n"
	.string "battle will be the one you've put in\l"
	.string "the left position in your Pokémon\l"
	.string "party.$"

HauoliOutskirtLassNPC_Text_0:
# 250 "data/maps/HauoliOutskirts/scripts.pory"
	.string "If you see a Pokémon Trainer, you've\ngotta show off the Pokémon you like!$"

HauoliOustkirtsFishingSpot1_Text_0:
# 258 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Would you like to fish here?$"

HauoliOustkirtsFishingSpot1_Text_1:
# 267 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You don't have a Fishing Rod.$"

HauoliOustkirtsFishingSpot1_Text_2:
# 277 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You can't fish while riding a Sharpedo!$"
