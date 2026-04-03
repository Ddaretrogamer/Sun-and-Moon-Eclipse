HauoliOutskirts_MapScripts::
	.byte 0


LabSign::
# 4 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 5 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox LabSign_Text_0
# 6 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


LabOutsideNPC::
# 11 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox LabOutsideNPC_Text_0, MSGBOX_NPC
	end


OutsideTenCarrotHill::
# 16 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 17 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox OutsideTenCarrotHill_Text_0
# 19 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


TenCarrotHillSign::
# 23 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 24 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox TenCarrotHillSign_Text_0
# 25 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLittleGirlNPC::
# 29 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 30 "data/maps/HauoliOutskirts/scripts.pory"
	faceplayer
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLittleGirlNPC_Text_0
# 32 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOustkirtsTrainerTipsSign::
# 37 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 38 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsTrainerTipsSign_Text_0
# 39 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end


HauoliOutskirtLassNPC::
# 44 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOutskirtLassNPC_Text_0, MSGBOX_NPC
	end


HauoliOustkirtsFishingSpot1::
# 49 "data/maps/HauoliOutskirts/scripts.pory"
	lock
# 50 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_SURF_MON_SLOT, 0
	goto_if_eq HauoliOustkirtsFishingSpot1_2
# 71 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_2
HauoliOustkirtsFishingSpot1_1:
# 73 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_2:
# 52 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_0, MSGBOX_YESNO
# 53 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_5
# 65 "data/maps/HauoliOutskirts/scripts.pory"
	release
	end

HauoliOustkirtsFishingSpot1_5:
# 55 "data/maps/HauoliOutskirts/scripts.pory"
	checkitem ITEM_SUPER_ROD
# 56 "data/maps/HauoliOutskirts/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq HauoliOustkirtsFishingSpot1_8
# 61 "data/maps/HauoliOutskirts/scripts.pory"
	msgbox HauoliOustkirtsFishingSpot1_Text_1
	goto HauoliOustkirtsFishingSpot1_1

HauoliOustkirtsFishingSpot1_8:
# 58 "data/maps/HauoliOutskirts/scripts.pory"
	startfishing
	goto HauoliOustkirtsFishingSpot1_1


LabSign_Text_0:
# 5 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Pokémon Research Lab$"

LabOutsideNPC_Text_0:
# 11 "data/maps/HauoliOutskirts/scripts.pory"
	.string "This is Professor Kukui's Lab.$"

OutsideTenCarrotHill_Text_0:
# 18 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Wa ha ha!\n"
	.string "You're a strong Trainer, all right!\l"
	.string "Go on! You take on Ten Carrot Hill,\l"
	.string "friend!\p"
	.string "Even stronger Pokémon await you\n"
	.string "within!$"

TenCarrotHillSign_Text_0:
# 24 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ten Carrot Hill$"

HauoliOutskirtLittleGirlNPC_Text_0:
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon I've got with me are all\n"
	.string "Grass-type.\p"
	.string "I'm looking for Water-type Pokémon\l"
	.string "for my team so I can beat Fire types,\l"
	.string "too.$"

HauoliOustkirtsTrainerTipsSign_Text_0:
# 38 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Trainer Tips\p"
	.string "The Pokémon that will appear first in\n"
	.string "battle will be the one you've put in\l"
	.string "the left position in your Pokémon\l"
	.string "party.$"

HauoliOutskirtLassNPC_Text_0:
# 44 "data/maps/HauoliOutskirts/scripts.pory"
	.string "If you see a Pokémon Trainer, you've\ngotta show off the Pokémon you like!$"

HauoliOustkirtsFishingSpot1_Text_0:
# 52 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Would you like to fish here?$"

HauoliOustkirtsFishingSpot1_Text_1:
# 61 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You don't have a Fishing Rod.$"

HauoliOustkirtsFishingSpot1_Text_2:
# 71 "data/maps/HauoliOutskirts/scripts.pory"
	.string "You can't fish while riding a Sharpedo!$"
