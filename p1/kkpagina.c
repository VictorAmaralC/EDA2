#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)    \
    {                 \
        int t = A;   \
        A = B, B = t; \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

void quickSelect(int *v, int l, int r, int k);
int separa(int *v, int l, int r);
void quickSort(int *v, int l, int r);

int main()
{
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    int *v = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        int id;
        scanf("%d", &id);
        v[i] = id;
    }

    int l, r;
    l = x*p;
    if (l > n) return 0;

    r = l + x - 1;
    if(r >= n) r = n-1;
    
    quickSelect(v, 0, n-1, l);
    quickSelect(v, l, n-1, r);
    quickSort  (v, l, r);


    for(int i = l; i <=r; i++)
        printf("%d\n", v[i]);

    return 0;
}

void quickSelect(int *v, int l, int r, int k)
{
    if (l >= r)
        return;
    int i = separa(v, l, r);
    if (i > k)
        quickSelect(v, l, i - 1, k);
    if (i < k)
        quickSelect(v, i + 1, r, k);
}

int separa(int *v, int l, int r)
{
    int c = v[r];
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

void quickSort(int *v, int l, int r)
{
    if (r <= l)
        return;

    int j = separa(v, l, r);

    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}