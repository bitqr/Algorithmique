#include<stdio.h>
#include<stdlib.h>
#define N 3
#define X 0.5



float evaluation_polynomiale(int *A, int n, float x){
      float y=0;
      int i;
      for(i=0;i<n;i++){
                  if(i==0){
                           y=A[i];
                           }
                  else{
                       y = y + A[i]*x;
                       x=x*x;
                       }
                  }
      return y;
}

int main(){
    int A[N] = {6,1,3};
    float a = evaluation_polynomiale(A,N,X);
    printf("%f", a);
    printf("\n\n\n");
    return 0;
}
