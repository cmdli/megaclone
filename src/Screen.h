//Christopher de la Iglesia

#ifndef SCREEN_H
#define SCREEN_H


class Screen {

 public:
	 Screen();
  Screen(char* title);
  ~Screen();
  bool blitSurface(SDL_Surface* src, int x, int y, SDL_Rect* rect = NULL);
  void preRender();
  void push();

  private:
	SDL_Surface* screen;
};


#endif
