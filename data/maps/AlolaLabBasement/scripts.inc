AlolaLabBasement_MapScripts::
	.byte 0


AlolaLabBasement_Polywhirl::
# 4 "data/maps/AlolaLabBasement/scripts.pory"
	lock
# 5 "data/maps/AlolaLabBasement/scripts.pory"
	faceplayer
# 6 "data/maps/AlolaLabBasement/scripts.pory"
	playmoncry SPECIES_POLIWHIRL, 0
# 7 "data/maps/AlolaLabBasement/scripts.pory"
	msgbox AlolaLabBasement_Polywhirl_Text_0
# 8 "data/maps/AlolaLabBasement/scripts.pory"
	waitmoncry
# 9 "data/maps/AlolaLabBasement/scripts.pory"
	release
	end


AlolaLabBasement_MovesBookcaseLeft::
# 14 "data/maps/AlolaLabBasement/scripts.pory"
	lock
# 15 "data/maps/AlolaLabBasement/scripts.pory"
	helpwindow HELP_NUMBER_OF_MOVES_1, 1
# 16 "data/maps/AlolaLabBasement/scripts.pory"
	helpwindow HELP_NUMBER_OF_MOVES_2, 1
# 17 "data/maps/AlolaLabBasement/scripts.pory"
	helpwindow HELP_NUMBER_OF_MOVES_3, 2
# 18 "data/maps/AlolaLabBasement/scripts.pory"
	release
	end


AlolaLabBasement_MovesBookcaseRight::
# 23 "data/maps/AlolaLabBasement/scripts.pory"
	lock
# 24 "data/maps/AlolaLabBasement/scripts.pory"
	helpwindow HELP_CLASSIFICATION_OF_MOVES_1, 1
# 25 "data/maps/AlolaLabBasement/scripts.pory"
	helpwindow HELP_CLASSIFICATION_OF_MOVES_2, 1
# 26 "data/maps/AlolaLabBasement/scripts.pory"
	helpwindow HELP_CLASSIFICATION_OF_MOVES_3, 1
# 27 "data/maps/AlolaLabBasement/scripts.pory"
	helpwindow HELP_CLASSIFICATION_OF_MOVES_4, 2
# 28 "data/maps/AlolaLabBasement/scripts.pory"
	release
	end


AlolaLabBasement_KukuiComputer::
# 33 "data/maps/AlolaLabBasement/scripts.pory"
	lock
# 34 "data/maps/AlolaLabBasement/scripts.pory"
	msgbox AlolaLabBasement_KukuiComputer_Text_0, MSGBOX_AUTOCLOSE
# 38 "data/maps/AlolaLabBasement/scripts.pory"
	waitmessage
# 39 "data/maps/AlolaLabBasement/scripts.pory"
	release
	end


AlolaLabBasement_FishTank::
# 44 "data/maps/AlolaLabBasement/scripts.pory"
	msgbox AlolaLabBasement_FishTank_Text_0, MSGBOX_SIGN
	end


AlolaLabBasement_Polywhirl_Text_0:
# 7 "data/maps/AlolaLabBasement/scripts.pory"
	.string "Goosh!$"

AlolaLabBasement_KukuiComputer_Text_0:
# 34 "data/maps/AlolaLabBasement/scripts.pory"
	.string "It's Profesor Kukui's PC!\p"
	.string "All the research data on Pokémon moves\n"
	.string "is very nearly organized!$"

AlolaLabBasement_FishTank_Text_0:
# 44 "data/maps/AlolaLabBasement/scripts.pory"
	.string "Inside the tank is the Sea Cucumber\n"
	.string "Pokémon, Pyukumuku.$"
