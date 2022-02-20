
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

int main() {
    const auto map = add_diagonal(make_map(data), data);
    const auto result = count_inercepting(map, 2);
    constexpr auto expected = 19851;
    fmt::print("{}\n", result);
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
