//Christopher de la Iglesia

#ifndef ART_H
#define ART_H

SDL_Rect* getSprite(int id);
SDL_Surface* getSpriteSurface();
void artInit();
void artDeInit();
SDL_Rect* getSprite(int x, int y, int width, int height);
SDL_Rect* getRect(int x, int y, int width, int height);
SDL_Rect* getTile(int id);
SDL_Surface* getTileSurface();


#endif
