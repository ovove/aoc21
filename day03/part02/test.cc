
#include "data.hh"
#include "solver.hh"

#include <gtest/gtest.h>
#include <vector>

TEST(day03part02, test1)
{
    std::vector<unsigned> data{0b00100, 0b11110, 0b10110, 0b10111, 0b10101, 0b01111,
                               0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010};
    const auto o2{get_o2_ratings<5>(data)};
    const auto co2{get_co2_ratings<5>(data)};
    const auto life{o2 * co2};
    ASSERT_EQ(life, 230);
}
