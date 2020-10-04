#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define N 500

void tri_insertion(int *A , int n){
     int i,j,cle;
     for(j=1;j<n;j++){
                      cle=A[j];
                      //Insère A[j] dans la séquence triée A[1..j-1].
                      i=j-1;
                      while((i>=0)&&(A[i]>cle)){
                                               A[i+1]=A[i];
                                               i--;
                                               }
                      A[i+1]=cle;
                      }
}



int main(){
    int l,n;
    time_t t1 = clock();
    long it = 50;
    for(l=0;l<it;l++){
                      printf("Tableau initial :\n\n"); 
                      int * A = (int *)malloc(N*sizeof(int));
                      for(n=0;n<N;n++){
                                       A[n] = rand()%200;
                                       printf("%d\t",A[n]);
                                       }
                      printf("\n\n");
                      tri_insertion(A,N);
                      int i;
                      printf("\n\nApres tri:\n\n");
                      for(i=0;i<N;i++){
                                       printf("%d\t", A[i]);
                                       }
                      printf("\n\n\n------------------------------------------------------------\n\n");
                      }
    time_t t2 = clock();
    printf("\n\nTemps CPU moyen : %lf\n",((float)(t2-t1))/((float)(it)));
    printf("\n\n\n");
    return 0;
}
