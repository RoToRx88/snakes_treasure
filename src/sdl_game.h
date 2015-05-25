#ifndef _SDL_GAME_H_
# define _SDL_GAME_H_

# include <stdio.h>
# include <stdlib.h>
# include "snake.h"

typedef struct s_Snake t_Snake;

/**
@brief permet de charger des images .bmp
@param filename chaine de caractère (nom de fichier)


SDL_Surface charge une image .bmp

@return none
*/


SDL_Surface		*sdl_Load_Image(char *filename);

/**
@brief applique une surface sur la fenêtre
@param x entier >0
@param y entier >0
@param source pointeur sur SDL-Surface
@param destination pointeur sur SDL-Surface

sdl_Apply_Surface applique une surface sur la fenêtre

@return none
*/
void sdl_Apply_Surface (int x, int y, SDL_Surface *source, SDL_Surface *destination);


/**
@brief affiche les butins non pris
@param snake est un pointeur sur t_Snake

sdl_Display_Loot affiche les butins et les coeurs non pris, si le personnage est sur une "case butin", alors le butin est pris et donc ne s'affiche plus.

@return none
*/

void sdl_Display_Loot(t_Snake *snake) ;

/**
@brief place les murs, le perso et les serpents sur le terrain
@param snake est un pointeur sur t_Snake

sdl_Draw_Map transforme les # par des murs et affiche le personnage et les serpents

@return 1
*/


int sdl_Draw_Map(t_Snake *snake);

/**
@brief affichage du menu
@param snake est un pointeur de structure t_Snake

sdl_Menu affiche le menu. La surface du fond BACKROUND0 sera appliqué à la fenetre avec par dessus le menu (proposition Play ou Quit).

@return 0
*/

int   sdl_Menu (t_Snake *snake);

/**
@brief affiche chaque partie des 4 serpents.
@param snake est un pointeur de structure t_Snake

sdl_Display_Guardian affiche partie par partie (en fonction de la taille du serpent)

@return none
*/

void	sdl_Display_Guardian(t_Snake *snake);

/**
@brief initialisation du jeu
@param snake est un pointeur sur t_Snake

sdl_Init initialise le jeu avec les images

@return 0
*/

int     sdl_Init(t_Snake *snake);


#endif //_SDL_GAME_H_
