#pragma once

#include <ranges>

auto nr_of_increasing(const std::ranges::range auto& rng)
{
    if (std::ranges::distance(std::ranges::begin(rng), std::ranges::end(rng)) == 1)
        return std::size_t{1};
    std::size_t result{0};
    for (auto it = std::ranges::begin(rng); it != std::ranges::end(rng);
         it = std::ranges::next(it)) {
        it = std::adjacent_find(it, std::ranges::end(rng),
                                [](const auto& itm1, const auto& itm2) { return itm1 < itm2; });
        if (it == std::ranges::end(rng)) break;
        ++result;
    }
    return result;
}
