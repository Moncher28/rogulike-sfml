#include "Enemy.h"

Enemy::Enemy(float x, float y) {
  std::string textureName = "Sprites/enemy.png";

  if (!setTexture(textureName)) {
    return;
  }

  pos = sf::Vector2f(x, y);
  sprite.setPosition(pos);
  health = 2;
  damage = 1;
}

bool Enemy::setTexture(std::string textureName) {
  if (!texture.loadFromFile(textureName)) {
    return false;
  }

  texture.setSmooth(true);
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 80, 80));
  return true;
}

void Enemy::moveUp() {
  pos.y -= 80;
  sprite.setPosition(pos);
}

void Enemy::moveDown() {
  pos.y += 80;
  sprite.setPosition(pos);
}

void Enemy::moveLeft() {
  pos.x -= 80;
  sprite.setPosition(pos);
}

void Enemy::moveRight() {
  pos.x += 80;
  sprite.setPosition(pos);
}
