//Christopher de la Iglesia

#ifndef MAP_H
#define MAP_H

class Map {

 public:
  Map();
  ~Map();
  bool loadFromFile(char* name);
  bool render(Screen* window);

  private:
  int* tiles;
  int width;
  int height;
};

#endif
