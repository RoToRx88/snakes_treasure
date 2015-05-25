#include "guardian.h"
#include <assert.h>

/**
@brief déplacement du serpent 0
@param g est un pointeur sur guardian

guard_0 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_0(t_Guardian *g)
{
  assert(g != NULL); //Le guardien ne doit pas être nul
  if (g->pos_y == 8 && g->pos_x > 1) g->pos_x -= 1;
  else if (g->pos_x == 1 && g->pos_y > 1) g->pos_y -= 1;
  else if (g->pos_y == 1 && g->pos_x < 8) g->pos_x += 1;
  else if (g->pos_x == 8 && g->pos_y < 8) g->pos_y += 1;
}


/**
@brief déplacement du serpent 1
@param g est un pointeur sur guardian

guard_1 gère le déplacement du deuxieme serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_1(t_Guardian *g)
{
  assert(g != NULL); //Le guardien ne doit pas être nul
  if (g->pos_y == 8 && g->pos_x > 9) g->pos_x -= 1;
  else if (g->pos_x == 9 && g->pos_y > 1) g->pos_y -= 1;
  else if (g->pos_y == 1 && g->pos_x < 16) g->pos_x += 1;
  else if (g->pos_x == 16 && g->pos_y < 8) g->pos_y += 1;
}

/**
@brief déplacement du serpent 2
@param g est un pointeur sur guardian

guard_2 gère le déplacement du troisieme serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_2(t_Guardian *g)
{
  assert(g != NULL); //Le guardien ne doit pas être nul
  if (g->pos_y == 16 && g->pos_x > 1) g->pos_x -= 1;
  else if (g->pos_x == 1 && g->pos_y > 9) g->pos_y -= 1;
  else if (g->pos_y == 9 && g->pos_x < 8) g->pos_x += 1;
  else if (g->pos_x == 8 && g->pos_y < 16) g->pos_y += 1;
}

/**
@brief déplacement du serpent 3
@param g est un pointeur sur guardian

guard_3 gère le déplacement du quatrieme serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_3(t_Guardian *g)
{
  assert(g != NULL); //Le guardien ne doit pas être nul
  if (g->pos_y == 16 && g->pos_x > 9) g->pos_x -= 1;
  else if (g->pos_x == 9 && g->pos_y > 9) g->pos_y -= 1;
  else if (g->pos_y == 9 && g->pos_x < 16) g->pos_x += 1;
  else if (g->pos_x == 16 && g->pos_y < 16) g->pos_y += 1;
}

