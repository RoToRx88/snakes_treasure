#include "snake.h"

/**
@brief déplace le personnage
@param snake est un pointeur de structure t_snake

move_player déplace le personnage selon la touche saisit par l'utilisateur sans qu'il puisse rentrer dans les murs

@return none
*/

void	move_player(t_snake *snake, int motion)
{
  if (motion == GO_UP && snake->map[snake->player_pos_y - 1][snake->player_pos_x] != '#')
    {
      snake->player_pos_y -= 1;
    }
  else if (motion == GO_DOWN && snake->map[snake->player_pos_y + 1][snake->player_pos_x] != '#')
    {
      snake->player_pos_y += 1;
    }
  else if (motion == GO_LEFT && snake->map[snake->player_pos_y][snake->player_pos_x - 1] != '#')
    {
      snake->player_pos_x -= 1;
    }
  else if (motion == GO_RIGHT && snake->map[snake->player_pos_y][snake->player_pos_x + 1] != '#')
    {
      snake->player_pos_x += 1;
    }
}
