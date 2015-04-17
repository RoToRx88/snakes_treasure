#ifndef _TERRAIN_H
#define _TERRAIN_H

struct sTerrain
{
	int dimx;
	int dimy;
	char **tab;
};
typedef struct sTerrain Terrain;


void terInit(Terrain *);
void terLibere(Terrain *);
int terEstPositionPersoValide(const Terrain *, const int x, const int y);
const char terGetXY(const Terrain *, const int x, const int y);
void terSetXY(const Terrain *, const int x, const int y, const char);
const int getDimX(const Terrain *);
const int getDimY(const Terrain *);

#endif
