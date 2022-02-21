#pragma once

#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <set>
#include <vector>

unsigned fuel_cost(const std::vector<int>& positions, int target) {
    return std::accumulate(std::begin(positions),
                           std::end(positions),
                           0U,
                           [target](unsigned acc, int pos) { return acc + abs(target - pos); });
}

unsigned lowest_fuel_cost(const std::vector<int>& positions) {
    std::set<int> unique_positions{std::begin(positions), std::end(positions)};
    std::vector<unsigned> unique_costs(unique_positions.size());
    std::transform(std::begin(unique_positions),
                   std::end(unique_positions),
                   std::begin(unique_costs),
                   [&positions](int pos) { return fuel_cost(positions, pos); });
    return *std::min_element(std::begin(unique_costs), std::end(unique_costs));
}
