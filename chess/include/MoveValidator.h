#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "ChessBoard.h"

class MoveValidator
{
public:
  static bool isValidMove(const ChessBoard &board, int startX, int startY, int endX, int endY);
};

#endif // MOVEVALIDATOR_H
