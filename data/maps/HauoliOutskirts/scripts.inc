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
	.string "friend! Even stronger Pokémon await\l"
	.string "you within!$"

TenCarrotHillSign_Text_0:
# 24 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Ten Carrot Hill$"

HauoliOutskirtLittleGirlNPC_Text_0:
# 31 "data/maps/HauoliOutskirts/scripts.pory"
	.string "The Pokémon I've got with me are all\n"
	.string "Grass-type.\l"
	.string "I'm looking for Water-type Pokémon for\l"
	.string "my team so I can beat Fire types, too.$"

HauoliOustkirtsTrainerTipsSign_Text_0:
# 38 "data/maps/HauoliOutskirts/scripts.pory"
	.string "Trainer Tips\p"
	.string "The Pokémon that will appear first in\n"
	.string "battle will be the one you've put in the\l"
	.string "left position in your Pokémon party.$"

HauoliOutskirtLassNPC_Text_0:
# 44 "data/maps/HauoliOutskirts/scripts.pory"
	.string "If you see a Pokémon Trainer, you've\ngotta show off the Pokémon you like!$"
