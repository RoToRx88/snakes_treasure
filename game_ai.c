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
