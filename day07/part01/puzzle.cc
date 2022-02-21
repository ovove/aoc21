
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

int main() {
    const auto result {lowest_fuel_cost_1(data)};
    fmt::print("{}\n", result);
    constexpr auto expected {351901};
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
