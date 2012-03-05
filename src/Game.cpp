//Christopher de la Iglesia

#define NUM_ENTS 6

#include "mega.h"

Game::Game() {
  /*entities = new Entity[NUM_ENTS];*/
  window = new Screen();
  running = true;
}

Game::~Game() {
  /*delete entities;*/
  delete window;

}



void Game::start() {
  clock_t prevTime = clock()*CLOCKS_PER_SEC;
  clock_t curTime = clock()*CLOCKS_PER_SEC;

  while(running) {
    curTime = clock()*CLOCKS_PER_SEC;
    if(curTime-prevTime > 0.005) {
		prevTime = clock()*CLOCKS_PER_SEC;
      //tick(curTime-prevTime);
      render();
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
	window->push();
}


