#ifndef TEMPLE_H
#define TEMPLE_H

#include "terrain.h"
#include "salle.h"


struct sTemple
{
   int x, y, nbTresor;
    Salle salleTab[4];
};
typedef struct sTemple Temple;

void templeInit(Temple *, int x, int y);
int templeGetX(const Temple *);
int templeGetY(const Temple *);
int templeGetNbTresor(const Temple *);
void templeSetX(Temple *,const int x);
void templeSetY(Temple *,const int y);
void templeSetnbTresor(Temple *,const int iNbTresor);

#endif
