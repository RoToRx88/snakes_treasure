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

int     draw_map(t_snake *snake)
{
  int   i = -1;
  int   j = -1;

  apply_surface(0, 0, snake->surfaces[BACKGROUND], snake->surfaces[SCREEN]);
  while (++i < 18)
    {
      j = -1;
      while (++j < 18)
        {
          if (snake->map[j][i] == '#') apply_surface(i * 32, j * 32, snake->surfaces[WALL], snake->surfaces[SCREEN]);
        }
    }
  apply_surface(snake->player_pos_x * 32, snake->player_pos_y * 32, snake->surfaces[PACMAN], snake->surfaces[SCREEN]);
  if(SDL_Flip(snake->surfaces[SCREEN]) == -1) return 1;
}
