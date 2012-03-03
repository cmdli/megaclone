#ifndef ENTITY_H
#define ENTITY_H

class Entity {

 public:
  Entity();
  ~Entity();
  void tick(double time);
  void render(Screen* screen);
  virtual int getID();

 private:
  int x;
  int y;
  double xSp;
  double ySp;

};


#endif
