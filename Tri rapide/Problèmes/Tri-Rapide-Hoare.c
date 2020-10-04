#include<stdio.h>
#include<stdlib.h>
#define N 12

void echanger(int*A,int i, int j){
     int tmp = A[i];
     A[i]=A[j];
     A[j]=tmp;
}

int hoare_partition(int * A, int p, int r){
    int x = A[p];
    int i = p-1;
    int j = r+1;
    while(1){
             do
               j--;
             while(A[j]>x);
             do 
                i++;
             while(A[i]<x);
             if(i<j)
                    echanger(A,i,j);
             else 
                  return j;
             }
}

void tri_rapide_hoare(int *A, int p, int r){
     if(p<r){
             int q = hoare_partition(A,p,r);
             tri_rapide_hoare(A,p,q);
             tri_rapide_hoare(A,q+1,r);
             }
}

int main(){
    int A[N]={13,19,9,5,12,8,7,4,11,2,6,21};
    int i;
    tri_rapide_hoare(A,0,N-1);
    for(i=0;i<N;i++){
                     printf("%d\t", A[i]);
                     }
    printf("\n\n\n");
    return 0;
}
    
