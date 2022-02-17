
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>

int main() {
    std::vector<BingoBoard> brds{boards};
    const auto [bingos, num] = play_bingo(brds, numbers).value();
    const auto result = num * calculate_score(bingos[0]);
    fmt::print("{}\n", result);
}

// answer: 87456
