#include <SFML/Graphics.hpp>
#include "GameMap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace sf;

bool canMove(Vector2f curr, std::vector<std::vector<std::shared_ptr<MapObject>>> objects) {
  bool result = false;
  for (const auto& o : objects) {
    for (const auto& t : o) {
      auto other = t.get();

      if (((curr.x == other->pos.x) && (curr.y == other->pos.y)) && other->isPassable == false) {
        result = true;
        //std::cout << "Colide";
      }
    }
  }
  return result;
}

void fight(Player* player, Character* enemy) {
  player->health -= enemy->damage;
  enemy->health -= player->damage;
  std::cout << "PlayerHealth: " << player->health << std::endl;
  std::cout << "EnemyHealth: " << enemy->health << std::endl;
  if (enemy->health <= 0) {
    std::cout << "Enemy Defeated!" << std::endl;
    enemy->deleteCharacter();
  }
}


bool isFight(Player* player, Vector2f curr, std::vector<std::shared_ptr<Character>> characters) {
  bool result = false;
  for (const auto& enemy : characters) {

      if ((curr.x == enemy->pos.x) && (curr.y == enemy->pos.y)) {
        result = true;
        std::cout << "Fight!" << std::endl;
        fight(player, enemy.get());
      }
    }
  return result;
}





int main() {
  int weight = 800, high = 800;
  std::srand(std::time(0));

  GameMap map = GameMap();
  std::queue<std::shared_ptr<Character>> turnOrder;
  std::vector<std::shared_ptr<Character>> characters;

  auto playerP = std::make_shared<Player>(80, 80);
  auto player = playerP.get();

  auto enemyP = std::make_shared<Enemy>(320, 320);
  auto enemy = enemyP.get();

  characters.push_back(playerP);
  characters.push_back(enemyP);

  turnOrder.push(playerP);
  turnOrder.push(enemyP);

  //Player player(80, 80);
  

  //Wall wall(80, 80);


  RenderWindow window(sf::VideoMode(high, weight), "Game");
  window.setKeyRepeatEnabled(false);
  bool keyPressed = false;

  while (window.isOpen()) {

    Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    
    if (turnOrder.front() == playerP) {
      if (event.type == sf::Event::KeyPressed && keyPressed != true) {
        keyPressed = true;
        if (event.key.code == sf::Keyboard::Right) {
          if ((isFight(player, player->pos + Vector2f(80, 0), characters))) {
          }
          if (!(canMove(player->pos + Vector2f(80, 0), map.objects))) {
            player->moveRight();
          }
        }
        if (event.key.code == sf::Keyboard::Down) {
          if ((isFight(player, player->pos + Vector2f(0, 80), characters))) {
          }
          if (!(canMove(player->pos + Vector2f(0, 80), map.objects))) {
            player->moveDown();
          }
        }
        if (event.key.code == sf::Keyboard::Up) {
          if ((isFight(player, player->pos + Vector2f(0, -80), characters))) {
          }
          if (!(canMove(player->pos + Vector2f(0, -80), map.objects))) {
            player->moveUp();
          }
        }
        if (event.key.code == sf::Keyboard::Left) {
          if ((isFight(player, player->pos + Vector2f(-80, 0), characters))) {
          }
          if (!(canMove(player->pos + Vector2f(-80, 0), map.objects))) {
            player->moveLeft();
          }
        }
      }
    }

    if (event.type == sf::Event::KeyReleased && keyPressed == true) {
      //std::cout << "Key released" << std::endl;
      keyPressed = false;
      auto temp = turnOrder.front();
      turnOrder.pop();
      turnOrder.push(temp);
    }

     if (turnOrder.front() == enemyP) {
      //std::cout << "EnemyTurn" << std::endl;
      int rnd = rand() % 4 + 1;
      switch (rnd) {
        case 1:
          if (!(canMove(enemy->pos + Vector2f(-80, 0), map.objects))) {
            enemy->moveLeft();
          }
          break;
        case 2:
          if (!(canMove(enemy->pos + Vector2f(80, 0), map.objects))) {
            enemy->moveRight();
          }
          break;
        case 3:
          if (!(canMove(enemy->pos + Vector2f(0, -80), map.objects))) {
            enemy->moveUp();
          }
          break;
        case 4:
          if (!(canMove(enemy->pos + Vector2f(0, 80), map.objects))) {
            enemy->moveDown();
          }
          break;
        default:
          break;
      }
      auto temp = turnOrder.front();
      turnOrder.pop();
      turnOrder.push(temp);
      //std::cout << "PlayerTurn" << std::endl;
    }

    window.clear(sf::Color::White);

    for (const auto& o : map.objects) {
        for (const auto& t : o) {
          window.draw(t.get()->sprite);
        }
    }    


    window.draw(player->sprite);
    window.draw(enemy->sprite);

    window.display();
    //std::cout << "Waiting for turn" << std::endl;
    }

    return 0;
}


