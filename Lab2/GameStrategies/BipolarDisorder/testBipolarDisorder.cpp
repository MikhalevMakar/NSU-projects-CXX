#include "BipolarDisorder/BipolarDisorder.h"
#include <gtest/gtest.h>
#include "../GameMatrix/Voice.h"

class BipolarDisorderArguments {
public:
    BipolarDisorderArguments() = default;
    Voice player1, player2, player3;
    BipolarDisorderArguments(Voice _player1, Voice _player2, Voice _player3) : player1(_player1),
                                                                               player2(_player2),
                                                                               player3(_player3) {}
};


class TestForFunctionsUpdateVoice : public ::testing::TestWithParam<BipolarDisorderArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BipolarDisorderTest,
        TestForFunctionsUpdateVoice,
        ::testing::Values(
            BipolarDisorderArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)COOPERATE),
            BipolarDisorderArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)COOPERATE),
            BipolarDisorderArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)COOPERATE),
            BipolarDisorderArguments((Voice)DEFECT, (Voice)COOPERATE, (Voice)COOPERATE),
            BipolarDisorderArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)COOPERATE),
            BipolarDisorderArguments(COOPERATE, DEFECT, (Voice)COOPERATE),
            BipolarDisorderArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)COOPERATE))
);

TEST_P(TestForFunctionsUpdateVoice, TestBipolarDisorder) {
    BipolarDisorder bipolarDisorder("ConfigFile");
    BipolarDisorderArguments  value = GetParam();
    ASSERT_EQ(bipolarDisorder.vote(), value.player3);
    bipolarDisorder.update(value.player1, value.player2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}