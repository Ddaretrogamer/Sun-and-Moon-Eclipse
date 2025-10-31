DaycareMountain_MapScripts::
# 2 "data/maps/DaycareMountain/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareMountain_OnTransition
	.byte 0


DaycareMountain_OnTransition::
# 6 "data/maps/DaycareMountain/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_MOUNTAIN
	end


SoarFront::
# 11 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_eq SoarFront_1
# 19 "data/maps/DaycareMountain/scripts.pory"
	goto_if_set FLAG_TRANS_NOIVERN, SoarFront_4
SoarFront_3:
# 52 "data/maps/DaycareMountain/scripts.pory"
	lock
# 53 "data/maps/DaycareMountain/scripts.pory"
	msgbox SoarFront_Text_1, MSGBOX_DEFAULT
# 54 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 55 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarFront_1:
# 13 "data/maps/DaycareMountain/scripts.pory"
	lock
# 14 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SoarFront_Movement_0
# 15 "data/maps/DaycareMountain/scripts.pory"
	waitmovement LOCALID_PLAYER
# 16 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarFront_2:
# 21 "data/maps/DaycareMountain/scripts.pory"
	lock
# 22 "data/maps/DaycareMountain/scripts.pory"
	checkpartymove MOVE_SUPER_FANG
# 23 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne SoarFront_8
# 43 "data/maps/DaycareMountain/scripts.pory"
	lock
# 44 "data/maps/DaycareMountain/scripts.pory"
	msgbox SoarFront_Text_1, MSGBOX_DEFAULT
# 45 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 46 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarFront_4:
# 19 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_ne SoarFront_2
	goto SoarFront_3

SoarFront_8:
# 25 "data/maps/DaycareMountain/scripts.pory"
	msgbox SoarFront_Text_0, MSGBOX_YESNO
# 26 "data/maps/DaycareMountain/scripts.pory"
	release
# 27 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SoarFront_11
# 37 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarFront_11:
# 29 "data/maps/DaycareMountain/scripts.pory"
	dittotransform SPECIES_NOIVERN
# 30 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SoarFront_Movement_0
# 31 "data/maps/DaycareMountain/scripts.pory"
	waitmovement LOCALID_PLAYER
# 32 "data/maps/DaycareMountain/scripts.pory"
	release
	end


SoarBack::
# 61 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_eq SoarBack_1
# 69 "data/maps/DaycareMountain/scripts.pory"
	goto_if_set FLAG_TRANS_NOIVERN, SoarBack_4
SoarBack_3:
# 101 "data/maps/DaycareMountain/scripts.pory"
	lock
# 102 "data/maps/DaycareMountain/scripts.pory"
	msgbox SoarFront_Text_1, MSGBOX_DEFAULT
# 103 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 104 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarBack_1:
# 63 "data/maps/DaycareMountain/scripts.pory"
	lock
# 64 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SoarBack_Movement_0
# 65 "data/maps/DaycareMountain/scripts.pory"
	waitmovement LOCALID_PLAYER
# 66 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarBack_2:
# 71 "data/maps/DaycareMountain/scripts.pory"
	lock
# 72 "data/maps/DaycareMountain/scripts.pory"
	checkpartymove MOVE_SUPER_FANG
# 73 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne SoarBack_8
# 93 "data/maps/DaycareMountain/scripts.pory"
	lock
# 94 "data/maps/DaycareMountain/scripts.pory"
	msgbox SoarFront_Text_1, MSGBOX_DEFAULT
# 95 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 96 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarBack_4:
# 69 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_ne SoarBack_2
	goto SoarBack_3

SoarBack_8:
# 75 "data/maps/DaycareMountain/scripts.pory"
	msgbox SoarFront_Text_0, MSGBOX_YESNO
# 76 "data/maps/DaycareMountain/scripts.pory"
	release
# 77 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SoarBack_11
# 87 "data/maps/DaycareMountain/scripts.pory"
	release
	end

SoarBack_11:
# 79 "data/maps/DaycareMountain/scripts.pory"
	dittotransform SPECIES_NOIVERN
# 80 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SoarBack_Movement_0
# 81 "data/maps/DaycareMountain/scripts.pory"
	waitmovement LOCALID_PLAYER
# 82 "data/maps/DaycareMountain/scripts.pory"
	release
	end


VullabyDialog::
# 111 "data/maps/DaycareMountain/scripts.pory"
	goto_if_unset FLAG_SOAR_ACROSS, VullabyDialog_1
# 124 "data/maps/DaycareMountain/scripts.pory"
	lock
# 125 "data/maps/DaycareMountain/scripts.pory"
	applymovement Vullaby, VullabyDialog_Movement_0
# 126 "data/maps/DaycareMountain/scripts.pory"
	speakername VullabyDialog_Text_0
# 127 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_VULLABY, EMOTE_NORMAL
# 128 "data/maps/DaycareMountain/scripts.pory"
	msgbox VullabyDialog_Text_2, MSGBOX_DEFAULT
# 129 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 130 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 131 "data/maps/DaycareMountain/scripts.pory"
	release
	end

VullabyDialog_1:
# 113 "data/maps/DaycareMountain/scripts.pory"
	lock
# 114 "data/maps/DaycareMountain/scripts.pory"
	applymovement Vullaby, VullabyDialog_Movement_0
# 115 "data/maps/DaycareMountain/scripts.pory"
	speakername VullabyDialog_Text_0
# 116 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_VULLABY, EMOTE_NORMAL
# 117 "data/maps/DaycareMountain/scripts.pory"
	msgbox VullabyDialog_Text_1, MSGBOX_DEFAULT
# 118 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 119 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 120 "data/maps/DaycareMountain/scripts.pory"
	release
	end


NoibatDialog::
# 138 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_eq NoibatDialog_1
# 156 "data/maps/DaycareMountain/scripts.pory"
	lock
# 157 "data/maps/DaycareMountain/scripts.pory"
	faceplayer
# 158 "data/maps/DaycareMountain/scripts.pory"
	speakername NoibatDialog_Text_0
# 159 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_NOIBAT, EMOTE_NORMAL
# 160 "data/maps/DaycareMountain/scripts.pory"
	msgbox NoibatDialog_Text_3, MSGBOX_DEFAULT
# 161 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 162 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 163 "data/maps/DaycareMountain/scripts.pory"
	release
	end

NoibatDialog_1:
# 140 "data/maps/DaycareMountain/scripts.pory"
	lock
# 141 "data/maps/DaycareMountain/scripts.pory"
	faceplayer
# 142 "data/maps/DaycareMountain/scripts.pory"
	speakername NoibatDialog_Text_0
# 143 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_NOIBAT, EMOTE_HAPPY
# 144 "data/maps/DaycareMountain/scripts.pory"
	msgbox NoibatDialog_Text_1, MSGBOX_DEFAULT
# 145 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 146 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 147 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_NOIBAT, EMOTE_NORMAL
# 148 "data/maps/DaycareMountain/scripts.pory"
	msgbox NoibatDialog_Text_2, MSGBOX_DEFAULT
# 149 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 150 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 151 "data/maps/DaycareMountain/scripts.pory"
	release
	end


BattleVsLurantis::
# 169 "data/maps/DaycareMountain/scripts.pory"
	lock
# 171 "data/maps/DaycareMountain/scripts.pory"
	goto_if_set FLAG_TRANS_LURANTIS, BattleVsLurantis_2
# 180 "data/maps/DaycareMountain/scripts.pory"
	playbgm MUS_PMD_BOSS_INTRO, FALSE
# 181 "data/maps/DaycareMountain/scripts.pory"
	applymovement Lurantis, VullabyDialog_Movement_0
# 182 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Lurantis
# 183 "data/maps/DaycareMountain/scripts.pory"
	playse SE_PIN
# 184 "data/maps/DaycareMountain/scripts.pory"
	applymovement Lurantis, Common_Movement_ExclamationMark
# 185 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Lurantis
# 186 "data/maps/DaycareMountain/scripts.pory"
	speakername BattleVsLurantis_Text_0
# 187 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_LURANTIS, EMOTE_NORMAL
# 188 "data/maps/DaycareMountain/scripts.pory"
	msgbox BattleVsLurantis_Text_2, MSGBOX_AUTOCLOSE
# 189 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 190 "data/maps/DaycareMountain/scripts.pory"
	setwildbattle SPECIES_LURANTIS, 25, item = ITEM_OCCA_BERRY, move1 = MOVE_LEAF_BLADE, move2 = MOVE_LEECH_LIFE, move3 = MOVE_BRICK_BREAK, move4 = MOVE_SWORDS_DANCE
# 191 "data/maps/DaycareMountain/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 1, 1, 1, 1, 1, 0
# 192 "data/maps/DaycareMountain/scripts.pory"
	dowildbattle
# 193 "data/maps/DaycareMountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 194 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsLurantis_4
	return

BattleVsLurantis_2:
# 173 "data/maps/DaycareMountain/scripts.pory"
	faceplayer
# 174 "data/maps/DaycareMountain/scripts.pory"
	speakername BattleVsLurantis_Text_0
# 175 "data/maps/DaycareMountain/scripts.pory"
	msgbox BattleVsLurantis_Text_1, MSGBOX_DEFAULT
# 176 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 177 "data/maps/DaycareMountain/scripts.pory"
	release
	end

BattleVsLurantis_4:
# 196 "data/maps/DaycareMountain/scripts.pory"
	lock
# 197 "data/maps/DaycareMountain/scripts.pory"
	applymovement Lurantis, Common_Movement_ExclamationMark
# 198 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Lurantis
# 199 "data/maps/DaycareMountain/scripts.pory"
	playse SE_PIN
# 200 "data/maps/DaycareMountain/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 201 "data/maps/DaycareMountain/scripts.pory"
	lock
# 202 "data/maps/DaycareMountain/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 203 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_TRANS_LURANTIS
# 204 "data/maps/DaycareMountain/scripts.pory"
	delay 30
# 205 "data/maps/DaycareMountain/scripts.pory"
	dittotransform SPECIES_LURANTIS
# 206 "data/maps/DaycareMountain/scripts.pory"
	playse MUS_LEVEL_UP
# 207 "data/maps/DaycareMountain/scripts.pory"
	msgbox BattleVsLurantis_Text_3, MSGBOX_DEFAULT
# 208 "data/maps/DaycareMountain/scripts.pory"
	waitse
# 209 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 210 "data/maps/DaycareMountain/scripts.pory"
	lock
# 211 "data/maps/DaycareMountain/scripts.pory"
	dittotransform VAR_TEMP_0
# 212 "data/maps/DaycareMountain/scripts.pory"
	givemon SPECIES_LURANTIS, 25, move1 = MOVE_AERIAL_ACE, move2 = MOVE_BUG_BITE, move3 = MOVE_TRAILBLAZE, move4 = MOVE_CUT
# 213 "data/maps/DaycareMountain/scripts.pory"
	speakername BattleVsLurantis_Text_0
# 214 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_LURANTIS, EMOTE_HAPPY
# 215 "data/maps/DaycareMountain/scripts.pory"
	msgbox BattleVsLurantis_Text_4, MSGBOX_DEFAULT
# 216 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 217 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 218 "data/maps/DaycareMountain/scripts.pory"
	fadenewbgm MUS_PMD_MOUNTAIN
# 219 "data/maps/DaycareMountain/scripts.pory"
	release
	end


OmanyteInCave::
# 225 "data/maps/DaycareMountain/scripts.pory"
	lock
# 227 "data/maps/DaycareMountain/scripts.pory"
	goto_if_set FLAG_OMANYTE_BATTLE, OmanyteInCave_1
# 240 "data/maps/DaycareMountain/scripts.pory"
	applymovement Omanyte, VullabyDialog_Movement_0
# 241 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Omanyte
# 242 "data/maps/DaycareMountain/scripts.pory"
	special PlayTrainerEncounterMusic
# 243 "data/maps/DaycareMountain/scripts.pory"
	applymovement Omanyte, Common_Movement_ExclamationMark
# 244 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Omanyte
# 245 "data/maps/DaycareMountain/scripts.pory"
	delay 60
# 246 "data/maps/DaycareMountain/scripts.pory"
	speakername OmanyteInCave_Text_0
# 247 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_OMANYTE, EMOTE_NORMAL
# 248 "data/maps/DaycareMountain/scripts.pory"
	msgbox OmanyteInCave_Text_2, MSGBOX_AUTOCLOSE
# 249 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 250 "data/maps/DaycareMountain/scripts.pory"
	setwildbattle SPECIES_OMANYTE, 25
# 251 "data/maps/DaycareMountain/scripts.pory"
	dowildbattle
# 252 "data/maps/DaycareMountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 253 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq OmanyteInCave_4
	return

OmanyteInCave_1:
# 229 "data/maps/DaycareMountain/scripts.pory"
	faceplayer
# 230 "data/maps/DaycareMountain/scripts.pory"
	speakername OmanyteInCave_Text_0
# 231 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_OMANYTE, EMOTE_NORMAL
# 232 "data/maps/DaycareMountain/scripts.pory"
	msgbox OmanyteInCave_Text_1, MSGBOX_DEFAULT
# 233 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 234 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 235 "data/maps/DaycareMountain/scripts.pory"
	release
	end

OmanyteInCave_4:
# 255 "data/maps/DaycareMountain/scripts.pory"
	speakername OmanyteInCave_Text_0
# 256 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_OMANYTE, EMOTE_NORMAL
# 257 "data/maps/DaycareMountain/scripts.pory"
	msgbox OmanyteInCave_Text_1, MSGBOX_DEFAULT
# 258 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_OMANYTE_BATTLE
# 259 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 260 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 261 "data/maps/DaycareMountain/scripts.pory"
	release
	end


OmanyteInCaveTrigger::
# 268 "data/maps/DaycareMountain/scripts.pory"
	goto_if_unset FLAG_OMANYTE_BATTLE, OmanyteInCaveTrigger_1
	return

OmanyteInCaveTrigger_1:
# 270 "data/maps/DaycareMountain/scripts.pory"
	special PlayTrainerEncounterMusic
# 271 "data/maps/DaycareMountain/scripts.pory"
	applymovement Omanyte, Common_Movement_ExclamationMark
# 272 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Omanyte
# 273 "data/maps/DaycareMountain/scripts.pory"
	delay 60
# 274 "data/maps/DaycareMountain/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 275 "data/maps/DaycareMountain/scripts.pory"
	switch VAR_TEMP_2
# 277 "data/maps/DaycareMountain/scripts.pory"
	case 34, OmanyteInCaveTrigger_4
# 299 "data/maps/DaycareMountain/scripts.pory"
	case 33, OmanyteInCaveTrigger_5
	return

OmanyteInCaveTrigger_4:
# 278 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, OmanyteInCaveTrigger_Movement_0
# 279 "data/maps/DaycareMountain/scripts.pory"
	applymovement Omanyte, OmanyteInCaveTrigger_Movement_1
# 280 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Omanyte
# 281 "data/maps/DaycareMountain/scripts.pory"
	speakername OmanyteInCave_Text_0
# 282 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_OMANYTE, EMOTE_NORMAL
# 283 "data/maps/DaycareMountain/scripts.pory"
	msgbox OmanyteInCave_Text_2, MSGBOX_AUTOCLOSE
# 284 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 285 "data/maps/DaycareMountain/scripts.pory"
	setwildbattle SPECIES_OMANYTE, 25
# 286 "data/maps/DaycareMountain/scripts.pory"
	dowildbattle
# 287 "data/maps/DaycareMountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 288 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq OmanyteInCaveTrigger_6
	return

OmanyteInCaveTrigger_5:
# 300 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, OmanyteInCaveTrigger_Movement_0
# 301 "data/maps/DaycareMountain/scripts.pory"
	speakername OmanyteInCave_Text_0
# 302 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_OMANYTE, EMOTE_NORMAL
# 303 "data/maps/DaycareMountain/scripts.pory"
	msgbox OmanyteInCave_Text_2, MSGBOX_AUTOCLOSE
# 304 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 305 "data/maps/DaycareMountain/scripts.pory"
	setwildbattle SPECIES_OMANYTE, 25
# 306 "data/maps/DaycareMountain/scripts.pory"
	dowildbattle
# 307 "data/maps/DaycareMountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 308 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq OmanyteInCaveTrigger_8
	return

OmanyteInCaveTrigger_6:
# 290 "data/maps/DaycareMountain/scripts.pory"
	speakername OmanyteInCave_Text_0
# 291 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_OMANYTE, EMOTE_NORMAL
# 292 "data/maps/DaycareMountain/scripts.pory"
	msgbox OmanyteInCave_Text_1, MSGBOX_DEFAULT
# 293 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_OMANYTE_BATTLE
# 294 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 295 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 296 "data/maps/DaycareMountain/scripts.pory"
	release
	end

OmanyteInCaveTrigger_8:
# 310 "data/maps/DaycareMountain/scripts.pory"
	speakername OmanyteInCave_Text_0
# 311 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_OMANYTE, EMOTE_NORMAL
# 312 "data/maps/DaycareMountain/scripts.pory"
	msgbox OmanyteInCave_Text_1, MSGBOX_DEFAULT
# 313 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_OMANYTE_BATTLE
# 314 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 315 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 316 "data/maps/DaycareMountain/scripts.pory"
	release
	end


KabutoInCave::
# 324 "data/maps/DaycareMountain/scripts.pory"
	lock
# 326 "data/maps/DaycareMountain/scripts.pory"
	goto_if_set FLAG_KABUTO_BATTLE, KabutoInCave_1
# 339 "data/maps/DaycareMountain/scripts.pory"
	applymovement Kabuto, VullabyDialog_Movement_0
# 340 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Kabuto
# 341 "data/maps/DaycareMountain/scripts.pory"
	special PlayTrainerEncounterMusic
# 342 "data/maps/DaycareMountain/scripts.pory"
	applymovement Kabuto, Common_Movement_ExclamationMark
# 343 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Kabuto
# 344 "data/maps/DaycareMountain/scripts.pory"
	delay 60
# 345 "data/maps/DaycareMountain/scripts.pory"
	speakername KabutoInCave_Text_0
# 346 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_KABUTO, EMOTE_NORMAL
# 347 "data/maps/DaycareMountain/scripts.pory"
	msgbox KabutoInCave_Text_2, MSGBOX_AUTOCLOSE
# 348 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 349 "data/maps/DaycareMountain/scripts.pory"
	setwildbattle SPECIES_KABUTO, 25
# 350 "data/maps/DaycareMountain/scripts.pory"
	dowildbattle
# 351 "data/maps/DaycareMountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 352 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq KabutoInCave_4
	return

KabutoInCave_1:
# 328 "data/maps/DaycareMountain/scripts.pory"
	faceplayer
# 329 "data/maps/DaycareMountain/scripts.pory"
	speakername KabutoInCave_Text_0
# 330 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_KABUTO, EMOTE_NORMAL
# 331 "data/maps/DaycareMountain/scripts.pory"
	msgbox KabutoInCave_Text_1, MSGBOX_DEFAULT
# 332 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 333 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 334 "data/maps/DaycareMountain/scripts.pory"
	release
	end

KabutoInCave_4:
# 354 "data/maps/DaycareMountain/scripts.pory"
	speakername KabutoInCave_Text_0
# 355 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_KABUTO, EMOTE_NORMAL
# 356 "data/maps/DaycareMountain/scripts.pory"
	msgbox KabutoInCave_Text_3, MSGBOX_DEFAULT
# 357 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_KABUTO_BATTLE
# 358 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 359 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 360 "data/maps/DaycareMountain/scripts.pory"
	release
	end


KabutoInCaveTrigger::
# 368 "data/maps/DaycareMountain/scripts.pory"
	goto_if_unset FLAG_KABUTO_BATTLE, KabutoInCaveTrigger_1
	return

KabutoInCaveTrigger_1:
# 370 "data/maps/DaycareMountain/scripts.pory"
	special PlayTrainerEncounterMusic
# 371 "data/maps/DaycareMountain/scripts.pory"
	applymovement Kabuto, Common_Movement_ExclamationMark
# 372 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Kabuto
# 373 "data/maps/DaycareMountain/scripts.pory"
	delay 60
# 374 "data/maps/DaycareMountain/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 375 "data/maps/DaycareMountain/scripts.pory"
	switch VAR_TEMP_1
# 377 "data/maps/DaycareMountain/scripts.pory"
	case 8, KabutoInCaveTrigger_4
# 397 "data/maps/DaycareMountain/scripts.pory"
	case 9, KabutoInCaveTrigger_5
	return

KabutoInCaveTrigger_4:
# 378 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, KabutoInCaveTrigger_Movement_0
# 379 "data/maps/DaycareMountain/scripts.pory"
	speakername KabutoInCave_Text_0
# 380 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_KABUTO, EMOTE_NORMAL
# 381 "data/maps/DaycareMountain/scripts.pory"
	msgbox KabutoInCave_Text_2, MSGBOX_AUTOCLOSE
# 382 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 383 "data/maps/DaycareMountain/scripts.pory"
	setwildbattle SPECIES_KABUTO, 25
# 384 "data/maps/DaycareMountain/scripts.pory"
	dowildbattle
# 385 "data/maps/DaycareMountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 386 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq KabutoInCaveTrigger_6
	return

KabutoInCaveTrigger_5:
# 398 "data/maps/DaycareMountain/scripts.pory"
	applymovement LOCALID_PLAYER, KabutoInCaveTrigger_Movement_0
# 399 "data/maps/DaycareMountain/scripts.pory"
	applymovement Kabuto, KabutoInCaveTrigger_Movement_1
# 400 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Kabuto
# 401 "data/maps/DaycareMountain/scripts.pory"
	speakername KabutoInCave_Text_0
# 402 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_KABUTO, EMOTE_NORMAL
# 403 "data/maps/DaycareMountain/scripts.pory"
	msgbox KabutoInCave_Text_2, MSGBOX_AUTOCLOSE
# 404 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 405 "data/maps/DaycareMountain/scripts.pory"
	setwildbattle SPECIES_KABUTO, 25
# 406 "data/maps/DaycareMountain/scripts.pory"
	dowildbattle
# 407 "data/maps/DaycareMountain/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 408 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq KabutoInCaveTrigger_8
	return

KabutoInCaveTrigger_6:
# 388 "data/maps/DaycareMountain/scripts.pory"
	speakername KabutoInCave_Text_0
# 389 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_KABUTO, EMOTE_NORMAL
# 390 "data/maps/DaycareMountain/scripts.pory"
	msgbox KabutoInCave_Text_3, MSGBOX_DEFAULT
# 391 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_KABUTO_BATTLE
# 392 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 393 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 394 "data/maps/DaycareMountain/scripts.pory"
	release
	end

KabutoInCaveTrigger_8:
# 410 "data/maps/DaycareMountain/scripts.pory"
	speakername KabutoInCave_Text_0
# 411 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_KABUTO, EMOTE_NORMAL
# 412 "data/maps/DaycareMountain/scripts.pory"
	msgbox KabutoInCave_Text_3, MSGBOX_DEFAULT
# 413 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_KABUTO_BATTLE
# 414 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 415 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 416 "data/maps/DaycareMountain/scripts.pory"
	release
	end


VullabyAfterSoar::
# 424 "data/maps/DaycareMountain/scripts.pory"
	goto_if_unset FLAG_SOAR_ACROSS, VullabyAfterSoar_1
	end

VullabyAfterSoar_1:
# 426 "data/maps/DaycareMountain/scripts.pory"
	lock
# 427 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_SHOW_NOICE
# 428 "data/maps/DaycareMountain/scripts.pory"
	special SpawnCameraObject
# 429 "data/maps/DaycareMountain/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, VullabyAfterSoar_Movement_0
# 430 "data/maps/DaycareMountain/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 431 "data/maps/DaycareMountain/scripts.pory"
	delay 30
# 432 "data/maps/DaycareMountain/scripts.pory"
	applymovement Vullaby, OmanyteInCaveTrigger_Movement_0
# 433 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Vullaby
# 434 "data/maps/DaycareMountain/scripts.pory"
	playse SE_PIN
# 435 "data/maps/DaycareMountain/scripts.pory"
	applymovement Vullaby, Common_Movement_ExclamationMark
# 436 "data/maps/DaycareMountain/scripts.pory"
	waitmovement Vullaby
# 437 "data/maps/DaycareMountain/scripts.pory"
	speakername VullabyDialog_Text_0
# 438 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_VULLABY, EMOTE_HAPPY
# 439 "data/maps/DaycareMountain/scripts.pory"
	msgbox VullabyAfterSoar_Text_0, MSGBOX_AUTOCLOSE
# 440 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 441 "data/maps/DaycareMountain/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, VullabyAfterSoar_Movement_1
# 442 "data/maps/DaycareMountain/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 443 "data/maps/DaycareMountain/scripts.pory"
	special RemoveCameraObject
# 444 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_SOAR_ACROSS
# 445 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 446 "data/maps/DaycareMountain/scripts.pory"
	release
	end


ChanseyDaycareMountainHeal::
# 456 "data/maps/DaycareMountain/scripts.pory"
	lock
# 457 "data/maps/DaycareMountain/scripts.pory"
	faceplayer
# 458 "data/maps/DaycareMountain/scripts.pory"
	speakername ChanseyDaycareMountainHeal_Text_0
# 459 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 460 "data/maps/DaycareMountain/scripts.pory"
	msgbox ChanseyDaycareMountainHeal_Text_1, MSGBOX_DEFAULT
# 461 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 462 "data/maps/DaycareMountain/scripts.pory"
	msgbox ChanseyDaycareMountainHeal_Text_2, MSGBOX_YESNO
# 463 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 464 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycareMountainHeal_1
# 494 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 495 "data/maps/DaycareMountain/scripts.pory"
	msgbox ChanseyDaycareMountainHeal_Text_5, MSGBOX_AUTOCLOSE
# 496 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 497 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 498 "data/maps/DaycareMountain/scripts.pory"
	release
	end

ChanseyDaycareMountainHeal_1:
# 466 "data/maps/DaycareMountain/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 467 "data/maps/DaycareMountain/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycareMountainHeal_4
# 484 "data/maps/DaycareMountain/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 485 "data/maps/DaycareMountain/scripts.pory"
	msgbox ChanseyDaycareMountainHeal_Text_4, MSGBOX_AUTOCLOSE
# 486 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 487 "data/maps/DaycareMountain/scripts.pory"
	removefieldmugshot
# 488 "data/maps/DaycareMountain/scripts.pory"
	release
	end

ChanseyDaycareMountainHeal_4:
# 469 "data/maps/DaycareMountain/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 470 "data/maps/DaycareMountain/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 471 "data/maps/DaycareMountain/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 472 "data/maps/DaycareMountain/scripts.pory"
	playfanfare MUS_HEAL
# 473 "data/maps/DaycareMountain/scripts.pory"
	waitfanfare
# 474 "data/maps/DaycareMountain/scripts.pory"
	special HealPlayerParty
# 475 "data/maps/DaycareMountain/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 476 "data/maps/DaycareMountain/scripts.pory"
	msgbox ChanseyDaycareMountainHeal_Text_3, MSGBOX_AUTOCLOSE
# 477 "data/maps/DaycareMountain/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 478 "data/maps/DaycareMountain/scripts.pory"
	waitmessage
# 479 "data/maps/DaycareMountain/scripts.pory"
	release
	end


# 14 "data/maps/DaycareMountain/scripts.pory"
SoarFront_Movement_0:
# 14 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 14 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 14 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 14 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
	step_end

# 64 "data/maps/DaycareMountain/scripts.pory"
SoarBack_Movement_0:
# 64 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 64 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 64 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 64 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
	step_end

# 114 "data/maps/DaycareMountain/scripts.pory"
VullabyDialog_Movement_0:
# 114 "data/maps/DaycareMountain/scripts.pory"
	face_player
	step_end

# 278 "data/maps/DaycareMountain/scripts.pory"
OmanyteInCaveTrigger_Movement_0:
# 278 "data/maps/DaycareMountain/scripts.pory"
	face_up
	step_end

# 279 "data/maps/DaycareMountain/scripts.pory"
OmanyteInCaveTrigger_Movement_1:
# 279 "data/maps/DaycareMountain/scripts.pory"
	walk_down
	step_end

# 378 "data/maps/DaycareMountain/scripts.pory"
KabutoInCaveTrigger_Movement_0:
# 378 "data/maps/DaycareMountain/scripts.pory"
	face_left
	step_end

# 399 "data/maps/DaycareMountain/scripts.pory"
KabutoInCaveTrigger_Movement_1:
# 399 "data/maps/DaycareMountain/scripts.pory"
	walk_right
	step_end

# 429 "data/maps/DaycareMountain/scripts.pory"
VullabyAfterSoar_Movement_0:
# 429 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 429 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 429 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 429 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 429 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
# 429 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_down
	step_end

# 441 "data/maps/DaycareMountain/scripts.pory"
VullabyAfterSoar_Movement_1:
# 441 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 441 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 441 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 441 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 441 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
# 441 "data/maps/DaycareMountain/scripts.pory"
	walk_fast_up
	step_end

SoarFront_Text_0:
# 25 "data/maps/DaycareMountain/scripts.pory"
	.string "The bridge seems to be broken.\pWould you like to transform into\nNoivern to soar across?$"

SoarFront_Text_1:
# 44 "data/maps/DaycareMountain/scripts.pory"
	.string "The bridge seems to be broken.\pMaybe a Flying Pokémon could soar\nover the gap.$"

VullabyDialog_Text_0:
# 115 "data/maps/DaycareMountain/scripts.pory"
	.string "Vullaby$"

VullabyDialog_Text_1:
# 117 "data/maps/DaycareMountain/scripts.pory"
	.string "I wish I had stronger wings...\pThen I'd just fly right over the\nbroken bridge!$"

VullabyDialog_Text_2:
# 128 "data/maps/DaycareMountain/scripts.pory"
	.string "I wish I could transform like you.\pI would change into a giant eagle!\n$"

NoibatDialog_Text_0:
# 142 "data/maps/DaycareMountain/scripts.pory"
	.string "Noibat$"

NoibatDialog_Text_1:
# 144 "data/maps/DaycareMountain/scripts.pory"
	.string "Big brother!$"

NoibatDialog_Text_2:
# 148 "data/maps/DaycareMountain/scripts.pory"
	.string "Oh, no. It's just another Ditto...\pThere's a cave up ahead.\pYou'll need my big bro's power\nto beat the Pokémon waiting deep\lwithin.$"

NoibatDialog_Text_3:
# 160 "data/maps/DaycareMountain/scripts.pory"
	.string "There's a cave up ahead.\pYou'll need my big bro's power\nto beat the Pokémon waiting deep\lwithin.$"

BattleVsLurantis_Text_0:
# 174 "data/maps/DaycareMountain/scripts.pory"
	.string "Lurantis$"

BattleVsLurantis_Text_1:
# 175 "data/maps/DaycareMountain/scripts.pory"
	.string "Haven't seen any small trees\naround?\pThey tend to grow on the top of\ncliffs with crashing waterfalls.$"

BattleVsLurantis_Text_2:
# 188 "data/maps/DaycareMountain/scripts.pory"
	.string "You're out seeking your Egg...\nare you not?\pEvery Ditto comes here in search\nof the Mythical Egg.\pProve your strength to me.\nMy sharp raptorial arms may come\lin handy.$"

BattleVsLurantis_Text_3:
# 207 "data/maps/DaycareMountain/scripts.pory"
	.string "You have gained the ability to\ntransform into Lurantis!$"

BattleVsLurantis_Text_4:
# 215 "data/maps/DaycareMountain/scripts.pory"
	.string "You are a sharp one!\pUse my abilities to your\nadvantage.\pThe journey ahead is no walk in the\ndaycare.$"

OmanyteInCave_Text_0:
# 230 "data/maps/DaycareMountain/scripts.pory"
	.string "Omanyte$"

OmanyteInCave_Text_1:
# 232 "data/maps/DaycareMountain/scripts.pory"
	.string "Fine.\nYou've earned your stay.$"

OmanyteInCave_Text_2:
# 248 "data/maps/DaycareMountain/scripts.pory"
	.string "You're no fossil!\n$"

KabutoInCave_Text_0:
# 329 "data/maps/DaycareMountain/scripts.pory"
	.string "Kabuto$"

KabutoInCave_Text_1:
# 331 "data/maps/DaycareMountain/scripts.pory"
	.string "It was only the two of us\nanyways...$"

KabutoInCave_Text_2:
# 347 "data/maps/DaycareMountain/scripts.pory"
	.string "Fossils only!\n$"

KabutoInCave_Text_3:
# 356 "data/maps/DaycareMountain/scripts.pory"
	.string "Alright.\nWe can make an exception.$"

VullabyAfterSoar_Text_0:
# 439 "data/maps/DaycareMountain/scripts.pory"
	.string "Wow!\pYou made it across!\pTransforming into Noivern was\nclever!$"

ChanseyDaycareMountainHeal_Text_0:
# 458 "data/maps/DaycareMountain/scripts.pory"
	.string "Chansey$"

ChanseyDaycareMountainHeal_Text_1:
# 460 "data/maps/DaycareMountain/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycareMountainHeal_Text_2:
# 462 "data/maps/DaycareMountain/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycareMountainHeal_Text_3:
# 476 "data/maps/DaycareMountain/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycareMountainHeal_Text_4:
# 485 "data/maps/DaycareMountain/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycareMountainHeal_Text_5:
# 495 "data/maps/DaycareMountain/scripts.pory"
	.string "Oh, okay then.$"
