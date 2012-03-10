//Christopher de la Iglesia

#define NUM_ENTS 6

#include "mega.h"

SDL_Event eventBuffer;

Game::Game() {
  /*entities = new Entity[NUM_ENTS];*/
  window = new Screen("Megaclone");
  running = true;
}

Game::~Game() {
  /*delete entities;*/
  delete window;

}



void Game::start() {
  clock_t prevTime = (clock()*1000)/CLOCKS_PER_SEC;
  clock_t curTime = (clock()*1000)/CLOCKS_PER_SEC;

  currentMap = new Map();

  running = currentMap->loadFromFile("../map.bmp");

  while(running) {
    curTime = (clock()*1000)/CLOCKS_PER_SEC;
    if(curTime-prevTime > 100) {
      processEvents();
      //tick(curTime-prevTime);
      render();
      prevTime = (clock()*1000)/CLOCKS_PER_SEC;
    }
  }

}

void Game::stop() {

}

void Game::tick(double time) {
  for(int i = 0; i < NUM_ENTS; i++) {
    entities[i].tick(time);
  }
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


