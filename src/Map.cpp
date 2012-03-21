//Christopher de la Iglesia

#include "mega.h"

#define AIR 0
#define BRICK 1
#define COMMENT_CHAR '#'
#define COLOR_SHEET "../color"
#define COLOR_SIZE 16777216

unsigned _int8* colors;

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

using namespace std;

bool Map::loadEnemies(char* name) {

	ifstream input;
	
	input.open(name,ios::in);

	if(input == NULL)
		return false;

	char* txt = new char[10];
	int numLines = 0;

	while(!input.eof()) {
		input.getline(txt,10);
		if(*txt != COMMENT_CHAR)
			numLines++;
	}
	input.seekg(ios::beg);

	units = new Entity*[numLines-1];

	player = new Player();
	input.getline(txt,10);
	if(*txt != COMMENT_CHAR)
		createEntity(txt,player);

	for(int i = 0; i < numLines-1; i++) {
		input.getline(txt,10);
		if(*txt != COMMENT_CHAR)
			createEntity(txt,units[i]);
	}

	input.close();

	numEntities = numLines-1;

	return true;
}

bool createEntity(char* txt, Entity* unit) {

	char tmp[4];
	int i = 0;

	for(i = 0;i < 4; i++) {
		tmp[i] = ' ';
	}
	i = 0;

	while(txt && *txt != ' ' && i < 4) {
		tmp[i] = *txt;
		txt++;
		i++;
	}
	i = 0;
	unit->setX(atoi(tmp));

	while(txt && *txt == ' ')
		txt++;

	while(txt && *txt != ' ' && i < 4) {
		tmp[i] = *txt;
		txt++;
		i++;
	}
	i = 0;
	unit->setY(atoi(tmp));

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

	player->render(window);

	for(int i = 0; i < numEntities; i++) {
		units[i]->render(window);
	}
	return true;
}

//Passes the time to units tick
bool Map::tick(double time) {
  player->tick(time);
  for(int i = 0; i < numEntities; i++) {
    units[i]->tick(time);
  }
  return true;
}

//Loads the Color Map
bool loadColorSheet(char* name) {

  colors = new unsigned _int8[COLOR_SIZE];

  ifstream input;

  input.open(name,ios::in);

  char* txt = new char[10];
  int index = 0;
  unsigned _int8 value = 0;

  while(!input.eof()) {
    input.getline(txt,10);
    if(txt && *txt != COMMENT_CHAR) {
      char tmp[10];
      int i = 0;

      for(i = 0;i < 10; i++) {
	tmp[i] = ' ';
      }
      i = 0;

      while(txt && *txt != ' ' && i < 10) {
	tmp[i] = *txt;
	txt++;
	i++;
      }
      i = 0;
      index = atoi(tmp);

      while(txt && *txt == ' ')
	txt++;

      while(txt && *txt != ' ' && i < 10) {
	tmp[i] = *txt;
	txt++;
	i++;
      }
      i = 0;
      value = atoi(tmp);

      colors[index] = value;
    }
  }

  return true;
}

//Accesses Color Map
int getTileFromColor(Uint32 color) {

  if(colors == NULL) {
    loadColorSheet(COLOR_SHEET);
  }

  return colors[color];
}
