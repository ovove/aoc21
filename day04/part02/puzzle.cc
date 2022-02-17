
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>

int main() {
    auto brds{boards};
    auto res = find_last_winning_bingo(brds, numbers);
    const auto [brd, num] = res.value();
    const auto result = num * calculate_score(brd);
    fmt::print("{}\n", result);
}

// answer: 15561
