#include"AdressageOuvert.h" 

int rechercher_hachage(int *T, int k, int m){
	int i = 0,j;
	do{
		j = h(k,i,m);
		if(T[j] == k)
			return j;
		i++;
	}while(T[j]!=-1 && i!=m);
	return -1;
}

