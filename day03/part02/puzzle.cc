
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>
#include <cassert>

int main() {
    const auto o2{get_o2_ratings<12>(data)};
    const auto co2{get_co2_ratings<12>(data)};
    const auto life{o2 * co2};
    fmt::print("{}\n", life);
    constexpr auto expected = 4996233;
    assert(life == expected);
    return (life == expected) ? 0 : 1;
}
