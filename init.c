#include "snake.h"

int     init_sdl(t_snake *snake)
{
  if (-1 == SDL_Init(SDL_INIT_EVERYTHING) ||
      !(snake->surfaces[SCREEN] = SDL_SetVideoMode(576, 576, 16, SDL_HWSURFACE)))
    {
      printf("Unable to launch SDL; error: %s\n", SDL_GetError());
      return 1;
    }
  SDL_WM_SetCaption("Snake's treasure", NULL);
  if (!(snake->surfaces[WALL] = load_image("img/wall.bmp"))) return 1;
  if (!(snake->surfaces[PACMAN] = load_image("img/pacman.bmp"))) return 1;
  if (!(snake->surfaces[SNAKE] = load_image("img/snake.bmp"))) return 1;
  if (!(snake->surfaces[BACKGROUND] = load_image("img/background.bmp"))) return 1;
  snake->player_pos_x = 1;
  snake->player_pos_y = 1;
  return 0;
}
