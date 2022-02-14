#pragma once

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

template <typename T> auto nr_of_increasing(const std::vector<T>& data)
{
    if (std::distance(std::begin(data), std::end(data)) == 1)
        return typename std::vector<T>::size_type{1};
    std::size_t result{0};
    for (auto it = std::begin(data); it != std::end(data); it = std::next(it)) {
        it = std::adjacent_find(it, std::end(data),
                                [](const auto& itm1, const auto& itm2) { return itm1 < itm2; });
        if (it == std::end(data)) break;
        ++result;
    }
    return result;
}

template <typename T>
auto running_accumulate(const std::vector<T>& data, typename std::vector<T>::size_type len)
{
    assert(len <= data.size());
    std::vector<T> result{};
    result.reserve(data.size() +1U - len);
    const auto end = std::next(std::prev(std::end(data), len));
    for (auto it = std::begin(data); it != end; ++it) {
        const auto acc =
            std::accumulate(it, std::next(it, len), typename std::vector<T>::value_type{});
        result.push_back(acc);
    }
    return result;
}
