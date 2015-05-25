#ifndef _GUARDIAN_H_
# define _GUARDIAN_H_

# include <stdio.h>
# include <stdlib.h>

typedef struct		s_Guardian // liste chainée des positions de chaques parties du serpent/guardient
{
  unsigned int		pos_x;
  unsigned int		pos_y;
  struct s_Guardian	*next;
}			t_Guardian;

/**
@brief déplacement du serpent 0
@param g est un pointeur sur guardian

guard_0 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_0(t_Guardian *g);

/**
@brief déplacement du serpent 1
@param g est un pointeur sur guardian

guard_1 gère le déplacement du deuxieme serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_1(t_Guardian *g);

/**
@brief déplacement du serpent 2
@param g est un pointeur sur guardian

guard_2 gère le déplacement du troisieme serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_2(t_Guardian *g);

/**
@brief déplacement du serpent 3
@param g est un pointeur sur guardian

guard_3 gère le déplacement du quatrieme serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void			guard_3(t_Guardian *g);

#endif //_GUARDIAN_H_
