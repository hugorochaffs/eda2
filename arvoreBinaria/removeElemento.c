/*Este é a base para a criação de árvores binárias. */
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef int PONT;

PONT incializa(){
    return (NULL);
}

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai)
{
    PONT atual = raiz;
    *pai =NULL;
    while(atual){
        if(atual->chave == ch) return atual;
        *pai = atual;
        if(ch <atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }
    return (NULL);
}

PONT removeNo(PONT raiz,TIPOCHAVE ch){
    PONT pai, no, p, q;
    no = buscaNo(raiz,ch,&pai);
    if(no == NULL) return(raiz);
    if(!no->esq || !no->dir){
        if(!no->esq) q = no->dir;
        else q = no->esq;
}
    else{
        p=no;
        q=no->esq;
        while(q->dir){
            p=q;
            q=q->dir;
        }
        if(p!= no){
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if(!pai){
        free(no);
        return(q);
    }
    if(ch <pai->chave) pai->esq = q;
    else pai->dir = q;
    free(no);
    return(raiz);
}


typedef struct aux{
TIPOCHAVE chave;
struct aux *esq,*dir;
}NO;

int main(){

PONT raiz = incializa();


    return 0;

}