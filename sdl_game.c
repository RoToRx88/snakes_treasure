#include "snake.h"

SDL_Surface     *load_image(char *filename)
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;

  loadedImage = SDL_LoadBMP(filename);
  if(loadedImage != NULL)
    {
      optimizedImage = SDL_DisplayFormat( loadedImage );
      SDL_FreeSurface( loadedImage );
    }
  return optimizedImage;
}


void            apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
  SDL_Rect      offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface( source, NULL, destination, &offset );
}

void	display_loot(t_snake *snake)
{
  int	i = -1;

  while (++i < 16)
    {
      if (snake->player_pos_x == snake->loot[i].pos_x && snake->player_pos_y == snake->loot[i].pos_y)
	snake->loot[i].taked = 1;
      if (snake->loot[i].type == ORBE && snake->loot[i].taked == 0)
	apply_surface(snake->loot[i].pos_x * 32, snake->loot[i].pos_y * 32,  snake->surfaces[BLUE_ORBE], snake->surfaces[SCREEN]);
      else if (snake->loot[i].type == LIFE && snake->loot[i].taked == 0)
	apply_surface(snake->loot[i].pos_x * 32, snake->loot[i].pos_y * 32, snake->surfaces[HEART], snake->surfaces[SCREEN]);
    }
}

int     draw_map(t_snake *snake)
{
  int   i = -1;
  int   j = -1;

  /*background first to avoid multiple image*/
  apply_surface(0, 0, snake->surfaces[BACKGROUND], snake->surfaces[SCREEN]);
  while (++i < 18)
    {
      j = -1;
      while (++j < 18)
        {
	  /*check to display a wall*/
          if (snake->map[j][i] == '#') apply_surface(i * 32, j * 32, snake->surfaces[WALL], snake->surfaces[SCREEN]);
	}
    }
  /*display all loots on the map*/
  display_loot(snake);
  /*display player on his pos*/
  apply_surface(snake->player_pos_x * 32, snake->player_pos_y * 32, snake->surfaces[PACMAN], snake->surfaces[SCREEN]);
  if(SDL_Flip(snake->surfaces[SCREEN]) == -1) return 1;
}
