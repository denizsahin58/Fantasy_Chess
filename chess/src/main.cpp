#include "GameManager.h"
#include <iostream>
#include <exception>

int main()
{
  try
  {
    GameManager gameManager;
    gameManager.loadConfiguration("config/game_config.json");
    gameManager.startGame();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
