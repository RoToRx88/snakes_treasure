#include "snake.h"
#include <time.h>
#include <unistd.h>

/**
@brief boucle du jeu
@param snake est un pointeur de structure t_snake

main_loop est la boucle du jeu qui permet le deplacement du perso et la fin du niveau

@return none
*/
/*
int	main_loop(t_snake *snake)
{
  int		quit = 0;
  int		i;
  SDL_Event	event;

  SDL_EnableKeyRepeat(50, 100);
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
	  if (check_if_win(snake)) printf("!!!!!!!!!!!!You win!!!!!!!!!!!!\n");
	  if (draw_map(snake)) return 0;
          break;
        default:
          ;
        }
    }
}*/


int main_loop(t_snake *snake)
{
    int		quit = 0;
    SDL_Event	event;
    float	horloge_courante, horloge_precedente;
    int		rafraichissement;
    float	old_clock, new_clock;

    horloge_precedente = (float)clock()/(float)CLOCKS_PER_SEC;
    old_clock = horloge_precedente;
    while (!quit)
    {
      rafraichissement = 0;
      horloge_courante = (float)clock()/(float)CLOCKS_PER_SEC;
      new_clock = (float)clock()/(float)CLOCKS_PER_SEC;
      check_guardian_collision(snake);
      if (snake->clock <= 0)
	{
          apply_surface(0, 0, snake->surfaces[TIMEOUT], snake->surfaces[SCREEN]);
          SDL_Flip(snake->surfaces[SCREEN]);
          usleep(1500000);
	  if (!menu(snake))
	    {
	      if (init_values(snake)) return 1;
	      main_loop(snake);
	    }	  
	  return 0;
	}
      if (new_clock - old_clock > 1.0)
	{
	   snake->clock -= 1;
	   old_clock = new_clock;
	   printf("Temps restant: %d\n", snake->clock);
	}
      if (horloge_courante - horloge_precedente >= snake->clock_speed)
        {
	  calc_guardian_pos(snake);
	  rafraichissement = 1;
	  horloge_precedente = horloge_courante;
        }
      /* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
      if (check_if_win(snake) && snake->guardian_size < 8)
	{
	  int i;
	  
	  apply_surface(0, 0, snake->surfaces[LEVELUP], snake->surfaces[SCREEN]);
	  SDL_Flip(snake->surfaces[SCREEN]);
	  usleep(1500000);
	  printf("!!!!!!!!!!!!You win!!!!!!!!!!!!\n");
	  generate_loot(snake);
	  snake->guardian_size += 1;
	  if (snake->guardian_size == 2)
	    snake->clock_speed -= 0.1;
	  else
	    snake->clock_speed -= 0.001;
	  snake->clock = 30 + (snake->guardian_size * 2);
	  for (i = 0; i < 4; ++i)
	    {
	      if (init_guardian(snake, i)) {printf("[error] Error creating guardian;\n"); return 1;}
	    }
	}
      else if (check_if_win(snake))
	{
          apply_surface(0, 0, snake->surfaces[WIN], snake->surfaces[SCREEN]);
          SDL_Flip(snake->surfaces[SCREEN]);
          usleep(1500000);
	  if (!menu(snake))
	    {
	      if (init_values(snake)) return 1;
	      main_loop(snake);
	    }
	  return 0;
	}
      while (SDL_PollEvent(&event))
	{
	  switch(event.type)
	    {
	    case SDL_QUIT:
	      quit = 1;
	      break;
	    case SDL_KEYDOWN:
	      if (event.key.keysym.sym == SDLK_UP) move_player(snake, GO_UP);
	      else if (event.key.keysym.sym == SDLK_RIGHT) move_player(snake, GO_RIGHT);
	      else if (event.key.keysym.sym == SDLK_DOWN) move_player(snake, GO_DOWN);
	      else if (event.key.keysym.sym == SDLK_LEFT) move_player(snake, GO_LEFT);
	      else if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
	      else if (event.key.keysym.sym == SDLK_c) cheat_win(snake); //permet de passer les niveaux "à la main"
	      break;
	    default:;
	    }
        }
      if (rafraichissement == 1)
        {
	  /* on affiche le jeu sur le buffer caché */
	  if (draw_map(snake)) return 1;
	  /* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
	  SDL_Flip(snake->surfaces[SCREEN]);
        }
      if(snake->life == 0)
        {
	  quit = 1;
	  printf("GAME OVER. TRY AGAIN !\n");
        }
      draw_map(snake);
    }
    return 0;
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
  apply_surface(0, 0, snake->surfaces[LOGO], snake->surfaces[SCREEN]);
  SDL_Flip(snake->surfaces[SCREEN]);
  usleep(3000000);
  draw_map(snake);
  /*menu before play*/
  if (!menu(snake))
    main_loop(snake);
  SDL_FreeSurface(snake->surfaces[SCREEN]);
  SDL_FreeSurface(snake->surfaces[WALL]);
  SDL_FreeSurface(snake->surfaces[PACMAN]);
  SDL_FreeSurface(snake->surfaces[SNAKE]);
  SDL_FreeSurface(snake->surfaces[BACKGROUND]);
  SDL_FreeSurface(snake->surfaces[BLUE_ORBE]);
  SDL_FreeSurface(snake->surfaces[HEART]);
  SDL_FreeSurface(snake->surfaces[WIN]);
  SDL_FreeSurface(snake->surfaces[LEVELUP]);
  SDL_FreeSurface(snake->surfaces[LOSE]);
  SDL_FreeSurface(snake->surfaces[TIMEOUT]);
  SDL_FreeSurface(snake->surfaces[MENU]);
  SDL_FreeSurface(snake->surfaces[LOGO]);
  SDL_Quit();
  free(snake);
  return 0;
}
