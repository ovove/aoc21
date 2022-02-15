
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>

int main() {
    const auto g = most_common_bits<12>(data);
    const auto e = ~g;
    const auto gamma = g.to_ulong();
    const auto epsilon = e.to_ulong();
    const auto power = gamma * epsilon;
    fmt::print("{}\n", power);
}

// answer: 3912944
