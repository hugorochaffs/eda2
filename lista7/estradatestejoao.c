#include<stdio.h>
#include<stdlib.h>
 int pre[6000];
 int cidadeJoao = -1;
int componenteCidadeJoao = 0;
int maiorComponenteConexa = -1;
int valorMenorIndiceComponenteConexa = 999999;
 
typedef struct componentes{
    int qnt;
    int menor;
    int maior;
}componentes;


int countConexoes = 0;
componentes *componentesConexos;
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


int dfsR(Graph G, Edge e){
    int t,w = e.w;
    countConexoes++;
    pre[w] = cnt++;
    for(t=0;t<G->V;t++){
         
        if(G->adj[w][t]!=0){
           
            if(pre[t]==-1)
                dfsR(G,EDGE(w,t));
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


int search(Graph g){
    int v;
    int componentesC = 0;
    for(int v=0;v<g->V;v++)
        pre[v] = -1;
    for(int v=0;v<g->V;v++){
        if(pre[v] == -1){
             countConexoes = 0;
            dfsR(g,EDGE(v,v));
            if(cidadeJoao == v){
                componenteCidadeJoao = componentesC;
            }
            componentesConexos[componentesC].menor = v;
            componentesConexos[componentesC].qnt = countConexoes;
            if(componentesConexos[componentesC].qnt> componentesConexos[maiorComponenteConexa].qnt){
                maiorComponenteConexa = componentesC;
                valorMenorIndiceComponenteConexa = v;
            }
            if(componentesConexos[componentesC].qnt == componentesConexos[maiorComponenteConexa].qnt && valorMenorIndiceComponenteConexa> v){
                maiorComponenteConexa = componentesC;
                valorMenorIndiceComponenteConexa = v;
            }
            componentesC++;
        }
    }
    return componentesC;
}

int main(){
    int V,J;
    int v,w;
    componentesConexos = malloc(sizeof(componentesConexos)*5000);
    scanf("%d %d",&V,&J);
    cidadeJoao = J;
    Graph g = graphInit(V);
    for(int cc=0;cc<V;cc++){
        pre[cc] = -1;
    }


    while(scanf("%d %d",&v,&w) != EOF){
        graphInsertE(g,EDGE(v,w));
        graphInsertE(g,EDGE(w,v));

    }

int qntComponentes = search(g);

if(componenteCidadeJoao == maiorComponenteConexa && componentesConexos[componenteCidadeJoao].qnt != 0){
    printf("Bora pra estrada\n");
}
if(componenteCidadeJoao == maiorComponenteConexa && componentesConexos[componenteCidadeJoao].qnt == 0){
    printf("Fique em casa\n");
}
if(componentesConexos[componenteCidadeJoao].qnt < componentesConexos[maiorComponenteConexa].qnt){
    printf("Vamos para %d\n",valorMenorIndiceComponenteConexa);
}


    return 0;
}