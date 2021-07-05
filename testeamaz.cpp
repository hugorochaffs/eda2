#include<stdio.h>
#include<queue>

using namespace std;

int grafo[42][42];	
int distancia[42][42];
int cores[42][42];
int n;

void BFS(pair<int, int> s){
	distancia[s.first][s.second] = 0;
	cores[s.first][s.second] = 1;
	queue <pair<int,int> > q;
	q.push(s);

	while(!q.empty()){
		pair<int,int> v = q.front();q.pop();

		for(int i=0; i<8; i++){
			int x = v.first + a[i]; 
			int y = v.second + b[i];
			if(grafo[x][y] == 1 && cores[x][y] == 0){
				q.push(make_pair(x,y));
				cores[x][y] = 1;
				distancia[x][y] = distancia[v.first][v.second]+1;
			}
		}

		cores[v.first][v.second] = 2;
	}
}


int main(){
	scanf("%d", &n);
	while(n != 0){
		for(int i=0; i<42; i++){
			for(int j=0; j<42; j++){
				distancia[i][j] = 0;
				cores[i][j] = 0;
				grafo[i][j] = 0;	
			}
		}
		pair<int,int> p;
		queue<pair<int,int> > estacoes;
		for(int i=0; i<n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			grafo[x+20][y+20] = 1;
			if(i == 0){
				p = make_pair(x+20, y+20);
			}
			estacoes.push(make_pair(x+20,y+20));
		}
		
		BFS(p);
		while(!estacoes.empty()){
			pair <int,int> p2 = estacoes.front(); 
			if(cores[p2.first][p2.second] == 0) break;
			estacoes.pop();
		}

		if(!estacoes.empty()) printf("There are stations that are unreachable.\n");
		else printf("All stations are reachable.\n");
		 
		scanf("%d", &n);
	}
	return 0;
}
