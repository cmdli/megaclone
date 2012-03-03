//Christopher de la Iglesia



static Art::init() {
  sprites = SDL_LoadBMP("sprites.bmp");
}

static Art::deInit() {
  SDL_FreeSurface(sprites);
}

static SDL_Rect* getSprite(int id) {
  return getSprite( (id%SPRITE_NUM_WIDTH)*SPRITE_WIDTH , (id-id%SPRITE_NUM_WIDTH)*SPRITE_HEIGHT, SPRITE_WIDTH, SPRITE_HEIGHT);
}

static SDL_Rect* getSprite(int x, int y, int width, int height) {
  SDL_Rect* rect;

  rect->x = x;
  rect->y = y;
  rect->width = width;
  rect->height = height;

  return rect;  
}

static SDL_Surface* getSpriteSurface() {
  return sprites;
}
