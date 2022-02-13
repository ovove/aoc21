
#include "solver.hh"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

using namespace ::testing;

TEST(day01part02, test1)
{
    const std::vector<int> data{1, 2, 3};
    const auto result{running_accumulate(data, 3)};
    ASSERT_EQ(result.size(), 1);
    ASSERT_THAT(result, ElementsAre(6));
}

TEST(day01part02, test2)
{
    const std::vector<int> data{1, 2, 3};
    const auto result{running_accumulate(data, 2)};
    ASSERT_EQ(result.size(), 2);
    ASSERT_THAT(result, ElementsAre(3, 5));
}

TEST(day01part02, test3)
{
    const std::vector<int> data{1, 2, 3};
    const auto result{running_accumulate(data, 1)};
    ASSERT_EQ(result.size(), 3);
    ASSERT_THAT(result, ElementsAre(1, 2, 3));
}

TEST(day01part02, test4)
{
    const std::vector data{199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
    const auto result{running_accumulate(data, 3)};
    ASSERT_EQ(result.size(), 8);
    ASSERT_THAT(result,
                ElementsAre(199 + 200 + 208, 200 + 208 + 210, 208 + 210 + 200, 210 + 200 + 207,
                            200 + 207 + 240, 207 + 240 + 269, 240 + 269 + 260, 269 + 260 + 263));
}

TEST(day01part02, test5)
{
    const std::vector data{199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
    const auto result{nr_of_increasing(running_accumulate(data, 3))};
    ASSERT_EQ(result, 5);
}
