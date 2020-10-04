#include<stdio.h>
#include<stdlib.h>
#define N 7

int * somme_binaire(int * A , int * B , int n){
    int * C =(int *) malloc((n+1)*sizeof(int));
    int i,k=0;
    for(i=n-1;i>=0;i--){
        if(k==0){
            if(A[i]!=B[i])
                C[i+1]=1;
            else{
                if(A[i]==0)
                    C[i+1]=0;
                else{
                    C[i+1]=0;
                    k=1;
                }
            }
        }
        else{
            if(A[i]!=B[i])
                C[i+1]=0;
            else{
                if(A[i]==0){
                    C[i+1]=1;
                    k=0;
                }
                else{
                    C[i+1]=1;
                }
            }
        }
    }
    if(k==0)
        C[0]=0;
    else 
        C[0]=1;
    return C;
}

int main(){
    int A[N] = {1,1,1,0,0,0,1};
    int B[N] = {0,0,1,1,0,1,1};
    int * C = somme_binaire(A,B,N);
    int i;
    for(i=0;i<N+1;i++)
        printf("%d\t", C[i]);
    printf("\n\n\n");
    return 0;
}

