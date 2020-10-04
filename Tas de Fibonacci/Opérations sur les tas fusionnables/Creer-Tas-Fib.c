#include"TASFIB.h"

TAS_FIBONACCI *creer_tas_fib(){
	TAS_FIBONACCI *T=(TAS_FIBONACCI *)malloc(sizeof(TAS_FIBONACCI));
	T->n=0;
	T->min=NIL;
	return T;
}

int main(int argc, char **argv){
	printf("\n\nCréation du tas de Fibonacci T : \n");
	TAS_FIBONACCI *T=creer_tas_fib();
	if(T->min==NIL)
		printf("T est vide.\n");
	printf("T a %d noeud(s).\n\n\n",T->n);
	NOEUD_TAS_FIBONACCI *x1=creerNoeudTasFibonacci(8,NIL,NIL,NIL,NIL,FAUX,0);
	inserer_tas_fib(T,x1);
	printf("\n\nAprès insertion de la clé 8 :\n");
	afficherTasFibonacci(T);
	NOEUD_TAS_FIBONACCI *x2=creerNoeudTasFibonacci(80,NIL,NIL,NIL,NIL,FAUX,0);
	inserer_tas_fib(T,x2);
	printf("\n\nAprès insertion de la clé 80 :\n");
	afficherTasFibonacci(T);
	TAS_FIBONACCI *T1=creer_tas_fib();
	NOEUD_TAS_FIBONACCI *x3=creerNoeudTasFibonacci(70,NIL,NIL,NIL,NIL,FAUX,0);
	inserer_tas_fib(T1,x3);
	printf("\n\nAprès insertion de la clé 70 :\n");
	afficherTasFibonacci(T1);
	NOEUD_TAS_FIBONACCI *x4=creerNoeudTasFibonacci(40,NIL,NIL,NIL,NIL,FAUX,0);
	inserer_tas_fib(T1,x4);
	printf("\n\nAprès insertion de la clé 40 :\n");
	afficherTasFibonacci(T1);
	TAS_FIBONACCI *T3=union_tas_fib(T,T1);
	printf("Après union des tas T et T1 :\n");
	afficherTasFibonacci(T3);
	TAS_FIBONACCI *T2=creer_tas_fib();
	NOEUD_TAS_FIBONACCI *y1=creerNoeudTasFibonacci(3,NIL,NIL,NIL,NIL,FAUX,3);
	NOEUD_TAS_FIBONACCI *y2=creerNoeudTasFibonacci(17,NIL,NIL,y1,NIL,FAUX,1);
	NOEUD_TAS_FIBONACCI *y3=creerNoeudTasFibonacci(24,NIL,NIL,y2,NIL,FAUX,2);
	NOEUD_TAS_FIBONACCI *y4=creerNoeudTasFibonacci(23,NIL,NIL,y3,NIL,FAUX,0);
	NOEUD_TAS_FIBONACCI *y5=creerNoeudTasFibonacci(7,NIL,NIL,y4,NIL,FAUX,0);
	NOEUD_TAS_FIBONACCI *y6=creerNoeudTasFibonacci(21,NIL,NIL,y5,y1,FAUX,0);
	NOEUD_TAS_FIBONACCI *y7=creerNoeudTasFibonacci(18,NIL,y1,NIL,NIL,VRAI,1);
	NOEUD_TAS_FIBONACCI *y8=creerNoeudTasFibonacci(52,NIL,y1,y7,NIL,FAUX,0);
	NOEUD_TAS_FIBONACCI *y9=creerNoeudTasFibonacci(38,NIL,y1,y8,y7,FAUX,1);
	NOEUD_TAS_FIBONACCI *y10=creerNoeudTasFibonacci(30,NIL,y2,NIL,NIL,FAUX,0);
	NOEUD_TAS_FIBONACCI *y11=creerNoeudTasFibonacci(26,NIL,y3,NIL,NIL,VRAI,1);
	NOEUD_TAS_FIBONACCI *y12=creerNoeudTasFibonacci(46,NIL,y3,y11,y11,FAUX,0);
	NOEUD_TAS_FIBONACCI *y13=creerNoeudTasFibonacci(39,NIL,y7,NIL,NIL,VRAI,0);
	NOEUD_TAS_FIBONACCI *y14=creerNoeudTasFibonacci(41,NIL,y9,NIL,NIL,FAUX,0);
	NOEUD_TAS_FIBONACCI *y15=creerNoeudTasFibonacci(35,NIL,y11,NIL,NIL,FAUX,0);
	y1->droite=y2;
	y1->gauche=y6;
	y1->enfant=y7;	
	y2->droite=y3;
	y2->enfant=y10;
	y3->droite=y4;
	y3->enfant=y11;
	y4->droite=y5;
	y5->droite=y6;
	y7->droite=y8;
	y7->gauche=y9;
	y7->enfant=y13;
	y8->droite=y9;
	y9->enfant=y14;
	y10->droite=y10;
	y10->gauche=y10;
	y11->droite=y12;
	y11->gauche=y12;
	y11->enfant=y15;
	y13->droite=y13;
	y13->gauche=y13;
	y14->droite=y14;
	y14->gauche=y14;
	y15->droite=y15;
	y15->gauche=y15;
	T2->n=15;
	T2->min=y1;
	printf("\n\nTas de Fibonacci T2 avant extraction de la clé minimale :\n\n");
	afficherTasFibonacci(T2);
	extraire_min_tas_fib(T2);
	printf("\n\nTas de Fibonacci T2 après extraction de la clé minimale :\n\n");
	afficherTasFibonacci(T2);
	extraire_min_tas_fib(T2);
	printf("\n\nTas de Fibonacci T2 après extraction de la clé minimale :\n\n");
	afficherTasFibonacci(T2);
	return 0;
}


