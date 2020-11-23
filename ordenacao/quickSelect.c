//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

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

//Funcoes
int separa(item *v, int l, int r);
void quickSelect (item *v, int l, int r, int k);

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

    quickSelect(valores, 0, n - 1, (n-1)/2);

    for (int i = 0; i < n - 1; i++)
        printf("%d ", valores[i]);

    printf("%d\n", valores[n - 1]);

    return 0;
}

//Desenvolvimento funcoes
void quickSelect(item *v, int l, int r, int k)
{
    if (l >= r)
        return;
    int i = separa(v, l, r);
    if (i > k)
        quickSelect(v, l, i - 1, k);
    if (i < k)
        quickSelect(v, i + 1, r, k);
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

