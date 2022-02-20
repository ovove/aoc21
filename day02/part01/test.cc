
#include "data.hh"
#include "solver.hh"

#include <gtest/gtest.h>

#include <vector>

TEST(day02part01, test1) {
    const std::vector<Course> data {{Direction::FORWARD, 5},
                                    {Direction::DOWN, 5},
                                    {Direction::FORWARD, 8},
                                    {Direction::UP, 3},
                                    {Direction::DOWN, 8},
                                    {Direction::FORWARD, 2}};
    ASSERT_EQ(distance(data), 150);
}
