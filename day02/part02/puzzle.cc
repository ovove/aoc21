
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>
#include <cassert>

int main() {
    const auto result = distance_with_aim(data);
    fmt::print("{}\n", result);
    constexpr auto expected = 1451210346;
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
