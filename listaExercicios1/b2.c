#include <stdio.h>

int main(void){
    int a,n,soma =0;


scanf("%d",&n);

while(n){
    n--;
    scanf("%d",&a);
    soma+=a;
}
printf("%d\n",soma);


    return 0;
}