#include <stdio.h>
#include <stdlib.h>

typedef struct velocidade{
    int D;
    int U;
}velocidade;

void merge(velocidade *V, int l, int m, int r)
{
  velocidade *R=malloc(sizeof(velocidade)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
      if(V[i].D == V[j].D){
           if(V[i].U<=V[j].U){
      R[k++]=V[i++];
    }

    else
      R[k++]=V[j++];
      }
      else{
    if(V[i].D<V[j].D){
      R[k++]=V[i++];
    }

    else
      R[k++]=V[j++];
  }
  }
  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}
void mergesort(velocidade *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

int main(){
int D,U,L,T;
scanf("%d %d %d %d",&D,&U,&L,&T);
float limiarD = (D*L)/100;
float limiarU = (U*L)/100;
int LeituraD,LeituraU;
struct velocidade* piores = malloc(sizeof(velocidade)*T+2);
int qntPiores = 0;

for(int i=0;i<T;i++){
    scanf("%d/%d",&LeituraD,&LeituraU);
    if(LeituraD < (D-limiarD) || LeituraU < (U-limiarU)){
        piores[qntPiores].D = LeituraD;
        piores[qntPiores].U = LeituraU;
        qntPiores++;
    }
}

mergesort(piores,0,qntPiores-1);

for(int j = 0;j<qntPiores;j++){
    printf("%d/%d\n",piores[j].D,piores[j].U);
}

    return 0;
}