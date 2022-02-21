#pragma once

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

unsigned fuel_cost_1(const std::vector<int>& positions, int target) {
    return std::accumulate(std::begin(positions),
                           std::end(positions),
                           0U,
                           [target](unsigned acc, int pos) { return acc + abs(target - pos); });
}

unsigned lowest_fuel_cost_1(const std::vector<int>& positions) {
    const auto min = *std::min_element(std::begin(positions), std::end(positions));
    const auto max = *std::max_element(std::begin(positions), std::end(positions));
    std::vector<unsigned> possible_fuel_costs((max - min) + 1);
    int target {min};
    std::generate(std::begin(possible_fuel_costs),
                  std::end(possible_fuel_costs),
                  [&positions, &target]() { return fuel_cost_1(positions, target++); });
    return *std::min_element(std::begin(possible_fuel_costs), std::end(possible_fuel_costs));
}

unsigned fuel_cost_2(const std::vector<int>& positions, int target) {
    // 0 + 1 + 2 + 3 + 4 + 5 + dist
    const auto inc_fuel_const
      = [](unsigned dist) { return dist * ((dist + 1) / 2) + (dist / 2) * ((dist + 1) % 2); };
    const auto result = std::accumulate(std::begin(positions),
                                        std::end(positions),
                                        0U,
                                        [target, inc_fuel_const](unsigned acc, int pos) {
                                            const auto inc = inc_fuel_const(abs(target - pos));
                                            return acc + inc;
                                        });
    return result;
}

unsigned lowest_fuel_cost_2(const std::vector<int>& positions) {
    const auto min = *std::min_element(std::begin(positions), std::end(positions));
    const auto max = *std::max_element(std::begin(positions), std::end(positions));
    std::vector<unsigned> possible_fuel_costs((max - min) + 1);
    int target {min};
    std::generate(std::begin(possible_fuel_costs),
                  std::end(possible_fuel_costs),
                  [&positions, &target]() { return fuel_cost_2(positions, target++); });
    return *std::min_element(std::begin(possible_fuel_costs), std::end(possible_fuel_costs));
}
