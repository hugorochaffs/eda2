#include <stdio.h>




void bubbleSort(int vet[],int n){

int ordena = 1;
while(ordena == 1){
ordena =0;
    for(int k = 0; k<n;k++){
        if(vet[k]> vet[k+1]){
            ordena = 1;
            int aux = vet[k];
            vet[k] = vet[k+1];
            vet[k+1] = aux;

        }
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

bubbleSort(vet,i-1);

for(int j =0;j<i;j++){
    printf("%d",vet[j]);
    if(j!=i-1){
        printf(" ");
    }
}
printf("\n");

}

