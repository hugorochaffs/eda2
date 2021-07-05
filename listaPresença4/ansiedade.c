#include <stdio.h>
#include <string.h>

int main(){
char ler[4];
int countWhile =0;
int countAnsiedade = 0;
int countAnsiedadeGeral =0;
while(scanf("%[^\n]",ler)!= EOF){
if(countWhile == 10){countWhile = 0;countAnsiedade = 0;}
if(strcmp(ler,"sim") == 0){countAnsiedade++;}
if(countAnsiedade==2){countAnsiedadeGeral++;}
countWhile++;

}
printf("%d\n",countAnsiedadeGeral);
}