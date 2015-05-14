#include "snake.h"

/**
@brief déplacement du serpent 0
@param g est un pointeur sur guardian

guard_0 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_0(t_guardian *g)
{
  if (g->pos_y == 8 && g->pos_x > 1) g->pos_x -= 1;
  else if (g->pos_x == 1 && g->pos_y > 1) g->pos_y -= 1;
  else if (g->pos_y == 1 && g->pos_x < 8) g->pos_x += 1;
  else if (g->pos_x == 8 && g->pos_y < 8) g->pos_y += 1;
}

/**
@brief déplacement du serpent 1
@param g est un pointeur sur guardian

guard_1 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_1(t_guardian *g)
{
  if (g->pos_y == 8 && g->pos_x > 9) g->pos_x -= 1;
  else if (g->pos_x == 9 && g->pos_y > 1) g->pos_y -= 1;
  else if (g->pos_y == 1 && g->pos_x < 16) g->pos_x += 1;
  else if (g->pos_x == 16 && g->pos_y < 8) g->pos_y += 1;
}

/**
@brief déplacement du serpent 2
@param g est un pointeur sur guardian

guard_2 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_2(t_guardian *g)
{
  if (g->pos_y == 16 && g->pos_x > 1) g->pos_x -= 1;
  else if (g->pos_x == 1 && g->pos_y > 9) g->pos_y -= 1;
  else if (g->pos_y == 9 && g->pos_x < 8) g->pos_x += 1;
  else if (g->pos_x == 8 && g->pos_y < 16) g->pos_y += 1;
}

/**
@brief déplacement du serpent 3
@param g est un pointeur sur guardian

guard_3 gère le déplacement du premier serpent, pour qu'il réalise de façon autonome ( sans intervention du joueur ) son trajet.

@return none
*/

void            guard_3(t_guardian *g)
{
  if (g->pos_y == 16 && g->pos_x > 9) g->pos_x -= 1;
  else if (g->pos_x == 9 && g->pos_y > 9) g->pos_y -= 1;
  else if (g->pos_y == 9 && g->pos_x < 16) g->pos_x += 1;
  else if (g->pos_x == 16 && g->pos_y < 16) g->pos_y += 1;
}

/**
@brief fait avancer chaque serpent
@param snake est un pointeur sur t_snake

calc_guardian_pos gère les positions des serpents en fonction de leur numéro en appelant les fonctions de déplacement guard_i pour i allant de 0 à 3.

@return none
*/

void            calc_guardian_pos(t_snake *snake)
{
  int           i = -1;
  t_guardian    *n;

  while (++i < 4)
    {
      n = &(snake->guardian[i]);
      while (n->next)
        {
          if (0 == i) guard_0(n);
          else if (1 == i) guard_1(n);
          else if (2 == i) guard_2(n);
          else if (3 == i) guard_3(n);
          n = n->next;
        }
    }
}
