#include <stdio.h>
#include <unistd.h>
#include "sdlJeu.h"
#include "personnage.h"
#include "salle.h"
#include "serpent.h"
#include "temple.h"
#include "terrain.h"
#include "tresor.h"

int main ( int argc, char** argv )
{
  
  sdlJeu sj;
  
  printf("[debug] sdlJeuInit start\n");
  sdljeuInit( &sj );
  printf("[debug]sdlJeuInit end\n");
  printf("[debug] sdlJeuBoucle start\n");
  sdljeuBoucle( &sj );
  printf("[debug] sdlJeuBoucle end\n");
  printf("[debug] sdlJeuLibere start");
  sdljeuLibere( &sj );
  printf("[debug] sdlJeuLibere end");
  printf("[debug] Ended");
  return 0;
}
