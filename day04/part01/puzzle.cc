
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

// NOLINTNEXTLINE(bugprone-exception-escape)
int main() {
    std::vector<BingoBoard> brds {boards};
    const auto [bingos, num] = play_bingo(brds, numbers).value();
    const auto result = num * calculate_score(bingos[0]);
    fmt::print("{}\n", result);
    constexpr auto expected = 87456;
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
