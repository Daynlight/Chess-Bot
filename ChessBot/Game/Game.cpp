#include "Game.h"

ChessBot::Game::Board::Board() {
  for(unsigned char &el : board) el = 0;
  for(size_t i = 0; i < 8; ++i) {
    set(i + 8 * 6, 6);                // White Pawn
    set(i + 8, 12);                   // Black Pawn
  };
  set(8*7 + 3, 1);                    // White King
  set(3, 7);                          // Black King
  set(8*7 + 4, 2);                    // White Queen
  set(4, 8);                          // Black Queen
  set(8*7 + 5, 3); set(8*7 + 2, 3);   // White Bishop
  set(5, 9); set(2, 9);               // Black Bishop
  set(8*7 + 6, 5); set(8*7 + 1, 5);   // White Knight
  set(6, 11); set(1, 11);             // Black Knight
  set(8*7 + 7, 4); set(8*7, 4);       // White Rook
  set(7, 10); set(0, 10);             // Black Rook
};

void ChessBot::Game::Board::set(const size_t &index, const unsigned char &value) {
  if(index % 2 == 0) board[index/2] = (board[index/2] & 0xF0) + (value & 0x0F);
  else board[index/2] = (board[index/2] & 0x0F) + ((value << 4) & 0xF0);
};

const char ChessBot::Game::Board::operator[](const size_t &index) const {
  if(index % 2 == 0) return board[index/2] & 0x0F;
  else return (board[index/2] & 0xF0) >> 4;
};

void ChessBot::Game::Game::print() const {
  for(size_t i = 0; i < 64; ++i) {
    printf("%c ", board.draw_pice.at(board[i]));
    if(i % 8 == 7) printf("\n");
  };
};
