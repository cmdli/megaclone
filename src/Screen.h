//Christopher de la Iglesia

#ifndef SCREEN_H
#define SCREEN_H

class Screen {

 public:
  Screen();
  ~Screen();
  void blitSurface(SDL_Surface* src, int x, int y);
  void blitTiles((*int)[][] tiles);
  void push();

  private:
  SDL_Surface* screen;
};


#endif
