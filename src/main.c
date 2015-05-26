#include "snake.h"
#include "loot.h"
#include "guardian.h"
#include "sdl_game.h"
#include <time.h>
#include <unistd.h>
#include <assert.h>

int main_loop(t_Snake *snake)
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
	snake_Check_Guardian_Collision(snake);
	if (new_clock - old_clock > 1.0) // décompte du chrono du jeu
	  {
	    snake->clock -= 1;
	    old_clock = new_clock;
	    printf("Temps restant: %d\n", snake->clock);
	  }
	if (snake->clock <= 0) // verifie qu'il nous reste du temps pour jouer
	  {
	    sdl_Apply_Surface(0, 0, snake->surfaces[TIMEOUT], snake->surfaces[SCREEN]);
	    SDL_Flip(snake->surfaces[SCREEN]);
	    usleep(1500000); // programme en pause durant 1.5sec
	    if (!sdl_Menu(snake))
	      {
		if (snake_Init_Values(snake)) return 1;
		main_loop(snake);
	      }
	    return 0;
	  }
	if (horloge_courante - horloge_precedente >= snake->clock_speed) // permet de faire avancer le serpent à chaque tic d'horloge
	  {
	    snake_Calc_Guardian_Pos(snake);
	    rafraichissement = 1;
	    horloge_precedente = horloge_courante;
	  }
	/* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
	if (snake_Check_If_Win(snake) && snake->guardian_size < 8)
	  {
	    int i;

	    sdl_Apply_Surface(0, 0, snake->surfaces[LEVELUP], snake->surfaces[SCREEN]);
	    SDL_Flip(snake->surfaces[SCREEN]);
	    usleep(1500000);
	    printf("!!!!!!!!!!!!You win!!!!!!!!!!!!\n");
	    snake_Generate_Loot(snake);
	    snake->guardian_size += 1;
	    if (snake->guardian_size == 2)
	      snake->clock_speed -= 0.1;
	    else
	      snake->clock_speed -= 0.001;
	    snake->clock = 30 + (snake->guardian_size * 2); // premier niveau on a 30 secondes de chrono et après 30 + 2 * taille du serpent
	    for (i = 0; i < 4; ++i)
	      {
		if (snake_Init_Guardian(snake, i)) {printf("[error] Error creating guardian;\n"); return 1;}
	      }
	  }
	else if (snake_Check_If_Win(snake)) // Si on est au dernier niveau et qu'on gagne fin du jeu
	  {
	    sdl_Apply_Surface(0, 0, snake->surfaces[WIN], snake->surfaces[SCREEN]);
	    SDL_Flip(snake->surfaces[SCREEN]);
	    usleep(1500000);
	    if (!sdl_Menu(snake))
	      {
		if (snake_Init_Values(snake)) return 1;
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
		if (event.key.keysym.sym == SDLK_UP) snake_Move_Player(snake, GO_UP);
		else if (event.key.keysym.sym == SDLK_RIGHT) snake_Move_Player(snake, GO_RIGHT);
		else if (event.key.keysym.sym == SDLK_DOWN) snake_Move_Player(snake, GO_DOWN);
		else if (event.key.keysym.sym == SDLK_LEFT) snake_Move_Player(snake, GO_LEFT);
		else if (event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
		else if (event.key.keysym.sym == SDLK_c) snake_Cheat_Win(snake); //permet de passer les niveaux "à la main"
		break;
	      default:;
	      }
	  }
	if (rafraichissement == 1)
	  {
	    /* on affiche le jeu sur le buffer caché */
	    if (sdl_Draw_Map(snake)) return 1;
	    /* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
	    SDL_Flip(snake->surfaces[SCREEN]);
	  }
	if(snake->life == 0)
	  {
	    sdl_Apply_Surface(0, 0, snake->surfaces[LOSE], snake->surfaces[SCREEN]);
	    SDL_Flip(snake->surfaces[SCREEN]);
	    usleep(1500000);
	    printf("GAME OVER. TRY AGAIN !\n");
	    if (!sdl_Menu(snake))
	      {
		if (snake_Init_Values(snake)) return 1;
		main_loop(snake);
	      }
	    return 0;

	  }
	sdl_Draw_Map(snake);
      }
    return 0;
}

int	main(int ac, char **av)
{
  t_Snake	*snake;


  if (!(snake = malloc(sizeof(t_Snake)))) return 1;
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
  if (sdl_Init(snake)) return 1;
  sdl_Apply_Surface(0, 0, snake->surfaces[LOGO], snake->surfaces[SCREEN]);
  SDL_Flip(snake->surfaces[SCREEN]);
  usleep(3000000);
  sdl_Draw_Map(snake);
  /*Menu avant le jeu*/
  if (!sdl_Menu(snake))
    main_loop(snake);
  SDL_FreeSurface(snake->surfaces[SCREEN]);
  SDL_FreeSurface(snake->surfaces[WALL]);
  SDL_FreeSurface(snake->surfaces[PLAYER]);
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
