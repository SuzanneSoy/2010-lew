#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "erreurs.h"

#define PROFONDEUR 24

typedef enum {
	TRUE = (0==0),
	FALSE = (0==1)
} bool;

// Variable globale boucle.
bool boucle = TRUE;

SDL_Surface* init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		die("Erreur lors de l'initialisation de SDL :");
	}
	
	SDL_Surface* fenetre;
	fenetre = SDL_SetVideoMode(640, 480, PROFONDEUR, SDL_HWSURFACE);
	if (fenetre == NULL) {
		die("Erreur lors de la création de la fenêtre.");
	}
	SDL_WM_SetCaption("Lew", NULL);
	SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);
	
	SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format, 0, 0, 0));
	SDL_Flip(fenetre);
	
	return fenetre;
}

void quit() {
	SDL_Quit();
	exit(EXIT_SUCCESS);
}

void clavier(SDL_Event* ev) {
	switch (ev->key.keysym.sym) {
		case SDLK_ESCAPE:
		case SDLK_q:
			boucle = FALSE;
			break;
	}
}

int main(int argc, char** argv) {
	SDL_Surface* fenetre = init();
	
	SDL_Surface* bloc = SDL_CreateRGBSurface(SDL_HWSURFACE, 11, 11, PROFONDEUR, 0, 0, 0, 0);
	SDL_FillRect(bloc, NULL, SDL_MapRGB(fenetre->format, 255, 255, 255));
	SDL_Rect position = {0,0};
	
	SDL_BlitSurface(bloc, NULL, fenetre, &position);
	SDL_Flip(fenetre);
	
	SDL_Event evenement;
	while (boucle) {
		SDL_WaitEvent(&evenement);
		switch (evenement.type) {
			case SDL_QUIT:
				boucle = FALSE;
				break;
			case SDL_KEYDOWN:
				clavier(&evenement);
				break;
		}
	}
	
	SDL_FreeSurface(bloc);
	
	quit();
}
