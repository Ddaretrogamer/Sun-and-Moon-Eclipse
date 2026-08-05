HaouliPokemonCenter_MapScripts::
# 2 "data/maps/HaouliPokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_Pokecenter_SetHealSpot
	.byte 0


Route1_Pokecenter_SetHealSpot::
# 6 "data/maps/HaouliPokemonCenter/scripts.pory"
	setrespawn HEAL_LOCATION_ROUTE1N
	end


HaouliPokemonCenter_EventScript_Nurse::
# 11 "data/maps/HaouliPokemonCenter/scripts.pory"
	setvar VAR_0x800B, Route_1_Nurse
# 12 "data/maps/HaouliPokemonCenter/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 13 "data/maps/HaouliPokemonCenter/scripts.pory"
	waitmessage
# 14 "data/maps/HaouliPokemonCenter/scripts.pory"
	waitbuttonpress
# 15 "data/maps/HaouliPokemonCenter/scripts.pory"
	release
	end


HaouliPokemonCenter_FatMan::
# 20 "data/maps/HaouliPokemonCenter/scripts.pory"
	lock
# 21 "data/maps/HaouliPokemonCenter/scripts.pory"
	faceplayer
# 22 "data/maps/HaouliPokemonCenter/scripts.pory"
	msgbox HaouliPokemonCenter_FatMan_Text_0
# 24 "data/maps/HaouliPokemonCenter/scripts.pory"
	waitmessage
# 25 "data/maps/HaouliPokemonCenter/scripts.pory"
	release
	end


HaouliPokemonCenter_Boy::
# 30 "data/maps/HaouliPokemonCenter/scripts.pory"
	lock
# 31 "data/maps/HaouliPokemonCenter/scripts.pory"
	faceplayer
# 32 "data/maps/HaouliPokemonCenter/scripts.pory"
	msgbox HaouliPokemonCenter_Boy_Text_0
# 37 "data/maps/HaouliPokemonCenter/scripts.pory"
	waitmessage
# 38 "data/maps/HaouliPokemonCenter/scripts.pory"
	release
	end


HaouliPokemonCenter_LittleBoy::
# 43 "data/maps/HaouliPokemonCenter/scripts.pory"
	lock
# 44 "data/maps/HaouliPokemonCenter/scripts.pory"
	faceplayer
# 45 "data/maps/HaouliPokemonCenter/scripts.pory"
	msgbox HaouliPokemonCenter_LittleBoy_Text_0
# 52 "data/maps/HaouliPokemonCenter/scripts.pory"
	waitmessage
# 53 "data/maps/HaouliPokemonCenter/scripts.pory"
	release
	end


HaouliPokemonCenter_Script_MartRight::
# 58 "data/maps/HaouliPokemonCenter/scripts.pory"
	lock
# 59 "data/maps/HaouliPokemonCenter/scripts.pory"
	faceplayer
# 60 "data/maps/HaouliPokemonCenter/scripts.pory"
	msgbox HaouliPokemonCenter_Script_MartRight_Text_0
# 62 "data/maps/HaouliPokemonCenter/scripts.pory"
	waitmessage
# 63 "data/maps/HaouliPokemonCenter/scripts.pory"
	pokemart HaouliPokemonCenter_MartRight_Items
# 64 "data/maps/HaouliPokemonCenter/scripts.pory"
	msgbox HaouliPokemonCenter_Script_MartRight_Text_1
# 65 "data/maps/HaouliPokemonCenter/scripts.pory"
	release
	end


HaouliPokemonCenter_Script_MartLeft::
# 70 "data/maps/HaouliPokemonCenter/scripts.pory"
	lock
# 71 "data/maps/HaouliPokemonCenter/scripts.pory"
	faceplayer
# 72 "data/maps/HaouliPokemonCenter/scripts.pory"
	gettime
# 73 "data/maps/HaouliPokemonCenter/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8000
# 74 "data/maps/HaouliPokemonCenter/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8001
# 75 "data/maps/HaouliPokemonCenter/scripts.pory"
	msgbox HaouliPokemonCenter_Script_MartLeft_Text_0
# 82 "data/maps/HaouliPokemonCenter/scripts.pory"
	waitmessage
# 83 "data/maps/HaouliPokemonCenter/scripts.pory"
	pokemart HaouliPokemonCenter_MartLeft_Items
# 84 "data/maps/HaouliPokemonCenter/scripts.pory"
	msgbox HaouliPokemonCenter_Script_MartLeft_Text_1
# 85 "data/maps/HaouliPokemonCenter/scripts.pory"
	release
	end


	.align 2
# 89 "data/maps/HaouliPokemonCenter/scripts.pory"
HaouliPokemonCenter_MartRight_Items:
# 90 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_POKE_BALL
# 91 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_POTION
# 92 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 93 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 94 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_AWAKENING
# 95 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 96 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 97 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_REPEL
	.2byte ITEM_NONE

	.align 2
# 100 "data/maps/HaouliPokemonCenter/scripts.pory"
HaouliPokemonCenter_MartLeft_Items:
# 101 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_LEMONADE
# 102 "data/maps/HaouliPokemonCenter/scripts.pory"
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_NONE

HaouliPokemonCenter_FatMan_Text_0:
# 22 "data/maps/HaouliPokemonCenter/scripts.pory"
	.string "Any Trainer can have their Pokémon\n"
	.string "healed or use the PC here for free.$"

HaouliPokemonCenter_Boy_Text_0:
# 32 "data/maps/HaouliPokemonCenter/scripts.pory"
	.string "You can have up to six Pokémon on\n"
	.string "your team when walking around.\p"
	.string "Catch any more than that, and you'll\n"
	.string "have to send 'em to your PC boxes$"

HaouliPokemonCenter_LittleBoy_Text_0:
# 45 "data/maps/HaouliPokemonCenter/scripts.pory"
	.string "You can buy and sell things at the\n"
	.string "Poké Mart.\p"
	.string "I feel better with a Bag full of plenty\n"
	.string "of Potions and Poké Balls.\p"
	.string "What about you?$"

HaouliPokemonCenter_Script_MartRight_Text_0:
# 60 "data/maps/HaouliPokemonCenter/scripts.pory"
	.string "Welcome to the Poké Mart!\n"
	.string "May I help you?$"

HaouliPokemonCenter_Script_MartRight_Text_1:
# 64 "data/maps/HaouliPokemonCenter/scripts.pory"
	.string "Please come again!$"

HaouliPokemonCenter_Script_MartLeft_Text_0:
# 75 "data/maps/HaouliPokemonCenter/scripts.pory"
	.string "Welcome to the Pokémon Center Cafe!\n"
	.string "It's about {STR_VAR_1}:{STR_VAR_2} now in Alola.\p"
	.string "Here in our café space, we provide a\n"
	.string "moment of peace to our customers.\p"
	.string "What can I get started for you today?$"

HaouliPokemonCenter_Script_MartLeft_Text_1:
# 84 "data/maps/HaouliPokemonCenter/scripts.pory"
	.string "Please come visit us again soon!$"
