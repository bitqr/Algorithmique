#ifndef DEF_LCC
#define DEF_LCC

#define M 8

struct Liste_Simplement_Chainee{
	int cle;
	struct Liste_Simplement_Chainee * suiv;
};

typedef struct Liste_Simplement_Chainee LSC;

LSC * creerElt(int cle);
int h(int cle,int m);
LSC * rechercher_hachage_chainee(LSC **T,int k,int m);
void supprimer_hachage_chainee(LSC **T,LSC *x,int m);

#endif 

