#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERIFICADO 1
#define NAOVERIFICADO 0
#define MAX 1000

int Matriz[MAX][MAX];
int pre[MAX];
int distancia[MAX];

void matrixInit(){
    memset(Matriz,10,sizeof(Matriz));
}

void initDijkstra(){
    memset(distancia,100,sizeof(distancia));
    memset(pre,0,sizeof(pre));
    distancia[0] = 0;
}

int dijkstra( int init,int n, int m){
    initDijkstra();
    int antN = n-1;
    while(1){
        int pil = init;
        int i = 0;
        
        while(i<n){
            if(pre[i] == NAOVERIFICADO && (distancia[i]<distancia[pil] || pil == init)){
                pil = i;
            }
            i++;
            }
        
        if(pil == init)
            break;
        pre[pil] = VERIFICADO;
        
        i=0;
        while(i<n){
            if(distancia[i]>Matriz[pil][i]+distancia[pil])
                distancia[i] = Matriz[pil][i]+distancia[pil];

            i++;

        }}

    return distancia[antN];
    }







int main(){
matrixInit();
int N,M,S,T,B;

scanf("%d %d",&N,&M);


for(int i=0;i<M;i++){
    scanf("%d %d %d",&S,&T,&B);
    Matriz[S][T] = B;
    Matriz[T][S] = B;
    
}
int valInitDijkstra = -1;
int res = dijkstra(valInitDijkstra,N+2,M);

printf("%d\n",res);


return 0;
}