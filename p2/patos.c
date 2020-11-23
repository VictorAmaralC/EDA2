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
#define less(a, b) (key(a) < key(b))
#define eq(a, b) (a == b)
#define null(a) (key(ht[a]) == key(NULLitem))

static int N, M;
static item *ht;

// Chamada Funcoes
void htInit(int max);
void htInsert(item item);
item htSearch(int v);
item defineMaior (item maior, item aux);

int main()
{
    int n;
    scanf("%d", &n);

    while(n != 0)
    {
        htInit(5003);

        item maior = {0, 0};

        for(int i = 0; i < n; i++){
            item patos;
            scanf("%d", &patos.chave);

            htInsert(patos);
            if(maior.chave != patos.chave)
                maior = defineMaior(maior, htSearch(patos.chave));
        }

        printf("%d\n", maior.chave);

        scanf("%d", &n);
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

    if(ht[i].chave != 0 && ht[i].chave != item.chave){
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

item defineMaior(item maior, item aux){
    if(maior.nAparicao < aux.nAparicao){
        return aux;
    }
    else return maior;
}
