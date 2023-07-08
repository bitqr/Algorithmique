#include "B_ARBRE.h"

NOEUD_B_ARBRE *allouerNoeud()
{
	return (NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
}

void creer_B_arbre(B_ARBRE *T)
{
	NOEUD_B_ARBRE *x = allouerNoeud();
	x->feuille = VRAI;
	x->n = 0;
	ecrireDisque(x);
	T->racine = x;
}

char *copierPointeur(NOEUD_B_ARBRE *x)
{
	char *s1 = (char *)malloc(20 * sizeof(char));
	FILE *fichier = fopen("temp", "w");
	fprintf(fichier, "%p.bab", x);
	fclose(fichier);
	fichier = fopen("temp", "r");
	fgets(s1, 20, fichier);
	fclose(fichier);
	system("rm temp");
	return s1;
}

void ecrireDisque(NOEUD_B_ARBRE *x)
{
	char *s1 = copierPointeur(x);
	FILE *f = fopen(s1, "w");
	free(s1);
	fprintf(f, "%d\n", x->n);
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
