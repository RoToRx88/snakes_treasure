#include "snake.h"

/**
@brief initialisation du jeu
@param snake est un pointeur de structure t_snake

init_sdl initialise le jeu avec les images

@return 0
*/

int     init_sdl(t_snake *snake)
{
  int	i;

  printf("Initializing SDL.\n");
  if (-1 == SDL_Init(SDL_INIT_EVERYTHING) ||
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
  SDL_SetColorKey(snake->surfaces[BLUE_ORBE], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[BLUE_ORBE]->format,255,255,255)) ;
  if (!(snake->surfaces[HEART] = load_image("img/heart.bmp")))
  {
      printf("L'image du coeur non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  SDL_SetColorKey(snake->surfaces[HEART], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[HEART]->format,255,255,255)) ;
  snake->player_pos_x = 6;
  snake->player_pos_y = 5;
  snake->life = 1;
  generate_loot(snake);
  /*Set size of a guardian*/
  snake->guardian_size = 4; /*WARNING need to be between 0 and 8*/
  /*init chained list for all guardians*/
  for (i = 0; i < 4; ++i)
    {
      if (init_guardian(snake, i)) {printf("[error] Error creating guardian;\n"); return 1;}
    }
  return 0;
}
