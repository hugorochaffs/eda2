#include <stdio.h>

int main(){
int n, leitura;

scanf("%d",&n);
while(n){
scanf("%d",&leitura);
if(leitura%2 == 0){
    printf("Jedi\n");
}else{
    printf("Sith\n");
}
    n--;
}
}