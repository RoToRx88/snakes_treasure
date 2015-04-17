#ifndef TRESOR_H
#define TRESOR_H

#include "terrain.h"


struct sTresor
{
    int x, y, valeur ;
    int prise;

};
typedef struct sTresor Tresor;

void tresorInit(Tresor *, int x, int y);
int tresorGetX(const Tresor *);
int tresorGetY(const Tresor *);
int tresorGetValeur(const Tresor *);
int tresorGetPrise(const Tresor *);
void tresorSetX(Tresor *,const int x);
void tresorSetY(Tresor *,const int y);
void tresorSetValeur(Tresor *,const int ivaleur);
void tresorSetPrise(Tresor *,const int bprise);

#endif
