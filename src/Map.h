//Christopher de la Iglesia

#ifndef MAP_H
#define MAP_H

class Player;
class Entity;

class Map {

 public:
  Map();
  ~Map();
  bool loadFromFile(char* name);
  bool render(Screen* window);
  bool tick(double time);
  bool loadEnemies(char* name);

  private:
  int* tiles;
  Entity** units;
  Player* player;
  int numEntities;
  int width;
  int height;
};

bool createEntity(char* txt, Entity* unit);

#endif
