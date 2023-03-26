#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>				//Not used can be deleted

using namespace std;

int main (){
	const int WINDOW_WIDTH = 800;		//Window width
	const int WINDOW_HEIGHT = 600;		//Window height


	if (SDL_Init(SDL_INIT_VIDEO) < 0){	//Start SDL with SDL_Init(SDL_INIT_VIDEO) and check if it returns error code (less then 0)
		cout << "SDL Init fail!" << endl;	//If SLD_Init returns error code print out and exit
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,  SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);	//Create a window with SDL_CreateWindow and store the returned pointer to window (SDL_Window* data type)
	if(window == NULL){
		SDL_Quit();			//If SDL_CreateWindow returns a NULL pointer call SDL_Quit
		return 2;
	}
	
	bool quit = false;			//Boolean for storeing if the window is closed 
	SDL_Event event;			//SDL_Event for storeing the events durring main loop
	while(!quit){				//Main loop. 
		
		while(SDL_PollEvent(&event)){	// Loop to pool events and store them in event. We are useing SLD_PollEvent
			if(event.type == SDL_QUIT){	//If the event.type is equal to SDL_QUIT 
				quit = true;		//we change quit=true so we live the main loop
			}
		}
	}

	SDL_DestroyWindow(window);		//Distory the window.
	SDL_Quit();				//SDL_Quit

	return 0;
}
