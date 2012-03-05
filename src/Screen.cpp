//Christopher de la Iglesia

#include "mega.h"

Screen::Screen() {

  screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);

  //artInit();
}

Screen::~Screen() {
	SDL_FreeSurface(screen);
  //artDeInit();
}

void Screen::preRender() {
	SDL_FillRect(screen,NULL,0x00FF00);
}

void Screen::blitSurface(SDL_Surface* src, int x, int y, SDL_Rect* rect) {
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( src, rect, screen, &offset );
}

void Screen::push() {
	SDL_Flip(screen);
}
