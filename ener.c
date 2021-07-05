#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 int pre[102];
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



void GRAPHshow( Graph G) { 
   for (int v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (int w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

void searchR(Graph g,int valor,int tamanho){

    if(pre[valor]){
        return;
    }
    pre[valor] = 1;

    for(int i=1;i<=tamanho;i++){
        if(g->adj[valor][i] == 1)
            searchR(g,i,tamanho);
    }

    
}

int main(){
    int E,L,X,Y;
    int countTeste = 1;
 

    while(scanf("%d %d",&E,&L) && (E!=0 && L!=0)){
        int falhadetectada=0;
        Graph g = graphInit(E*2);
        memset(pre,0,sizeof(pre));
    
        for(int countL=0;countL<L;countL++){
            scanf("%d %d",&X,&Y);
            graphInsertE(g,EDGE(X,Y));
            graphInsertE(g,EDGE(Y,X));
        }
        searchR(g,1,E);

        for(int i=1;i<=E && falhadetectada==0;i++){
            if(pre[i] == 0){
                falhadetectada = 1;
                printf ("Teste %d\nfalha\n\n", countTeste);
                countTeste++;

            }
        }
        if(falhadetectada== 0){
            printf ("Teste %d\nnormal\n\n", countTeste);
            countTeste++;}
    }
}