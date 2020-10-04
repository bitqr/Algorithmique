#ifndef DEF_ABR
#define DEF_ABR


struct abr{
	int cle;
	struct abr *p;
	struct abr *gauche;
	struct abr *droite;
	};
	
typedef struct abr ABR;

ABR * creer_abr(int cle, ABR *d, ABR *g);
ABR * arbre_rechercher_iteratif(ABR *x, int k);
ABR * arbre_minimum(ABR *x);
ABR * arbre_maximum(ABR *x);
ABR * arbre_successeur(ABR *x);
ABR * arbre_minimum_recursif(ABR *x);
ABR * arbre_maximum_recursif(ABR *x);
ABR * arbre_predecesseur(ABR *x);


#endif




	
