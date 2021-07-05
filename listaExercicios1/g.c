#include <stdio.h>
#include <stdlib.h>



void insertionSortCrescente(int vet[],int n){



    for(int i = 0;i<n;i++){
int chave = i;
while(chave>0 && vet[chave-1]> vet[chave]){
    int aux = vet[chave];
    vet[chave] = vet[chave-1];
    vet[chave-1] = aux;
    chave--;
}

    }

}





int main(void){
int n;int * vet = (int*) malloc(10 * sizeof(int));
int i=0;
unsigned long int countMil =2;
unsigned long int auxcountMil = 2;


while(scanf("%d",&n)!= EOF){
    if(countMil == 10){
        vet = (int*) realloc(vet,(auxcountMil*10) * sizeof(int));
       auxcountMil++;
       countMil = 0;
    }
    vet[i] = n;
    i++;
    countMil++;
}

insertionSortCrescente(vet,i);

for(int j =0;j<i;j++){
    printf("%d",vet[j]);
    if(j!=i-1){
        printf(" ");
    }
}
printf("\n");

}

