//Christopher de la Iglesia

#ifndef GAME_H
#define GAME_H

#include "mega.h"

class Game {

 public:
  Game();
  ~Game();
  void init();
  void start();
  void stop();
  void deInit();
  void processEvents();

 private:
  void tick(double time);
  void render();
  Entity* entities;
  Screen* window;
  Map* currentMap;
  int numEnts;
  bool running;

};

#endif
