#include "Character.h"

void Character::deleteCharacter() {
  sprite.setColor(sf::Color::Transparent);
  pos = sf::Vector2f(-1000, -1000);
  //sprite.setPosition(-1000, -1000);
}