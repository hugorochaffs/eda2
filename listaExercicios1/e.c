#include <stdio.h>



void selectionSort(int vet[],int n){

for(int i=0;i<n-1;i++){
    int menor = i;

for(int k=i+1;k<n;k++){
    if(vet[k]<vet[menor]){
        menor = k;
    }

}
if(vet[i]!= vet[menor]){
    int aux = vet[i];
    vet[i] = vet[menor];
    vet[menor] = aux;

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

selectionSort(vet,i);

for(int j =0;j<i;j++){
    printf("%d",vet[j]);
    if(j!=i-1){
        printf(" ");
    }
}
printf("\n");

}

