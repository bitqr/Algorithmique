#include"HUFF.h"

NOEUD * allouerNoeud(){
	NOEUD * z = (NOEUD *) malloc(sizeof(NOEUD));
	z->gauche = NULL;
	z->droite = NULL;
	return z;
}

FILE_DE_PRIORITE * creer_tas(int longueur, int taille){
	FILE_DE_PRIORITE * t = (FILE_DE_PRIORITE *) malloc( sizeof(FILE_DE_PRIORITE));
	t->longueur = longueur;
	t->taille = taille;
	NOEUD ** tab = (NOEUD **) malloc( longueur * sizeof(NOEUD *));
	int i;
	for(i=0;i<longueur;i++)
	tab[i] = allouerNoeud();
	t->tableau = tab;
	return t;
}  

int parent(int i){
    return (i-1)/2;
}

void echanger(NOEUD ** A, int a, int b){
	NOEUD * tmp = A[b];
	A[b] = A[a];
	A[a] = tmp;
}

void diminuer_cle_tas(FILE_DE_PRIORITE * fp, int i, NOEUD * x){
	NOEUD ** A = fp->tableau;
	if(x->f>A[i]->f){
		printf("Nouvelle cle plus grande que cle actuelle\n\n\n");
		exit(1);
	}
	A[i]->f=x->f;
	while((i>0)&&(A[parent(i)]->f > A[i]->f)){
		echanger(A,i,parent(i));
		i=parent(i);
	}
}

void inserer(FILE_DE_PRIORITE * fp, NOEUD * x){
	fp->taille++;
	fp->tableau[fp->taille-1]->gauche = x->gauche;
	fp->tableau[fp->taille-1]->droite = x->droite;
	fp->tableau[fp->taille-1]->f = INFINI;
	diminuer_cle_tas(fp,fp->taille-1,x);
}

int droite(int i){
    return 2*i+2;
}

int gauche(int i){
    return 2*i+1;
}

void entasser_min(FILE_DE_PRIORITE * fp, int i){
	int l = gauche(i);
	int r = droite(i);
	int min;
	NOEUD ** A = fp->tableau;
	if((l<fp->taille)&&(A[l]->f<A[i]->f))
		min = l;
	else
		min = i;
	if((r<fp->taille)&&(A[r]->f<A[min]->f))
		min = r;
	if(min!=i){
		echanger(A,i,min);
		entasser_min(fp, min);
	}
}

NOEUD * extraire_min(FILE_DE_PRIORITE * fp){
    if(fp->taille<1){
		printf("Limite inferieure depassee\n\n\n");
		exit(1);
	}
    NOEUD ** A = fp->tableau;
    NOEUD *min = allouerNoeud();
    min->f = A[0]->f;
    min->gauche = A[0]->gauche;
    min->droite = A[0]->droite;
    A[0]->f = A[fp->taille - 1]->f;
    A[0]->gauche = A[fp->taille - 1]->gauche;
    A[0]->droite = A[fp->taille - 1]->droite;
    fp->taille--;
    entasser_min(fp,0);  
    return min;
}

void affichageInfixe(NOEUD *z){
	if(z!=NULL){
		affichageInfixe(z->gauche);
		printf("%d\n",z->f);
		affichageInfixe(z->droite);
	}
}

NOEUD * Huffman(FILE_DE_PRIORITE * C){
	int n = C->taille;
	FILE_DE_PRIORITE * Q = C;
	int i;
	for(i=1;i<=n-1;i++){
		NOEUD * z = allouerNoeud();
		NOEUD * x = extraire_min(Q);
		z->gauche = x;
		NOEUD * y = extraire_min(Q);
		z->droite = y;
		z->f = x->f + y->f;
		inserer(Q,z);
	}
	return extraire_min(Q); //Retourner la racine de l'arborescence.
}

int main(int argc, char **argv){
	FILE_DE_PRIORITE * C = creer_tas(LG,0);
	NOEUD *f = allouerNoeud();
	f->f=5;
	inserer(C,f);
	NOEUD *e = allouerNoeud();
	e->f=9;
	inserer(C,e);
	NOEUD *c = allouerNoeud();
	c->f=12;
	inserer(C,c);
	NOEUD *b = allouerNoeud();
	b->f=13;
	inserer(C,b);
	NOEUD *d = allouerNoeud();
	d->f=16;
	inserer(C,d);
	NOEUD *a = allouerNoeud();
	a->f=45;
	inserer(C,a);
	NOEUD * z = Huffman(C);
	affichageInfixe(z);
	printf("\n\n");	
	FILE_DE_PRIORITE_TERNAIRE * Q = creerTasTernaire(LG,0);
	NOEUD_TERNAIRE *f1 = allouerNoeudTernaire();
	f1->f=5;
	insererTernaire(Q,f1);
	NOEUD_TERNAIRE *e1 = allouerNoeudTernaire();
	e1->f=9;
	insererTernaire(Q,e1);
	NOEUD_TERNAIRE *c1 = allouerNoeudTernaire();
	c1->f=12;
	insererTernaire(Q,c1);
	NOEUD_TERNAIRE *b1 = allouerNoeudTernaire();
	b1->f=13;
	insererTernaire(Q,b1);
	NOEUD_TERNAIRE *d1 = allouerNoeudTernaire();
	d1->f=16;
	insererTernaire(Q,d1);
	NOEUD_TERNAIRE *a1 = allouerNoeudTernaire();
	a1->f=45;
	insererTernaire(Q,a1);
	NOEUD_TERNAIRE * z1 = Huffman_ternaire(Q);
	affichagePrefixeTernaire(z1);
	return 0;
}

