#include "snake.h"

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
	  if (event.key.keysym.sym == SDLK_UP) move_player(snake, GO_UP);
	  else if (event.key.keysym.sym == SDLK_RIGHT) move_player(snake, GO_RIGHT);
	  else if (event.key.keysym.sym == SDLK_DOWN) move_player(snake, GO_DOWN);
	  else if (event.key.keysym.sym == SDLK_LEFT)  move_player(snake, GO_LEFT);
	  else if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
	  break;
	default:
	  ;
	}
        draw_map(snake);
    }
}
int	main(int ac, char **av)
{
  t_snake	*snake;

  if (!(snake = malloc(sizeof(t_snake)))) return 1;
  strcpy(snake->map[0], "##################");
  strcpy(snake->map[1], "#................#");
  strcpy(snake->map[2], "#.##..##..##..##.#");
  strcpy(snake->map[3], "#.##..##..##..##.#");
  strcpy(snake->map[4], "#...##......##...#");
  strcpy(snake->map[5], "#...##......##...#");
  strcpy(snake->map[6], "#.##..##..##..##.#");
  strcpy(snake->map[7], "#.##..##..##..##.#");
  strcpy(snake->map[8], "#................#");
  strcpy(snake->map[9], "#................#");
  strcpy(snake->map[10],"#.##..##..##..##.#");
  strcpy(snake->map[11],"#.##..##..##..##.#");
  strcpy(snake->map[12],"#...##......##...#");
  strcpy(snake->map[13],"#...##......##...#");
  strcpy(snake->map[14],"#.##..##..##..##.#");
  strcpy(snake->map[15],"#.##..##..##..##.#");
  strcpy(snake->map[16],"#................#");
  strcpy(snake->map[17],"##################");
  if (init_sdl(snake)) return 1;
  main_loop(snake);
  SDL_FreeSurface(snake->surfaces[SCREEN]);
  SDL_Quit();
  return 0;
}
