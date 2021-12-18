#include <gtest.h>
#include "Monom.h"

TEST(TMonom, can_create_monom)
{
    ASSERT_NO_THROW(Monom m(2,3,3,3));
}

TEST(TMonom, cant_create_monom_with_degree_x_more_or_equal_than_max_degree)
{
    ASSERT_ANY_THROW(Monom m(2,10,2,2));
}

TEST(TMonom, cant_create_monom_with_degree_y_more_or_equal_than_max_degree)
{
    ASSERT_ANY_THROW(Monom m(2, 2, 10, 2));
}

TEST(TMonom, cant_create_monom_with_degree_z_more_or_equal_than_max_degree)
{
    ASSERT_ANY_THROW(Monom m(2, 2, 2, 10));
}

TEST(TMonom, cant_create_monom_with_degree_x_less_than_null)
{
    ASSERT_ANY_THROW(Monom m(2, -1, 2, 2));
}

TEST(TMonom, cant_create_monom_with_degree_y_less_than_null)
{
    ASSERT_ANY_THROW(Monom m(2, 2, -3, 2));
}

TEST(TMonom, cant_create_monom_with_degree_z_less_than_null)
{
    ASSERT_ANY_THROW(Monom m(2, 2, 2, -1));
}

TEST(TMonom, true_if_monoms_are_equal_and_coeff_is_ignored)
{
    Monom m(5,3,2,1);
    Monom m1(4,3,2,1);
    EXPECT_EQ(true, m == m1);
}

TEST(TMonom, false_if_monoms_arent_equal_and_coeff_is_ignored)
{
    Monom m(5, 3, 2, 1);
    Monom m1(4, 4, 2, 1);
    EXPECT_EQ(false, m == m1);
}

TEST(TMonom, true_if_monoms_arent_equal_and_coeff_is_ignored)
{
    Monom m(5, 3, 2, 1);
    Monom m1(4, 5, 3, 1);
    EXPECT_EQ(true, m != m1);
}

TEST(TMonom, false_if_monoms_are_equal_and_coeff_is_ignored)
{
    Monom m(5, 3, 2, 1);
    Monom m1(5, 3, 2, 1);
    EXPECT_EQ(false, m != m1);
}

TEST(TMonom, true_if_first_monom_is_more_than_second_monom_and_coeff_is_ignored_first_example)
{
    Monom m(5, 5, 2, 7);
    Monom m1(5, 3, 6, 8);
    EXPECT_EQ(true, m > m1);
}

TEST(TMonom, true_if_first_monom_is_more_than_second_monom_and_coeff_is_ignored_second_example)
{
    Monom m(5, 5, 3, 7);
    Monom m1(5, 5, 2, 3);
    EXPECT_EQ(true, m > m1);
}

TEST(TMonom, true_if_first_monom_is_more_than_second_monom_and_coeff_is_ignored_third_example)
{
    Monom m(5, 5, 2, 3);
    Monom m1(6, 5, 2, 1);
    EXPECT_EQ(true, m > m1);
}

TEST(TMonom, true_if_first_monom_is_less_than_second_monom_and_coeff_is_ignored_first_example)
{
    Monom m(5, 3, 2, 7);
    Monom m1(29, 4, 6, 8);
    EXPECT_EQ(true, m < m1);
}

TEST(TMonom, true_if_first_monom_is_less_than_second_monom_and_coeff_is_ignored_second_example)
{
    Monom m(5, 5, 3, 7);
    Monom m1(5, 5, 6, 3);
    EXPECT_EQ(true, m < m1);
}

TEST(TMonom, true_if_first_monom_is_less_than_second_monom_and_coeff_is_ignored_third_example)
{
    Monom m(5, 5, 2, 7);
    Monom m1(6, 5, 2, 9);
    EXPECT_EQ(true, m < m1);
}

TEST(TMonom, can_plus_two_monoms_with_equals_degrees)
{
    Monom m(5, 5, 4, 7);
    Monom m1(6, 5, 4, 7);
    ASSERT_NO_THROW(m + m1);
}

TEST(TMonom, can_multiply_two_monoms)
{
    Monom m(5, 3, 4, 1);
    Monom m1(6, 5, 4, 7);
    ASSERT_NO_THROW(m * m1);
}

TEST(TMonom, cant_multiply_if_two_monoms_if_degree_of_third_monom_more_than_max_degree)
{
    Monom m(5, 3, 4, 1);
    Monom m1(6, 5, 4, 9);
    ASSERT_ANY_THROW(m * m1);
}

TEST(TMonom, can_take_derivative_to_x)
{
    Monom m(5, 3, 4, 1);
    ASSERT_NO_THROW(m.Derivative('x'));
}

TEST(TMonom, can_take_integral_to_x)
{
    Monom m(5, 3, 4, 1);
    ASSERT_NO_THROW(m.Integrate('x'));
}

TEST(TMonom, can_take_derivative_to_y)
{
    Monom m(5, 3, 4, 1);
    ASSERT_NO_THROW(m.Derivative('y'));
}

TEST(TMonom, can_take_integral_to_y)
{
    Monom m(5, 3, 4, 1);
    ASSERT_NO_THROW(m.Integrate('y'));
}

TEST(TMonom, can_take_derivative_to_z)
{
    Monom m(5, 3, 4, 1);
    ASSERT_NO_THROW(m.Derivative('z'));
}

TEST(TMonom, can_take_integral_to_z)
{
    Monom m(5, 3, 4, 1);
    ASSERT_NO_THROW(m.Integrate('z'));
}

TEST(TMonom, can_take_derivative_first_example)
{
    Monom m(5, 3, 4, 1);
    m.Derivative('x');
    Monom m1(15,2,4,1);
    EXPECT_EQ(true, m1 == m);
}

TEST(TMonom, can_take_derivative_second_example)
{
    Monom m(5, 3, 4, 1);
    m.Derivative('z');
    Monom m1(5, 3, 4, 0);
    EXPECT_EQ(true, m1 == m);
}

TEST(TMonom, can_take_integral_first_example)
{
    Monom m(5, 3, 4, 1);
    m.Integrate('x');
    Monom m1(5/4, 4, 4, 1);
    EXPECT_EQ(true, m1 == m);
}

TEST(TMonom, can_take_integral_second_example)
{
    Monom m(5, 3, 4, 0);
    m.Integrate('z');
    Monom m1(5, 3, 4, 1);
    EXPECT_EQ(true, m1 == m);
}

TEST(TMonom, cant_take_integral_when_degree_will_equal_max_degree)
{
    Monom m(5, 3, 4, 9);
    ASSERT_ANY_THROW(m.Integrate('z'));
}
