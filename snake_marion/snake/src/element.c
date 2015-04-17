#include <stdio.h>
#include "element.h"

void afficherElement(Element e)
{
  printf("%d\n", e);
}


int estEgalElement(Element e1, Element e2)
{
  if (e1 == e2) return 1;
  else return 0;
}



int estInferieurElement(Element e1, Element e2)
{
  if (e1 < e2) return 1;
  else return 0;
}
