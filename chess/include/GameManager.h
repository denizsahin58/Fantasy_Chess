#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <memory>
#include "ChessBoard.h"

class GameManager
{
private:
  int boardSize;
  int turnLimit;
  std::unique_ptr<ChessBoard> chessBoard;

public:
  void loadConfiguration(const std::string &filepath);
  void startGame();
};

#endif // GAMEMANAGER_H
