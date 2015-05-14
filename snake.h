#ifndef _SNAKE_H_
# define _SNAKE_H_

# include <stdio.h>
# include <stdlib.h>
# include "SDL/SDL.h"
# define X_DEFAULT 6
# define Y_DEFAULT 5

/*enum of SDL's surfaces*/
enum {
  SCREEN,
  WALL,
  PACMAN,
  SNAKE,
  BACKGROUND,
  BLUE_ORBE,
  HEART,
  LEVELUP
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

typedef struct		s_guardian
{
  unsigned int		pos_x;
  unsigned int		pos_y;
  struct s_guardian	*next;
}			t_guardian;

typedef struct		s_snake
{
  SDL_Surface		*surfaces[8];
  unsigned int		player_pos_x;
  unsigned int		player_pos_y;
  char			map[18][18];
  t_loot		loot[16];
  size_t		life;
  int			score;
  t_guardian		guardian[4];
  size_t		guardian_size;
  float			clock_speed;
}			t_snake;

/**
@brief initialisation du jeu
@param snake est un pointeur de structure t_snake

init_sdl initialise le jeu avec les images

@return 0
*/

int			init_sdl(t_snake *snake);


/**
@brief place les murs, le perso et les serpents sur le terrain
@param snake est un pointeur de structure t_snake

draw_map transforme les # par des murs et affiche le personnage et les serpents

@return 1
*/

int			draw_map(t_snake *snake);


/**
@brief regarde si tous les tresors été récupérés
@param snake est un pointeur de structure t_snake

check_if_win renvoi 1 si tous les tresors ont été récupéré, 0 sinon

@return bool
*/

int			check_if_win(t_snake *snake);

/**
@brief boucle du jeu
@param snake est un pointeur de structure t_snake

main_loop est la boucle du jeu qui permet le deplacement du perso et la fin du niveau

@return erreurs ou fin de jeu si mort
*/

int			main_loop(t_snake *snake);

/**
@brief déplace le personnage
@param snake est un pointeur de structure t_snake

move_player déplace le personnage selon la touche saisit par l'utilisateur sans qu'il puisse rentrer dans les murs

@return none
*/

void			move_player(t_snake *snake, int motion);

/**
@brief
@param x entier >0
@param y entier >0
@param source
@param destination

apply_surface

@return none
*/
void			apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);


/**
@brief place les trésors et les vies
@param snake est un pointeur de structure t_snake

generate_loot place les trésors et les vies dans les salles

@return none
*/

void			generate_loot(t_snake *snake);
SDL_Surface		*load_image(char *filename);
int			init_guardian(t_snake *snake, int i);
int			check_life(t_snake *snake);
void			display_guardian(t_snake *snake);
void			calc_guardian_pos(t_snake *snake);
void			guard_0(t_guardian *g);
void			guard_1(t_guardian *g);
void			guard_2(t_guardian *g);
void			guard_3(t_guardian *g);
#endif /*_SNAKE_H_*/
