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