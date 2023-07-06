#include "ARN.h"

void rn_inserer_correction(ARN *T, NOEUD *z)
{
	NOEUD *y;
	while (z->p->couleur == ROUGE)
	{
		if (z->p == z->p->p->gauche)
		{
			y = z->p->p->droite;
			if (y->couleur == ROUGE)
			{
				z->p->couleur = NOIR;	  // Cas 1
				y->couleur = NOIR;		  // Cas 1
				z->p->p->couleur = ROUGE; // Cas 1
				z = z->p->p;			  // Cas 1
			}
			else
			{
				if (z == z->p->droite)
				{
					z = z->p;			   // Cas 2
					rotation_gauche(T, z); // Cas 2
				}
				z->p->couleur = NOIR;		 // Cas 3
				z->p->p->couleur = ROUGE;	 // Cas 3
				rotation_droite(T, z->p->p); // Cas 3
			}
		}
		else
		{
			y = z->p->p->gauche;
			if (y->couleur == ROUGE)
			{
				z->p->couleur = NOIR;	  // Cas 1
				y->couleur = NOIR;		  // Cas 1
				z->p->p->couleur = ROUGE; // Cas 1
				z = z->p->p;			  // Cas 1
			}
			else
			{
				if (z == z->p->gauche)
				{
					z = z->p;			   // Cas 2
					rotation_droite(T, z); // Cas 2
				}
				z->p->couleur = NOIR;		 // Cas 3
				z->p->p->couleur = ROUGE;	 // Cas 3
				rotation_gauche(T, z->p->p); // Cas 3
			}
		}
	}
	T->racine->couleur = NOIR;
}
