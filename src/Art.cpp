//Christopher de la Iglesia

#include "mega.h"

SDL_Surface* sprites;
SDL_Surface* tiles;

void artInit() {
  sprites = SDL_LoadBMP("../sprites.bmp");
  tiles = SDL_LoadBMP("../tiles.bmp");
}

void artDeInit() {
  SDL_FreeSurface(sprites);
  SDL_FreeSurface(tiles);
}

SDL_Rect* getSprite(int id) {
	if(sprites == NULL) 
		return NULL;
	return getRect( (id%SPRITE_NUM_WIDTH)*SPRITE_WIDTH , (id-id%SPRITE_NUM_WIDTH)*SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT);
}

SDL_Rect* getRect(int x, int y, int width, int height) {
  SDL_Rect* rect = new SDL_Rect;

  rect->x = x;
  rect->y = y;
  rect->w = width;
  rect->h = height;

  return rect;  
}

SDL_Rect* getTile(int id) {
	if(tiles == NULL) {
		printError("Art Tile sheet is called but null.");
		return NULL;
	}

	return getRect( (id%TILE_NUM_WIDTH)*TILE_WIDTH , (id-id%TILE_NUM_WIDTH)*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);

}

SDL_Surface* getSpriteSurface() {
  return sprites;
}

SDL_Surface* getTileSurface() {
	return tiles;
}
