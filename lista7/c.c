#include <stdio.h>
#include <stdlib.h>

int bb(int v[],int pos[],int val, int tam){
int esq = -1;int dir = tam;int meio;
int fim =0;int a;
while(esq<dir-1){
    meio = (esq+dir)/2;
    if(v[meio] ==val)
    fim = 1;
if(v[meio]<val)
esq = meio;
else
dir = meio;
}
if (fim == 1){
    for(a=0;a<tam;a++){
        if(pos[a] == val){return a;}
    }
}

return -1;
}

void subs(int *v1,int *v2){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

int main(){
int *v,*vpos,n,m;
int val;
scanf("%d %d",&n,&m);
v= malloc(n*sizeof(int));
vpos = malloc(n*sizeof(int));

for(int i = 0;i<n;i++){
    scanf("%d", &v[i]);
    vpos[i] = v[i];
}
for(int i = 1;i<n;i++){
    for(int j=i;v[j]<v[j-1]&&j>0;j--){
       subs(&v[j],&v[j-1]); 

    }
}

for(int i = 0;i<m;i++){
    scanf("%d",&val);
    printf("%d\n",bb(v,vpos,val,n));

}
    return 0;

}