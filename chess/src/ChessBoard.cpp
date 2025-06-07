#include "ChessBoard.h"
#include <stdexcept>
#include <iostream>

ChessBoard::ChessBoard(int size) : size(size), board(size, std::vector<Piece *>(size, nullptr)) {}

void ChessBoard::placePiece(Piece *piece, int x, int y)
{
  if (x < 0 || y < 0 || x >= size || y >= size)
  {
    throw std::out_of_range("Position out of bounds");
  }
  board[x][y] = piece;
}

Piece *ChessBoard::getPiece(int x, int y) const
{
  if (x < 0 || y < 0 || x >= size || y >= size)
  {
    throw std::out_of_range("Position out of bounds");
  }
  return board[x][y];
}

void ChessBoard::movePiece(int startX, int startY, int endX, int endY)
{
  if (!board[startX][startY])
  {
    throw std::invalid_argument("No piece at start position");
  }
  board[endX][endY] = board[startX][startY];
  board[startX][startY] = nullptr;
}

void ChessBoard::displayBoard() const
{
  for (int y = 0; y < size; ++y)
  {
    for (int x = 0; x < size; ++x)
    {
      if (board[x][y])
      {
        std::cout << board[x][y]->getType()[0] << " ";
      }
      else
      {
        std::cout << ". ";
      }
    }
    std::cout << std::endl;
  }
}
