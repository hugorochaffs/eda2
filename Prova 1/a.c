#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A,B)(A<B)
#define lesseq(A,B)(A<=B)
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B){if (less(B,A)) exch(A,B);}


void merge(Item *v,int l,int r1,int r2){

    Item *vAux = malloc(sizeof(Item)*(r2-l+1));
    int k= 0;
    int i= l;
    int j = r1+1;

    while(i<= r1 && j<=r2){
       if(less(v[i],v[j])){
           vAux[k++] = v[i++];
       }
       else{
           vAux[k++] = v[j++];
       }
    }
while(i<=r1){
    vAux[k++] = v[i++];
}
while(j<=r2){
    vAux[k++] = v[j++];
}
k=0;
int anterior = 0;
for(i=l;i<=r2;i++){
    int aux = k++;
v[i] = vAux[aux];


        
    }
    


free(vAux);
}

int buscaBinaria (int x, int n, Item v[]) { 
    int encontrado = 0;
   int e = -1, d = n; 
   while (e <= d && !encontrado) {  
      int m = (e + d)/2;
      if(v[m] == x)
encontrado = 1;
else if(x<v[m])
d= m-1;
else
e = m+1;     
   }
  if(encontrado){return 1;}else{return 0;}
}





void mergeSort(Item *v,int l,int r){
    if(l>=r)return;
    int meio = (r+l)/2;
    mergeSort(v,l,meio);
    mergeSort(v,meio+1,r);
    merge(v,l,meio,r);
}





int main(){

    int teste;
    int nTestes=0,numeroLido =0;

scanf("%d",&nTestes);
Item *vetor = malloc(sizeof(Item)*(65000));
Item *vetor2 = malloc(sizeof(Item)*(65000));
Item *vetorMalucos = malloc(sizeof(Item)*(65000));

for(int i = 0;i<nTestes;i++){
    scanf("%d",&numeroLido);
    vetor[i]= numeroLido;
}

mergeSort(vetor,0,nTestes-1);
int nV2 =0;
for(int i =0;i<nTestes;i++){
    if(nV2>0){
        if(vetor2[nV2-1] == vetor[i]){
        }
        else{
            vetor2[nV2] = vetor[i];
            nV2++;
        }

    }
    else{
        vetor2[nV2] = vetor[i];
            nV2++;
    }
}

if(nV2%2 == 0){
    //par
}
else{
    //impar
    vetor2[nV2] = 1000000000;
    nV2++;
}

int qntPares = nV2/2;
int n1 =0;
int n2 = 1;

for(int h = 0;h<qntPares;h++){
    int soma = vetor2[n1] + vetor2[n2];
    vetorMalucos[h] = soma;
    n1 = n1+2;
    n2 = n2+2;
}

for(int p = 0;p<qntPares;p++){
    if(buscaBinaria (vetorMalucos[p],nV2, vetor2) == 0){
vetor2[nV2] = vetorMalucos[p];
nV2++; 

    }
}

mergeSort(vetor2,0,nV2-1);


for(int k = 0;k<nV2;k= k+4)
printf("%d\n",vetor2[k]);
printf("Elementos: %d\n",nV2);

free(vetor);
free(vetor2);
free(vetorMalucos);

    return 0;
}