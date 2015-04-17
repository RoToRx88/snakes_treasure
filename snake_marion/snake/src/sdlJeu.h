#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL.h>
#include "jeu.h"


typedef struct
{
	Jeu jeu;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_perso;
	SDL_Surface* surface_mur;
	SDL_Surface* surface_serpent;
	//SDL_Surface* surface_temple;
} sdlJeu;

void sdljeuInit(sdlJeu *);
void sdljeuBoucle(sdlJeu *);
void sdljeuLibere(sdlJeu *);

#endif
