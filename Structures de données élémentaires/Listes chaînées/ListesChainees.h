#ifndef DEF_LC
#define DEF_LC

struct Liste_Simplement_Chaine_Circulaire
{
	int cle;
	struct Liste_Simplement_Chaine_Circulaire *suiv;
	struct Liste_Simplement_Chaine_Circulaire *tete;
};

typedef struct Liste_Simplement_Chaine_Circulaire LSCC;

void afficherLSCC(LSCC *L);

LSCC *creerElement(int x);

void inserer(LSCC *L, int x);

void supprimer(LSCC *L, int x);

LSCC *rechercher(LSCC *L, int k);

void inverser(LSCC *L);

#endif
