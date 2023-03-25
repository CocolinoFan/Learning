#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace std;

int main (){
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		cout << "SDL Init fail!" << endl;
		return 1;
	}
	
	cout << "SDL Init success" <<endl;

	SDL_Quit();

	return 0;
}
