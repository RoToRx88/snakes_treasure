#ifndef _SERPENT
#define _SERPENT

#include "element.h"


struct sPartie
{
  Element x;
  Element y;
  struct sPartie *suivant;
  struct sPartie *precedent;
};
typedef struct sPartie Partie;


struct sSerpent
{
  Partie *tete;
  Partie *queue;
};
typedef struct sSerpent Serpent;


void initialiserSerpent(Serpent * l);
/* Precondition : l non prealablement initialisee
   Postcondition : la liste l initialisee est vide */

int estVideSerpent(const Serpent * l);
/* Precondition : l prealablement initialisee et manipulee uniquement
                  a travers les operations du module
   Resultat : 1 si l est vide, 0 sinon */

unsigned int nbPartiesSerpent(const Serpent * l);
/* Precondition : l initialisee et manipulee uniquement a travers les
                  operations du module
   Resultat : nombre d'elements contenus dans la liste */


Element XiemeElementSerpent(const Serpent * l, unsigned int i);
/* Precondition : l n'est pas vide, et 0 <= i < nbElementsListe(l)
   Resultat : valeur X du i-eme element de la liste, sachant que les
   elements sont numerotes a partir de 0 */

Element YiemeElementSerpent(const Serpent * l, unsigned int i);
/* Precondition : l n'est pas vide, et 0 <= i < nbElementsListe(l)
   Resultat : valeur Y du i-eme element de la liste, sachant que les
   elements sont numerotes a partir de 0 */

void modifierIemeElementSerpent(Element PosX, Element PosY, const Serpent * l, unsigned int i);
/* Precondition : l n'est pas vide, et 0 <= i < nbElementsListe(l)
   Postcondition : e remplace le i-eme element de la liste, sachant que les
   elements sont numerotes a partir de 0 */


Partie * premiereCelluleSerpent(const Serpent * l);
/* Precondition : l initialisee et manipulee uniquement a travers les
                  operations du module
   Resultat : adresse de la cellule du premier element si l non vide,
              NULL sinon
   Attention : la liste l pourra ensuite etre modifiee a travers la
   connaissance de l'adresse de sa premiere cellule */


Partie * celluleSuivanteSerpent(const Partie *c, const Serpent * l);
/* Precondition : c adresse valide d'une Partie de la Serpent l
   Resultat : adresse de la cellule suivante si elle existe, NULL sinon
   Attention : la liste l pourra ensuite etre modifiee a travers la
   connaissance de l'adresse d'une de ses cellules */


void afficherSerpentGaucheDroite(const Serpent * l);
/* Precondition : l initialisee et manipulee uniquement a travers les
                  operations du module
   Postcondition : Affichage de tous les elements de l, en commencant
   par le premier */

void afficherSerpentDroiteGauche(const Serpent * l);
/* Precondition : l initialisee et manipulee uniquement a travers les
                  operations du module
   Postcondition : Affichage de tous les elements de l, en commencant
   par le dernier */

void ajouterEnTeteSerpent(Element PosX, Element PosY, Serpent * l);
/* Precondition : l et e initialises et manipules uniquement a travers les
                  operations de leurs modules respectifs
   Postcondition : e est ajoute en tete de l */

void ajouterEnQueueSerpent(Element PosX, Element PosY, Serpent * l);
/* Precondition : l et e initialises et manipules uniquement a travers les
                  operations de leurs modules respectifs
   Postcondition : e est ajoute en fin de la liste l */

void supprimerTeteSerpent(Serpent * l);
/* Precondition : l n'est pas vide
   Postcondition : la liste l perd son premier element */

void supprimerQueueSerpent(Serpent * l);
/* Precondition : l n'est pas vide
   Postcondition : la liste l perd son dernier element */

void viderSerpent(Serpent * l);
/* Precondition : l initialisee et manipulee uniquement a travers les
   operations du module
   Postcondition : l ne contient plus acune cellule */

void testamentSerpent(Serpent * l);
/* Precondition : l prealablement initialisee et manipulee uniquement
   a travers les operations du module
   Postcondition : l prete a etre detruite */


void affecterSerpent(Serpent * l1, Serpent * l2);
/* Precondition : l1 et l2 prealablement initialisees et manipulees uniquement
                  a travers les operations du module
   Postcondition : la liste l1 correspond a une copie de l2
   (mais les 2 listes sont totalement independantes l'une de l'autre) */


int rechercherElementSerpent(Element e, const Serpent *l);
/* Precondition : l initialisee et manipulee uniquement a travers les
   operations du module
   Resultat : Position de la premiere occurrence de e dans la liste (en
   partant de la gauche), -1 si e n'est pas dans la liste. Les cellules
   sont numerotees de 0 a n-1, donc une valeur de retour egale a 0
   signifie sue la premiere occurrence de e se trouve dans la premiere
   cellule de la liste. */

void insererPositonSerpent(Element posX, Element posY, Serpent * l, unsigned int position);
/* Preconditions : l initialisee et manipulee uniquement a travers les
   operations du module, 0 <= position <= nbElements(l)
   Postconditions : une copie independante de e est inseree de sorte a
   ce qu'elle occupe la position indiquee dans la liste l (les positions
   etant numerotees a partir de 0).*/


void deplacementAdroite(Serpent * l);
/* le serpent avance d'une case vers la droite */

void deplacementAgauche(Serpent * l);
/* le serpent avance d'une case vers la gauche */

void deplacementENhaut(Serpent * l);
/* le serpent avance d'une case vers le haut */

void deplacementENbas(Serpent * l);
/* le serpent avance d'une case vers le bas */

void deplacementSerp(Serpent *l);

void AgrandirSerpent(Serpent *l);
// initialise le serpent avec sa nouvelle longueur
#endif
