#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int cnt;
#define MAX 2000
int pre[2000];
int visited[2000];
typedef struct {
    int v; int w;
}Edge;

Edge EDGE(int v,int w){
    Edge b;
    b.v = v;
    b.w = w;
    return b;
}

struct graph {
    int V; //Quantos vértices
    int E; // Quantas arestas
    int **adj; // Matriz de adjacencia
};
typedef struct graph *Graph;

static int **matrixInit( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for (int i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

 Graph graphInit(int V){ //RECEBE A QUANTIDADE DE VERTICES
    Graph G = malloc(sizeof(*G));
    G->V = V; // Contador de vértices recebe V
    G->E = 0;// Contador de arestas recebe 0
    G->adj = matrixInit(V,V,0); //Chama uma função que cria um matriz VxV com zeros ASSISTIR VIDEO DE ALOCAÇÂO DINAMICA DE MATRIZES REV PONT DE PONT 
    return G;
}
void graphInsertE(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w] == 0){
        G->E++;
        G->adj[v][w] = 1;
        G->adj[w][v] = 1;
    }
}

void graphRemoveE(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w] == 1){
        G->E--;
    }
}

int graphEdges(Edge *a,Graph G){
    int v,w,E=0;
    for(v=0;v<G->V;v++){
        for(w=v+1;w<G->V;w++){
            if(G->adj[v][w] == 1){
                a[E++] = EDGE(v,w);
            }
        }
    }
return E;
}


int dfsR(Graph G, int buscado,Edge e){
    int t,w = e.w;
    pre[w] = cnt++;
    for(t=0;t<G->V;t++){
        
        if(G->adj[buscado][t]!=0){
           
            if(pre[t]==-1){
                dfsR(G,buscado,EDGE(w,t));
            }
                
    }}
    
}

void GRAPHshow( Graph G) { 
   for (int v = 0; v < G->V; ++v) {
       
      printf( "%2d:", v);
      for (int w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

int search(Graph g, int buscado){
    int v;
    int componentesC = 0;
    for(int v=0;v<g->V;v++)
        pre[v] = -1;
    for(int v=0;v<g->V;v++){
        if(pre[1] == -1){
             
                dfsR(g,buscado,EDGE(v,v));
            
            
        }
   }
    return componentesC;
}




int juliusEsteve[2000];



int main(){
int N,M,J,A,Alido,Mlido,Jlido;
memset(visited,0,sizeof(visited));
memset(juliusEsteve,0,sizeof(juliusEsteve));

    
scanf("%d %d %d",&N,&M,&J);
Graph g = graphInit(N);

for(int Cn=0;Cn<N;Cn++){
    scanf("%d",&A);
    for(int Ca=0;Ca<A;Ca++){
        scanf("%d",&Alido);
        graphInsertE(g,EDGE(A,Alido));
        graphInsertE(g,EDGE(Alido,A));
       
        
    }
}
for(int Cm=0;Cm<M;Cm++){
    scanf("%d",&Mlido);
    search(g,Mlido);
    for(int e=0;e<cnt;e++){
        if(pre[e] != -1)
            juliusEsteve[e]++;

    }
    


    
         
       }
   

for(int cJ=0;cJ<J;cJ++){
    scanf("%d",&Jlido);
    if(juliusEsteve[Jlido])
        printf("Eu vou estar la\n");
    else
        printf("Nao vou estar la\n");
    }
    






/*
for(int u=0;u<cJulianoEstara;u++){
   printf("%d\n",julianoEstara[u]);
}
*/
/*
 for (int v = 0; v < N; ++v) {
      printf( "%2d:", Mlido);
      for (int w = 0; w < N; ++w)
         if (graph[Mlido][w]) 
            printf( " %2d", w);
      printf( "\n");
   }
   */
    return 0;
}
