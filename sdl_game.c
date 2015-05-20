#include "snake.h"

/**
@brief permet de charger des image .bmp
@param filename chaine de caractère (nom de fichier")


SDL_Surface charge une image .bmp

@return none
*/

SDL_Surface *load_image(char *filename)
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

/**
@brief
@param x entier >0
@param y entier >0
@param source
@param destination

apply_surface applique une surface sur la fenêtre ????

@return none
*/

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
  SDL_Rect      offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface( source, NULL, destination, &offset );
}


/**
@brief affiche les butins non pris
@param snake est un pointeur de structure t_snake

display_loot affiche les butins et les coeurs non pris, si le personnage est sur une "case butin", alors le butin est pris et donc ne s'affiche plus.

@return none
*/
void display_loot(t_snake *snake)
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

/**
@brief place les murs, le perso et les serpents sur le terrain
@param snake est un pointeur de structure t_snake

draw_map transforme les # par des murs et affiche le personnage et les serpents

@return 1
*/

int draw_map(t_snake *snake)
{
  int   i = -1;
  int   j = -1;

  /*background first to avoid multiple image*/
  apply_surface(0, 0, snake->surfaces[BACKGROUND], snake->surfaces[SCREEN]);
  /*if 1 returned player have no more life, else he have at least 1 life*/
  if (check_life(snake) == 1) return 1;
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
  display_guardian(snake);
  /*display player on his pos*/
  apply_surface(snake->player_pos_x * 32, snake->player_pos_y * 32, snake->surfaces[PACMAN], snake->surfaces[SCREEN]);
  if(SDL_Flip(snake->surfaces[SCREEN]) == -1) return 1;
  return 0;
}

/**
@brief affichage du menu
@param snake est un pointeur de structure t_snake

init_sdl affiche le menu. Il y a un une case "play". La surface du fond BACKROUND0 sera appliqué à la fenetre avec par dessus la surface de la case "play".

@return 0
*/

int    menu(t_snake *snake)
{
  SDL_Event     event;

  apply_surface(0, 0, snake->surfaces[MENU], snake->surfaces[SCREEN]);
  SDL_Flip(snake->surfaces[SCREEN]);
  while (SDL_WaitEvent(&event))
    {
      printf("get event\n");
      switch(event.type)
        {
        case SDL_QUIT:
          return 1;
          break;
        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_p) return 0;
          else if (event.key.keysym.sym == SDLK_q) return 1;
          break;
        default:;
        }
    }
  return 0;
}


/**
@brief initialisation du jeu
@param snake est un pointeur de structure t_snake

init_sdl initialise le jeu avec les images

@return 0
*/

int     init_sdl(t_snake *snake)
{
  printf("Initializing SDL.\n");
  if (-1 == SDL_Init(SDL_INIT_VIDEO) ||
      !(snake->surfaces[SCREEN] = SDL_SetVideoMode(576, 576, 16, SDL_HWSURFACE)))
    {
      printf("Unable to launch SDL; error: %s\n", SDL_GetError());
      return 1;
    }
  SDL_WM_SetCaption("Snake's treasure", NULL);
  if (!(snake->surfaces[WALL] = load_image("img/wall.bmp")))
  {
      printf("L'image du mur non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  if (!(snake->surfaces[PACMAN] = load_image("img/pacman.bmp")))
  {
      printf("L'image du personnage non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  // SDL_SetColorKey(snake->surfaces[PACMAN], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[PACMAN]->format,255,255,255)) ;
  if (!(snake->surfaces[SNAKE] = load_image("img/snake.bmp")))
    {
      printf("L'image du snake non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  if (!(snake->surfaces[BACKGROUND] = load_image("img/background.bmp")))
  {
      printf("L'image du FOND (parce Maelle fait chier) non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  if (!(snake->surfaces[BLUE_ORBE] = load_image("img/blue_orbe.bmp")))
  {
      printf("L'image du tresor (Blue_orbe) non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  SDL_SetColorKey(snake->surfaces[BLUE_ORBE], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[BLUE_ORBE]->format,255,255,255));
  if (!(snake->surfaces[HEART] = load_image("img/heart.bmp")))
  {
      printf("L'image du coeur non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  SDL_SetColorKey(snake->surfaces[HEART], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[HEART]->format,255,255,255)) ;

  /*level up*/
  if (!(snake->surfaces[LEVELUP] = load_image("img/levelup.bmp")))
  {
      printf("L'image du level up non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*win*/
  if (!(snake->surfaces[WIN] = load_image("img/win.bmp")))
  {
      printf("L'image du win non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*lose*/
  if (!(snake->surfaces[LOSE] = load_image("img/lose.bmp")))
  {
      printf("L'image du lose non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*time out*/
  if (!(snake->surfaces[TIMEOUT] = load_image("img/timeout.bmp")))
  {
      printf("L'image du timeout non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*menu*/
  if (!(snake->surfaces[MENU] = load_image("img/menu.bmp")))
  {
      printf("L'image du menu non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*logo*/
  if (!(snake->surfaces[LOGO] = load_image("img/logo.bmp")))
  {
      printf("L'image du logo non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  if (init_values(snake)) return 1;
  return 0;
}

int	init_values(t_snake *snake)
{
  int	i;

  snake->player_pos_x = X_DEFAULT;
  snake->player_pos_y = Y_DEFAULT;
  snake->life = 1;
  snake->clock_speed = 0.2;
  snake->clock = 30; /*set startup clock in seconds*/
  generate_loot(snake);
  /*Set size of a guardian*/
  snake->guardian_size = 1; /*WARNING need to be between 0 and 8*/
  /*init chained list for all guardians*/
  for (i = 0; i < 4; ++i)
    {
      if (init_guardian(snake, i)) {printf("[error] Error creating guardian;\n"); return 1;}
    }
  return 0;
}
