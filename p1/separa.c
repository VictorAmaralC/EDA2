#include <stdio.h> 
#include <stdlib.h>

int sep(int v[], int p, int r)
{
    int q, i, j, t;
    i = p;
    q = (p + r) / 2;
    j = r;
    do
    {
        while (v[i] < v[q]){
            ++i;
        }
        while (v[j] > v[q])
        {
            --j;
        }
        if (i <= j)
        {
            t = v[i], v[i] = v[j], v[j] = t;
            ++i, --j;
        }
    } while (i < j);
    return i;
}

int main(){
    int v[6] = {4, 3, 5, 2, 1, 4};
    int indice;

    indice = sep(v, 0, 5);

    printf("%d\n", indice);
    for(int i = 0; i<6; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}