#include <stdio.h>
#include <stdlib.h>

#define hash(v,m) ((618033*(unsigned)v)%m)

typedef struct Item{
    int chave;
    long e1,e2;
    long elemento;
}Item;

Item NULLitem = {0,0,0,0};

#define key(x) (x.chave)
#define less(a,b) (key(a) < key(b))
#define null(A) (key(ht[A])== key(NULLitem))
#define eq(a,b) (a == b)
static int N,M;
static Item *ht;
void HtInit(int max){
    int i;
    N=0,M = 2*max;
    ht = malloc(sizeof(Item)*M);
    for(i=0;i<M;i++){
        ht[i] = NULLitem;
    }

}

int HTcount(){return N;}

void HTinsert(Item item){
    int v = key(item);
    int i = hash(v,M);
    while(!null(i)) i=(i+1)%M;
    ht[i] = item;
    N++;
}
Item HTsearch (int v){
    int i = hash(v,M);
    while(!null(i))
    if(eq(v,key(ht[i])))
    return ht[i]; //Aqui era para ser st
    
    else
    i = (i+1)%M;

    return NULLitem;

}