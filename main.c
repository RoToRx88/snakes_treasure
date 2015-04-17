#include "snake.h"

SDL_Surface     *load_image(char* filename)
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


void		apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{ 
  SDL_Rect	offset; 
  
  offset.x = x; 
  offset.y = y;
  SDL_BlitSurface( source, NULL, destination, &offset ); 
}

int	draw_map(t_snake *snake)
{
  int	i = -1;
  int	j = -1;

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

int	init_sdl(t_snake *snake)
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

void		main_loop(t_snake *snake)
{
  int		quit = 0;
  SDL_Event	event;
 
  while (!quit)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  quit = 1;
	  break;
	case SDL_KEYDOWN:
	  if(event.key.keysym.sym == SDLK_UP) move_player(snake, GO_UP);
	  if(event.key.keysym.sym == SDLK_RIGHT) move_player(snake, GO_RIGHT);
	  if(event.key.keysym.sym == SDLK_DOWN) move_player(snake, GO_DOWN);
	  if(event.key.keysym.sym == SDLK_LEFT)  move_player(snake, GO_LEFT);
	  break; 
	default:
	  ;
	}
    }
}
int	main(int ac, char **av)
{
  t_snake	*snake;

  if (!(snake = malloc(sizeof(t_snake)))) return 1;
  strcpy(snake->map[0], "##################");
  strcpy(snake->map[1], "#................#");
  strcpy(snake->map[2],  "#.##..##..##..##.#");
  strcpy(snake->map[3], "#.##..##..##..##.#");
  strcpy(snake->map[4], "#...##......##...#");
  strcpy(snake->map[5], "#...##......##...#");
  strcpy(snake->map[6], "#.##..##..##..##.#");
  strcpy(snake->map[7], "#.##..##..##..##.#");
  strcpy(snake->map[8], "#................#");
  strcpy(snake->map[9], "#................#");
  strcpy(snake->map[10], "#.##..##..##..##.#");
  strcpy(snake->map[11], "#.##..##..##..##.#");
  strcpy(snake->map[12], "#...##......##...#");
  strcpy(snake->map[13], "#...##......##...#");
  strcpy(snake->map[14], "#.##..##..##..##.#");
  strcpy(snake->map[15], "#.##..##..##..##.#");
  strcpy(snake->map[16], "#................#");
  strcpy(snake->map[17], "##################");
  if (init_sdl(snake)) return 1;
  draw_map(snake);
  main_loop(snake);
  SDL_FreeSurface(snake->surfaces[SCREEN]);
  SDL_Quit();
  return 0;
}
