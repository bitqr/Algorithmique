#include "HUFF.h"

NOEUD_TERNAIRE *allouerNoeudTernaire()
{
	NOEUD_TERNAIRE *z = (NOEUD_TERNAIRE *)malloc(sizeof(NOEUD_TERNAIRE));
	z->gauche = NULL;
	z->centre = NULL;
	z->droite = NULL;
	return z;
}

FILE_DE_PRIORITE_TERNAIRE *creerTasTernaire(int longueur, int taille)
{
	FILE_DE_PRIORITE_TERNAIRE *t =
		(FILE_DE_PRIORITE_TERNAIRE *)malloc(sizeof(FILE_DE_PRIORITE_TERNAIRE));
	t->longueur = longueur;
	t->taille = taille;
	NOEUD_TERNAIRE **tab =
		(NOEUD_TERNAIRE **)malloc(longueur * sizeof(NOEUD_TERNAIRE *));
	int i;
	for (i = 0; i < longueur; i++)
	{
		tab[i] = allouerNoeudTernaire();
	}
	t->tableau = tab;
	return t;
}

void echangerTernaire(NOEUD_TERNAIRE **A, int a, int b)
{
	NOEUD_TERNAIRE *tmp = A[b];
	A[b] = A[a];
	A[a] = tmp;
}

void diminuerCleTasTernaire(FILE_DE_PRIORITE_TERNAIRE *fp, int i,
							NOEUD_TERNAIRE *x)
{
	NOEUD_TERNAIRE **A = fp->tableau;
	if (x->f > A[i]->f)
	{
		printf("Nouvelle cle plus grande que cle actuelle\n\n\n");
		exit(1);
	}
	A[i]->f = x->f;
	while ((i > 0) && (A[parent(i)]->f > A[i]->f))
	{
		echangerTernaire(A, i, parent(i));
		i = parent(i);
	}
}

void insererTernaire(FILE_DE_PRIORITE_TERNAIRE *fp, NOEUD_TERNAIRE *x)
{
	fp->taille++;
	fp->tableau[fp->taille - 1]->gauche = x->gauche;
	fp->tableau[fp->taille - 1]->centre = x->centre;
	fp->tableau[fp->taille - 1]->droite = x->droite;
	fp->tableau[fp->taille - 1]->f = INFINI;
	diminuerCleTasTernaire(fp, fp->taille - 1, x);
}

void entasserMinTernaire(FILE_DE_PRIORITE_TERNAIRE *fp, int i)
{
	int l = gauche(i);
	int r = droite(i);
	int min;
	NOEUD_TERNAIRE **A = fp->tableau;
	if ((l < fp->taille) && (A[l]->f < A[i]->f))
		min = l;
	else
		min = i;
	if ((r < fp->taille) && (A[r]->f < A[min]->f))
		min = r;
	if (min != i)
	{
		echangerTernaire(A, i, min);
		entasserMinTernaire(fp, min);
	}
}

NOEUD_TERNAIRE *extraireMinTernaire(FILE_DE_PRIORITE_TERNAIRE *fp)
{
	if (fp->taille < 1)
	{
		printf("Limite inferieure depassee\n\n\n");
		exit(1);
	}
	NOEUD_TERNAIRE **A = fp->tableau;
	NOEUD_TERNAIRE *min = allouerNoeudTernaire();
	min->f = A[0]->f;
	min->gauche = A[0]->gauche;
	min->centre = A[0]->centre;
	min->droite = A[0]->droite;
	A[0]->f = A[fp->taille - 1]->f;
	A[0]->gauche = A[fp->taille - 1]->gauche;
	A[0]->centre = A[fp->taille - 1]->centre;
	A[0]->droite = A[fp->taille - 1]->droite;
	fp->taille--;
	entasserMinTernaire(fp, 0);
	return min;
}

void affichagePrefixeTernaire(NOEUD_TERNAIRE *z)
{
	if (z != NULL)
	{
		printf("%d\n", z->f);
		affichagePrefixeTernaire(z->gauche);
		affichagePrefixeTernaire(z->centre);
		affichagePrefixeTernaire(z->droite);
	}
}

NOEUD_TERNAIRE *Huffman_ternaire(FILE_DE_PRIORITE_TERNAIRE *C)
{
	int n = C->taille;
	FILE_DE_PRIORITE_TERNAIRE *Q = C;
	int i;
	for (i = 1; i <= (n - 1) / 2 + (1 - n % 2); i++)
	{
		NOEUD_TERNAIRE *z = allouerNoeudTernaire();
		z->f = 0;
		NOEUD_TERNAIRE *x = extraireMinTernaire(Q);
		z->gauche = x;
		NOEUD_TERNAIRE *y = extraireMinTernaire(Q);
		z->centre = y;
		if (Q->taille >= 1)
		{
			NOEUD_TERNAIRE *t = extraireMinTernaire(Q);
			z->droite = t;
			z->f += t->f;
		}
		z->f += x->f + y->f;
		insererTernaire(Q, z);
		free(z);
	}
	return extraireMinTernaire(Q); // Retourner la racine de l'arborescence.
}
