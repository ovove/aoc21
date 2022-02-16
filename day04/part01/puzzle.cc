
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>

int main() {
    std::vector<BingoBoard> brds{boards};
    const auto [brd, num] = *play_bingo(brds, numbers);
    const auto result = num * calculate_score(brd);
    fmt::print("{}\n", result);
}

// answer: 87456
