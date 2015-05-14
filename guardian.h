#ifndef _GUARDIAN_H_
# define _GUARDIAN_H_

# include <stdio.h>
# include <stdlib.h>
# include "snake.h"


typedef struct		s_guardian
{
  unsigned int		pos_x;
  unsigned int		pos_y;
  struct s_guardian	*next;
}			t_guardian;

/**
@brief initialise les serpents.
@param snake est un pointeur de structure t_snake
@param i entier qui prend comme valeur 0, 1, 2, 3 qui correspond au différent

init_guardian initialise les 4 serpents au milieu du terrain.

@return 1
*/

int			init_guardian(t_snake *snake, int i);

/**
@brief vérifie s'il y a collision entre le joueur et les serpents.
@param snake est un pointeur de structure t_snake

check_guardian_collision vérifie la position du joueur par rapport à la position des serpents, et si elles sont semblables, la vie du personnage diminue de 1.

@return 1
*/
int		check_guardian_collision(t_snake *snake);

/**
@brief affiche chaque partie des 4 serpents.
@param snake est un pointeur de structure t_snake

display_guardian affiche partie par partie (en fonction de la taille du serpent

@return none
*/

void			display_guardian(t_snake *snake);

/**
@brief fait avancer chaque serpent
@param snake est un pointeur sur t_snake

calc_guardian_pos gère les positions des serpents en fonction de leur numéro en appelant les fonctions de déplacement guard_i pour i allant de 0 à 3.

@return none
*/

void			calc_guardian_pos(t_snake *snake);

/**
@brief déplacement du serpent 0
@param g est un pointeur sur guardian

guard_0 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_0(t_guardian *g);

/**
@brief déplacement du serpent 1
@param g est un pointeur sur guardian

guard_1 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_1(t_guardian *g);

/**
@brief déplacement du serpent 2
@param g est un pointeur sur guardian

guard_2 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_2(t_guardian *g);

/**
@brief déplacement du serpent 3
@param g est un pointeur sur guardian

guard_3 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_3(t_guardian *g);

#endif //_GUARDIAN_H_
