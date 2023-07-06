#include "AVL.h"

void avl_inserer(AVL *T, NOEUD *x, NOEUD *z)
{
	if (x == T->nil)
	{
		x = z;
		printf("Insertion dans un sous-arbre vide de %d\n", x->cle);
		z->p = T->nil;
	}
	else if (x->gauche == T->nil && x->droite == T->nil)
	{
		if (z->cle < x->cle)
		{
			x->gauche = z;
		}
		else
		{
			x->droite = z;
		}
		z->p = x;
		while (x != T->nil)
		{
			x->h = 1 + max(x->gauche->h, x->droite->h);
			equilibre(T, x);
			x = x->p;
		}
	}
	else
	{
		if (z->cle < x->cle)
		{
			avl_inserer(T, x->gauche, z);
		}
		else
		{
			avl_inserer(T, x->droite, z);
		}
	}
}
