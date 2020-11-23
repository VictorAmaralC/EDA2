#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int chave;
} item;

item NULLitem = {0};

#define hash(v, m) ((618033 * (unsigned)v) % m)
#define key(x) (x.chave)
#define less(a, b) (key(a) < key(b))
#define eq(a, b) (a == b)
#define null(a) (key(ht[a]) == key(NULLitem))

static int N, M;
static item *ht;

// Chamada Funcoes
void htInit(int max);
int htCount();
void htInsert(item item);
item htSearch(int v);


int main()
{
    int n, c;
    htInit(262139);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        item t;
        scanf("%d", &t.chave);
        htInsert(t);
    }

    while (scanf("%d", &c) == 1)
    {
        item t = htSearch(c);

        if (t.chave == c)
            printf("sim\n");
        else if (t.chave == 0)
            printf("nao\n");
        else if (t.chave != c)
            printf("Putz\n");
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

    while (!null(i))
    {
        if (eq(v, key(ht[i])))
            return ht[i];
        else
            i = (i + 1) % M;
    }

    return NULLitem;
}