#include<stdio.h>
#include<stdlib.h>
#define N 6
#define CLE 5

int recherche_lineaire(int *A, int n, int v){
    int i;
    for(i=0;i<n;i++){
        if(A[i]==v)
            return i;
    }
    return -1;
}

int main(){
    int A[N] = {5,2,4,6,1,3};
    int n = recherche_lineaire(A,N,CLE);
    if(n==-1)
        printf("L'élément %d n'est pas dans le tableau\n\n",CLE);
    else
        printf("L'élément %d est dans le tableau à l'indice %d\n\n", CLE , n+1);
    printf("\n\n\n");
    return 0;
}

