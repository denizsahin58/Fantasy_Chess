#include "MoveValidator.h"
#include "ChessBoard.h"

bool MoveValidator::isValidMove(const ChessBoard &board, int startX, int startY, int endX, int endY)
{
  Piece *piece = board.getPiece(startX, startY);
  if (!piece)
    return false;

  if (endX < 0 || endY < 0 || endX >= board.getSize() || endY >= board.getSize())
  {
    return false;
  }

  return true; // Placeholder
}
