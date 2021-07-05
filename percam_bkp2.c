#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2002
int graf[MAX][MAX];
int V;
int visited[MAX];
int CountGraf = 0;
void limpaVisitas(){
    memset(visited,0,sizeof(visited));
}

static void reachR( int v) 
{ 
   visited[v] = 1;
   for (int w = 0; w < V; ++w)
      if (graf[v][w] == 1 && visited[w] == 0)
         reachR(w);
}

int GRAPHreach( int s, int t) 
{ 
    if(s==t)return 1;
    limpaVisitas();
   for (int v = 0; v <V; ++v)
      visited[v] = 0;
   reachR(s);
   if (visited[t] == 0) return 0;
   else return 1;
}



int main(){
    int v,w,d,t,x;
    scanf("%d",&V);
    memset(graf,0,sizeof(graf));
    while(scanf("%d %d %d",&v,&w,&d) && !(v== 0 && w==0 && d==0)){
        if(d == 1){
            graf[v][w] = 1;
            CountGraf++;
        }
        if(d == 2){
            graf[v][w] = 1;
            graf[w][v] = 1;
            CountGraf++;
        }
        
    }
    while(scanf("%d %d",&t,&x) != EOF ){
        int ida=0,volta=0;
        if(GRAPHreach(t,x))
            ida = 1;
        if(GRAPHreach(x,t))
            volta = 1;
        if(ida == 1 && volta == 1)
            printf("Ida e Volta\n");
        else if(ida)
            printf("Apenas Ida\n");
        else if(volta)
            printf("Apenas Volta\n");
        else
            printf("Impossibru\n");
    }




    return 0;
}