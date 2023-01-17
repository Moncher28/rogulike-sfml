#pragma once
#include "MapObject.h"
class Wall : public MapObject {
 public:
  Wall(float, float);
  bool setTexture(std::string);
};
