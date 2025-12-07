DaycareEast_MapScripts::
# 2 "data/maps/DaycareEast/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareEast_OnTransition
	.byte 0


DaycareEast_OnTransition::
# 7 "data/maps/DaycareEast/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_EAST
	end


KrabbyDialog::
# 11 "data/maps/DaycareEast/scripts.pory"
	lock
# 12 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 13 "data/maps/DaycareEast/scripts.pory"
	speakername KrabbyDialog_Text_0
# 14 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_KRABBY, EMOTE_NORMAL
# 15 "data/maps/DaycareEast/scripts.pory"
	msgbox KrabbyDialog_Text_1, MSGBOX_NPC
# 16 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 17 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 18 "data/maps/DaycareEast/scripts.pory"
	release
	end


AlolanRaichuDialog::
# 23 "data/maps/DaycareEast/scripts.pory"
	lock
# 24 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 25 "data/maps/DaycareEast/scripts.pory"
	speakername AlolanRaichuDialog_Text_0
# 26 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_ALOLANRAICHU, EMOTE_NORMAL
# 27 "data/maps/DaycareEast/scripts.pory"
	msgbox AlolanRaichuDialog_Text_1, MSGBOX_DEFAULT
# 28 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 29 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 30 "data/maps/DaycareEast/scripts.pory"
	release
	end


SandyghastDialog::
# 35 "data/maps/DaycareEast/scripts.pory"
	lock
# 36 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 37 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_RHYHORN
	goto_if_eq SandyghastDialog_2
# 47 "data/maps/DaycareEast/scripts.pory"
	speakername SandyghastDialog_Text_0
# 48 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SANDYGHAST, EMOTE_NORMAL
# 49 "data/maps/DaycareEast/scripts.pory"
	msgbox SandyghastDialog_Text_2, MSGBOX_DEFAULT
# 50 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 51 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
SandyghastDialog_1:
# 53 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 54 "data/maps/DaycareEast/scripts.pory"
	release
	end

SandyghastDialog_2:
# 39 "data/maps/DaycareEast/scripts.pory"
	speakername SandyghastDialog_Text_0
# 40 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SANDYGHAST, EMOTE_HAPPY
# 41 "data/maps/DaycareEast/scripts.pory"
	msgbox SandyghastDialog_Text_1, MSGBOX_DEFAULT
# 42 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 43 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
	goto SandyghastDialog_1


DaycareEast_FindLuckyEgg::
# 59 "data/maps/DaycareEast/scripts.pory"
	finditem ITEM_LUCKY_EGG
	return


ShellosEastDialog::
# 63 "data/maps/DaycareEast/scripts.pory"
	lock
# 64 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 65 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_MARILL
	goto_if_eq ShellosEastDialog_2
# 72 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CHINCHOU
	goto_if_eq ShellosEastDialog_3
# 81 "data/maps/DaycareEast/scripts.pory"
	speakername ShellosEastDialog_Text_0
# 82 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SHELLOS, EMOTE_NORMAL
# 83 "data/maps/DaycareEast/scripts.pory"
	msgbox ShellosEastDialog_Text_3, MSGBOX_NPC
# 84 "data/maps/DaycareEast/scripts.pory"
	waitmessage
ShellosEastDialog_1:
# 86 "data/maps/DaycareEast/scripts.pory"
	release
	end

ShellosEastDialog_2:
# 67 "data/maps/DaycareEast/scripts.pory"
	speakername ShellosEastDialog_Text_0
# 68 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SHELLOS, EMOTE_HAPPY
# 69 "data/maps/DaycareEast/scripts.pory"
	msgbox ShellosEastDialog_Text_1, MSGBOX_NPC
# 70 "data/maps/DaycareEast/scripts.pory"
	waitmessage
	goto ShellosEastDialog_1

ShellosEastDialog_3:
# 74 "data/maps/DaycareEast/scripts.pory"
	speakername ShellosEastDialog_Text_0
# 75 "data/maps/DaycareEast/scripts.pory"
	msgbox ShellosEastDialog_Text_2, MSGBOX_NPC
# 76 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SHELLOS, EMOTE_HAPPY
# 77 "data/maps/DaycareEast/scripts.pory"
	waitmessage
	goto ShellosEastDialog_1


AlolanExeggutorDialog::
# 91 "data/maps/DaycareEast/scripts.pory"
	lock
# 92 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 93 "data/maps/DaycareEast/scripts.pory"
	speakername AlolanExeggutorDialog_Text_0
# 94 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_ALOLANEXEGGUTOR, EMOTE_NORMAL
# 95 "data/maps/DaycareEast/scripts.pory"
	msgbox AlolanExeggutorDialog_Text_1, MSGBOX_DEFAULT
# 96 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 97 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 98 "data/maps/DaycareEast/scripts.pory"
	release
	end


WingullDialog::
# 103 "data/maps/DaycareEast/scripts.pory"
	lock
# 104 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 105 "data/maps/DaycareEast/scripts.pory"
	speakername WingullDialog_Text_0
# 106 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_WINGULL, EMOTE_HAPPY
# 107 "data/maps/DaycareEast/scripts.pory"
	msgbox WingullDialog_Text_1, MSGBOX_DEFAULT
# 108 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 109 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 110 "data/maps/DaycareEast/scripts.pory"
	release
	end


RuffletDialog::
# 115 "data/maps/DaycareEast/scripts.pory"
	lock
# 116 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, RuffletDialog_Movement_0
# 117 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_eq RuffletDialog_7
RuffletDialog_5:
# 180 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_eq RuffletDialog_4
RuffletDialog_3:
# 247 "data/maps/DaycareEast/scripts.pory"
	speakername RuffletDialog_Text_0
# 248 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ANGRY
# 249 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_5, MSGBOX_DEFAULT
# 250 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 251 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 252 "data/maps/DaycareEast/scripts.pory"
	release
	end

RuffletDialog_1:
# 119 "data/maps/DaycareEast/scripts.pory"
	speakername RuffletDialog_Text_0
# 120 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ANGRY
# 121 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_1, MSGBOX_DEFAULT
# 122 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 123 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 124 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, Common_Movement_ExclamationMark
# 125 "data/maps/DaycareEast/scripts.pory"
	playse SE_PIN
# 126 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 127 "data/maps/DaycareEast/scripts.pory"
	waitmovement
# 128 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ELATED
# 129 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_2, MSGBOX_DEFAULT
# 130 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 131 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, Common_Movement_ExclamationMark
# 132 "data/maps/DaycareEast/scripts.pory"
	playse SE_PIN
# 133 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 134 "data/maps/DaycareEast/scripts.pory"
	waitmovement
# 135 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_3, MSGBOX_DEFAULT
# 136 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 137 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 138 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 139 "data/maps/DaycareEast/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 140 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 141 "data/maps/DaycareEast/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 142 "data/maps/DaycareEast/scripts.pory"
	speakername RuffletDialog_Text_0
# 143 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ELATED
# 144 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_4, MSGBOX_AUTOCLOSE
# 145 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 146 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 147 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, RuffletFlyAway
# 148 "data/maps/DaycareEast/scripts.pory"
	waitmovement 0
# 149 "data/maps/DaycareEast/scripts.pory"
	playse SE_LEDGE
# 151 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, RuffletDialog_Movement_1
# 155 "data/maps/DaycareEast/scripts.pory"
	waitmovement 0
# 156 "data/maps/DaycareEast/scripts.pory"
	playse SE_FALL
# 157 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, RuffletDialog_Movement_2
# 159 "data/maps/DaycareEast/scripts.pory"
	waitmovement 0
# 160 "data/maps/DaycareEast/scripts.pory"
	delay 30
# 162 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8004, 2
# 163 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8005, 6
# 164 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8006, 4
# 165 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8007, 4
# 166 "data/maps/DaycareEast/scripts.pory"
	special ShakeCamera
# 167 "data/maps/DaycareEast/scripts.pory"
	waitstate
# 168 "data/maps/DaycareEast/scripts.pory"
	delay 60
# 170 "data/maps/DaycareEast/scripts.pory"
	playse SE_BANG
# 171 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 172 "data/maps/DaycareEast/scripts.pory"
	delay 60
# 173 "data/maps/DaycareEast/scripts.pory"
	playmoncry SPECIES_SHARPEDO, CRY_MODE_NORMAL
# 174 "data/maps/DaycareEast/scripts.pory"
	waitmoncry
# 175 "data/maps/DaycareEast/scripts.pory"
	removeobject Rufflet
# 176 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_HIDE_RUFFLET
# 177 "data/maps/DaycareEast/scripts.pory"
	release
	end

RuffletDialog_2:
# 182 "data/maps/DaycareEast/scripts.pory"
	speakername RuffletDialog_Text_0
# 183 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ANGRY
# 184 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_1, MSGBOX_DEFAULT
# 185 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 186 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 187 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, Common_Movement_ExclamationMark
# 188 "data/maps/DaycareEast/scripts.pory"
	playse SE_PIN
# 189 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 190 "data/maps/DaycareEast/scripts.pory"
	waitmovement
# 191 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ELATED
# 192 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_2, MSGBOX_DEFAULT
# 193 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 194 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, Common_Movement_ExclamationMark
# 195 "data/maps/DaycareEast/scripts.pory"
	playse SE_PIN
# 196 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 197 "data/maps/DaycareEast/scripts.pory"
	waitmovement
# 198 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_3, MSGBOX_DEFAULT
# 199 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 200 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 201 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 202 "data/maps/DaycareEast/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 203 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 204 "data/maps/DaycareEast/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 205 "data/maps/DaycareEast/scripts.pory"
	speakername RuffletDialog_Text_0
# 206 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ELATED
# 207 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletDialog_Text_4, MSGBOX_AUTOCLOSE
# 208 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 209 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 210 "data/maps/DaycareEast/scripts.pory"
	applymovement LOCALID_PLAYER, RuffletDialog_Movement_3
# 211 "data/maps/DaycareEast/scripts.pory"
	waitmovement LOCALID_PLAYER
# 212 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, RuffletFlyAway
# 213 "data/maps/DaycareEast/scripts.pory"
	waitmovement 0
# 214 "data/maps/DaycareEast/scripts.pory"
	playse SE_LEDGE
# 216 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, RuffletDialog_Movement_1
# 220 "data/maps/DaycareEast/scripts.pory"
	waitmovement 0
# 221 "data/maps/DaycareEast/scripts.pory"
	playse SE_FALL
# 222 "data/maps/DaycareEast/scripts.pory"
	applymovement Rufflet, RuffletDialog_Movement_2
# 224 "data/maps/DaycareEast/scripts.pory"
	waitmovement 0
# 225 "data/maps/DaycareEast/scripts.pory"
	delay 30
# 227 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8004, 2
# 228 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8005, 6
# 229 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8006, 4
# 230 "data/maps/DaycareEast/scripts.pory"
	setvar VAR_0x8007, 4
# 231 "data/maps/DaycareEast/scripts.pory"
	special ShakeCamera
# 232 "data/maps/DaycareEast/scripts.pory"
	waitstate
# 233 "data/maps/DaycareEast/scripts.pory"
	delay 60
# 235 "data/maps/DaycareEast/scripts.pory"
	playse SE_BANG
# 236 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 237 "data/maps/DaycareEast/scripts.pory"
	delay 60
# 238 "data/maps/DaycareEast/scripts.pory"
	playmoncry SPECIES_SHARPEDO, CRY_MODE_NORMAL
# 239 "data/maps/DaycareEast/scripts.pory"
	waitmoncry
# 240 "data/maps/DaycareEast/scripts.pory"
	removeobject Rufflet
# 241 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_HIDE_RUFFLET
# 242 "data/maps/DaycareEast/scripts.pory"
	release
	end

RuffletDialog_4:
# 180 "data/maps/DaycareEast/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq RuffletDialog_2
	goto RuffletDialog_3

RuffletDialog_7:
# 117 "data/maps/DaycareEast/scripts.pory"
	compare VAR_FACING, DIR_SOUTH
	goto_if_ne RuffletDialog_1
	goto RuffletDialog_5


# 258 "data/maps/DaycareEast/scripts.pory"
RuffletFlyAway:
# 259 "data/maps/DaycareEast/scripts.pory"
	face_down
# 260 "data/maps/DaycareEast/scripts.pory"
	lock_facing_direction
# 261 "data/maps/DaycareEast/scripts.pory"
	walk_slow_up
# 261 "data/maps/DaycareEast/scripts.pory"
	walk_slow_up
# 262 "data/maps/DaycareEast/scripts.pory"
	delay_16
# 262 "data/maps/DaycareEast/scripts.pory"
	delay_16
# 263 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 263 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
	step_end

RuffletOnShore::
# 268 "data/maps/DaycareEast/scripts.pory"
	lock
# 269 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 270 "data/maps/DaycareEast/scripts.pory"
	speakername RuffletDialog_Text_0
# 271 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_RUFFLET, EMOTE_ELATED
# 272 "data/maps/DaycareEast/scripts.pory"
	msgbox RuffletOnShore_Text_0, MSGBOX_DEFAULT
# 273 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 274 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 275 "data/maps/DaycareEast/scripts.pory"
	release
	end


SlowpokeDialog::
# 280 "data/maps/DaycareEast/scripts.pory"
	lock
# 281 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 282 "data/maps/DaycareEast/scripts.pory"
	speakername SlowpokeDialog_Text_0
# 283 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SLOWPOKE, EMOTE_NORMAL
# 284 "data/maps/DaycareEast/scripts.pory"
	msgbox SlowpokeDialog_Text_1, MSGBOX_DEFAULT
# 285 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 286 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 287 "data/maps/DaycareEast/scripts.pory"
	release
	end


SharpedoDialog::
# 292 "data/maps/DaycareEast/scripts.pory"
	lock
# 293 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 294 "data/maps/DaycareEast/scripts.pory"
	goto_if_set FLAG_HIDE_RUFFLET, SharpedoDialog_1
# 314 "data/maps/DaycareEast/scripts.pory"
	speakername SharpedoDialog_Text_0
# 315 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SHARPEDO, EMOTE_NORMAL
# 316 "data/maps/DaycareEast/scripts.pory"
	msgbox SharpedoDialog_Text_3, MSGBOX_DEFAULT
# 317 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 318 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 319 "data/maps/DaycareEast/scripts.pory"
	release
	end

SharpedoDialog_1:
# 296 "data/maps/DaycareEast/scripts.pory"
	speakername SharpedoDialog_Text_0
# 297 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SHARPEDO, EMOTE_NORMAL
# 298 "data/maps/DaycareEast/scripts.pory"
	msgbox SharpedoDialog_Text_1, MSGBOX_DEFAULT
# 299 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 300 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 301 "data/maps/DaycareEast/scripts.pory"
	applymovement Sharpedo, ContestHall_Movement_Heart
# 302 "data/maps/DaycareEast/scripts.pory"
	speakername SharpedoDialog_Text_0
# 303 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_SHARPEDO, EMOTE_ELATED
# 304 "data/maps/DaycareEast/scripts.pory"
	playse SE_PIN
# 305 "data/maps/DaycareEast/scripts.pory"
	msgbox SharpedoDialog_Text_2, MSGBOX_DEFAULT
# 306 "data/maps/DaycareEast/scripts.pory"
	clearflag FLAG_SHOW_RUFFLET
# 307 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 308 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 309 "data/maps/DaycareEast/scripts.pory"
	release
	end


DaycareEastDittoOpenXforms::
# 325 "data/maps/DaycareEast/scripts.pory"
	lock
# 326 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 327 "data/maps/DaycareEast/scripts.pory"
	goto_if_set FLAG_DITTO_INTRO, DaycareEastDittoOpenXforms_1
# 367 "data/maps/DaycareEast/scripts.pory"
	speakername DaycareEastDittoOpenXforms_Text_1
# 368 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 369 "data/maps/DaycareEast/scripts.pory"
	msgbox DaycareEastDittoOpenXforms_Text_4, MSGBOX_DEFAULT
# 370 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 371 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 372 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 373 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 374 "data/maps/DaycareEast/scripts.pory"
	release
	end

DaycareEastDittoOpenXforms_1:
# 329 "data/maps/DaycareEast/scripts.pory"
	goto_if_set FLAG_XFORMS_TALKED_TO_DITTO, DaycareEastDittoOpenXforms_4
# 355 "data/maps/DaycareEast/scripts.pory"
	speakername DaycareEastDittoOpenXforms_Text_1
# 356 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 357 "data/maps/DaycareEast/scripts.pory"
	msgbox DaycareEastDittoOpenXforms_Text_3, MSGBOX_DEFAULT
# 358 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 359 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 360 "data/maps/DaycareEast/scripts.pory"
	release
	end

DaycareEastDittoOpenXforms_4:
# 331 "data/maps/DaycareEast/scripts.pory"
	msgbox DaycareEastDittoOpenXforms_Text_0, MSGBOX_YESNO
# 332 "data/maps/DaycareEast/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareEastDittoOpenXforms_7
# 343 "data/maps/DaycareEast/scripts.pory"
	speakername DaycareEastDittoOpenXforms_Text_1
# 344 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 345 "data/maps/DaycareEast/scripts.pory"
	msgbox DaycareEastDittoOpenXforms_Text_2, MSGBOX_AUTOCLOSE
# 346 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 347 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 348 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 349 "data/maps/DaycareEast/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 350 "data/maps/DaycareEast/scripts.pory"
	release
	end

DaycareEastDittoOpenXforms_7:
# 334 "data/maps/DaycareEast/scripts.pory"
	dittotransform SPECIES_DITTO
# 335 "data/maps/DaycareEast/scripts.pory"
	special OpenPCMoveMons
# 336 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 337 "data/maps/DaycareEast/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 338 "data/maps/DaycareEast/scripts.pory"
	release
	end


ChanseyDaycareEast::
# 381 "data/maps/DaycareEast/scripts.pory"
	lock
# 382 "data/maps/DaycareEast/scripts.pory"
	faceplayer
# 383 "data/maps/DaycareEast/scripts.pory"
	speakername ChanseyDaycareEast_Text_0
# 384 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 385 "data/maps/DaycareEast/scripts.pory"
	msgbox ChanseyDaycareEast_Text_1, MSGBOX_DEFAULT
# 386 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 387 "data/maps/DaycareEast/scripts.pory"
	msgbox ChanseyDaycareEast_Text_2, MSGBOX_YESNO
# 388 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 389 "data/maps/DaycareEast/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycareEast_1
# 419 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 420 "data/maps/DaycareEast/scripts.pory"
	msgbox ChanseyDaycareEast_Text_5, MSGBOX_AUTOCLOSE
# 421 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 422 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 423 "data/maps/DaycareEast/scripts.pory"
	release
	end

ChanseyDaycareEast_1:
# 391 "data/maps/DaycareEast/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 392 "data/maps/DaycareEast/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycareEast_4
# 409 "data/maps/DaycareEast/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 410 "data/maps/DaycareEast/scripts.pory"
	msgbox ChanseyDaycareEast_Text_4, MSGBOX_AUTOCLOSE
# 411 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 412 "data/maps/DaycareEast/scripts.pory"
	removefieldmugshot
# 413 "data/maps/DaycareEast/scripts.pory"
	release
	end

ChanseyDaycareEast_4:
# 394 "data/maps/DaycareEast/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 395 "data/maps/DaycareEast/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 396 "data/maps/DaycareEast/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 397 "data/maps/DaycareEast/scripts.pory"
	playfanfare MUS_HEAL
# 398 "data/maps/DaycareEast/scripts.pory"
	waitfanfare
# 399 "data/maps/DaycareEast/scripts.pory"
	special HealPlayerParty
# 400 "data/maps/DaycareEast/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 401 "data/maps/DaycareEast/scripts.pory"
	msgbox ChanseyDaycareEast_Text_3, MSGBOX_AUTOCLOSE
# 402 "data/maps/DaycareEast/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 403 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 404 "data/maps/DaycareEast/scripts.pory"
	release
	end


SoarFrontEast::
# 430 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_eq SoarFrontEast_1
# 438 "data/maps/DaycareEast/scripts.pory"
	goto_if_set FLAG_TRANS_NOIVERN, SoarFrontEast_4
SoarFrontEast_3:
# 471 "data/maps/DaycareEast/scripts.pory"
	lock
# 472 "data/maps/DaycareEast/scripts.pory"
	msgbox SoarFrontEast_Text_1, MSGBOX_DEFAULT
# 473 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 474 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarFrontEast_1:
# 432 "data/maps/DaycareEast/scripts.pory"
	lock
# 433 "data/maps/DaycareEast/scripts.pory"
	applymovement LOCALID_PLAYER, SoarFrontEast_Movement_0
# 434 "data/maps/DaycareEast/scripts.pory"
	waitmovement LOCALID_PLAYER
# 435 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarFrontEast_2:
# 440 "data/maps/DaycareEast/scripts.pory"
	lock
# 441 "data/maps/DaycareEast/scripts.pory"
	checkpartymove MOVE_SUPER_FANG
# 442 "data/maps/DaycareEast/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne SoarFrontEast_8
# 462 "data/maps/DaycareEast/scripts.pory"
	lock
# 463 "data/maps/DaycareEast/scripts.pory"
	msgbox SoarFrontEast_Text_1, MSGBOX_DEFAULT
# 464 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 465 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarFrontEast_4:
# 438 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_ne SoarFrontEast_2
	goto SoarFrontEast_3

SoarFrontEast_8:
# 444 "data/maps/DaycareEast/scripts.pory"
	msgbox SoarFrontEast_Text_0, MSGBOX_YESNO
# 445 "data/maps/DaycareEast/scripts.pory"
	release
# 446 "data/maps/DaycareEast/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SoarFrontEast_11
# 456 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarFrontEast_11:
# 448 "data/maps/DaycareEast/scripts.pory"
	dittotransform SPECIES_NOIVERN
# 449 "data/maps/DaycareEast/scripts.pory"
	applymovement LOCALID_PLAYER, SoarFrontEast_Movement_0
# 450 "data/maps/DaycareEast/scripts.pory"
	waitmovement LOCALID_PLAYER
# 451 "data/maps/DaycareEast/scripts.pory"
	release
	end


SoarBackEast::
# 480 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_eq SoarBackEast_1
# 488 "data/maps/DaycareEast/scripts.pory"
	goto_if_set FLAG_TRANS_NOIVERN, SoarBackEast_4
SoarBackEast_3:
# 520 "data/maps/DaycareEast/scripts.pory"
	lock
# 521 "data/maps/DaycareEast/scripts.pory"
	msgbox SoarBackEast_Text_1, MSGBOX_DEFAULT
# 522 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 523 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarBackEast_1:
# 482 "data/maps/DaycareEast/scripts.pory"
	lock
# 483 "data/maps/DaycareEast/scripts.pory"
	applymovement LOCALID_PLAYER, SoarBackEast_Movement_0
# 484 "data/maps/DaycareEast/scripts.pory"
	waitmovement LOCALID_PLAYER
# 485 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarBackEast_2:
# 490 "data/maps/DaycareEast/scripts.pory"
	lock
# 491 "data/maps/DaycareEast/scripts.pory"
	checkpartymove MOVE_SUPER_FANG
# 492 "data/maps/DaycareEast/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne SoarBackEast_8
# 512 "data/maps/DaycareEast/scripts.pory"
	lock
# 513 "data/maps/DaycareEast/scripts.pory"
	msgbox SoarBackEast_Text_1, MSGBOX_DEFAULT
# 514 "data/maps/DaycareEast/scripts.pory"
	waitmessage
# 515 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarBackEast_4:
# 488 "data/maps/DaycareEast/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_NOIVERN
	goto_if_ne SoarBackEast_2
	goto SoarBackEast_3

SoarBackEast_8:
# 494 "data/maps/DaycareEast/scripts.pory"
	msgbox SoarBackEast_Text_0, MSGBOX_YESNO
# 495 "data/maps/DaycareEast/scripts.pory"
	release
# 496 "data/maps/DaycareEast/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SoarBackEast_11
# 506 "data/maps/DaycareEast/scripts.pory"
	release
	end

SoarBackEast_11:
# 498 "data/maps/DaycareEast/scripts.pory"
	dittotransform SPECIES_NOIVERN
# 499 "data/maps/DaycareEast/scripts.pory"
	applymovement LOCALID_PLAYER, SoarBackEast_Movement_0
# 500 "data/maps/DaycareEast/scripts.pory"
	waitmovement LOCALID_PLAYER
# 501 "data/maps/DaycareEast/scripts.pory"
	release
	end


# 116 "data/maps/DaycareEast/scripts.pory"
RuffletDialog_Movement_0:
# 116 "data/maps/DaycareEast/scripts.pory"
	face_player
	step_end

# 151 "data/maps/DaycareEast/scripts.pory"
RuffletDialog_Movement_1:
# 152 "data/maps/DaycareEast/scripts.pory"
	jump_2_down
# 153 "data/maps/DaycareEast/scripts.pory"
	delay_16
# 153 "data/maps/DaycareEast/scripts.pory"
	delay_16
	step_end

# 157 "data/maps/DaycareEast/scripts.pory"
RuffletDialog_Movement_2:
# 158 "data/maps/DaycareEast/scripts.pory"
	slide_down
# 158 "data/maps/DaycareEast/scripts.pory"
	slide_down
# 158 "data/maps/DaycareEast/scripts.pory"
	slide_down
# 158 "data/maps/DaycareEast/scripts.pory"
	slide_down
# 158 "data/maps/DaycareEast/scripts.pory"
	slide_down
	step_end

# 210 "data/maps/DaycareEast/scripts.pory"
RuffletDialog_Movement_3:
# 210 "data/maps/DaycareEast/scripts.pory"
	walk_fast_left
# 210 "data/maps/DaycareEast/scripts.pory"
	face_right
	step_end

# 433 "data/maps/DaycareEast/scripts.pory"
SoarFrontEast_Movement_0:
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
# 433 "data/maps/DaycareEast/scripts.pory"
	walk_fast_up
	step_end

# 483 "data/maps/DaycareEast/scripts.pory"
SoarBackEast_Movement_0:
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
# 483 "data/maps/DaycareEast/scripts.pory"
	walk_fast_down
	step_end

KrabbyDialog_Text_0:
# 13 "data/maps/DaycareEast/scripts.pory"
	.string "Krabby$"

KrabbyDialog_Text_1:
# 15 "data/maps/DaycareEast/scripts.pory"
	.string "I love it here at the Daycare!\pI don't have to battle anyone that\nI don't want to!\pAlthough some Pokémon see it\ndifferently...$"

AlolanRaichuDialog_Text_0:
# 25 "data/maps/DaycareEast/scripts.pory"
	.string "Raichu$"

AlolanRaichuDialog_Text_1:
# 27 "data/maps/DaycareEast/scripts.pory"
	.string "Move out of my way!\nYou're blocking my waves dude.$"

SandyghastDialog_Text_0:
# 39 "data/maps/DaycareEast/scripts.pory"
	.string "Sandyghast$"

SandyghastDialog_Text_1:
# 41 "data/maps/DaycareEast/scripts.pory"
	.string "A fellow Ground_type!\pLet me give you some info...\nGround_type to Ground_type.\pI've heard a Pokémon will give an\nEgg for defeating it in a special\lbattle.\pBut...\pThat's just a rumor as no one has\nseen that Pokémon in ages.$"

SandyghastDialog_Text_2:
# 49 "data/maps/DaycareEast/scripts.pory"
	.string "...\n$"

ShellosEastDialog_Text_0:
# 67 "data/maps/DaycareEast/scripts.pory"
	.string "Shellos$"

ShellosEastDialog_Text_1:
# 69 "data/maps/DaycareEast/scripts.pory"
	.string "Wow a Marill!\pGastrodon told me about a cave\nwith a powerful flying Pokémon at\lthe top of the waterfall.\pMaybe you can reach it!\n$"

ShellosEastDialog_Text_2:
# 75 "data/maps/DaycareEast/scripts.pory"
	.string "Wow a Chinchou!\pGastrodon told me about a reef\nunder the sea.\pMaybe you can reach it!\n$"

ShellosEastDialog_Text_3:
# 83 "data/maps/DaycareEast/scripts.pory"
	.string "You seem nice and all...\nbut Gastrodon told me to only\ltalk to Water_types.$"

AlolanExeggutorDialog_Text_0:
# 93 "data/maps/DaycareEast/scripts.pory"
	.string "Exeggutor$"

AlolanExeggutorDialog_Text_1:
# 95 "data/maps/DaycareEast/scripts.pory"
	.string "I hang out here all day long,\nbut I'm still not sure how to\lgain EXP.\pI haven't interacted with the\nDaycare Man much though.\pMaybe he controls it?\pIt's all so confusing.\n$"

WingullDialog_Text_0:
# 105 "data/maps/DaycareEast/scripts.pory"
	.string "Wingull$"

WingullDialog_Text_1:
# 107 "data/maps/DaycareEast/scripts.pory"
	.string "I wish more Pokémon could make\nway their up here.\pWe Flying_type Pokémon can just\nfly down this cliffside here.$"

RuffletDialog_Text_0:
# 119 "data/maps/DaycareEast/scripts.pory"
	.string "Rufflet$"

RuffletDialog_Text_1:
# 121 "data/maps/DaycareEast/scripts.pory"
	.string "I wish I had the confidence to jump\nand try to fly...$"

RuffletDialog_Text_2:
# 129 "data/maps/DaycareEast/scripts.pory"
	.string "Wow a Flying_type Pokémon!\pWhere do you get the confidence to\nsoar like that?$"

RuffletDialog_Text_3:
# 135 "data/maps/DaycareEast/scripts.pory"
	.string "It just takes a leap of faith\nyou say?\pAlright, I'll try it!\pHere. Take this.$"

RuffletDialog_Text_4:
# 144 "data/maps/DaycareEast/scripts.pory"
	.string "Thanks for the confidence boost.$"

RuffletDialog_Text_5:
# 249 "data/maps/DaycareEast/scripts.pory"
	.string "I wish I had the confidence to jump\nand try to fly but I don't have\la role model to show me how.$"

RuffletOnShore_Text_0:
# 272 "data/maps/DaycareEast/scripts.pory"
	.string "That Sharpedo was nice enough to\nbring me ashore.\pI don't know why they get such a\nbad rap...$"

SlowpokeDialog_Text_0:
# 282 "data/maps/DaycareEast/scripts.pory"
	.string "Slowpoke$"

SlowpokeDialog_Text_1:
# 284 "data/maps/DaycareEast/scripts.pory"
	.string "I stay close to the shore.\pThere are some scary Pokémon\nfurther out!$"

SharpedoDialog_Text_0:
# 296 "data/maps/DaycareEast/scripts.pory"
	.string "Sharpedo$"

SharpedoDialog_Text_1:
# 298 "data/maps/DaycareEast/scripts.pory"
	.string "That little Rufflet fell into\nthe water.\pPoor fellow couldn't swim so\nI carried it to the shore.$"

SharpedoDialog_Text_2:
# 305 "data/maps/DaycareEast/scripts.pory"
	.string "Looks can be deceiving!\n$"

SharpedoDialog_Text_3:
# 316 "data/maps/DaycareEast/scripts.pory"
	.string "I don't understand why Pokémon are\nso afraid of me...\pIs it something stuck in my teeth?\n$"

DaycareEastDittoOpenXforms_Text_0:
# 331 "data/maps/DaycareEast/scripts.pory"
	.string "Would you like to change out your\ntransformation options?$"

DaycareEastDittoOpenXforms_Text_1:
# 343 "data/maps/DaycareEast/scripts.pory"
	.string "Ditto$"

DaycareEastDittoOpenXforms_Text_2:
# 345 "data/maps/DaycareEast/scripts.pory"
	.string "Come back anytime!$"

DaycareEastDittoOpenXforms_Text_3:
# 357 "data/maps/DaycareEast/scripts.pory"
	.string "Ditto!\pYou can transform into any\nPokémon you defeat in battle!\pThis only applies to Pokémon\nnot already using Transform...\lLike other Dittos in disguise.\pPress the{SELECT_BUTTON} button to\naccess your transformation menu.\pYou can also view more information\nabout your transformations from\lthe Xforms option on the {START_BUTTON} menu.\pTo swap out your transformation\noptions, press the {L_BUTTON} button!$"

DaycareEastDittoOpenXforms_Text_4:
# 369 "data/maps/DaycareEast/scripts.pory"
	.string "Hello there fellow Ditto!\pDaycare Man asked you to get an Egg\nfor him, did he?\pWell, you're about to learn the\nsecret of how we Dittos are\lalways found holding Eggs.\pIt'll be quite the adventure!\pTalk to any of the Dittos around\nthe Daycare for some control tips,\lincluding me!$"

ChanseyDaycareEast_Text_0:
# 383 "data/maps/DaycareEast/scripts.pory"
	.string "Chansey$"

ChanseyDaycareEast_Text_1:
# 385 "data/maps/DaycareEast/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycareEast_Text_2:
# 387 "data/maps/DaycareEast/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycareEast_Text_3:
# 401 "data/maps/DaycareEast/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycareEast_Text_4:
# 410 "data/maps/DaycareEast/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycareEast_Text_5:
# 420 "data/maps/DaycareEast/scripts.pory"
	.string "Oh, okay then.$"

SoarFrontEast_Text_0:
# 444 "data/maps/DaycareEast/scripts.pory"
	.string "There is a tall cliff.\pWould you like to transform into\nNoivern to soar up it?$"

SoarFrontEast_Text_1:
# 463 "data/maps/DaycareEast/scripts.pory"
	.string "There is a tall cliff.\pMaybe a Flying Pokémon could soar\nup to the top.$"

SoarBackEast_Text_0:
# 494 "data/maps/DaycareEast/scripts.pory"
	.string "There is a tall cliff.\pWould you like to transform into\nNoivern to soar down it?$"

SoarBackEast_Text_1:
# 513 "data/maps/DaycareEast/scripts.pory"
	.string "There is a tall cliff.\pMaybe a Flying Pokémon could soar\ndown to the bottom.$"
