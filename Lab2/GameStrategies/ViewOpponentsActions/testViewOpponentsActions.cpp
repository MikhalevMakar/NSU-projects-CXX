#include "ViewOpponentsActions/ViewOpponentsActions.h"
#include <gtest/gtest.h>
#include "../GameMatrix/Voice.h"

class ViewOpponentsActionsArguments {
public:
    ViewOpponentsActionsArguments() = default;
    Voice player1, player2, player3;
    ViewOpponentsActionsArguments(Voice _player1, Voice _player2, Voice _player3) : player1(_player1),
                                                                                    player2(_player2),
                                                                                    player3(_player3) {}
};


class TestForFunctionsUpdateVoice : public ::testing::TestWithParam<ViewOpponentsActionsArguments> {};

INSTANTIATE_TEST_SUITE_P(
        ViewOpponentsActionsTest,
        TestForFunctionsUpdateVoice,
        ::testing::Values(
            ViewOpponentsActionsArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)COOPERATE),
            ViewOpponentsActionsArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)COOPERATE),
            ViewOpponentsActionsArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)COOPERATE),
            ViewOpponentsActionsArguments((Voice)DEFECT, (Voice)COOPERATE, (Voice)COOPERATE),
            ViewOpponentsActionsArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)COOPERATE),
            ViewOpponentsActionsArguments((Voice)COOPERATE, (Voice)DEFECT, (Voice)COOPERATE),
            ViewOpponentsActionsArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)COOPERATE))
);

TEST_P(TestForFunctionsUpdateVoice, TestViewOpponentsActions) {
    ViewOpponentsActions viewOpponentsActions("ConfigFile");
    ViewOpponentsActionsArguments  value = GetParam();
    ASSERT_EQ(viewOpponentsActions.vote(), value.player3);
    viewOpponentsActions.update(value.player1, value.player2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}