#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <numeric>
#include <vector>

void fish_grow_simulation(std::vector<int>& population, unsigned days) {
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
}

std::array<uint64_t, 9> fish_population_distribution(const std::vector<int>& population) {
    std::array<uint64_t, 9> result {};
    for (unsigned days_until_reproduce = 0; days_until_reproduce <= 8; ++days_until_reproduce) {
        result[days_until_reproduce]
          = std::count(std::begin(population), std::end(population), days_until_reproduce);
    }
    return result;
}

void fish_grow_simulation(std::array<uint64_t, 9>& population, unsigned days) {
    while (days--) {
        const uint64_t new_fish = population[0];
        for (std::size_t days_until_reproduce = 0; days_until_reproduce < 8;
             ++days_until_reproduce) {
            population[days_until_reproduce] = population[days_until_reproduce + 1];
        }
        population[6] += new_fish;
        population[8] = new_fish;
    }
}

uint64_t fish_population_size(const std::array<uint64_t, 9>& population) {
    return std::accumulate(std::begin(population), std::end(population), 0LLU);
}
