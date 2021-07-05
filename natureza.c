#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tamanhoTabela = 5002;
int countHash = 0;
 int cidadeJoao = -1;
int componenteCidadeJoao = 0;
int maiorComponenteConexa = 0;
int valorMenorIndiceComponenteConexa = 999999;
int qntMaiorCompConexa;
 
typedef struct componentes{
    int qnt;
    int menor;
    int maior;
}componentes;


int countConexoes = 0;
componentes *componentesConexos;
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




int stringParaInt(char *string) {
    int tamanho, primeira, segunda; //Inteiros que representam o tamanho,
                                    //o código da primeira letra da string
                                    //e o código da segunda letra.
    tamanho =  strlen(string);      //Mede o tamanho da string
    primeira = string[0];           //Obtém o código da primeira letra
    segunda = string[1];            //Obtém o código da segunda letra
    int resultado = (tamanho * primeira) + segunda; //Função de transformação
    return resultado;  //Retorna número que representa a string
    }

int hash(int valor) {
    return valor % tamanhoTabela;  
    }

int BB(int *tabela,char *c){
    
    for(int i=0;i<countHash;i++){
        if(tabela[i] == hash(stringParaInt(c))){
            return i;
        }
    }
return -1;
}

int dfsR(Graph G, Edge e){
    int t,w = e.w;
     countConexoes++;
    pre[w] = cnt++;
    for(t=0;t<G->V;t++){
        
        if(G->adj[w][t]!=0){
           
            if(pre[t]==-1){
                
                dfsR(G,EDGE(w,t));
            }
                
    }}
    
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
            qntMaiorCompConexa = componentesConexos[componentesC].qnt;
            if(componentesConexos[componentesC].qnt> componentesConexos[maiorComponenteConexa].qnt){
                maiorComponenteConexa = componentesC;
                valorMenorIndiceComponenteConexa = v;
                qntMaiorCompConexa = componentesConexos[componentesC].qnt;
            }
            
            componentesC++;
        }
    }
    return componentesC;
}



int main(){
int C, R;
char Clido[32];
char Clido1[32];
int *tabelaHash;
componentesConexos = malloc(sizeof(componentesConexos)*5000);
tabelaHash = malloc(sizeof(int)*5002);
while(scanf("%d %d",&C,&R) && C !=0 || R!=0){
    countHash = 0;
    cidadeJoao = -1;
    componenteCidadeJoao = 0;
    maiorComponenteConexa = 0;
    valorMenorIndiceComponenteConexa = 999999;
    qntMaiorCompConexa = 0;

    Graph g = graphInit(C);
    memset(tabelaHash,0,5002);
    for(int cc=0;cc<C;cc++){
        pre[cc] = -1;
    }
    for(int i=0;i<C;i++){
        scanf("%s",Clido);
        if(BB(tabelaHash,Clido) == -1)
        tabelaHash[countHash] = hash(stringParaInt(Clido));
        countHash++;
    }
    for(int j=0;j<R;j++){
        if(scanf("%s %s",Clido,Clido1)){
             graphInsertE(g,EDGE(BB(tabelaHash,Clido),BB(tabelaHash,Clido1)));
             graphInsertE(g,EDGE(BB(tabelaHash,Clido1),BB(tabelaHash,Clido)));
        }
           
    }
search(g);

printf("%d\n",componentesConexos[maiorComponenteConexa].qnt);
free(g);
}



    return 0;
}
