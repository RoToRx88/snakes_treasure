#include "personnage.h"

void persoInit(Personnage *pPerso, const Terrain *pTer)
{
	pPerso->x = (pTer->dimx)/2; // milieu du terrain
	pPerso->y = ((pTer->dimy)/2)-1; // milieu du terrain
}

void persoGauche(Personnage *pPerso, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPerso->x-1, pPerso->y))
		pPerso->x--;
}

void persoDroite(Personnage*pPerso, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPerso->x+1, pPerso->y))
		pPerso->x++;
}

void persoHaut(Personnage *pPerso, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPerso->x, pPerso->y-1))
		pPerso->y--;
}

void persoBas(Personnage *pPerso, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pPerso->x, pPerso->y+1))
		pPerso->y++;
}

int persoGetX(const Personnage *pPerso)
{
	return pPerso->x;
}

int persoGetY(const Personnage *pPerso)
{
	return pPerso->y;
}

void persoSetX(Personnage *pPerso,const int x)
{
	pPerso->x = x;
}


void persoSetY(Personnage *pPerso,const int y)
{
	pPerso->y = y;
}
