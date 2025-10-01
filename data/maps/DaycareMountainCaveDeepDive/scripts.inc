DaycareMountainCaveDeepDive_MapScripts::
	.byte 0


GorebyssInCave::
# 4 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	lock
# 6 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	goto_if_set FLAG_GOREBYSS_BATTLE, GorebyssInCave_1
# 19 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Gorebyss, GorebyssInCave_Movement_0
# 20 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Gorebyss
# 21 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	special PlayTrainerEncounterMusic
# 22 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Gorebyss, Common_Movement_ExclamationMark
# 23 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Gorebyss
# 24 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	delay 60
# 25 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 26 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 27 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_2, MSGBOX_AUTOCLOSE
# 28 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 29 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_GOREBYSS, 25
# 30 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 31 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 32 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GorebyssInCave_4
	return

GorebyssInCave_1:
# 8 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	faceplayer
# 9 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 10 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 11 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_1, MSGBOX_DEFAULT
# 12 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 13 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 14 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

GorebyssInCave_4:
# 34 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 35 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 36 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_3, MSGBOX_DEFAULT
# 37 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_GOREBYSS_BATTLE
# 38 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 39 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 40 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end


GorebyssInCaveTrigger::
# 47 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	goto_if_unset FLAG_GOREBYSS_BATTLE, GorebyssInCaveTrigger_1
	return

GorebyssInCaveTrigger_1:
# 49 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	special PlayTrainerEncounterMusic
# 50 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Gorebyss, Common_Movement_ExclamationMark
# 51 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Gorebyss
# 52 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	delay 60
# 53 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 54 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	switch VAR_TEMP_1
# 56 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 5, GorebyssInCaveTrigger_4
# 76 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 6, GorebyssInCaveTrigger_5
# 98 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 7, GorebyssInCaveTrigger_6
# 120 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 8, GorebyssInCaveTrigger_7
	return

GorebyssInCaveTrigger_4:
# 57 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, GorebyssInCaveTrigger_Movement_0
# 58 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 59 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 60 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_2, MSGBOX_AUTOCLOSE
# 61 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 62 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_GOREBYSS, 25
# 63 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 64 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 65 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GorebyssInCaveTrigger_8
	return

GorebyssInCaveTrigger_5:
# 77 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, GorebyssInCaveTrigger_Movement_0
# 78 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Gorebyss, GorebyssInCaveTrigger_Movement_1
# 79 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Gorebyss
# 80 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 81 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 82 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_2, MSGBOX_AUTOCLOSE
# 83 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 84 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_GOREBYSS, 25
# 85 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 86 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 87 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GorebyssInCaveTrigger_10
	return

GorebyssInCaveTrigger_6:
# 99 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, GorebyssInCaveTrigger_Movement_0
# 100 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Gorebyss, GorebyssInCaveTrigger_Movement_2
# 101 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Gorebyss
# 102 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 103 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 104 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_2, MSGBOX_AUTOCLOSE
# 105 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 106 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_GOREBYSS, 25
# 107 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 108 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 109 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GorebyssInCaveTrigger_12
	return

GorebyssInCaveTrigger_7:
# 121 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, GorebyssInCaveTrigger_Movement_0
# 122 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Gorebyss, GorebyssInCaveTrigger_Movement_3
# 123 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Gorebyss
# 124 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 125 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 126 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_2, MSGBOX_AUTOCLOSE
# 127 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 128 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_GOREBYSS, 25
# 129 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 130 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 131 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq GorebyssInCaveTrigger_14
	return

GorebyssInCaveTrigger_8:
# 67 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 68 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 69 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_3, MSGBOX_DEFAULT
# 70 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_GOREBYSS_BATTLE
# 71 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 72 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 73 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

GorebyssInCaveTrigger_10:
# 89 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 90 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 91 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_3, MSGBOX_DEFAULT
# 92 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_GOREBYSS_BATTLE
# 93 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 94 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 95 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

GorebyssInCaveTrigger_12:
# 111 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 112 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 113 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_3, MSGBOX_DEFAULT
# 114 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_GOREBYSS_BATTLE
# 115 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 116 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 117 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

GorebyssInCaveTrigger_14:
# 133 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername GorebyssInCave_Text_0
# 134 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_GOREBYSS, EMOTE_NORMAL
# 135 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox GorebyssInCave_Text_3, MSGBOX_DEFAULT
# 136 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_GOREBYSS_BATTLE
# 137 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 138 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 139 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end


HuntailInCave::
# 147 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	lock
# 148 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	faceplayer
# 149 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	goto_if_set FLAG_HUNTAIL_BATTLE, HuntailInCave_1
# 161 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Huntail, GorebyssInCave_Movement_0
# 162 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Huntail
# 163 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	special PlayTrainerEncounterMusic
# 164 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Huntail, Common_Movement_ExclamationMark
# 165 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Huntail
# 166 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	delay 60
# 167 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 168 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 169 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_2, MSGBOX_AUTOCLOSE
# 170 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 171 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_HUNTAIL, 25
# 172 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 173 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 174 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq HuntailInCave_4
	return

HuntailInCave_1:
# 151 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 152 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 153 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_1, MSGBOX_DEFAULT
# 154 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 155 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 156 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

HuntailInCave_4:
# 176 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 177 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 178 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_3, MSGBOX_DEFAULT
# 179 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_HUNTAIL_BATTLE
# 180 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 181 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 182 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end


HuntailInCaveTrigger::
# 189 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	goto_if_unset FLAG_HUNTAIL_BATTLE, HuntailInCaveTrigger_1
	return

HuntailInCaveTrigger_1:
# 191 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	special PlayTrainerEncounterMusic
# 192 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Huntail, Common_Movement_ExclamationMark
# 193 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Huntail
# 194 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	delay 60
# 195 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 196 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	switch VAR_TEMP_1
# 198 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 26, HuntailInCaveTrigger_4
# 218 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 25, HuntailInCaveTrigger_5
# 240 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 24, HuntailInCaveTrigger_6
# 262 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	case 23, HuntailInCaveTrigger_7
	return

HuntailInCaveTrigger_4:
# 199 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, HuntailInCaveTrigger_Movement_0
# 200 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 201 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 202 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_2, MSGBOX_AUTOCLOSE
# 203 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 204 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_HUNTAIL, 25
# 205 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 206 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 207 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq HuntailInCaveTrigger_8
	return

HuntailInCaveTrigger_5:
# 219 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, HuntailInCaveTrigger_Movement_0
# 220 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Huntail, HuntailInCaveTrigger_Movement_1
# 221 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Huntail
# 222 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 223 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 224 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_2, MSGBOX_AUTOCLOSE
# 225 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 226 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_HUNTAIL, 25
# 227 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 228 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 229 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq HuntailInCaveTrigger_10
	return

HuntailInCaveTrigger_6:
# 241 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, HuntailInCaveTrigger_Movement_0
# 242 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Huntail, HuntailInCaveTrigger_Movement_2
# 243 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Huntail
# 244 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 245 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 246 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_2, MSGBOX_AUTOCLOSE
# 247 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 248 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_HUNTAIL, 25
# 249 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 250 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 251 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq HuntailInCaveTrigger_12
	return

HuntailInCaveTrigger_7:
# 263 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement LOCALID_PLAYER, HuntailInCaveTrigger_Movement_0
# 264 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	applymovement Huntail, HuntailInCaveTrigger_Movement_3
# 265 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmovement Huntail
# 266 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 267 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 268 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_2, MSGBOX_AUTOCLOSE
# 269 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 270 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setwildbattle SPECIES_HUNTAIL, 25
# 271 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	dowildbattle
# 272 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 273 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq HuntailInCaveTrigger_14
	return

HuntailInCaveTrigger_8:
# 209 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 210 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 211 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_3, MSGBOX_DEFAULT
# 212 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_HUNTAIL_BATTLE
# 213 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 214 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 215 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

HuntailInCaveTrigger_10:
# 231 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 232 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 233 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_3, MSGBOX_DEFAULT
# 234 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_HUNTAIL_BATTLE
# 235 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 236 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 237 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

HuntailInCaveTrigger_12:
# 253 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 254 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 255 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_3, MSGBOX_DEFAULT
# 256 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_HUNTAIL_BATTLE
# 257 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 258 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 259 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end

HuntailInCaveTrigger_14:
# 275 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	speakername HuntailInCave_Text_0
# 276 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	createfieldmugshot MUGSHOT_HUNTAIL, EMOTE_NORMAL
# 277 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	msgbox HuntailInCave_Text_3, MSGBOX_DEFAULT
# 278 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	setflag FLAG_HUNTAIL_BATTLE
# 279 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	waitmessage
# 280 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	removefieldmugshot
# 281 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	release
	end


# 19 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
GorebyssInCave_Movement_0:
# 19 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	face_player
	step_end

# 57 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
GorebyssInCaveTrigger_Movement_0:
# 57 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	face_left
	step_end

# 78 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
GorebyssInCaveTrigger_Movement_1:
# 78 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_right
	step_end

# 100 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
GorebyssInCaveTrigger_Movement_2:
# 100 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_right
# 100 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_right
	step_end

# 122 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
GorebyssInCaveTrigger_Movement_3:
# 122 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_right
# 122 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_right
# 122 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_right
	step_end

# 199 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
HuntailInCaveTrigger_Movement_0:
# 199 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	face_right
	step_end

# 220 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
HuntailInCaveTrigger_Movement_1:
# 220 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_left
	step_end

# 242 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
HuntailInCaveTrigger_Movement_2:
# 242 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_left
# 242 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_left
	step_end

# 264 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
HuntailInCaveTrigger_Movement_3:
# 264 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_left
# 264 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_left
# 264 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	walk_left
	step_end

GorebyssInCave_Text_0:
# 9 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "Gorebyss$"

GorebyssInCave_Text_1:
# 11 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "My brother Huntail doesn't care\nfor beauty.\pHe will attack you fiercely!\n$"

GorebyssInCave_Text_2:
# 27 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "You are glowing!\nShow me how you illuminate\lthe deep with a battle!$"

GorebyssInCave_Text_3:
# 36 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "You really are quite luminescent.\n$"

HuntailInCave_Text_0:
# 151 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "Huntail$"

HuntailInCave_Text_1:
# 153 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "Back into the dark...\nBut you swim well, little one.$"

HuntailInCave_Text_2:
# 169 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "There's no need for light here in\nthe depths!$"

HuntailInCave_Text_3:
# 178 "data/maps/DaycareMountainCaveDeepDive/scripts.pory"
	.string "I prefer the the seafloor to be\ndark.$"
