#include"TAS_2_3_4.h"

NOEUD_TAS_2_3_4 *minimum(TAS_2_3_4 *T){
	NOEUD_TAS_2_3_4 *x=T->racine;
	while(!x->feuille){
		NOEUD_TAS_2_3_4 *min=x->c[0];
		int i;
		for(i=1;i<x->n+1;i++){
			if((x->c[i]->feuille && x->c[i]->cle==x->petit) || (!x->c[i]->feuille && x->c[i]->petit==x->petit)){
				min=x->c[i];
			}
		}
		x=min;
	}
	return x;
}

void afficherTas234(TAS_2_3_4 *T){
	if(T->racine!=NIL){
		afficherNoeudTas234(T->racine,0);
	}
	else{
		printf("[Tas 2-3-4 Vide]");
	}
}

void afficherNoeudTas234(NOEUD_TAS_2_3_4 *x, int profondeur){
	int i;
	for(i=0;i<profondeur;i++){
		printf("\t");
	}
	if(!x->feuille){
		printf("Noeud interne : [petit=%d, %d enfant(s)]\n",x->petit,x->n+1);
		int j;
		for(j=0;j<x->n+1;j++){
			afficherNoeudTas234(x->c[j],profondeur+1);
		}
	}
	else{
		printf("Feuille : [clé=%d]\n", x->cle);
	}
}

int main(int argc, char **argv){
	NOEUD_TAS_2_3_4 *f1=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f1->feuille=VRAI;
	f1->cle=4;
	f1->n=1;
	NOEUD_TAS_2_3_4 *f2=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f2->feuille=VRAI;
	f2->cle=2;
	f2->n=1;
	NOEUD_TAS_2_3_4 *f3=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f3->feuille=VRAI;
	f3->cle=3;
	f3->n=1;
	NOEUD_TAS_2_3_4 *f4=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f4->feuille=VRAI;
	f4->cle=7;
	f4->n=1;
	NOEUD_TAS_2_3_4 *f5=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f5->feuille=VRAI;
	f5->cle=8;
	f5->n=1;
	NOEUD_TAS_2_3_4 *f6=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f6->feuille=VRAI;
	f6->cle=9;
	f6->n=1;
	NOEUD_TAS_2_3_4 *f7=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f7->feuille=VRAI;
	f7->cle=6;
	f7->n=1;
	NOEUD_TAS_2_3_4 *f8=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f8->feuille=VRAI;
	f8->cle=11;
	f8->n=1;
	NOEUD_TAS_2_3_4 *f9=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	f9->feuille=VRAI;
	f9->cle=5;
	f9->n=1;
	NOEUD_TAS_2_3_4 *x1=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	x1->feuille=FAUX;
	x1->petit=2;
	x1->n=2;
	x1->c=(NOEUD_TAS_2_3_4 **) malloc(3*sizeof(NOEUD_TAS_2_3_4 *));
	x1->c[0]=f1;
	x1->c[1]=f2;
	x1->c[2]=f3;
	f1->p=x1;
	f2->p=x1;
	f3->p=x1;
	NOEUD_TAS_2_3_4 *x2=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	x2->feuille=FAUX;
	x2->petit=7;
	x2->n=1;
	x2->c=(NOEUD_TAS_2_3_4 **) malloc(2*sizeof(NOEUD_TAS_2_3_4 *));
	x2->c[0]=f4;
	x2->c[1]=f5;
	f4->p=x2;
	f5->p=x2;
	NOEUD_TAS_2_3_4 *x3=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	x3->feuille=FAUX;
	x3->petit=5;
	x3->n=3;
	x3->c=(NOEUD_TAS_2_3_4 **) malloc(4*sizeof(NOEUD_TAS_2_3_4 *));
	x3->c[0]=f6;
	x3->c[1]=f7;
	x3->c[2]=f8;
	x3->c[3]=f9;
	f6->p=x3;
	f7->p=x3;
	f8->p=x3;
	f9->p=x3;
	NOEUD_TAS_2_3_4 *r=(NOEUD_TAS_2_3_4 *) malloc(sizeof(NOEUD_TAS_2_3_4));
	r->feuille=FAUX;
	r->petit=2;
	r->n=2;
	r->c=(NOEUD_TAS_2_3_4 **) malloc(3*sizeof(NOEUD_TAS_2_3_4 *));
	r->c[0]=x1;
	r->c[1]=x2;
	r->c[2]=x3;
	x1->p=r;
	x2->p=r;
	x3->p=r;
	r->hauteur=2;
	TAS_2_3_4 *T1=(TAS_2_3_4 *) malloc(sizeof(TAS_2_3_4));
	T1->racine=r;
	NOEUD_TAS_2_3_4 *min=minimum(T1);
	printf("\n\nSoit T1 le tas 2-3-4 suivant :\n\n");
	afficherTas234(T1);
	printf("\n\nLe noeud de clé minimale est une feuille de clé %d\n\n",min->cle);
	printf("\n\nAprès diminution de clé pour la feuille de clé %d, qui prend la clé %d :\n\n",f8->cle,CLEDIMINUEE);
	diminuer_cle(T1,f8,4);
	afficherTas234(T1);
	printf("\n\n");
	inserer(T1,10);
	printf("\n\nAprès insertion de la clé 10:\n\n");
	afficherTas234(T1);
	inserer(T1,1);
	printf("\n\nAprès insertion de la clé 1:\n\n");
	afficherTas234(T1);
	inserer(T1,0);
	printf("\n\nAprès insertion de la clé 0:\n\n");
	afficherTas234(T1);
	supprimer(T1,T1->racine->c[1]->c[1]->c[1]);
	printf("\n\nAprès suppression de la clé 10:\n\n");
	afficherTas234(T1);
	supprimer(T1,T1->racine->c[0]->c[0]->c[0]);
	printf("\n\nAprès suppression de la clé 4:\n\n");
	afficherTas234(T1);
	supprimer(T1,T1->racine->c[0]->c[0]->c[0]);
	printf("\n\nAprès suppression de la clé 2:\n\n");
	afficherTas234(T1);
	supprimer(T1,T1->racine->c[0]->c[1]->c[0]);
	printf("\n\nAprès suppression de la clé 7:\n\n");
	afficherTas234(T1);
	NOEUD_TAS_2_3_4 *y=extraire_min(T1);
	printf("\n\nAprès extraction de la clé minimale %d:\n\n",y->cle);
	afficherTas234(T1);
	TAS_2_3_4 *T2=(TAS_2_3_4 *)malloc(sizeof(TAS_2_3_4));
	NOEUD_TAS_2_3_4 *r2=allouerNoeud();
	r2->feuille=VRAI;
	r2->n=0;
	r2->hauteur=0;
	T2->racine=r2;
	printf("\n\n\n\nSoit un tas 2-3-4 vide T2.\n\n");
	inserer(T2,2);
	printf("\n\nAprès insertion de la clé 2:\n\n");
	afficherTas234(T2);
	inserer(T2,7);
	printf("\n\nAprès insertion de la clé 7:\n\n");
	afficherTas234(T2);
	TAS_2_3_4 *T=union_tas_2_3_4(T1,T2);
	printf("\n\nAprès union des tas 2-3-4 T1 et T2, on obtient le tas 2-3-4 T:\n\n");
	afficherTas234(T);
	TAS_2_3_4 *T3=(TAS_2_3_4 *)malloc(sizeof(TAS_2_3_4));
	NOEUD_TAS_2_3_4 *r3=allouerNoeud();
	r3->feuille=VRAI;
	r3->n=0;
	r3->hauteur=0;
	T3->racine=r3;
	printf("\n\n\n\nSoit un tas 2-3-4 vide T3.\n\n");
	TAS_2_3_4 *T4=union_tas_2_3_4(T,T3);
	printf("\n\nAprès union des tas 2-3-4 T et T3, on obtient le tas 2-3-4 T4:\n\n");
	afficherTas234(T4);
	TAS_2_3_4 *T5=(TAS_2_3_4 *)malloc(sizeof(TAS_2_3_4));
	NOEUD_TAS_2_3_4 *r5=allouerNoeud();
	r5->feuille=VRAI;
	r5->n=0;
	r5->hauteur=0;
	T5->racine=r5;
	printf("\n\n\n\nSoit un tas 2-3-4 vide T5.\n\n");
	inserer(T5,0);
	printf("\n\nAprès insertion de la clé 0:\n\n");
	afficherTas234(T5);
	inserer(T5,15);
	printf("\n\nAprès insertion de la clé 15:\n\n");
	afficherTas234(T5);
	inserer(T5,22);
	printf("\n\nAprès insertion de la clé 22:\n\n");
	afficherTas234(T5);
	inserer(T5,17);
	printf("\n\nAprès insertion de la clé 17:\n\n");
	afficherTas234(T5);
	TAS_2_3_4 *T6=union_tas_2_3_4(T4,T5);
	printf("\n\nAprès union des tas 2-3-4 T4 et T5, on obtient le tas 2-3-4 T6:\n\n");
	afficherTas234(T6);
	TAS_2_3_4 *T7=(TAS_2_3_4 *)malloc(sizeof(TAS_2_3_4));
	NOEUD_TAS_2_3_4 *r7=allouerNoeud();
	r7->feuille=VRAI;
	r7->n=0;
	r7->hauteur=0;
	T7->racine=r7;
	printf("\n\n\n\nSoit un tas 2-3-4 vide T7.\n\n");
	inserer(T7,30);
	printf("\n\nAprès insertion de la clé 30:\n\n");
	afficherTas234(T7);
	inserer(T7,31);
	printf("\n\nAprès insertion de la clé 31:\n\n");
	afficherTas234(T7);
	inserer(T7,32);
	inserer(T7,33);
	inserer(T7,34);
	inserer(T7,35);
	printf("\n\nAprès insertion successive des clés 32, 33, 34 et 35:\n\n");
	afficherTas234(T7);
	inserer(T7,36);
	inserer(T7,37);
	inserer(T7,38);
	inserer(T7,39);
	printf("\n\nAprès insertion successive des clés 36, 37, 38 et 39:\n\n");
	afficherTas234(T7);
	TAS_2_3_4 *T8=union_tas_2_3_4(T6,T7);
	printf("\n\nAprès union des tas 2-3-4 T6 et T7, on obtient le tas 2-3-4 T8:\n\n");
	afficherTas234(T8);

	GRAPHE *G=(GRAPHE *)malloc(sizeof(GRAPHE));
	G->n=10;
	G->m=21;
	G->aretes=(ARETE *)malloc(G->m*sizeof(ARETE));
	G->aretes[0].u=0;
	G->aretes[0].v=3;
	G->aretes[0].w=6;
	G->aretes[1].u=0;
	G->aretes[1].v=1;
	G->aretes[1].w=3;
	G->aretes[2].u=0;
	G->aretes[2].v=9;
	G->aretes[2].w=9;
	G->aretes[3].u=1;
	G->aretes[3].v=3;
	G->aretes[3].w=4;
	G->aretes[4].u=1;
	G->aretes[4].v=2;
	G->aretes[4].w=2;
	G->aretes[5].u=1;
	G->aretes[5].v=8;
	G->aretes[5].w=9;
	G->aretes[6].u=1;
	G->aretes[6].v=9;
	G->aretes[6].w=9;
	G->aretes[7].u=2;
	G->aretes[7].v=3;
	G->aretes[7].w=2;
	G->aretes[8].u=2;
	G->aretes[8].v=4;
	G->aretes[8].w=9;
	G->aretes[9].u=2;
	G->aretes[9].v=8;
	G->aretes[9].w=8;
	G->aretes[10].u=3;
	G->aretes[10].v=4;
	G->aretes[10].w=9;
	G->aretes[11].u=4;
	G->aretes[11].v=5;
	G->aretes[11].w=4;
	G->aretes[12].u=4;
	G->aretes[12].v=6;
	G->aretes[12].w=5;
	G->aretes[13].u=4;
	G->aretes[13].v=8;
	G->aretes[13].w=7;
	G->aretes[14].u=5;
	G->aretes[14].v=6;
	G->aretes[14].w=1;
	G->aretes[15].u=5;
	G->aretes[15].v=7;
	G->aretes[15].w=4;
	G->aretes[16].u=6;
	G->aretes[16].v=7;
	G->aretes[16].w=3;
	G->aretes[17].u=6;
	G->aretes[17].v=8;
	G->aretes[17].w=9;
	G->aretes[18].u=7;
	G->aretes[18].v=8;
	G->aretes[18].w=10;
	G->aretes[19].u=7;
	G->aretes[19].v=9;
	G->aretes[19].w=18;
	G->aretes[20].u=8;
	G->aretes[20].v=9;
	G->aretes[20].w=8;
	G->degres=(int *)malloc(G->n*sizeof(int));
	G->degres[0]=3;
	G->degres[1]=5;
	G->degres[2]=4;
	G->degres[3]=4;
	G->degres[4]=5;
	G->degres[5]=3;
	G->degres[6]=4;
	G->degres[7]=4;
	G->degres[8]=6;
	G->degres[9]=4;
	G->incidentes=(int **)malloc(G->n*sizeof(int *));
	int i;
	for(i=0;i<G->n;i++){
		G->incidentes[i]=(int *)malloc(G->degres[i]*sizeof(int));
	}
	G->incidentes[0][0]=0;
	G->incidentes[0][1]=1;
	G->incidentes[0][2]=2;
	G->incidentes[1][0]=1;
	G->incidentes[1][1]=3;
	G->incidentes[1][2]=4;
	G->incidentes[1][3]=5;
	G->incidentes[1][4]=6;
	G->incidentes[2][0]=4;
	G->incidentes[2][1]=7;
	G->incidentes[2][2]=8;
	G->incidentes[2][3]=9;
	G->incidentes[3][0]=0;
	G->incidentes[3][1]=3;
	G->incidentes[3][2]=7;
	G->incidentes[3][3]=10;
	G->incidentes[4][0]=8;
	G->incidentes[4][1]=10;
	G->incidentes[4][2]=11;
	G->incidentes[4][3]=12;
	G->incidentes[4][4]=13;
	G->incidentes[5][0]=11;
	G->incidentes[5][1]=14;
	G->incidentes[5][2]=15;
	G->incidentes[6][0]=12;
	G->incidentes[6][1]=14;
	G->incidentes[6][2]=16;
	G->incidentes[6][3]=17;
	G->incidentes[7][0]=15;
	G->incidentes[7][1]=16;
	G->incidentes[7][2]=18;
	G->incidentes[7][3]=19;
	G->incidentes[8][0]=5;
	G->incidentes[8][1]=9;
	G->incidentes[8][2]=13;
	G->incidentes[8][3]=17;
	G->incidentes[8][4]=18;
	G->incidentes[8][5]=20;
	G->incidentes[9][0]=2;
	G->incidentes[9][1]=6;
	G->incidentes[9][2]=19;
	G->incidentes[9][3]=20;
	printf("\n\nSoit G le graphe suivant :\n\n");
	afficherGraphe(G);
	ARETE *Acm=ACM(G);
	printf("\n\nOn obtient l'arbre couvrant minimum suivant :\n\n");
	double total=0.0;
	for(i=0;i<G->n-1;i++){
		printf("Arête (%d,%d) de poids %f\n",Acm[i].u,Acm[i].v,Acm[i].w);
		total=total+Acm[i].w;
	}
	printf("\nLe poids total est égal à %f\n\n",total);
	return 0;
}



