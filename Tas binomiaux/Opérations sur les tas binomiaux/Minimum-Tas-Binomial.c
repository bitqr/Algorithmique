#include "TASBIN.h"

NOEUD_TAS_BINOMIAL *minimum_tas_binomial(TAS_BINOMIAL *T)
{
	NOEUD_TAS_BINOMIAL *y = NIL;
	NOEUD_TAS_BINOMIAL *x = T->tete;
	int min = INFINI;
	while (x != NIL)
	{
		if (x->cle < min)
		{
			min = x->cle;
			y = x;
		}
		x = x->frere;
	}
	return y;
}

int main(int argc, char **argv)
{
	TAS_BINOMIAL *T = creer_tas_binomial();
	NOEUD_TAS_BINOMIAL *x = creerNoeudTasBinomial(8, NIL, NIL, 0, NIL);
	T->tete = x;
	NOEUD_TAS_BINOMIAL *y = minimum_tas_binomial(T);
	printf("La clé minimale est égale à %d.\n", y->cle);
	TAS_BINOMIAL *U = creer_tas_binomial();
	NOEUD_TAS_BINOMIAL *x1 = creerNoeudTasBinomial(2, NIL, NIL, 0, NIL);
	U->tete = x1;
	lien_binomial(x, x1);
	printf("\n");
	afficherArbreBinomial(x1, 1);

	TAS_BINOMIAL *T1 = creer_tas_binomial();
	TAS_BINOMIAL *T2 = creer_tas_binomial();

	NOEUD_TAS_BINOMIAL *x33 = creerNoeudTasBinomial(33, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x41 = creerNoeudTasBinomial(41, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *filsvh = creerNoeudTasBinomial(28, NIL, x41, 1, x33);
	NOEUD_TAS_BINOMIAL *filsvc = creerNoeudTasBinomial(25, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *racine3 = creerNoeudTasBinomial(15, NIL, filsvh, 2, NIL);
	NOEUD_TAS_BINOMIAL *racine2 = creerNoeudTasBinomial(7, NIL, filsvc, 1, racine3);
	NOEUD_TAS_BINOMIAL *racine1 = creerNoeudTasBinomial(12, NIL, NIL, 0, racine2);
	x33->p = racine3;
	filsvh->p = racine3;
	x41->p = filsvh;
	filsvc->p = racine2;
	T1->tete = racine1;

	NOEUD_TAS_BINOMIAL *x44 = creerNoeudTasBinomial(44, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x17 = creerNoeudTasBinomial(17, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x31 = creerNoeudTasBinomial(31, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x50 = creerNoeudTasBinomial(50, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x22 = creerNoeudTasBinomial(22, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x24 = creerNoeudTasBinomial(24, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x32 = creerNoeudTasBinomial(32, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x55 = creerNoeudTasBinomial(55, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *x10 = creerNoeudTasBinomial(10, NIL, x17, 1, x44);
	NOEUD_TAS_BINOMIAL *x48 = creerNoeudTasBinomial(48, NIL, x50, 1, x31);
	NOEUD_TAS_BINOMIAL *x23 = creerNoeudTasBinomial(23, NIL, x24, 1, x22);
	NOEUD_TAS_BINOMIAL *x45 = creerNoeudTasBinomial(45, NIL, x55, 1, x32);
	NOEUD_TAS_BINOMIAL *x29 = creerNoeudTasBinomial(29, NIL, x48, 2, x10);
	NOEUD_TAS_BINOMIAL *x30 = creerNoeudTasBinomial(30, NIL, x45, 2, x23);
	NOEUD_TAS_BINOMIAL *x8 = creerNoeudTasBinomial(8, NIL, x30, 3, x29);
	NOEUD_TAS_BINOMIAL *x37 = creerNoeudTasBinomial(37, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *racine6 = creerNoeudTasBinomial(6, NIL, x8, 4, NIL);
	NOEUD_TAS_BINOMIAL *racine5 = creerNoeudTasBinomial(3, NIL, x37, 1, racine6);
	NOEUD_TAS_BINOMIAL *racine4 = creerNoeudTasBinomial(18, NIL, NIL, 0, racine5);
	x37->p = racine5;
	x8->p = racine6;
	x29->p = racine6;
	x10->p = racine6;
	x44->p = racine6;
	x30->p = x8;
	x23->p = x8;
	x22->p = x8;
	x32->p = x30;
	x45->p = x30;
	x48->p = x29;
	x31->p = x29;
	x55->p = x45;
	x24->p = x23;
	x50->p = x48;
	x17->p = x10;
	T2->tete = racine4;

	printf("\n\nTas binomial T_1 :\n");
	afficherTasBinomial(T1);
	printf("\n\nTas binomial T_2 :\n");
	afficherTasBinomial(T2);

	TAS_BINOMIAL *T3 = union_tas_binomiaux(T1, T2);
	printf("\n\nAprès union de T_1 et T_2 :\n");
	afficherTasBinomial(T3);

	NOEUD_TAS_BINOMIAL *z = creerNoeudTasBinomial(101, NIL, NIL, 0, NIL);
	tas_binomial_inserer(&T3, z);
	printf("\n\nAprès insertion d'une nouvelle clé :\n");
	afficherTasBinomial(T3);

	NOEUD_TAS_BINOMIAL *xmin = tas_binomial_extraire_min(&T3);
	if (xmin != NIL)
	{
		printf("\n\nAprès extraction de la clé minimale %d :\n", xmin->cle);
		afficherTasBinomial(T3);
	}

	TAS_BINOMIAL *T4 = creer_tas_binomial();

	NOEUD_TAS_BINOMIAL *y25 = creerNoeudTasBinomial(25, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y18 = creerNoeudTasBinomial(18, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y23 = creerNoeudTasBinomial(23, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y42 = creerNoeudTasBinomial(42, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y29 = creerNoeudTasBinomial(29, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y38 = creerNoeudTasBinomial(38, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y17 = creerNoeudTasBinomial(17, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y27 = creerNoeudTasBinomial(27, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y12 = creerNoeudTasBinomial(12, NIL, y18, 1, y25);
	NOEUD_TAS_BINOMIAL *y26 = creerNoeudTasBinomial(26, NIL, y42, 1, y23);
	NOEUD_TAS_BINOMIAL *y14 = creerNoeudTasBinomial(14, NIL, y38, 1, y29);
	NOEUD_TAS_BINOMIAL *y11 = creerNoeudTasBinomial(11, NIL, y27, 1, y17);
	NOEUD_TAS_BINOMIAL *y16 = creerNoeudTasBinomial(16, NIL, y26, 2, y12);
	NOEUD_TAS_BINOMIAL *y8 = creerNoeudTasBinomial(8, NIL, y11, 2, y14);
	NOEUD_TAS_BINOMIAL *y13 = creerNoeudTasBinomial(13, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y77 = creerNoeudTasBinomial(77, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *y6 = creerNoeudTasBinomial(6, NIL, y8, 3, y16);
	NOEUD_TAS_BINOMIAL *y28 = creerNoeudTasBinomial(28, NIL, y77, 1, y13);
	NOEUD_TAS_BINOMIAL *y41 = creerNoeudTasBinomial(41, NIL, NIL, 0, NIL);
	NOEUD_TAS_BINOMIAL *r3 = creerNoeudTasBinomial(1, NIL, y6, 4, NIL);
	NOEUD_TAS_BINOMIAL *r2 = creerNoeudTasBinomial(10, NIL, y28, 2, r3);
	NOEUD_TAS_BINOMIAL *r1 = creerNoeudTasBinomial(37, NIL, y41, 1, r2);
	y41->p = r1;
	y28->p = r2;
	y13->p = r2;
	y6->p = r3;
	y16->p = r3;
	y12->p = r3;
	y25->p = r3;
	y77->p = y28;
	y8->p = y6;
	y14->p = y6;
	y29->p = y6;
	y26->p = y16;
	y23->p = y16;
	y18->p = y12;
	y11->p = y8;
	y17->p = y8;
	y38->p = y14;
	y42->p = y26;
	y27->p = y11;
	T4->tete = r1;

	printf("\n\nTas binomial T_4 :\n");
	afficherTasBinomial(T4);
	NOEUD_TAS_BINOMIAL *xmin2 = tas_binomial_extraire_min(&T4);
	if (xmin2 != NIL)
	{
		printf("\n\nAprès extraction de la clé minimale %d:\n", xmin2->cle);
		afficherTasBinomial(T4);
	}

	printf("\n\nAprès diminution de la clé du noeud (%d) :\n", y26->cle);
	tas_binomial_diminuer_cle(T4, y26, 7);
	afficherTasBinomial(T4);

	printf("\n\nAprès suppression du noeud (%d) :\n", r1->cle);
	tas_binomial_supprimer(&T4, r1);
	afficherTasBinomial(T4);

	NOEUD_TAS_BINOMIAL *z0 = creerNoeudTasBinomial(INFINI, NIL, NIL, 0, NIL);
	TAS_BINOMIAL *V = creer_tas_binomial();
	V->tete = z0;
	NOEUD_TAS_BINOMIAL *min1 = minimum_tas_binomial(V);
	NOEUD_TAS_BINOMIAL *min2 = minimum_tas_binomial_avec_infini(V);
	if (min1 == NIL)
	{
		printf("\n\nLe minimum n'a pas été trouvé\n");
	}
	else
	{
		printf("\n\nLe minimum a pour clé %d\n", min1->cle);
	}
	if (min2 == NIL)
	{
		printf("\n\nLe minimum n'a pas été trouvé en considérant l'infini\n");
	}
	else
	{
		printf("\n\nLe minimum a pour clé %d en considérant l'infini\n", min2->cle);
	}

	printf("\n\nAprès suppression du noeud (%d) :\n", T4->tete->frere->enfant->enfant->enfant->cle);
	tas_binomial_supprimer_sans_infini(&T4, T4->tete->frere->enfant->enfant->enfant);
	afficherTasBinomial(T4);

	NOEUD_TAS_BINOMIAL *nn = creerNoeudTasBinomial(69, NIL, NIL, 0, NIL);
	tas_binomial_inserer_direct(T4, nn);
	printf("\n\nAprès insertion directe de la clé %d :\n", nn->cle);
	afficherTasBinomial(T4);

	return 0;
}
