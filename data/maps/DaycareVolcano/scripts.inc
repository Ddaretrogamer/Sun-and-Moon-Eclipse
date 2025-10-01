DaycareVolcano_MapScripts::
# 2 "data/maps/DaycareVolcano/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareVolcano_OnTransition
	.byte 0


DaycareVolcano_OnTransition::
# 6 "data/maps/DaycareVolcano/scripts.pory"
	dittotransform SPECIES_MARILL
# 7 "data/maps/DaycareVolcano/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_VOLCANO
# 8 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_DISABLE_XFORM_MENU
	end


CyndaquilInCave::
# 13 "data/maps/DaycareVolcano/scripts.pory"
	lock
# 14 "data/maps/DaycareVolcano/scripts.pory"
	faceplayer
# 15 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_set FLAG_CYNDAQUIL_BATTLE, CyndaquilInCave_1
# 27 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Cyndaquil, CyndaquilInCave_Movement_0
# 28 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Cyndaquil
# 29 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 30 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Cyndaquil, Common_Movement_ExclamationMark
# 31 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Cyndaquil
# 32 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 33 "data/maps/DaycareVolcano/scripts.pory"
	speakername CyndaquilInCave_Text_0
# 34 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CYNDAQUIL, EMOTE_NORMAL
# 35 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CyndaquilInCave_Text_2, MSGBOX_AUTOCLOSE
# 36 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 37 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_CYNDAQUIL, 25
# 38 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 39 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 40 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CyndaquilInCave_4
	return

CyndaquilInCave_1:
# 17 "data/maps/DaycareVolcano/scripts.pory"
	speakername CyndaquilInCave_Text_0
# 18 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CYNDAQUIL, EMOTE_NORMAL
# 19 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CyndaquilInCave_Text_1, MSGBOX_DEFAULT
# 20 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 21 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 22 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

CyndaquilInCave_4:
# 42 "data/maps/DaycareVolcano/scripts.pory"
	speakername CyndaquilInCave_Text_0
# 43 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CYNDAQUIL, EMOTE_NORMAL
# 44 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CyndaquilInCave_Text_1, MSGBOX_DEFAULT
# 45 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_CYNDAQUIL_BATTLE
# 46 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 47 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 48 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


CyndaquilInCaveTrigger::
# 56 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_unset FLAG_CYNDAQUIL_BATTLE, CyndaquilInCaveTrigger_1
	return

CyndaquilInCaveTrigger_1:
# 58 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 59 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Cyndaquil, Common_Movement_ExclamationMark
# 60 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Cyndaquil
# 61 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 62 "data/maps/DaycareVolcano/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 63 "data/maps/DaycareVolcano/scripts.pory"
	switch VAR_TEMP_2
# 65 "data/maps/DaycareVolcano/scripts.pory"
	case 37, CyndaquilInCaveTrigger_4
# 87 "data/maps/DaycareVolcano/scripts.pory"
	case 36, CyndaquilInCaveTrigger_5
	return

CyndaquilInCaveTrigger_4:
# 66 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, CyndaquilInCaveTrigger_Movement_0
# 67 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Cyndaquil, CyndaquilInCaveTrigger_Movement_1
# 68 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Cyndaquil
# 69 "data/maps/DaycareVolcano/scripts.pory"
	speakername CyndaquilInCave_Text_0
# 70 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CYNDAQUIL, EMOTE_NORMAL
# 71 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CyndaquilInCave_Text_2, MSGBOX_AUTOCLOSE
# 72 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 73 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_CYNDAQUIL, 25
# 74 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 75 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 76 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CyndaquilInCaveTrigger_6
	return

CyndaquilInCaveTrigger_5:
# 88 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, CyndaquilInCaveTrigger_Movement_0
# 89 "data/maps/DaycareVolcano/scripts.pory"
	speakername CyndaquilInCave_Text_0
# 90 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CYNDAQUIL, EMOTE_NORMAL
# 91 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CyndaquilInCave_Text_2, MSGBOX_AUTOCLOSE
# 92 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 93 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_CYNDAQUIL, 25
# 94 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 95 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 96 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CyndaquilInCaveTrigger_8
	return

CyndaquilInCaveTrigger_6:
# 78 "data/maps/DaycareVolcano/scripts.pory"
	speakername CyndaquilInCave_Text_0
# 79 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CYNDAQUIL, EMOTE_NORMAL
# 80 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CyndaquilInCave_Text_1, MSGBOX_DEFAULT
# 81 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_CYNDAQUIL_BATTLE
# 82 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 83 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 84 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

CyndaquilInCaveTrigger_8:
# 98 "data/maps/DaycareVolcano/scripts.pory"
	speakername CyndaquilInCave_Text_0
# 99 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CYNDAQUIL, EMOTE_NORMAL
# 100 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CyndaquilInCave_Text_1, MSGBOX_DEFAULT
# 101 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_CYNDAQUIL_BATTLE
# 102 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 103 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 104 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


VulpixInCave::
# 113 "data/maps/DaycareVolcano/scripts.pory"
	lock
# 114 "data/maps/DaycareVolcano/scripts.pory"
	faceplayer
# 115 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_set FLAG_VULPIX_BATTLE, VulpixInCave_1
# 127 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Vulpix, CyndaquilInCave_Movement_0
# 128 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Vulpix
# 129 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 130 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Vulpix, Common_Movement_ExclamationMark
# 131 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Vulpix
# 132 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 133 "data/maps/DaycareVolcano/scripts.pory"
	speakername VulpixInCave_Text_0
# 134 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_VULPIX, EMOTE_NORMAL
# 135 "data/maps/DaycareVolcano/scripts.pory"
	msgbox VulpixInCave_Text_2, MSGBOX_AUTOCLOSE
# 136 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 137 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 138 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 139 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 140 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq VulpixInCave_4
	return

VulpixInCave_1:
# 117 "data/maps/DaycareVolcano/scripts.pory"
	speakername VulpixInCave_Text_0
# 118 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_VULPIX, EMOTE_NORMAL
# 119 "data/maps/DaycareVolcano/scripts.pory"
	msgbox VulpixInCave_Text_1, MSGBOX_DEFAULT
# 120 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 121 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 122 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

VulpixInCave_4:
# 142 "data/maps/DaycareVolcano/scripts.pory"
	speakername VulpixInCave_Text_0
# 143 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_VULPIX, EMOTE_NORMAL
# 144 "data/maps/DaycareVolcano/scripts.pory"
	msgbox VulpixInCave_Text_3, MSGBOX_DEFAULT
# 145 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_VULPIX_BATTLE
# 146 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 147 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 148 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


VulpixInCaveTrigger::
# 156 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_unset FLAG_VULPIX_BATTLE, VulpixInCaveTrigger_1
	return

VulpixInCaveTrigger_1:
# 158 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 159 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Vulpix, Common_Movement_ExclamationMark
# 160 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Vulpix
# 161 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 162 "data/maps/DaycareVolcano/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 163 "data/maps/DaycareVolcano/scripts.pory"
	switch VAR_TEMP_1
# 165 "data/maps/DaycareVolcano/scripts.pory"
	case 26, VulpixInCaveTrigger_4
# 186 "data/maps/DaycareVolcano/scripts.pory"
	case 27, VulpixInCaveTrigger_5
	return

VulpixInCaveTrigger_4:
# 166 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, VulpixInCaveTrigger_Movement_0
# 167 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, VulpixInCaveTrigger_Movement_0
# 168 "data/maps/DaycareVolcano/scripts.pory"
	speakername VulpixInCave_Text_0
# 169 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_VULPIX, EMOTE_NORMAL
# 170 "data/maps/DaycareVolcano/scripts.pory"
	msgbox VulpixInCave_Text_2, MSGBOX_AUTOCLOSE
# 171 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 172 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 173 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 174 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 175 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq VulpixInCaveTrigger_6
	return

VulpixInCaveTrigger_5:
# 187 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, VulpixInCaveTrigger_Movement_0
# 188 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Vulpix, VulpixInCaveTrigger_Movement_1
# 189 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Vulpix
# 190 "data/maps/DaycareVolcano/scripts.pory"
	speakername VulpixInCave_Text_0
# 191 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_VULPIX, EMOTE_NORMAL
# 192 "data/maps/DaycareVolcano/scripts.pory"
	msgbox VulpixInCave_Text_2, MSGBOX_AUTOCLOSE
# 193 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 194 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_VULPIX, 25
# 195 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 196 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 197 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq VulpixInCaveTrigger_8
	return

VulpixInCaveTrigger_6:
# 177 "data/maps/DaycareVolcano/scripts.pory"
	speakername VulpixInCave_Text_0
# 178 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_VULPIX, EMOTE_NORMAL
# 179 "data/maps/DaycareVolcano/scripts.pory"
	msgbox VulpixInCave_Text_3, MSGBOX_DEFAULT
# 180 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_VULPIX_BATTLE
# 181 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 182 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 183 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

VulpixInCaveTrigger_8:
# 199 "data/maps/DaycareVolcano/scripts.pory"
	speakername VulpixInCave_Text_0
# 200 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_VULPIX, EMOTE_NORMAL
# 201 "data/maps/DaycareVolcano/scripts.pory"
	msgbox VulpixInCave_Text_3, MSGBOX_DEFAULT
# 202 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_VULPIX_BATTLE
# 203 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 204 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 205 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


FuecocoInCave::
# 213 "data/maps/DaycareVolcano/scripts.pory"
	lock
# 214 "data/maps/DaycareVolcano/scripts.pory"
	faceplayer
# 215 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_set FLAG_FUECOCO_BATTLE, FuecocoInCave_1
# 227 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Fuecoco, CyndaquilInCave_Movement_0
# 228 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Fuecoco
# 229 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 230 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Fuecoco, Common_Movement_ExclamationMark
# 231 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Fuecoco
# 232 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 233 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 234 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 235 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_2, MSGBOX_AUTOCLOSE
# 236 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 237 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_FUECOCO, 25, move1 = MOVE_SNARL, move2 = MOVE_YAWN, move3 = MOVE_INCINERATE, move4 = MOVE_CURSE
# 238 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 239 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 240 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FuecocoInCave_4
	return

FuecocoInCave_1:
# 217 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 218 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 219 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_1, MSGBOX_DEFAULT
# 220 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 221 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 222 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

FuecocoInCave_4:
# 242 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 243 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 244 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_3, MSGBOX_DEFAULT
# 245 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_FUECOCO_BATTLE
# 246 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 247 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 248 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


FuecocoInCaveTrigger::
# 255 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_unset FLAG_FUECOCO_BATTLE, FuecocoInCaveTrigger_1
	return

FuecocoInCaveTrigger_1:
# 257 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 258 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Fuecoco, Common_Movement_ExclamationMark
# 259 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Fuecoco
# 260 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 261 "data/maps/DaycareVolcano/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 262 "data/maps/DaycareVolcano/scripts.pory"
	switch VAR_TEMP_2
# 264 "data/maps/DaycareVolcano/scripts.pory"
	case 21, FuecocoInCaveTrigger_4
# 286 "data/maps/DaycareVolcano/scripts.pory"
	case 20, FuecocoInCaveTrigger_5
# 306 "data/maps/DaycareVolcano/scripts.pory"
	case 22, FuecocoInCaveTrigger_6
	return

FuecocoInCaveTrigger_4:
# 265 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, CyndaquilInCaveTrigger_Movement_0
# 266 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Fuecoco, CyndaquilInCaveTrigger_Movement_1
# 267 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Fuecoco
# 268 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 269 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 270 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_2, MSGBOX_AUTOCLOSE
# 271 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 272 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_FUECOCO, 25, move1 = MOVE_SNARL, move2 = MOVE_YAWN, move3 = MOVE_INCINERATE, move4 = MOVE_CURSE
# 273 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 274 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 275 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FuecocoInCaveTrigger_7
	return

FuecocoInCaveTrigger_5:
# 287 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, CyndaquilInCaveTrigger_Movement_0
# 288 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 289 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 290 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_2, MSGBOX_AUTOCLOSE
# 291 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 292 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_FUECOCO, 25, move1 = MOVE_SNARL, move2 = MOVE_YAWN, move3 = MOVE_INCINERATE, move4 = MOVE_CURSE
# 293 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 294 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 295 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FuecocoInCaveTrigger_9
	return

FuecocoInCaveTrigger_6:
# 307 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, CyndaquilInCaveTrigger_Movement_0
# 308 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Fuecoco, FuecocoInCaveTrigger_Movement_0
# 309 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Fuecoco
# 310 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 311 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 312 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_2, MSGBOX_AUTOCLOSE
# 313 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 314 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_FUECOCO, 25, move1 = MOVE_SNARL, move2 = MOVE_YAWN, move3 = MOVE_INCINERATE, move4 = MOVE_CURSE
# 315 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 316 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 317 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FuecocoInCaveTrigger_11
	return

FuecocoInCaveTrigger_7:
# 277 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 278 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 279 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_3, MSGBOX_DEFAULT
# 280 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_FUECOCO_BATTLE
# 281 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 282 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 283 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

FuecocoInCaveTrigger_9:
# 297 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 298 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 299 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_3, MSGBOX_DEFAULT
# 300 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_FUECOCO_BATTLE
# 301 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 302 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 303 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

FuecocoInCaveTrigger_11:
# 319 "data/maps/DaycareVolcano/scripts.pory"
	speakername FuecocoInCave_Text_0
# 320 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_FUECOCO, EMOTE_NORMAL
# 321 "data/maps/DaycareVolcano/scripts.pory"
	msgbox FuecocoInCave_Text_3, MSGBOX_DEFAULT
# 322 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_FUECOCO_BATTLE
# 323 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 324 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 325 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


CombuskenInCave::
# 333 "data/maps/DaycareVolcano/scripts.pory"
	lock
# 334 "data/maps/DaycareVolcano/scripts.pory"
	faceplayer
# 335 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_set FLAG_COMBUSKEN_BATTLE, CombuskenInCave_1
# 347 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Combusken, CyndaquilInCave_Movement_0
# 348 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Combusken
# 349 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 350 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Combusken, Common_Movement_ExclamationMark
# 351 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Combusken
# 352 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 353 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 354 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 355 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_2, MSGBOX_AUTOCLOSE
# 356 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 357 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 358 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 359 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 360 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CombuskenInCave_4
	return

CombuskenInCave_1:
# 337 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 338 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 339 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_1, MSGBOX_DEFAULT
# 340 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 341 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 342 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

CombuskenInCave_4:
# 362 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 363 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 364 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_3, MSGBOX_DEFAULT
# 365 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_COMBUSKEN_BATTLE
# 366 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 367 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 368 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


CombuskenInCaveTrigger::
# 376 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_unset FLAG_COMBUSKEN_BATTLE, CombuskenInCaveTrigger_1
	return

CombuskenInCaveTrigger_1:
# 378 "data/maps/DaycareVolcano/scripts.pory"
	special PlayTrainerEncounterMusic
# 379 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Combusken, Common_Movement_ExclamationMark
# 380 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Combusken
# 381 "data/maps/DaycareVolcano/scripts.pory"
	delay 60
# 382 "data/maps/DaycareVolcano/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 383 "data/maps/DaycareVolcano/scripts.pory"
	switch VAR_TEMP_1
# 385 "data/maps/DaycareVolcano/scripts.pory"
	case 6, CombuskenInCaveTrigger_4
# 405 "data/maps/DaycareVolcano/scripts.pory"
	case 7, CombuskenInCaveTrigger_5
# 427 "data/maps/DaycareVolcano/scripts.pory"
	case 8, CombuskenInCaveTrigger_6
	return

CombuskenInCaveTrigger_4:
# 386 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, VulpixInCaveTrigger_Movement_0
# 387 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 388 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 389 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_2, MSGBOX_AUTOCLOSE
# 390 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 391 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 392 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 393 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 394 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CombuskenInCaveTrigger_7
	return

CombuskenInCaveTrigger_5:
# 406 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, VulpixInCaveTrigger_Movement_0
# 407 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Combusken, VulpixInCaveTrigger_Movement_1
# 408 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Combusken
# 409 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 410 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 411 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_2, MSGBOX_AUTOCLOSE
# 412 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 413 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 414 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 415 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 416 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CombuskenInCaveTrigger_9
	return

CombuskenInCaveTrigger_6:
# 428 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, VulpixInCaveTrigger_Movement_0
# 429 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Combusken, CombuskenInCaveTrigger_Movement_0
# 430 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Combusken
# 431 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 432 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 433 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_2, MSGBOX_AUTOCLOSE
# 434 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 435 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_COMBUSKEN, 25
# 436 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 437 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 438 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CombuskenInCaveTrigger_11
	return

CombuskenInCaveTrigger_7:
# 396 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 397 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 398 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_3, MSGBOX_DEFAULT
# 399 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_COMBUSKEN_BATTLE
# 400 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 401 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 402 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

CombuskenInCaveTrigger_9:
# 418 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 419 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 420 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_3, MSGBOX_DEFAULT
# 421 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_COMBUSKEN_BATTLE
# 422 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 423 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 424 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

CombuskenInCaveTrigger_11:
# 440 "data/maps/DaycareVolcano/scripts.pory"
	speakername CombuskenInCave_Text_0
# 441 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_COMBUSKEN, EMOTE_NORMAL
# 442 "data/maps/DaycareVolcano/scripts.pory"
	msgbox CombuskenInCave_Text_3, MSGBOX_DEFAULT
# 443 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_COMBUSKEN_BATTLE
# 444 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 445 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 446 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


BattleVsArcanine::
# 454 "data/maps/DaycareVolcano/scripts.pory"
	goto_if_set FLAG_TRANS_ARCANINE, BattleVsArcanine_2
# 458 "data/maps/DaycareVolcano/scripts.pory"
	lock
# 459 "data/maps/DaycareVolcano/scripts.pory"
	playbgm MUS_DUMMY, FALSE
# 460 "data/maps/DaycareVolcano/scripts.pory"
	playmoncry SPECIES_ARCANINE, CRY_MODE_NORMAL
# 461 "data/maps/DaycareVolcano/scripts.pory"
	waitmoncry
# 462 "data/maps/DaycareVolcano/scripts.pory"
	playse SE_PIN
# 463 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 464 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement LOCALID_PLAYER
# 465 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, CyndaquilInCaveTrigger_Movement_0
# 466 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement LOCALID_PLAYER
# 467 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsArcanine_Movement_0
# 468 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement LOCALID_PLAYER
# 469 "data/maps/DaycareVolcano/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsArcanine_Movement_1
# 470 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement LOCALID_PLAYER
# 471 "data/maps/DaycareVolcano/scripts.pory"
	playse SE_LEDGE
# 472 "data/maps/DaycareVolcano/scripts.pory"
	playse SE_LEDGE
# 473 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Arcanine, BattleVsArcanine_Movement_2
# 474 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Arcanine
# 475 "data/maps/DaycareVolcano/scripts.pory"
	playbgm MUS_PMD_BOSS_INTRO, FALSE
# 476 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_ARCANINE, EMOTE_ANGRY
# 477 "data/maps/DaycareVolcano/scripts.pory"
	speakername BattleVsArcanine_Text_0
# 478 "data/maps/DaycareVolcano/scripts.pory"
	msgbox BattleVsArcanine_Text_1, MSGBOX_AUTOCLOSE
# 479 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 480 "data/maps/DaycareVolcano/scripts.pory"
	setwildbattle SPECIES_ARCANINE, 25, move1 = MOVE_FLAME_WHEEL, move2 = MOVE_BITE, move3 = MOVE_AERIAL_ACE, move4 = MOVE_FLAME_CHARGE, ability = 3
# 481 "data/maps/DaycareVolcano/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0, 1, 0
# 482 "data/maps/DaycareVolcano/scripts.pory"
	dowildbattle
# 483 "data/maps/DaycareVolcano/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 484 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsArcanine_4
	return

BattleVsArcanine_2:
	end

BattleVsArcanine_4:
# 486 "data/maps/DaycareVolcano/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 487 "data/maps/DaycareVolcano/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 488 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_TRANS_ARCANINE
# 489 "data/maps/DaycareVolcano/scripts.pory"
	delay 15
# 490 "data/maps/DaycareVolcano/scripts.pory"
	dittotransform SPECIES_ARCANINE
# 491 "data/maps/DaycareVolcano/scripts.pory"
	playse MUS_LEVEL_UP
# 492 "data/maps/DaycareVolcano/scripts.pory"
	msgbox BattleVsArcanine_Text_2, MSGBOX_DEFAULT
# 493 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 494 "data/maps/DaycareVolcano/scripts.pory"
	dittotransform VAR_TEMP_0
# 495 "data/maps/DaycareVolcano/scripts.pory"
	givemon SPECIES_ARCANINE, 25, move1 = MOVE_FIRE_FANG, move2 = MOVE_BITE, move3 = MOVE_AERIAL_ACE, move4 = MOVE_THUNDER_FANG
# 496 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 497 "data/maps/DaycareVolcano/scripts.pory"
	speakername BattleVsArcanine_Text_0
# 498 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_ARCANINE, EMOTE_NORMAL
# 499 "data/maps/DaycareVolcano/scripts.pory"
	msgbox BattleVsArcanine_Text_3, MSGBOX_AUTOCLOSE
# 500 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 501 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 502 "data/maps/DaycareVolcano/scripts.pory"
	playse SE_LEDGE
# 503 "data/maps/DaycareVolcano/scripts.pory"
	playse SE_LEDGE
# 504 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Arcanine, BattleVsArcanine_Movement_3
# 505 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Arcanine
# 506 "data/maps/DaycareVolcano/scripts.pory"
	applymovement Arcanine, BattleVsArcanine_Movement_4
# 507 "data/maps/DaycareVolcano/scripts.pory"
	waitmovement Arcanine
# 508 "data/maps/DaycareVolcano/scripts.pory"
	fadenewbgm MUS_PMD_VOLCANO
# 509 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


ChanseyDaycareVolcano::
# 515 "data/maps/DaycareVolcano/scripts.pory"
	lock
# 516 "data/maps/DaycareVolcano/scripts.pory"
	faceplayer
# 517 "data/maps/DaycareVolcano/scripts.pory"
	speakername ChanseyDaycareVolcano_Text_0
# 518 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 519 "data/maps/DaycareVolcano/scripts.pory"
	msgbox ChanseyDaycareVolcano_Text_1, MSGBOX_DEFAULT
# 520 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 521 "data/maps/DaycareVolcano/scripts.pory"
	msgbox ChanseyDaycareVolcano_Text_2, MSGBOX_YESNO
# 522 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 523 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycareVolcano_1
# 553 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 554 "data/maps/DaycareVolcano/scripts.pory"
	msgbox ChanseyDaycareVolcano_Text_5, MSGBOX_AUTOCLOSE
# 555 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 556 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 557 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

ChanseyDaycareVolcano_1:
# 525 "data/maps/DaycareVolcano/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 526 "data/maps/DaycareVolcano/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycareVolcano_4
# 543 "data/maps/DaycareVolcano/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 544 "data/maps/DaycareVolcano/scripts.pory"
	msgbox ChanseyDaycareVolcano_Text_4, MSGBOX_AUTOCLOSE
# 545 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 546 "data/maps/DaycareVolcano/scripts.pory"
	removefieldmugshot
# 547 "data/maps/DaycareVolcano/scripts.pory"
	release
	end

ChanseyDaycareVolcano_4:
# 528 "data/maps/DaycareVolcano/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 529 "data/maps/DaycareVolcano/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 530 "data/maps/DaycareVolcano/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 531 "data/maps/DaycareVolcano/scripts.pory"
	playfanfare MUS_HEAL
# 532 "data/maps/DaycareVolcano/scripts.pory"
	waitfanfare
# 533 "data/maps/DaycareVolcano/scripts.pory"
	special HealPlayerParty
# 534 "data/maps/DaycareVolcano/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 535 "data/maps/DaycareVolcano/scripts.pory"
	msgbox ChanseyDaycareVolcano_Text_3, MSGBOX_AUTOCLOSE
# 536 "data/maps/DaycareVolcano/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 537 "data/maps/DaycareVolcano/scripts.pory"
	waitmessage
# 538 "data/maps/DaycareVolcano/scripts.pory"
	release
	end


SetArcanineRespawn::
# 564 "data/maps/DaycareVolcano/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_VOLCANO_1
	end


# 27 "data/maps/DaycareVolcano/scripts.pory"
CyndaquilInCave_Movement_0:
# 27 "data/maps/DaycareVolcano/scripts.pory"
	face_player
	step_end

# 66 "data/maps/DaycareVolcano/scripts.pory"
CyndaquilInCaveTrigger_Movement_0:
# 66 "data/maps/DaycareVolcano/scripts.pory"
	face_up
	step_end

# 67 "data/maps/DaycareVolcano/scripts.pory"
CyndaquilInCaveTrigger_Movement_1:
# 67 "data/maps/DaycareVolcano/scripts.pory"
	walk_down
	step_end

# 166 "data/maps/DaycareVolcano/scripts.pory"
VulpixInCaveTrigger_Movement_0:
# 166 "data/maps/DaycareVolcano/scripts.pory"
	face_left
	step_end

# 188 "data/maps/DaycareVolcano/scripts.pory"
VulpixInCaveTrigger_Movement_1:
# 188 "data/maps/DaycareVolcano/scripts.pory"
	walk_right
	step_end

# 308 "data/maps/DaycareVolcano/scripts.pory"
FuecocoInCaveTrigger_Movement_0:
# 308 "data/maps/DaycareVolcano/scripts.pory"
	walk_down
# 308 "data/maps/DaycareVolcano/scripts.pory"
	walk_down
	step_end

# 429 "data/maps/DaycareVolcano/scripts.pory"
CombuskenInCaveTrigger_Movement_0:
# 429 "data/maps/DaycareVolcano/scripts.pory"
	walk_right
# 429 "data/maps/DaycareVolcano/scripts.pory"
	walk_right
	step_end

# 467 "data/maps/DaycareVolcano/scripts.pory"
BattleVsArcanine_Movement_0:
# 467 "data/maps/DaycareVolcano/scripts.pory"
	lock_facing_direction
	step_end

# 469 "data/maps/DaycareVolcano/scripts.pory"
BattleVsArcanine_Movement_1:
# 469 "data/maps/DaycareVolcano/scripts.pory"
	walk_fast_down
	step_end

# 473 "data/maps/DaycareVolcano/scripts.pory"
BattleVsArcanine_Movement_2:
# 473 "data/maps/DaycareVolcano/scripts.pory"
	jump_2_down
# 473 "data/maps/DaycareVolcano/scripts.pory"
	jump_2_down
	step_end

# 504 "data/maps/DaycareVolcano/scripts.pory"
BattleVsArcanine_Movement_3:
# 504 "data/maps/DaycareVolcano/scripts.pory"
	jump_2_up
# 504 "data/maps/DaycareVolcano/scripts.pory"
	jump_2_up
	step_end

# 506 "data/maps/DaycareVolcano/scripts.pory"
BattleVsArcanine_Movement_4:
# 506 "data/maps/DaycareVolcano/scripts.pory"
	walk_in_place_down
	step_end

CyndaquilInCave_Text_0:
# 17 "data/maps/DaycareVolcano/scripts.pory"
	.string "Cyndaquil$"

CyndaquilInCave_Text_1:
# 19 "data/maps/DaycareVolcano/scripts.pory"
	.string "Go on!\nSee for yourself.$"

CyndaquilInCave_Text_2:
# 35 "data/maps/DaycareVolcano/scripts.pory"
	.string "The boss is so strong.\nHe must know how to gain EXP!$"

VulpixInCave_Text_0:
# 117 "data/maps/DaycareVolcano/scripts.pory"
	.string "Vulpix$"

VulpixInCave_Text_1:
# 119 "data/maps/DaycareVolcano/scripts.pory"
	.string "Someone once told me there's a\nplace where Vulpix live on snowy\lmountains... that sounds nice.$"

VulpixInCave_Text_2:
# 135 "data/maps/DaycareVolcano/scripts.pory"
	.string "Can't take the heat?\n$"

VulpixInCave_Text_3:
# 144 "data/maps/DaycareVolcano/scripts.pory"
	.string "Neither can I.\nIt's hot in here.$"

FuecocoInCave_Text_0:
# 217 "data/maps/DaycareVolcano/scripts.pory"
	.string "Fuecoco$"

FuecocoInCave_Text_1:
# 219 "data/maps/DaycareVolcano/scripts.pory"
	.string "At least it doesn't lag here in\nHoenn...$"

FuecocoInCave_Text_2:
# 235 "data/maps/DaycareVolcano/scripts.pory"
	.string "I joined this group to fit in!\n$"

FuecocoInCave_Text_3:
# 244 "data/maps/DaycareVolcano/scripts.pory"
	.string "No one here has even heard of\nPaldea...$"

CombuskenInCave_Text_0:
# 337 "data/maps/DaycareVolcano/scripts.pory"
	.string "Combusken$"

CombuskenInCave_Text_1:
# 339 "data/maps/DaycareVolcano/scripts.pory"
	.string "Ran out of steam.\n$"

CombuskenInCave_Text_2:
# 355 "data/maps/DaycareVolcano/scripts.pory"
	.string "I've heard the boss is so fast\nhe can gain EXP just by running\laround the Daycare!$"

CombuskenInCave_Text_3:
# 364 "data/maps/DaycareVolcano/scripts.pory"
	.string "Guess I should take a lap.\n$"

BattleVsArcanine_Text_0:
# 477 "data/maps/DaycareVolcano/scripts.pory"
	.string "Arcanine$"

BattleVsArcanine_Text_1:
# 478 "data/maps/DaycareVolcano/scripts.pory"
	.string "Aha!\pA Water_type challenger.\pYou must be strong if you battled\nyour way through my volcano.\pI see how your spirit burns bright.\pMaybe taking you down will grant me\nthe EXP I am looking for.\pLet me test your flame!\n$"

BattleVsArcanine_Text_2:
# 492 "data/maps/DaycareVolcano/scripts.pory"
	.string "You have gained the ability to\ntransform into Arcanine!$"

BattleVsArcanine_Text_3:
# 499 "data/maps/DaycareVolcano/scripts.pory"
	.string "That was a clever trick you pulled\nby transforming into a Rock_type.\pI lure Water_types into the volcano\nunder the guise that they have\lan advantage.\pThe intense fire here actually\ngives me the advantage.\pThis way I have a greater chance\nto earn EXP.\pMaybe I'm insecure about my\nabilities...\p...\pExcuse me.\pI meant to say...\pCarry yourself with honor.\pDon't soil my good name.\pMaybe you will unlock the secret\nto gain EXP.$"

ChanseyDaycareVolcano_Text_0:
# 517 "data/maps/DaycareVolcano/scripts.pory"
	.string "Chansey$"

ChanseyDaycareVolcano_Text_1:
# 519 "data/maps/DaycareVolcano/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycareVolcano_Text_2:
# 521 "data/maps/DaycareVolcano/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycareVolcano_Text_3:
# 535 "data/maps/DaycareVolcano/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycareVolcano_Text_4:
# 544 "data/maps/DaycareVolcano/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycareVolcano_Text_5:
# 554 "data/maps/DaycareVolcano/scripts.pory"
	.string "Oh, okay then.$"
