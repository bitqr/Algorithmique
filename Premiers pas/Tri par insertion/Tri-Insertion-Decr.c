#include<stdio.h>
#include<stdlib.h>
#define N 6

void tri_insertion_decr(int *A , int n){
     int i,j,cle;
     for(j=1;j<n;j++){
                      cle=A[j];
                      //Insère A[j] dans la séquence triée A[1..j-1].
                      i=j-1;
                      while((i>=0)&&(A[i]<cle)){
                                               A[i+1]=A[i];
                                               i--;
                                               }
                      A[i+1]=cle;
                      }
}



int main(){
    int A[N] = {5,2,4,6,1,3};
    tri_insertion_decr(A,N);
    int i;
    for(i=0;i<N;i++)
                    printf("%d\t", A[i]);
    printf("\n\n\n");
    return 0;
}
