#include "PortalSystem.h"
#include "ChessBoard.h"

void PortalSystem::teleportPiece(ChessBoard &board, int entryX, int entryY, int exitX, int exitY)
{
  Piece *piece = board.getPiece(entryX, entryY);
  if (!piece)
  {
    throw std::invalid_argument("No piece at portal entry");
  }
  board.placePiece(piece, exitX, exitY);
  board.placePiece(nullptr, entryX, entryY);
}
