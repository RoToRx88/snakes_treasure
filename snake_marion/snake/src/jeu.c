#include "jeu.h"
#include <malloc.h>
#include <stdlib.h>

void jeuInit(Jeu *pJeu)
{
    int X, Y, i;
    X=(pJeu->ter.dimx)/2; // X est la moitié du terrain
    Y=(pJeu->ter.dimy)/2; // Y est la moitié du terrain
	terInit(&(pJeu->ter));
	persoInit(&(pJeu->perso), &(pJeu->ter));
	for(i=0; i<(4); i++)
    {
        initialiserSerpent(&(pJeu->serpentTab[i]));
    }
    ajouterEnTeteSerpent(X, Y, &(pJeu->serpentTab[0]));
    ajouterEnTeteSerpent(X+1, Y,&(pJeu->serpentTab[1]));
    ajouterEnTeteSerpent(X, Y+1, &(pJeu->serpentTab[2]));
    ajouterEnTeteSerpent(X+1, Y+1, &(pJeu->serpentTab[3]));
    //templeInit(pJeu->templeTab[0], 2, 2);
    //templeInit(pJeu->templeTab[1], 10, 2);
    //templeInit(pJeu->templeTab[2], 2, 10);
    //templeInit(pJeu->templeTab[3], 10, 10);

}


void jeuLibere(Jeu *pJeu)
{
	terLibere(&(pJeu->ter));
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

Personnage *jeuGetPersoPtr(Jeu *pJeu)
{
	return &(pJeu->perso);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{
	return &(pJeu->ter);
}

const Personnage *jeuGetConstPersoPtr(const Jeu *pJeu)
{
	return &(pJeu->perso);
}

const Serpent *jeuGetConstSerpentPtr(const Jeu *pJeu)
{
    return &(pJeu->serpentTab[0]);
}

const Temple *jeuGetConstTemplePtr(const Jeu *pJeu)
{
     return &(pJeu->templeTab[0]);
}

void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' :
				persoGauche(&(pJeu->perso), &(pJeu->ter));
				break;
		case 'd' :
				persoDroite(&(pJeu->perso), &(pJeu->ter));
				break;
		case 'h' :
				persoHaut(&(pJeu->perso), &(pJeu->ter));
				break;
		case 'b' :
				persoBas(&(pJeu->perso), &(pJeu->ter));
				break;
	}
}

void jeuEvolue(Jeu *pJeu)
{
    int i ;
    for (i=0; i<4; i++)
    {
        deplacementSerp(&(pJeu->serpentTab[i])) ;

    }
}

