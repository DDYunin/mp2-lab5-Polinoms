#include <gtest.h>
#include "Polinom.h";
#include "Store.h";

TEST(TPolinom, cant_create_empty_polinom)
{
    ASSERT_ANY_THROW(Polinom pl(""));
}

TEST(TPolinom, can_create_polinom_and_convert_it_to_string_example_1)
{
    Polinom pl("2x1");
    string str = "2x1";
    string str1 = pl.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_create_polinom_and_convert_it_to_string_example_2)
{
    Polinom pl("7");
    string str = "7";
    string str1 = pl.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_create_polinom_and_convert_it_to_string_example_3)
{
    Polinom pl("2x1y2z2");
    string str = "2x1y2z2";
    string str1 = pl.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_create_polinom_and_convert_it_to_string_example_4)
{
    Polinom pl("-7.2y1z7");
    string str = "-7.2y1z7";
    string str1 = pl.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_create_polinom_and_convert_it_to_string_example_5)
{
    Polinom pl("2x1+5x1");
    string str = "7x1";
    string str1 = pl.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_create_polinom_and_convert_it_to_string_example_6)
{
    Polinom pl("7.2x3-7x2");
    string str = "7.2x3-7x2";
    string str1 = pl.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_correct_sorted_monoms_of_polinoms)
{
    Polinom pl("7.2x2-7x3");
    string str = "-7x3+7.2x2";
    pl.Sorted();
    string str1 = pl.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_assign_first_polinom_to_second_polinom)
{
    Polinom pl("7.2x3-7x2");
    Polinom pl1;
    string str = "7.2x3-7x2";
    pl1 = pl;
    string str1 = pl1.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_sum_of_two_polinoms_first_example)
{
    Polinom pl1("3");
    Polinom pl2("2");
    Polinom pl3;
    string str = "5";
    pl3 = pl1 + pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_sum_of_two_polinoms_second_example)
{
    Polinom pl1("-3");
    Polinom pl2("3");
    Polinom pl3;
    string str = "0";
    pl3 = pl1 + pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_sum_of_two_polinoms_third_example)
{
    Polinom pl1("3x2y2z2");
    Polinom pl2("5x2y2z2");
    Polinom pl3;
    string str = "8x2y2z2";
    pl3 = pl1 + pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_sum_of_two_polinoms_fouth_example)
{
    Polinom pl1("3x2y2z2+5.2x2-3");
    Polinom pl2("5x2y2z2+6.2y2+5");
    Polinom pl3;
    string str = "8x2y2z2+5.2x2+6.2y2+2";
    pl3 = pl1 + pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_sum_of_two_polinoms_fifth_example)
{
    Polinom pl1("3x2y2z2+5.2x2-3");
    Polinom pl2("5x2y2z2+6.2y2+5");
    string str = "8x2y2z2+5.2x2+6.2y2+2";
    pl1 += pl2;
    string str1 = pl1.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_multiplication_of_two_polinoms_first_example)
{
    Polinom pl1("5x2");
    Polinom pl2("1x1+5");
    Polinom pl3;
    string str = "5x3+25x2";
    pl3 = pl1 * pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_multiplication_of_two_polinoms_second_example)
{
    Polinom pl1("5x7y2z6-6x2y2-5");
    Polinom pl2("0");
    Polinom pl3;
    string str = "0";
    pl3 = pl1 * pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_multiplication_of_two_polinoms_third_example)
{
    Polinom pl1("5x2y2-6.2x1z6+6x1z2+5");
    Polinom pl2("-1");
    Polinom pl3;
    string str = "-5x2y2+6.2x1z6-6x1z2-5";
    pl3 = pl1 * pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_multiplication_of_two_polinoms_fouth_example)
{
    Polinom pl1("3x2y2z2+5.1x2");
    Polinom pl2("5x2y2z2+6.1y2");
    Polinom pl3;
    string str = "15x4y4z4+25.5x4y2z2+18.3x2y4z2+31.11x2y2";
    pl3 = pl1 * pl2;
    string str1 = pl3.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_find_multiplication_of_two_polinoms_fifth_example)
{
    Polinom pl1("3x2y2z2+5.1x2");
    Polinom pl2("5x2y2z2+6.1y2");
    string str = "15x4y4z4+25.5x4y2z2+18.3x2y4z2+31.11x2y2";
    pl2 *= pl1;
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, throw_if_degree_will_be_more_than_max_degree)
{
    Polinom pl1("3x8y2z2+5.1x2");
    Polinom pl2("5x2y2z2+6.1y2");
    ASSERT_ANY_THROW(pl2 *= pl1);
}

TEST(TPolinom, can_calculate_value_in_point)
{
    Polinom pl1("3x2y2z2+5x2");
    double c = pl1.CalculateInPoint(2,1,3);
    EXPECT_EQ(128,c);
}

TEST(TPolinom, can_take_derivative_first_example)
{
    Polinom pl1("3x2y2z2+5x2");
    Polinom pl2;
    pl2 = pl1.TakeDerivative('x');
    string str = "6x1y2z2+10x1";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_take_derivative_second_example)
{
    Polinom pl1("3x2y2z2+5x2");
    Polinom pl2;
    pl2 = pl1.TakeDerivative('y');
    string str = "6x2y1z2";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_take_derivative_thirth_example)
{
    Polinom pl1("3x2y2z1+5x2");
    Polinom pl2;
    pl2 = pl1.TakeDerivative('z');
    string str = "3x2y2";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_take_derivative_fourth_example)
{
    Polinom pl1("3x2y2+5x2");
    Polinom pl2;
    pl2 = pl1.TakeDerivative('z');
    string str = "0";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_take_integral_first_example)
{
    Polinom pl1("3x2y2z2+6x2");
    Polinom pl2;
    pl2 = pl1.TakeIntegral('x');
    string str = "1x3y2z2+2x3";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_take_integral_second_example)
{
    Polinom pl1("3x2y2z2+5x2");
    Polinom pl2;
    pl2 = pl1.TakeIntegral('y');
    string str = "1x2y3z2+5x2y1";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_take_integral_thirth_example)
{
    Polinom pl1("3x2y2z1+5x2");
    Polinom pl2;
    pl2 = pl1.TakeIntegral('z');
    string str = "1.5x2y2z2+5x2z1";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, can_take_integral_fourth_example)
{
    Polinom pl1("0");
    Polinom pl2;
    pl2 = pl1.TakeIntegral('z');
    string str = "0";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
}

TEST(TPolinom, throw_if_degree_after_integration_will_be_equals_or_more_than_max_degree)
{
    Polinom pl1("10x9");
    Polinom pl2;
    ASSERT_ANY_THROW(pl2 = pl1.TakeIntegral('x'));
}

TEST(TPolinom, can_take_definite_integral)
{
    Polinom pl1("5x4-4x3");
    Polinom pl2;
    pl2 = pl1.TakeIntegral('x');
    double c = pl1.TakeAndCalculateDefiniteIntegral('x', 2, 0, 0, 3, 0, 0);
    string str = "1x5-1x4";
    string str1 = pl2.ToString();
    EXPECT_TRUE(str == str1);
    EXPECT_EQ(146, c);
}
