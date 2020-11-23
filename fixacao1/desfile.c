#include <stdio.h>
#include <stdlib.h>

int min(int *vet, int min, int posicao, int tamanhoVet);
int ordena(int *vet1, int *vet2, int menor, int vet2max, int posicao, int possivel, int tamanhoVet);

int main(){
    int carros;
    scanf("%d", &carros);
    
    while(carros != 0){
        int possivel = 0, menor;

        int *ordem = malloc (carros*sizeof(int));
        int *rua = malloc (carros*sizeof(int));   

        scanf("%d", &menor);
        ordem[0] = menor;

        for(int i = 1; i < carros; i++){
            int carro;
            scanf("%d", &carro);
            if(carro < menor) menor = carro;
            ordem[i] = carro;
        }

        possivel = ordena(ordem, rua, menor, 0, 0, 0, carros);

        if (possivel == 0) printf("yes\n");
        else printf("no\n");

        scanf("%d", &carros);
    }
    
    return 0;
}

int min(int *vet, int min, int posicao, int tamanhoVet){
    for(int i = posicao+1; i < tamanhoVet-1; i++){
        if(min > vet[i])
            min = vet[i];
    }
    return min;
}

int ordena(int *vet1, int *vet2, int menor, int vet2max, int posicao, int possivel, int tamanhoVet){
    if(posicao == tamanhoVet-1) return possivel;

    for(posicao; vet1[posicao] != menor; posicao++){
        vet2[vet2max] = vet1[posicao];
        if( vet2max > 0 && vet2[vet2max] > vet2[vet2max-1] ){
            possivel = 1;
            return possivel;
        }
        vet2max++;
    }

    if(posicao == tamanhoVet-1) return possivel;

    menor = min(vet1, vet1[posicao+1], posicao+1, tamanhoVet);

    while(menor > vet2[vet2max-1] && vet2max >= 0){
        vet2[vet2max-1] = 0;
        vet2max--;
    }
    
    possivel = ordena(vet1, vet2, menor, vet2max, posicao, possivel, tamanhoVet);
}