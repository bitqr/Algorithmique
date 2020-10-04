#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 8
#define CLE 13


void fusion(int * A, int p , int q, int r){
     int n1 = q-p+1;
     int n2 = r-q;
     long infini = 100000000;
     int * L = (int *) malloc((n1 + 1)*sizeof(int));
     int * R = (int *) malloc((n2 + 1)*sizeof(int));
     int i,j;
     for(i=0;i<n1;i++)
                      L[i]=A[p+i];
     for(j=0;j<n2;j++)
                      R[j]=A[q+j+1];
     L[n1]= infini;
     R[n2]= infini;
     i=0;
     j=0;
     int k;
     for(k=p;k<r+1;k++){
                        if(L[i]<=R[j]){
                                      A[k]=L[i];
                                      i++;
                                      }
                        else{
                                      A[k]=R[j];
                                      j++;
                                      }
                        }
}

void tri_fusion(int* A, int p, int r){
     int q;
     if(p<r){
             q=(p+r)/2;
             tri_fusion(A,p,q);
             tri_fusion(A,q+1,r);
             fusion(A,p,q,r);
             }
}

int recherche_dichotomique(int*A,int deb,int fin,int cle){
    if(deb>fin){
                if(A[deb]==cle)
                               return deb;
                else return -1;
                }
    int mil = (deb + fin)/2;
    if(A[mil]==cle)
                   return mil;
    if(A[mil]<cle)
                  return recherche_dichotomique(A,mil+1,fin,cle);
    else
                  return recherche_dichotomique(A,deb,mil-1,cle);
}

int somme_ensemble(int *S, int n, int x){
    int i;
    tri_fusion(S,0,n-1);
    for(i=0;i<n;i++){
                     int comp = abs(S[i]-x);
                     if(recherche_dichotomique(S,i+1,n-1,comp)!=-1)
                                                                   return 1;
                     }
    return 0;
}
                                                                
                     

int main(){
    int A[N] = {5,2,4,7,1,3,2,6};
    int n = somme_ensemble(A,8,CLE);
    if(!n)
             printf("Pas de couple d'elements dont la somme vaut %d \n\n",CLE);
    else
             printf("Il y a un couple d'elements dont la somme vaut %d\n\n", CLE , n+1);
    printf("\n\n\n");
    return 0;
}
