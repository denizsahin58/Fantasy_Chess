# FantasyChess Design

## Overview
FantasyChess expands on the classic chess game by adding unique features like portals and customizable rules.

## Core Components
### GameManager
- Handles the main game loop and player interactions.
- Initializes the game board and pieces.

### MoveValidator
- Ensures all moves are valid according to the rules.

### PortalSystem
- Manages portal logic, allowing pieces to teleport.

### Piece
- Represents individual pieces, encapsulating behavior and properties.

## Flow of Execution
1. **Initialization**: `GameManager` sets up the board.
2. **Player Turn**: Players input moves, validated by `MoveValidator`.
3. **Special Moves**: Portals are handled by `PortalSystem`.
4. **Game End**: The game ends after a set turn limit or specific condition.
