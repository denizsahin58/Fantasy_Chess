#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece
{
private:
  std::string type;
  std::string color;

public:
  Piece(const std::string &type, const std::string &color) : type(type), color(color) {}
  std::string getType() const { return type; }
  std::string getColor() const { return color; }
};

#endif // PIECE_H
