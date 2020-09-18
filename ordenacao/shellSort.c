//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definicoes Gerais
typedef int item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {item t=A; A=B, B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

//Funcoes
void ordena(int *v, int l, int r, int h);
void shellSort(int *v, int l, int r);

//Main
int main(){
    int n;
    scanf("%d", &n);

    int *valores = malloc (n*sizeof(int));

    for(int i=0, j = n; i<n; i++, j--){
        int v;
        scanf("%d", &v);
        valores[i] = v;
    }

    shellSort(valores, 0, n-1);

    for(int i=0; i < n-1; i++)
        printf("%d ", valores[i]);

    printf("%d\n", valores[n-1]);
    
    return 0;
}

//Desenvolvimento funcoes
void ordena(int *v, int l, int r, int h){
    for(int i=l+h; i <=r; i++){
        int j = i;
        item tmp = v[i];
        while (j>=l+h && less(tmp, v[j-h])){
            v[j] = v[j-h];
            j-=h;
        }
        v[j] = tmp;
    }
}

void shellSort(int *v, int l, int r){
    int h;
    for(h = 1; h <= (r-l)/9; h = 3*h+1);
    for(; h>0; h=h/3)
        ordena(v, l, r, h);
}