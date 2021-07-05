#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int Item;
#define MAX 1000

typedef struct FilaPrioridade{
    int qnt;
     Item dados[MAX];
}FilaPrioridade;



FilaPrioridade* PQinit()
{   FilaPrioridade *fp;
    fp = (struct FilaPrioridade*) malloc(sizeof(struct FilaPrioridade)*MAX);
    if(fp != NULL)
        fp->qnt = 0;
    return fp;
}

int PQempty(FilaPrioridade *fp)
{
	return fp->qnt == 0;
}

void fixUp(FilaPrioridade *v, int k){
    while(k>1 && v->dados[k/2]<v->dados[k]){
        Item aux = v->dados[k];
        v->dados[k] = v->dados[k/2];
        v->dados[k/2] = aux;
        k = k/2;
    }

}

void fixDown(FilaPrioridade *v, int k, int tamanhoHeap){
    int j;

    while(2*k <= tamanhoHeap){

        j= 2*k;
        if(j<tamanhoHeap && v->dados[j]<v->dados[j+1]) j++;
        if(v->dados[k]>=v->dados[j]) break;

       Item aux = v->dados[k];
       v->dados[k] = v->dados[j];
       v->dados[j] = aux;

    }

}

int PQinsert(FilaPrioridade *fp, Item v)
{
    if(fp==NULL)
        return 0;
    if(fp->qnt == MAX)
        return 0;
	fp->dados[++fp->qnt]=v;
	fixUp(fp,fp->qnt);
    return 1;
}

int PQdelmax(FilaPrioridade *fp)
{
    Item aux;
    aux = fp->dados[1];
    fp->dados[1] = fp->dados[fp->qnt];
    fp->dados[fp->qnt] = aux;
	fixDown(fp,1,fp->qnt-1);
	return fp->dados[fp->qnt--];
}





int main(){
    FilaPrioridade *fp = PQinit();
    
int n;
int qnt = 20;
while(qnt>10){
    scanf("%d",&n);
    PQinsert(fp,n);
    qnt--;
}


printf("%d\n",PQdelmax(fp));




    return 0;
}