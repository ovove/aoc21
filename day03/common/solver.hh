#pragma once

#include <algorithm>
#include <bitset>
#include <numeric>
#include <tuple>
#include <vector>

namespace details {

template <std::size_t N> auto make_vector_of_bitsets(const std::vector<unsigned>& input)
{
    std::vector<std::bitset<N>> result(input.size());
    std::transform(std::begin(input), std::end(input), std::begin(result),
                   [](const auto bits) { return std::bitset<N>{bits}; });
    return result;
}

template <std::size_t N>
auto count_zeros_and_ones(const std::vector<std::bitset<N>>& data, std::size_t n)
{
    const auto ones = std::count_if(std::begin(data), std::end(data),
                                    [n](const auto& bits) { return bits.test(n); });
    const auto zeros = data.size() - ones;
    return std::make_tuple(zeros, ones);
}

template <std::size_t N>
void filter_out_based_on_bit_at_pos(std::vector<std::bitset<N>>& data, bool bit_is_set,
                                    std::size_t n)
{
    const auto it =
        std::remove_if(std::begin(data), std::end(data), [bit_is_set, pos = n](const auto& bits) {
            return bits.test(pos) == bit_is_set;
        });
    data.erase(it, std::end(data));
}

template <std::size_t N> auto get_ratings(const std::vector<unsigned>& input, auto zeros_vs_ones)
{
    auto data{details::make_vector_of_bitsets<N>(input)};
    for (std::size_t n = 0; (n < N) and (data.size() > 1); ++n) {
        const auto& [zeros, ones] = details::count_zeros_and_ones<N>(data, N - n - 1);
        details::filter_out_based_on_bit_at_pos(data, zeros_vs_ones(zeros, ones), N - n - 1);
    }
    return data.front().to_ulong();
}

} // namespace details

template <std::size_t N> auto most_common_bits(const std::vector<unsigned>& input)
{
    auto data{details::make_vector_of_bitsets<N>(input)};
    std::bitset<N> result;
    for (std::size_t n = 0; n < N; ++n) {
        const auto [zeros, ones] = details::count_zeros_and_ones<N>(data, n);
        result[n] = (ones >= zeros);
    }
    return result;
}

template <std::size_t N> auto get_o2_ratings(const std::vector<unsigned>& input)
{
    return details::get_ratings<N>(input, [](auto z, auto o) { return z > o; });
}

template <std::size_t N> auto get_co2_ratings(const std::vector<unsigned>& input)
{
    return details::get_ratings<N>(input, [](auto z, auto o) { return z <= o; });
}
