#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int chave;
    int nAparicao;
} item;

item NULLitem = {0, 0};

#define hash(v, m) ((618033 * (unsigned)v) % m)
#define key(x) (x.chave)
#define eq(a, b) (a == b)
#define null(a) (key(ht[a]) == key(NULLitem))

static int N, M;
static item *ht;

// Chamada Funcoes
void htInit(int max);
void htInsert(item item);
item htSearch(int v);
item defineMaior(item maior, item aux);
void ordena(item *v, int l, int r);
void merge(item *v, int l, int r1, int r2);

int main()
{
    char entrada[1000];

    while (scanf("%s", entrada) != EOF)
    {
        htInit(1009);
        item vet[1000];
        int j = 0;

        for(int i = 0; entrada[i] != '\0'; i++){
            item letra;
            letra.chave = entrada[i];
            letra.nAparicao = 1;
            htInsert(letra);
        }

        for(int i = 0; i < M; i++){
            if(ht[i].chave != 0){
                vet[j] = ht[i];
                j++;
            }
        }

        ordena(vet, 0, j-1);

        for (int i = 0; i < j; i++)
            printf("%d %d\n", vet[i].chave, vet[i].nAparicao);
    }

    return 0;
}

// Funcoes
void htInit(int max)
{
    int i;
    N = 0, M = 2 * max;
    ht = malloc(sizeof(item) * M);
    for (i = 0; i < M; i++)
        ht[i] = NULLitem;
}

void htInsert(item item)
{
    int v = key(item);
    int i = hash(v, M);

    if (ht[i].chave != 0 && ht[i].chave != item.chave)
    {
        while (!null(i))
            i = (i + 1) % M;
    }

    ht[i].chave = item.chave;
    ht[i].nAparicao++;
    N++;
}

item htSearch(int v)
{
    int i = hash(v, M);

    while (!null(i))
    {
        if (eq(v, key(ht[i])))
            return ht[i];
        else
            i = (i + 1) % M;
    }

    return NULLitem;
}

item defineMaior(item maior, item aux)
{
    if (maior.nAparicao < aux.nAparicao)
    {
        return aux;
    }
    else
        return maior;
}

void ordena(item *v, int l, int r)
{
    if (l >= r)
        return;
    int meio = (r + l) / 2;
    ordena(v, l, meio);
    ordena(v, meio + 1, r);
    merge(v, l, meio, r);
}

void merge(item *v, int l, int r1, int r2)
{
    item *v2 = malloc(sizeof(item) * (r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2)
    {
        if (v[i].nAparicao < v[j].nAparicao)
            v2[k++] = v[i++];
        else if (v[i].nAparicao > v[j].nAparicao)
            v2[k++] = v[j++];
        else if (v[i].nAparicao == v[j].nAparicao && v[i].chave < v[j].chave)
            v2[k++] = v[i++];
        else if (v[i].nAparicao == v[j].nAparicao && v[i].chave > v[j].chave)
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