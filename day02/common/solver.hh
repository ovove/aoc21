#pragma once

#include "data.hh"
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>

unsigned distance(const std::vector<Course>& course)
{
    // unsigned fw{}, dn{};
    // for (const auto& [directory, distance]: course) {}
    const auto& [fw, dn] =
        std::accumulate(std::begin(course), std::end(course), std::make_pair(0U, 0U),
                        [](const auto& acc, const auto& dir) -> std::pair<unsigned, unsigned> {
                            const auto& [forward, down] = acc;
                            const auto& [direction, distance] = dir;
                            switch (direction) {
                            case Direction::FORWARD: return {forward + distance, down};
                            case Direction::DOWN: return {forward, down + distance};
                            case Direction::UP: return {forward, down - distance};
                            }
                            assert(false);
                            return {};
                        });
    return fw * dn;
}
