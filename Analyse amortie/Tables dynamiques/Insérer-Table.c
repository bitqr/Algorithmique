#include"TABDYN.h"

TABLEDYNAMIQUE * creerTableDynamique(){
	TABLEDYNAMIQUE * tabdyn = (TABLEDYNAMIQUE *) malloc(sizeof(TABLEDYNAMIQUE));
	tabdyn->taille = 0;
	tabdyn->num = 0;	
	tabdyn->table = (int *) malloc(tabdyn->taille*sizeof(int));
	return tabdyn;
}

void inserer_table(TABLEDYNAMIQUE * T, int x){
	if(T->taille == 0){
		T->table = (int *) malloc(1*sizeof(int));
		T->taille=1;
	}
	if(T->num == T->taille){
		int *nouvelle_table = (int *)malloc((2*T->taille)*sizeof(int));
		int i;
		for(i=0;i<T->num;i++)
			nouvelle_table[i] = T->table[i];
		free(T->table);
		T->table = nouvelle_table;
		T->taille = 2*T->taille;	
	}
	T->table[T->num] = x;
	T->num = T->num + 1;
}

void afficherTable(TABLEDYNAMIQUE *T){
	int i;
	for(i=0;i<T->num;i++)
		printf("%d ",T->table[i]);
	printf("\ntaille[T]=%d\n\n",T->taille);
}

int main(int argc, char ** argv){
	TABLEDYNAMIQUE *T = creerTableDynamique();
	inserer_table(T,4);
	afficherTable(T);
	inserer_table(T,5);
	afficherTable(T);
	inserer_table(T,7);
	afficherTable(T);	
	inserer_table(T,8);
	afficherTable(T);
	inserer_table(T,15);
	afficherTable(T);
	return 0;
}

