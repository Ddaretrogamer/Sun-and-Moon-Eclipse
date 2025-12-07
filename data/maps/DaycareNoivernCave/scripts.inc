DaycareNoivernCave_MapScripts::
	.byte 0


GastlyDialog::
# 6 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 7 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 8 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername GastlyDialog_Text_0
# 9 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_GASTLY, EMOTE_NORMAL
# 10 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox GastlyDialog_Text_1, MSGBOX_NPC
# 11 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 12 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 13 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


HaunterDialog::
# 18 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 19 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 20 "data/maps/DaycareNoivernCave/scripts.pory"
	playse SE_PIN
# 21 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 22 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement LOCALID_PLAYER
# 23 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername HaunterDialog_Text_0
# 24 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_HAUNTER, EMOTE_NORMAL
# 25 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox HaunterDialog_Text_1, MSGBOX_NPC
# 26 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 27 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 28 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


GengarDialog::
# 33 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 34 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_unset FLAG_GENGAR_EGG, GengarDialog_1
# 54 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Gengar, GengarDialog_Movement_0
# 55 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Gengar
# 56 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername GengarDialog_Text_0
# 57 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_GENGAR, EMOTE_NORMAL
# 58 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox GengarDialog_Text_2, MSGBOX_DEFAULT
# 59 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 60 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 61 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

GengarDialog_1:
# 36 "data/maps/DaycareNoivernCave/scripts.pory"
	playse SE_PIN
# 37 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Gengar, GengarDialog_Movement_0
# 38 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Gengar
# 39 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Gengar, Common_Movement_ExclamationMark
# 40 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Gengar
# 41 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername GengarDialog_Text_0
# 42 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_GENGAR, EMOTE_NORMAL
# 43 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox GengarDialog_Text_1, MSGBOX_DEFAULT
# 44 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 45 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 46 "data/maps/DaycareNoivernCave/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 47 "data/maps/DaycareNoivernCave/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 48 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_GENGAR_EGG
# 49 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 50 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


LitwickDialog::
# 67 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_unset FLAG_LITWICK_EGG, LitwickDialog_1
# 104 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 105 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 106 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername LitwickDialog_Text_0
# 107 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_LITWICK, EMOTE_NORMAL
# 108 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox LitwickDialog_Text_4, MSGBOX_DEFAULT
# 109 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 110 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 111 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

LitwickDialog_1:
# 69 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_set FLAG_TRANS_NOIVERN, LitwickDialog_4
# 91 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 92 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 93 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername LitwickDialog_Text_0
# 94 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_LITWICK, EMOTE_NORMAL
# 95 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox LitwickDialog_Text_3, MSGBOX_DEFAULT
# 96 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 97 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 98 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

LitwickDialog_4:
# 71 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 72 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 73 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername LitwickDialog_Text_0
# 74 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_LITWICK, EMOTE_NORMAL
# 75 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox LitwickDialog_Text_1, MSGBOX_DEFAULT
# 76 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 77 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 78 "data/maps/DaycareNoivernCave/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 79 "data/maps/DaycareNoivernCave/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 80 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_LITWICK_EGG
# 81 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername LitwickDialog_Text_0
# 82 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_LITWICK, EMOTE_NORMAL
# 83 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox LitwickDialog_Text_2, MSGBOX_DEFAULT
# 84 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 85 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 86 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


MawileInCave::
# 117 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 118 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 119 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_set FLAG_MAWILE_BATTLE, MawileInCave_1
# 131 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Mawile, GengarDialog_Movement_0
# 132 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Mawile
# 133 "data/maps/DaycareNoivernCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 134 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Mawile, Common_Movement_ExclamationMark
# 135 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Mawile
# 136 "data/maps/DaycareNoivernCave/scripts.pory"
	delay 60
# 137 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername MawileInCave_Text_0
# 138 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_MAWILE, EMOTE_NORMAL
# 139 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox MawileInCave_Text_2, MSGBOX_AUTOCLOSE
# 140 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 141 "data/maps/DaycareNoivernCave/scripts.pory"
	setwildbattle SPECIES_MAWILE, 25, move1 = MOVE_SWORDS_DANCE, move2 = MOVE_PLAY_ROUGH, move3 = MOVE_SUCKER_PUNCH, move4 = MOVE_THUNDER_PUNCH
# 142 "data/maps/DaycareNoivernCave/scripts.pory"
	dowildbattle
# 143 "data/maps/DaycareNoivernCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 144 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MawileInCave_4
	return

MawileInCave_1:
# 121 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername MawileInCave_Text_0
# 122 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_MAWILE, EMOTE_NORMAL
# 123 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox MawileInCave_Text_1, MSGBOX_DEFAULT
# 124 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 125 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 126 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

MawileInCave_4:
# 146 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername MawileInCave_Text_0
# 147 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_MAWILE, EMOTE_NORMAL
# 148 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox MawileInCave_Text_3, MSGBOX_DEFAULT
# 149 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_MAWILE_BATTLE
# 150 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 151 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 152 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


MawileInCaveTrigger::
# 159 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_unset FLAG_MAWILE_BATTLE, MawileInCaveTrigger_1
	return

MawileInCaveTrigger_1:
# 161 "data/maps/DaycareNoivernCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 162 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Mawile, Common_Movement_ExclamationMark
# 163 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Mawile
# 164 "data/maps/DaycareNoivernCave/scripts.pory"
	delay 60
# 165 "data/maps/DaycareNoivernCave/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 166 "data/maps/DaycareNoivernCave/scripts.pory"
	switch VAR_TEMP_2
# 168 "data/maps/DaycareNoivernCave/scripts.pory"
	case 11, MawileInCaveTrigger_4
# 190 "data/maps/DaycareNoivernCave/scripts.pory"
	case 10, MawileInCaveTrigger_5
	return

MawileInCaveTrigger_4:
# 169 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, MawileInCaveTrigger_Movement_0
# 170 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Mawile, MawileInCaveTrigger_Movement_1
# 171 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Mawile
# 172 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername MawileInCave_Text_0
# 173 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_MAWILE, EMOTE_NORMAL
# 174 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox MawileInCave_Text_2, MSGBOX_AUTOCLOSE
# 175 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 176 "data/maps/DaycareNoivernCave/scripts.pory"
	setwildbattle SPECIES_MAWILE, 25, move1 = MOVE_SWORDS_DANCE, move2 = MOVE_PLAY_ROUGH, move3 = MOVE_SUCKER_PUNCH, move4 = MOVE_THUNDER_PUNCH
# 177 "data/maps/DaycareNoivernCave/scripts.pory"
	dowildbattle
# 178 "data/maps/DaycareNoivernCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 179 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MawileInCaveTrigger_6
	return

MawileInCaveTrigger_5:
# 191 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, MawileInCaveTrigger_Movement_0
# 192 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername MawileInCave_Text_0
# 193 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_MAWILE, EMOTE_NORMAL
# 194 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox MawileInCave_Text_2, MSGBOX_AUTOCLOSE
# 195 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 196 "data/maps/DaycareNoivernCave/scripts.pory"
	setwildbattle SPECIES_MAWILE, 25, move1 = MOVE_SWORDS_DANCE, move2 = MOVE_PLAY_ROUGH, move3 = MOVE_SUCKER_PUNCH, move4 = MOVE_THUNDER_PUNCH
# 197 "data/maps/DaycareNoivernCave/scripts.pory"
	dowildbattle
# 198 "data/maps/DaycareNoivernCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 199 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MawileInCaveTrigger_8
	return

MawileInCaveTrigger_6:
# 181 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername MawileInCave_Text_0
# 182 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_MAWILE, EMOTE_NORMAL
# 183 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox MawileInCave_Text_3, MSGBOX_DEFAULT
# 184 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_MAWILE_BATTLE
# 185 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 186 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 187 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

MawileInCaveTrigger_8:
# 201 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername MawileInCave_Text_0
# 202 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_MAWILE, EMOTE_NORMAL
# 203 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox MawileInCave_Text_3, MSGBOX_DEFAULT
# 204 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_MAWILE_BATTLE
# 205 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 206 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 207 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


DuskullInCave::
# 215 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 216 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 217 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_set FLAG_DUSKULL_BATTLE, DuskullInCave_1
# 229 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Duskull, GengarDialog_Movement_0
# 230 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Duskull
# 231 "data/maps/DaycareNoivernCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 232 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Duskull, Common_Movement_ExclamationMark
# 233 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Duskull
# 234 "data/maps/DaycareNoivernCave/scripts.pory"
	delay 60
# 235 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername DuskullInCave_Text_0
# 236 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_DUSKULL, EMOTE_NORMAL
# 237 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox DuskullInCave_Text_2, MSGBOX_AUTOCLOSE
# 238 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 239 "data/maps/DaycareNoivernCave/scripts.pory"
	setwildbattle SPECIES_DUSKULL, 25
# 240 "data/maps/DaycareNoivernCave/scripts.pory"
	dowildbattle
# 241 "data/maps/DaycareNoivernCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 242 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DuskullInCave_4
	return

DuskullInCave_1:
# 219 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername DuskullInCave_Text_0
# 220 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_DUSKULL, EMOTE_NORMAL
# 221 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox DuskullInCave_Text_1, MSGBOX_DEFAULT
# 222 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 223 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 224 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

DuskullInCave_4:
# 244 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername DuskullInCave_Text_0
# 245 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_DUSKULL, EMOTE_NORMAL
# 246 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox DuskullInCave_Text_1, MSGBOX_DEFAULT
# 247 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_DUSKULL_BATTLE
# 248 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 249 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 250 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


DuskullInCaveTrigger::
# 257 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_unset FLAG_DUSKULL_BATTLE, DuskullInCaveTrigger_1
	return

DuskullInCaveTrigger_1:
# 259 "data/maps/DaycareNoivernCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 260 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Duskull, Common_Movement_ExclamationMark
# 261 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Duskull
# 262 "data/maps/DaycareNoivernCave/scripts.pory"
	delay 60
# 263 "data/maps/DaycareNoivernCave/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 264 "data/maps/DaycareNoivernCave/scripts.pory"
	switch VAR_TEMP_1
# 266 "data/maps/DaycareNoivernCave/scripts.pory"
	case 15, DuskullInCaveTrigger_4
	return

DuskullInCaveTrigger_4:
# 267 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, DuskullInCaveTrigger_Movement_0
# 268 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Duskull, DuskullInCaveTrigger_Movement_1
# 269 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Duskull
# 270 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername DuskullInCave_Text_0
# 271 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_DUSKULL, EMOTE_NORMAL
# 272 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox DuskullInCave_Text_2, MSGBOX_AUTOCLOSE
# 273 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 274 "data/maps/DaycareNoivernCave/scripts.pory"
	setwildbattle SPECIES_DUSKULL, 25
# 275 "data/maps/DaycareNoivernCave/scripts.pory"
	dowildbattle
# 276 "data/maps/DaycareNoivernCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 277 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DuskullInCaveTrigger_5
	return

DuskullInCaveTrigger_5:
# 279 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername DuskullInCave_Text_0
# 280 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_DUSKULL, EMOTE_NORMAL
# 281 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox DuskullInCave_Text_1, MSGBOX_DEFAULT
# 282 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_DUSKULL_BATTLE
# 283 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 284 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 285 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


BattleVsNoivern::
# 294 "data/maps/DaycareNoivernCave/scripts.pory"
	goto_if_set FLAG_TRANS_NOIVERN, BattleVsNoivern_2
# 298 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 299 "data/maps/DaycareNoivernCave/scripts.pory"
	playbgm MUS_NONE, FALSE
# 300 "data/maps/DaycareNoivernCave/scripts.pory"
	playmoncry SPECIES_NOIVERN, CRY_MODE_NORMAL
# 301 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmoncry
# 302 "data/maps/DaycareNoivernCave/scripts.pory"
	playse SE_PIN
# 303 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 304 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement LOCALID_PLAYER
# 305 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, MawileInCaveTrigger_Movement_0
# 306 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement LOCALID_PLAYER
# 307 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsNoivern_Movement_0
# 308 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement LOCALID_PLAYER
# 309 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsNoivern_Movement_1
# 310 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement LOCALID_PLAYER
# 311 "data/maps/DaycareNoivernCave/scripts.pory"
	playse SE_M_SCREECH
# 312 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Noivern, BattleVsNoivern_Movement_2
# 313 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Noivern
# 314 "data/maps/DaycareNoivernCave/scripts.pory"
	playbgm MUS_PMD_BOSS_INTRO, FALSE
# 315 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername BattleVsNoivern_Text_0
# 316 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_NOIVERN, EMOTE_ANGRY
# 317 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox BattleVsNoivern_Text_1, MSGBOX_AUTOCLOSE
# 318 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 319 "data/maps/DaycareNoivernCave/scripts.pory"
	setwildbattle SPECIES_NOIVERN, 25, move1 = MOVE_HURRICANE, move2 = MOVE_BOOMBURST, move3 = MOVE_DRAGON_PULSE, move4 = MOVE_DOUBLE_TEAM
# 320 "data/maps/DaycareNoivernCave/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 4, 4, 0, 2, 0, 0
# 321 "data/maps/DaycareNoivernCave/scripts.pory"
	dowildbattle
# 322 "data/maps/DaycareNoivernCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 323 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsNoivern_4
	return

BattleVsNoivern_2:
	end

BattleVsNoivern_4:
# 325 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 326 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Noivern, Common_Movement_ExclamationMark
# 327 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Noivern
# 328 "data/maps/DaycareNoivernCave/scripts.pory"
	playse SE_PIN
# 329 "data/maps/DaycareNoivernCave/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 330 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 331 "data/maps/DaycareNoivernCave/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 332 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_TRANS_NOIVERN
# 333 "data/maps/DaycareNoivernCave/scripts.pory"
	delay 30
# 334 "data/maps/DaycareNoivernCave/scripts.pory"
	dittotransform SPECIES_NOIVERN
# 335 "data/maps/DaycareNoivernCave/scripts.pory"
	playse MUS_LEVEL_UP
# 336 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox BattleVsNoivern_Text_2, MSGBOX_DEFAULT
# 337 "data/maps/DaycareNoivernCave/scripts.pory"
	waitse
# 338 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 339 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 340 "data/maps/DaycareNoivernCave/scripts.pory"
	dittotransform VAR_TEMP_0
# 341 "data/maps/DaycareNoivernCave/scripts.pory"
	givemon SPECIES_NOIVERN, 25, move1 = MOVE_AIR_CUTTER, move2 = MOVE_DRAGON_BREATH, move3 = MOVE_SUPERSONIC, move4 = MOVE_SUPER_FANG
# 342 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 343 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername BattleVsNoivern_Text_0
# 344 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_NOIVERN, EMOTE_NORMAL
# 345 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox BattleVsNoivern_Text_3, MSGBOX_AUTOCLOSE
# 346 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 347 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 348 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Noivern, BattleVsNoivern_Movement_3
# 349 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Noivern
# 350 "data/maps/DaycareNoivernCave/scripts.pory"
	applymovement Noivern, BattleVsNoivern_Movement_4
# 351 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmovement Noivern
# 352 "data/maps/DaycareNoivernCave/scripts.pory"
	fadenewbgm MUS_PMD_NOIVERNCAVE
# 353 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


ChanseyDaycareNoivern::
# 360 "data/maps/DaycareNoivernCave/scripts.pory"
	lock
# 361 "data/maps/DaycareNoivernCave/scripts.pory"
	faceplayer
# 362 "data/maps/DaycareNoivernCave/scripts.pory"
	speakername ChanseyDaycareNoivern_Text_0
# 363 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 364 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox ChanseyDaycareNoivern_Text_1, MSGBOX_DEFAULT
# 365 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 366 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox ChanseyDaycareNoivern_Text_2, MSGBOX_YESNO
# 367 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 368 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycareNoivern_1
# 398 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 399 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox ChanseyDaycareNoivern_Text_5, MSGBOX_AUTOCLOSE
# 400 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 401 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 402 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

ChanseyDaycareNoivern_1:
# 370 "data/maps/DaycareNoivernCave/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 371 "data/maps/DaycareNoivernCave/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycareNoivern_4
# 388 "data/maps/DaycareNoivernCave/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 389 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox ChanseyDaycareNoivern_Text_4, MSGBOX_AUTOCLOSE
# 390 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 391 "data/maps/DaycareNoivernCave/scripts.pory"
	removefieldmugshot
# 392 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end

ChanseyDaycareNoivern_4:
# 373 "data/maps/DaycareNoivernCave/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 374 "data/maps/DaycareNoivernCave/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 375 "data/maps/DaycareNoivernCave/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 376 "data/maps/DaycareNoivernCave/scripts.pory"
	playfanfare MUS_HEAL
# 377 "data/maps/DaycareNoivernCave/scripts.pory"
	waitfanfare
# 378 "data/maps/DaycareNoivernCave/scripts.pory"
	special HealPlayerParty
# 379 "data/maps/DaycareNoivernCave/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 380 "data/maps/DaycareNoivernCave/scripts.pory"
	msgbox ChanseyDaycareNoivern_Text_3, MSGBOX_AUTOCLOSE
# 381 "data/maps/DaycareNoivernCave/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 382 "data/maps/DaycareNoivernCave/scripts.pory"
	waitmessage
# 383 "data/maps/DaycareNoivernCave/scripts.pory"
	release
	end


SetNoivernRespawn::
# 409 "data/maps/DaycareNoivernCave/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_NOIVERN_CAVE
	end


# 37 "data/maps/DaycareNoivernCave/scripts.pory"
GengarDialog_Movement_0:
# 37 "data/maps/DaycareNoivernCave/scripts.pory"
	face_player
	step_end

# 169 "data/maps/DaycareNoivernCave/scripts.pory"
MawileInCaveTrigger_Movement_0:
# 169 "data/maps/DaycareNoivernCave/scripts.pory"
	face_up
	step_end

# 170 "data/maps/DaycareNoivernCave/scripts.pory"
MawileInCaveTrigger_Movement_1:
# 170 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_down
	step_end

# 267 "data/maps/DaycareNoivernCave/scripts.pory"
DuskullInCaveTrigger_Movement_0:
# 267 "data/maps/DaycareNoivernCave/scripts.pory"
	face_right
	step_end

# 268 "data/maps/DaycareNoivernCave/scripts.pory"
DuskullInCaveTrigger_Movement_1:
# 268 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_left
# 268 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_left
# 268 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_left
	step_end

# 307 "data/maps/DaycareNoivernCave/scripts.pory"
BattleVsNoivern_Movement_0:
# 307 "data/maps/DaycareNoivernCave/scripts.pory"
	lock_facing_direction
	step_end

# 309 "data/maps/DaycareNoivernCave/scripts.pory"
BattleVsNoivern_Movement_1:
# 309 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_down
	step_end

# 312 "data/maps/DaycareNoivernCave/scripts.pory"
BattleVsNoivern_Movement_2:
# 312 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_down
# 312 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_down
# 312 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_down
# 312 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_down
	step_end

# 348 "data/maps/DaycareNoivernCave/scripts.pory"
BattleVsNoivern_Movement_3:
# 348 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_up
# 348 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_up
# 348 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_up
# 348 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_fast_up
	step_end

# 350 "data/maps/DaycareNoivernCave/scripts.pory"
BattleVsNoivern_Movement_4:
# 350 "data/maps/DaycareNoivernCave/scripts.pory"
	walk_in_place_down
	step_end

GastlyDialog_Text_0:
# 8 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Rick$"

GastlyDialog_Text_1:
# 10 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "My trainer gave me this nickname...\nI'm not sure what it means.\pMy trainer is confusing...\pThey had just told me the were never\ngoing to give me up before dropping me\loff here.$"

HaunterDialog_Text_0:
# 23 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Haunter$"

HaunterDialog_Text_1:
# 25 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "BOO!$"

GengarDialog_Text_0:
# 41 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Gengar$"

GengarDialog_Text_1:
# 43 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "How did you manage to pass\nthrough that rock?\pMaybe you've got a bit of\nGhost_type in you.\pKekeh!\n$"

GengarDialog_Text_2:
# 58 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Back for more?\pI have nothing left for you.\pKekeh!\n$"

LitwickDialog_Text_0:
# 73 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Litwick$"

LitwickDialog_Text_1:
# 75 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Noivern is quite the challenge,\nisn't he?\pHere. Take this.\n$"

LitwickDialog_Text_2:
# 83 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "I know a Chansey will exchange\nit to heal your wounds.$"

LitwickDialog_Text_3:
# 95 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Careful, that bat is feisty!\n$"

LitwickDialog_Text_4:
# 108 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Noivern is quite the challenge,\nisn't he?$"

MawileInCave_Text_0:
# 121 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Mawile$"

MawileInCave_Text_1:
# 123 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Keep your guard up.\nA strong challenge is ahead.$"

MawileInCave_Text_2:
# 139 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Not many get this far...\nLet's see if you're clever or just lucky.$"

MawileInCave_Text_3:
# 148 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "You’ve got bite.\nMaybe we’re not so different.$"

DuskullInCave_Text_0:
# 219 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Duskull$"

DuskullInCave_Text_1:
# 221 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Even spirits respect strength.\pWander well, traveler.\n$"

DuskullInCave_Text_2:
# 237 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Not many dare to speak to me...\nYou must be bold.$"

BattleVsNoivern_Text_0:
# 315 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Noivern$"

BattleVsNoivern_Text_1:
# 317 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "You tread where echos rule.\pI've ruled over this cave since\nI bested my little brother as a\lNoibat.\pI hope you've come prepared.\pLet's see if you can keep up with\nthe speed of sound!$"

BattleVsNoivern_Text_2:
# 336 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "You have gained the ability to\ntransform into Noivern!$"

BattleVsNoivern_Text_3:
# 345 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Soar high gooey friend.\pYou'll need my flight to reach your\ndestination.\pYou near the end of your quest!\pTest out my flight by soaring down\nfrom the cliff near Wingull rather\l than taking the waterfall.$"

ChanseyDaycareNoivern_Text_0:
# 362 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Chansey$"

ChanseyDaycareNoivern_Text_1:
# 364 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycareNoivern_Text_2:
# 366 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycareNoivern_Text_3:
# 380 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycareNoivern_Text_4:
# 389 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycareNoivern_Text_5:
# 399 "data/maps/DaycareNoivernCave/scripts.pory"
	.string "Oh, okay then.$"
