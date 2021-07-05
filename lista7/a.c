#include <stdio.h>
int count =0;
int number =0;
int vet[1000];




int main(){
while(count<1000){
    vet[count] = 0;
    count++;
}
count=0;

while(scanf("%d",&number) !=EOF){
    vet[count] = number;
    count++;
}

for(int i=0; i<count;i++){
    for(int j=0; j<count;j++){
if(vet[j]>vet[j+1] && j!=count-1){
    int aux = vet[j];
    vet[j] = vet[j+1];
    vet[j+1] = aux;

}}
}

for(int i=0; i<count;i++){


printf("%d ",vet[i]);
}






    return 0;
}