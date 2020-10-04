#include"B_ARBRE.h"

NOEUD_B_ARBRE *allouerNoeud(){
	return (NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
}

void creer_B_arbre(B_ARBRE *T){
	NOEUD_B_ARBRE *x=allouerNoeud();
	x->feuille=VRAI;
	x->n=0;
	ecrireDisque(x);
	T->racine=x;
}

void ecrireDisque(NOEUD_B_ARBRE *x){
	char s1[20];
	sprintf(s1,"%p.bab",x);	
	FILE *f=fopen(s1,"w");
	fprintf(f,"%d\n",x->n);
	int i;
	for(i=1;i<=x->n;i++)
		fprintf(f,"%d\n",x->cle[i-1]);
	if(x->feuille==VRAI)
		fprintf(f,"1\n");
	else{
		fprintf(f,"0\n");
		for(i=1;i<=x->n+1;i++)
			fprintf(f,"%p\n",x->c[i-1]);
	}
	fclose(f);
}


