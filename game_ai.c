#include "snake.h"

int	check_if_win(t_snake *snake)
{
  int	i = -1;

  while (++i < 16)
    {
      if (snake->loot[i].taked == 0 && snake->loot[i].type == ORBE) return 0;
    }
  return 1;
}
