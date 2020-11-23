#include<stdio.h>
#include<stdlib.h>

void compara(int *v, int limite, int posicao, int vmax);

int main (){
    int numero, v[1000], i=0, limite;
    
    scanf("%d", &numero);
    while(numero != 0){
        v[i] = numero;
        i++;
        scanf("%d", &numero);
    }
    scanf("%d", &limite);

    compara(v, limite, 0, i-1);
    
    return 0;
}

void compara(int *v, int limite, int posicao, int vmax){
    if(posicao >= vmax) return;

    int soma = 0, posUltrapassa;
    
    for(posicao; posicao < vmax; posicao++)
        if(soma < limite){
            soma += v[posicao];
        } else break;


    posUltrapassa = posicao;
    compara(v, limite, posicao, vmax);
    if(soma > limite)
    printf("%d\n", v[posUltrapassa-1]);
    return;
}