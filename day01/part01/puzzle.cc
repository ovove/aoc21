
#include "solver.hh"
#include "../data.hh"
#include <fmt/format.h>

int main() {
    const auto result = nr_of_increasing(data);
    fmt::print("{}\n", result);
}
