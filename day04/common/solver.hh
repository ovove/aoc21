#pragma once

#include "data.hh"
#include <algorithm>
#include <numeric>
#include <optional>
#include <tuple>

bool check_bingo(const BingoBoard& board) {
    auto check_row = [&b = board](std::size_t r) {
        return (b[r * 5 + 0] == -1) and (b[r * 5 + 1] == -1) and (b[r * 5 + 2] == -1) and
               (b[r * 5 + 3] == -1) and (b[r * 5 + 4] == -1);
    };
    auto check_col = [&b = board](std::size_t c) {
        return (b[0 * 5 + c] == -1) and (b[1 * 5 + c] == -1) and (b[2 * 5 + c] == -1) and
               (b[3 * 5 + c] == -1) and (b[4 * 5 + c] == -1);
    };
    return check_row(0) or check_row(1) or check_row(2) or check_row(3) or check_row(4) or
           check_col(0) or check_col(1) or check_col(2) or check_col(3) or check_col(4);
}

unsigned calculate_score(const BingoBoard& board) {
    return std::accumulate(std::begin(board), std::end(board), 0U, [](unsigned acc, int val) {
        return acc + ((val >= 0) ? static_cast<unsigned>(val) : 0U);
    });
}

BingoBoard mark_number(BingoBoard board, int number) {
    const auto it = std::find(std::begin(board), std::end(board), number);
    if (it != std::end(board)) *it = -1;
    return board;
}

std::optional<std::tuple<BingoBoard, int>> play_bingo(std::vector<BingoBoard>& boards,
                                                      const std::vector<int>& numbers)
{
    for (int num: numbers) {
        for (BingoBoard& board: boards) {
            board = mark_number(board, num);
            if (check_bingo(board)) return std::make_tuple(board, num);
        }
    }
    return {};
}
