DaycarePond_MapScripts::
# 2 "data/maps/DaycarePond/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycarePond_OnTransition
	.byte 0


DaycarePond_OnTransition::
# 6 "data/maps/DaycarePond/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_POND
	end


BattleVsMarill::
# 10 "data/maps/DaycarePond/scripts.pory"
	lock
# 12 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_TRANS_MARILL, BattleVsMarill_2
# 23 "data/maps/DaycarePond/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 24 "data/maps/DaycarePond/scripts.pory"
	applymovement Marill, BattleVsMarill_Movement_0
# 25 "data/maps/DaycarePond/scripts.pory"
	waitmovement Marill
# 26 "data/maps/DaycarePond/scripts.pory"
	playse SE_PIN
# 27 "data/maps/DaycarePond/scripts.pory"
	applymovement Marill, Common_Movement_ExclamationMark
# 28 "data/maps/DaycarePond/scripts.pory"
	waitmovement Marill
# 29 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_MARILL, EMOTE_NORMAL
# 30 "data/maps/DaycarePond/scripts.pory"
	speakername BattleVsMarill_Text_0
# 31 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsMarill_Text_2, MSGBOX_AUTOCLOSE
# 32 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 33 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_MARILL, 25, move1 = MOVE_SURF, move2 = MOVE_AQUA_JET, move3 = MOVE_COVET, move4 = MOVE_WATER_PULSE, ability = 2
# 34 "data/maps/DaycarePond/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 2, 0, 0
# 35 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 36 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 37 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsMarill_4
	return

BattleVsMarill_2:
# 14 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 15 "data/maps/DaycarePond/scripts.pory"
	speakername BattleVsMarill_Text_0
# 16 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_MARILL, EMOTE_NORMAL
# 17 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsMarill_Text_1, MSGBOX_DEFAULT
# 18 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 19 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 20 "data/maps/DaycarePond/scripts.pory"
	release
	end

BattleVsMarill_4:
# 39 "data/maps/DaycarePond/scripts.pory"
	lock
# 40 "data/maps/DaycarePond/scripts.pory"
	applymovement Marill, Common_Movement_ExclamationMark
# 41 "data/maps/DaycarePond/scripts.pory"
	waitmovement Marill
# 42 "data/maps/DaycarePond/scripts.pory"
	lock
# 43 "data/maps/DaycarePond/scripts.pory"
	playse SE_PIN
# 44 "data/maps/DaycarePond/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 45 "data/maps/DaycarePond/scripts.pory"
	lock
# 46 "data/maps/DaycarePond/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 47 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_TRANS_MARILL
# 48 "data/maps/DaycarePond/scripts.pory"
	lock
# 49 "data/maps/DaycarePond/scripts.pory"
	dittotransform SPECIES_MARILL
# 50 "data/maps/DaycarePond/scripts.pory"
	playse MUS_LEVEL_UP
# 51 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsMarill_Text_3, MSGBOX_DEFAULT
# 52 "data/maps/DaycarePond/scripts.pory"
	waitse
# 53 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 54 "data/maps/DaycarePond/scripts.pory"
	lock
# 55 "data/maps/DaycarePond/scripts.pory"
	dittotransform VAR_TEMP_0
# 56 "data/maps/DaycarePond/scripts.pory"
	givemon SPECIES_MARILL, 25, move1 = MOVE_SURF, move2 = MOVE_AQUA_JET, move3 = MOVE_COVET, move4 = MOVE_RAIN_DANCE, abilityNum = 1
# 57 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 58 "data/maps/DaycarePond/scripts.pory"
	speakername BattleVsMarill_Text_0
# 59 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_MARILL, EMOTE_HAPPY
# 60 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsMarill_Text_1, MSGBOX_DEFAULT
# 61 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 62 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 63 "data/maps/DaycarePond/scripts.pory"
	fadenewbgm MUS_PMD_LAKE
# 64 "data/maps/DaycarePond/scripts.pory"
	release
	end


PsyduckDialog::
# 71 "data/maps/DaycarePond/scripts.pory"
	goto_if_unset FLAG_MUDKIP_PICKED_UP, PsyduckDialog_1
# 85 "data/maps/DaycarePond/scripts.pory"
	lock
# 86 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 87 "data/maps/DaycarePond/scripts.pory"
	speakername PsyduckDialog_Text_0
# 88 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_PSYDUCK, EMOTE_NORMAL
# 89 "data/maps/DaycarePond/scripts.pory"
	msgbox PsyduckDialog_Text_2, MSGBOX_NPC
# 90 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 91 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 92 "data/maps/DaycarePond/scripts.pory"
	release
	end

PsyduckDialog_1:
# 73 "data/maps/DaycarePond/scripts.pory"
	lock
# 74 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 75 "data/maps/DaycarePond/scripts.pory"
	speakername PsyduckDialog_Text_0
# 76 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_PSYDUCK, EMOTE_NORMAL
# 77 "data/maps/DaycarePond/scripts.pory"
	msgbox PsyduckDialog_Text_1, MSGBOX_NPC
# 78 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 79 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 80 "data/maps/DaycarePond/scripts.pory"
	release
	end


SprigatitoDialog::
# 99 "data/maps/DaycarePond/scripts.pory"
	goto_if_unset FLAG_SPRIGATITO_EGG, SprigatitoDialog_1
# 132 "data/maps/DaycarePond/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_LURANTIS
	goto_if_eq SprigatitoDialog_7
# 146 "data/maps/DaycarePond/scripts.pory"
	lock
# 147 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 148 "data/maps/DaycarePond/scripts.pory"
	speakername SprigatitoDialog_Text_0
# 149 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SPRIGATITO, EMOTE_NORMAL
# 150 "data/maps/DaycarePond/scripts.pory"
	msgbox SprigatitoDialog_Text_2, MSGBOX_DEFAULT
# 151 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 152 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 153 "data/maps/DaycarePond/scripts.pory"
	release
	end

SprigatitoDialog_1:
# 101 "data/maps/DaycarePond/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_LURANTIS
	goto_if_eq SprigatitoDialog_4
# 119 "data/maps/DaycarePond/scripts.pory"
	lock
# 120 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 121 "data/maps/DaycarePond/scripts.pory"
	speakername SprigatitoDialog_Text_0
# 122 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SPRIGATITO, EMOTE_NORMAL
# 123 "data/maps/DaycarePond/scripts.pory"
	msgbox SprigatitoDialog_Text_2, MSGBOX_DEFAULT
# 124 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 125 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 126 "data/maps/DaycarePond/scripts.pory"
	release
	end

SprigatitoDialog_4:
# 103 "data/maps/DaycarePond/scripts.pory"
	lock
# 104 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 105 "data/maps/DaycarePond/scripts.pory"
	speakername SprigatitoDialog_Text_0
# 106 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SPRIGATITO, EMOTE_ELATED
# 107 "data/maps/DaycarePond/scripts.pory"
	msgbox SprigatitoDialog_Text_1, MSGBOX_DEFAULT
# 108 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 109 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 110 "data/maps/DaycarePond/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 111 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_SPRIGATITO_EGG
# 112 "data/maps/DaycarePond/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 113 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 114 "data/maps/DaycarePond/scripts.pory"
	release
	end

SprigatitoDialog_7:
# 134 "data/maps/DaycarePond/scripts.pory"
	lock
# 135 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 136 "data/maps/DaycarePond/scripts.pory"
	speakername SprigatitoDialog_Text_0
# 137 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SPRIGATITO, EMOTE_ELATED
# 138 "data/maps/DaycarePond/scripts.pory"
	msgbox SprigatitoDialog_Text_3, MSGBOX_DEFAULT
# 139 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 140 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 141 "data/maps/DaycarePond/scripts.pory"
	release
	end


MudkipDialog::
# 161 "data/maps/DaycarePond/scripts.pory"
	lock
# 162 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 163 "data/maps/DaycarePond/scripts.pory"
	speakername MudkipDialog_Text_0
# 164 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_MUDKIP, EMOTE_ANGRY
# 165 "data/maps/DaycarePond/scripts.pory"
	msgbox MudkipDialog_Text_1, MSGBOX_NPC
# 166 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 167 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 168 "data/maps/DaycarePond/scripts.pory"
	release
	end


SeakingDialog::
# 173 "data/maps/DaycarePond/scripts.pory"
	lock
# 174 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 175 "data/maps/DaycarePond/scripts.pory"
	speakername SeakingDialog_Text_0
# 176 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SEAKING, EMOTE_NORMAL
# 177 "data/maps/DaycarePond/scripts.pory"
	msgbox SeakingDialog_Text_1, MSGBOX_NPC
# 178 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 179 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 180 "data/maps/DaycarePond/scripts.pory"
	release
	end


QuagsireDialog::
# 186 "data/maps/DaycarePond/scripts.pory"
	lock
# 187 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 188 "data/maps/DaycarePond/scripts.pory"
	speakername QuagsireDialog_Text_0
# 189 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_QUAGSIRE, EMOTE_HAPPY
# 190 "data/maps/DaycarePond/scripts.pory"
	msgbox QuagsireDialog_Text_1, MSGBOX_NPC
# 191 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 192 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 193 "data/maps/DaycarePond/scripts.pory"
	release
	end


GoomyInCave::
# 198 "data/maps/DaycarePond/scripts.pory"
	lock
# 199 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 200 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_GOOMY_BATTLE, GoomyInCave_1
# 212 "data/maps/DaycarePond/scripts.pory"
	applymovement Goomy, BattleVsMarill_Movement_0
# 213 "data/maps/DaycarePond/scripts.pory"
	waitmovement Goomy
# 214 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 215 "data/maps/DaycarePond/scripts.pory"
	applymovement Goomy, Common_Movement_ExclamationMark
# 216 "data/maps/DaycarePond/scripts.pory"
	waitmovement Goomy
# 217 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 218 "data/maps/DaycarePond/scripts.pory"
	speakername GoomyInCave_Text_0
# 219 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_GOOMY, EMOTE_NORMAL
# 220 "data/maps/DaycarePond/scripts.pory"
	msgbox GoomyInCave_Text_2, MSGBOX_AUTOCLOSE
# 221 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 222 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_GOOMY, 25
# 223 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 224 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 225 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GoomyInCave_4
	return

GoomyInCave_1:
# 202 "data/maps/DaycarePond/scripts.pory"
	speakername GoomyInCave_Text_0
# 203 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_GOOMY, EMOTE_NORMAL
# 204 "data/maps/DaycarePond/scripts.pory"
	msgbox GoomyInCave_Text_1, MSGBOX_DEFAULT
# 205 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 206 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 207 "data/maps/DaycarePond/scripts.pory"
	release
	end

GoomyInCave_4:
# 227 "data/maps/DaycarePond/scripts.pory"
	speakername GoomyInCave_Text_0
# 228 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_GOOMY, EMOTE_NORMAL
# 229 "data/maps/DaycarePond/scripts.pory"
	msgbox GoomyInCave_Text_1, MSGBOX_DEFAULT
# 230 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_GOOMY_BATTLE
# 231 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 232 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 233 "data/maps/DaycarePond/scripts.pory"
	release
	end


GoomyInCaveTrigger::
# 240 "data/maps/DaycarePond/scripts.pory"
	goto_if_unset FLAG_GOOMY_BATTLE, GoomyInCaveTrigger_1
	return

GoomyInCaveTrigger_1:
# 242 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 243 "data/maps/DaycarePond/scripts.pory"
	applymovement Goomy, Common_Movement_ExclamationMark
# 244 "data/maps/DaycarePond/scripts.pory"
	waitmovement Goomy
# 245 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 246 "data/maps/DaycarePond/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 247 "data/maps/DaycarePond/scripts.pory"
	switch VAR_TEMP_1
# 249 "data/maps/DaycarePond/scripts.pory"
	case 17, GoomyInCaveTrigger_4
# 269 "data/maps/DaycarePond/scripts.pory"
	case 16, GoomyInCaveTrigger_5
	return

GoomyInCaveTrigger_4:
# 250 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, GoomyInCaveTrigger_Movement_0
# 251 "data/maps/DaycarePond/scripts.pory"
	speakername GoomyInCave_Text_0
# 252 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_GOOMY, EMOTE_NORMAL
# 253 "data/maps/DaycarePond/scripts.pory"
	msgbox GoomyInCave_Text_2, MSGBOX_AUTOCLOSE
# 254 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 255 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_GOOMY, 25
# 256 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 257 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 258 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GoomyInCaveTrigger_6
	return

GoomyInCaveTrigger_5:
# 270 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, GoomyInCaveTrigger_Movement_0
# 271 "data/maps/DaycarePond/scripts.pory"
	applymovement Goomy, GoomyInCaveTrigger_Movement_1
# 272 "data/maps/DaycarePond/scripts.pory"
	waitmovement Goomy
# 273 "data/maps/DaycarePond/scripts.pory"
	speakername GoomyInCave_Text_0
# 274 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_GOOMY, EMOTE_NORMAL
# 275 "data/maps/DaycarePond/scripts.pory"
	msgbox GoomyInCave_Text_2, MSGBOX_AUTOCLOSE
# 276 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 277 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_GOOMY, 25
# 278 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 279 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 280 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GoomyInCaveTrigger_8
	return

GoomyInCaveTrigger_6:
# 260 "data/maps/DaycarePond/scripts.pory"
	speakername GoomyInCave_Text_0
# 261 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_GOOMY, EMOTE_NORMAL
# 262 "data/maps/DaycarePond/scripts.pory"
	msgbox GoomyInCave_Text_1, MSGBOX_DEFAULT
# 263 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_GOOMY_BATTLE
# 264 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 265 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 266 "data/maps/DaycarePond/scripts.pory"
	release
	end

GoomyInCaveTrigger_8:
# 282 "data/maps/DaycarePond/scripts.pory"
	speakername GoomyInCave_Text_0
# 283 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_GOOMY, EMOTE_NORMAL
# 284 "data/maps/DaycarePond/scripts.pory"
	msgbox GoomyInCave_Text_1, MSGBOX_DEFAULT
# 285 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_GOOMY_BATTLE
# 286 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 287 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 288 "data/maps/DaycarePond/scripts.pory"
	release
	end


BuizelInCave::
# 296 "data/maps/DaycarePond/scripts.pory"
	lock
# 297 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 298 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_TRANS_WEAVILE, BuizelInCave_1
# 341 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 342 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 343 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_4, MSGBOX_DEFAULT
# 344 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 345 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 346 "data/maps/DaycarePond/scripts.pory"
	release
	end

BuizelInCave_1:
# 300 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_BUIZEL_BATTLE, BuizelInCave_4
# 312 "data/maps/DaycarePond/scripts.pory"
	applymovement Buizel, BattleVsMarill_Movement_0
# 313 "data/maps/DaycarePond/scripts.pory"
	waitmovement Buizel
# 314 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 315 "data/maps/DaycarePond/scripts.pory"
	applymovement Buizel, Common_Movement_ExclamationMark
# 316 "data/maps/DaycarePond/scripts.pory"
	waitmovement Buizel
# 317 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 318 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 319 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 320 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_2, MSGBOX_AUTOCLOSE
# 321 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 322 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_BUIZEL, 25
# 323 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 324 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 325 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BuizelInCave_7
	return

BuizelInCave_4:
# 302 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 303 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 304 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_1, MSGBOX_DEFAULT
# 305 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 306 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 307 "data/maps/DaycarePond/scripts.pory"
	release
	end

BuizelInCave_7:
# 327 "data/maps/DaycarePond/scripts.pory"
	lock
# 328 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 329 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 330 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_3, MSGBOX_DEFAULT
# 331 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_BUIZEL_BATTLE
# 332 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 333 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 334 "data/maps/DaycarePond/scripts.pory"
	release
	end


BuizelInCaveTrigger::
# 352 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_TRANS_WEAVILE, BuizelInCaveTrigger_1
	end

BuizelInCaveTrigger_1:
# 354 "data/maps/DaycarePond/scripts.pory"
	goto_if_unset FLAG_BUIZEL_BATTLE, BuizelInCaveTrigger_4
	return

BuizelInCaveTrigger_4:
# 356 "data/maps/DaycarePond/scripts.pory"
	lock
# 357 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 358 "data/maps/DaycarePond/scripts.pory"
	applymovement Buizel, Common_Movement_ExclamationMark
# 359 "data/maps/DaycarePond/scripts.pory"
	waitmovement Buizel
# 360 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 361 "data/maps/DaycarePond/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 362 "data/maps/DaycarePond/scripts.pory"
	switch VAR_TEMP_2
# 364 "data/maps/DaycarePond/scripts.pory"
	case 37, BuizelInCaveTrigger_7
# 389 "data/maps/DaycarePond/scripts.pory"
	case 36, BuizelInCaveTrigger_8
	return

BuizelInCaveTrigger_7:
# 365 "data/maps/DaycarePond/scripts.pory"
	applymovement Buizel, BattleVsMarill_Movement_0
# 366 "data/maps/DaycarePond/scripts.pory"
	waitmovement Buizel
# 367 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, BuizelInCaveTrigger_Movement_0
# 368 "data/maps/DaycarePond/scripts.pory"
	applymovement Buizel, BuizelInCaveTrigger_Movement_1
# 369 "data/maps/DaycarePond/scripts.pory"
	waitmovement Buizel
# 370 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 371 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 372 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_2, MSGBOX_AUTOCLOSE
# 373 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 374 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_BUIZEL, 25
# 375 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 376 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 377 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BuizelInCaveTrigger_9
	return

BuizelInCaveTrigger_8:
# 390 "data/maps/DaycarePond/scripts.pory"
	applymovement Buizel, BattleVsMarill_Movement_0
# 391 "data/maps/DaycarePond/scripts.pory"
	waitmovement Buizel
# 392 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, BuizelInCaveTrigger_Movement_0
# 393 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 394 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 395 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_2, MSGBOX_AUTOCLOSE
# 396 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 397 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_BUIZEL, 25
# 398 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 399 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 400 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BuizelInCaveTrigger_11
	return

BuizelInCaveTrigger_9:
# 379 "data/maps/DaycarePond/scripts.pory"
	lock
# 380 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 381 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 382 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_3, MSGBOX_DEFAULT
# 383 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_BUIZEL_BATTLE
# 384 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 385 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 386 "data/maps/DaycarePond/scripts.pory"
	release
	end

BuizelInCaveTrigger_11:
# 402 "data/maps/DaycarePond/scripts.pory"
	lock
# 403 "data/maps/DaycarePond/scripts.pory"
	speakername BuizelInCave_Text_0
# 404 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_BUIZEL, EMOTE_NORMAL
# 405 "data/maps/DaycarePond/scripts.pory"
	msgbox BuizelInCave_Text_3, MSGBOX_DEFAULT
# 406 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_BUIZEL_BATTLE
# 407 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 408 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 409 "data/maps/DaycarePond/scripts.pory"
	release
	end


SlowpokeInCave::
# 422 "data/maps/DaycarePond/scripts.pory"
	lock
# 423 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 424 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_SLOWPOKE_BATTLE, SlowpokeInCave_1
# 436 "data/maps/DaycarePond/scripts.pory"
	applymovement Slowpoke, BattleVsMarill_Movement_0
# 437 "data/maps/DaycarePond/scripts.pory"
	waitmovement Slowpoke
# 438 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 439 "data/maps/DaycarePond/scripts.pory"
	applymovement Slowpoke, Common_Movement_ExclamationMark
# 440 "data/maps/DaycarePond/scripts.pory"
	waitmovement Slowpoke
# 441 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 442 "data/maps/DaycarePond/scripts.pory"
	speakername SlowpokeInCave_Text_0
# 443 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 444 "data/maps/DaycarePond/scripts.pory"
	msgbox SlowpokeInCave_Text_2, MSGBOX_AUTOCLOSE
# 445 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 446 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_SLOWPOKE, 25
# 447 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 448 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 449 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SlowpokeInCave_4
	return

SlowpokeInCave_1:
# 426 "data/maps/DaycarePond/scripts.pory"
	speakername SlowpokeInCave_Text_0
# 427 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 428 "data/maps/DaycarePond/scripts.pory"
	msgbox SlowpokeInCave_Text_1, MSGBOX_DEFAULT
# 429 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 430 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 431 "data/maps/DaycarePond/scripts.pory"
	release
	end

SlowpokeInCave_4:
# 451 "data/maps/DaycarePond/scripts.pory"
	speakername SlowpokeInCave_Text_0
# 452 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 453 "data/maps/DaycarePond/scripts.pory"
	msgbox SlowpokeInCave_Text_3, MSGBOX_DEFAULT
# 454 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_SLOWPOKE_BATTLE
# 455 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 456 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 457 "data/maps/DaycarePond/scripts.pory"
	release
	end


SlowpokeInCaveTrigger::
# 463 "data/maps/DaycarePond/scripts.pory"
	goto_if_unset FLAG_SLOWPOKE_BATTLE, SlowpokeInCaveTrigger_1
	return

SlowpokeInCaveTrigger_1:
# 465 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 466 "data/maps/DaycarePond/scripts.pory"
	applymovement Slowpoke, Common_Movement_ExclamationMark
# 467 "data/maps/DaycarePond/scripts.pory"
	waitmovement Slowpoke
# 468 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 469 "data/maps/DaycarePond/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 470 "data/maps/DaycarePond/scripts.pory"
	switch VAR_TEMP_1
# 472 "data/maps/DaycarePond/scripts.pory"
	case 26, SlowpokeInCaveTrigger_4
# 497 "data/maps/DaycarePond/scripts.pory"
	case 25, SlowpokeInCaveTrigger_5
	return

SlowpokeInCaveTrigger_4:
# 473 "data/maps/DaycarePond/scripts.pory"
	applymovement Slowpoke, BattleVsMarill_Movement_0
# 474 "data/maps/DaycarePond/scripts.pory"
	waitmovement Slowpoke
# 475 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, SlowpokeInCaveTrigger_Movement_0
# 476 "data/maps/DaycarePond/scripts.pory"
	applymovement Slowpoke, SlowpokeInCaveTrigger_Movement_1
# 477 "data/maps/DaycarePond/scripts.pory"
	waitmovement Slowpoke
# 478 "data/maps/DaycarePond/scripts.pory"
	speakername SlowpokeInCave_Text_0
# 479 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 480 "data/maps/DaycarePond/scripts.pory"
	msgbox SlowpokeInCave_Text_2, MSGBOX_AUTOCLOSE
# 481 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 482 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_SLOWPOKE, 25
# 483 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 484 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 485 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SlowpokeInCaveTrigger_6
	return

SlowpokeInCaveTrigger_5:
# 498 "data/maps/DaycarePond/scripts.pory"
	applymovement Slowpoke, BattleVsMarill_Movement_0
# 499 "data/maps/DaycarePond/scripts.pory"
	waitmovement Slowpoke
# 500 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, SlowpokeInCaveTrigger_Movement_0
# 501 "data/maps/DaycarePond/scripts.pory"
	speakername SlowpokeInCave_Text_0
# 502 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 503 "data/maps/DaycarePond/scripts.pory"
	msgbox SlowpokeInCave_Text_2, MSGBOX_AUTOCLOSE
# 504 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 505 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_SLOWPOKE, 25
# 506 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 507 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 508 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SlowpokeInCaveTrigger_8
	return

SlowpokeInCaveTrigger_6:
# 487 "data/maps/DaycarePond/scripts.pory"
	lock
# 488 "data/maps/DaycarePond/scripts.pory"
	speakername SlowpokeInCave_Text_0
# 489 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 490 "data/maps/DaycarePond/scripts.pory"
	msgbox SlowpokeInCave_Text_3, MSGBOX_DEFAULT
# 491 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_SLOWPOKE_BATTLE
# 492 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 493 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 494 "data/maps/DaycarePond/scripts.pory"
	release
	end

SlowpokeInCaveTrigger_8:
# 510 "data/maps/DaycarePond/scripts.pory"
	lock
# 511 "data/maps/DaycarePond/scripts.pory"
	speakername SlowpokeInCave_Text_0
# 512 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 513 "data/maps/DaycarePond/scripts.pory"
	msgbox SlowpokeInCave_Text_3, MSGBOX_DEFAULT
# 514 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_SLOWPOKE_BATTLE
# 515 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 516 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 517 "data/maps/DaycarePond/scripts.pory"
	release
	end


CroagunkInCave::
# 525 "data/maps/DaycarePond/scripts.pory"
	lock
# 526 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 527 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_CROAGUNK_BATTLE, CroagunkInCave_1
# 539 "data/maps/DaycarePond/scripts.pory"
	applymovement Croagunk, BattleVsMarill_Movement_0
# 540 "data/maps/DaycarePond/scripts.pory"
	waitmovement Croagunk
# 541 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 542 "data/maps/DaycarePond/scripts.pory"
	applymovement Croagunk, Common_Movement_ExclamationMark
# 543 "data/maps/DaycarePond/scripts.pory"
	waitmovement Croagunk
# 544 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 545 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 546 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 547 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_2, MSGBOX_AUTOCLOSE
# 548 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 549 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_CROAGUNK, 25
# 550 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 551 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 552 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CroagunkInCave_4
	return

CroagunkInCave_1:
# 529 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 530 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 531 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_1, MSGBOX_DEFAULT
# 532 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 533 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 534 "data/maps/DaycarePond/scripts.pory"
	release
	end

CroagunkInCave_4:
# 554 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 555 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 556 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_3, MSGBOX_DEFAULT
# 557 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_CROAGUNK_BATTLE
# 558 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 559 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 560 "data/maps/DaycarePond/scripts.pory"
	release
	end


CroagunkInCaveTrigger::
# 566 "data/maps/DaycarePond/scripts.pory"
	goto_if_unset FLAG_CROAGUNK_BATTLE, CroagunkInCaveTrigger_1
	return

CroagunkInCaveTrigger_1:
# 568 "data/maps/DaycarePond/scripts.pory"
	special PlayTrainerEncounterMusic
# 569 "data/maps/DaycarePond/scripts.pory"
	applymovement Croagunk, Common_Movement_ExclamationMark
# 570 "data/maps/DaycarePond/scripts.pory"
	waitmovement Croagunk
# 571 "data/maps/DaycarePond/scripts.pory"
	delay 60
# 572 "data/maps/DaycarePond/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 573 "data/maps/DaycarePond/scripts.pory"
	switch VAR_TEMP_2
# 575 "data/maps/DaycarePond/scripts.pory"
	case 7, CroagunkInCaveTrigger_4
# 595 "data/maps/DaycarePond/scripts.pory"
	case 8, CroagunkInCaveTrigger_5
# 617 "data/maps/DaycarePond/scripts.pory"
	case 9, CroagunkInCaveTrigger_6
# 639 "data/maps/DaycarePond/scripts.pory"
	case 10, CroagunkInCaveTrigger_7
# 661 "data/maps/DaycarePond/scripts.pory"
	case 11, CroagunkInCaveTrigger_8
	return

CroagunkInCaveTrigger_4:
# 576 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, BuizelInCaveTrigger_Movement_0
# 577 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 578 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 579 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_2, MSGBOX_AUTOCLOSE
# 580 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 581 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_CROAGUNK, 25
# 582 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 583 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 584 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CroagunkInCaveTrigger_9
	return

CroagunkInCaveTrigger_5:
# 596 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, BuizelInCaveTrigger_Movement_0
# 597 "data/maps/DaycarePond/scripts.pory"
	applymovement Croagunk, BuizelInCaveTrigger_Movement_1
# 598 "data/maps/DaycarePond/scripts.pory"
	waitmovement Croagunk
# 599 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 600 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 601 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_2, MSGBOX_AUTOCLOSE
# 602 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 603 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_CROAGUNK, 25
# 604 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 605 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 606 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CroagunkInCaveTrigger_11
	return

CroagunkInCaveTrigger_6:
# 618 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, BuizelInCaveTrigger_Movement_0
# 619 "data/maps/DaycarePond/scripts.pory"
	applymovement Croagunk, CroagunkInCaveTrigger_Movement_0
# 620 "data/maps/DaycarePond/scripts.pory"
	waitmovement Croagunk
# 621 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 622 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 623 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_2, MSGBOX_AUTOCLOSE
# 624 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 625 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_CROAGUNK, 25
# 626 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 627 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 628 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CroagunkInCaveTrigger_13
	return

CroagunkInCaveTrigger_7:
# 640 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, BuizelInCaveTrigger_Movement_0
# 641 "data/maps/DaycarePond/scripts.pory"
	applymovement Croagunk, CroagunkInCaveTrigger_Movement_1
# 642 "data/maps/DaycarePond/scripts.pory"
	waitmovement Croagunk
# 643 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 644 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 645 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_2, MSGBOX_AUTOCLOSE
# 646 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 647 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_CROAGUNK, 25
# 648 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 649 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 650 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CroagunkInCaveTrigger_15
	return

CroagunkInCaveTrigger_8:
# 662 "data/maps/DaycarePond/scripts.pory"
	applymovement LOCALID_PLAYER, BuizelInCaveTrigger_Movement_0
# 663 "data/maps/DaycarePond/scripts.pory"
	applymovement Croagunk, CroagunkInCaveTrigger_Movement_2
# 664 "data/maps/DaycarePond/scripts.pory"
	waitmovement Croagunk
# 665 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 666 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 667 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_2, MSGBOX_AUTOCLOSE
# 668 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 669 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_CROAGUNK, 25
# 670 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 671 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 672 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CroagunkInCaveTrigger_17
	return

CroagunkInCaveTrigger_9:
# 586 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 587 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 588 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_3, MSGBOX_DEFAULT
# 589 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_CROAGUNK_BATTLE
# 590 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 591 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 592 "data/maps/DaycarePond/scripts.pory"
	release
	end

CroagunkInCaveTrigger_11:
# 608 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 609 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 610 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_3, MSGBOX_DEFAULT
# 611 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_CROAGUNK_BATTLE
# 612 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 613 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 614 "data/maps/DaycarePond/scripts.pory"
	release
	end

CroagunkInCaveTrigger_13:
# 630 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 631 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 632 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_3, MSGBOX_DEFAULT
# 633 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_CROAGUNK_BATTLE
# 634 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 635 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 636 "data/maps/DaycarePond/scripts.pory"
	release
	end

CroagunkInCaveTrigger_15:
# 652 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 653 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 654 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_3, MSGBOX_DEFAULT
# 655 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_CROAGUNK_BATTLE
# 656 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 657 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 658 "data/maps/DaycarePond/scripts.pory"
	release
	end

CroagunkInCaveTrigger_17:
# 674 "data/maps/DaycarePond/scripts.pory"
	speakername CroagunkInCave_Text_0
# 675 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROAGUNK, EMOTE_NORMAL
# 676 "data/maps/DaycarePond/scripts.pory"
	msgbox CroagunkInCave_Text_3, MSGBOX_DEFAULT
# 677 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_CROAGUNK_BATTLE
# 678 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 679 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 680 "data/maps/DaycarePond/scripts.pory"
	release
	end


BattleVsDragonair::
# 688 "data/maps/DaycarePond/scripts.pory"
	lock
# 690 "data/maps/DaycarePond/scripts.pory"
	goto_if_set FLAG_TRANS_DRAGONAIR, BattleVsDragonair_2
# 702 "data/maps/DaycarePond/scripts.pory"
	playbgm MUS_PMD_BOSS_INTRO, FALSE
# 703 "data/maps/DaycarePond/scripts.pory"
	applymovement Dragonair, BattleVsMarill_Movement_0
# 704 "data/maps/DaycarePond/scripts.pory"
	waitmovement Dragonair
# 705 "data/maps/DaycarePond/scripts.pory"
	playse SE_PIN
# 706 "data/maps/DaycarePond/scripts.pory"
	applymovement Dragonair, Common_Movement_ExclamationMark
# 707 "data/maps/DaycarePond/scripts.pory"
	waitmovement Dragonair
# 708 "data/maps/DaycarePond/scripts.pory"
	speakername BattleVsDragonair_Text_0
# 709 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_DRAGONAIR, EMOTE_NORMAL
# 710 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsDragonair_Text_2, MSGBOX_AUTOCLOSE
# 711 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 712 "data/maps/DaycarePond/scripts.pory"
	setwildbattle SPECIES_DRAGONAIR, 25, move1 = MOVE_OUTRAGE, move2 = MOVE_WATERFALL, move3 = MOVE_IRON_HEAD, move4 = MOVE_OUTRAGE
# 713 "data/maps/DaycarePond/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 0, 2, 0, 0
# 714 "data/maps/DaycarePond/scripts.pory"
	dowildbattle
# 715 "data/maps/DaycarePond/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 716 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsDragonair_4
	return

BattleVsDragonair_2:
# 692 "data/maps/DaycarePond/scripts.pory"
	applymovement Dragonair, BattleVsMarill_Movement_0
# 693 "data/maps/DaycarePond/scripts.pory"
	waitmovement Dragonair
# 694 "data/maps/DaycarePond/scripts.pory"
	speakername BattleVsDragonair_Text_0
# 695 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_DRAGONAIR, EMOTE_NORMAL
# 696 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsDragonair_Text_1, MSGBOX_DEFAULT
# 697 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 698 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 699 "data/maps/DaycarePond/scripts.pory"
	release
	end

BattleVsDragonair_4:
# 718 "data/maps/DaycarePond/scripts.pory"
	lock
# 719 "data/maps/DaycarePond/scripts.pory"
	applymovement Dragonair, Common_Movement_ExclamationMark
# 720 "data/maps/DaycarePond/scripts.pory"
	waitmovement Dragonair
# 721 "data/maps/DaycarePond/scripts.pory"
	playse SE_PIN
# 722 "data/maps/DaycarePond/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 723 "data/maps/DaycarePond/scripts.pory"
	lock
# 724 "data/maps/DaycarePond/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 725 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_TRANS_DRAGONAIR
# 726 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_MUDKIP_PICKED_UP
# 727 "data/maps/DaycarePond/scripts.pory"
	delay 30
# 728 "data/maps/DaycarePond/scripts.pory"
	dittotransform SPECIES_DRAGONAIR
# 729 "data/maps/DaycarePond/scripts.pory"
	playse MUS_LEVEL_UP
# 730 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsDragonair_Text_3, MSGBOX_DEFAULT
# 731 "data/maps/DaycarePond/scripts.pory"
	waitse
# 732 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 733 "data/maps/DaycarePond/scripts.pory"
	lock
# 734 "data/maps/DaycarePond/scripts.pory"
	dittotransform VAR_TEMP_0
# 735 "data/maps/DaycarePond/scripts.pory"
	givemon SPECIES_DRAGONAIR, 25, move1 = MOVE_OUTRAGE, move2 = MOVE_WATERFALL, move3 = MOVE_IRON_HEAD, move4 = MOVE_SURF
# 736 "data/maps/DaycarePond/scripts.pory"
	speakername BattleVsDragonair_Text_0
# 737 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_DRAGONAIR, EMOTE_HAPPY
# 738 "data/maps/DaycarePond/scripts.pory"
	msgbox BattleVsDragonair_Text_4, MSGBOX_DEFAULT
# 739 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 740 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 741 "data/maps/DaycarePond/scripts.pory"
	fadenewbgm MUS_PMD_LAKE
# 742 "data/maps/DaycarePond/scripts.pory"
	release
	end


DaycarePond_FindLuckyEgg::
# 750 "data/maps/DaycarePond/scripts.pory"
	finditem ITEM_LUCKY_EGG
	return


ChanseyDaycarePond::
# 755 "data/maps/DaycarePond/scripts.pory"
	lock
# 756 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 757 "data/maps/DaycarePond/scripts.pory"
	speakername ChanseyDaycarePond_Text_0
# 758 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 759 "data/maps/DaycarePond/scripts.pory"
	msgbox ChanseyDaycarePond_Text_1, MSGBOX_DEFAULT
# 760 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 761 "data/maps/DaycarePond/scripts.pory"
	msgbox ChanseyDaycarePond_Text_2, MSGBOX_YESNO
# 762 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 763 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycarePond_1
# 793 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 794 "data/maps/DaycarePond/scripts.pory"
	msgbox ChanseyDaycarePond_Text_5, MSGBOX_AUTOCLOSE
# 795 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 796 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 797 "data/maps/DaycarePond/scripts.pory"
	release
	end

ChanseyDaycarePond_1:
# 765 "data/maps/DaycarePond/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 766 "data/maps/DaycarePond/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycarePond_4
# 783 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 784 "data/maps/DaycarePond/scripts.pory"
	msgbox ChanseyDaycarePond_Text_4, MSGBOX_AUTOCLOSE
# 785 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 786 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 787 "data/maps/DaycarePond/scripts.pory"
	release
	end

ChanseyDaycarePond_4:
# 768 "data/maps/DaycarePond/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 769 "data/maps/DaycarePond/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 770 "data/maps/DaycarePond/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 771 "data/maps/DaycarePond/scripts.pory"
	playfanfare MUS_HEAL
# 772 "data/maps/DaycarePond/scripts.pory"
	waitfanfare
# 773 "data/maps/DaycarePond/scripts.pory"
	special HealPlayerParty
# 774 "data/maps/DaycarePond/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 775 "data/maps/DaycarePond/scripts.pory"
	msgbox ChanseyDaycarePond_Text_3, MSGBOX_AUTOCLOSE
# 776 "data/maps/DaycarePond/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 777 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 778 "data/maps/DaycarePond/scripts.pory"
	release
	end


CroconawDialog::
# 804 "data/maps/DaycarePond/scripts.pory"
	lock
# 805 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 806 "data/maps/DaycarePond/scripts.pory"
	speakername CroconawDialog_Text_0
# 807 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_CROCONAW, EMOTE_NORMAL
# 808 "data/maps/DaycarePond/scripts.pory"
	msgbox CroconawDialog_Text_1, MSGBOX_NPC
# 809 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 810 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 811 "data/maps/DaycarePond/scripts.pory"
	release
	end


StarmieDialog::
# 816 "data/maps/DaycarePond/scripts.pory"
	lock
# 817 "data/maps/DaycarePond/scripts.pory"
	faceplayer
# 818 "data/maps/DaycarePond/scripts.pory"
	speakername StarmieDialog_Text_0
# 819 "data/maps/DaycarePond/scripts.pory"
	createfieldmugshot MUGSHOT_STARMIE, EMOTE_NORMAL
# 820 "data/maps/DaycarePond/scripts.pory"
	msgbox StarmieDialog_Text_1, MSGBOX_NPC
# 821 "data/maps/DaycarePond/scripts.pory"
	waitmessage
# 822 "data/maps/DaycarePond/scripts.pory"
	removefieldmugshot
# 823 "data/maps/DaycarePond/scripts.pory"
	release
	end


DragonairHealLocation::
# 830 "data/maps/DaycarePond/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_POND_1
	end


# 24 "data/maps/DaycarePond/scripts.pory"
BattleVsMarill_Movement_0:
# 24 "data/maps/DaycarePond/scripts.pory"
	face_player
	step_end

# 250 "data/maps/DaycarePond/scripts.pory"
GoomyInCaveTrigger_Movement_0:
# 250 "data/maps/DaycarePond/scripts.pory"
	face_right
	step_end

# 271 "data/maps/DaycarePond/scripts.pory"
GoomyInCaveTrigger_Movement_1:
# 271 "data/maps/DaycarePond/scripts.pory"
	walk_left
	step_end

# 367 "data/maps/DaycarePond/scripts.pory"
BuizelInCaveTrigger_Movement_0:
# 367 "data/maps/DaycarePond/scripts.pory"
	face_up
	step_end

# 368 "data/maps/DaycarePond/scripts.pory"
BuizelInCaveTrigger_Movement_1:
# 368 "data/maps/DaycarePond/scripts.pory"
	walk_down
	step_end

# 475 "data/maps/DaycarePond/scripts.pory"
SlowpokeInCaveTrigger_Movement_0:
# 475 "data/maps/DaycarePond/scripts.pory"
	face_left
	step_end

# 476 "data/maps/DaycarePond/scripts.pory"
SlowpokeInCaveTrigger_Movement_1:
# 476 "data/maps/DaycarePond/scripts.pory"
	walk_right
	step_end

# 619 "data/maps/DaycarePond/scripts.pory"
CroagunkInCaveTrigger_Movement_0:
# 619 "data/maps/DaycarePond/scripts.pory"
	walk_down
# 619 "data/maps/DaycarePond/scripts.pory"
	walk_down
	step_end

# 641 "data/maps/DaycarePond/scripts.pory"
CroagunkInCaveTrigger_Movement_1:
# 641 "data/maps/DaycarePond/scripts.pory"
	walk_down
# 641 "data/maps/DaycarePond/scripts.pory"
	walk_down
# 641 "data/maps/DaycarePond/scripts.pory"
	walk_down
	step_end

# 663 "data/maps/DaycarePond/scripts.pory"
CroagunkInCaveTrigger_Movement_2:
# 663 "data/maps/DaycarePond/scripts.pory"
	walk_down
# 663 "data/maps/DaycarePond/scripts.pory"
	walk_down
# 663 "data/maps/DaycarePond/scripts.pory"
	walk_down
# 663 "data/maps/DaycarePond/scripts.pory"
	walk_down
	step_end

BattleVsMarill_Text_0:
# 15 "data/maps/DaycarePond/scripts.pory"
	.string "Marill$"

BattleVsMarill_Text_1:
# 17 "data/maps/DaycarePond/scripts.pory"
	.string "You’re stronger than you look!\pSwim swiftly on your journey!$"

BattleVsMarill_Text_2:
# 31 "data/maps/DaycarePond/scripts.pory"
	.string "Oh!\nA Ditto?\pYou’re gathering powers for your\nquest, right?\pIf you can beat me, you’ll earn the\npower to transform into me!$"

BattleVsMarill_Text_3:
# 51 "data/maps/DaycarePond/scripts.pory"
	.string "You have gained the ability to\ntransform into Marill!$"

PsyduckDialog_Text_0:
# 75 "data/maps/DaycarePond/scripts.pory"
	.string "Psyduck$"

PsyduckDialog_Text_1:
# 77 "data/maps/DaycarePond/scripts.pory"
	.string "I came to the lake to try to ease\nthis headache...\pIt's the most peaceful biome at\nthe daycare.$"

PsyduckDialog_Text_2:
# 89 "data/maps/DaycarePond/scripts.pory"
	.string "Are you looking for Mudkip?\pIt's trainer came back and picked\nit up!\pAs fun as the Daycare is, some\nPokémon yearn to battle alongside\ltheir trainers.$"

SprigatitoDialog_Text_0:
# 105 "data/maps/DaycarePond/scripts.pory"
	.string "Sprigatito$"

SprigatitoDialog_Text_1:
# 107 "data/maps/DaycarePond/scripts.pory"
	.string "A Grass_type!\pDon't see many around the lake\nhere.\pPlease take this Egg I found.\n$"

SprigatitoDialog_Text_2:
# 123 "data/maps/DaycarePond/scripts.pory"
	.string "I love it here by the water but\nI hardly see any other\lGrass_types...$"

SprigatitoDialog_Text_3:
# 138 "data/maps/DaycarePond/scripts.pory"
	.string "A Grass_type!\pDon't see many around the lake\nhere.$"

MudkipDialog_Text_0:
# 163 "data/maps/DaycarePond/scripts.pory"
	.string "Mudkip$"

MudkipDialog_Text_1:
# 165 "data/maps/DaycarePond/scripts.pory"
	.string "I hope my trainer comes back\nsoon...\pI miss them.\pI'm supposed to be their first\npartner Pokémon.$"

SeakingDialog_Text_0:
# 175 "data/maps/DaycarePond/scripts.pory"
	.string "Seaking$"

SeakingDialog_Text_1:
# 177 "data/maps/DaycarePond/scripts.pory"
	.string "Everyone talks about how\ncool Vaporeon is.\pSeakings deserve attention too...\n$"

QuagsireDialog_Text_0:
# 188 "data/maps/DaycarePond/scripts.pory"
	.string "Quagsire$"

QuagsireDialog_Text_1:
# 190 "data/maps/DaycarePond/scripts.pory"
	.string "The Lake here is so calm.\pDragonair makes sure that we\nkeep the peace here.\pShe believes keeping it mellow\nis the key to EXP.$"

GoomyInCave_Text_0:
# 202 "data/maps/DaycarePond/scripts.pory"
	.string "Goomy$"

GoomyInCave_Text_1:
# 204 "data/maps/DaycarePond/scripts.pory"
	.string "Cool vibes friend.\pKeep on keepin on.\n$"

GoomyInCave_Text_2:
# 220 "data/maps/DaycarePond/scripts.pory"
	.string "Keepin it mellow...\nLet's just have some fun.$"

BuizelInCave_Text_0:
# 302 "data/maps/DaycarePond/scripts.pory"
	.string "Buizel$"

BuizelInCave_Text_1:
# 304 "data/maps/DaycarePond/scripts.pory"
	.string "Dragonair keeps to herself.\nEnsuring maximum relaxation.$"

BuizelInCave_Text_2:
# 320 "data/maps/DaycarePond/scripts.pory"
	.string "Dragonair likes to keep the waters\ncalm around here.\pLet's keep it lowkey.\n$"

BuizelInCave_Text_3:
# 330 "data/maps/DaycarePond/scripts.pory"
	.string "Dragonair likes to be cryptic.\pShe set up this maze so only those\nwho really need something from her\lwill seek her out.\pSome Pokémon really harsh her\nmellow.$"

BuizelInCave_Text_4:
# 343 "data/maps/DaycarePond/scripts.pory"
	.string "Welcome to the Lake biome,\nthe calmest in the Daycare.$"

SlowpokeInCave_Text_0:
# 426 "data/maps/DaycarePond/scripts.pory"
	.string "Slowpoke$"

SlowpokeInCave_Text_1:
# 428 "data/maps/DaycarePond/scripts.pory"
	.string "These bridges are so confusing...\pI've been stuck here for a while,\nbut it's chill.$"

SlowpokeInCave_Text_2:
# 444 "data/maps/DaycarePond/scripts.pory"
	.string "Dragonair really likes my vibe.\n$"

SlowpokeInCave_Text_3:
# 453 "data/maps/DaycarePond/scripts.pory"
	.string "Maybe I'm too slow to\nharsh the vibe.$"

CroagunkInCave_Text_0:
# 529 "data/maps/DaycarePond/scripts.pory"
	.string "Croagunk$"

CroagunkInCave_Text_1:
# 531 "data/maps/DaycarePond/scripts.pory"
	.string "Right on.$"

CroagunkInCave_Text_2:
# 547 "data/maps/DaycarePond/scripts.pory"
	.string "Duuuuuude.\nWhat's upppp?$"

CroagunkInCave_Text_3:
# 556 "data/maps/DaycarePond/scripts.pory"
	.string "We keep it peaceful here my dude.\pCan't have anyone mess with the\nvibes or we risk losing out on\lgaining EXP.\pHaven't leveled up yet but I'm\nchillin.\pI'm sure it'll come.\n$"

BattleVsDragonair_Text_0:
# 694 "data/maps/DaycarePond/scripts.pory"
	.string "Dragonair$"

BattleVsDragonair_Text_1:
# 696 "data/maps/DaycarePond/scripts.pory"
	.string "You have proven your strength.\pI hope one day you learn that\ngrace will be the way to the EXP.$"

BattleVsDragonair_Text_2:
# 710 "data/maps/DaycarePond/scripts.pory"
	.string "Hello there Ditto.\pYes, I see through your facade.\pMy philosophy to gain EXP has been\nto keep this biome calm.\pI spent my early days in the\ncrashing waterfalls, but gained\lno EXP.\pI found this biome and figured\nI try a different approach.\pYou seem to be causing a ruckus,\nand I have no problem taking you\ldown!$"

BattleVsDragonair_Text_3:
# 730 "data/maps/DaycarePond/scripts.pory"
	.string "You have gained the ability to\ntransform into Dragonair!$"

BattleVsDragonair_Text_4:
# 738 "data/maps/DaycarePond/scripts.pory"
	.string "Very well Ditto.\nGo on.\pLeave this place calmly, with\nthe power to scale roaring\lwaterfalls.$"

ChanseyDaycarePond_Text_0:
# 757 "data/maps/DaycarePond/scripts.pory"
	.string "Chansey$"

ChanseyDaycarePond_Text_1:
# 759 "data/maps/DaycarePond/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycarePond_Text_2:
# 761 "data/maps/DaycarePond/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycarePond_Text_3:
# 775 "data/maps/DaycarePond/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycarePond_Text_4:
# 784 "data/maps/DaycarePond/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycarePond_Text_5:
# 794 "data/maps/DaycarePond/scripts.pory"
	.string "Oh, okay then.$"

CroconawDialog_Text_0:
# 806 "data/maps/DaycarePond/scripts.pory"
	.string "Croconaw$"

CroconawDialog_Text_1:
# 808 "data/maps/DaycarePond/scripts.pory"
	.string "I haven't seen Totodile around the\nlake for a while now.\pI wonder if he's found a new spot.\pWhile it is peaceful here, privacy\nis hard to come by.$"

StarmieDialog_Text_0:
# 818 "data/maps/DaycarePond/scripts.pory"
	.string "Starmie$"

StarmieDialog_Text_1:
# 820 "data/maps/DaycarePond/scripts.pory"
	.string "Isn't the water so relaxing?\nReally puts the mind at ease.$"
