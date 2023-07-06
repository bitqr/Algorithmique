#include "VDCB.h"

SOLUTION *creerSol(NOEUD *x)
{
	SOLUTION *S = (SOLUTION *)malloc(sizeof(SOLUTION));
	S->employe = x;
	return S;
}

int presence(NOEUD *x, SOLUTION **C, int i)
{
	int k;
	for (k = 0; k <= i; k++)
	{
		if (C[k]->employe == x)
		{
			return k;
		}
	}
	return -1;
}

double calcul_solution(int *i, NOEUD *x, ARBRE *A, SOLUTION **C)
{
	if (x == A->nil)
	{
		return 0;
	}
	int p = presence(x, C, *i);
	if (p != -1)
	{
		return C[p]->cout;
	}
	*i = *i + 1;
	int ind = *i;
	C[ind]->employe = x;
	if (x->fils_gauche == A->nil)
	{
		C[ind]->cout = x->note;
	}
	else
	{
		double k, l;
		l = 0;
		k = x->note;
		NOEUD *y = x->fils_gauche;
		while (y != A->nil)
		{
			l += calcul_solution(i, y, A, C);
			y = y->frere_droite;
		}
		y = x->fils_gauche;
		NOEUD *z;
		while (y != A->nil)
		{
			z = y->fils_gauche;
			while (z != A->nil)
			{
				k += calcul_solution(i, z, A, C);
				z = z->frere_droite;
			}
			y = y->frere_droite;
		}
		C[ind]->cout = (k < l) ? l : k;
	}
	return C[ind]->cout;
}

SOLUTION **raout(ARBRE *A, int nb)
{
	SOLUTION **C = (SOLUTION **)malloc((nb + 1) * sizeof(SOLUTION *));
	int j, i = 0;
	for (j = 0; j < nb + 1; j++)
		C[j] = creerSol(A->nil);
	C[0] = creerSol(A->racine);
	C[0]->cout = 0;
	NOEUD *y = A->racine->fils_gauche;
	while (y != A->nil)
	{
		C[0]->cout += calcul_solution(&i, y, A, C);
		y = y->frere_droite;
	}
	return C;
}

NOEUD *creerNoeud(NOEUD *fils, char *nom, double note)
{
	NOEUD *x = (NOEUD *)malloc(sizeof(NOEUD));
	x->fils_gauche = fils;
	x->note = note;
	int l = strlen(nom);
	x->nom = malloc(l + 1);
	int i;
	for (i = 0; i < l; i++)
	{
		x->nom[i] = nom[i];
	}
	return x;
}

ARBRE *creerArbre(NOEUD *racine, NOEUD *nl)
{
	ARBRE *A = (ARBRE *)malloc(sizeof(ARBRE));
	A->racine = racine;
	A->nil = nl;
	return A;
}

int main(int argc, char **argv)
{
	NOEUD *nl = creerNoeud(NULL, "", 0);
	nl->frere_droite = nl;
	nl->p = nl;
	NOEUD *d = creerNoeud(nl, "Daniel", 12);
	NOEUD *e = creerNoeud(nl, "Beck", 3);
	NOEUD *f = creerNoeud(nl, "Bellman", 17);
	NOEUD *g = creerNoeud(nl, "Rivest", 11);
	d->frere_droite = e;
	e->frere_droite = f;
	f->frere_droite = g;
	g->frere_droite = nl;

	NOEUD *h = creerNoeud(nl, "Zack", 3);
	NOEUD *i = creerNoeud(nl, "Julie", 8);
	h->frere_droite = i;
	i->frere_droite = nl;

	NOEUD *j = creerNoeud(nl, "Zahia", 2);
	j->frere_droite = nl;

	NOEUD *k = creerNoeud(nl, "Rambo", 2);
	NOEUD *l = creerNoeud(nl, "Beyonce", 10);
	k->frere_droite = l;
	l->frere_droite = nl;

	NOEUD *m = creerNoeud(d, "Henry", 14);
	NOEUD *n = creerNoeud(h, "Bille", 4);
	NOEUD *o = creerNoeud(j, "Levy", 0);
	m->frere_droite = n;
	n->frere_droite = o;
	o->frere_droite = nl;
	d->p = e->p = f->p = g->p = m;
	h->p = i->p = n;
	j->p = o;

	NOEUD *p = creerNoeud(nl, "Payne", 11);
	NOEUD *q = creerNoeud(k, "Boyd", 3);
	NOEUD *r = creerNoeud(nl, "Lilly", 10);
	p->frere_droite = q;
	q->frere_droite = r;
	r->frere_droite = nl;
	k->p = q;

	NOEUD *a = creerNoeud(m, "Orson", 8);
	NOEUD *b = creerNoeud(p, "Elie", 7);
	NOEUD *rac = creerNoeud(a, "Boss", 10);
	a->frere_droite = b;
	b->frere_droite = nl;
	rac->frere_droite = nl;
	m->p = n->p = o->p = a;
	p->p = q->p = r->p = b;
	a->p = b->p = rac;
	rac->p = nl;

	ARBRE *A = creerArbre(rac, nl);

	SOLUTION **C = raout(A, NB);

	printf("\n\nLa solution optimale de convivialité pour ce raout a pour coût %f\n\n", C[0]->cout);
	return 0;
}
