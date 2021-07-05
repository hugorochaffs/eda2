#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aeroporto{
int nome;
int qntVoos;
}Aeroporto;




int main(){
int A,V;
int X,Y;


int compararVoos (const void *x, const void *y) {
    int pri = ((struct Aeroporto *)x)->qntVoos;
    int seg = ((struct Aeroporto *)y)->qntVoos;
    return (pri - seg);
}
int teste=0;
while(scanf("%d",&A) && A !=0 && scanf("%d",&V) && V!=0){
    teste++;
    X=0; Y=0;
    struct Aeroporto *Aeroportos = malloc(A*sizeof(Aeroporto)+1);
    memset(Aeroportos,0,A*sizeof(Aeroporto)+1);
    for(int contaVoos=0;contaVoos<V;contaVoos++){
        scanf("%d %d",&X,&Y);
        Aeroportos[X].nome = X;
        Aeroportos[Y].nome = Y;
        Aeroportos[X].qntVoos++;
        Aeroportos[Y].qntVoos++;
    }
qsort(Aeroportos, A+1, sizeof(struct Aeroporto),compararVoos);

printf("Teste %d\n", teste);

for(int j = 0;j<A+1;j++){
    if(Aeroportos[j].qntVoos == Aeroportos[A].qntVoos){
        printf("%d ",Aeroportos[j].nome);
    }
}

    printf("\n\n");

}
}