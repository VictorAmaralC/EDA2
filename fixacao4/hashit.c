#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 101

char hashtb[size][15];
char NULL_KEY[] = "NULL_KEY";
int N;

int hash(char key[15])
{
    int i = 0, soma = 0;

    while (key[i] != '\0')
    {
        soma += key[i] * (i + 1);
        i++;
    }
    
    soma *= 19;
    soma %= size;

    return soma;
}

int search(char nome[15])
{
    int h = hash(nome), pos = 0, j = 0;

    while (j < 20)
    {
        pos = (h + (j * j) + 23 * j) % size;
        if (!strcmp(hashtb[pos], nome))
            return pos;
        j++;
    }
    
    return -1;
}

void del(char nome[15])
{
    int pos = search(nome);

    if (pos == -1)  return;

    strcpy(hashtb[pos], NULL_KEY);
    N--;
}

void insert(char nome[15])
{
    if (search(nome) != -1) return;

    int h = hash(nome), pos = 0, j = 0;

    while (j < 20)
    {
        pos = (h + (j * j) + 23 * j) % size;
        if (!strcmp(hashtb[pos], NULL_KEY))
        {
            strcpy(hashtb[pos], nome);
            N++;
            return;
        }
        j++;
    }
}

void init()
{
    N = 0;
    for(int i = 0; i < size; i++)
        strcpy(hashtb[i], NULL_KEY);
    
    return;
}

int main()
{
    int aux;
    scanf("%d ", &aux);

    for(aux; aux > 0; aux --){
        init();
        int ops;
        char aux[20], nome[15], comando[3];
        scanf("%d", &ops);

        for(int i = 0; i < ops; i++)
        {
            scanf("%s", aux);
            strncpy(nome, aux + 4, sizeof(char) * 15);
            strncpy(comando, aux, sizeof(char) * 3);

            if (comando[0] == 'A')
                insert(nome);
            else
                del(nome);
        }

        printf("%d\n", N);
        
        for(int i = 0; i < size; i++)
        {
            if (strcmp(hashtb[i], NULL_KEY))
                printf("%d:%s\n", i, hashtb[i]);
        }
    }

    return 0;
}