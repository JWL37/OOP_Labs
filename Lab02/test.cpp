#include <gtest/gtest.h>
#include "FiveDigitArray.h"

class isEqualParameterizedTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, bool>>
{
};

TEST_P(isEqualParameterizedTest, CheckIsEquals)
{
    bool expected = std::get<2>(GetParam());
    FiveDigitArray first(std::get<0>(GetParam()));
    FiveDigitArray second(std::get<1>(GetParam()));
    ASSERT_EQ(expected, first == second);
}

INSTANTIATE_TEST_CASE_P(
    isEqualTests,
    isEqualParameterizedTest,
    ::testing::Values(
        std::make_tuple("23", "13", false),
        std::make_tuple("10", "14", false),
        std::make_tuple("214", "214", true),
        std::make_tuple("0", "0", true)));

class isMoreParameterizedTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, bool>>
{
};

TEST_P(isMoreParameterizedTest, CheckIsMore)
{
    bool expected = std::get<2>(GetParam());
    FiveDigitArray first(std::get<0>(GetParam()));
    FiveDigitArray second(std::get<1>(GetParam()));
    ASSERT_EQ(expected, first > second);
}

INSTANTIATE_TEST_CASE_P(
    isMoreTests,
    isMoreParameterizedTest,
    ::testing::Values(
        std::make_tuple("23", "13", true),
        std::make_tuple("10", "14", false),
        std::make_tuple("214", "214", false)));

class isLessParameterizedTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, bool>>
{
};

TEST_P(isLessParameterizedTest, CheckIsMore)
{
    bool expected = std::get<2>(GetParam());
    FiveDigitArray first(std::get<0>(GetParam()));
    FiveDigitArray second(std::get<1>(GetParam()));
    ASSERT_EQ(expected, first < second);
}

INSTANTIATE_TEST_CASE_P(
    isLessTests,
    isLessParameterizedTest,
    ::testing::Values(
        std::make_tuple("23", "13", false),
        std::make_tuple("10", "14", true),
        std::make_tuple("214", "214", false)));

class sumFiveParameterizedTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::string>>
{
};

TEST_P(sumFiveParameterizedTest, CheckSumFive)
{
    FiveDigitArray expected(std::get<2>(GetParam()));
    FiveDigitArray first(std::get<0>(GetParam()));
    FiveDigitArray second(std::get<1>(GetParam()));
    ASSERT_EQ(expected, first + second);
}

INSTANTIATE_TEST_CASE_P(
    sumFiveTests,
    sumFiveParameterizedTest,
    ::testing::Values(
        std::make_tuple("21", "31", "102"),
        std::make_tuple("10", "14", "24"),
        std::make_tuple("0", "0", "0"),
        std::make_tuple("2", "3", "10")));

class subtractFiveParameterizedTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::string>>
{
};

TEST_P(subtractFiveParameterizedTest, CheckSubtractFive)
{
    FiveDigitArray expected(std::get<2>(GetParam()));
    FiveDigitArray first(std::get<0>(GetParam()));
    FiveDigitArray second(std::get<1>(GetParam()));
    ASSERT_EQ(expected, first - second);
}

INSTANTIATE_TEST_CASE_P(
    subtractFiveTests,
    subtractFiveParameterizedTest,
    ::testing::Values(
        std::make_tuple("14", "14", "0"),
        std::make_tuple("0", "0", "0"),
        std::make_tuple("12", "3", "4")));

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}