#include "snake.h"

/**
@brief regarde si tous les tresors été récupérés
@param snake est un pointeur de structure t_snake

check_if_win renvoi 1 si tous les tresors ont été récupéré, 0 sinon

@return bool
*/

int	check_if_win(t_snake *snake)
{
  int	i = -1;

  while (++i < 16)
    {
      if (snake->loot[i].taked == 0 && snake->loot[i].type == ORBE) return 0;
    }
  return 1;
}

void	cheat_win(t_snake *snake)
{
  int	i = -1;

  printf("life: %d\n", snake->life);
  if (snake->guardian_size < 8)
    {
      if (snake->life > 1) snake->life -= 1;
      while (++i < 16)
	{
	  if (snake->loot[i].taked == 0 && snake->loot[i].type == ORBE)
	    {
	       snake->loot[i].taked = 1;
	       snake->player_pos_x = X_DEFAULT;
	       snake->player_pos_y = Y_DEFAULT;	       
	    }
	}
    }
}
