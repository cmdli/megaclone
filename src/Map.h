//Christopher de la Iglesia

#ifndef MAP_H
#define MAP_H

class Map {

 public:
  Map();
  ~Map();
  void loadFromFile(char* name);
  void render(Screen* window);

  private:
  int* tiles;
};

#endif
