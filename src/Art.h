//Christopher de la Iglesia

#ifndef ART_H
#define ART_H

SDL_Surface* getSpriteSurface();
void artInit();
void artDeInit();
SDL_Surface* getSprite(int id);
SDL_Rect* getRect(int x, int y, int width, int height);
SDL_Rect* getTile(int id);
SDL_Surface* getTileSurface();
SDL_Surface* loadSurface(char* name);
void loadSprites();


#endif
