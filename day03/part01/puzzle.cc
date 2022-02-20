
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

// NOLINTNEXTLINE(bugprone-exception-escape)
int main() {
    const auto g = most_common_bits<12>(data);
    const auto e = ~g;
    const auto gamma = g.to_ulong();
    const auto epsilon = e.to_ulong();
    const auto power = gamma * epsilon;
    fmt::print("{}\n", power);
    constexpr auto expected = 3912944;
    assert(power == expected);
    return (power == expected) ? 0 : 1;
}
