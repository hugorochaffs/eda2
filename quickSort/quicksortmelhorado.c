#include <stdio.h>
#include <string.h>
typedef int Item;
#define key(A) (A)
#define less(A,B)(A<B)
#define lesseq(A,B)(A<=B)
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B){if (less(B,A)) exch(A,B);}

int separa(Item *v, int l, int r){
    int i = l-1,j=r; Item c=v[r];
    for(;;){
        while (less(v[++i],c));
        while (less(c,v[--j])) if(j==l)break;
        if (i>=j)break;
        exch(v[i],v[j]);
    }
    exch(v[i],v[r]);
    return i;
}

void quickSort(Item *v,int l,int r){
    int j;
    if(r<=l)return;

//aqui estão as modificaçoes do m3
   exch(v[(l+r)/2],v[r-1]);
   cmpexch(v[l],v[r-1]);
   cmpexch(v[l],v[r]);
   cmpexch(v[r-1],v[r]);
////

    j=separa(v,l,r);
    quickSort(v,l,j-1);
    quickSort(v,j+1,r);
}

int main(){
Item vetor[100];
int j=50;
for(int i=0;i<50;i++){
    vetor[i] = j;
    j--;
}
quickSort(vetor,0,50);
for(int i=0;i<50;i++){
    printf("%d ",vetor[i]);
}
}