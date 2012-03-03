//Christopher de la Iglesia

#ifndef GAME_H
#define GAME_H

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
  (*Entity)[] entities;
  Screen* screen;
  int numEnts;
  bool running;

};

#endif
