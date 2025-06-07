#ifndef PORTALSYSTEM_H
#define PORTALSYSTEM_H

#include "ChessBoard.h"

class PortalSystem
{
public:
  static void teleportPiece(ChessBoard &board, int entryX, int entryY, int exitX, int exitY);
};

#endif // PORTALSYSTEM_H
