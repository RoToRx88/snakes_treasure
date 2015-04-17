#ifndef _JEU_H
#define _JEU_H

#include "terrain.h"
#include "personnage.h"
#include "serpent.h"
#include "temple.h"

struct sJeu
{
	Terrain ter;
	Personnage perso;
	Serpent serpentTab[4];
	Temple templeTab[4];
};

typedef struct sJeu Jeu;

void jeuInit(Jeu *);
/* on initialise le jeu en positionnant le personnage au centre, les serpents et les temples (contenant déjà les salles) sur le terrain.*/
void jeuLibere(Jeu *);
Terrain *jeuGetTerrainPtr(Jeu *);
Personnage *jeuGetPersoPtr(Jeu *);
Serpent *jeuGetSerpentPtr(Jeu *);
Temple *jeuGetTemplePtr(Jeu *);
const Terrain *jeuGetConstTerrainPtr(const Jeu *);
const Personnage *jeuGetConstPersoPtr(const Jeu *);
const Serpent *jeuGetConstSerpentPtr(const Jeu *);
const Temple *jeuGetConstTemplePtr(const Jeu *);

void jeuActionClavier(Jeu *j, const char);
void jeuEvolue(Jeu *pJeu);

#endif
