
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

int main() {
    const auto result {lowest_fuel_cost_2(data)};
    fmt::print("{}\n", result);
    constexpr auto expected {101079875};
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
