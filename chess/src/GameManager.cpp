#include "GameManager.h"
#include "ChessBoard.h"
#include "MoveValidator.h"
#include "PortalSystem.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

void GameManager::loadConfiguration(const std::string &filepath)
{
  std::ifstream configFile(filepath);
  if (!configFile.is_open())
  {
    throw std::runtime_error("Configuration file not found: " + filepath);
  }

  nlohmann::json config;
  configFile >> config;

  boardSize = config["game_settings"]["board_size"];
  turnLimit = config["game_settings"]["turn_limit"];
  chessBoard = std::make_unique<ChessBoard>(boardSize);

  // Initialize pieces
  for (const auto &pieceData : config["pieces"])
  {
    std::string type = pieceData["type"];
    std::string color = pieceData["color"];
    int x = pieceData["position"][0];
    int y = pieceData["position"][1];
    chessBoard->placePiece(new Piece(type, color), x, y);
  }

  // Initialize portals
  for (const auto &portalData : config["portals"])
  {
    portals.push_back({portalData["entry"], portalData["exit"]});
  }
}

void GameManager::startGame()
{
  MoveValidator validator;
  PortalSystem portalSystem;

  for (int turn = 1; turn <= turnLimit; ++turn)
  {
    std::cout << "\nTurn " << turn << "/" << turnLimit << std::endl;
    chessBoard->displayBoard();

    // Ask the player for input
    int startX, startY, endX, endY;
    std::cout << "Enter your move (startX startY endX endY): ";
    std::cin >> startX >> startY >> endX >> endY;

    try
    {
      if (!validator.isValidMove(*chessBoard, startX, startY, endX, endY))
      {
        throw std::invalid_argument("Invalid move! Please try again.");
      }

      chessBoard->movePiece(startX, startY, endX, endY);

      // Check for portal activation
      for (const auto &portal : portals)
      {
        if (portal.entry[0] == endX && portal.entry[1] == endY)
        {
          portalSystem.teleportPiece(*chessBoard, endX, endY, portal.exit[0], portal.exit[1]);
          std::cout << "Portal activated! Piece teleported.\n";
          break;
        }
      }
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
      --turn; // Retry the turn
    }
  }

  std::cout << "Game Over! Thank you for playing Fantasy Chess." << std::endl;
}
