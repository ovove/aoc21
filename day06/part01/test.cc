
#include "data.hh"
#include "solver.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

// clang-format off
TEST(day06part01, test1) {
    std::vector fish {3, 4, 3, 1, 2};
    fish_grow_simulation(fish, 1);
    ASSERT_THAT(fish, ElementsAreArray({2, 3, 2, 0, 1}));    // Day 1
    fish_grow_simulation(fish, 1);
    ASSERT_THAT(fish, ElementsAreArray({1, 2, 1, 6, 0, 8}));    // Day 2
    fish_grow_simulation(fish, 2);
    ASSERT_THAT(fish, ElementsAreArray({6, 0, 6, 4, 5, 6, 7, 8, 8}));    // Day 4
    fish_grow_simulation(fish, 4);
    ASSERT_THAT(fish, ElementsAreArray({2, 3, 2, 0, 1, 2, 3, 4, 4, 5}));    // Day 8
    fish_grow_simulation(fish, 8);
    ASSERT_THAT(fish, ElementsAreArray({1, 2, 1, 6, 0, 1, 2, 3, 3, 4, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 8}));    // Day 16
}
// clang-format off

TEST(day06part01, test2) {
    std::vector fish {3, 4, 3, 1, 2};
    fish_grow_simulation(fish, 80);
    ASSERT_EQ(fish.size(), 5934);
}
