
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

int main() {
    const auto fish {data};
    auto dist = fish_population_distribution(fish);
    fish_grow_simulation(dist, 256);
    const auto result = fish_population_size(dist);
    fmt::print("{}\n", result);
    constexpr auto expected = 1617359101538LLU;
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
