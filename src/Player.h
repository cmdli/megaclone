//Christopher de la Iglesia

#ifndef PLAYER_H
#define PLAYER_H


class Player: public Entity {
 public:
	 Player();
  ~Player();
  void tick(double time);
  void render(Screen* window);
  int getID();

 private:
};


#endif
