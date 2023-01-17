#include "GameMap.h"

void GameMap::init(){ 
  objects.clear();


  for (int i = 0; i < gridSize; i++) {
    std::vector<std::shared_ptr<MapObject>> currRow;
    for (int j = 0; j < gridSize; j++) {
      currRow.push_back(std::make_unique<Grass>(i * 80, j * 80));
    }
    objects.push_back(currRow);
  }

  std::vector<std::shared_ptr<MapObject>> WallRight;
  for (int j = 0; j < gridSize; j++) {
    WallRight.push_back(std::make_unique<Wall>(-80, j * 80));
  }
  objects.push_back(WallRight);


  std::vector<std::shared_ptr<MapObject>> WallLeft;
  for (int j = 0; j < gridSize; j++) {
    WallLeft.push_back(std::make_unique<Wall>(800, j * 80));
  }
  objects.push_back(WallLeft);

  std::vector<std::shared_ptr<MapObject>> WallUp;
  for (int j = 0; j < gridSize; j++) {
    WallUp.push_back(std::make_unique<Wall>(j * 80, -80));
  }
  objects.push_back(WallUp);

  std::vector<std::shared_ptr<MapObject>> WallDown;
  for (int j = 0; j < gridSize; j++) {
    WallDown.push_back(std::make_unique<Wall>(j*80, 800));
  }
  objects.push_back(WallDown);

  std::vector<std::shared_ptr<MapObject>> HouseWallUp;
  for (int j = 2; j < 7; j++) {
    WallDown.push_back(std::make_unique<Wall>(j * 80, 160));
  }
  objects.push_back(WallDown);

  std::vector<std::shared_ptr<MapObject>> HouseWallDown;
  for (int j = 2; j < 7; j++) {
    WallDown.push_back(std::make_unique<Wall>(j * 80, 560));
  }
  objects.push_back(WallDown);

  std::vector<std::shared_ptr<MapObject>> HouseWallLeft;
  for (int j = 2; j < 6; j++) {
    HouseWallLeft.push_back(std::make_unique<Wall>(160, j * 80));
  }
  objects.push_back(HouseWallLeft);

  std::vector<std::shared_ptr<MapObject>> HouseWallRight;
  for (int j = 2; j < 8; j++) {
    HouseWallRight.push_back(std::make_unique<Wall>(560, j * 80));
  }
  objects.push_back(HouseWallRight);
};

GameMap::GameMap() {
  gridSize = 10;
  init();
};
