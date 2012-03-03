//Christopher de la Iglesia

#ifndef PLAYER_H
#define PLAYER_H

class Player: public Entity {
 public:
  Player();
  ~Player();
  void tick(double time): tick(time);
  void render(Screen* screen): render(screen);
  int getID();


 private:
};


#endif
