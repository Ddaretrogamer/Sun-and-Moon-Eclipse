IkitownHouseOne_MapScripts::
	.byte 0


IkitownHouseOne_ManDialog::
# 4 "data/maps/IkitownHouseOne/scripts.pory"
	lock
# 5 "data/maps/IkitownHouseOne/scripts.pory"
	faceplayer
# 6 "data/maps/IkitownHouseOne/scripts.pory"
	msgbox IkitownHouseOne_ManDialog_Text_0
# 11 "data/maps/IkitownHouseOne/scripts.pory"
	waitmessage
# 12 "data/maps/IkitownHouseOne/scripts.pory"
	release
	end


IkitownHouseOne_WomanDialog::
# 17 "data/maps/IkitownHouseOne/scripts.pory"
	lock
# 18 "data/maps/IkitownHouseOne/scripts.pory"
	faceplayer
# 19 "data/maps/IkitownHouseOne/scripts.pory"
	msgbox IkitownHouseOne_WomanDialog_Text_0
# 27 "data/maps/IkitownHouseOne/scripts.pory"
	waitmessage
# 28 "data/maps/IkitownHouseOne/scripts.pory"
	release
	end


IkitownHouseOne_ManDialog_Text_0:
# 6 "data/maps/IkitownHouseOne/scripts.pory"
	.string "Opening a window lets night come\n"
	.string "creeping in.\p"
	.string "If you leave one open, it'll make you\n"
	.string "sleepy.$"

IkitownHouseOne_WomanDialog_Text_0:
# 19 "data/maps/IkitownHouseOne/scripts.pory"
	.string "Ahh… On lovely calm days like this one,\n"
	.string "I always think of my brother…\p"
	.string "When we were young, he always worked so\n"
	.string "hard to collect sand from the beach.\p"
	.string "Where could he be now?\n"
	.string "What must he be doing?$"
