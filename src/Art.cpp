//Christopher de la Iglesia

#include "mega.h"

SDL_Surface* sprites;
SDL_Surface* tiles;

SDL_Surface* player;

//Loads Art Files
void artInit() {
	sprites = loadSurface("../sprites.bmp");
	tiles = loadSurface("../tiles.bmp");
}

//Removes art files
void artDeInit() {
  SDL_FreeSurface(sprites);
  SDL_FreeSurface(tiles);
}

//Gets the sprite based on ID
SDL_Rect* getSprite(int id) {
	if(sprites == NULL) 
		return NULL;
	return getRect( (id%SPRITE_NUM_WIDTH)*SPRITE_WIDTH , (id-id%SPRITE_NUM_WIDTH)*SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT);
}

//Creates a SDL_Rect object based on the config values
SDL_Rect* getRect(int x, int y, int width, int height) {
  SDL_Rect* rect = new SDL_Rect;

  rect->x = x;
  rect->y = y;
  rect->w = width;
  rect->h = height;

  return rect;  
}


//Returns the SDL_Rect which designates the area of the Tile sheet to blit
SDL_Rect* getTile(int id) {
	if(tiles == NULL) {
		printError("Art Tile sheet is called but null.");
		return NULL;
	}

	return getRect( (id%TILE_NUM_WIDTH)*TILE_WIDTH , (id-id%TILE_NUM_WIDTH)*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);

}

SDL_Surface* loadSurface(char* name) {
	SDL_Surface* image = NULL;

	SDL_Surface* optImage = NULL;

	image = SDL_LoadBMP(name);

	if(image != NULL) {
		optImage = SDL_DisplayFormat(image);
		SDL_FreeSurface(image);

		if(optImage != NULL) {
			Uint32 colorkey = SDL_MapRGB(optImage->format,0xFF,0,0xFF);
			SDL_SetColorKey(optImage,SDL_SRCCOLORKEY,colorkey);
		}
	}

	return optImage;
}

void loadSprites() {

}

SDL_Surface* getSpriteSurface() {
  return sprites;
}

SDL_Surface* getTileSurface() {
	return tiles;
}
