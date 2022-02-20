
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

int main() {
    auto fish {data};
    fish_grow_simulation(fish, 80);
    const auto result = fish.size();
    fmt::print("{}\n", result);
    constexpr auto expected = 356190;
    assert(result == expected);
    return (result == expected) ? 0 : 1;
};
