//Christopher de la Iglesia

#include "mega.h"

extern SDL_Surface* sprites = NULL;

void artInit() {
	sprites = NULL;
  sprites = SDL_LoadBMP("sprites.bmp");
}

void artDeInit() {
  SDL_FreeSurface(sprites);
}

SDL_Rect* getSprite(int id) {
	if(sprites == NULL) return NULL;
  return getSprite( (id%SPRITE_NUM_WIDTH)*SPRITE_WIDTH , (id-id%SPRITE_NUM_WIDTH)*SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT);
}

SDL_Rect* getSprite(int x, int y, int width, int height) {
  SDL_Rect rect;

  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;

  return &rect;  
}

SDL_Surface* getSpriteSurface() {
  return sprites;
}
