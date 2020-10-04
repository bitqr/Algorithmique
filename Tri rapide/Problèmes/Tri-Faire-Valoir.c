#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 50


void echanger(int *A, int i, int j){
     int tmp = A[i];
     A[i]=A[j];
     A[j]=tmp;
}

void tri_faire_valoir(int *A, int i, int j){
     if(A[i]>A[j])
          echanger(A,i,j);
     if(i+1>=j)
          return; 
     int k=(j-i+1)/3;  // arrondi inf�rieur.
     tri_faire_valoir(A,i,j-k); //deux premiers tiers.
     tri_faire_valoir(A,i+k,j); //deux derniers tiers.
     tri_faire_valoir(A,i,j-k); //deux premiers tiers derechef.           
}

int main(){
    srand(time(NULL));
    int j;
    int*A = (int*)malloc(N*sizeof(int));
    for(j=0;j<N;j++)
          A[j] = rand()%100;
    tri_faire_valoir(A,0,N-1);
    int i;
    for(i=0;i<N;++i){
         printf("%d\t",A[i]);
    }
    printf("\n\n\n");
    return 0;
}

