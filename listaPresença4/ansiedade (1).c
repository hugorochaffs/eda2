#include <stdio.h>
#include <string.h>

int main(){
char ler[3];
int countWhile =0;
int countAnsiedade = 0;
int countAnsiedadeGeral =0;
int compara =1;
while(scanf("%s",ler)!= EOF){
compara = strcmp(ler,"sim");
if(compara == 0){ countAnsiedade++;}
countWhile++;
if(countWhile == 10){
if(countAnsiedade>=2){countAnsiedadeGeral++;}
countAnsiedade=0;
countWhile =0;


}}
printf("%d\n",countAnsiedadeGeral);
}
