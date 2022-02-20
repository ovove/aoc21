
#include "data.hh"
#include "solver.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <array>
#include <vector>

using namespace ::testing;

TEST(day05part01, test1) {
    const std::vector<Line> data {{{0, 9}, {5, 9}},
                                  {{8, 0}, {0, 8}},
                                  {{9, 4}, {3, 4}},
                                  {{2, 2}, {2, 1}},
                                  {{7, 0}, {7, 4}},
                                  {{6, 4}, {2, 0}},
                                  {{0, 9}, {2, 9}},
                                  {{3, 4}, {1, 4}},
                                  {{0, 0}, {8, 8}},
                                  {{5, 5}, {8, 2}}};
    const auto map = make_map(data);
    const auto result = count_inercepting(map, 2);
    ASSERT_EQ(result, 5);
}
