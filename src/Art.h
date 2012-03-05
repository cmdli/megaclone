//Christopher de la Iglesia

#ifndef ART_H
#define ART_H


SDL_Rect* getSprite(int id);
SDL_Surface* getSpriteSurface();
void artInit();
void artDeInit();

extern SDL_Surface* sprites = NULL;
SDL_Rect* getSprite(int x, int y, int width, int height);


#endif
