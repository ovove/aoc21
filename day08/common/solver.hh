#pragma once

#include "data.hh"
#include <algorithm>
#include <numeric>

bool is1(const Digit& dig) { return (dig.size() == 2); }

bool is4(const Digit& dig) { return (dig.size() == 4); }

bool is7(const Digit& dig) { return (dig.size() == 3); }

bool is8(const Digit& dig) { return (dig.size() == 7); }

unsigned count1478(const Digits& digs) {
    return std::count_if(std::begin(digs), std::end(digs), [](const Digit& dig) {
        return (is1(dig) or is4(dig) or is7(dig) or is8(dig));
    });
}

unsigned count1478(const SignatsToDigits& s2d) {
    const auto& [sig, dig] = s2d;
    return count1478(dig);
}

unsigned count1478(const std::vector<SignatsToDigits>& data) {
    return std::accumulate(
      std::begin(data),
      std::end(data),
      0U,
      [](unsigned acc, const SignatsToDigits& s2d) { return acc + count1478(s2d); });
}
