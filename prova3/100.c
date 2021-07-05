#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int Item;
#define MAX 102

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

int pqEspiaMax(FilaPrioridade *fp){
    if(fp!=NULL){
       
        return fp->dados[1];
    }

}

void PQworkaround(FilaPrioridade *fp,Item x){
    fp->dados[1] = x;
    fixDown(fp,1,fp->qnt);
}

void imprimeHeap(FilaPrioridade *fp){
    if(PQempty(fp))
        return;
    int x= PQdelmax(fp);
    imprimeHeap(fp);
    printf("%d ",x);
        
    
}




int main(){
    FilaPrioridade *fp = PQinit();
    FilaPrioridade *aux = PQinit();
int x;
int i = 1;
int op;
int qnt;
while(scanf("%d",&op) != EOF){
    if(op == 1){
        if(i<=100)
            {
                i++;
                scanf("%d",&x);
            PQinsert(fp,x);
            PQinsert(aux,x);
                
            }
        if(i>101){
            i++;
            scanf("%d",&x);
             PQinsert(fp,x);
             PQinsert(aux,x);
        PQdelmax(fp);
        PQdelmax(aux);
        
            
            
        }
    }

    if(op == 2){

        scanf("%d",&qnt);
while(fp->qnt > qnt){PQdelmax(fp);}
        
        imprimeHeap(fp);
        printf("\n");

    }
while(fp->qnt>0){PQdelmax(fp);}
while(aux->qnt >0){
    PQinsert(fp,PQdelmax(aux));
}


}

    return 0;
}