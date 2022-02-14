#pragma once

#include "data.hh"
#include <cassert>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

unsigned distance(const std::vector<Course>& course)
{
    // unsigned fw{}, dn{};
    // for (const auto& [directory, distance]: course) {}
    const auto& [fw, dn] =
        std::accumulate(std::begin(course), std::end(course), std::make_tuple(0U, 0U),
                        [](const auto& acc, const auto& dir) -> std::tuple<unsigned, unsigned> {
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

unsigned distance_with_aim(const std::vector<Course>& course)
{
    // unsigned fw{}, dn{};
    // for (const auto& [directory, distance]: course) {}
    const auto& [fw, dn, am] = std::accumulate(
        std::begin(course), std::end(course), std::make_tuple(0U, 0U, 0U),
        [](const auto& acc, const auto& dir) -> std::tuple<unsigned, unsigned, unsigned> {
            const auto& [forward, down, aim] = acc;
            const auto& [direction, distance] = dir;
            switch (direction) {
            case Direction::FORWARD: return {forward + distance, down + distance * aim, aim};
            case Direction::DOWN: return {forward, down, aim + distance};
            case Direction::UP: return {forward, down, aim - distance};
            }
            assert(false);
            return {};
        });
    return fw * dn;
}
