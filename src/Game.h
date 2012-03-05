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

 private:
  void tick(double time);
  void render();
  Entity* entities;
  Screen* window;
  int numEnts;
  bool running;

};

#endif
