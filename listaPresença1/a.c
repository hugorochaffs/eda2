#include <stdio.h>
int n = 0;
int num=0;
int vet[140001];



void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void 
buscaBinaria (int x, int n, int v[]) { 
    int encontrado = 0;
   int e = -1, d = n; 
   while (e <= d && !encontrado) {  
      int m = (e + d)/2;
      if(vet[m] == x)
encontrado = 1;
else if(x<vet[m])
d= m-1;
else
e = m+1;     
   }
  if(encontrado){printf("sim\n");}else{printf("nao\n");}
}



int main(void){
scanf("%d",&n);

for(int i=0;i<n;i++){
    scanf("%d",&num);
    vet[i] = num;
}

mergeSort(vet,0,n-1);

int valB;
while(scanf("%d", &valB)!= EOF){
buscaBinaria(valB,n,vet);
}





return 0;
}