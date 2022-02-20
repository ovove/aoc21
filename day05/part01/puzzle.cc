
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>
#include <cassert>

int main() {
    const auto map = make_map(data);
    const auto result = count_inercepting(map, 2);
    constexpr auto expected = 6687;
    fmt::print("{}\n", result);
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
