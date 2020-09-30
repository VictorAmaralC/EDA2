#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {int t=A; A=B, B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

void ordena(int *v, int l, int r);
int separa(int *v, int l, int r);

int main(){
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

void ordena(int *v, int l, int r){
    int j;
    if(r <= l) return;
    j = separa(v, l, r);
    
    ordena(v, l, j-1);
    ordena(v, j+1, r);
}

int separa(int *v, int l, int r){
    int c = v[r];
    int j = l;
    for(int k = l; k<r; k++)
        if(less(v[k], c)){
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}