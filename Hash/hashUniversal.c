#include <stdio.h>
#include <stdlib.h>

// Chamada Funcoes
int hashU(char *v, int m);

int main()
{


    return 0;
}

// Funcoes
int hashU(char *v, int m)
{
    int h, a = 31415, b = 27183;

    for(h = 0; *v != '\0'; v++){
        a = a*b%(m-1);
        h = (a*h+*v)%m;
    }

    return h;
}
