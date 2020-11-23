#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lesseq(A, B) (key(A) <= key(B))

int *intercala2(int *v1, int n1, int *v2, int n2);
int *intercala4(int *v1, int n1, int *v2, int n2, int *v3, int n3, int *v4, int n4);
int *intercala8(int *v1, int n1, int *v2, int n2, int *v3, int n3, int *v4, int n4, int *v5, int n5, int *v6, int n6, int *v7, int n7, int *v8, int n8);

int main(){
    int *v[8];
    int t[8], tamTotal = 0;

    for(int i = 0; i < 8; i++){
        int tam;
        scanf("%d", &tam);

        tamTotal += tam;
        t[i] = tam;
        v[i] = malloc(tam*sizeof(int));

        for (int j = 0; j < tam; j++){
            int valor;
            scanf("%d", &valor);
            v[i][j] = valor;
        }
    }

    int *result = malloc(tamTotal*sizeof(int));
    result = intercala8(v[0], t[0], v[1], t[1], v[2], t[2], v[3], t[3], v[4], t[4], v[5], t[5], v[6], t[6], v[7], t[7]);

    for(int i = 0; i < tamTotal-1; i++)
        printf("%d ", result[i]);

    printf("%d\n", result[tamTotal-1]);

    return 0;
}

int *intercala2(int *v1, int n1, int *v2, int n2){
    int *result = malloc((n1 + n2) * sizeof(int));
    int p1 = 0, p2 = 0, rp = 0;

    while (p1 < n1 && p2 < n2)
    {
        int min;
        if (lesseq(v1[p1], v2[p2]))
        {
            result[rp] = v1[p1];
            p1++;
        }
        else
        {
            result[rp] = v2[p2];
            p2++;
        }
        rp++;
    }

    while (p1 < n1)
    {
        result[rp] = v1[p1];
        p1++;
        rp++;
    }

    while (p2 < n2)
    {
        result[rp] = v2[p2];
        p2++;
        rp++;
    }

    return result;
}

int *intercala4(int *v1, int n1, int *v2, int n2, int *v3, int n3, int *v4, int n4){
    int *left = intercala2(v1, n1, v2, n2);
    int tamLeft = n1 + n2;

    int *right = intercala2(v3, n3, v4, n4);
    int tamRight = n3 + n4;

    int *result = intercala2(left, tamLeft, right, tamRight);
    free(left);
    free(right);

    return result;
}

int *intercala8(int *v1, int n1, int *v2, int n2, int *v3, int n3, int *v4, int n4, int *v5, int n5, int *v6, int n6, int *v7, int n7, int *v8, int n8){
    int *left = intercala4(v1, n1, v2, n2, v3, n3, v4, n4);
    int tamLeft = n1 + n2 + n3 + n4;

    int *right = intercala4(v5, n5, v6, n6, v7, n7, v8, n8);
    int tamRight = n5 + n6 + n7 +n8;

    int *result = intercala2(left, tamLeft, right, tamRight);
    free(left);
    free(right);

    return result;
}