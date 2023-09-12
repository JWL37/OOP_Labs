#include <gtest/gtest.h>
#include "functions.h"

TEST(test_check_func_swapAtoBorBtoA,test_check_for_ordinary_input)
{
    ASSERT_TRUE(swapAtoBorBtoA("acb")=="bca");
}

TEST(test_check_func_swapAtoBorBtoA,test_check_for_only_c)
{
    ASSERT_TRUE(swapAtoBorBtoA("ccc")=="ccc");
}

TEST(test_check_func_swapAtoBorBtoA,test_check_for_only_a)
{
    ASSERT_TRUE(swapAtoBorBtoA("a")=="b");
}

TEST(test_check_func_swapAtoBorBtoA,test_check_for_only_b)
{
    ASSERT_TRUE(swapAtoBorBtoA("bbb")=="aaa");
}


TEST(test_check_func_swapAtoBorBtoA,test_check_for_only_ab)
{
    ASSERT_TRUE(swapAtoBorBtoA("baba")=="abab");
}

TEST(test_check_func_isValue,test_check_for_number)
{
    ASSERT_TRUE(isValue("abc7")==false);
}

TEST(test_check_func_isValue,test_check_for_another_symbol_brackets)
{
    ASSERT_TRUE(isValue("abbb{cccaa}")==false);
}

TEST(test_check_func_isValue,test_check_for_another_symbol_cobachka)
{
    ASSERT_TRUE(isValue("aa@a")==false);
}

TEST(test_check_func_isValue,test_check_for_only_another_symbol)
{
    ASSERT_TRUE(isValue("%")==false);
}

TEST(test_check_func_isValue,test_check_for_another_alphabet)
{
    ASSERT_TRUE(isValue("aа")==false); // вторая а c русской раскладки
}

TEST(test_check_func_isValue,test_check_for_upper_letter)
{
    ASSERT_TRUE(isValue("AABBC")==false);
}

TEST(test_check_func_isValue,test_check_for_space)
{
    ASSERT_TRUE(isValue("cac cbc")==false);
}

TEST(test_check_func_isValue,test_correct_line)
{
    ASSERT_TRUE(isValue("abbabcbbccccca")==true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}