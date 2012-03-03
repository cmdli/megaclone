//Christopher de la Iglesia

Screen::Screen() {
  SDL_Init(SDL_INIT_EVERYTHING);

  screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);

  Art.init();
}

Screen::~Screen() {
  Art.deinit();

  SDL_Quit();
}

void Screen::blitSurface(SDL_Surface* src,SDL_Rect* rect = NULL, int x, int y) {
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( src, rect, screen, &offset );
}

void Screen::blitTiles((*int)[][] tiles) {
  for(int y = 0; y < tiles.size(); y++) {
    for(int x = 0; x < tiles[y].size(); x++) {
      blitSurface(Art.getSpriteSurface(),Art.getSprite(tiles[y][x]),x*SPRITE_WIDTH,y*SPRITE_HEIGHT);
    }
  }
}

void Screen::push() {

}
