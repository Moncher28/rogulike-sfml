#include "Grass.h"

 Grass::Grass(float x, float y) {
  std::string textureName = "Sprites/grass.png";

  if (!setTexture(textureName)) {
     return;
   }

   pos = sf::Vector2f(x, y);
   sprite.setPosition(pos);
   isPassable = true;
   isExit = false;
 }

 bool Grass::setTexture(std::string textureName) {
   if(!texture.loadFromFile(textureName)) {
     return false;
   }

   texture.setSmooth(true);
   sprite.setTexture(texture);
   sprite.setTextureRect(sf::IntRect(0, 0, 80, 80));
   return true;
 }
