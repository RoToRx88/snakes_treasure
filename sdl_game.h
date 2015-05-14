#ifndef _SDL_GAME_H_
# define _SDL_GAME_H_

# include <stdio.h>
# include <stdlib.h>
# include "snake.h"

/**
@brief permet de charger des image .bmp
@param filename chaine de caractère (nom de fichier")


SDL_Surface charge une image .bmp

@return none
*/


SDL_Surface		*load_image(char *filename);

/**
@brief
@param x entier >0
@param y entier >0
@param source
@param destination

apply_surface applique une surface sur la fenêtre ????

@return none
*/
void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);


/**
@brief affiche les butins non pris
@param snake est un pointeur de structure t_snake

display_loot affiche les butins et les coeurs non pris, si le personnage est sur une "case butin", alors le butin est pris et donc ne s'affiche plus.

@return none
*/

void display_loot(t_snake *snake) ;

/**
@brief place les murs, le perso et les serpents sur le terrain
@param snake est un pointeur de structure t_snake

draw_map transforme les # par des murs et affiche le personnage et les serpents

@return 1
*/


int draw_map(t_snake *snake);

void    menu (t_snake *snake);

/**
@brief initialisation du jeu
@param snake est un pointeur de structure t_snake

init_sdl initialise le jeu avec les images

@return 0
*/

int     init_sdl(t_snake *snake);





#endif //_SDL_GAME_H_
