#include "snake.h"

void	move_player(t_snake *snake, int motion)
{
  if (motion == GO_UP && snake->map[snake->player_pos_y - 1][snake->player_pos_x] == '.')
    {
      snake->player_pos_y -= 1;
      printf("up: %d;%d\n", snake->player_pos_x, snake->player_pos_y);
    }
  else if (motion == GO_DOWN && snake->map[snake->player_pos_y + 1][snake->player_pos_x] == '.')
    {
      snake->player_pos_y += 1;
      printf("down: %d;%d\n", snake->player_pos_x, snake->player_pos_y);
    }
  else if (motion == GO_LEFT && snake->map[snake->player_pos_y][snake->player_pos_x - 1] == '.')
    {
      snake->player_pos_x -= 1;
      printf("left: %d;%d\n", snake->player_pos_x, snake->player_pos_y);
   }
  else if (motion == GO_RIGHT && snake->map[snake->player_pos_y][snake->player_pos_x + 1] == '.')
    {
      snake->player_pos_x += 1;
      printf("right: %d;%d\n", snake->player_pos_x, snake->player_pos_y);
    }
}
