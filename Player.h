#pragma once
#include "Character.h"
class Player : public Character {
 public:
  Player(float, float);
  bool setTexture(std::string);

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
};
