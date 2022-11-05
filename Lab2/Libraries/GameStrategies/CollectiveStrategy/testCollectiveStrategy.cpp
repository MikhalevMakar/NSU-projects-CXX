#include "CollectiveStrategy/CollectiveStrategy.h"
#include <gtest/gtest.h>
#include "../GameMatrix/Voice.h"

class CollectiveStrategyArguments {
public:
    CollectiveStrategyArguments() = default;
    Voice player1, player2, player3;
    CollectiveStrategyArguments(Voice _player1, Voice _player2, Voice _player3) : player1(_player1),
                                                                                  player2(_player2),
                                                                                  player3(_player3) {}
};


class TestForFunctionsUpdateVoice : public ::testing::TestWithParam<CollectiveStrategyArguments> {};

INSTANTIATE_TEST_SUITE_P(
        CollectiveStrategyTest,
        TestForFunctionsUpdateVoice,
        ::testing::Values(
        CollectiveStrategyArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)DEFECT),
CollectiveStrategyArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)DEFECT),
CollectiveStrategyArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)DEFECT),
CollectiveStrategyArguments((Voice)DEFECT, (Voice)COOPERATE, (Voice)DEFECT),
CollectiveStrategyArguments((Voice)COOPERATE, (Voice)COOPERATE, (Voice)DEFECT),
CollectiveStrategyArguments((Voice)COOPERATE, (Voice)DEFECT, (Voice)DEFECT),
CollectiveStrategyArguments((Voice)DEFECT, (Voice)DEFECT, (Voice)COOPERATE))
);

TEST_P(TestForFunctionsUpdateVoice, TestCollectiveStrategy) {
CollectiveStrategy collectiveStrategy("ConfigFile");
CollectiveStrategyArguments  value = GetParam();
ASSERT_EQ(collectiveStrategy.vote(), value.player3);
collectiveStrategy.update(value.player1, value.player2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}