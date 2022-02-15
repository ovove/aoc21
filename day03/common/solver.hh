#pragma once

#include <algorithm>
#include <bitset>
#include <numeric>
#include <vector>

template <std::size_t N>
auto most_common_bits(const std::vector<unsigned>& input) {
    std::vector<std::bitset<N>> data(input.size());
    std::transform(std::begin(input), std::end(input), std::begin(data),
                   [](const auto bits) {return std::bitset<N>{bits}; });
    std::bitset<N> result;
    for (std::size_t n = 0; n < N; ++n) {
        const auto ones = std::count_if(std::begin(data), std::end(data),
                                        [n](const auto& bits) {
                                            return bits.test(n); });
        const auto zeros = input.size() - ones;
        result[n] = (ones >= zeros);
    }
    return result;
}
