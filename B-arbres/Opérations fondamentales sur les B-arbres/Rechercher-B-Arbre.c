#include "B_ARBRE.h"

COUPLE *rechercher_B_arbre(NOEUD_B_ARBRE *x, int k)
{
	int i = 1;
	while ((i <= x->n) && (k > x->cle[i - 1]))
	{
		i = i + 1;
	}
	if ((i <= x->n) && (k == x->cle[i - 1]))
	{
		COUPLE *r = (COUPLE *)malloc(sizeof(COUPLE));
		r->y = x;
		r->i = i;
		return r;
	}
	if (x->feuille)
	{
		return NIL;
	}
	else
	{
		lireDisque(x, i - 1);
		return rechercher_B_arbre(x->c[i - 1], k);
	}
}

void lireDisque(NOEUD_B_ARBRE *x, int j)
{
	char s1[20];
	sprintf(s1, "%p.bab", x->c[j]);
	FILE *f = fopen(s1, "r");
	fscanf(f, "%d\n", &(x->c[j]->n));
	int i;
	x->cle = (int *)malloc(x->c[j]->n * sizeof(int));
	for (i = 1; i <= x->c[j]->n; i++)
	{
		fscanf(f, "%d\n", &(x->c[j]->cle[i - 1]));
	}
	fscanf(f, "%d\n", &(x->c[j]->feuille));
	if (x->c[j]->feuille == 0)
	{
		x->c[j]->c = (NOEUD_B_ARBRE **)malloc((x->c[j]->n + 1) * sizeof(NOEUD_B_ARBRE *));
		for (i = 1; i <= x->c[j]->n + 1; i++)
		{
			x->c[j]->c[i - 1] = (NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
			void *p;
			fscanf(f, "%p\n", &p);
			x->c[j]->c[i - 1] = (NOEUD_B_ARBRE *)p;
		}
	}
	fclose(f);
}

int main(int argc, char **argv)
{
	NOEUD_B_ARBRE *f1 = (NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	f1->n = 2;
	f1->cle = (int *)malloc(f1->n * sizeof(int));
	f1->cle[0] = 3;
	f1->cle[1] = 22;
	f1->feuille = 1;
	ecrireDisque(f1);

	NOEUD_B_ARBRE *f2 = (NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	f2->n = 3;
	f2->cle = (int *)malloc(f2->n * sizeof(int));
	f2->cle[0] = 50;
	f2->cle[1] = 60;
	f2->cle[2] = 95;
	f2->feuille = 1;
	ecrireDisque(f2);

	NOEUD_B_ARBRE *f3 = (NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	f3->n = 2;
	f3->cle = (int *)malloc(f3->n * sizeof(int));
	f3->cle[0] = 500;
	f3->cle[1] = 2000;
	f3->feuille = 1;
	ecrireDisque(f3);

	NOEUD_B_ARBRE *rac = (NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	rac->n = 2;
	rac->cle = (int *)malloc(rac->n * sizeof(int));
	rac->cle[0] = 29;
	rac->cle[1] = 100;
	rac->feuille = 0;
	rac->c = (NOEUD_B_ARBRE **)malloc((rac->n + 1) * sizeof(NOEUD_B_ARBRE *));
	rac->c[0] = f1;
	rac->c[1] = f2;
	rac->c[2] = f3;
	ecrireDisque(rac);

	B_ARBRE *A = (B_ARBRE *)malloc(sizeof(B_ARBRE));
	A->racine = rac;
	COUPLE *rech = rechercher_B_arbre(A->racine, K);
	if (rech == NIL)
	{
		printf("\nL'élément %d n'a pas été trouvé dans le B-arbre.\n\n", K);
	}
	else
	{
		printf("\nL'élément %d a bien été trouvé au noeud d'adresse %p, à la clé en position %d.\n\n", K, rech->y, rech->i);
	}

	free(rech);
	B_ARBRE *T = (B_ARBRE *)malloc(sizeof(B_ARBRE));
	creer_B_arbre(T);
	printf("Un arbre a ete créé et sa racine contient %d clé(s)\n\n", T->racine->n);

	inserer_B_arbre(A, 55);
	int min = minimum_B_arbre(A);
	printf("La clé minimale est %d\n", min);
	int pred1 = predecesseur_B_arbre(A, 95);
	printf("Le prédécesseur de la clé 95 est %d\n", pred1);

	inserer_B_arbre(A, 1);
	min = minimum_B_arbre(A);
	printf("La nouvelle clé minimale est %d\n", min);
	int pred2 = predecesseur_B_arbre(A, 3);
	printf("Le prédécesseur de la clé 3 est %d\n\n", pred2);

	return 0;
}
