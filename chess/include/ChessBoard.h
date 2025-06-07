#pragma once
#include <vector>
class Piece;
class ChessBoard
{
public:
  explicit ChessBoard(int size);
  void placePiece(Piece *piece, int x, int y);
  Piece *getPiece(int x, int y) const;
  void movePiece(int startX, int startY, int endX, int endY);

  void displayBoard() const;

private:
  int size;
  std::vector<std::vector<Piece *>> board;
};
