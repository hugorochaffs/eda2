#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5002

int graph[MAX][MAX];
int visited[MAX];
int quantidade,c,r;
typedef char * string;

char nomesLidos[5002][31];

int BinarySearch( char* key, int low, int high) 
{
   int mid, cmp;

   if (low > high) return -1;
   mid = (low + high) / 2;
   cmp = strcmp( key, nomesLidos[mid]);
   if (cmp == 0 ) 
      return mid;
   if (cmp < 0) 
      return BinarySearch( key, low, mid - 1); 
   else 
      return BinarySearch( key, mid + 1, high); 
}

void ordenaMatriz(int tamanho){
    int i,j;
    char aux[32];
    for (i = 1; i < tamanho; i++) {
   for (j = 1; j < tamanho; j++) {
      if (strcmp(nomesLidos[j - 1], nomesLidos[j]) > 0) {
         strcpy(aux, nomesLidos[j - 1]);
         strcpy(nomesLidos[j - 1], nomesLidos[j]);
         strcpy(nomesLidos[j], aux);
      }
   }
}
}

void buscar(int v, int c){
    quantidade++;
    visited[v] = 1;
    for(int i=0;i<c;i++){
        if(graph[v][i] && !visited[i])
            buscar(i,c);
    }
}



int main(){
    char s[31],q[31];
    int *tabelaHash;
    tabelaHash = malloc(sizeof(int)*5002);
    while(scanf("%d %d",&c,&r) && c+r>0){
        memset(nomesLidos,0,sizeof(nomesLidos));
        for(int i=0;i<c;i++){
            scanf("%s",nomesLidos[i]);
        }
        ordenaMatriz(c);
        memset(graph,0,sizeof(graph));
        
        for(int i=0;i<r;i++){
            scanf("%s %s",s,q);
            int indices = BinarySearch(s,0,c);
            int indiceq = BinarySearch(q,0,c);
            graph[indices][indiceq] = 1;
            graph[indiceq][indices] = 1;

        }

        int qntMax = 0;
        memset(visited,0,sizeof(visited));

        for(int i = 0; i<c;i++){
            quantidade =0;
            if(!visited[i]){
                buscar(i,c);
                if(quantidade>qntMax){
                    qntMax = quantidade;
                }
            }

        }
        printf("%d\n",qntMax);



    }






    return 0;
}