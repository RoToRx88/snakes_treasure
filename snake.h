#ifndef _SNAKE_H_
# define _SNAKE_H_

# include <stdio.h>
# include <stdlib.h>
# include "SDL/SDL.h"

/*enum of SDL's surfaces*/
enum {
  SCREEN,
  WALL,
  PACMAN,
  SNAKE,
  BACKGROUND,
  BLUE_ORBE,
  HEART
};

/*enum for move_player function*/
enum {
  GO_UP,
  GO_DOWN,
  GO_LEFT,
  GO_RIGHT
};

/*enum for loot type*/
enum {
  ORBE,
  LIFE
};

typedef struct		s_loot
{
  unsigned int		pos_x;
  unsigned int		pos_y;
  unsigned int		type; /*ORBE or LIFE*/
  unsigned int		taked; /*0 = no, 1 = yes*/		
}			t_loot;

typedef struct		s_snake
{
  SDL_Surface		*surfaces[7];
  unsigned int		player_pos_x;
  unsigned int		player_pos_y;
  char			map[18][18];
  t_loot		loot[16];
}			t_snake;

int			init_sdl(t_snake *snake);
int			draw_map(t_snake *snake);
int			check_if_win(t_snake *snake);
void			main_loop(t_snake *snake);
void			move_player(t_snake *snake, int motion);
void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);
void			generate_loot(t_snake *snake);
SDL_Surface		*load_image(char *filename);

#endif /*_SNAKE_H_*/
