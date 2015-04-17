#include "snake.h"

void	move_player(t_snake *snake, int motion)
{
  if (motion == GO_UP && snake->map[snake->player_pos_y - 1][snake->player_pos_x] == '.')
    {
      printf("up\n");
      snake->player_pos_y -= 1;
    }
  else if (motion == GO_DOWN && snake->map[snake->player_pos_y + 1][snake->player_pos_x] == '.')
    {
      printf("down\n");
      snake->player_pos_y += 1;
    }
  else if (motion == GO_LEFT && snake->map[snake->player_pos_y][snake->player_pos_x - 1] == '.')
    {
      printf("left\n");
      snake->player_pos_x -= 1;
   }
  else if (motion == GO_RIGHT && snake->map[snake->player_pos_y][snake->player_pos_x + 1] == '.')
    {
      printf("right\n");
      snake->player_pos_x += 1;
    }
  draw_map(snake);
}
