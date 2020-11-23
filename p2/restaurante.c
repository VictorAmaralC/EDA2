#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, dia = 1;

    while(scanf("%d", &n) != EOF){
        int restaurante, nota, mRestaurante, mNota = -1;
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &restaurante, &nota);
            if(nota > mNota)
            {
                mRestaurante = restaurante;
                mNota = nota;
            }
            else if (nota == mNota && restaurante < mRestaurante){
                mRestaurante = restaurante;
            }
        }
        
        printf("Dia %d\n%d\n\n", dia, mRestaurante);
        dia++;
    }

    return 0;
}