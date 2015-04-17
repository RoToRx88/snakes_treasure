#ifndef SALLE_H
#define SALLE_H

#include "terrain.h"
#include "tresor.h"

struct sSalle
{
    int x, y;
    int occupe;

};
typedef struct sSalle Salle;

void salleInit(Salle *, int x, int y);
int salleGetX(const Salle *);
int salleGetY(const Salle *);
int salleGetOccupe(const Salle *);
void salleSetX(Salle *,const int x);
void salleSetY(Salle *,const int y);
void salleSetOccupe(Salle *,const int boccup);

#endif
