#include"ARN_INT.h"

NOEUD *rechercher_intervalle(ARN *T, INTERVALLE *i){
	NOEUD *x = T->racine;
	while(x != T->nil && (i->fin < x->Int->debut || x->Int->fin < i->debut)){
		if(x->gauche != T->nil && x->gauche->max >= i->debut)
			x = x->gauche;
		else	
			x = x->droite;
	}
	return x;
}

NOEUD *creernoeudInt(INTERVALLE *Int,int couleur, NOEUD *g, NOEUD *d){
	NOEUD *n = (NOEUD *)malloc(sizeof(NOEUD));
	int m = g->max > d->max?g->max:d->max;
	n->max = Int->fin > m?Int->fin:m;
	n->Int = Int;
	n->cle = Int->debut;
	n->couleur = couleur;
	n->gauche = g;
	n->droite = d;
	return n;
}


ARN *creeArbInt(NOEUD *r, NOEUD *n){
	ARN *a = (ARN *)malloc(sizeof(ARN));
	a->racine = r;
	a->nil = n;
	return a;
}

void parcoursPrefixe(ARN *T, NOEUD *x){
	if(x != T->nil){
		printf("%d %d\n",x->cle,x->max);
		parcoursPrefixe(T,x->gauche);
		parcoursPrefixe(T,x->droite);
		}
}


int main(int argc, char ** argv){
	
	//Intervalle i
	INTERVALLE *i = creeInt(11,14);
	
	//Arbre T
	NOEUD *nl = (NOEUD *)malloc(sizeof(NOEUD));
	nl->couleur = NOIR;nl->max = 0;
	
	NOEUD *f1 = creernoeudInt(creeInt(0,3),ROUGE,nl,nl);
	NOEUD *f2 = creernoeudInt(creeInt(6,10),ROUGE,nl,nl);
	NOEUD *f3 = creernoeudInt(creeInt(15,23),NOIR,nl,nl); 
	NOEUD *f4 = creernoeudInt(creeInt(19,20),ROUGE,nl,nl);
	NOEUD *f5 = creernoeudInt(creeInt(26,26),ROUGE,nl,nl);
	NOEUD *n12 = creernoeudInt(creeInt(5,8),NOIR,f1,f2);
	NOEUD *n4 = creernoeudInt(creeInt(17,19),NOIR,nl,f4);
	NOEUD *n123 = creernoeudInt(creeInt(8,9),ROUGE,n12,f3);
	NOEUD *n45 = creernoeudInt(creeInt(25,30),ROUGE,n4,f5);
	NOEUD *rac = creernoeudInt(creeInt(16,21),NOIR,n123,n45);
	
	f1->p = f2->p = n12; n12->p = f3->p = n123; f4->p = n4; n4->p = f5->p = n45;
	n123->p = n45->p = rac; rac->p = nl; 
	
	ARN * T = creeArbInt(rac,nl);

	
	//Application de l'algorithme
	
	NOEUD * rech = rechercher_intervalle(T,i);

	if(rech == T->nil)
		printf("L'intervalle i=[%d,%d] ne coupe aucun autre intervalle dans T\n\n",i->debut,i->fin);
	else	
		printf("L'intervalle i=[%d,%d] se recoupe avec [%d,%d]\n\n",i->debut,i->fin,rech->Int->debut,rech->Int->fin);
	
	rotation_gauche(T,T->racine);
	printf("L'affichage du parcours prefixe resultant de la rotation gauche de T avec le couple (cle,max) de chaque noeud:\n\n");
	parcoursPrefixe(T,T->racine);
	
	printf("\n\n");
	
	NOEUD * rech2 = rechercher_intervalle_ouvert(T,i);
	
	
	if(rech2 == T->nil)
		printf("L'intervalle i=]%d,%d[ ne coupe aucun autre intervalle ouvert dans T\n\n",i->debut,i->fin);
	else	
		printf("L'intervalle i=]%d,%d[ se recoupe avec ]%d,%d[\n\n",i->debut,i->fin,rech2->Int->debut,rech2->Int->fin);
	
	INTERVALLE *j = creeInt(18,21);
	
	NOEUD * rech3 = rechercher_intervalle_avant(T,j);
	
	
	if(rech3 == T->nil)
		printf("L'intervalle j=[%d,%d] ne coupe aucun autre intervalle dans T\n\n",j->debut,j->fin);
	else	
		printf("L'intervalle j=[%d,%d] se recoupe avec [%d,%d]\n\n",j->debut,j->fin,rech3->Int->debut,rech3->Int->fin);
	
	
	return 0;
}
			
			
