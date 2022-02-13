
#include "solver.hh"

#include <gtest/gtest.h>
#include <vector>

TEST(day01part01, test1)
{
    std::vector<int> data{};
    const auto result{nr_of_increasing(data)};
    ASSERT_EQ(result, 0);
}

TEST(day01part01, test2)
{
    std::vector<int> data{100};
    const auto result{nr_of_increasing(data)};
    ASSERT_EQ(result, 1);
}

TEST(day01part01, test3)
{
    std::vector<int> data{100, 101};
    const auto result{nr_of_increasing(data)};
    ASSERT_EQ(result, 1);
}

TEST(day01part01, test4)
{
    std::vector<int> data{101, 100};
    const auto result{nr_of_increasing(data)};
    ASSERT_EQ(result, 0);
}

TEST(day01part01, test5)
{
    std::vector data{199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
    const auto result{nr_of_increasing(data)};
    ASSERT_EQ(result, 7);
}

