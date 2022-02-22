
#include "data.hh"
#include "solver.hh"

#include <fmt/format.h>

#include <cassert>

int main() {
    const auto result {count1478(data)};
    fmt::print("{}\n", result);
    constexpr auto expected {375};
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
