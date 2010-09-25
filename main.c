#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#define die(msg) {\
	fprintf(stderr, msg "\n"); \
	fprintf(stderr, "  %s\n", SDL_GetError()); \
	exit(EXIT_FAILURE); \
}

int main(int argc, char** argv) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		die("Erreur lors de l'initialisation de SDL :");
	}
	
	SDL_Surface* fenetre;
	fenetre = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE);
	if (fenetre == NULL) {
		die("Erreur lors de la création de la fenêtre.");
	}
	SDL_WM_SetCaption("Lew", "lew.png");
	
	SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 255, 0, 128));
	SDL_Flip(fenetre);
	
	while (1);
	
	SDL_Quit();
	return EXIT_SUCCESS;
}
