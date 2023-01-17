#pragma once
#include "MapObject.h"
class Grass : public MapObject {
 public:
  Grass(float, float);
  bool setTexture(std::string);
};
