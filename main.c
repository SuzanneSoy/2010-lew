#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main(int argc, char** argv) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Erreur à l'initialisation de SDL :");
		fprintf(stderr, "  %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	
	
	SDL_Quit();
	return 0;
}
