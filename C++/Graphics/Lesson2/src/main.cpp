#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main (){
	const int WINDOW_WIDTH = 800;			//Window width
	const int WINDOW_HEIGHT = 600;			//Window height


	if (SDL_Init(SDL_INIT_VIDEO) < 0){		//Start SDL with SDL_Init(SDL_INIT_VIDEO) and check if it returns error code (less then 0)
		cout << "SDL Init fail!" << endl;	//If SLD_Init returns error code print out and exit
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,  SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);	//Create a window with SDL_CreateWindow and store the returned pointer to window (SDL_Window* data type)
	if(window == NULL){
		SDL_Quit();			//If SDL_CreateWindow returns a NULL pointer call SDL_Quit
		return 2;
	}
	


	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);		//We create a renderer with SDL_CreateRenderer and we set the location of set renderer to render with holds the address. 
	if(renderer == NULL){
		cout << "Could not create renderer!" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;										//We check if we succesfully created the renderer if not we close window, quit SDL and return 3 (eronious error code)
		}
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);	//We create a texture. we give it the renderer to use, specify the color encodeing of the pixels and the rest is self explanatory
	if(texture == NULL){
		cout << "Could not create texture!" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;															//We check if we succesffully created the texture if not we close winodw, delete the rederer, quit SDL and return 4 (erronious error code)
		}
	Uint32* buffer = new Uint32[WINDOW_WIDTH*WINDOW_HEIGHT];					//We create a buffer to hold the data for the pixels. Uint32 as we need to make sure that we use 32 bits for every pixel to be compatibile with RGBA

	memset(buffer, 0xFF, WINDOW_WIDTH*WINDOW_HEIGHT*sizeof(Uint32));				//We use memset() to set a value to the pixels. Not ideal as pixels have 4 byts in our case and memset() set the values in our buffer 1 byte at a time

	SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH*sizeof(Uint32));				//We load the data from the buffer into texture
	SDL_RenderClear(renderer);									//We clear the renderer
	SDL_RenderCopy(renderer, texture, NULL, NULL);							//We coppy the data from the texturer to the renderer
	SDL_RenderPresent(renderer);									//Finally we tell the renderer to send the data to the screen.
	bool quit = false;			//Boolean for storeing if the window is closed 
	SDL_Event event;			//SDL_Event for storeing the events durring main loop


	while(!quit){				//Main loop. 
		
		while(SDL_PollEvent(&event)){	// Loop to pool events and store them in event. We are useing SLD_PollEvent
			if(event.type == SDL_QUIT){	//If the event.type is equal to SDL_QUIT 
				quit = true;		//we change quit=true so we live the main loop
			}
		}
	}

	delete [] buffer;			//Make sure we delete the data we requested for the buffer
	SDL_DestroyTexture(texture); 		//We destroy the texture object
	SDL_DestroyRenderer(renderer);		//We destroy the render object
	SDL_DestroyWindow(window);		//Distory the window.
	SDL_Quit();				//SDL_Quit

	return 0;
}
