#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct cont_st
{
int Char;
int count;
}cont_st;

typedef struct cont_st Item;

#define key(A) (A.count)
#define lesseq(A,B)(key(A)<=key(B))
#define exch(A,B) {Item t=A; A=B; B=t;}
#define cmpexch(A,B){if (less(B,A)) exch(A,B);}

int less(Item A, Item B){
    if(key(A)== key(B)){
        (A.Char) < (B.Char);
    }
    else{
        key(A)<key(B);
    }

}

void merge(Item *v,int l,int r1,int r2){

    Item *vAux = malloc(sizeof(Item)*(r2-l+1));
    int k= 0;
    int i= l;
    int j = r1+1;

    while(i<= r1 && j<=r2){
       if(less(v[i],v[j])){
           vAux[k++] = v[i++];
       }
       else{
           vAux[k++] = v[j++];
       }
    }
while(i<=r1){
    vAux[k++] = v[i++];
}
while(j<=r2){
    vAux[k++] = v[j++];
}
k=0;
int anterior = 0;
for(i=l;i<=r2;i++){
    int aux = k++;
v[i] = vAux[aux];


        
    }
    


free(vAux);
}

void mergeSort(Item *v,int l,int r){
    if(l>=r)return;
    int meio = (r+l)/2;
    mergeSort(v,l,meio);
    mergeSort(v,meio+1,r);
    merge(v,l,meio,r);
}

void resolvelinha(){
    struct cont_st th[128];
    memset(th,0,sizeof(struct cont_st)*128);
    char b;
    while(scanf("%c",&b)==1 && b!= '\n')
    {
        th[b].Char = b;
        th[b].count++;
    }
    mergeSort(th,0,127);

    int i =32;

    while(i<128){
        if(th[i].count>0)
        printf("%hd %d\n",th[i].Char,th[i].count);
        i++;
    }
}





int main(){
resolvelinha();
    return 0;
}