#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 7
#define D 3

const int b = 10;

int base(int n, int i){
    int r =(n/(pow(10,i)));
    return r%10;
}

int * tri_base(int *A, int n, int d){
     int i,j,k,a;
     int * B = (int *) malloc(n*sizeof(int));
     int * C = (int *) malloc((b-1)*sizeof(int));
     for(i=0;i<d;i++){
                      for(j=0;j<=b-1;j++){
                                        C[j] = 0;
                                        }
                      for(j=0;j<n;j++){
                                       C[base(A[j],i)]++;          
                             }
                             
                      for(j=1;j<=b-1;j++){
                                       C[j] += C[j-1];
                                      }
                                      
                      for(j=n-1;j>=0;j--){
                                          B[C[base(A[j],i)]-1] = A[j];
                                          C[base(A[j],i)]--;
                                          }
                      for(j=0;j<N;j++)
                                      A[j]=B[j];
                      }
                      
     return B;
}

int main(){
    int A[N] = {329,457,657,839,436,720,355};
    int i;
    tri_base(A,N,D);
    for(i=0;i<N;i++)
                   printf("%d\n\n",tri_base(A,N,D)[i]);
    printf("\n\n\n");
    return 0;
}
