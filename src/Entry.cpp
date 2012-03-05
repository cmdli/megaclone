//Christopher de la Iglesia

#include "mega.h"

int main( int argc, char* args[] ){

	SDL_Init( SDL_INIT_VIDEO );
    
	Game* game = new Game();

	game->start();
	

    //Quit SDL
    SDL_Quit();
    
    return 0;    
}