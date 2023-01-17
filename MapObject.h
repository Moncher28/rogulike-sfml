#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"


 class MapObject : public Entity {
  public:
   bool isPassable;
   bool isExit;
 };
