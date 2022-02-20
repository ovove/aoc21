
#include "data.hh"
#include "solver.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

using namespace ::testing;

TEST(day06part02, test1) {
    std::vector fish {3, 4, 3, 1, 2};
    const auto dist_day0 = fish_population_distribution(fish);
    ASSERT_THAT(dist_day0, ElementsAreArray({0, 1, 1, 2, 1, 0, 0, 0, 0}));
    ASSERT_EQ(fish_population_size(dist_day0), 5);

    fish_grow_simulation(fish, 1);
    const auto dist_day1 = fish_population_distribution(fish);
    ASSERT_THAT(dist_day1, ElementsAreArray({1, 1, 2, 1, 0, 0, 0, 0, 0}));
    ASSERT_EQ(fish_population_size(dist_day1), 5);

    fish_grow_simulation(fish, 1);
    const auto dist_day2 = fish_population_distribution(fish);
    ASSERT_THAT(dist_day2, ElementsAreArray({1, 2, 1, 0, 0, 0, 1, 0, 1}));
    ASSERT_EQ(fish_population_size(dist_day2), 6);

    fish_grow_simulation(fish, 2);
    const auto dist_day4 = fish_population_distribution(fish);
    ASSERT_THAT(dist_day4, ElementsAreArray({1, 0, 0, 0, 1, 1, 3, 1, 2}));
    ASSERT_EQ(fish_population_size(dist_day4), 9);
}

TEST(day06part02, test2) {
    std::vector fish {3, 4, 3, 1, 2};
    auto dist = fish_population_distribution(fish);
    ASSERT_THAT(dist, ElementsAreArray({0, 1, 1, 2, 1, 0, 0, 0, 0}));
    ASSERT_EQ(fish_population_size(dist), 5);

    fish_grow_simulation(dist, 1);
    ASSERT_THAT(dist, ElementsAreArray({1, 1, 2, 1, 0, 0, 0, 0, 0}));
    ASSERT_EQ(fish_population_size(dist), 5);

    fish_grow_simulation(dist, 1);
    ASSERT_THAT(dist, ElementsAreArray({1, 2, 1, 0, 0, 0, 1, 0, 1}));
    ASSERT_EQ(fish_population_size(dist), 6);

    fish_grow_simulation(dist, 2);
    ASSERT_THAT(dist, ElementsAreArray({1, 0, 0, 0, 1, 1, 3, 1, 2}));
    ASSERT_EQ(fish_population_size(dist), 9);
}

TEST(day06part02, test3) {
    std::vector fish {3, 4, 3, 1, 2};
    auto dist = fish_population_distribution(fish);
    fish_grow_simulation(dist, 80);
    ASSERT_EQ(fish_population_size(dist), 5934);
}

TEST(day06part02, test4) {
    std::vector fish {3, 4, 3, 1, 2};
    auto dist = fish_population_distribution(fish);
    fish_grow_simulation(dist, 256);
    ASSERT_EQ(fish_population_size(dist), static_cast<uint64_t>(26984457539U));
}
