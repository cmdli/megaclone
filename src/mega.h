//Christopher de la Iglesia

#ifndef MEGA_H
#define MEGA_H

#define SPRITE_NUM_WIDTH 10
#define SPRITE_WIDTH 16
#define SPRITE_HEIGHT 16

#include "SDL.h"
#include <time.h>

void printError(char* message);
SDL_Rect* getSprite(int id);
SDL_Surface* getSpriteSurface();
void artInit();
void artDeInit();
SDL_Rect* getSprite(int x, int y, int width, int height);

#include "Screen.h"
#include "Entity.h"
#include "Player.h"
#include "Game.h"

#endif
