#include "GameMatrix/GameMatrix.h"
#include <gtest/gtest.h>
#include "GameMatrix/Voice.h"
#include <array>
#include <iostream>
std::array< std::array<int, 3>, 8> matrix_point =
        { { {7, 7, 7},
            {3, 3, 9},
            {3, 9, 3},
            {9, 3, 3},
            {0, 5, 5},
            {5, 0, 5},
            {5, 5, 0},
            {1, 1, 1} } };

std::array< std::string, 8>matrix_voice = {{ {"CCC"},
                                             {"CCD"},
                                             {"CDC"},
                                             {"DCC"},
                                             {"CDD"},
                                             {"DCD"},
                                             {"DDC"},
                                             {"DDD"} }};

TEST(test_constructors, TestMatrix) {
    GameMatrix matrix;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(matrix.matrixPoint[i][j], matrix_point[i][j]);
            EXPECT_EQ(matrix.matrixVoice[i], matrix_voice[i]);
        }
    }
}

TEST(test_updateGivenGameMatrix, TestMatrix) {
    GameMatrix matrix;
    matrix.updateGivenGameMatrix("matrix");
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(matrix.matrixVoice[i][j], matrix_voice[i][j]);
            EXPECT_EQ(matrix.matrixVoice[i], matrix_voice[i]);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}