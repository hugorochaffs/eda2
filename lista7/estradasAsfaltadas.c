#include<stdio.h>
#include<stdlib.h>
 int pre[6000];
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


void dfsR(Graph G, Edge e){
    int t,w = e.w;
    pre[w] = cnt++;
    for(t=0;t<G->V;t++){
        if(G->adj[w][t]!=0)
            if(pre[t]==-1)
                dfsR(G,EDGE(w,t));
    }
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

int search(Graph g){
    int v;
    int componentes = 0;
    for(int v=0;v<g->V;v++)
        pre[v] = -1;
    for(int v=0;v<g->V;v++){
        if(pre[v] == -1){
            dfsR(g,EDGE(v,v));
            componentes++;
        }
    }
    return componentes;
}

int main(){
    int V;
    int v,w;
    scanf("%d",&V);
    Graph g = graphInit(V);
    for(int cc=0;cc<V;cc++){
        pre[cc] = -1;
    }


    while(scanf("%d %d",&v,&w) != EOF){
        graphInsertE(g,EDGE(v,w));
        graphInsertE(g,EDGE(w,v));

    }

printf("%d\n",search(g));




    return 0;
}