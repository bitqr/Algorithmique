#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 4


typedef struct _POINT{
        float abscisse;
        float ordonnee;
        }POINT;

        
typedef struct _PAQUET{
         struct _ELEM{
                POINT * point;
                float distance;
                }*
                 element;
        struct _PAQUET *precedent;
        struct _PAQUET *suivant;
                       }PAQUET;

typedef struct _ELEM ELEM;
typedef struct _ELEM* P_ELEM;
        
PAQUET * init_paquet(){
       PAQUET * p = (PAQUET *)malloc(sizeof(PAQUET));
       p->suivant = NULL;
       p->precedent=NULL;
       p->element = (P_ELEM)malloc(sizeof(ELEM));
       p->element->point = (POINT *)malloc(sizeof(POINT));
       return p;
}

PAQUET * init_list(P_ELEM e , PAQUET *q){
       PAQUET * p = init_paquet() ;
       p->element->point->abscisse = e->point->abscisse;
       p->element->point->ordonnee = e->point->ordonnee;
       p->element->distance = e->distance;
       p->suivant = q;
       p->precedent = NULL;
       q->precedent = p;
       return p;
}

void inserer_liste(PAQUET ** B, P_ELEM e, int j){
          if(B[j]==NULL){
                    PAQUET * p1 = init_paquet();
                    p1->element->point->abscisse = e->point->abscisse;
                    p1->element->point->ordonnee = e->point->ordonnee;
                    p1->element->distance = e->distance;
                    p1->suivant = NULL;
                    p1->precedent = NULL;     
                    B[j] = p1;
                    }
          else{
               PAQUET * l = init_list(e,B[j]);
               //B[j]->precedent = l;
               B[j] = l;
               }                    
}

PAQUET * queue(PAQUET * l){
       PAQUET *q = l;
       if(q==NULL) return NULL;
       while(q->suivant!=NULL){
                      q=q->suivant;
                      }
       return q;
}

PAQUET * inserer_element(PAQUET * p, P_ELEM e){
                   PAQUET*q=init_paquet();
                   q->element->point->abscisse = e->point->abscisse;
                   q->element->point->ordonnee = e->point->ordonnee;
                   q->element->distance = e->distance;
       if(p==NULL){
                   p=q;
                   return p;
                   }
       else{
            if(p->element->distance>=e->distance){
                              q->suivant = p;
                              return q;
                              }
            else{
                 PAQUET*o = p;
                  while((o->suivant)&&(o->suivant->element->distance<e->distance)){
                                                               o = o->suivant;
                                                               }
                  q->suivant = o->suivant;
                  o->suivant = q;
                  q->precedent = o;
                  if(q->suivant)
                  q->suivant->precedent = q;
                  return p;
                 }
            }
}

  
PAQUET* trier_par_insertion(PAQUET * l){
     if(l==NULL) return l;
     if(l->suivant == NULL) return l;
     PAQUET * p = NULL;
     while(l){
              P_ELEM e = l->element;
              p = inserer_element(p,e);
              l =l->suivant;
              }
              
     return p;
     
}

PAQUET * concat(PAQUET * p, PAQUET * q){
       if(p==NULL)
                  return q;
       if(q==NULL)
                  return p;
       queue(p)->suivant = q;
       return p;
       }
       
init_distance(P_ELEM * A, int n){
     int i;
     for(i=0;i<n;i++){
                      A[i]->distance = sqrt(A[i]->point->abscisse * A[i]->point->abscisse + 
                      A[i]->point->ordonnee * A[i]->point->ordonnee);
                      }
}


PAQUET * tri_distances(P_ELEM * A, int n){
     PAQUET ** B = (PAQUET **) malloc( n * sizeof(PAQUET*));
     int i;
     PAQUET *C = init_paquet(); 
     C = NULL;
     for(i=0;i<n;i++){
                     B[i] = init_paquet();
                     B[i]=NULL;
                     }
     for(i=0;i<n;i++){
                      inserer_liste( B , A[i] , (int)(floor(n*(A[i]->distance))) );
                      }
     for(i=0;i<n;i++){
                      B[i] = trier_par_insertion(B[i]);
                      }
     for(i=0;i<n;i++){
                      C = concat(C,B[i]);
                      }
    
     return C;
}

POINT * init_point(float a, float b){
      POINT * p = (POINT *)malloc(sizeof(POINT));
      p->abscisse = a;
      p->ordonnee = b;
      return p;
} 

P_ELEM init_element(POINT * p, float distance){
       P_ELEM el = (P_ELEM)malloc(sizeof(ELEM));
       el->point = init_point(p->abscisse,p->ordonnee);
       el->distance = distance;
       return el;
}  

P_ELEM * former_element(POINT ** P, int n){
     P_ELEM * A = (P_ELEM *)malloc(n*sizeof(P_ELEM));
     int i;
     for(i=0;i<n;i++){
                      A[i] = init_element(P[i],0.00);
                      }
     init_distance(A,n);
     return A;
}

    

int main(){
    POINT * p1 = init_point(0.79,0.13); 
    POINT * p2 = init_point(0.16,0.64);
    POINT * p3 = init_point(0.39,0.20);
    POINT * p4 = init_point(0.71,0.42);
    POINT* P[N] = {p1,p2,p3,p4};
    P_ELEM * A = former_element(P,N);
    PAQUET *C = tri_distances(A,N);
    int i;
    printf("VOICI LES DONNEES AVANT LE TRI PAR PAQUETS :\n\n\n");
    for(i=0;i<N;i++){
                     printf("d(%.2f ; %.2f)=%.3f\n",A[i]->point->abscisse,A[i]->point->ordonnee,A[i]->distance);
                     }
    printf("\n\n\n\n");
    printf("VOICI LES DONNEES APRES LE TRI PAR PAQUETS :\n\n\n");
    while(C){
             printf("d(%.2f ; %.2f)=%.3f\n", C->element->point->abscisse , C->element->point->ordonnee , C->element->distance);
             C = C->suivant;
             }
    printf("\n\n\n\n");
    return 0;
}
