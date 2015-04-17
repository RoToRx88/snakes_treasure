#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "terrain.h"

struct sPersonnage
{
    int x, y;
};
typedef struct sPersonnage Personnage;

void persoInit(Personnage *, const Terrain *);
void persoGauche(Personnage *, const Terrain *);
void persoDroite(Personnage *, const Terrain *);
void persoHaut(Personnage *, const Terrain *);
void persoBas(Personnage *, const Terrain *);
int persoGetX(const Personnage *);
int persoGetY(const Personnage *);
void persoSetX(Personnage *,const int x);
void persoSetY(Personnage *,const int y);


#endif
