
#include "data.hh"
#include "solver.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

//   0.  1.  2.  3.  4.  5.  6 . 7.  8.  9  10  11  12  13  14  15  16
//   0.  1.  3   6  10  15  21  28  36  45  55  66  78  91 105 120 136

TEST(day07part02, test1) {
    const std::vector positions {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};
    ASSERT_EQ(fuel_cost_2(positions, 16), 0 + 120 + 105 + 136 + 78 + 105 + 45 + 120 + 105 + 3);
    ASSERT_EQ(fuel_cost_2(positions, 1), 120 + 0 + 1 + 1 + 6 + 1 + 21 + 0 + 1 + 91);
    ASSERT_EQ(fuel_cost_2(positions, 2), 105 + 1 + 0 + 3 + 3 + 0 + 15 + 1 + 0 + 78);
}

TEST(day07part02, test2) {
    const std::vector positions {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};
    ASSERT_EQ(lowest_fuel_cost_2(positions), 66 + 10 + 6 + 15 + 1 + 6 + 3 + 10 + 6 + 45);
}
