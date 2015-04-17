#include <assert.h>
#include <time.h>
#include "sdlJeu.h"
#include "jeu.h"

const int TAILLE_SPRITE=32;

SDL_Surface *SDL_load_image(const char* filename);
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );

void sdljeuInit(sdlJeu *pSdlJeu)
{
  Jeu *pJeu;
  int dimx, dimy;
  
  pJeu = &(pSdlJeu->jeu);
  jeuInit(pJeu);
  
  assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );
  
  dimx = getDimX( jeuGetConstTerrainPtr(pJeu) );
  dimy = getDimY( jeuGetConstTerrainPtr(pJeu) );
  dimx = dimx * TAILLE_SPRITE;
  dimy = dimy * TAILLE_SPRITE;
  pSdlJeu->surface_ecran = SDL_SetVideoMode(   dimx, dimy, 32, SDL_SWSURFACE );
  assert( pSdlJeu->surface_ecran!=NULL);
  SDL_WM_SetCaption( "Snake's Treasure", NULL );
  
  pSdlJeu->surface_perso = SDL_load_image("data/pacman.bmp");
  if (pSdlJeu->surface_perso==NULL)
    pSdlJeu->surface_perso = SDL_load_image("../data/pacman.bmp");
  assert( pSdlJeu->surface_perso!=NULL);
  
  pSdlJeu->surface_mur = SDL_load_image("data/mur.bmp");
  if (pSdlJeu->surface_mur==NULL)
    pSdlJeu->surface_mur = SDL_load_image("../data/mur.bmp");
  assert( pSdlJeu->surface_mur!=NULL);
  
  pSdlJeu->surface_serpent = SDL_load_image("data/serpent.bmp");
  if (pSdlJeu->surface_serpent==NULL)
    pSdlJeu->surface_serpent = SDL_load_image("../data/serpent.bmp");
  assert( pSdlJeu->surface_serpent!=NULL);

  printf("[debug] All datas loaded\n");
}


SDL_Surface *SDL_load_image(const char* filename )
{
  /* Temporary storage for the image that's loaded */
  SDL_Surface* loadedImage = NULL;
  
  /* The optimized image that will be used */
  SDL_Surface* optimizedImage = NULL;
  
  /* Load the image */
  loadedImage = SDL_LoadBMP( filename );

  /* If nothing went wrong in loading the image */
  if ( loadedImage != NULL )
    {
		/* Create an optimized image */
      optimizedImage = SDL_DisplayFormat( loadedImage );
      
      /* Free the old image */
      SDL_FreeSurface( loadedImage );
    }
  
  /* Return the optimized image */
  return optimizedImage;
}

void sdljeuAff(sdlJeu *pSdlJeu)
{
	int x,y,i;

    const Jeu *pJeu = &(pSdlJeu->jeu);
	const Terrain *pTer = jeuGetConstTerrainPtr(pJeu);
	const Personnage *pPerso = jeuGetConstPersoPtr(pJeu);
    //const Serpent *pSerpent = jeuGetConstSerpentPtr(pJeu);
	//const Temple *pTemple =  jeuGetConstTemplePtr(pJeu) ;

	/* Remplir l'écran de blanc */
	SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0xFF, 0xFF, 0xFF ) );

	for (x=0;x<getDimX(pTer);++x)
		for (y=0;y<getDimY(pTer);++y)
			if (terGetXY(pTer,x,y)=='#')
				SDL_apply_surface(  pSdlJeu->surface_mur, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);

    for (i=0; i<4; i++)
        SDL_apply_surface(  pSdlJeu->surface_serpent, pSdlJeu->surface_ecran, (pJeu->serpentTab[i].tete->x)*TAILLE_SPRITE, (pJeu->serpentTab[i].tete->y)*TAILLE_SPRITE);

	/* Copier le sprite du Personnage sur l'écran */
	SDL_apply_surface(  pSdlJeu->surface_perso, pSdlJeu->surface_ecran, persoGetX(pPerso)*TAILLE_SPRITE,  persoGetY(pPerso)*TAILLE_SPRITE );

}

void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y )
{
	/* Make a temporary rectangle to hold the offsets */
	SDL_Rect offset;

	/* Give the offsets to the rectangle */
	offset.x = x;
	offset.y = y;

	/* Blit the surface */
	SDL_BlitSurface( source, NULL, destination, &offset );
}

void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	SDL_Event event;
	int continue_boucle = 1;

    /* Horloges (en secondes) */
    float horloge_courante, horloge_precedente;

    /* Intervalle de temps (en secondes) entre deux évolutions du jeu */
    /* Changer la valeur pour ralentir ou accélérer le déplacement des fantomes */
    float intervalle_horloge = 0.1f;

    int rafraichissement;

	sdljeuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );

    /* Récupère l'horloge actuelle et la convertit en secondes */
    /* clock() retourne le nombre de tops horloge depuis le lancement du programme */
    horloge_precedente = (float)(clock()/CLOCKS_PER_SEC);

	/* Tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
	    rafraichissement = 0;

	     /* Récupère l'horloge actuelle et la convertit en secondes */
        horloge_courante = (float)clock()/(float)CLOCKS_PER_SEC;

        /* Si suffisamment de temps s'est écoulé depuis la dernière prise d'horloge */
        if (horloge_courante-horloge_precedente>=intervalle_horloge)
        {
                jeuEvolue(&(pSdlJeu->jeu));
                rafraichissement = 1;
                horloge_precedente = horloge_courante;
        }

		/* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
		while ( SDL_PollEvent( &event ) )
		{
			/* Si l'utilisateur a cliqué sur la croix de fermeture */
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;

			/* Si l'utilisateur a appuyé sur une touche */
			if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
				case SDLK_UP:
					jeuActionClavier( &(pSdlJeu->jeu), 'h');
					rafraichissement = 1;
					break;
				case SDLK_DOWN:
					jeuActionClavier( &(pSdlJeu->jeu), 'b');
					rafraichissement = 1;
					break;
				case SDLK_LEFT:
					jeuActionClavier( &(pSdlJeu->jeu), 'g');
					rafraichissement = 1;
					break;
				case SDLK_RIGHT:
					jeuActionClavier( &(pSdlJeu->jeu), 'd');
					rafraichissement = 1;
					break;
				default: break;
				}
			}

		}

        if (rafraichissement==1)
        {
            /* on affiche le jeu sur le buffer caché */
            sdljeuAff(pSdlJeu);

            /* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
            SDL_Flip( pSdlJeu->surface_ecran );
        }
	}
}

void sdljeuLibere( sdlJeu *pSdlJeu)
{
	SDL_FreeSurface( pSdlJeu->surface_perso );
	SDL_FreeSurface( pSdlJeu->surface_mur );
	SDL_FreeSurface( pSdlJeu->surface_serpent );
	//SDL_FreeSurface( pSdlJeu->surface_temple ) ;

	jeuLibere(&(pSdlJeu->jeu));

	SDL_Quit();
}
