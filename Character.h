#pragma once
#include "Entity.h"
class Character : public Entity {
 public:
  int health;
  int damage;

  void deleteCharacter();
};
