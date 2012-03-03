//Christopher de la Iglesia

#define ID 0

Entity::Entity() {

}

Entity::~Entity() {

}

void Entity::tick(double time) {
  x += xSp*time;
  y += ySp*time;
}

void Entity::render(Screen* screen) {
  screen->blitSurface(Art.getSprite(getID),x,y);
}

int Entity::getID() {
  return ID;
}
