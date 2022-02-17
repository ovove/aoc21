
#include "data.hh"
#include "solver.hh"

#include <array>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

using namespace ::testing;

TEST(day04part01, test1)
{
    ASSERT_FALSE(check_bingo({1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                              14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}));
    ASSERT_FALSE(check_bingo({-1, -1, -1, -1, 5,  -1, -1, -1, 9,  -1, -1, -1, 13,
                              -1, -1, -1, 17, -1, -1, -1, 21, -1, -1, -1, -1}));
    ASSERT_TRUE(check_bingo({-1, -1, -1, -1, -1, 6,  7,  8,  9,  10, 11, 12, 13,
                             14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}));
    ASSERT_TRUE(check_bingo({1,  2,  3,  4,  5,  -1, -1, -1, -1, -1, 11, 12, 13,
                             14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}));
    ASSERT_TRUE(check_bingo({1,  2,  3,  4,  5,  6,  7,  8,  9,  10, -1, -1, -1,
                             -1, -1, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}));
    ASSERT_TRUE(check_bingo({1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                             14, 15, -1, -1, -1, -1, -1, 21, 22, 23, 24, 25}));
    ASSERT_TRUE(check_bingo({1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                             14, 15, 16, 17, 18, 19, 20, -1, -1, -1, -1, -1}));
    ASSERT_TRUE(check_bingo({-1, 2,  3,  4,  5,  -1, 7,  8,  9,  10, -1, 12, 13,
                             14, 15, -1, 17, 18, 19, 20, -1, 22, 23, 24, 25}));
    ASSERT_TRUE(check_bingo({1,  -1, 3,  4,  5,  6,  -1, 8,  9,  10, 11, -1, 13,
                             14, 15, 16, -1, 18, 19, 20, 21, -1, 23, 24, 25}));
    ASSERT_TRUE(check_bingo({1,  2,  -1, 4,  5,  6,  7,  -1, 9,  10, 11, 12, -1,
                             14, 15, 16, 17, -1, 19, 20, 21, 22, -1, 24, 25}));
    ASSERT_TRUE(check_bingo({1,  2,  3,  -1, 5,  6,  7,  8,  -1, 10, 11, 12, 13,
                             -1, 15, 16, 17, 18, -1, 20, 21, 22, 23, -1, 25}));
    ASSERT_TRUE(check_bingo({1,  2,  3,  4,  -1, 6,  7,  8,  9,  -1, 11, 12, 13,
                             14, -1, 16, 17, 18, 19, -1, 21, 22, 23, 24, -1}));
}

TEST(day04part01, test2)
{
    ASSERT_EQ(calculate_score({-1, -1, -1, -1, -1, 10, 16, 15, -1, 19, 18, 8, -1,
                               26, 20, 22, -1, 13, 6,  -1, -1, -1, 12, 3,  -1}),
              188);
}

TEST(day04part01, test3)
{
    const BingoBoard board{14, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                           26, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7};
    ASSERT_THAT(mark_number(board, 99),
                ElementsAreArray({14, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                                  26, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}));
    ASSERT_THAT(mark_number(board, 14),
                ElementsAreArray({-1, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                                  26, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}));
    ASSERT_THAT(mark_number(board, 26),
                ElementsAreArray({14, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                                  -1, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}));
}

TEST(day04part01, test4)
{
    std::vector<BingoBoard> boards{{14, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                                    26, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}};
    ASSERT_EQ(play_bingo(boards, {}), std::nullopt);
    ASSERT_THAT(boards[0], ElementsAreArray({14, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                                             26, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}));
    ASSERT_EQ(play_bingo(boards, {99, 98, 97}), std::nullopt);
    ASSERT_THAT(boards[0], ElementsAreArray({14, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                                             26, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}));
    ASSERT_EQ(play_bingo(boards, {14, 26}), std::nullopt);
    ASSERT_THAT(boards[0], ElementsAreArray({-1, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
                                             -1, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}));
    const auto result = play_bingo(boards, {21, 17, 24, 4});
    ASSERT_TRUE(result.has_value());
    const auto& [bingos, num] = *result;
    ASSERT_EQ(num, 4);
    ASSERT_EQ(bingos.size(), 1);
    ASSERT_THAT(bingos[0], ElementsAreArray({-1, -1, -1, -1, -1, 10, 16, 15, 9, 19, 18, 8, 23,
                                             -1, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}));
    ASSERT_EQ(boards.size(), 0);
}

TEST(day04part01, test5)
{
    std::vector<BingoBoard> boards{
        {22, 13, 17, 11, 0, 8, 2, 23, 4, 24, 21, 9, 14, 16, 7, 6, 10, 3, 18, 5, 1, 12, 20, 15, 19},
        {3, 15, 0, 2, 22, 9, 18, 13, 17, 5, 19, 8, 7, 25, 23, 20, 11, 10, 24, 4, 14, 21, 16, 12, 6},
        {14, 21, 17, 24, 4,  10, 16, 15, 9, 19, 18, 8, 23,
         26, 20, 22, 11, 13, 6,  5,  2,  0, 12, 3,  7}};
    ASSERT_EQ(play_bingo(boards, {7, 4, 9, 5, 11}), std::nullopt);
    ASSERT_THAT(boards[0], ElementsAreArray({22, 13, 17, -1, 0, 8,  2,  23, -1, 24, 21, -1, 14,
                                             16, -1, 6,  10, 3, 18, -1, 1,  12, 20, 15, 19}));
    ASSERT_THAT(boards[1], ElementsAreArray({3,  15, 0,  2,  22, -1, 18, 13, 17, -1, 19, 8, -1,
                                             25, 23, 20, -1, 10, 24, -1, 14, 21, 16, 12, 6}));
    ASSERT_THAT(boards[2], ElementsAreArray({14, 21, 17, 24, -1, 10, 16, 15, -1, 19, 18, 8, 23,
                                             26, 20, 22, -1, 13, 6,  -1, 2,  0,  12, 3,  -1}));
    ASSERT_EQ(play_bingo(boards, {17, 23, 2, 0, 14, 21}), std::nullopt);
    ASSERT_THAT(boards[0], ElementsAreArray({22, 13, -1, -1, -1, 8,  -1, -1, -1, 24, -1, -1, -1,
                                             16, -1, 6,  10, 3,  18, -1, 1,  12, 20, 15, 19}));
    ASSERT_THAT(boards[1], ElementsAreArray({3,  15, -1, -1, 22, -1, 18, 13, -1, -1, 19, 8, -1,
                                             25, -1, 20, -1, 10, 24, -1, -1, -1, 16, 12, 6}));
    ASSERT_THAT(boards[2], ElementsAreArray({-1, -1, -1, 24, -1, 10, 16, 15, -1, 19, 18, 8, -1,
                                             26, 20, 22, -1, 13, 6,  -1, -1, -1, 12, 3,  -1}));
    auto res = play_bingo(boards, {24});
    ASSERT_TRUE(res.has_value());
    const auto [bingos, num] = *res;
    ASSERT_EQ(num, 24);
    ASSERT_EQ(bingos.size(), 1);
    ASSERT_EQ(boards.size(), 2);
    ASSERT_THAT(bingos[0], ElementsAreArray({-1, -1, -1, -1, -1, 10, 16, 15, -1, 19, 18, 8, -1,
                                             26, 20, 22, -1, 13, 6,  -1, -1, -1, 12, 3,  -1}));
    ASSERT_EQ(calculate_score(bingos[0]), 188);
    ASSERT_EQ(num * calculate_score(bingos[0]), 4512);
}
