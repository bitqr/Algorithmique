#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#define N 7
#define K 3


int* creer_candidates(n){
    int i;
    int* tab = (int *) malloc (n*sizeof(int));
    for(i=0;i<n;i++){
                     tab[i] = rand()%1000;
                     }
    return tab;
}


int maximum_en_ligne(int k, int n){
     int * t = creer_candidates(n);
     int i;
     for(i=0;i<n;i++)
                     printf("%d\t",t[i]);
     printf("\n\n\n");                
     int meilleur_score = -100000000; 
     for(i=0;i<k;i++){
                      if(t[i]>meilleur_score)
                                      meilleur_score = t[i];
                      }
     for(i=k;i<n;i++){
                      if(t[i]>meilleur_score)
                                             return i;
                      }
     return n;
}             



int main(){
    srand(time(NULL));
    printf("La candidate embauchee est la numero %d\n",maximum_en_ligne(K,N)+1);
    return 0;
}
