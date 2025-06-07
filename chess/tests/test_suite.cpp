#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ChessBoard.h"

TEST_CASE("Piece movement validation", "[MoveValidator]")
{
  ChessBoard board;
  REQUIRE(board.isMoveValid("E2", "E4"));
}
