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
int quickTrapStop = 0;

typedef struct{
    int nota;
    int id;
}semente;

//Chamada das funcoes
void quickSelect(semente *v, int l, int r, int k);
int  separa     (semente *v, int l, int r);
void introSort  (semente *v, int l, int r);
void quickSort  (semente *v, int l, int r, int maxRec);
int  separa2    (semente *v, int l, int r);
void mergeSort  (semente *v, int l, int r);
void merge      (semente *v, int l, int r1, int r2);
void insertionSort(semente *v, int l, int r);

//Main
int main()
{
    int k, i=0, aux = 1, id, nota;
    scanf("%d", &k);
    semente *sem = malloc(aux*sizeof(semente));

    while(scanf("%d %d", &id, &nota) != EOF){
        if(i == aux){ 
            sem = realloc(sem, (aux*2)*sizeof(semente));
            aux *= 2;
        }
        
        sem[i].id = id;
        sem[i].nota = nota;
        i++;
    }

    quickSelect(sem, 0, i - 1, k);
    introSort(sem, 0, k-1);

    for (int j = 0; j < k; j++)
    {
        printf("%d %d\n", sem[j].id, sem[j].nota);
    }
    
    return 0;
}

//Desenvolvimento funcoes
void quickSelect(semente *v, int l, int r, int k)
{
    if (l >= r)
        return;
    int i = separa(v, l, r);
    if (i > k)
        quickSelect(v, l, i - 1, k);
    if (i < k)
        quickSelect(v, i + 1, r, k);
}

int separa(semente *v, int l, int r)
{
    int c = v[r].nota;
    int d = v[r].id;
    int j = l;

    for (int k = l; k < r; k++){
        if (less(v[k].nota, c))
        {
            exch(v[k].nota, v[j].nota);
            exch(v[k].id, v[j].id);
            j++;
        } else if (v[k].nota == c && v[k].id < d){
            exch(v[k].nota, v[j].nota);
            exch(v[k].id, v[j].id);
            j++;
        }
    }

    exch(v[j].nota, v[r].nota);
    exch(v[j].id, v[r].id);

    return j;
}

void introSort(semente *v, int l, int r)
{
    int maxRec = 2 * log2((r - l + 1));

    quickSort(v, l, r, maxRec);
    if (quickTrapStop == 1)
    {
        mergeSort(v, l, r);
    }
    else
        insertionSort(v, l, r);
}

void quickSort(semente *v, int l, int r, int maxRec)
{
    if (quickTrapStop == 1)
        return;
    if (maxRec == 0)
    {
        quickTrapStop = 1;
        return;
    }
    if (r <= l)
        return;

    int j = separa2(v, l, r);

    quickSort(v, l, j - 1, maxRec-1);
    quickSort(v, j + 1, r, maxRec-1);
}

int separa2(semente *v, int l, int r)
{
    int c = v[r].id;
    int j = l;

    for (int k = l; k < r; k++)
        if (less(v[k].id, c))
        {
            exch(v[k].nota, v[j].nota);
            exch(v[k].id, v[j].id);
            j++;
        }
    
    exch(v[j].nota, v[r].nota);
    exch(v[j].id, v[r].id);

    return j;
}

void mergeSort(semente *v, int l, int r)
{
    if (l >= r)
        return;
    int meio = (r + l) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
}

void merge(semente *v, int l, int r1, int r2)
{
    semente *v2 = malloc(sizeof(semente) * (r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2)
    {
        if (less(v[i].id, v[j].id)){
            v2[k++].id = v[i++].id;
            v2[k++].id = v[i++].id;
        }
        else{
            v2[k++].id = v[j++].id;
            v2[k++].nota = v[j++].nota;
        }
    }

    while (i <= r1){
        v2[k++].id = v[i++].id;
        v2[k++].nota = v[i++].nota;
    }
    while (j <= r2){
        v2[k++].id = v[j++].id;
        v2[k++].nota = v[j++].nota;
    }

    k = 0;
    for (int i = l; i <= r2; i++)
    {
        v[i].id = v2[k++].id;
        v[i].nota = v2[k++].nota;
    }
    free(v2);
    return;
}

void insertionSort(semente *v, int l, int r)
{
    for (int i = r; i > l; i--)
    {
        if(v[i].id < v[i-1].id){
            exch(v[i].id, v[i-1].id);
        }
    }
    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        int tmp = v[j].id;
        int tmp2 = v[j].nota;

        while (less(tmp, v[j - 1].id))
        {
            v[j].id = v[j - 1].id;
            v[j].nota = v[j - 1].nota;
            j--;
        }
        v[j].id = tmp;
        v[j].nota = tmp2;
    }
}