
#include "data.hh"
#include "solver.hh"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

using namespace ::testing;

TEST(day08part01, test1) {
    // clang-format off
    const std::vector<SignatsToDigits> data {
        {{"be"sv, "cfbegad"sv, "cbdgef"sv, "fgaecd"sv, "cgeb"sv, "fdcge"sv, "agebfd"sv, "fecdb"sv, "fabcd"sv, "edb"sv,}, {"fdgacbe"sv, "cefdb"sv, "cefbgd"sv, "gcbe"sv}},
        {{"edbfga"sv, "begcd"sv, "cbg"sv, "gc"sv, "gcadebf"sv, "fbgde"sv, "acbgfd"sv, "abcde"sv, "gfcbed"sv, "gfec"sv,}, {"fcgedb"sv, "cgb"sv, "dgebacf"sv, "gc"sv}},
        {{"fgaebd"sv, "cg"sv, "bdaec"sv, "gdafb"sv, "agbcfd"sv, "gdcbef"sv, "bgcad"sv, "gfac"sv, "gcb"sv, "cdgabef"sv,}, {"cg"sv, "cg"sv, "fdcagb"sv, "cbg"sv}},
        {{"fbegcd"sv, "cbd"sv, "adcefb"sv, "dageb"sv, "afcb"sv, "bc"sv, "aefdc"sv, "ecdab"sv, "fgdeca"sv, "fcdbega"sv,}, {"efabcd"sv, "cedba"sv, "gadfec"sv, "cb"sv}},
        {{"aecbfdg"sv, "fbg"sv, "gf"sv, "bafeg"sv, "dbefa"sv, "fcge"sv, "gcbea"sv, "fcaegb"sv, "dgceab"sv, "fcbdga"sv,}, {"gecf"sv, "egdcabf"sv, "bgf"sv, "bfgea"sv}},
        {{"fgeab"sv, "ca"sv, "afcebg"sv, "bdacfeg"sv, "cfaedg"sv, "gcfdb"sv, "baec"sv, "bfadeg"sv, "bafgc"sv, "acf"sv,}, {"gebdcfa"sv, "ecba"sv, "ca"sv, "fadegcb"sv}},
        {{"dbcfg"sv, "fgd"sv, "bdegcaf"sv, "fgec"sv, "aegbdf"sv, "ecdfab"sv, "fbedc"sv, "dacgb"sv, "gdcebf"sv, "gf"sv,}, {"cefg"sv, "dcbef"sv, "fcge"sv, "gbcadfe"sv}},
        {{"bdfegc"sv, "cbegaf"sv, "gecbf"sv, "dfcage"sv, "bdacg"sv, "ed"sv, "bedf"sv, "ced"sv, "adcbefg"sv, "gebcd"sv,}, {"ed"sv, "bcgafe"sv, "cdgba"sv, "cbgef"sv}},
        {{"egadfb"sv, "cdbfeg"sv, "cegd"sv, "fecab"sv, "cgb"sv, "gbdefca"sv, "cg"sv, "fgcdab"sv, "egfdb"sv, "bfceg"sv,}, {"gbdfcae"sv, "bgc"sv, "cg"sv, "cgb"sv}},
        {{"gcafb"sv, "gcf"sv, "dcaebfg"sv, "ecagb"sv, "gf"sv, "abcdeg"sv, "gaef"sv, "cafbge"sv, "fdbac"sv, "fegbdc"sv,}, {"fgae"sv, "cfgab"sv, "fg"sv, "bagce"sv}}
    };
    // clang-format off
    ASSERT_EQ(count1478(data), 26);
}
