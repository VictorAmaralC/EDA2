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
void ordena(int *v, int l, int r);
void merge(int *v, int l, int r1, int r2);

    //Main
    int main()
{
    int n;
    scanf("%d", &n);

    int *valores = malloc (n*sizeof(int));

    for(int i=0, j = n; i<n; i++, j--){
        int v;
        scanf("%d", &v);
        valores[i] = v;
    }

    ordena(valores, 0, n-1);

    for(int i=0; i < n-1; i++)
        printf("%d ", valores[i]);

    printf("%d\n", valores[n-1]);
    
    return 0;
}

//Desenvolvimento funcoes
void ordena(int *v, int l, int r){
    if(l>=r) return;
    int meio = (r+l)/2;
    ordena(v, l, meio);
    ordena(v, meio+1, r);
    merge(v, l, meio, r);
}

void merge(int *v, int l, int r1, int r2){
    int *v2 = malloc(sizeof(item) * (r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2)
    {
        if (less(v[i], v[j]))
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }

    while (i <= r1)
        v2[k++] = v[i++];
    while (j <= r2)
        v2[k++] = v[j++];

    k = 0;
    for (int i = l; i <= r2; i++)
    {
        v[i] = v2[k++];
    }
    free(v2);
    return;
}