#include "temple.h"
#include "stdlib.h"
#include "stdio.h"

void templeInit(Temple *pTemple, int x, int y)
{
	pTemple->x = x;
	pTemple->y = y;
    salleInit(&(pTemple->salleTab[0]), x+2, y);
    salleInit(&(pTemple->salleTab[1]), x, y+2);
    salleInit(&(pTemple->salleTab[2]), x+4, y+2);
    salleInit(&(pTemple->salleTab[3]), x+2, y+4);
}

int templeGetX(const Temple *pTemple)
{
	return pTemple->x;
}

int templeGetY(const Temple *pTemple)
{
	return pTemple->y;
}

int templeGetNbTresor(const Temple *pTemple)
{
	return pTemple->nbTresor;
}


void templeSetX(Temple *pTemple,const int x)
{
	pTemple->x = x;
}


void templeSetY(Temple *pTemple,const int y)
{
	pTemple->y = y;
}

void templeSetLong(Temple *pTemple,const int iNbTresor)
{
	pTemple->nbTresor = iNbTresor;
}
