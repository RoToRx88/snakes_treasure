#include "snake.h"

void	generate_loot(t_snake *snake)
{
  /*ORBE or LIFE*/
  int	i = -1;
  int	tabx[16] = {4, 6, 4, 2, 12, 14, 12, 10,  4,  6,  4,  2, 12, 14, 12, 10};
  int	taby[16] = {2, 4, 6, 4,  2,  4,  6,  4, 10, 12, 14, 12, 10, 12, 14, 12};
  while (++i < 16)
    {
      snake->loot[i].pos_x = tabx[i];
      snake->loot[i].pos_y = taby[i];
      snake->loot[i].type = i % 2;
      snake->loot[i].taked = 0;
    }
}
