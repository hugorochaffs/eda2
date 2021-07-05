#include <stdio.h>



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
int n;int vet[1000];
int i=0;


while(scanf("%d",&n)!= EOF){
    vet[i] = n;
    i++;
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

