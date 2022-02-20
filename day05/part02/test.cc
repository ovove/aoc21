
#include "data.hh"
#include "solver.hh"

#include <gtest/gtest.h>

#include <vector>

TEST(day05part02, test1) {
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
    const auto map = add_diagonal(make_map(data), data);
    const auto result = count_inercepting(map, 2);
    ASSERT_EQ(result, 12);
}
