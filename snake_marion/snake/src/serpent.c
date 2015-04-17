#include <stdlib.h>
#include <stdio.h>
#include "element.h"
#include "serpent.h"


void initialiserSerpent(Serpent * l)
{
	l -> tete = NULL;
	l -> queue = NULL;
}

unsigned int nbPartiesSerpent(const Serpent * l)
{
    int i=1;
	Partie * c;
	c=l->tete;
	while (c!=l->queue)
	{
		c=c->suivant;
		i++;
	}
	return i;
}


void ajouterEnTeteSerpent(Element PosX, Element PosY, Serpent * l) {
        Partie * temp;
        temp = malloc(sizeof(Partie));
        temp->precedent = NULL;
        temp->x = PosX;
        temp->y= PosY;
        if(estVideSerpent(l))
        {
                temp->suivant = NULL;
                l->queue = temp;
                l->tete = temp;
        }
        else
        {
                temp->suivant = l->tete;
                (l->tete)->precedent = temp;
        }
        l->tete  = temp;
}

 void ajouterEnQueueSerpent(Element PosX, Element PosY, Serpent * l)
{
	Partie * temp;
	temp = malloc(sizeof(Partie));
	temp-> suivant = NULL;
        temp->x = PosX;
	temp->y= PosY;
	if(estVideSerpent(l))
	{
		temp->precedent = NULL;
                l->tete = temp;
                l->queue = temp;
	}
	else
	{
	temp-> precedent = l->queue;
	(l->queue)-> suivant = temp;
	l-> queue =temp;
	}
}

int estVideSerpent(const Serpent * l)
{
	if(l->tete == NULL && l->queue == NULL)
	{ return 1;}
	else
	{return 0;}
}

Element XiemeElementSerpent(const Serpent * l, unsigned int i)
{
	int j =0;
	Partie * c;
	c=l->tete;
	while (j!=i)
	{
		c=c->suivant;
		j++;
	}
	return c->x;
}

Element YiemeElementSerpent(const Serpent * l, unsigned int i)
{
	int j =0;
	Partie * c;
	c=l->tete;
	while (j!=i)
	{
		c=c->suivant;
		j++;
	}
	return c->y;
}

Element* Xieme(const Serpent * l, unsigned int i)
{
	int j =0;
	Partie * c;
	c=l->tete;
	while (j!=i)
	{
		c=c->suivant;
		j++;
	}
	return &c->x;
}

Element* Yieme(const Serpent * l, unsigned int i)
{
	int j =0;
	Partie * c;
	c=l->tete;
	while (j!=i)
	{
		c=c->suivant;
		j++;
	}
	return &c->y;
}

void modifierIemeElementSerpent(Element PosX, Element PosY, const Serpent * l, unsigned int i)
{
	*Xieme( l, i)= PosX;
	*Yieme( l, i)= PosY;
}


void afficherSerpentGaucheDroite(const Serpent * l)
{
	Partie * c;
	c=l->tete;
	while (c != NULL)
	{
	printf("x : %d\n", c->x);
	printf("y :%d\n", c->y);
	c=c->suivant;
	}
}

void afficherSerpentDroiteGauche(const Serpent * l)
{
	Partie * c;
	c=l->queue;
	while (c != NULL)
	{
	printf("x : %d\n", c->x);
	printf("y :%d\n", c->y);
	c=c->precedent;
	}
}

void supprimerTeteSerpent(Serpent * l)
{
		Partie * temp;
                temp = l->tete;
                if(temp->suivant != NULL)
			{
                	l->tete= temp->suivant;
                	(l->tete)->precedent = NULL;
                }
                else {
                    l->tete = NULL;
                }
                free(temp);
}

void supprimerQueueSerpent(Serpent * l)
{
		Partie * temp;
                temp = l->queue;
                if(temp->precedent != NULL)
                {
                	l->queue= temp->precedent;
                	(l->queue)->suivant = NULL;
                }
                else
                {
                    l->queue = NULL;
                }
                free(temp);
}

void viderSerpent(Serpent * l)
{	Partie * c;
	Partie * temp;
	c=l->tete;
	while (c != NULL)
	{
		temp=c->suivant;
		free(c);
		c=temp;

	}
	l->tete= NULL;
	l->queue=NULL;
}

void testamentSerpent(Serpent * l)
{
	Partie * c;
	Partie * temp;
	c=l->tete;
	while (c != NULL)
	{
		temp=c->suivant;
		free(c);
		c=temp;

	}
}

void affecterSerpent(Serpent * l1, Serpent * l2)
{
	Partie * c1;
	Partie * temp;
	c1=l1->tete;
	while (c1 != NULL)
	{
		ajouterEnQueueSerpent(c1->x, c1->y, l2);
		temp=c1->suivant;
		free(c1);
		c1=temp;
	}
}


void insererPositonSerpent(Element posX, Element posY, Serpent * l, unsigned int position)
{
	Partie * nouv;
        nouv = (Partie*)malloc(sizeof(Partie));
        nouv->x = posX;
	nouv->y = posY;
	int j =0;
	Partie * c;
	c=l->tete;
	while (j!=position)
	{
		c=c->suivant;
		j++;
	}
	nouv->suivant=c;
	c->precedent=nouv;
	j=0;
	while (j!=position-1)
	{
		c=c->suivant;
		j++;
	}
	nouv->precedent=c;
	c->suivant=nouv;
}

void deplacementAdroite(Serpent *l)
{
    int a, b;
    supprimerQueueSerpent(l);
    a=l->tete->x;
    b=l->tete->y;
    ajouterEnTeteSerpent(a+1, b, l);

}

void deplacementAgauche(Serpent * l)
{
    int a, b;
    supprimerQueueSerpent(l);
    a=l->tete->x;
    b=l->tete->y;
    ajouterEnTeteSerpent(a-1, b, l);

}

void deplacementENhaut(Serpent * l)
{
    int a, b;
    supprimerQueueSerpent(l);
    a=l->tete->x;
    b=l->tete->y;
    ajouterEnTeteSerpent(a, b-1, l);

}

void deplacementENbas(Serpent * l)
{
    int a, b;
    supprimerQueueSerpent(l);
    a=l->tete->x;
    b=l->tete->y;
    ajouterEnTeteSerpent(a, b+1, l);

}

void deplacementSerp(Serpent *l)
{
    int X, Y ;
    X=l->tete->x ;
    Y=l->tete->y ;
    if((Y=1 && (X!=8 || X!=16)) || (Y=9 && (X!=8 || X!=16)))
    {
        deplacementAdroite(l);
    }
    else if ((Y=8 && (X!=8 || X!=16)) || (Y=16 && (X!=8 || X!=16)))
        {
            deplacementAgauche(l);
        }
        else if ((X=1 && (Y!=1 || Y!=9)) || (X=9 && (Y!=1 || Y!=9)) )
            {
                deplacementENhaut(l);
            }
            else
                {
                    deplacementENbas(l);
                }
}
