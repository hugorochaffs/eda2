/*Este é a base para a criação de árvores binárias. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define true 1
#define false 0
typedef int TIPOCHAVE;

typedef struct aux{
TIPOCHAVE chave;
struct aux *esq,*dir;
}NO;

typedef struct pilha{
    NO *topo;
    struct pilha *prox; 
}pilha;

pilha *criapilha (){
    pilha *topo = malloc(sizeof(pilha));
    topo->prox = NULL;
    return topo;
}

void empilha (pilha *topo, NO *x){
    pilha *novo = malloc(sizeof(pilha));
    novo->topo = x;
    novo->prox = topo->prox;
    topo->prox = novo;
}
NO *desempilha (pilha *topo){
    pilha *lixo = topo->prox;
    NO *x = lixo->topo;
    topo->prox = lixo->prox;
    free(lixo);
    return x;
}
bool pilhavazia (pilha* p){
 if(p->prox == NULL) return false;
  return true;
}

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

NO pilha1[101];
NO pilha2[101];
int topo,topo2;

void criapilha1(){
  topo = -1;
  topo2 = -1;
}


void push(NO valor){
    if(topo < 99){
topo++;
pilha1[topo] = valor;

}
}
void push2(NO valor){
    if(topo2 < 99){
topo2++;
pilha2[topo2] = valor;

}
}

NO pop(){
if(topo > -1){
    NO carac;
    carac = pilha1[topo];
    topo--;
    return carac;
}
}

NO pop2(){
if(topo2 > -1){
    NO carac2;
    carac2 = pilha2[topo2];
    topo2--;
    return carac2;
}}
void pre_ordem(NO *ptr){
criapilha1();
if(ptr != NULL){push(*ptr);}


while(topo>-1){
*ptr = pop();
if(ptr->dir !=NULL){push(*ptr->dir);}
  if(ptr->esq !=NULL){push(*ptr->esq);}

if(ptr!= NULL){printf("%d ",ptr->chave);}

}


}

void PosOrdem (NO *p) {if (p != NULL) {PosOrdem (p->esq) ;PosOrdem (p->dir) ;printf ("%d ", p->chave) ;}}

void em_ordem (NO *raiz){
   pilha *p = criapilha();
   int fim = 0;
   
   
   while (!fim) {
      
      if (raiz != NULL) {
        
         empilha (p, raiz);
         raiz = raiz->esq;
      }
      else {
        
         if (pilhavazia (p)){
           
         
         raiz = desempilha (p);
         printf ("%d ", raiz->chave);
        raiz = raiz->dir;
         
         }else{fim =1;}
      }
   }
}


int main(){

PONT raiz = incializa();
PONT raiz2 = incializa();
PONT raiz3 = incializa();
int ler;

while (scanf("%d",&ler) != EOF)
{
PONT no = criaNovoNo(ler);
raiz = adiciona(raiz,no); 
PONT no2 = criaNovoNo(ler);
raiz2 = adiciona(raiz2,no2); 
PONT no3 = criaNovoNo(ler);
raiz3 = adiciona(raiz3,no3); 
}

pre_ordem(raiz);
printf(".\n");
em_ordem(raiz2);
printf(".\n");
PosOrdem(raiz3);
printf(".\n");

    return 0;

}