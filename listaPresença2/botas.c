#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int l1;
char l2;
int vetD[61];
int vetE[61];



int main(){

for(int i=30;i<60;i++){
    vetD[i] = 0;
    vetE[i] = 0;
}


while(scanf("%d %c",&l1,&l2)!= EOF){

    if(l2 == 'D')
    {vetD[l1]++;}
    if(l2 == 'E')
    {vetE[l1]++;}


}
int pares = 0;
for(int i = 30; i<61;i++){

    if(vetD[i]>0 && vetE[i]>0 ){
       if(vetD[i]<=vetE[i]){
       pares +=vetD[i];}
       else
       {
           pares+=vetE[i];
       }
       

    }
}
printf("%d\n",pares);





    return 0;
}