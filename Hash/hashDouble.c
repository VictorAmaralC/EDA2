#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int chave;
    long e1, e2;
    long elemento;
} item;

item NULLitem = {0, 0, 0, 0};

#define hash(v, m) (v % m)
#define hashtwo(v, m) (v % 97 + 1)
#define key(x) (x.chave)
#define less(a, b) (key(a) < key(b))
#define null(a) (key(ht[a]) == key(NULLitem))

static int N, M;
static item *ht;

// Chamada Funcoes
void htInit(int max);
void htInsert(item item);
int htCount();
item htSearch(int v);

int main()
{

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

void htInsert(item item){
    int v = key (item);
    int i = hash(v,M);
    int k = hashtwo(v,M);

    while(!null(i))
        i = (i+k) % M;
    
    ht[i] = item;
    N++;
}

int htCount()
{
    return N;
}

void htInsert(item item)
{
    int v = key(item);
    int i = hash(v, M);

    while (!null(i))
        i = (i + 1) % M;

    ht[i] = item;
    N++;
}

item htSearch(int v)
{
    int i = hash(v, M);
    int k = hashtwo (v, M);

    while (!null(i))
    {
        if (eq(v, key(ht[i])))
            return ht[i];
        else
            i = (i + k) % M;
    }

    return NULLitem;
}