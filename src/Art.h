//Christopher de la Iglesia

#ifndef ART_H
#define ART_H

class Art {

 public:
  static SDL_Surface* getSprite(int id);
  static void init();
  static void deInit();

 private:
  static SDL_Surface* sprites;
  static SDL_Surface* getSprite(int x, int y);
};

#endif
