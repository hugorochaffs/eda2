/*Este é a base para a criação de árvores binárias. */
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
TIPOCHAVE chave;
struct aux *esq,*dir;
}NO;


typedef NO* PONT;

PONT incializa(){
    return (NULL);
}

PONT adiciona(PONT raiz, PONT no){
    if(raiz == NULL) return(no);
    if(no->chave < raiz->chave) raiz->esq = adiciona(raiz->esq,no);
    else raiz->dir = adiciona(raiz->dir,no);
    return (raiz);
}

PONT criaNovoNo(TIPOCHAVE ch){
    PONT novoNo = (PONT) malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return(novoNo);
}

PONT busca(TIPOCHAVE ch, PONT raiz){
    if(raiz== NULL)return(NULL);
    if(raiz->chave == ch) return(raiz);
    if(raiz->chave>ch) return(busca(ch,raiz->esq));
    return(busca(ch,raiz->dir));

}

int contaNos(PONT raiz){
    if(!raiz) return 0;
    return(contaNos(raiz->esq)+1+contaNos(raiz->dir));
}

void printArvore(PONT raiz){
    if(raiz!=NULL){
        printf("%i",raiz->chave);
        printf("(");
        printArvore(raiz->esq);
        printArvore(raiz->dir);
        printf(")");
    }

}


int main(){

PONT raiz = incializa();
PONT no = criaNovoNo(23); // CRIA UM NÓ 23
raiz = adiciona(raiz,no); // ADICIONA O NÓ 23 NA RAIZ
PONT p = busca(23,raiz);  //BUSCA O 23 NA RAIZ

    return 0;

}