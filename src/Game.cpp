//Christopher de la Iglesia

#define NUM_ENTS 6

#include "mega.h"

SDL_Event eventBuffer;

Game::Game() {
  window = new Screen("Megaclone");
  running = true;
}

Game::~Game() {
  delete window;

}



void Game::start() {
  clock_t prevTime = (clock()*1000)/CLOCKS_PER_SEC;
  clock_t curTime = (clock()*1000)/CLOCKS_PER_SEC;

  currentMap = new Map();

  running = currentMap->loadFromFile("../map.bmp");
  running = currentMap->loadEnemies("../config");

  while(running) {
    curTime = (clock()*1000)/CLOCKS_PER_SEC;
    if(curTime-prevTime > 100) {
      processEvents();
      tick(curTime-prevTime);
      render();
      prevTime = (clock()*1000)/CLOCKS_PER_SEC;
    }
  }

}

void Game::stop() {

}

void Game::tick(double time) {
  currentMap->tick(time);
}

void Game::render() {
	window->preRender();
	/*for(int i = 0; i < numEnts; i++) {
		entities[i].render(window);
	}*/
	currentMap->render(window);
	window->push();
}

void Game::processEvents() {
	while(SDL_PollEvent(&eventBuffer)) {
		switch(eventBuffer.type) {
		case SDL_QUIT:
			running = false;
			break;
		}
	}
}


