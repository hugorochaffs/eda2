/* Solucao para o problema "Caminho das Pontes" da OBI 2009
   por: Igor Ribeiro de Assis */
#include <stdio.h>
#include <string.h> 		/* memset() */

#define MAXN 1010

/* matriz de adjacencias */
int A[MAXN][MAXN], visitado[MAXN], dis[MAXN];

int n, m;

int dijkstra() {
  int i;

  memset(dis, 0x3f, sizeof(dis)); /* distancia inicial infinita */
  memset(visitado, 0, sizeof(visitado));
  dis[0] = 0;

  for (;;) {
    int no = -1;
    for (i = 0; i < n; i++)
      if (!visitado[i] && (no == -1 || dis[i] < dis[no]))
	no = i;

    if (no == -1) break;
    visitado[no] = 1;

    for (i = 0; i < n; i++)
      if (dis[no] + A[no][i] < dis[i])
	dis[i] = dis[no] + A[no][i];
  }    

  return dis[n-1];
}

int main() {
  int i;
  int s, t, b;

  scanf("%d%d", &n, &m);
  n += 2; /* imagina os as bordas como pilares */
  memset(A, 0x3f, sizeof(A));	/* numero de buracos infinito */
  for (i = 0; i < m; i++) {
    scanf("%d%d%d", &s, &t, &b);
    A[s][t] = A[t][s] = b;
  }
  
  printf("%d\n", dijkstra());

  return 0;
}
