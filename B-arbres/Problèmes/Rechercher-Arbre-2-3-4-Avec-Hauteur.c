#include "ARBRE_2_3_4.h"

char *copierPointeur234(NOEUD_ARBRE_2_3_4 *x)
{
	char *s1 = (char *)malloc(20 * sizeof(char));
	FILE *fichier = fopen("temp", "w");
	fprintf(fichier, "%p.234", x);
	fclose(fichier);
	fichier = fopen("temp", "r");
	fgets(s1, 20, fichier);
	fclose(fichier);
	system("rm temp");
	return s1;
}

void lireDisque(NOEUD_ARBRE_2_3_4 *x, int j)
{
	if (j >= x->n)
	{
		return;
	}
	char *s1 = copierPointeur234(x->c[j]);
	FILE *f = fopen(s1, "r");
	free(s1);
	char s[20];
	fgets(s, 20, f);
	x->c[j]->n = atoi(s);
	int i;
	fgets(s, 20, f);
	x->c[j]->hauteur = atoi(s);
	x->c[j]->cle = (int *)malloc(x->c[j]->n * sizeof(int));
	for (i = 1; i <= x->c[j]->n; i++)
	{
		fgets(s, 20, f);
		x->c[j]->cle[i - 1] = atoi(s);
	}
	fgets(s, 20, f);
	x->c[j]->feuille = atoi(s);
	if (x->c[j]->feuille == 0)
	{
		x->c[j]->c = (NOEUD_ARBRE_2_3_4 **)malloc((x->n + 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
		for (i = 1; i <= x->c[j]->n + 1; i++)
		{
			x->c[j]->c[i - 1] = (NOEUD_ARBRE_2_3_4 *)malloc(sizeof(NOEUD_ARBRE_2_3_4));
			void *p;
			fgets(s, 20, f);
			long adresse = strtol(s, NULL, 16);
			p = (void *)adresse;
			x->c[j]->c[i - 1] = (NOEUD_ARBRE_2_3_4 *)p;
		}
	}
	fclose(f);
}

NOEUD_ARBRE_2_3_4 *allouerNoeud()
{
	return (NOEUD_ARBRE_2_3_4 *)malloc(sizeof(NOEUD_ARBRE_2_3_4));
}

void ecrireDisque(NOEUD_ARBRE_2_3_4 *x)
{
	char *s1 = copierPointeur234(x);
	FILE *f = fopen(s1, "w");
	free(s1);
	fprintf(f, "%d\n", x->n);
	fprintf(f, "%d\n", x->hauteur);
	int i;
	for (i = 1; i <= x->n; i++)
	{
		fprintf(f, "%d\n", x->cle[i - 1]);
	}
	if (x->feuille == VRAI)
	{
		fprintf(f, "1\n");
	}
	else
	{
		fprintf(f, "0\n");
		for (i = 1; i <= x->n + 1; i++)
		{
			fprintf(f, "%p\n", x->c[i - 1]);
		}
	}
	fclose(f);
}

COUPLE *rechercher_arbre_2_3_4_avec_hauteur(NOEUD_ARBRE_2_3_4 *x, int k)
{
	int i = 1;
	while (i <= x->n && k > x->cle[i - 1])
	{
		i++;
	}
	if (i <= x->n && k == x->cle[i - 1])
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
		return rechercher_arbre_2_3_4_avec_hauteur(x->c[i - 1], k);
	}
}

int main(int argc, char **argv)
{
	NOEUD_ARBRE_2_3_4 *f1 = allouerNoeud();
	f1->n = 2;
	f1->cle = (int *)malloc(f1->n * sizeof(int));
	f1->cle[0] = 3;
	f1->cle[1] = 22;
	f1->feuille = 1;
	f1->hauteur = 0;
	ecrireDisque(f1);

	NOEUD_ARBRE_2_3_4 *f2 = allouerNoeud();
	f2->n = 3;
	f2->cle = (int *)malloc(f2->n * sizeof(int));
	f2->cle[0] = 50;
	f2->cle[1] = 60;
	f2->cle[2] = 95;
	f2->feuille = 1;
	f2->hauteur = 0;
	ecrireDisque(f2);

	NOEUD_ARBRE_2_3_4 *f3 = allouerNoeud();
	f3->n = 2;
	f3->cle = (int *)malloc(f3->n * sizeof(int));
	f3->cle[0] = 500;
	f3->cle[1] = 2000;
	f3->feuille = 1;
	f3->hauteur = 0;
	ecrireDisque(f3);

	NOEUD_ARBRE_2_3_4 *rac = (NOEUD_ARBRE_2_3_4 *)malloc(sizeof(NOEUD_ARBRE_2_3_4));
	rac->n = 2;
	rac->cle = (int *)malloc(rac->n * sizeof(int));
	rac->cle[0] = 29;
	rac->cle[1] = 100;
	rac->feuille = 0;
	rac->c = (NOEUD_ARBRE_2_3_4 **)malloc((rac->n + 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
	rac->c[0] = f1;
	rac->c[1] = f2;
	rac->c[2] = f3;
	rac->hauteur = 1;
	ecrireDisque(rac);

	ARBRE_2_3_4 *A = (ARBRE_2_3_4 *)malloc(sizeof(ARBRE_2_3_4));
	A->racine = rac;
	COUPLE *rech = rechercher_arbre_2_3_4_avec_hauteur(A->racine, K);
	if (rech == NIL)
	{
		printf("\nL'élément %d n'a pas été trouvé dans l'arbre 2-3-4.\n\n", K);
	}
	else
	{
		printf("\nL'élément %d a bien été trouvé au noeud d'adresse %p, à la clé en position %d.\n\n", K, rech->y, rech->i);
	}

	free(rech);
	inserer_arbre_2_3_4_avec_hauteur(A, 55);
	inserer_arbre_2_3_4_avec_hauteur(A, 1);

	supprimer_arbre_2_3_4_avec_hauteur(A, 3);
	supprimer_arbre_2_3_4_avec_hauteur(A, 60);
	supprimer_arbre_2_3_4_avec_hauteur(A, 100);
	supprimer_arbre_2_3_4_avec_hauteur(A, 55);
	supprimer_arbre_2_3_4_avec_hauteur(A, 2000);
	supprimer_arbre_2_3_4_avec_hauteur(A, 200);
	printf("Adresse de la racine de l'arbre 2-3-4 : %p.234\n", A->racine);

	int k = 2000;
	NOEUD_ARBRE_2_3_4 *rac2 = allouerNoeud();
	rac2->n = 1;
	rac2->cle = (int *)malloc(rac2->n * sizeof(int));
	rac2->cle[0] = 4000;
	rac2->feuille = VRAI;
	rac2->hauteur = 0;
	ecrireDisque(rac2);
	ARBRE_2_3_4 *A2 = (ARBRE_2_3_4 *)malloc(sizeof(ARBRE_2_3_4));
	A2->racine = rac2;

	ARBRE_2_3_4 *A3 = jointure_arbres_2_3_4(A, k, A2);
	printf("Adresse de la racine de l'arbre 2-3-4 résultant de la jointure : %p.234\n", A3->racine);

	NOEUD_ARBRE_2_3_4 *g1 = allouerNoeud();
	g1->n = 1;
	g1->cle = (int *)malloc(rac2->n * sizeof(int));
	g1->cle[0] = 6000;
	g1->feuille = VRAI;
	g1->hauteur = 0;
	ecrireDisque(g1);

	NOEUD_ARBRE_2_3_4 *g2 = allouerNoeud();
	g2->n = 1;
	g2->cle = (int *)malloc(rac2->n * sizeof(int));
	g2->cle[0] = 10000;
	g2->feuille = VRAI;
	g2->hauteur = 0;
	ecrireDisque(g2);

	int k2 = 5000;
	NOEUD_ARBRE_2_3_4 *rac3 = allouerNoeud();
	rac3->n = 1;
	rac3->cle = (int *)malloc(rac3->n * sizeof(int));
	rac3->cle[0] = 8000;
	rac3->feuille = FAUX;
	rac3->c = (NOEUD_ARBRE_2_3_4 **)malloc((rac3->n + 1) * sizeof(NOEUD_ARBRE_2_3_4 *));
	rac3->c[0] = g1;
	rac3->c[1] = g2;
	rac3->hauteur = 1;
	ecrireDisque(rac3);
	ARBRE_2_3_4 *A4 = (ARBRE_2_3_4 *)malloc(sizeof(ARBRE_2_3_4));
	A4->racine = rac3;

	ARBRE_2_3_4 *B4 = jointure_arbres_2_3_4(A3, k2, A4);
	printf("Adresse de la racine de l'arbre 2-3-4 résultant de la jointure : %p.234\n", B4->racine);

	COUPLE_ARBRES_APRES_SCISSION c2 = scission_arbre_2_3_4(B4, 5000);
	printf("Adresses des racines des arbres 2-3-4 résultant de ");
	printf("la scission : %p.234 et %p.234\n", c2.arbre1->racine, c2.arbre2->racine);

	return 0;
}
