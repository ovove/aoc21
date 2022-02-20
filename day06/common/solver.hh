#pragma once

#include <algorithm>
#include <vector>

auto fish_grow_simulation(std::vector<int> population, unsigned days) {
    while (days--) {
        unsigned new_fish {0};
        std::for_each(std::begin(population),
                      std::end(population),
                      [&new_fish](int& days_until_reproduce) {
                          if (days_until_reproduce == 0) {
                              ++new_fish;
                              days_until_reproduce = 6;
                          }
                          else {
                              --days_until_reproduce;
                          }
                      });
        population.insert(std::end(population), new_fish, 8);
    }
    return population;
}
