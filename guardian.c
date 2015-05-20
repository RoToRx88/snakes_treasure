#include "snake.h"


/**
@brief affiche chaque partie des 4 serpents.
@param snake est un pointeur de structure t_snake

display_guardian affiche partie par partie (en fonction de la taille du serpent

@return none
*/

void		display_guardian(t_snake *snake)
{
  int		i = -1;
  t_guardian	*n;

  while (++i < 4)
    {
      n = &(snake->guardian[i]);
      while (n->next)
	{
	  apply_surface(n->pos_x * 32, n->pos_y * 32, snake->surfaces[SNAKE], snake->surfaces[SCREEN]);
	  n = n->next;
	}
    }
}

/**
@brief vérifie s'il y a collision entre le joueur et les serpents.
@param snake est un pointeur de structure t_snake

check_guardian_collision vérifie la position du joueur par rapport à la position des serpents, et si elles sont semblables, la vie du personnage diminue de 1.

@return 1
*/

int		check_guardian_collision(t_snake *snake)
{
  t_guardian	*n;
  int		i = -1;

  while (++i < 4)
    {
      n = &(snake->guardian[i]);
      while (n->next)
	{
	  if (n->pos_x == snake->player_pos_x && n->pos_y == snake->player_pos_y)
	    {
	      snake->life -= 1;
	      snake->player_pos_x = X_DEFAULT;
	      snake->player_pos_y = Y_DEFAULT;
	      return 1;
	    }
	  n = n->next;
	}
    }
    return 0;
}

/**
@brief initialise les serpents.
@param snake est un pointeur de structure t_snake
@param i entier qui prend comme valeur 0, 1, 2, 3 qui correspond au différent

init_guardian initialise les 4 serpents au milieu du terrain.

@return 1
*/

int		init_guardian(t_snake *snake, int i)
{
  t_guardian	*n;
  int		j = -1;
  unsigned int          init_snake[4][8][2];

  if (snake->guardian_size > 8) return 1;
  /*snake 0*/
  init_snake[0][0][0] = 7; // init_snake[num snake][num part snake][pos_x] = coord x
  init_snake[0][0][1] = 8; // init_snake[num snake][num part snake][pos_y] = coord y
  init_snake[0][1][0] = 6;
  init_snake[0][1][1] = 8;
  init_snake[0][2][0] = 5;
  init_snake[0][2][1] = 8;
  init_snake[0][3][0] = 4;
  init_snake[0][3][1] = 8;
  init_snake[0][4][0] = 3;
  init_snake[0][4][1] = 8;
  init_snake[0][5][0] = 2;
  init_snake[0][5][1] = 8;
  init_snake[0][6][0] = 1;
  init_snake[0][6][1] = 8;
  init_snake[0][7][0] = 1;
  init_snake[0][7][1] = 7;

  /*snake 1*/
  init_snake[1][0][0] = 9;
  init_snake[1][0][1] = 8;
  init_snake[1][1][0] = 9;
  init_snake[1][1][1] = 7;
  init_snake[1][2][0] = 9;
  init_snake[1][2][1] = 6;
  init_snake[1][3][0] = 9;
  init_snake[1][3][1] = 5;
  init_snake[1][4][0] = 9;
  init_snake[1][4][1] = 4;
  init_snake[1][5][0] = 9;
  init_snake[1][5][1] = 3;
  init_snake[1][6][0] = 9;
  init_snake[1][6][1] = 2;
  init_snake[1][7][0] = 9;
  init_snake[1][7][1] = 1;

  /*snake 2*/
  init_snake[2][0][0] = 8;
  init_snake[2][0][1] = 9;
  init_snake[2][1][0] = 8;
  init_snake[2][1][1] = 10;
  init_snake[2][2][0] = 8;
  init_snake[2][2][1] = 11;
  init_snake[2][3][0] = 8;
  init_snake[2][3][1] = 12;
  init_snake[2][4][0] = 8;
  init_snake[2][4][1] = 13;
  init_snake[2][5][0] = 8;
  init_snake[2][5][1] = 14;
  init_snake[2][6][0] = 8;
  init_snake[2][6][1] = 15;
  init_snake[2][7][0] = 8;
  init_snake[2][7][1] = 16;

  /*snake 3*/
  init_snake[3][0][0] = 9;
  init_snake[3][0][1] = 9;
  init_snake[3][1][0] = 10;
  init_snake[3][1][1] = 9;
  init_snake[3][2][0] = 11;
  init_snake[3][2][1] = 9;
  init_snake[3][3][0] = 12;
  init_snake[3][3][1] = 9;
  init_snake[3][4][0] = 13;
  init_snake[3][4][1] = 9;
  init_snake[3][5][0] = 14;
  init_snake[3][5][1] = 9;
  init_snake[3][6][0] = 15;
  init_snake[3][6][1] = 9;
  init_snake[3][7][0] = 16;
  init_snake[3][7][1] = 9;

  n = &(snake->guardian[i]);
  while (++j < snake->guardian_size)
    {
      if (!(n->next = malloc(sizeof(t_guardian)))) return 1;
      n->pos_x = init_snake[i][j][0];
      n->pos_y = init_snake[i][j][1];
      n = n->next;
    }
  n->next = NULL;
  return 0;
}
