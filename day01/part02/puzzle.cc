
#include "data.hh"
#include "solver.hh"
#include <fmt/format.h>

int main() {
    const auto result = nr_of_increasing(running_accumulate(data, 3));
    fmt::print("{}\n", result);
}

// answer: 1567
