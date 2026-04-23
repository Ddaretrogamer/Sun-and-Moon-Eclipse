AetherConservatory_MapScripts::
	.byte 0


UseElevator::
# 4 "data/maps/AetherConservatory/scripts.pory"
	lockall
# 5 "data/maps/AetherConservatory/scripts.pory"
	msgbox UseElevator_Text_0, MSGBOX_YESNO
# 9 "data/maps/AetherConservatory/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq UseElevator_1
# 16 "data/maps/AetherConservatory/scripts.pory"
	waitmessage
# 17 "data/maps/AetherConservatory/scripts.pory"
	releaseall
	end

UseElevator_1:
# 10 "data/maps/AetherConservatory/scripts.pory"
	warp MAP_HAUOLI_DOCK_BOATHOUSE, 13, 9
# 11 "data/maps/AetherConservatory/scripts.pory"
	delay 30
# 12 "data/maps/AetherConservatory/scripts.pory"
	release
	end


UseElevator_Text_0:
# 5 "data/maps/AetherConservatory/scripts.pory"
	.string "This elevator will take you back to the\n"
	.string "Hau'oli City Docks.\p"
	.string "Would you like to use it?$"
