#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "erreurs.h"

SDL_Surface* init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		die("Erreur lors de l'initialisation de SDL :");
	}
	
	SDL_Surface* fenetre;
	fenetre = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE);
	if (fenetre == NULL) {
		die("Erreur lors de la création de la fenêtre.");
	}
	SDL_WM_SetCaption("Lew", "lew.png");
	
	return fenetre;
}

void quit() {
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

int main(int argc, char** argv) {
	SDL_Surface* fenetre = init();
	
	SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 255, 0, 128));
	SDL_Flip(fenetre);
	
	while (1);
	
	quit();
}
