#pragma once
#include <SFML/Graphics.hpp>

class Entity {
 public:
  sf::Vector2f pos;
  sf::Texture texture;
  sf::Sprite sprite;
  virtual ~Entity() = default;
};
