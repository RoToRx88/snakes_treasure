#ifndef _SNAKE_H_
# define _SNAKE_H_

# include <stdio.h>
# include <stdlib.h>
# include "SDL/SDL.h"

enum {
  SCREEN,
  WALL,
  PACMAN,
  SNAKE,
  BACKGROUND
};

enum {
  GO_UP,
  GO_DOWN,
  GO_LEFT,
  GO_RIGHT
};

typedef struct s_snake
{
  SDL_Surface	*surfaces[5];
  int		player_pos_x;
  int		player_pos_y;
  char		map[18][18];
}		t_snake;

int		init_sdl(t_snake *snake);
int		draw_map(t_snake *snake);
void		main_loop(t_snake *snake);
void		move_player(t_snake *snake, int motion);
void		apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);
SDL_Surface	*load_image(char *filename);

#endif /*_SNAKE_H_*/
