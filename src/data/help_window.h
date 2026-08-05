// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_START_MENU] =
    {
        .header = COMPOUND_STRING("Information: Pokédex"),
        .desc = COMPOUND_STRING("To access the Pokédex, press {START_BUTTON}\n"
                                "while you're in the overworld!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL
    },
    [HELP_MEGA_EVOLUTION] =
    {
        .header = COMPOUND_STRING("Information: Mega Evolution"),
        .desc = COMPOUND_STRING("In battle, press {START_BUTTON} to Mega Evolve!\n\n"
                                "The Pokémon must hold their Mega Stone\n"
                                "to be able to Mega Evolve.\n"
                                "You can only Mega Evolve once per battle."
                            ),
    },
    [HELP_MASTER_BALL] =
    {
        .header = COMPOUND_STRING("Information: Master Ball"),
        .desc = COMPOUND_STRING("There is only one Master Ball in Pokémon;\n"
                                "use it wisely!\n"
                                "Professor Oak suggests using it on a Pokémon\n"
                                "you want to add to your team but are hard to\n"
                                "catch, like a Fearow or Tentacruel!"
                            ),
    },
    [HELP_GIMMIGHOUL_COINS] =
    {
        .header = COMPOUND_STRING("Information: Evolving Gimmighoul into Gholdengo"),
        .desc = COMPOUND_STRING("To evolve Gimmighoul into Gholdengo, you\n"
                                "need to gather 999 {COLOR RED}Gimmighoul Coins{COLOR DARK_GRAY}.\n\n"
                                "You can find Gimmighoul Coins scattered\n"
                                "all around Paldea."
                            ),
        .headerFont = FONT_NARROWER,
    },
    [HELP_ADVENTURE_GUIDE] =
    {
        .header = COMPOUND_STRING("ADVENTURE GUIDE"),
        .desc = COMPOUND_STRING("ADVENTURE RULE NO. 1\n"
                                "Open the Start Menu by pressing {START_BUTTON}.\n\n"
                                "ADEVENTURE RULE NO. 2\n"
                                "You can save your progress by selecting the\n"
                                "“Save” option in the Start Menu."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_CATCHING_GUIDE] =
    {
        .header = COMPOUND_STRING("KUKUI'S CATCHING GUIDE"),
        .desc = COMPOUND_STRING("CATCHING TIP NO. 1\n"
                                "You've gotta weaken a Pokémon up a bit before\n"
                                "you try lobbing a Poké Ball at it!\n\n"
                                "CATCHING TIP NO. 2\n"
                                "Status conditions like Sleep or Paralysis can\n"
                                "make it easier to catch Pokémon."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_OVERWORLD_MON_GUIDE] =
    {
        .header = COMPOUND_STRING("OVERWORLD POKéMON GUIDE"),
        .desc = COMPOUND_STRING("ABOUT OVERWORLD POKéMON ENCOUNTERS:\n"
                                "When enabled, Pokémon will appear in the\n"
                                "overworld. Interact with them to start a\n"
                                "battle!\n"
                                "TO ENABLE OVERWORLD POKéMON ENCOUNTERS:\n"
                                "Open the options menu and press {R_BUTTON} and\n"
                                "scroll down to toggle overworld encounters."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_ROTOM_PHONE_GUIDE] =
    {
        .header = COMPOUND_STRING("ABOUT THE ROTOM PHONE"),
        .desc = COMPOUND_STRING("The Rotom Phone is a device that allows you\n"
                                "to access various features, such as the\n"
                                "Pokédex, map, and more.\n"
                                "ROTOM REALITY:\n"
                                "The Rotom Phone has a feature called\n"
                                "Rotom Reality, which opens a larger\n"
                                "display with more applications."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_NUMBER_OF_MOVES_1] =
    {
        .header = COMPOUND_STRING("ON THE NUMBER OF POKéMON MOVES"),
        .desc = COMPOUND_STRING("As of this writing, scholars in this field\n"
                                "have identified more than 600 distinct moves\n"
                                "that can be used by Pokémon in battle."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_NUMBER_OF_MOVES_2] =
    {
        .header = COMPOUND_STRING("ON THE NUMBER OF POKéMON MOVES"),
        .desc = COMPOUND_STRING("Yet each Pokémon is only able to remember a\n"
                                "maximum of four moves at a time.\n\n"
                                "To learn a fifth move, it must forget one of\n"
                                "the other moves it knows."
        ),
        .headerFont = FONT_NARROW,
    },
    [HELP_NUMBER_OF_MOVES_3] =
    {
        .header = COMPOUND_STRING("ON THE NUMBER OF POKéMON MOVES"),
        .desc = COMPOUND_STRING("Additionally, it must be noted that there are\n"
                                "also many different ways through which\n"
                                "Pokémon are able to learn moves.\n\n"
                                "There is still much for us to learn about the\n"
                                "relationship of Pokémon and their moves."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_CLASSIFICATION_OF_MOVES_1] =
    {
        .header = COMPOUND_STRING("ON THE CLASSIFICATION OF POKéMON MOVES"),
        .desc = COMPOUND_STRING("Pokémon moves can be divided into three broad\n"
                                "categories: physical moves, special moves,\n"
                                "and of course, status moves."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_CLASSIFICATION_OF_MOVES_2] =
    {
        .header = COMPOUND_STRING("PHYSICAL MOVES"),
        .desc = COMPOUND_STRING("Moves that attack an opponent, dealing\n"
                                "damage based upon the Attack stat of the\n"
                                "Pokémon using the move and the Defense\n"
                                "stat of the Pokémon on the receiving side."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_CLASSIFICATION_OF_MOVES_3] =
    {
        .header = COMPOUND_STRING("SPECIAL MOVES"),
        .desc = COMPOUND_STRING("Moves that attack an opponent, dealing\n"
                                "damage based upon the Sp. Attack stat of\n"
                                "the Pokémon using the move and the\n"
                                "Sp. Defense stat of the Pokémon on the\n"
                                "receiving side."
                            ),
        .headerFont = FONT_NARROW,
    },
    [HELP_CLASSIFICATION_OF_MOVES_4] =
    {
        .header = COMPOUND_STRING("STATUS MOVES"),
        .desc = COMPOUND_STRING("Moves that have effects other than directly\n"
                                "attacking another target in battle."
                            ),
        .headerFont = FONT_NARROW,
    },
    // Add more entries
};
