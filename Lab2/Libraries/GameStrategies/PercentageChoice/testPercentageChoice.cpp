#include "PercentageChoice/PercentageChoice.h"
#include <gtest/gtest.h>
#include "../GameMatrix/Voice.h"

class PercentageChoiceArguments {
public:
    PercentageChoiceArguments() = default;
    Voice player1, player2, player3;
    PercentageChoiceArguments(Voice _player1, Voice _player2, Voice _player3) : player1(_player1),
                                                                                player2(_player2),
                                                                                player3(_player3) {}
};


class TestForFunctionsUpdateVoice : public ::testing::TestWithParam<PercentageChoiceArguments> {};

INSTANTIATE_TEST_SUITE_P(
        CollectiveStrategyTest,
        TestForFunctionsUpdateVoice,
        ::testing::Values(
            PercentageChoiceArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)DEFECT),
            PercentageChoiceArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)DEFECT),
            PercentageChoiceArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)DEFECT),
            PercentageChoiceArguments((Voice)DEFECT, (Voice)COOPERATE, (Voice)DEFECT),
            PercentageChoiceArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)DEFECT),
            PercentageChoiceArguments((Voice)COOPERATE, (Voice)DEFECT, (Voice)DEFECT),
            PercentageChoiceArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)DEFECT))
);

TEST_P(TestForFunctionsUpdateVoice, TestPercentageChoice) {
    PercentageChoice percentageChoice("ConfigFile");
    PercentageChoiceArguments  value = GetParam();
    ASSERT_EQ(percentageChoice.vote(), value.player3);
    percentageChoice.update(value.player1, value.player2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}