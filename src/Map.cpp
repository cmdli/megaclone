//Christopher de la Iglesia

#include "mega.h"

#define AIR 0
#define BRICK 1

Map::Map() {
  tiles = NULL;
  width = 0;
  height = 0;
}

Map::~Map() {
  if(tiles != NULL)
    delete tiles;
}

bool Map::loadFromFile(char* name) {
  SDL_Surface* mapRaw = SDL_LoadBMP(name);
  if(mapRaw == NULL) {
    printError("Map Name not valid");
	return false;
  }
  SDL_Surface* map = SDL_DisplayFormat(mapRaw);
  SDL_FreeSurface(mapRaw);


  Uint32* pixels = (Uint32*) map->pixels;

  width = map->w;
  height = map->h;

  tiles = new int[map->w*map->h];

  for(int x = 0; x < map->w; x++) {
    for(int y = 0; y < map->h; y++) {
      if((tiles[x + y*width] = getTileFromColor(pixels[(y*map->w) + x])) == -1) {
		printError("Map File color not correct...\n");
		printf("%u\n",pixels[(y*map->w) + x]);
		tiles[x+y*width] = BRICK;
      }
    }
  }
    return true;
}

bool Map::render(Screen* window) {
	if(tiles == NULL) {
		printError("Tiles is null! Cannot render Map");
		return false;
	}

	for(int x = 0; x <  width; x++) {
		for(int y = 0; y < height; y++) {
			if((window->blitSurface(getTileSurface(),x*TILE_WIDTH,y*TILE_WIDTH,getTile(tiles[x+y*width]))) == false) {
				printError("Failed to render a tile!");
				return false;
			}
		}
	}
	return true;
}

int getTileFromColor(Uint32 color) {
  switch(color) {
  case 0xFFFFFF:
    return AIR;
  case 0x000000:
    return BRICK;
  }
  return -1;
}
