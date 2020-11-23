//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definicoes Gerais
typedef int item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)    \
    {                 \
        item t = A;   \
        A = B, B = t; \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }
int quickTrapStop = 0;

//Funcoes
void introSort  (int *v, int l, int r);
void quicksort  (int *v, int l, int r, int maxRec);
int  separa     (item *v, int l, int r);
void mergeSort  (int *v, int l, int r);
void merge      (int *v, int l, int r1, int r2);
void insertionSort(int *v, int l, int r);

//Main
int main()
{
    int n;
    scanf("%d", &n);

    int *valores = malloc(n * sizeof(int));

    for (int i = 0, j = n; i < n; i++, j--)
    {
        int v;
        scanf("%d", &v);
        valores[i] = v;
    }

    introSort(valores, 0, n - 1);

    for (int i = 0; i < n - 1; i++)
        printf("%d ", valores[i]);

    printf("%d\n", valores[n - 1]);

    return 0;
}

//Desenvolvimento funcoes
void introSort(int *v, int l, int r)
{
    int maxRec = 2*log2((r-l+1));

    quicksort(v,l,r, maxRec);
    if(quickTrapStop == 1){
        mergeSort(v, l, r);
    } else
        insertionSort(v, l, r);
}

void quicksort(int *v, int l, int r, int maxRec)
{
    if(quickTrapStop == 1) return;
    if(maxRec == 0){
        quickTrapStop = 1; 
        return;
    }
    if(l-r <= 32)   return;

    exch(v[(l + r) / 2], v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int j = separa(v, l + 1, r - 1);

    quicksort(v, l, j - 1, maxRec-1);
    quicksort(v, j + 1, r, maxRec-1);
}

int separa(item *v, int l, int r)
{
    item c = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], c))
        {
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void mergeSort(int *v, int l, int r)
{
    if (l >= r)
        return;
    int meio = (r + l) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
}

void merge(int *v, int l, int r1, int r2)
{
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

void insertionSort(int *v, int l, int r)
{
    for (int i = r; i > l; i--)
    {
        cmpexch(v[i - 1], v[i]);
    }
    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        item tmp = v[j];
        while (less(tmp, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = tmp;
    }
}