#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct paciente{
    char nome[30];
    int prio;
}paciente;
typedef struct FilaPrioridade{
    int qnt;
    struct paciente dados[MAX];
}FilaPrioridade;

FilaPrioridade* criaFila(){
    FilaPrioridade *fp;
    fp = (struct FilaPrioridade*) malloc(sizeof(struct FilaPrioridade));
    if(fp != NULL)
        fp->qnt = 0;
    return fp;
}


void liberaFilaPrio(struct FilaPrioridade *fp){
free(fp);
}

void promoverElemento(FilaPrioridade* fp, int filho){
    int pai;
    struct paciente temp;
    pai = (filho-1)/2;
    while(filho>0 && (fp->dados[pai].prio <= fp->dados[filho].prio)){
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;
        filho = pai;
        pai = (pai-1)/2;
    }
}

void rebaixarElemento(FilaPrioridade* fp, int pai){
    struct paciente temp;
    int filho = 2*pai+1;
    while(filho<fp->qnt){
        if(filho<fp->qnt-1)
            if(fp->dados[filho].prio < fp->dados[filho+1].prio)
                filho++;
        if(fp->dados[pai].prio >= fp->dados[filho].prio)
            break;
        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;
        pai = filho;
        filho = 2*pai+1;
    }
}

int insereFilaPrio(struct FilaPrioridade *fp, char *nome, int prio){
    if(fp==NULL)
        return 0;
    if(fp->qnt == MAX)
        return 0;
    strcpy(fp->dados[fp->qnt].nome,nome);
    fp->dados[fp->qnt].prio = prio;
    promoverElemento(fp,fp->qnt);
    fp->qnt++;
    return 1;
}
int removeFilaPrio(struct FilaPrioridade *fp){
    if(fp == NULL)
        return 0;
    if(fp->qnt == 0)
        return 0;
    fp->qnt--;
    fp->dados[0] = fp->dados[fp->qnt];
    rebaixarElemento(fp,0);
    return 1;

}
int tamanhoFilaPrio(struct FilaPrioridade *fp){
    if(fp == NULL)
        return -1;
    else
        return fp->qnt;
    
}
int estaCheiaFilaPrio(struct FilaPrioridade *fp){
    if(fp == NULL)
        return -1;
    return(fp->qnt == MAX);
    
}
int estaVaziaFilaPrio(struct FilaPrioridade *fp){
    if(fp==NULL)
        return -1;
    return(fp->qnt == 0);
}

int consultaPrimeiroFilaPrioridade(FilaPrioridade* fp, char* nome){
   if(fp == NULL || fp->qnt == 0)
    return 0;
    strcpy(nome,fp->dados[1].nome);
    return 1; 
}




int main(){
    
    
FilaPrioridade *fp = criaFila();
int prio;
char nome;
while(scanf("%c %d",&nome,&prio) != EOF){
    insereFilaPrio(fp,&nome,prio);
}
char *nomel;

consultaPrimeiroFilaPrioridade(fp,nomel);

printf("NOME DO MAIOR: %s\nTamanho da fila: %d\n",nomel,tamanhoFilaPrio(fp));
liberaFilaPrio(fp);
    return 0;
}