#include<stdio.h>
#include<stdlib.h>
#define N 10

const int a = 0;
const int b = 1;

int compte(int *A, int n, int x){
    int i,cpt=0;
    for(i=0;i<n;i++){
                     if(A[i]==x)
                                cpt++;
                     }
    return cpt;
}

void tri_lineaire_surplace(int *A, int n){
     int g = compte(A,n,a);
     int d = n-g;
     int i;
     for(i=0;i<n;i++){
                      if(i<g){
                              A[i] = a;
                              }
                      else{
                           A[i] = b;
                           }
                      }
}

int main(){
    int A[N] = {0,1,0,1,1,1,0,1,0,0};
    tri_lineaire_surplace(A,N);
    int i;
    for(i=0;i<N;i++){
                     printf("%d\n",A[i]);
                     }
    printf("\n\n\n");
    return 0;
}
