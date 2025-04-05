#pragma once
#include <cstdio>
#include <unordered_map>
#include <vector>

namespace ChessBot::Game {
struct Board {
public:
  const std::unordered_map<unsigned char, const unsigned char> draw_pice = {
    {0, '.'}, {1, 'K'}, {2, 'Q'}, {3, 'B'}, {4, 'R'},
    {5, 'N'}, {6, 'P'}, {7, 'k'}, {8, 'q'},
    {9, 'b'}, {10, 'r'}, {11, 'n'}, {12, 'p'},
  };
  unsigned char board[32]; // optimized for 8x4 board
  Board();
  void set(const size_t &index, const unsigned char &value);
  const char operator[](const size_t &index) const;
}; // namespace ChessBot::Game

class Game {
private:
  Board board;
  bool tour = true; // true = white, false = black
public:
  void print() const;
  std::vector<const size_t> possible(const size_t index);
  bool move(const size_t &from, const size_t &to);
};
}; // namespace ChessBot::Game