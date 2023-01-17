#pragma once
#include <vector>
#include "MapObject.h"
#include "Grass.h"
#include "Wall.h"
#include "Player.h"
#include "Enemy.h"

class GameMap {

  void init();

 public:
  std::vector<std::vector<std::shared_ptr<MapObject>>> objects;
  int gridSize;
  GameMap();
};
