#include "snake.h"

int	check_life(t_snake *snake)
{
  int	i = -1;

  if (snake->life <= 0) return 1;
  while (++i < 16)
    {
      if (snake->loot[i].pos_x == snake->player_pos_x &&
	  snake->loot[i].pos_y == snake->player_pos_y &&
	  snake->loot[i].type == LIFE &&
	  snake->loot[i].taked == 0)
	{
	  printf("Yeah, one more life found\n");
	  snake->life += 1;
	}
    }
  return 0;
}
