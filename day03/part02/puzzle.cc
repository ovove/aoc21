
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>

int main() {
    const auto o2{get_o2_ratings<12>(data)};
    const auto co2{get_co2_ratings<12>(data)};
    const auto life{o2 * co2};
    fmt::print("{}\n", life);
}

// answer: 4996233
