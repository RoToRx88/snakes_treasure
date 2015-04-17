#include "tresor.h"

void tresorInit(Tresor *pTresor, int x, int y)
{
	pTresor->x = x;
	pTresor->y = y;
}

int tresorGetX(const Tresor *pTresor)
{
	return pTresor->x;
}

int tresorGetY(const Tresor *pTresor)
{
	return pTresor->y;
}

int tresorGetValeur(const Tresor *pTresor)
{
	return pTresor->valeur;
}

int tresorGetPrise(const Tresor *pTresor)
{
	return pTresor->prise;
}

void tresortSetX(Tresor *pTresor,const int x)
{
	pTresor->x = x;
}


void tresorSetY(Tresor *pTresor,const int y)
{
	pTresor->y = y;
}

void tresorSetValeur(Tresor *pTresor,const int ivaleur)
{
	pTresor->valeur = ivaleur;
}

void tresorSetPrise(Tresor *pTresor,const int bprise)
{
	pTresor->prise = bprise;
}
