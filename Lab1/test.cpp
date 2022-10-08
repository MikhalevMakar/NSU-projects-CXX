#include <iostream>
#include <gtest/gtest.h>
#include "BigInt.h"

class BigIntArguments {
public:
    BigInt firstArg;
    BigInt secondArg;
    std::string result;
    BigIntArguments(BigInt firstArg, BigInt secondArg, std::string result);
    BigIntArguments(BigInt firstArg, std::string result);
};


BigIntArguments::BigIntArguments(BigInt firstArg, BigInt secondArg, std::string result) :
                    firstArg(std::move(firstArg)),
                    secondArg(std::move(secondArg)),
                    result(std::move(result)) {}


BigIntArguments::BigIntArguments(BigInt firstArg, std::string result) :
        firstArg(std::move(firstArg)),
        result(std::move(result)) {}


TEST(BigIntTest, TestConstructorInt) {
    BigInt value1(1294349);
    BigInt value2(-123422433);
    ASSERT_EQ("1294349", (std::string)value1);
    ASSERT_EQ("-123422433", (std::string)value2);
};

TEST(BigIntTest, TestConstructorBigInt) {
    BigInt value1(1294349);
    BigInt value2(value1);
    ASSERT_EQ((std::string)value1, (std::string)value2);
};

TEST(BigIntTest, TestConstructorString) {
    BigInt value1("1294349");
    ASSERT_EQ((std::string)value1, (std::string)value1);
    ASSERT_THROW({BigInt value2("13243543qafe243");}, std::invalid_argument);
};

TEST(BigIntTest, TestOperatorString) {
    BigInt value("1294349");
    ASSERT_EQ((std::string)value, "1294349");
};

TEST(BigIntTest, TestSize) {
    BigInt value1("-1294349687657575");
    BigInt value2(4532456);
    ASSERT_EQ(value1.size(), 3);
    ASSERT_EQ(value2.size(), 2);
};

TEST(BigIntTest, TestOperatorInt) {
    BigInt value1(-4532456);
    BigInt value2("1294349687657575");
    ASSERT_EQ((int)value1, -4532456);
    ASSERT_THROW({(int)value2;}, std::invalid_argument);
};

TEST(BigIntTest, TestOperatorTilde) {
    BigInt value1(-4532456);
    BigInt value2("1294349687657575");
    ASSERT_EQ((std::string)~value1, "4532457");
    ASSERT_EQ((std::string)~value2, "-1294349687657576");
};

TEST(BigIntTest, TestOperatorEquality) {
    BigInt value1(-4532456);
    BigInt value2("1294349687657575");
    value1 = value2;
    value2 = value1;
    ASSERT_EQ((std::string)value1, "1294349687657575");
    ASSERT_EQ((std::string)value2, "1294349687657575");
};

class BigIntIncrement : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntIncrement,
        ::testing::Values(
                BigIntArguments(BigInt("100"), "101"),
                BigIntArguments(BigInt("-1"), "0"),
                BigIntArguments(BigInt("999999999"), "1000000000"),
                BigIntArguments(BigInt("-1000000000"), "-999999999"))
);

TEST_P(BigIntIncrement, TestPrefixIncrement) {
    BigIntArguments v = GetParam();
    ++v.firstArg;
    ASSERT_EQ(v.result, (std::string)v.firstArg);
}

TEST_P(BigIntIncrement, TestPostfixIncrement) {
    BigIntArguments v = GetParam();
    v.firstArg++;
    ASSERT_EQ(v.result, (std::string)v.firstArg);
}

class BigIntDecrement : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntDecrement,
        ::testing::Values(
                BigIntArguments(BigInt("100"), "99"),
                BigIntArguments(BigInt("0"), "-1"),
                BigIntArguments(BigInt("1000000000"), "999999999"),
                BigIntArguments(BigInt("-999999999"), "-1000000000"))
);

TEST_P(BigIntDecrement, TestPrefDecrement) {
    BigIntArguments v = GetParam();
    --v.firstArg;
    ASSERT_EQ(v.result, (std::string)v.firstArg);
}

TEST_P(BigIntDecrement, TestPostDecrement) {
    BigIntArguments v = GetParam();
    v.firstArg--;
    ASSERT_EQ(v.result, (std::string)v.firstArg);
}

class BigIntOperatorUnary : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorUnary,
        ::testing::Values(
                BigIntArguments (BigInt("378434256432"), "378434256432"),
                BigIntArguments (BigInt("-243543244873"), "-243543244873"))
);

TEST_P(BigIntOperatorUnary, TestUnaryPlus) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(+value.firstArg), value.result);
}

TEST_P(BigIntOperatorUnary, TestUnaryMinus) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(-(-value.firstArg)), value.result);
}

class BigIntTestComparse : public ::testing::Test {
public:
    BigInt *vector1{}, *vector2{}, *vector3{}, *vector4{}, *vector5{}, *vector6{}, *vector7{};
protected:
    void SetUp() override {
        vector1 = new BigInt("2356789098789878");
        vector2 = new BigInt("-567678987667898767");
        vector3 = new BigInt("12567673456789239994839");
        vector4 = new BigInt("789327222728228344");
        vector5 = new BigInt("-345565");
        vector6 = new BigInt("-3456789343546789897654456");
        vector7 = new BigInt("789327222728228341");

    }
    void TearDown() override {
        delete vector1;
        delete vector2;
        delete vector3;
        delete vector4;
        delete vector5;
        delete vector6;
        delete vector7;
    }
};

TEST_F(BigIntTestComparse, checOperatorCoomparseMore) {
    ASSERT_EQ((*vector1) < (*vector2), false);
    ASSERT_EQ((*vector2) < (*vector5), true);
    ASSERT_EQ((*vector3) < (*vector4), false);
    ASSERT_EQ((*vector3) < (*vector4), false);
    ASSERT_EQ((*vector4) < (*vector3), true);
    ASSERT_EQ((*vector6) < (*vector2), true);
    ASSERT_EQ((*vector6) < (*vector5), true);
    ASSERT_EQ((*vector7) < (*vector4), true);
    ASSERT_EQ((*vector7) < (*vector7), false);
    ASSERT_EQ((*vector7) < (*vector7), false);
    ASSERT_EQ((*vector6) < (*vector6), false);
}

TEST_F(BigIntTestComparse, checOperatorCoomparseLess) {
    ASSERT_EQ((*vector1) > (*vector2), true);
    ASSERT_EQ((*vector2) > (*vector6), true);
    ASSERT_EQ((*vector7) > (*vector7), false);
    ASSERT_EQ((*vector3) > (*vector4), true);
    ASSERT_EQ((*vector5) > (*vector6), true);
    ASSERT_EQ((*vector6) > (*vector6), false);
}

TEST_F(BigIntTestComparse, checOperatorCoomparseEquals) {
    ASSERT_EQ((*vector4) == (*vector2), false);
    ASSERT_EQ((*vector2) == (*vector2), true);
    ASSERT_EQ((*vector7) == (*vector7), true);
    ASSERT_EQ((*vector3) == (*vector5), false);
    ASSERT_EQ((*vector2) == (*vector6), false);
}

TEST_F(BigIntTestComparse, checOperatorCoomparseNonEquals) {
    ASSERT_EQ((*vector4) != (*vector2), true);
    ASSERT_EQ((*vector2) != (*vector2), false);
    ASSERT_EQ((*vector7) != (*vector7), false);
    ASSERT_EQ((*vector3) != (*vector5), true);
    ASSERT_EQ((*vector2) != (*vector6), true);
}

class BigIntOperatorSum : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorSum,
        ::testing::Values(
                BigIntArguments (BigInt("123432432"), BigInt("4353453"), "127785885"),
                BigIntArguments (BigInt("4787473298642"), BigInt("33457367"), "4787506756009"),
                BigIntArguments (BigInt("33457367"), BigInt("4787473298642"), "4787506756009"),
                BigIntArguments (BigInt("33457367"), BigInt("-4787473298642"), "-4787439841275"),
                BigIntArguments (BigInt("-378238942347"), BigInt("-4787473298642"), "-5165712240989"))
);

TEST_P(BigIntOperatorSum, TestSumOneArg) {
    BigIntArguments value = GetParam();
    value.firstArg += value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorSum, TestSumPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(value.firstArg + value.secondArg), value.result);
}

class BigIntOperatorDiff : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorDiff,
        ::testing::Values(
                BigIntArguments (BigInt("8734632463"), BigInt("34893264786874"), "-34885469845589"),
                BigIntArguments (BigInt("0"), BigInt("0"), "0"),
                BigIntArguments (BigInt("-3484789"), BigInt("-3467863242782"), "-3467859757993"))
);

TEST_P(BigIntOperatorDiff, TestDiffOneArg) {
    BigIntArguments value = GetParam();
    value.firstArg -= value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorDiff, TestDiffPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)( value.firstArg - value.secondArg), value.result);
}

class BigIntOperatorMult : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorMult,
        ::testing::Values(
                BigIntArguments (BigInt("34242343"), BigInt("43243424"), "1480756157102432"),
                BigIntArguments (BigInt("0"), BigInt("0"), "0"),
                BigIntArguments (BigInt("-4385739472"), BigInt("-428479749827"), "1879200551768959071344"),
                BigIntArguments (BigInt("3487379"), BigInt("-2487349728482"), "-8674331208763828678"))
);

TEST_P(BigIntOperatorMult, TestMultOneArg) {
    BigIntArguments value = GetParam();
    value.firstArg *= value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorMult, TestMultPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(value.firstArg * value.secondArg), value.result);
}

class BigIntOperatorDiv : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorDiv,
        ::testing::Values(
                BigIntArguments (BigInt("34827479"), BigInt("32474732864823"), "0"),
                BigIntArguments (BigInt("0"), BigInt("4829384"), "0"),
                BigIntArguments (BigInt("-374827349342"), BigInt("-3428374"), "109330"),
                BigIntArguments (BigInt("7632478664"), BigInt("-43782477"), "-174"))
);

TEST_P(BigIntOperatorDiv, TestDivOneArg) {
    BigIntArguments value = GetParam();
    value.firstArg /= value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorDiv, TestDivPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(value.firstArg / value.secondArg), value.result);
}

class BigIntOperatorRemainder : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorRemainder,
        ::testing::Values(
                BigIntArguments (BigInt("7632478664"), BigInt("-43782477"), "14327666"),
                BigIntArguments (BigInt("0"), BigInt("4829384"), "0"),
                BigIntArguments (BigInt("-374827349342"), BigInt("-3428374"), "3219922"),
                BigIntArguments (BigInt("7632478664"), BigInt("-43782477"), "14327666"))
);

TEST_P(BigIntOperatorRemainder, TestMultOneArg) {
    BigIntArguments value = GetParam();
    value.firstArg %= value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorRemainder, TestRemainderPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(value.firstArg % value.secondArg), value.result);
}

class BigIntOperatorAND : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorAND,
        ::testing::Values(
                BigIntArguments (BigInt("2346782943"), BigInt("3427643"), "2097179"),
                BigIntArguments (BigInt("0"), BigInt("4829384"), "0"),
                BigIntArguments (BigInt("-374827349342"), BigInt("-3428374"), "-373829729118"),
                BigIntArguments (BigInt("7632478664"), BigInt("-43782477"), "7589748864"))
);

TEST_P(BigIntOperatorAND, TestAndOneArg) {
    BigIntArguments value = GetParam();
    value.firstArg &= value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorAND, TestAndPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(value.firstArg & value.secondArg), value.result);
}

class BigIntOperatorOR : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorOR,
        ::testing::Values(
                BigIntArguments (BigInt("2346782943"), BigInt("3427643"), "2348113407"),
                BigIntArguments (BigInt("0"), BigInt("4829384"), "4829384"),
                BigIntArguments (BigInt("-374827349342"), BigInt("-3428374"), "-1048598"),
                BigIntArguments (BigInt("7632478664"), BigInt("-43782477"), "-1052677"))
);

TEST_P(BigIntOperatorOR, TestOrOneArg) {
    BigIntArguments value = GetParam();
    value.firstArg |= value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorOR, TestOrPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(value.firstArg | value.secondArg), value.result);
}

class BigIntOperatorXOR : public ::testing::TestWithParam<BigIntArguments> {};

INSTANTIATE_TEST_SUITE_P(
        BigIntTest,
        BigIntOperatorXOR,
        ::testing::Values(
                BigIntArguments (BigInt("2346782943"), BigInt("3427643"), "2346016228"),
                BigIntArguments (BigInt("0"), BigInt("4829384"), "4829384"),
                BigIntArguments (BigInt("-374827349342"), BigInt("-3428374"), "373828680520"),
                BigIntArguments (BigInt("7632478664"), BigInt("-43782477"), "-7590801541"))
);

TEST_P(BigIntOperatorXOR, TestXOROneArg) {
    BigIntArguments value = GetParam();
    value.firstArg ^= value.secondArg;
    ASSERT_EQ((std::string)value.firstArg, value.result);
}

TEST_P(BigIntOperatorXOR, TestXorPair) {
    BigIntArguments value = GetParam();
    ASSERT_EQ((std::string)(value.firstArg ^ value.secondArg), value.result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
