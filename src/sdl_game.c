#include "sdl_game.h"
#include <assert.h>

/**
@brief permet de charger des images .bmp
@param filename chaine de caractère (nom de fichier)


SDL_Surface charge une image .bmp

@return optimizedImage
*/

SDL_Surface *sdl_Load_Image(char *filename)
{
  assert (filename != NULL); // le fichier ne peut pas être nul

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
@brief applique une surface sur la fenêtre
@param x entier >0
@param y entier >0
@param source pointeur sur SDL_Surface
@param destination pointeur sur SDL_Surface

sdl_Apply_Surface applique une surface sur la fenêtre

@return none
*/

void sdl_Apply_Surface(const int x, const int y, SDL_Surface* source, SDL_Surface* destination)
{
  assert (source != NULL && destination != NULL); // source et destination non nuls

  SDL_Rect      offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface( source, NULL, destination, &offset );
}


/**
@brief affiche les butins non pris
@param snake est un pointeur sur t_Snake

sdl_Display_Loot affiche les butins et les coeurs non pris, si le personnage est sur une "case butin", alors le butin est pris et donc ne s'affiche plus.

@return none
*/
void sdl_Display_Loot(t_Snake *snake)
{
  assert (snake != NULL); // le jeu ne peut pas être nul
  int	i = -1;

  while (++i < 16)
    {
      if (snake->player_pos_x == snake->loot[i].pos_x && snake->player_pos_y == snake->loot[i].pos_y)
	snake->loot[i].taked = 1;
      if (snake->loot[i].type == ORBE && snake->loot[i].taked == 0)
	sdl_Apply_Surface(snake->loot[i].pos_x * 32, snake->loot[i].pos_y * 32,  snake->surfaces[BLUE_ORBE], snake->surfaces[SCREEN]);
      else if (snake->loot[i].type == LIFE && snake->loot[i].taked == 0)
	sdl_Apply_Surface(snake->loot[i].pos_x * 32, snake->loot[i].pos_y * 32, snake->surfaces[HEART], snake->surfaces[SCREEN]);
    }
}

/**
@brief place les murs, le perso et les serpents sur le terrain
@param snake est un pointeur sur t_Snake

sdl_Draw_Map transforme les # par des murs et affiche le personnage et les serpents

@return 1
*/

int sdl_Draw_Map(t_Snake *snake)
{
  assert(snake != NULL); // le jeu ne peut pas être nulle
  int   i = -1;
  int   j = -1;

  /* le fond d'abord pour éviter les images multiples */
  sdl_Apply_Surface(0, 0, snake->surfaces[BACKGROUND], snake->surfaces[SCREEN]);
    /* si 1, plus de vie, sinon au moins une */
  if (snake_Check_Life(snake) == 1) return 1;
  while (++i < 18)
    {
      j = -1;
      while (++j < 18)
	{
	  /*test pour afficher un mur*/
          if (snake->map[j][i] == '#') sdl_Apply_Surface(i * 32, j * 32, snake->surfaces[WALL], snake->surfaces[SCREEN]);
	}
    }
  /*affiche tous les trésors/vies a leur position*/
  sdl_Display_Loot(snake);
  sdl_Display_Guardian(snake);
  /*affiche le player a sa position*/
  sdl_Apply_Surface(snake->player_pos_x * 32, snake->player_pos_y * 32, snake->surfaces[PLAYER], snake->surfaces[SCREEN]);
  if(SDL_Flip(snake->surfaces[SCREEN]) == -1) return 1;
  return 0;
}

/**
@brief affichage du menu
@param snake est un pointeur sur t_Snake

sdl_Menu affiche le menu. La surface du fond "BACKROUND" sera appliqué à la fenetre avec par dessus le menu (proposition Play ou Quit)

@return 0
*/

int    sdl_Menu(t_Snake *snake)
{
  assert (snake != NULL); // le jeu ne peut pas être nul

  SDL_Event     event;

  sdl_Apply_Surface(0, 0, snake->surfaces[MENU], snake->surfaces[SCREEN]);
  SDL_Flip(snake->surfaces[SCREEN]);
  while (SDL_WaitEvent(&event))
    {
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
@brief affiche chaque partie des 4 serpents.
@param snake est un pointeur de structure t_Snake

sdl_Display_Guardian affiche partie par partie (en fonction de la taille du serpent)

@return none
*/

void		sdl_Display_Guardian(t_Snake *snake)
{
  assert(snake != NULL); // le jeu ne peut pas être nul
  
  int		i = -1;
  t_Guardian	*n;

  while (++i < 4)
    {
      n = &(snake->guardian[i]);
      while (n->next)
	{
	  sdl_Apply_Surface (n->pos_x * 32, n->pos_y * 32, snake->surfaces[SNAKE], snake->surfaces[SCREEN]);
	  n = n->next;
	}
    }
}

/**
@brief initialisation du jeu
@param snake est un pointeur sur t_Snake

sdl_Init initialise le jeu avec les images

@return 0
*/

int     sdl_Init(t_Snake *snake)
{
  assert (snake != NULL); // le jeu ne peut pas être nul

  printf("Initializing SDL.\n");
  if (-1 == SDL_Init(SDL_INIT_VIDEO) ||
      !(snake->surfaces[SCREEN] = SDL_SetVideoMode(576, 576, 16, SDL_HWSURFACE)))
    {
      printf("Unable to launch SDL; error: %s\n", SDL_GetError());
      return 1;
    }
  SDL_WM_SetCaption("Snake's treasure", NULL);
  if (!(snake->surfaces[WALL] = sdl_Load_Image("data/wall.bmp")))
  {
      printf("L'image du mur non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  if (!(snake->surfaces[PLAYER] = sdl_Load_Image("data/player.bmp")))
  {
      printf("L'image du personnage non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  // SDL_SetColorKey(snake->surfaces[PLAYER], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[PLAYER]->format,255,255,255)) ;
  if (!(snake->surfaces[SNAKE] = sdl_Load_Image("data/snake.bmp")))
    {
      printf("L'image du snake non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  if (!(snake->surfaces[BACKGROUND] = sdl_Load_Image("data/background.bmp")))
  {
      printf("L'image du FOND (parce Maelle fait chier) non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  if (!(snake->surfaces[BLUE_ORBE] = sdl_Load_Image("data/blue_orbe.bmp")))
  {
      printf("L'image du tresor (Blue_orbe) non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  SDL_SetColorKey(snake->surfaces[BLUE_ORBE], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[BLUE_ORBE]->format,255,255,255));
  if (!(snake->surfaces[HEART] = sdl_Load_Image("data/heart.bmp")))
  {
      printf("L'image du coeur non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }
  SDL_SetColorKey(snake->surfaces[HEART], SDL_SRCCOLORKEY, SDL_MapRGB(snake->surfaces[HEART]->format,255,255,255)) ;

  /*level up*/
  if (!(snake->surfaces[LEVELUP] = sdl_Load_Image("data/levelup.bmp")))
  {
      printf("L'image du level up non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*win*/
  if (!(snake->surfaces[WIN] = sdl_Load_Image("data/win.bmp")))
  {
      printf("L'image du win non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*lose*/
  if (!(snake->surfaces[LOSE] = sdl_Load_Image("data/lose.bmp")))
  {
      printf("L'image du lose non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*time out*/
  if (!(snake->surfaces[TIMEOUT] = sdl_Load_Image("data/timeout.bmp")))
  {
      printf("L'image du timeout non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*menu*/
  if (!(snake->surfaces[MENU] = sdl_Load_Image("data/menu.bmp")))
  {
      printf("L'image du menu non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  /*logo*/
  if (!(snake->surfaces[LOGO] = sdl_Load_Image("data/logo.bmp")))
  {
      printf("L'image du logo non trouvée. Maelle tu n'as pas mis les images au bon endroit :@");
      return 1;
  }

  if (snake_Init_Values(snake)) return 1;
  return 0;
}
