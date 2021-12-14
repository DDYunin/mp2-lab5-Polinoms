#include <gtest.h>
#include "TList.h"

TEST(TList, can_create_list)
{
    ASSERT_NO_THROW(TList<int> l);
}

TEST(TList, can_create_list_with_list)
{
    TList<int> f;
    ASSERT_NO_THROW(TList<int> l(f));
}

TEST(TList, can_create_list_with_vector)
{
    vector<int> v;
    v.push_back(2);
    ASSERT_NO_THROW(TList<int> l(v));
}

TEST(TList, true_if_return_right_size_of_list)
{
    TList<int> l;
    l.push_back(2);
    EXPECT_EQ(1, l.size());
}

TEST(TList, true_if_queue_is_empty)
{
    TList<int> l;
    EXPECT_EQ(true, l.empty());
}

TEST(TList, false_if_queue_isnt_empty)
{
    TList<int> l;
    l.push_back(2);
    EXPECT_EQ(false, l.empty());
}

TEST(TList, can_get_list_size)
{
    TList<int> l;
    ASSERT_NO_THROW(l.size());
}

TEST(TList, can_print_list)
{
    TList<int> l;
    l.push_back(2);
    ASSERT_NO_THROW(l.print());
}

TEST(TList, can_pop_front)
{
    TList<int> l;
    l.push_back(2);
    l.push_back(5);
    l.pop_front();
    EXPECT_EQ(5, l[0]);
}

TEST(TList, can_pop_back)
{
    TList<int> l;
    l.push_back(2);
    l.push_back(5);
    l.pop_back();
    EXPECT_EQ(2, l[0]);
}

TEST(TList, can_clear_list)
{
    TList<int> l;
    l.push_back(2);
    l.push_back(5);
    l.push_back(5);
    l.clear();
    EXPECT_EQ(0, l.size());
}

TEST(TList, can_invert_list)
{
    TList<int> l;
    l.push_back(2);
    l.push_back(5);
    l.push_back(7);
    l.push_back(19);
    TList<int> l1;
    l1.push_front(2);
    l1.push_front(5);
    l1.push_front(7);
    l1.push_front(19);
    EXPECT_EQ(l[0], l1[3]);
    EXPECT_EQ(l[1], l1[2]);
    EXPECT_EQ(l[2], l1[1]);
    EXPECT_EQ(l[3], l1[0]);
}

TEST(TList, can_list_to_vector)
{
    TList<int> l;
    l.push_back(2);
    l.push_back(5);
    l.push_back(7);
    l.push_back(19);
    vector<int> v = l.to_vector();
    EXPECT_EQ(v[0], l[0]);
    EXPECT_EQ(v[1], l[1]);
    EXPECT_EQ(v[2], l[2]);
    EXPECT_EQ(v[3], l[3]);
}

TEST(TList, cant_use_remove_at_if_invalid_index)
{
    TList<int> l;
    l.push_back(2);
    l.push_back(5);
    ASSERT_ANY_THROW(l.removeAt(3));
}

TEST(TList, can_remove_at_in_set_index)
{
    TList<int> l;
    l.push_back(2);
    l.push_back(5);
    l.push_back(7);
    TList<int> l1;
    l1.push_back(2);
    l1.push_back(5);
    l1.push_back(7);
    l.removeAt(1);
    EXPECT_EQ(2, l.size());
    EXPECT_EQ(l[0],l1[0]);
    EXPECT_NE(l[1], l1[1]);
    EXPECT_EQ(l[1], l1[2]);
}

TEST(TList, can_use_push_back)
{
    TList<int> l;
    ASSERT_NO_THROW(l.push_back(2));
}

TEST(TList, can_use_push_front)
{
    TList<int> l;
    ASSERT_NO_THROW(l.push_front(2));
}

TEST(TList, can_use_insert)
{
    TList<int> l;
    ASSERT_NO_THROW(l.insert(2,0));
}

TEST(TList, push_back_of_list_work_correct)
{
    TList<int> l;
    l.push_back(2);
    EXPECT_EQ(1, l.size());
    EXPECT_EQ(2, l[0]);
}

TEST(TList, push_front_of_list_work_correct)
{
    TList<int> l;
    l.push_front(2);
    EXPECT_EQ(1, l.size());
    EXPECT_EQ(2, l[0]);
    l.push_front(3);
    EXPECT_EQ(2, l.size());
    EXPECT_EQ(3, l[0]);
}

TEST(TList, insert_of_list_work_correct)
{
    TList<int> l;
    l.insert(3, 0);
    l.insert(2, 0);
    l.insert(5, 1);
    EXPECT_EQ(3, l.size());
    EXPECT_EQ(5, l[1]);
}

TEST(TList, throw_if_index_more_than_size_of_list)
{
    TList<int> l;
    ASSERT_ANY_THROW(l.insert(2, 2));
}

TEST(TList, throw_if_index_less_null_for_insert)
{
    TList<int> l;
    ASSERT_ANY_THROW(l.insert(2, -1));
}

TEST(TList, throw_if_index_more_than_size_of_list_for_insert)
{
    TList<int> l;
    ASSERT_ANY_THROW(l.insert(2, 2));
}

TEST(TList, throw_if_index_more_that_size_of_list_for_operator_of_indexation)
{
    TList<int> l;
    l.push_back(4);
    ASSERT_ANY_THROW(l[2]);
}

TEST(TList, throw_if_index_less_than_null_for_operator_of_indexation)
{
    TList<int> l;
    ASSERT_ANY_THROW(l[-2]);
}

TEST(TList, operator_indexation_work_correct_with_correct_index)
{
    TList<int> l;
    l.push_back(2);
    EXPECT_EQ(2, l[0]);
}
