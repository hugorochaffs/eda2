#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1001
int N;
int coordX[MAX];
int coordY[MAX];
int countN=0;
int Graph[MAX][2];
int visited[MAX];


void dfsR(int no){
    
    visited[no] = 1;
  
 for (int i = 0; i < 2; i++)
 {
  if (visited[Graph[no][i]]==0) dfsR(Graph[no][i]);
 }
}

int main(){
    

    while(scanf("%d",&N) && N!=0){
        for(int i=0;i<N;i++){
        scanf("%d %d",&coordX[countN],&coordY[countN]);
        countN++;
        }
        

        for(int i=0;i<N;i++){
            int distanciaA = 0;int distanciaB = 0;
            Graph[i][0] = -1;Graph[i][1] = -1;

            for(int j=0;j<N;j++){
                if(!(j==i)){
                    int distancia = ((coordX[i]-coordX[j])*(coordX[i]-coordX[j]))+((coordY[i]-coordY[j])*(coordY[i]-coordY[j]));
                    if(Graph[i][0] == -1){Graph[i][0] = j;distanciaA = distancia;}
                    else if(Graph[i][1] == -1){
                        Graph[i][1] = j;distanciaB = distancia;
                        if(distanciaA>distanciaB || (Graph[i][1] < Graph[i][0]&& distanciaB == distanciaA)){
                        int aux = distanciaA;
                        distanciaA = distanciaB;
                        distanciaB = aux;
                        aux = Graph[i][1];
                        Graph[i][1] = Graph[i][0];
                        Graph[i][0] = aux;
                        }
                        }
                    else{
                        if(distanciaA == distancia){
                            if(j < Graph[i][1]){
                                Graph[i][1] = j;
                            }
                        if(distanciaA>distanciaB || (Graph[i][1] < Graph[i][0]&& distanciaB == distanciaA)){
                        int aux = distanciaA;
                        distanciaA = distanciaB;
                        distanciaB = aux;
                        aux = Graph[i][1];
                        Graph[i][1] = Graph[i][0];
                        Graph[i][0] = aux;
                        }

                        }
                        else if(distanciaA> distancia){
                            Graph[i][1] = j;
                            distanciaA = distancia;
                            if(distanciaA>distanciaB || (Graph[i][1] < Graph[i][0]&& distanciaB == distanciaA)){
                        int aux = distanciaA;
                        distanciaA = distanciaB;
                        distanciaB = aux;
                        aux = Graph[i][1];
                        Graph[i][1] = Graph[i][0];
                        Graph[i][0] = aux;
                        }
                        }
                    }
                }
            }

        }
        
        
        for (int i = 0; i < N; i++) visited[i] = 0;
        dfsR(0);
        int ok = 1;
        for (int i = 0; i < N; i++){if (visited[i] == 0) {ok= 0;break;}}

   if (ok == 1) printf("All stations are reachable.\n");
  else printf("There are stations that are unreachable.\n");
        
    }


    return 0;
}