#include "ARN.h"

NOEUDPOINT *rn_minimum(ARNP *T, NOEUDPOINT *x)
{
	if (x == T->nil || x->gauche == T->nil)
		return x;
	else
		return rn_minimum(T, x->gauche);
}

NOEUDPOINT *rn_maximum(ARNP *T, NOEUDPOINT *x)
{
	if (x == T->nil || x->droite == T->nil)
		return x;
	else
		return rn_maximum(T, x->droite);
}

NOEUDPOINT *rn_successeur(ARNP *T, NOEUDPOINT *x)
{
	if (x->droite != T->nil)
		return rn_minimum(T, x->droite);
	NOEUDPOINT *y = x->p;
	while (y != T->nil && x == y->droite)
	{
		x = y;
		y = y->p;
	}
	return y;
}

int appartient(ARNP *T, NOEUDPOINT *x1, NOEUDPOINT *x2)
{
	if (x1 == T->nil)
	{
		return 0;
	}
	if (x2 == x1)
	{
		return 1;
	}
	else if (x2->cle < x1->cle)
	{
		return appartient(T, x1->gauche, x2);
	}
	else
	{
		return appartient(T, x1->droite, x2);
	}
}

int intersection_meme_branche(NOEUDPOINT *x1, NOEUDPOINT *x2)
{
	int n = 0;
	NOEUDPOINT *s2 = x2;
	if (x1->cle < x2->cle)
	{
		while (x1 != x2)
		{
			if (x2 == x2->p->gauche)
			{
				n = n + x2->gauche->taille;
			}
			while (x2 == x2->p->gauche)
			{
				x2 = x2->p;
			}
			if (x2 == s2)
			{
				n += x2->gauche->taille;
			}
			x2 = x2->p;
			n++;
			if (x2 != x1)
			{
				if (x2 == x2->p->droite)
				{
					n += x2->gauche->taille;
				}
				if (x1 != x2->p)
				{
					n++;
				}
				x2 = x2->p;
			}
		}
	}
	else
	{
		while (x1 != x2)
		{
			if (x2 == x2->p->droite)
			{
				n = n + x2->droite->taille;
			}
			while (x2 == x2->p->droite)
			{
				x2 = x2->p;
			}
			if (x2 == s2)
			{
				n += x2->droite->taille;
			}
			x2 = x2->p;
			n++;
			if (x2 != x1)
			{
				if (x2 == x2->p->gauche)
				{
					n += x2->droite->taille;
				}
				if (x1 != x2->p)
				{
					n++;
				}
				x2 = x2->p;
			}
		}
	}
	return n - 2 * x2->doublon;
}

int intersection_branches_diff(ARNP *T, NOEUDPOINT *x1, NOEUDPOINT *x2)
{
	NOEUDPOINT *s1 = x1;
	int n = 0;
	if (x1->cle > T->racine->cle)
	{
		while (x1 && x1 != T->racine)
		{
			if (x1 == x1->p->gauche)
			{
				n = n + x1->gauche->taille;
			}
			while (x1->p && x1 == x1->p->gauche)
			{
				x1 = x1->p;
			}
			if (x1 == s1)
			{
				n += x1->gauche->taille;
			}
			x1 = x1->p;
			if (x1 && x1 != T->racine)
			{
				if (x1 == x1->p->droite)
				{
					n += x1->gauche->taille;
				}
				if (T->racine != x1->p)
				{
					n++;
				}
				x1 = x1->p;
			}
		}
	}
	else
	{
		while (x1 && x1 != T->racine)
		{
			if (x1 == x1->p->droite)
			{
				n = n + x1->droite->taille;
			}
			while (x1->p && x1 == x1->p->droite)
			{
				x1 = x1->p;
			}
			if (x1 == s1)
			{
				n += x1->droite->taille;
			}
			x1 = x1->p;
			if (x1 && x1 != T->racine)
			{
				if (x1 == x1->p->gauche)
				{
					n += x1->droite->taille;
				}
				if (T->racine != x1->p)
				{
					n++;
				}
				x1 = x1->p;
			}
		}
	}
	if (s1->cle > T->racine->cle)
	{
		return intersection_meme_branche(T->racine, x2) - n;
	}
	if (s1->cle < T->racine->cle && x2->cle < T->racine->cle)
	{
		return n - intersection_meme_branche(T->racine, x2);
	}
	else
	{
		return n + intersection_meme_branche(T->racine, x2);
	}
}

int intersections(ARNP *T, NOEUDPOINT *x1, NOEUDPOINT *x2)
{
	if (appartient(T, x1->droite, x2))
	{
		return intersection_meme_branche(x1, x2);
	}
	if (appartient(T, x2->gauche, x1))
	{
		return intersection_meme_branche(x1, x2);
	}
	if (x1 == x2)
	{
		return 0;
	}
	else
	{
		return intersection_branches_diff(T, x1, x2);
	}
}

int intersection_cordes(ARNP *T)
{
	NOEUDPOINT *x = rn_minimum(T, T->racine);
	int n = 0;
	while (x != T->nil)
	{
		if (x->cle < x->jumeau->cle)
		{
			n += intersections(T, x, x->jumeau);
		}
		x = rn_successeur(T, x);
	}
	return n / 2;
}

void rotation_gauchePoint(ARNP *T, NOEUDPOINT *x)
{
	NOEUDPOINT *y = x->droite; // initialise y.
	x->droite = y->gauche;	   // sous-arbre gauche de y devient sous-arbre droit de x.
	if (y->gauche != T->nil)
	{
		y->gauche->p = x;
	}
	y->p = x->p; // relie parent de x à y.
	if (x->p == T->nil)
	{
		T->racine = y;
	}
	else if (x == x->p->gauche)
	{
		x->p->gauche = y;
	}
	else
	{
		x->p->droite = y;
	}
	y->gauche = x; // place x à gauche de y.
	x->p = y;
	y->taille = x->taille;
	x->taille = x->gauche->taille + x->droite->taille + 1;
	T->racine->taille = T->racine->gauche->taille + T->racine->droite->taille + 1;
}

NOEUDPOINT *creerNoeudRNP(float cle, int etiq, NOEUDPOINT *g, NOEUDPOINT *d, int couleur, NOEUDPOINT *p)
{
	NOEUDPOINT *node = (NOEUDPOINT *)malloc(sizeof(NOEUDPOINT));
	node->cle = cle;
	node->gauche = g;
	node->droite = d;
	node->couleur = couleur;
	node->etiquette = etiq;
	node->taille = 0;
	node->p = p;
	return node;
}

ARNP *creerARNP(NOEUDPOINT *racine, NOEUDPOINT *nil)
{
	ARNP *a = (ARNP *)malloc(sizeof(ARNP));
	a->racine = racine;
	a->nil = nil;
	return a;
}

void rotation_droitePoint(ARNP *T, NOEUDPOINT *x)
{
	NOEUDPOINT *y = x->gauche; // initialise y.
	x->gauche = y->droite;	   // sous-arbre droit de y devient sous-arbre gauche de x.
	if (y->droite != T->nil)
	{
		y->droite->p = x;
	}
	y->p = x->p; // relie parent de x à y.
	if (x->p == T->nil)
	{
		T->racine = y;
		y->taille = y->gauche->taille + y->droite->taille + 1;
	}
	else if (x == x->p->gauche)
	{
		x->p->gauche = y;
	}
	else
	{
		x->p->droite = y;
	}
	y->droite = x; // place x à droite de y.
	x->p = y;
	y->taille = x->taille;
	x->taille = x->gauche->taille + x->droite->taille + 1;
	T->racine->taille = T->racine->gauche->taille + T->racine->droite->taille + 1;
}

void rn_inserer_correctionPoint(ARNP *T, NOEUDPOINT *z)
{
	NOEUDPOINT *y;
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
					z = z->p;					// Cas 2
					rotation_gauchePoint(T, z); // Cas 2
				}
				z->p->couleur = NOIR;			  // Cas 3
				z->p->p->couleur = ROUGE;		  // Cas 3
				rotation_droitePoint(T, z->p->p); // Cas 3
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
					z = z->p;					// Cas 2
					rotation_droitePoint(T, z); // Cas 2
				}
				z->p->couleur = NOIR;			  // Cas 3
				z->p->p->couleur = ROUGE;		  // Cas 3
				rotation_gauchePoint(T, z->p->p); // Cas 3
			}
		}
	}
	T->racine->couleur = NOIR;
}

void rn_insererPoint(ARNP *T, NOEUDPOINT *z)
{
	NOEUDPOINT *y = T->nil;
	NOEUDPOINT *x = T->racine;
	while (x != T->nil)
	{
		y = x;
		if (z->cle < x->cle)
		{
			x->taille++;
			x = x->gauche;
		}
		else
		{
			x->taille++;
			x = x->droite;
		}
	}
	z->p = y;
	if (y == T->nil)
		T->racine = z;
	else if (z->cle < y->cle)
		y->gauche = z;
	else
		y->droite = z;
	z->gauche = T->nil;
	z->droite = T->nil;
	z->couleur = ROUGE;
	z->taille = 1;
	rn_inserer_correctionPoint(T, z);
}

void parcoursPrefixePoint(ARNP *T, NOEUDPOINT *z)
{
	if (z != T->nil)
	{
		printf("%d (taille = %d)\n", z->etiquette, z->taille);
		printf("Gauche:\n");
		parcoursPrefixePoint(T, z->gauche);
		printf("Droite:\n");
		parcoursPrefixePoint(T, z->droite);
	}
}

int main(int argc, char **argv)
{
	NOEUDPOINT *nil = creerNoeudRNP(-1.0, -1, NULL, NULL, NOIR, NULL);
	NOEUDPOINT *rac = creerNoeudRNP(1.0, 2, nil, nil, NOIR, nil);
	rac->p = nil;
	ARNP *cordes = creerARNP(rac, nil);
	NOEUDPOINT *c1 = creerNoeudRNP(2.0, 3, nil, nil, ROUGE, nil);
	NOEUDPOINT *a1 = creerNoeudRNP(3.0, 1, nil, nil, ROUGE, nil);
	NOEUDPOINT *e1 = creerNoeudRNP(4.0, 5, nil, nil, ROUGE, nil);
	NOEUDPOINT *c2 = creerNoeudRNP(5.0, 3, nil, nil, ROUGE, nil);
	NOEUDPOINT *d1 = creerNoeudRNP(6.0, 4, nil, nil, ROUGE, nil);
	NOEUDPOINT *b2 = creerNoeudRNP(7.0, 2, nil, nil, ROUGE, nil);
	NOEUDPOINT *e2 = creerNoeudRNP(8.0, 5, nil, nil, ROUGE, nil);
	NOEUDPOINT *d2 = creerNoeudRNP(9.0, 4, nil, nil, ROUGE, nil);
	NOEUDPOINT *a2 = creerNoeudRNP(10.0, 1, nil, nil, ROUGE, nil);
	rn_insererPoint(cordes, c1);
	rn_insererPoint(cordes, a1);
	rn_insererPoint(cordes, e1);
	rn_insererPoint(cordes, c2);
	rn_insererPoint(cordes, d1);
	rn_insererPoint(cordes, b2);
	rn_insererPoint(cordes, e2);
	rn_insererPoint(cordes, d2);
	rn_insererPoint(cordes, a2);
	rac->jumeau = b2;
	b2->jumeau = rac;
	c1->jumeau = c2;
	c2->jumeau = c1;
	a1->jumeau = a2;
	a2->jumeau = a1;
	d1->jumeau = d2;
	d2->jumeau = d1;
	e1->jumeau = e2;
	e2->jumeau = e1;
	rac->doublon = b2->doublon = 1;
	c1->doublon = c2->doublon = 0;
	a1->doublon = a2->doublon = 2;
	d1->doublon = d2->doublon = 0;
	e1->doublon = e2->doublon = 0;
	printf("Le nombre de paires de cordes ayant une intersection est de %d\n\n", intersection_cordes(cordes));
	free(cordes);
	return 0;
}
