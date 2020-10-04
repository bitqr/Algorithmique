#include<stdio.h>
#include<stdlib.h>
#define N 10

const int a = 0;
const int b = 1;

void tri_stable_surplace(int *A, int n){
     int i,j,cle;
     for(j=0;j<n;j++){
                      cle = A[j];
                      i=j-1;
                      while((i>0)&&(A[i]>cle)){
                                               A[i+1]=A[i];
                                               i--;
                                               }
                      A[i+1]=cle;
                      }
}

int main(){
    int A[N] = {0,1,0,1,1,1,0,1,0,0};
    tri_stable_surplace(A,N);
    int i;
    for(i=0;i<N;i++){
                     printf("%d\n",A[i]);
                     }
    printf("\n\n\n");
    return 0;
}
