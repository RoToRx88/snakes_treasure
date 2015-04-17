#ifndef _ELEMENT
#define _ELEMENT


typedef int Element;

void afficherElement(Element e);

int estEgalElement(Element e1, Element e2);
/* Preconditions : aucune
   Resultat : renvoie 1 si e1 est egal a e2, 0 sinon */

int estInferieurElement(Element e1, Element e2);
/* Preconditions : aucune
   Resultat : renvoie 1 si e1 est strictement inferieur a e2, 0 sinon */


#endif
