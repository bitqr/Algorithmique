#include "Jos.h"

NOEUD *recuperer_rang(NOEUD *x, int i)
{
	int r = x->gauche->taille + 1;
	if (i == r)
	{
		return x;
	}
	else if (i < r)
	{
		return recuperer_rang(x->gauche, i);
	}
	else
	{
		return recuperer_rang(x->droite, i - r);
	}
}

NOEUD *creerNoeudRN(int cle, NOEUD *g, NOEUD *d, int couleur)
{
	NOEUD *node = (NOEUD *)malloc(sizeof(NOEUD));
	node->cle = cle;
	node->taille = 1 + g->taille + d->taille;
	node->gauche = g;
	node->droite = d;
	node->couleur = couleur;
	return node;
}

ARN *creerARN(NOEUD *racine, NOEUD *nil)
{
	ARN *a = (ARN *)malloc(sizeof(ARN));
	a->racine = racine;
	a->nil = nil;
	return a;
}

void rotation_gauche(ARN *T, NOEUD *x)
{
	NOEUD *y = x->droite;  // initialise y.
	x->droite = y->gauche; // sous-arbre gauche de y devient sous-arbre droit de x.
	if (y->gauche != T->nil)
		y->gauche->p = x;
	y->p = x->p; // relie parent de x � y.
	if (x->p == T->nil)
	{
		T->racine = y;
	}
	else if (x == x->p->gauche)
		x->p->gauche = y;
	else
		x->p->droite = y;
	y->gauche = x; // place x � gauche de y.
	x->p = y;
	y->taille = x->taille;
	x->taille = x->gauche->taille + x->droite->taille + 1;
	T->racine->taille = T->racine->gauche->taille + T->racine->droite->taille + 1;
}

void rotation_droite(ARN *T, NOEUD *x)
{
	NOEUD *y = x->gauche;  // initialise y.
	x->gauche = y->droite; // sous-arbre droit de y devient sous-arbre gauche de x.
	if (y->droite != T->nil)
		y->droite->p = x;
	y->p = x->p; // relie parent de x � y.
	if (x->p == T->nil)
	{
		T->racine = y;
		y->taille = y->gauche->taille + y->droite->taille + 1;
	}
	else if (x == x->p->gauche)
		x->p->gauche = y;
	else
		x->p->droite = y;
	y->droite = x; // place x � droite de y.
	x->p = y;
	y->taille = x->taille;
	x->taille = x->gauche->taille + x->droite->taille + 1;
	T->racine->taille = T->racine->gauche->taille + T->racine->droite->taille + 1;
}

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

void rn_inserer(ARN *T, NOEUD *z)
{
	NOEUD *y = T->nil;
	NOEUD *x = T->racine;
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
	rn_inserer_correction(T, z);
}

void rn_supprimer_correction(ARN *T, NOEUD *x)
{
	NOEUD *w;
	while (x != T->racine && x->couleur == NOIR)
	{
		if (x == x->p->gauche)
		{
			w = x->p->droite;
			if (w->couleur == ROUGE)
			{
				w->couleur = NOIR;		  // Cas 1
				x->p->couleur = ROUGE;	  // Cas 1
				rotation_gauche(T, x->p); // Cas 1
				w = x->p->droite;		  // Cas 1
			}
			if (w->gauche->couleur == NOIR && w->droite->couleur == NOIR)
			{
				w->couleur = ROUGE; // Cas 2
				x = x->p;			// Cas 2
			}
			else
			{
				if (w->droite->couleur == NOIR)
				{
					w->gauche->couleur = NOIR; // Cas 3
					w->couleur = ROUGE;		   // Cas 3
					rotation_droite(T, w);	   // Cas 3
					w = x->p->droite;		   // Cas 3
				}
				w->couleur = x->p->couleur; // Cas 4
				x->p->couleur = NOIR;		// Cas 4
				w->droite->couleur = NOIR;	// Cas 4
				rotation_gauche(T, x->p);	// Cas 4
				x = T->racine;				// Cas 4
			}
		}
		else
		{
			w = x->p->gauche;
			if (w->couleur == ROUGE)
			{
				w->couleur = NOIR;		  // Cas 1
				x->p->couleur = ROUGE;	  // Cas 1
				rotation_droite(T, x->p); // Cas 1
				w = x->p->gauche;		  // Cas 1
			}
			if (w->gauche->couleur == NOIR && w->droite->couleur == NOIR)
			{
				w->couleur = ROUGE; // Cas 2
				x = x->p;			// Cas 2
			}
			else
			{
				if (w->gauche->couleur == NOIR)
				{
					w->droite->couleur = NOIR; // Cas 3
					w->couleur = ROUGE;		   // Cas 3
					rotation_gauche(T, w);	   // Cas 3
					w = x->p->gauche;		   // Cas 3
				}
				w->couleur = x->p->couleur; // Cas 4
				x->p->couleur = NOIR;		// Cas 4
				w->gauche->couleur = NOIR;	// Cas 4
				rotation_droite(T, x->p);	// Cas 4
				x = T->racine;				// Cas 4
			}
		}
	}
	x->couleur = NOIR;
}

NOEUD *arbre_minimumTaille(NOEUD *x, NOEUD *nl)
{
	while (x->gauche != nl)
	{
		x->taille--;
		x = x->gauche;
	}
	return x;
}

NOEUD *arbre_successeurTaille(NOEUD *x, NOEUD *nl)
{
	if (x->droite != nl)
		return arbre_minimumTaille(x->droite, nl);
	NOEUD *y = x->p;
	while (y != nl && x == y->droite)
	{
		x = y;
		y = y->p;
	}
	return y;
}

NOEUD *rn_supprimer(ARN *T, NOEUD *z)
{
	NOEUD *y;
	NOEUD *x;
	if (z->gauche == T->nil || z->droite == T->nil)
	{
		y = z;
	}
	else
	{
		y = arbre_successeurTaille(z, T->nil);
	}
	if (y->gauche != T->nil)
	{
		x = y->gauche;
	}
	else
	{
		x = y->droite;
	}
	x->p = y->p;
	if (y->p == T->nil)
	{
		T->racine = x;
	}
	else if (y == y->p->gauche)
	{
		y->p->gauche = x;
	}
	else
	{
		y->p->droite = x;
	}
	if (y != z)
	{
		z->cle = y->cle;
		z->couleur = y->couleur;
	}
	z->taille = z->gauche->taille + z->droite->taille + 1;
	if (y->couleur == NOIR)
	{
		rn_supprimer_correction(T, x);
	}
	return y;
}

void supp(ARN *T, NOEUD *z)
{
	NOEUD *x = T->racine;
	while (x != z && x != T->nil)
	{
		x->taille--;
		x = (x->cle > z->cle) ? x->gauche : x->droite;
	}
	rn_supprimer(T, z);
}

void parcoursPrefixe(ARN *A, NOEUD *x)
{
	if (x != A->nil)
	{
		printf("%d(taille=%d) \n", x->cle, x->taille);
		printf("gauche:\n");
		parcoursPrefixe(A, x->gauche);
		printf("droite:\n");
		parcoursPrefixe(A, x->droite);
	}
}

int *josephus_efficace(int n, int m)
{
	NOEUD *s;
	NOEUD *nl = (NOEUD *)malloc(sizeof(NOEUD));
	nl->taille = 0;
	nl->couleur = NOIR;
	nl->gauche = nl->droite = nl->p = nl;
	nl->cle = -1;
	ARN *A = creerARN(nl, nl);
	int *T = (int *)calloc(n, sizeof(int));
	int i;
	for (i = 1; i <= n; i++)
	{
		NOEUD *node = (NOEUD *)malloc(sizeof(NOEUD));
		node->cle = i;
		rn_inserer(A, node);
	}
	int k = 0, nd = n, rang = m, e;
	while (nd > 1)
	{
		s = recuperer_rang(A->racine, rang);
		T[k] = s->cle;
		printf("%d\n", T[k]);
		supp(A, s);
		e = nd - rang;
		k++;
		if (e >= m)
			rang = rang + m - 1;
		else
		{
			if (e == 0)
				rang = m % (nd - 1) == 0 ? (nd - 1) : m % (nd - 1);
			else
				rang = (m - e) % (nd - 1) == 0 ? (nd - 1) : (m - e) % (nd - 1);
		}
		nd--;
	}
	s = recuperer_rang(A->racine, 1);
	T[k] = s->cle;
	free(A);
	printf("%d\n", T[k]);
	return T;
}
