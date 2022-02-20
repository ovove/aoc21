#pragma once

#include "data.hh"

#include <algorithm>
#include <cstdlib>
#include <unordered_map>

auto make_map(const std::vector<Line>& lines) {
    std::unordered_map<Coord, unsigned> result {1024};
    for (const auto& line : lines) {
        const auto& [c1, c2] = line;
        const auto& [x1, y1] = c1;
        const auto& [x2, y2] = c2;
        if ((x1 != x2) and (y1 != y2)) continue;
        if ((x1 == x2) and (y1 == y2)) continue;
        if (x1 != x2)
            for (auto x = x1; x <= x2; ++x) ++result[{x, y1}];
        if (x1 != x2)
            for (auto x = x2; x <= x1; ++x) ++result[{x, y1}];
        if (y1 != y2)
            for (auto y = y1; y <= y2; ++y) ++result[{x1, y}];
        if (y1 != y2)
            for (auto y = y2; y <= y1; ++y) ++result[{x1, y}];
    }
    return result;
}

auto add_diagonal(const std::unordered_map<Coord, unsigned>& map, const std::vector<Line>& lines) {
    std::unordered_map<Coord, unsigned> result {map};
    for (const auto& line : lines) {
        const auto& [c1, c2] = line;
        const auto& [x1, y1] = c1;
        const auto& [x2, y2] = c2;
        if (abs(x1 - x2) != abs(y1 - y2)) continue;
        if ((x1 < x2) and (y1 < y2))
            for (auto d = 0; (x1 + d) <= x2; ++d) ++result[{x1 + d, y1 + d}];
        if ((x1 > x2) and (y1 > y2))
            for (auto d = 0; (x2 + d) <= x1; ++d) ++result[{x2 + d, y2 + d}];
        if ((x1 < x2) and (y1 > y2))
            for (auto d = 0; (x1 + d) <= x2; ++d) ++result[{x1 + d, y1 - d}];
        if ((x1 > x2) and (y1 < y2))
            for (auto d = 0; (x2 + d) <= x1; ++d) ++result[{x2 + d, y2 - d}];
    }
    return result;
}

auto count_inercepting(const std::unordered_map<Coord, unsigned>& map, unsigned threshold) {
    return std::count_if(std::begin(map), std::end(map), [threshold](const auto& itm) {
        const auto& [_, cnt] = itm;
        return cnt >= threshold;
    });
}
