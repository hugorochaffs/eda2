#include <stdio.h>

long long int raio[100001];

int c, t;


int busca(long long int x){
int esq = 1;
int dir = c;

if(x>raio[c]) return 0;

while(esq<dir){
    int m = (esq+dir)/2;
    if(raio[m]>=x)
    dir = m;
    else
    esq = m+1;
    
}
return c+1-dir;


}

int main(){
    long long int raioaux;
scanf("%d %d",&c,&t);

for (int i =1;i<=c;i++){
scanf("%lld",&raioaux);
raio[i] = raioaux*raioaux;
}

long long int pontos = 0;
for(int i=1;i<=t;i++){
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    pontos = pontos+busca((x*x)+(y*y));
}

printf("%lld\n",pontos);


    return 0;

}