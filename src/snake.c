#include "snake.h"
#include <assert.h>

/**
@brief regarde si tous les tresors ont été récupérés
@param snake est un pointeur sur t_Snake

snake_Check_If_Win renvoi 1 si tous les tresors ont été récupéré, 0 sinon

@return bool
*/

int     snake_Check_If_Win(t_Snake *snake)
{
    assert (snake != NULL); // le jeu ne peut pas être nul
    int i;
    for(i = 0; i < 16; ++i)
    {
        if (snake->loot[i].taked == 0 && snake->loot[i].type == ORBE)
            return 0;
    }

    return 1;
}

/**
@brief passe au niveau suivant
@param snake est un pointeur sur t_Snake

snake_Cheat_Win prend tous les trésors à la place du joueur afin de passer au niveau suivant (pour une démo par exemple)

@return none
*/

void	snake_Cheat_Win(t_Snake *snake)
{
  int	i;
  assert (snake != NULL); // le jeu ne peut pas être nul

  printf("life: %d\n", snake->life);
  if (snake->guardian_size <= 8)
    {
      if (snake->life > 1) snake->life -= 1;
      for(i = 0; i < 16; ++i)
      {
          if (snake->loot[i].taked == 0 && snake->loot[i].type == ORBE)
	    {
	       snake->loot[i].taked = 1;
	       snake->player_pos_x = X_DEFAULT;
	       snake->player_pos_y = Y_DEFAULT;
	    }
      }
    }
}


/**
@brief déplace le personnage
@param snake est un pointeur sur t_Snake
@param motion est un entier

snake_Move_Player déplace le personnage selon la touche saisit par l'utilisateur sans qu'il puisse rentrer dans les murs

@return none
*/

void	snake_Move_Player(t_Snake *snake,const int motion)
{
  assert (snake != NULL); // le jeu ne peut pas être nul

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

/**
@brief vérifie s'il y a collision entre le joueur et les serpents.
@param snake est un pointeur sur t_Snake

snake_Check_Guardian_Collision vérifie la position du joueur par rapport à la position des serpents, et si elles sont semblables, la vie du personnage diminue de 1.

@return 1
*/

int		snake_Check_Guardian_Collision(t_Snake *snake)
{
  assert (snake != NULL); // le jeu ne peut pas être nul
  t_Guardian	*n;
  int		i = -1;

  while (++i < 4)
    {
      n = &(snake->guardian[i]);
      while (n->next)
	{
	  if (n->pos_x == snake->player_pos_x && n->pos_y == snake->player_pos_y)
	    {
	      snake->life -= 1;
	      snake->player_pos_x = X_DEFAULT;
	      snake->player_pos_y = Y_DEFAULT;
	      return 1;
	    }
	  n = n->next;
	}
    }
    return 0;
}

/**
@brief initialise les serpents.
@param snake est un pointeur sur t_Snake
@param i entier qui prend comme valeur 0, 1, 2, 3 qui correspond au différent

snake_Init_Guardian initialise les 4 serpents au milieu du terrain.

@return 1
*/

int		snake_Init_Guardian(t_Snake *snake, const int i)
{
  assert (snake != NULL && i>=0 && i<4); // le jeu ne peut pas être nul

  t_Guardian	*n;
  int		j = -1;
  unsigned int          init_snake[4][8][2];

  if (snake->guardian_size > 8) return 1;
  /*snake 0*/
  init_snake[0][0][0] = 7; // init snake[num snake][num part snake][pos_x] = coord x
  init_snake[0][0][1] = 8; // init_snake[num snake][num part snake][pos_y] = coord y
  init_snake[0][1][0] = 6;
  init_snake[0][1][1] = 8;
  init_snake[0][2][0] = 5;
  init_snake[0][2][1] = 8;
  init_snake[0][3][0] = 4;
  init_snake[0][3][1] = 8;
  init_snake[0][4][0] = 3;
  init_snake[0][4][1] = 8;
  init_snake[0][5][0] = 2;
  init_snake[0][5][1] = 8;
  init_snake[0][6][0] = 1;
  init_snake[0][6][1] = 8;
  init_snake[0][7][0] = 1;
  init_snake[0][7][1] = 7;

  /*snake 1*/
  init_snake[1][0][0] = 9;
  init_snake[1][0][1] = 8;
  init_snake[1][1][0] = 9;
  init_snake[1][1][1] = 7;
  init_snake[1][2][0] = 9;
  init_snake[1][2][1] = 6;
  init_snake[1][3][0] = 9;
  init_snake[1][3][1] = 5;
  init_snake[1][4][0] = 9;
  init_snake[1][4][1] = 4;
  init_snake[1][5][0] = 9;
  init_snake[1][5][1] = 3;
  init_snake[1][6][0] = 9;
  init_snake[1][6][1] = 2;
  init_snake[1][7][0] = 9;
  init_snake[1][7][1] = 1;

  /*snake 2*/
  init_snake[2][0][0] = 8;
  init_snake[2][0][1] = 9;
  init_snake[2][1][0] = 8;
  init_snake[2][1][1] = 10;
  init_snake[2][2][0] = 8;
  init_snake[2][2][1] = 11;
  init_snake[2][3][0] = 8;
  init_snake[2][3][1] = 12;
  init_snake[2][4][0] = 8;
  init_snake[2][4][1] = 13;
  init_snake[2][5][0] = 8;
  init_snake[2][5][1] = 14;
  init_snake[2][6][0] = 8;
  init_snake[2][6][1] = 15;
  init_snake[2][7][0] = 8;
  init_snake[2][7][1] = 16;

  /*snake 3*/
  init_snake[3][0][0] = 9;
  init_snake[3][0][1] = 9;
  init_snake[3][1][0] = 10;
  init_snake[3][1][1] = 9;
  init_snake[3][2][0] = 11;
  init_snake[3][2][1] = 9;
  init_snake[3][3][0] = 12;
  init_snake[3][3][1] = 9;
  init_snake[3][4][0] = 13;
  init_snake[3][4][1] = 9;
  init_snake[3][5][0] = 14;
  init_snake[3][5][1] = 9;
  init_snake[3][6][0] = 15;
  init_snake[3][6][1] = 9;
  init_snake[3][7][0] = 16;
  init_snake[3][7][1] = 9;

  n = &(snake->guardian[i]);
  while (++j < snake->guardian_size)
    {
      if (!(n->next = malloc(sizeof(t_Guardian)))) return 1;
      n->pos_x = init_snake[i][j][0];
      n->pos_y = init_snake[i][j][1];
      n = n->next;
    }
  n->next = NULL;
  return 0;
}

/**
@brief place les trésors et les vies
@param snake est un pointeur sur t_Snake

snake_Generate_Loot place les trésors et les vies dans les salles

@return none
*/

void	snake_Generate_Loot(t_Snake *snake)
{
  assert (snake != NULL); // le jeu ne peut pas être nul
  /*ORBE ou LIFE*/
  int	i = -1;
  int	tabx[16] = {4, 6, 4, 2, 12, 14, 12, 10,  4,  6,  4,  2, 12, 14, 12, 10};
  int	taby[16] = {2, 4, 6, 4,  2,  4,  6,  4, 10, 12, 14, 12, 10, 12, 14, 12};

  while (++i < 16)
    {
      snake->loot[i].pos_x = tabx[i];
      snake->loot[i].pos_y = taby[i];
      snake->loot[i].type = (tabx[i] == 6 ? 1 : 0); // si tabx[i]=6 alors type=LIFE
      snake->loot[i].taked = 0;
    }
}

/**
@brief ajoute une vie au joueur
@param snake est un pointeur sur t_Snake

snake_Check_Life incrémente la vie du joueur de 1 si sa psition concorde avec celle d'une vie.
@return none
*/

int	snake_Check_Life(t_Snake *snake)
{
  assert (snake != NULL); // le jeu ne peut pas être nul
  int	i = -1;

  if (snake->life <= 0) return 1;
  while (++i < 16)
    {
      if (snake->loot[i].pos_x == snake->player_pos_x &&
	  snake->loot[i].pos_y == snake->player_pos_y &&
	  snake->loot[i].type == LIFE &&
	  snake->loot[i].taked == 0)
	{
	  printf("Yeah, one more life found\n");
	  snake->life += 1;
	}
    }
  return 0;
}

/**
@brief fait avancer chaque serpent
@param snake est un pointeur sur t_Snake

snake_Calc_Guardian_Pos gère les positions des serpents en fonction de leur numéro en appelant les fonctions de déplacement guard_i pour i allant de 0 à 3.

@return none
*/

void            snake_Calc_Guardian_Pos(t_Snake *snake)
{
  assert (snake != NULL); // le jeu ne peut pas être nul

  int           i = -1;
  t_Guardian    *n;

  while (++i < 4)
    {
      n = &(snake->guardian[i]);
      while (n->next)
        {
          if (0 == i) guard_0(n);
          else if (1 == i) guard_1(n);
          else if (2 == i) guard_2(n);
          else if (3 == i) guard_3(n);
          n = n->next;
        }
    }
}

/**
@brief initialisation de la position du joueur, du nombre de vie, de la vitesse et la taille du serpent et du chrono
@param snake est un pointeur sur t_Snake

snake_Init_Values initialise la position du joueur, le nombre de vie, la vitesse et la taille du serpent et le chrono

@return 0
*/

int	snake_Init_Values(t_Snake *snake)
{
  int	i;
  assert (snake != NULL); // le jeu ne peut pas être nul

  snake->player_pos_x = X_DEFAULT;
  snake->player_pos_y = Y_DEFAULT;
  snake->life = 1;
  snake->clock_speed = 0.2;
  snake->clock = 30; /*initialise le début de la clock en seconde*/
  snake_Generate_Loot(snake);
  /*initialise la taille des gardiens*/
  snake->guardian_size = 1; /*guardian_size doit être compris entre 0 et 8*/
  /*initialise les parties de tous les guardiens*/
  for (i = 0; i < 4; ++i)
    {
      if (snake_Init_Guardian(snake, i)) {printf("[error] Error creating guardian;\n"); return 1;}
    }
  return 0;
}
