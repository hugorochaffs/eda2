#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2002
int graf[MAX][MAX];
int consultas[MAX][MAX];
int V;
int visited[MAX];
int CountGraf = 0;
void limpaVisitas(){
    memset(visited,0,sizeof(visited));
}

static int cnt;
// AQUI ADT DO GRAFO (Edge -> ARESTA)
 typedef struct {
    int v; int w;
}Edge;

Edge EDGE(int v,int w){
    Edge b;
    b.v = v;
    b.w = w;
    return b;
}



// ESTRUTURA DOS GRAFOS
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
    }
}

void graphRemoveE(Graph G, Edge E){
    int v = E.v;
    int w = E.w;
    if(G->adj[v][w] == 1){
        G->E--;
    }
}







static void reachR( Graph G, int v) 
{ 
   visited[v] = 1;
   for (int w = 0; w < G->V; ++w)
      if (G->adj[v][w] == 1 && visited[w] == 0)
         reachR( G, w);
}

int GRAPHreach( Graph G, int s, int t) 
{ 
    if(s==t) return 1;
   for (int v = 0; v < G->V; ++v)
      visited[v] = 0;
   reachR( G, s);
   if (visited[t] == 0) return 0;
   else return 1;
}



int buff(Graph g,int a, int b){
if(consultas[a][b] == -1){
    consultas[a][b] = GRAPHreach(g,a,b);
    return consultas[a][b];
}
if(consultas[a][b] == 0){
    return 0;
}
if(consultas[a][b] == 1){
    return 1;
}

}



int main(){
    int v,w,d,t,x;
    scanf("%d",&V);
    if(V < 2){return 0;}
    if(V>100){return 0;}
    Graph g= graphInit(V);
    memset(consultas,-1,sizeof(consultas));
    while(scanf("%d %d %d",&v,&w,&d) && !(v== 0 && w==0 && d==0)){
        
        if(d == 1){
            graphInsertE(g,EDGE(v,w));
        }
        if(d == 2){
            graphInsertE(g,EDGE(v,w));
            graphInsertE(g,EDGE(w,v));
        }
        
    }

    while(scanf("%d %d",&t,&x) != EOF){
        int ida=0,volta=0;
        if(buff(g,t,x))
            ida = 1;
        if(buff(g,x,t))
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



free(g);

    return 0;
}