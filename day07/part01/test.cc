
#include "data.hh"
#include "solver.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

using namespace ::testing;

TEST(day07part01, test1) {
    const std::vector positions {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};
    ASSERT_EQ(fuel_cost(positions, 16), 0 + 15 + 14 + 16 + 12 + 14 + 9 + 15 + 14 + 2);
    ASSERT_EQ(fuel_cost(positions, 1), 15 + 0 + 1 + 1 + 3 + 1 + 6 + 0 + 1 + 13);
    ASSERT_EQ(fuel_cost(positions, 2), 14 + 1 + 0 + 2 + 2 + 0 + 5 + 1 + 0 + 12);
}

TEST(day07part01, test2) {
    const std::vector positions {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};
    ASSERT_EQ(lowest_fuel_cost(positions), 14 + 1 + 0 + 2 + 2 + 0 + 5 + 1 + 0 + 12);
}
