//Christopher de la Iglesia

#define NUM_ENTS 6

Game::Game() {
  init();
}

Game::~Game() {
  deInit();
}

void Game::init() {
  numEnts = NUM_ENTS;
  entites = new Entity[NUM_ENTS];
  screen = new Screen();
  running = true;
}

void Game::start() {
  clock_t prevTime = clock()*CLOCKS_PER_SEC;
  clock_t curTime = clock()*CLOCKS_PER_SEC;

  while(running) {
    curTime = clock()*CLOCKS_PER_SEC;
    if(curTime-prevTime > 0.005) {
      tick(curTime-prevTime);
      render();
    }
  }

}

void Game::stop() {

}

void Game::deInit() {

}

void Game::tick(double time) {
  for(int i = 0; i < numEnts; i++) {
    (*entites)[i].tick(time);
  }
}

void Game::render() {
  for(int i = 0; i < numEnts; i++) {
    (*entites)[i].render(screen);
  }
}


