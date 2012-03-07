//Christopher de la Iglesia

#include "mega.h"

#define AIR 0
#define BRICK 1

Map::Map() {
  tiles = NULL;
}

Map::~Map() {
  if(tiles != NULL)
    delete tiles;
}

void Map::loadFromFIle(char* name) {
  SDL_Surface* map = SDL_LoadBMP(name);
  if(map == NULL) {
    printError("Map Name not valid");
  }

  Uint32* pixels = (Uint32*) map->pixels;

  tiles = new int[map->w][map->h];

  for(int x = 0; x < map->w; x++) {
    for(int y = 0; y < map->h; y++) {
      if((tiles[x][y] = getTileFromColor(pixels[(y*map->w) + x])) == -1) {
	printError("Map File color not correct...");
	tiles[x][y] = AIR;
      }
    }
  }
    
}

void render(Screen* window) {
  
}

void getTileFromColor(Uint32 color) {
  switch(color) {
  case 0x000000:
    return AIR;
  case 0xFFFFFF:
    return BRICK;
  }
  return -1;
}
