//Christopher de la Iglesia

#define ID -1

#include "mega.h"

Entity::Entity() {
	x = 0;
	y = 0;
	xSp = 0.0;
	ySp = 0.0;
}

Entity::~Entity() {

}

void Entity::tick(double time) {
}

void Entity::render(Screen* window, int id) {
	if(window == NULL) {
		printError("The Window is not initialized!");
		return;
	}
	window->blitSurface( getSprite(id), x , y );
}

bool Entity::setX(int xn) {
	x = xn;
	return true;
}

bool Entity::setY(int yn) {
	y = yn;
	return true;
}

int Entity::getID() {
	return ID;
}
