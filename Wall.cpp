#include "Wall.h"

 Wall::Wall(float x, float y) {
  std::string textureName = "Sprites/wall.png";

  if (!setTexture(textureName)) {
    return;
  }

  pos = sf::Vector2f(x, y);
  sprite.setPosition(pos);
  isPassable = false;
  isExit = false;
}

bool Wall::setTexture(std::string textureName) {
  if (!texture.loadFromFile(textureName)) {
    return false;
  }

  texture.setSmooth(true);
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 80, 80));
  return true;
}
