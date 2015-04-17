#include "salle.h"

void salleInit(Salle *pSalle, int x, int y)
{
	pSalle->x = x;
	pSalle->y = y;
    pSalle->occupe = 0;
}

int salleGetX(const Salle *pSalle)
{
	return pSalle->x;
}

int salleGetY(const Salle *pSalle)
{
	return pSalle->y;
}


int salleGetOccupe(const Salle *pSalle)
{
	return pSalle->occupe;
}

void salleSetX(Salle *pSalle,const int x)
{
	pSalle->x = x;
}


void salleSetY(Salle *pSalle,const int y)
{
	pSalle->y = y;
}

void salleSetOccupe(Salle *pSalle,const int boccup)
{
	pSalle->occupe = boccup;
}

