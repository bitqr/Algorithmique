#ifndef DEF_ARB
#define DEF_ARB

struct arbreBin{
	int cle;
	struct arbreBin *p;
	struct arbreBin *gauche;
	struct arbreBin *droit;
};

typedef struct arbreBin ARBREBINAIRE;


struct PILE{
    int taille;
    int sommet;
    ARBREBINAIRE **tableau;
};

typedef struct PILE PILE;

struct arbre{
	int cle;
	struct arbre *p;
	struct arbre *filsg;
	struct arbre *frered;
};

typedef struct arbre ARBRE;


void empiler(PILE *P,ARBREBINAIRE *x);
ARBREBINAIRE *depiler(PILE *P);
PILE *creer_pile(int taille);

void afficher_arbre_2(ARBREBINAIRE *A);
void afficher_arbre_3(ARBRE *A);
void afficher_arbre_4(ARBREBINAIRE *A);


#endif


