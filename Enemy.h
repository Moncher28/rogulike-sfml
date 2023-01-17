#pragma once
#include "Character.h"
class Enemy : public Character {
 public:
  Enemy(float, float);
  bool setTexture(std::string);

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
};
