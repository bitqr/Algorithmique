#ifndef DEF_ABR
#define DEF_ABR

struct abr
{
	int cle;
	struct abr *p;
	struct abr *gauche;
	struct abr *droite;
};

typedef struct abr ABR;

struct PILE
{
	int taille;
	int sommet;
	ABR **tableau;
};

typedef struct PILE PILE;

void parcours_infixe(ABR *x);
void parcours_infixe_non_recursif(ABR *x);
void parcours_prefixe(ABR *x);
void parcours_postfixe(ABR *x);
ABR *creer_abr(int cle, ABR *p, ABR *d, ABR *g);
void empiler(PILE *P, ABR *x);
ABR *depiler(PILE *P);
PILE *creer_pile(int taille);

#endif
