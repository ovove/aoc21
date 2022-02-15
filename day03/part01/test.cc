
#include "data.hh"
#include "solver.hh"

#include <gtest/gtest.h>
#include <vector>

TEST(day03part01, test1)
{
    std::vector<unsigned> data{0b00100, 0b11110, 0b10110, 0b10111, 0b10101, 0b01111,
                               0b00111, 0b11100, 0b10000, 0b11001, 0b00010, 0b01010};
    const auto g = most_common_bits<5>(data);
    const auto e = ~g;
    const auto gamma = g.to_ulong();
    const auto epsilon = e.to_ulong();
    const auto power = gamma * epsilon;
    ASSERT_EQ(power, 198);
}

TEST(day03part01, test2)
{
    std::vector<unsigned> data{0b000011000110};
    const auto g = most_common_bits<12>(data); // 0b000011000110 ==  198
    const auto e = ~g;                         // 0b111100111001 == 3897
    const auto gamma = g.to_ulong();           // 198
    const auto epsilon = e.to_ulong();         // 3897
    const auto power = gamma * epsilon;        // 771606
    ASSERT_EQ(power, 771606);
}

TEST(day03part01, test3)
{
    std::vector<unsigned> data{0b0000'1100'0110, 0b1001'1010'0101, 0b1011'0010'1001};
    const auto g = most_common_bits<12>(data); // 0b1001'1010'0101
    const auto e = ~g;                         // 0b0110'0101'1010
    const auto gamma = g.to_ulong();           // 2469
    const auto epsilon = e.to_ulong();         // 1626
    const auto power = gamma * epsilon;        // 4014594
    ASSERT_EQ(power, 4014594);
}
