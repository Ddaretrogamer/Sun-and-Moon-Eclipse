DaycareTreehouse_MapScripts::
# 2 "data/maps/DaycareTreehouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareTreehouse_OnTransition
	.byte 0


DaycareTreehouse_OnTransition::
# 6 "data/maps/DaycareTreehouse/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCARE_TREEHOUSE
	end


GrovyleDialog::
# 11 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 12 "data/maps/DaycareTreehouse/scripts.pory"
	faceplayer
# 13 "data/maps/DaycareTreehouse/scripts.pory"
	speakername GrovyleDialog_Text_0
# 14 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_GROVYLE, EMOTE_NORMAL
# 15 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox GrovyleDialog_Text_1, MSGBOX_DEFAULT
# 16 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 17 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 18 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end


BattleVsWeavile::
# 24 "data/maps/DaycareTreehouse/scripts.pory"
	goto_if_set FLAG_TRANS_WEAVILE, BattleVsWeavile_2
# 28 "data/maps/DaycareTreehouse/scripts.pory"
	goto_if_unset FLAG_TRANS_ARCANINE, BattleVsWeavile_3
# 59 "data/maps/DaycareTreehouse/scripts.pory"
	goto_if_set FLAG_TRANS_ARCANINE, BattleVsWeavile_5
BattleVsWeavile_1:
# 90 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 91 "data/maps/DaycareTreehouse/scripts.pory"
	playbgm MUS_NONE, FALSE
# 92 "data/maps/DaycareTreehouse/scripts.pory"
	playmoncry SPECIES_WEAVILE, CRY_MODE_NORMAL
# 93 "data/maps/DaycareTreehouse/scripts.pory"
	waitmoncry
# 94 "data/maps/DaycareTreehouse/scripts.pory"
	playse SE_PIN
# 95 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 96 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 97 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_0
# 98 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 99 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_1
# 100 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 101 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_2
# 102 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 103 "data/maps/DaycareTreehouse/scripts.pory"
	playse SE_M_SCRATCH
# 104 "data/maps/DaycareTreehouse/scripts.pory"
	waitse
# 105 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_3
# 106 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 107 "data/maps/DaycareTreehouse/scripts.pory"
	playbgm MUS_PMD_BOSS_INTRO, FALSE
# 108 "data/maps/DaycareTreehouse/scripts.pory"
	speakername BattleVsWeavile_Text_0
# 109 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_WEAVILE, EMOTE_ANGRY
# 110 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox BattleVsWeavile_Text_2, MSGBOX_AUTOCLOSE
# 111 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 112 "data/maps/DaycareTreehouse/scripts.pory"
	setwildbattle SPECIES_WEAVILE, 25, item = ITEM_EXPERT_BELT, move1 = MOVE_FAKE_OUT, move2 = MOVE_DIG, move3 = MOVE_ICE_SHARD, move4 = MOVE_ICE_PUNCH
# 113 "data/maps/DaycareTreehouse/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 1, 1, 1, 0, 0
# 114 "data/maps/DaycareTreehouse/scripts.pory"
	dowildbattle
# 115 "data/maps/DaycareTreehouse/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 116 "data/maps/DaycareTreehouse/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsWeavile_10
	return

BattleVsWeavile_2:
	end

BattleVsWeavile_3:
# 30 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 31 "data/maps/DaycareTreehouse/scripts.pory"
	playbgm MUS_NONE, FALSE
# 32 "data/maps/DaycareTreehouse/scripts.pory"
	playmoncry SPECIES_WEAVILE, CRY_MODE_NORMAL
# 33 "data/maps/DaycareTreehouse/scripts.pory"
	waitmoncry
# 34 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 35 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 36 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_0
# 37 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 38 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_1
# 39 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 40 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_2
# 41 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 42 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_3
# 43 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 44 "data/maps/DaycareTreehouse/scripts.pory"
	playse SE_M_SCRATCH
# 45 "data/maps/DaycareTreehouse/scripts.pory"
	playbgm MUS_PMD_BOSS_INTRO, FALSE
# 46 "data/maps/DaycareTreehouse/scripts.pory"
	speakername BattleVsWeavile_Text_0
# 47 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_WEAVILE, EMOTE_ANGRY
# 48 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox BattleVsWeavile_Text_1, MSGBOX_AUTOCLOSE
# 49 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 50 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 51 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_4
# 52 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 53 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_5
# 54 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 55 "data/maps/DaycareTreehouse/scripts.pory"
	fadenewbgm MUS_PMD_JUNGLE
# 56 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end

BattleVsWeavile_4:
# 61 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 62 "data/maps/DaycareTreehouse/scripts.pory"
	playbgm MUS_NONE, FALSE
# 63 "data/maps/DaycareTreehouse/scripts.pory"
	playmoncry SPECIES_WEAVILE, CRY_MODE_NORMAL
# 64 "data/maps/DaycareTreehouse/scripts.pory"
	waitmoncry
# 65 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 66 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 67 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_0
# 68 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 69 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_1
# 70 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 71 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement LOCALID_PLAYER, BattleVsWeavile_Movement_2
# 72 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement LOCALID_PLAYER
# 73 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_3
# 74 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 75 "data/maps/DaycareTreehouse/scripts.pory"
	playse SE_M_SCRATCH
# 76 "data/maps/DaycareTreehouse/scripts.pory"
	playbgm MUS_PMD_BOSS_INTRO, FALSE
# 77 "data/maps/DaycareTreehouse/scripts.pory"
	speakername BattleVsWeavile_Text_0
# 78 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_WEAVILE, EMOTE_ANGRY
# 79 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox BattleVsWeavile_Text_1, MSGBOX_AUTOCLOSE
# 80 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 81 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 82 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_4
# 83 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 84 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_5
# 85 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 86 "data/maps/DaycareTreehouse/scripts.pory"
	fadenewbgm MUS_PMD_JUNGLE
# 87 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end

BattleVsWeavile_5:
# 59 "data/maps/DaycareTreehouse/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_ARCANINE
	goto_if_ne BattleVsWeavile_4
	goto BattleVsWeavile_1

BattleVsWeavile_10:
# 118 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 119 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, Common_Movement_ExclamationMark
# 120 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 121 "data/maps/DaycareTreehouse/scripts.pory"
	playse SE_PIN
# 122 "data/maps/DaycareTreehouse/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 123 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 124 "data/maps/DaycareTreehouse/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 125 "data/maps/DaycareTreehouse/scripts.pory"
	setflag FLAG_TRANS_WEAVILE
# 126 "data/maps/DaycareTreehouse/scripts.pory"
	delay 30
# 127 "data/maps/DaycareTreehouse/scripts.pory"
	dittotransform SPECIES_WEAVILE
# 128 "data/maps/DaycareTreehouse/scripts.pory"
	playse MUS_LEVEL_UP
# 129 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox BattleVsWeavile_Text_3, MSGBOX_DEFAULT
# 130 "data/maps/DaycareTreehouse/scripts.pory"
	waitse
# 131 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 132 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 133 "data/maps/DaycareTreehouse/scripts.pory"
	dittotransform VAR_TEMP_0
# 134 "data/maps/DaycareTreehouse/scripts.pory"
	givemon SPECIES_WEAVILE, 25, move1 = MOVE_ICE_SHARD, move2 = MOVE_ICE_PUNCH, move3 = MOVE_SHADOW_CLAW, move4 = MOVE_BRICK_BREAK
# 135 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 136 "data/maps/DaycareTreehouse/scripts.pory"
	speakername BattleVsWeavile_Text_0
# 137 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_WEAVILE, EMOTE_NORMAL
# 138 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox BattleVsWeavile_Text_4, MSGBOX_AUTOCLOSE
# 139 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 140 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 141 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_4
# 142 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 143 "data/maps/DaycareTreehouse/scripts.pory"
	applymovement Weavile, BattleVsWeavile_Movement_5
# 144 "data/maps/DaycareTreehouse/scripts.pory"
	waitmovement Weavile
# 145 "data/maps/DaycareTreehouse/scripts.pory"
	fadenewbgm MUS_PMD_JUNGLE
# 146 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end


ChanseyDaycareTreehouseHeal::
# 152 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 153 "data/maps/DaycareTreehouse/scripts.pory"
	faceplayer
# 154 "data/maps/DaycareTreehouse/scripts.pory"
	speakername ChanseyDaycareTreehouseHeal_Text_0
# 155 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 156 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox ChanseyDaycareTreehouseHeal_Text_1, MSGBOX_DEFAULT
# 157 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 158 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox ChanseyDaycareTreehouseHeal_Text_2, MSGBOX_YESNO
# 159 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 160 "data/maps/DaycareTreehouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyDaycareTreehouseHeal_1
# 190 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 191 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox ChanseyDaycareTreehouseHeal_Text_5, MSGBOX_AUTOCLOSE
# 192 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 193 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 194 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end

ChanseyDaycareTreehouseHeal_1:
# 162 "data/maps/DaycareTreehouse/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 163 "data/maps/DaycareTreehouse/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyDaycareTreehouseHeal_4
# 180 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 181 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox ChanseyDaycareTreehouseHeal_Text_4, MSGBOX_AUTOCLOSE
# 182 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 183 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 184 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end

ChanseyDaycareTreehouseHeal_4:
# 165 "data/maps/DaycareTreehouse/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 166 "data/maps/DaycareTreehouse/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 167 "data/maps/DaycareTreehouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 168 "data/maps/DaycareTreehouse/scripts.pory"
	playfanfare MUS_HEAL
# 169 "data/maps/DaycareTreehouse/scripts.pory"
	waitfanfare
# 170 "data/maps/DaycareTreehouse/scripts.pory"
	special HealPlayerParty
# 171 "data/maps/DaycareTreehouse/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 172 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox ChanseyDaycareTreehouseHeal_Text_3, MSGBOX_AUTOCLOSE
# 173 "data/maps/DaycareTreehouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 174 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 175 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end


DaycareTreehouseDittoOpenXforms::
# 201 "data/maps/DaycareTreehouse/scripts.pory"
	lock
# 202 "data/maps/DaycareTreehouse/scripts.pory"
	faceplayer
# 203 "data/maps/DaycareTreehouse/scripts.pory"
	goto_if_set FLAG_DITTO_INTRO, DaycareTreehouseDittoOpenXforms_1
# 243 "data/maps/DaycareTreehouse/scripts.pory"
	speakername DaycareTreehouseDittoOpenXforms_Text_1
# 244 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 245 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox DaycareTreehouseDittoOpenXforms_Text_4, MSGBOX_DEFAULT
# 246 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 247 "data/maps/DaycareTreehouse/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 248 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 249 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 250 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end

DaycareTreehouseDittoOpenXforms_1:
# 205 "data/maps/DaycareTreehouse/scripts.pory"
	goto_if_set FLAG_XFORMS_TALKED_TO_DITTO, DaycareTreehouseDittoOpenXforms_4
# 231 "data/maps/DaycareTreehouse/scripts.pory"
	speakername DaycareTreehouseDittoOpenXforms_Text_1
# 232 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 233 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox DaycareTreehouseDittoOpenXforms_Text_3, MSGBOX_DEFAULT
# 234 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 235 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 236 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end

DaycareTreehouseDittoOpenXforms_4:
# 207 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox DaycareTreehouseDittoOpenXforms_Text_0, MSGBOX_YESNO
# 208 "data/maps/DaycareTreehouse/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareTreehouseDittoOpenXforms_7
# 219 "data/maps/DaycareTreehouse/scripts.pory"
	speakername DaycareTreehouseDittoOpenXforms_Text_1
# 220 "data/maps/DaycareTreehouse/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 221 "data/maps/DaycareTreehouse/scripts.pory"
	msgbox DaycareTreehouseDittoOpenXforms_Text_2, MSGBOX_AUTOCLOSE
# 222 "data/maps/DaycareTreehouse/scripts.pory"
	waitmessage
# 223 "data/maps/DaycareTreehouse/scripts.pory"
	removefieldmugshot
# 224 "data/maps/DaycareTreehouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 225 "data/maps/DaycareTreehouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 226 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end

DaycareTreehouseDittoOpenXforms_7:
# 210 "data/maps/DaycareTreehouse/scripts.pory"
	dittotransform SPECIES_DITTO
# 211 "data/maps/DaycareTreehouse/scripts.pory"
	special OpenPCMoveMons
# 212 "data/maps/DaycareTreehouse/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 213 "data/maps/DaycareTreehouse/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 214 "data/maps/DaycareTreehouse/scripts.pory"
	release
	end


# 36 "data/maps/DaycareTreehouse/scripts.pory"
BattleVsWeavile_Movement_0:
# 36 "data/maps/DaycareTreehouse/scripts.pory"
	face_up
	step_end

# 38 "data/maps/DaycareTreehouse/scripts.pory"
BattleVsWeavile_Movement_1:
# 38 "data/maps/DaycareTreehouse/scripts.pory"
	lock_facing_direction
	step_end

# 40 "data/maps/DaycareTreehouse/scripts.pory"
BattleVsWeavile_Movement_2:
# 40 "data/maps/DaycareTreehouse/scripts.pory"
	walk_fast_down
	step_end

# 42 "data/maps/DaycareTreehouse/scripts.pory"
BattleVsWeavile_Movement_3:
# 42 "data/maps/DaycareTreehouse/scripts.pory"
	jump_2_down
	step_end

# 51 "data/maps/DaycareTreehouse/scripts.pory"
BattleVsWeavile_Movement_4:
# 51 "data/maps/DaycareTreehouse/scripts.pory"
	walk_fast_up
# 51 "data/maps/DaycareTreehouse/scripts.pory"
	walk_fast_up
	step_end

# 53 "data/maps/DaycareTreehouse/scripts.pory"
BattleVsWeavile_Movement_5:
# 53 "data/maps/DaycareTreehouse/scripts.pory"
	walk_in_place_down
	step_end

GrovyleDialog_Text_0:
# 13 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Grovyle$"

GrovyleDialog_Text_1:
# 15 "data/maps/DaycareTreehouse/scripts.pory"
	.string "A lot of us here in the Jungle\nbiome are very agile, but none\lare quite as shifty as Weavile.\pHe is particular about who he\nchallenges to battle so don't\lbe surprised if he turns you\laway.$"

BattleVsWeavile_Text_0:
# 46 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Weavile$"

BattleVsWeavile_Text_1:
# 48 "data/maps/DaycareTreehouse/scripts.pory"
	.string "You want to challenge me?\pNot a chance weakling.\pCome back when you can keep up...\nor don't come back at all.$"

BattleVsWeavile_Text_2:
# 110 "data/maps/DaycareTreehouse/scripts.pory"
	.string "You look quick.\pNow we're talking.\pLet's see if you're fast or just\nflashy.$"

BattleVsWeavile_Text_3:
# 129 "data/maps/DaycareTreehouse/scripts.pory"
	.string "You have gained the ability to\ntransform into Weavile!$"

BattleVsWeavile_Text_4:
# 138 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Godspeed challenger.\pYou have shown me that you aren't\nall looks.$"

ChanseyDaycareTreehouseHeal_Text_0:
# 154 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Chansey$"

ChanseyDaycareTreehouseHeal_Text_1:
# 156 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyDaycareTreehouseHeal_Text_2:
# 158 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Would you like to heal?$"

ChanseyDaycareTreehouseHeal_Text_3:
# 172 "data/maps/DaycareTreehouse/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyDaycareTreehouseHeal_Text_4:
# 181 "data/maps/DaycareTreehouse/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyDaycareTreehouseHeal_Text_5:
# 191 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Oh, okay then.$"

DaycareTreehouseDittoOpenXforms_Text_0:
# 207 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Would you like to change out your\ntransformation options?$"

DaycareTreehouseDittoOpenXforms_Text_1:
# 219 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Ditto$"

DaycareTreehouseDittoOpenXforms_Text_2:
# 221 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Come back anytime!$"

DaycareTreehouseDittoOpenXforms_Text_3:
# 233 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Ditto!\pYou can transform into any\nPokémon you defeat in battle!\pThis only applies to Pokémon\nnot already using Transform...\lLike other Dittos in disguise.\pPress the{SELECT_BUTTON} button to\naccess your transformation menu.\pYou can also view more information\nabout your transformations from\lthe Xforms option on the {START_BUTTON} menu.\pTo swap out your transformation\noptions, press the {L_BUTTON} button!$"

DaycareTreehouseDittoOpenXforms_Text_4:
# 245 "data/maps/DaycareTreehouse/scripts.pory"
	.string "Hello there fellow Ditto!\pDaycare Man asked you to get an Egg\nfor him, did he?\pWell, you're about to learn the\nsecret of how we Dittos are\lalways found holding Eggs.\pIt'll be quite the adventure!\pTalk to any of the Dittos around\nthe Daycare for some control tips,\lincluding me!$"
