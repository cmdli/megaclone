//Christopher de la Iglesia

#ifndef MEGA_H
#define MEGA_H

#define SPRITE_NUM_WIDTH 10
#define SPRITE_WIDTH 16
#define SPRITE_HEIGHT 16
#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define TILE_NUM_WIDTH 10

#include "SDL.h"
#include <time.h>

void printError(char* message);
int getTileFromColor(Uint32 color);

#include "Art.h"
#include "Screen.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Game.h"

#endif
