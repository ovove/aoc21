
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

// NOLINTNEXTLINE(bugprone-exception-escape)
int main() {
    auto brds {boards};
    auto res = find_last_winning_bingo(brds, numbers);
    const auto [brd, num] = res.value();
    const auto result = num * calculate_score(brd);
    fmt::print("{}\n", result);
    constexpr auto expected = 15561;
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
