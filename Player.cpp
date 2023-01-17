#include "Player.h"

Player::Player(float x, float y) {
  std::string textureName = "Sprites/player.png";

  if (!setTexture(textureName)) {
    return;
  }

  pos = sf::Vector2f(x, y);
  sprite.setPosition(pos);
  health = 5;
  damage = 1;
}

bool Player::setTexture(std::string textureName) {
  if (!texture.loadFromFile(textureName)) {
    return false;
  }

  texture.setSmooth(true);
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 80, 80));
  return true;
}

void Player::moveUp() { 
  pos.y -= 80;
  sprite.setPosition(pos);
}

void Player::moveDown() {
  pos.y += 80; 
  sprite.setPosition(pos);
}

void Player::moveLeft() { 
  pos.x -= 80;
  sprite.setPosition(pos);
}

void Player::moveRight() { 
  pos.x += 80;
  sprite.setPosition(pos);
}
