HauoliOutskirts_MapScripts::
	.byte 0


HauoliOutskirts_LillieOutsideLab::
# 4 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 5 "data/maps/HauoliOutskirts/scripts.pory"
	startcutscene CUTSCENE_HAUOLI_OUTSKIRTS_LILLIE_OUTSIDE_LAB
# 6 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 7 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 8 "data/maps/HauoliOutskirts/scripts.pory"
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
# 9 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_LillieOutsideLab_Text_0
# 10 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_1, MSGBOX_AUTOCLOSE
# 25 "data/maps/HauoliOutskirts/scripts.pory"
	playmoncry SPECIES_COSMOG, 0
# 26 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_1
# 27 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 28 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_2, MSGBOX_AUTOCLOSE
# 29 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 30 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	waitmessage
# 32 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_LillieOutsideLab_Text_0
# 33 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_3, MSGBOX_AUTOCLOSE
# 52 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 53 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 54 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 55 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 56 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 57 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 58 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 59 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 60 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 61 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 62 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_LillieOutsideLab_Text_4
# 63 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_5, MSGBOX_AUTOCLOSE
# 66 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 67 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_3
HauoliOutskirts_LillieOutsideLab_1:
# 70 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_9
HauoliOutskirts_LillieOutsideLab_8:
# 74 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_5
HauoliOutskirts_LillieOutsideLab_6:
# 76 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 77 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_LillieOutsideLab_Text_0
# 78 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_6, MSGBOX_AUTOCLOSE
# 94 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8004, 1
# 95 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8005, 1
# 96 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8006, 8
# 97 "data/maps/HauoliOutskirts/scripts.pory"
	setvar VAR_0x8007, 5
# 98 "data/maps/HauoliOutskirts/scripts.pory"
	special ShakeCamera
# 99 "data/maps/HauoliOutskirts/scripts.pory"
	waitstate
# 100 "data/maps/HauoliOutskirts/scripts.pory"
	playse SE_PIN
# 101 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_2
# 102 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_2
# 103 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 104 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 105 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_7, MSGBOX_AUTOCLOSE
# 106 "data/maps/HauoliOutskirts/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 107 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_0
# 108 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 24
	goto_if_eq HauoliOutskirts_LillieOutsideLab_14
HauoliOutskirts_LillieOutsideLab_12:
# 111 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_3, 25
	goto_if_eq HauoliOutskirts_LillieOutsideLab_20
HauoliOutskirts_LillieOutsideLab_19:
# 115 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_5
HauoliOutskirts_LillieOutsideLab_17:
# 117 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement 0
# 118 "data/maps/HauoliOutskirts/scripts.pory"
	speakername HauoliOutskirts_LillieOutsideLab_Text_0
# 119 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirts_LillieOutsideLab_Text_8, MSGBOX_AUTOCLOSE
# 136 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_6
# 137 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 138 "data/maps/HauoliOutskirts/scripts.pory"
	opendoor 25, 12
# 139 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 140 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement lillie_outside_lab, HauoliOutskirts_LillieOutsideLab_Movement_7
# 141 "data/maps/HauoliOutskirts/scripts.pory"
	waitmovement lillie_outside_lab
# 142 "data/maps/HauoliOutskirts/scripts.pory"
	hideobjectat lillie_outside_lab, MAP_HAUOLI_OUTSKIRTS
# 143 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 144 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 145 "data/maps/HauoliOutskirts/scripts.pory"
	closedoor 25, 12
# 146 "data/maps/HauoliOutskirts/scripts.pory"
	waitdooranim
# 147 "data/maps/HauoliOutskirts/scripts.pory"
	endcutscene
# 148 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOutskirts_LillieOutsideLab_2:
# 68 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_3
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_3:
# 67 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_2
	goto HauoliOutskirts_LillieOutsideLab_1

HauoliOutskirts_LillieOutsideLab_7:
# 71 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_4
	goto HauoliOutskirts_LillieOutsideLab_6

HauoliOutskirts_LillieOutsideLab_9:
# 70 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_7
	goto HauoliOutskirts_LillieOutsideLab_8

HauoliOutskirts_LillieOutsideLab_13:
# 109 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_3
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_14:
# 108 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 15
	goto_if_eq HauoliOutskirts_LillieOutsideLab_13
	goto HauoliOutskirts_LillieOutsideLab_12

HauoliOutskirts_LillieOutsideLab_18:
# 112 "data/maps/HauoliOutskirts/scripts.pory"
	applymovement LOCALID_PLAYER, HauoliOutskirts_LillieOutsideLab_Movement_4
	goto HauoliOutskirts_LillieOutsideLab_17

HauoliOutskirts_LillieOutsideLab_20:
# 111 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_TEMP_4, 16
	goto_if_eq HauoliOutskirts_LillieOutsideLab_18
	goto HauoliOutskirts_LillieOutsideLab_19


HauoliOutskirts_LillieOutsideLabSkip::
# 153 "data/maps/HauoliOutskirts/scripts.pory"
	closemessage
# 154 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 155 "data/maps/HauoliOutskirts/scripts.pory"
	special StopAllObjectMovements
# 156 "data/maps/HauoliOutskirts/scripts.pory"
	special CloseScriptMenus
# 157 "data/maps/HauoliOutskirts/scripts.pory"
	removeobject lillie_outside_lab
# 158 "data/maps/HauoliOutskirts/scripts.pory"
	setflag FLAG_HIDE_LILLIE_HAUOLI_LAB
# 159 "data/maps/HauoliOutskirts/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 160 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


LabSign::
# 165 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 166 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox LabSign_Text_0
# 167 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


OutsideTenCarrotHill::
# 172 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 173 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 174 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox OutsideTenCarrotHill_Text_0
# 175 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


TenCarrotHillSign::
# 179 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 180 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox TenCarrotHillSign_Text_0
# 181 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLittleGirlNPC::
# 185 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 186 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 187 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLittleGirlNPC_Text_0
# 188 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOustkirtsTrainerTipsSign::
# 193 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 194 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsTrainerTipsSign_Text_0
# 195 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLassNPC::
# 200 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLassNPC_Text_0, MSGBOX_NPC
	end


HauoliOustkirtsFishingSpot1::
# 205 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 206 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_SURF_MON_SLOT, 0
	goto_if_eq HauoliOustkirtsFishingSpot1_2
# 227 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_2
HauoliOustkirtsFishingSpot1_1:
# 229 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_2:
# 208 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_0, MSGBOX_YESNO
# 209 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_5
# 221 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_5:
# 211 "data/maps/HauoliOutskirts/scripts.pory"
	checkitem ITEM_SUPER_ROD
# 212 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_8
# 217 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_1
	goto HauoliOustkirtsFishingSpot1_1

HauoliOustkirtsFishingSpot1_8:
# 214 "data/maps/HauoliOutskirts/scripts.pory"
	startfishing
	goto HauoliOustkirtsFishingSpot1_1


# 6 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_0:
# 6 "data/maps/HauoliOutskirts/scripts.pory"
	face_player
	step_end

# 26 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_1:
# 26 "data/maps/HauoliOutskirts/scripts.pory"
	shake_horizontal
	step_end

# 59 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_2:
# 59 "data/maps/HauoliOutskirts/scripts.pory"
	emote_exclamation_mark
# 59 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 68 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_3:
# 68 "data/maps/HauoliOutskirts/scripts.pory"
	face_right
	step_end

# 71 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_4:
# 71 "data/maps/HauoliOutskirts/scripts.pory"
	face_up
	step_end

# 74 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_5:
# 74 "data/maps/HauoliOutskirts/scripts.pory"
	face_left
	step_end

# 136 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_6:
# 136 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
# 136 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

# 140 "data/maps/HauoliOutskirts/scripts.pory"
HauoliOutskirts_LillieOutsideLab_Movement_7:
# 140 "data/maps/HauoliOutskirts/scripts.pory"
	walk_up
	step_end

HauoliOutskirts_LillieOutsideLab_Text_0:
# 9 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Lillie$"

HauoliOutskirts_LillieOutsideLab_Text_1:
# 10 "data/maps/HauoliOutskirts/scripts.pory"
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

HauoliOutskirts_LillieOutsideLab_Text_2:
# 28 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pew!$"

HauoliOutskirts_LillieOutsideLab_Text_3:
# 33 "data/maps/HauoliOutskirts/scripts.pory"
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

HauoliOutskirts_LillieOutsideLab_Text_4:
# 62 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Kukui$"

HauoliOutskirts_LillieOutsideLab_Text_5:
# 63 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Oh yeah, Rockruff! Lets go!\n"
	.string "Give it everything you've got!\l"
	.string "My body is ready. Woo!$"

HauoliOutskirts_LillieOutsideLab_Text_6:
# 78 "data/maps/HauoliOutskirts/scripts.pory"
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

HauoliOutskirts_LillieOutsideLab_Text_7:
# 105 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Raaaa-oooooohhh! Raff ruff!$"

HauoliOutskirts_LillieOutsideLab_Text_8:
# 119 "data/maps/HauoliOutskirts/scripts.pory"
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
# 166 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pokémon Research Lab$"

OutsideTenCarrotHill_Text_0:
# 174 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Wa ha ha!\n"
	.string "You're a strong Trainer, all right!\l"
	.string "Go on! You take on Ten Carrot Hill,\l"
	.string "friend!\p"
	.string "Even stronger Pokémon await you\n"
	.string "within!$"

TenCarrotHillSign_Text_0:
# 180 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ten Carrot Hill$"

HauoliOutskirtLittleGirlNPC_Text_0:
# 187 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon I've got with me are all\n"
	.string "Grass-type.\p"
	.string "I'm looking for Water-type Pokémon\l"
	.string "for my team so I can beat Fire types,\l"
	.string "too.$"

HauoliOustkirtsTrainerTipsSign_Text_0:
# 194 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Trainer Tips\p"
	.string "The Pokémon that will appear first in\n"
	.string "battle will be the one you've put in\l"
	.string "the left position in your Pokémon\l"
	.string "party.$"

HauoliOutskirtLassNPC_Text_0:
# 200 "data/maps/HauoliOutskirts/scripts.pory"
	.string "If you see a Pokémon Trainer, you've\ngotta show off the Pokémon you like!$"

HauoliOustkirtsFishingSpot1_Text_0:
# 208 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Would you like to fish here?$"

HauoliOustkirtsFishingSpot1_Text_1:
# 217 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You don't have a Fishing Rod.$"

HauoliOustkirtsFishingSpot1_Text_2:
# 227 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You can't fish while riding a Sharpedo!$"
