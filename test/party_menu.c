#include "global.h"
#include "battle.h"
#include "party_menu.h"
#include "pokemon.h"
#include "test/test.h"

#define TEST_MENU_DIR_DOWN     1
#define TEST_MENU_DIR_UP      -1
#define TEST_MENU_DIR_LEFT    -2
#define TEST_MENU_DIR_RIGHT    2

static void SetTestPartySize(enum BattleTrainer trainer, u8 partySize)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[trainer][i]);

    for (u32 i = 0; i < partySize; i++)
        CreateMon(&gParties[trainer][i], SPECIES_WOBBUFFET, 50, 0, OTID_STRUCT_PRESET(0));

    gPartiesCount[trainer] = partySize;
}

TEST("Full multi partner party menu stops down navigation at partner party count")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    SetTestPartySize(B_TRAINER_PARTNER, 2);
    gPartyMenu.layout = PARTY_LAYOUT_MULTI_FULL_PARTNER;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(1, TEST_MENU_DIR_DOWN, FALSE, 0), PARTY_SIZE + 1);
}

TEST("Full multi partner party menu allows down navigation through partner party count")
{
    SetTestPartySize(B_TRAINER_PLAYER, 2);
    SetTestPartySize(B_TRAINER_PARTNER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_MULTI_FULL_PARTNER;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(1, TEST_MENU_DIR_DOWN, FALSE, 0), 3);
}

TEST("Full multi partner party menu wraps cancel up to partner party count")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    SetTestPartySize(B_TRAINER_PARTNER, 2);
    gPartyMenu.layout = PARTY_LAYOUT_MULTI_FULL_PARTNER;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(PARTY_SIZE + 1, TEST_MENU_DIR_UP, FALSE, 0), 1);
}

TEST("Single party menu moves right across the top row")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(0, TEST_MENU_DIR_RIGHT, FALSE, 0), 1);
}

TEST("Single party menu moves left across the middle row")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(3, TEST_MENU_DIR_LEFT, FALSE, 0), 2);
}

TEST("Single party menu moves down within the same column")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(1, TEST_MENU_DIR_DOWN, FALSE, 0), 3);
}

TEST("Single party menu moves up within the same column")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(2, TEST_MENU_DIR_UP, FALSE, 0), 0);
}

TEST("Single party menu up from top row stays in grid")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(0, TEST_MENU_DIR_UP, FALSE, 0), 0);
}

TEST("Single party menu down from bottom row goes to cancel")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(4, TEST_MENU_DIR_DOWN, FALSE, 0), PARTY_SIZE + 1);
}

TEST("Choose-half menu down from bottom-left goes to confirm")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(4, TEST_MENU_DIR_DOWN, TRUE, 0), PARTY_SIZE);
}

TEST("Choose-half menu down from bottom-right goes to cancel")
{
    SetTestPartySize(B_TRAINER_PLAYER, PARTY_SIZE);
    gPartyMenu.layout = PARTY_LAYOUT_SINGLE;

    EXPECT_EQ(Test_UpdatePartySelectionSingleLayout(5, TEST_MENU_DIR_DOWN, TRUE, 0), PARTY_SIZE + 1);
}
