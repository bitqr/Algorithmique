#include"B_ARBRE.h"

void supprimer_B_arbre(B_ARBRE *T, int k){
	NOEUD_B_ARBRE *r=T->racine;
	if(r->feuille){
		supprimer_B_arbre_incomplet(r,k);	
	}
	else{
		int i=0;
		while(i<=r->n-1 && r->cle[i]<k)
			i=i+1;
		lireDisque(r->c[i]);
		if(i<=r->n-1 && r->cle[i]==k){
			NOEUD_B_ARBRE *y=r->c[i];
			if(y->n>=t){
				int k1=cle_maximale(y);
				supprimer_B_arbre_incomplet(y,k1);
				r->cle[i]=k1;
				ecrireDisque(r);
			}
			else{
				lireDisque(r->c[i+1]);
				NOEUD_B_ARBRE *z=r->c[i+1];
				if(z->n>=t){
					int k2=cle_minimale(z);
					supprimer_B_arbre_incomplet(z,k2);
					r->cle[i]=k2;
					ecrireDisque(r);				
				}
				else{
					fusionner(r,i,y,z);
					if(r->n==0){
						T->racine=y;
						supprimer_B_arbre(T,k);					
					}
					else
						supprimer_B_arbre_incomplet(y,k);
				}
			}
		}
		else{
			if(r->c[i]->n>=t)
				supprimer_B_arbre_incomplet(r->c[i],k);
			else{
				if(i>=1){
					lireDisque(r->c[i-1]);
					if(r->c[i-1]->n>=t){
						echanger_frere(r,i,r->c[i-1],r->c[i]);
						supprimer_B_arbre_incomplet(r->c[i],k);
					}
					else{
						if(i<=r->n-1){
							lireDisque(r->c[i+1]);
							if(r->c[i+1]->n>=t){
								echanger_frere(r,i,r->c[i+1],r->c[i]);
								supprimer_B_arbre_incomplet(r->c[i],k);
							}
							else{
								fusionner(r,i,r->c[i],r->c[i+1]);
								if(r->n==0){
									T->racine=r->c[i];
									supprimer_B_arbre(T,k);
								}
								else
									supprimer_B_arbre_incomplet(r->c[i],k);
							}					
						}
						else{
							fusionner(r,i-1,r->c[i-1],r->c[i]);
							if(r->n==0){
								T->racine=r->c[i-1];
								supprimer_B_arbre(T,k);
							}
							else
								supprimer_B_arbre_incomplet(r->c[i-1],k);
						}
					}
				}
				else{
					lireDisque(r->c[1]);
					if(r->c[1]->n>=t){
						echanger_frere(r,0,r->c[1],r->c[0]);
						supprimer_B_arbre_incomplet(r->c[i],k);
					}
					else{
						fusionner(r,0,r->c[0],r->c[1]);
						if(r->n==0){
							T->racine=r->c[0];
							supprimer_B_arbre(T,k);
						}
						else
							supprimer_B_arbre_incomplet(r->c[0],k);
					}
				}
			}
		}
	}
}


void supprimer_B_arbre_incomplet(NOEUD_B_ARBRE *x, int k){
	int i=0;
	if(x->feuille){
		while(i<x->n-1 && x->cle[i]<k)
			i=i+1;
		if(i<=x->n-1 && x->cle[i]==k){
			int j;
			for(j=i;j<x->n-1;j++)
				x->cle[j]=x->cle[j+1];
			x->n=x->n-1;
			ecrireDisque(x);
		}
		else{
			fprintf(stderr,"La clé est introuvable\n");
		}
	}
	else{
		while(i<x->n && x->cle[i]<k)
			i=i+1;
		lireDisque(x->c[i]);
		if(i<=x->n-1 && x->cle[i]==k){
			NOEUD_B_ARBRE *y=x->c[i];
			if(y->n>=t){
				int k1=cle_maximale(y);
				supprimer_B_arbre_incomplet(y,k1);
				x->cle[i]=k1;
				ecrireDisque(x);
			}
			else{
				lireDisque(x->c[i+1]);
				NOEUD_B_ARBRE *z=x->c[i+1];
				if(z->n>=t){
					int k2=cle_minimale(z);
					supprimer_B_arbre_incomplet(z,k2);
					x->cle[i]=k2;
					ecrireDisque(x);				
				}
				else{
					fusionner(x,i,y,z);
					supprimer_B_arbre_incomplet(y,k);
				}
			}
		}
		else{
			if(x->c[i]->n>=t)
				supprimer_B_arbre_incomplet(x->c[i],k);
			else{
				if(i>=1){
					lireDisque(x->c[i-1]);
					if(x->c[i-1]->n>=t){
						echanger_frere(x,i,x->c[i-1],x->c[i]);
						supprimer_B_arbre_incomplet(x->c[i],k);
					}
					else{
						if(i<=x->n-1){
							lireDisque(x->c[i+1]);
							if(x->c[i+1]->n>=t){
								echanger_frere(x,i,x->c[i+1],x->c[i]);
								supprimer_B_arbre_incomplet(x->c[i],k);
							}
							else{
								fusionner(x,i,x->c[i],x->c[i+1]);
								supprimer_B_arbre_incomplet(x->c[i],k);
							}
						}
						else{
							fusionner(x,i-1,x->c[i-1],x->c[i]);
							supprimer_B_arbre_incomplet(x->c[i-1],k);
						}
					}
				}
				else{
					lireDisque(x->c[1]);
					if(x->c[1]->n>=t){
						echanger_frere(x,0,x->c[1],x->c[0]);
						supprimer_B_arbre_incomplet(x->c[i],k);
					}
					else{
						fusionner(x,0,x->c[0],x->c[1]);
						supprimer_B_arbre_incomplet(x->c[0],k);
					}
				}
			}
		}
	}
}


int cle_maximale(NOEUD_B_ARBRE *x){
	while(x->feuille==FAUX){
		lireDisque(x->c[x->n]);
		x=x->c[x->n];	
	}
	return x->cle[x->n-1];
}


int cle_minimale(NOEUD_B_ARBRE *x){
	while(x->feuille==FAUX){
		lireDisque(x->c[0]);
		x=x->c[0];	
	}
	return x->cle[0];
}

void fusionner(NOEUD_B_ARBRE *x, int i, NOEUD_B_ARBRE *y, NOEUD_B_ARBRE *z){
	int k=x->cle[i];
	z->n=z->n+1;
	int j;
	int *nouveauClez=(int *)malloc((z->n)*sizeof(int));
	for(j=z->n-1;j>=1;j--)
		nouveauClez[j]=z->cle[j-1];
	nouveauClez[0]=k;
	z->cle=nouveauClez;
	if(!z->feuille){
		NOEUD_B_ARBRE **nouveauCz=(NOEUD_B_ARBRE **)malloc((z->n+1)*sizeof(NOEUD_B_ARBRE *));
		for(j=z->n;j>=1;j--)
			nouveauCz[j]=z->c[j-1];
		nouveauCz[0]=z->c[0];
		z->c=nouveauCz;
	}
	y->n=y->n+z->n;
	int *nouveauCley=(int *)malloc((y->n)*sizeof(int));
	for(j=0;j<t-1;j++)
		nouveauCley[j]=y->cle[j];
	for(j=t-1;j<y->n;j++)
		nouveauCley[j]=z->cle[j-t+1];
	y->cle=nouveauCley;
	if(!y->feuille){
		NOEUD_B_ARBRE **nouveauCy=(NOEUD_B_ARBRE **)malloc((y->n+1)*sizeof(NOEUD_B_ARBRE *));
		for(j=0;j<=t-1;j++)
			nouveauCy[j]=y->c[j-t];		
		for(j=t;j<=y->n;j++)
			nouveauCy[j]=z->c[j-t+1];
		y->c=nouveauCy;
	}
	for(j=i;j<x->n-1;j++){
		x->cle[j]=x->cle[j+1];
		x->c[j+1]=x->c[j+2];
	}
	x->n=x->n-1;
	ecrireDisque(y);
	ecrireDisque(x);
}


void echanger_frere(NOEUD_B_ARBRE *x, int i, NOEUD_B_ARBRE *z, NOEUD_B_ARBRE *y){
	int j;
	if(i>=1 && z==x->c[i-1]){
		y->n=y->n+1;
		int *nouveauCley=(int *)malloc((y->n)*sizeof(int));
		for(j=t-1;j>=1;j--)
			nouveauCley[j]=y->cle[j-1];
		nouveauCley[0]=x->cle[i-1];
		y->cle=nouveauCley;
		if(!y->feuille){
			NOEUD_B_ARBRE **nouveauCy=(NOEUD_B_ARBRE **)malloc((y->n+1)*sizeof(NOEUD_B_ARBRE *));
			for(j=t;j>=1;j--)
				nouveauCy[j]=y->c[j-1];
			nouveauCy[0]=z->c[z->n];
			y->c=nouveauCy;
		}
		x->cle[i-1]=z->cle[z->n-1];
		z->n=z->n-1;
	}
	else{
		y->n=y->n+1;
		int *nouveauCley=(int *)malloc((y->n)*sizeof(int));
		for(j=0;j<t-1;j++)
			nouveauCley[j]=y->cle[j];
		nouveauCley[t-1]=x->cle[i];
		y->cle=nouveauCley;
		if(!y->feuille){
			NOEUD_B_ARBRE **nouveauCy=(NOEUD_B_ARBRE **)malloc((y->n+1)*sizeof(NOEUD_B_ARBRE *));
			for(j=0;j<t;j++)
				nouveauCy[j]=y->c[j];
			nouveauCy[t]=z->c[0];
			y->c=nouveauCy;
		}
		x->cle[i]=z->cle[0];
		for(j=0;j<z->n-1;j++)
			z->cle[j]=z->cle[j+1];
		if(!z->feuille){
			for(j=0;j<z->n;j++)
				z->c[j]=z->c[j+1];		
		}
		z->n=z->n-1;
	}
	ecrireDisque(z);
	ecrireDisque(y);
	ecrireDisque(x);
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

void lireDisque(NOEUD_B_ARBRE *x){
	char s1[20];
	sprintf(s1,"%p.bab",x);
	FILE *f=fopen(s1,"r");
	fscanf(f,"%d\n",&(x->n));
	int i;
	x->cle = (int *)malloc(x->n * sizeof(int));
	for(i=1;i<=x->n;i++){
		fscanf(f,"%d\n",&(x->cle[i-1]));
	}
	fscanf(f,"%d\n",&(x->feuille));
	if(x->feuille==0){
		x->c=(NOEUD_B_ARBRE **)malloc((x->n+1)*sizeof(NOEUD_B_ARBRE *));
		for(i=1;i<=x->n+1;i++){
			x->c[i-1]=(NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
			void *p;
			fscanf(f,"%p\n",&p);
			x->c[i-1]=(NOEUD_B_ARBRE *)p;
		}
	}
	fclose(f);
}


int main(int argc, char **argv){
	NOEUD_B_ARBRE *f1=(NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	f1->n=2;
	f1->cle=(int *)malloc(f1->n*sizeof(int));
	f1->cle[0]=3;
	f1->cle[1]=22;
	f1->feuille=1;
	ecrireDisque(f1);

	NOEUD_B_ARBRE *f2=(NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	f2->n=3;
	f2->cle=(int *)malloc(f2->n*sizeof(int));
	f2->cle[0]=50;
	f2->cle[1]=60;
	f2->cle[2]=95;
	f2->feuille=1;
	ecrireDisque(f2);

	NOEUD_B_ARBRE *f3=(NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	f3->n=2;
	f3->cle=(int *)malloc(f3->n*sizeof(int));
	f3->cle[0]=500;
	f3->cle[1]=2000;
	f3->feuille=1;
	ecrireDisque(f3);

	NOEUD_B_ARBRE *rac=(NOEUD_B_ARBRE *)malloc(sizeof(NOEUD_B_ARBRE));
	rac->n=2;
	rac->cle=(int *)malloc(rac->n*sizeof(int));
	rac->cle[0]=29;
	rac->cle[1]=100;
	rac->feuille=0;
	rac->c=(NOEUD_B_ARBRE **)malloc((rac->n+1)*sizeof(NOEUD_B_ARBRE *));
	rac->c[0]=f1;
	rac->c[1]=f2;
	rac->c[2]=f3;
	ecrireDisque(rac);
	
	B_ARBRE *A=(B_ARBRE *)malloc(sizeof(B_ARBRE));
	A->racine=rac;

	supprimer_B_arbre(A,60);
	supprimer_B_arbre(A,29);
	supprimer_B_arbre(A,22);
	supprimer_B_arbre(A,50);
	supprimer_B_arbre(A,95);
	supprimer_B_arbre(A,3);
	supprimer_B_arbre(A,2000);
	supprimer_B_arbre(A,322);
	
	return 0;
}



