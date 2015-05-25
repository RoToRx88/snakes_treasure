#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "loot.h"
#include "guardian.h"


#define X_DEFAULT 6
#define Y_DEFAULT 5

/*enum pour les surfaces SDL*/
enum {
  SCREEN,
  WALL,
  PLAYER,
  SNAKE,
  BACKGROUND,
  BLUE_ORBE,
  HEART,
  LEVELUP,
  WIN,
  LOSE,
  TIMEOUT,
  MENU,
  LOGO
};

/*enum pour le déplacement du personnage*/
enum {
  GO_UP,
  GO_DOWN,
  GO_LEFT,
  GO_RIGHT
};

/*enum pour le type du butin*/
enum {
  ORBE,
  LIFE
};



typedef struct		s_Snake
{
  SDL_Surface		*surfaces[13];
  unsigned int		player_pos_x;
  unsigned int		player_pos_y;
  char			map[18][18];
  t_Loot		loot[16];
  size_t		life;
  t_Guardian		guardian[4];
  size_t		guardian_size;
  float			clock_speed;
  size_t		clock;
}			t_Snake;

/**
@brief regarde si tous les tresors ont été récupéré
@param snake est un pointeur sur t_Snake

snake_Check_If_Win renvoi 1 si tous les tresors ont été récupéré, 0 sinon

@return bool
*/

int         snake_Check_If_Win(t_Snake *snake);

/**
@brief passe au niveau suivant
@param snake est un pointeur sur t_Snake

snake_Cheat_Win passe au niveau suivant même s'il n'a pas été finis. En prenant tous les trésors à la place du joueur.

@return void
*/

void        snake_Cheat_Win(t_Snake *snake);

/**
@brief déplace le personnage
@param snake est un pointeur sur t_Snake
@param motion est un entier

snake_Move_Player déplace le personnage selon la touche saisit par l'utilisateur sans qu'il puisse rentrer dans les murs

@return none
*/

void        snake_Move_Player(t_Snake *snake, int motion);

/**
@brief initialise les serpents.
@param snake est un pointeur de structure t_Snake
@param i entier qui prend comme valeur 0, 1, 2, 3 qui correspond au différent

snake_Init_Guardian initialise les 4 serpents au milieu du terrain.

@return 1
*/
int			snake_Init_Guardian(t_Snake *snake, int i);

/**
@brief vérifie s'il y a collision entre le joueur et les serpents.
@param snake est un pointeur de structure t_Snake

snake_Check_Guardian_Collision vérifie la position du joueur par rapport à la position des serpents, et si elles sont semblables, la vie du personnage diminue de 1.

@return 1
*/
int	    snake_Check_Guardian_Collision(t_Snake *snake);

/**
@brief fait avancer chaque serpent
@param snake est un pointeur sur t_Snake

snake_Calc_Guardian_Pos gère les positions des serpents en fonction de leur numéro en appelant les fonctions de déplacement guard_i pour i allant de 0 à 3.

@return none
*/

void    snake_Calc_Guardian_Pos(t_Snake *snake);

/**
@brief place les trésors et les vies
@param snake est un pointeur de structure struct t_Snake

snake_Generate_Loot place les trésors et les vies dans les salles

@return none
*/

void	snake_Generate_Loot(t_Snake *snake);

/**
@brief ajoute une vie au player
@param snake est un pointeur sur struct t_Snake

snake_Check_Life ajoute incrémente la vie du player de 1 si sa position concorde avec celle de la life.
@return none
*/

int    snake_Check_Life(t_Snake *snake);

/**
@brief initialisation de la position du joueur, du nombre de vie, de la vitesse et la taille du serpent et du chrono
@param snake est un pointeur sur t_Snake

snake_Init_Values initialise la position du joueur, le nombre de vie, la vitesse et la taille du serpent et le chrono

@return 0
*/

int    snake_Init_Values(t_Snake *snake);

#endif //_SNAKE_H_
