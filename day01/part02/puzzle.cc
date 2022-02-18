
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>
#include <cassert>

int main() {
    const auto result = nr_of_increasing(running_accumulate(data, 3));
    fmt::print("{}\n", result);
    constexpr auto expected = 1567;
    assert(result == expected);
    return (result == expected) ? 0 : 1;
}
