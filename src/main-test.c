int main()
{
    t_Snake *snake;
    t_Guardian *g;
    t_Loot *loot;
    i=-1;

    /* Initialisations des butins*/

    printf("Initialisations des butins");


    snake_Generate_Loot(snake);
    int	tabx[16] = {4, 6, 4, 2, 12, 14, 12, 10,  4,  6,  4,  2, 12, 14, 12, 10};
    int	taby[16] = {2, 4, 6, 4,  2,  4,  6,  4, 10, 12, 14, 12, 10, 12, 14, 12};
      while (++i < 16)
    {
      assert(snake->loot[i].pos_x)= tabx[i]);
      asset(snake->loot[i].pos_y = taby[i]);
      if tabx[i] == 6
      {
          assert(snake->loot[i].type =1);
      }
      else
      {
          assert(snake->loot[i].type =0);
      }
      assert(snake->loot[i].taked = 0);
    }
    printf("...OK!\n");



    /* Initialisations du jeu*/

    printf("Initialisations du jeu");
    snake_Init_Values(snake);
    assert(snake->player_pos_x=6);
    assert(snake->player_pos_y=5);
    assert(snake->life = 1);
    assert(snake->clock_speed = 0.2);
    assert(snake->clock = 30);
    assert(snake->guardian_size = 1);
    printf("...OK!\n");

     /* déplacement du gardien 0*/
     printf("déplacement du gardien 0");
     g->pos_y == 8;
     g->pos_x == 2;
     guard_0(g);
     assert(g->pos_y = 8 && g->pos_x = 1);
     g->pos_y == 2;
     g->pos_x == 8;
     assert(g->pos_y = 3 && g->pos_x = 8);
    printf("...OK!\n");
}

/**
@brief Test le module

Effectue tout une série de test vérifiant que le module fonctionne et que les champ de la structure sont conformes

@return none
*/
void imTestRegression()
{
	Image picW, picH, *picCreate;


	int i,j;
	Pixel blue = { 0, 0, 255 };
	Pixel black = { 0, 0, 0 };
	Pixel red = { 255, 0, 0 };
	Pixel flash = { 124, 48, 112 };
	Pixel test;

	/* Initialisations d'images larges et hautes */
	printf("Initialisation d'une image 150x20");
	imInit(&picW, 150, 20);
	assert(picW.dimx == 150 && picW.dimy == 20 && picW.tab != NULL);
	printf("...OK!\n");

	printf("Initialisation d'une image 20x150");
	imInit(&picH, 20, 150);
	assert(picH.dimy == 150 && picH.dimx == 20 && picH.tab != NULL);
	printf("...OK!\n");

	/* Creation d'image par la proc imCreer */
	printf("Creation d'une image 150x60");
	picCreate = imCreer(150, 60);
	assert(picCreate != NULL && picCreate->dimx == 150 && picCreate->dimy == 60 && picCreate->tab != NULL);
	printf("...OK!\n");



	printf("Remplissage de  l'image 150x20 d'une couleur");
	imEffacer(&picW, &flash);
	for (i = 0; i < picW.dimx; i++) {
		for (j = 0; j < picW.dimy; j++) {
			assert(picW.tab[j * (picW.dimx) + i].r == 124 &&
			picW.tab[j * (picW.dimx) + i].g == 48 &&
			picW.tab[j * (picW.dimx) + i].b == 112 );
		}
	}
	printf("...OK!\n");

	printf("Remplissage de  l'image 20x150 d'une couleur");
	imEffacer(&picH, &flash);
	for (i = 0; i < picH.dimx; i++) {
		for (j = 0; j < picH.dimy; j++) {
			assert(picH.tab[j * (picH.dimx) + i].r == 124 &&
			picH.tab[j * (picH.dimx) + i].g == 48 &&
			picH.tab[j * (picH.dimx) + i].b == 112 );
		}
	}
	printf("...OK!\n");

	printf("Remplissage de  l'image 150x60 d'une couleur");
	imEffacer(picCreate, &flash);
	for (i = 0; i < picCreate->dimx; i++) {
		for (j = 0; j < picCreate->dimy; j++) {
			assert(picCreate->tab[j * (picCreate->dimx) + i].r == 124 &&
			picCreate->tab[j * (picCreate->dimx) + i].g == 48 &&
			picCreate->tab[j * (picCreate->dimx) + i].b == 112 );
		}
	}
	printf("...OK!\n");

	printf("Premier pixel d'image 1 devient rouge");
	setPix(&picW, 0, 0, &red);
	assert( picW.tab[0].r == 255 &&
		picW.tab[0].g == 0 &&
		picW.tab[0].b == 0 );
	printf("...OK!\n");

	printf("Premier pixel d'image 2 devient rouge");
	setPix(&picH, 0, 0, &red);
	assert( picH.tab[0].r == 255 &&
		picH.tab[0].g == 0 &&
		picH.tab[0].b == 0 );
	printf("...OK!\n");

	printf("Premier pixel d'image 3 devient rouge");
	setPix(picCreate, 0, 0, &red);
	assert( picCreate->tab[0].r == 255 &&
		picCreate->tab[0].g == 0 &&
		picCreate->tab[0].b == 0 );
	printf("...OK!\n");

	printf("Test si pixel d'image 1 est vraiment rouge");
	test = getPix(picW, 0, 0);
	assert(red.r == test.r && red.g == test.g && red.b == test.b);
	printf("...OK!\n");

	printf("Test si pixel d'image 2 est vraiment rouge");
	test = getPix(picH, 0, 0);
	assert(red.r == test.r && red.g == test.g && red.b == test.b);
	printf("...OK!\n");

	printf("Test si pixel d'image 3 est vraiment rouge");
	test = getPix(*picCreate, 0, 0);
	assert(red.r == test.r && red.g == test.g && red.b == test.b);
	printf("...OK!\n");

	printf("Dessin d'un rectangle bleu sur image 1 avec x => 0 => 15 et y => 5 => 15");
	imDessineRect(&picW, 0, 5, 15, 15, &blue);
	for (i = 0; i < 15; i++) {
		for (j = 5; j < 15; j++) {
			assert(picW.tab[j * (picW.dimx) + i].r == 0 &&
			picW.tab[j * (picW.dimx) + i].g == 0 &&
			picW.tab[j * (picW.dimx) + i].b == 255 );
		}
	}
	printf("...OK!\n");

	printf("Dessin d'un rectangle noir sur image 2 avec x => 5 => 15 et y => 5 => 15");
	imDessineRect(&picH, 5, 5, 15, 15, &black);
	for (i = 5; i < 15; i++) {
		for (j = 5; j < 15; j++) {
			assert(picH.tab[j * (picH.dimx) + i].r == 0 &&
			picH.tab[j * (picH.dimx) + i].g == 0 &&
			picH.tab[j * (picH.dimx) + i].b == 0 );
		}
	}
	printf("...OK!\n");

	printf("Dessin d'un rectangle bleu sur image 3 avec x => 20 => 40 et y => 21 => 45");
	imDessineRect(picCreate, 20, 21, 40, 45, &blue);
	for (i = 20; i < 40; i++) {
		for (j = 21; j < 45; j++) {
			assert(picCreate->tab[j * (picCreate->dimx) + i].r == 0 &&
			picCreate->tab[j * (picCreate->dimx) + i].g == 0 &&
			picCreate->tab[j * (picCreate->dimx) + i].b == 255);
		}
	}
	printf("...OK!\n");

	imSauver(&picW, "data/picw.ppm");
	imSauver(&picH, "data/picH.ppm");
	imSauver(picCreate, "data/picCreate.ppm");

	imOuvrir(&picW, "data/picw.ppm");
	imOuvrir(&picH, "data/picH.ppm");
	imOuvrir(picCreate, "data/picCreate.ppm");

	printf("Libération mémoire de picW");
	imLibere(&picW);
	assert( picW.tab == NULL && picW.dimx == 0 && picW.dimy == 0);
	printf("...OK!\n");

	printf("Libération mémoire de picH");
	imLibere(&picH);
	assert( picH.tab == NULL && picH.dimx == 0 && picH.dimy == 0);
	printf("...OK!\n");

	printf("Libération mémoire de picCreate");
	imDetruire(&picCreate);
	assert( picCreate == NULL );
	printf("...OK!\n");

}
