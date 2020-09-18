//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definicoes Gerais
typedef int item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {item t=A; A=B, B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

//Funcoes
void ordena(int *v, int l, int r);
int separa(item *v, int l, int r);

//Main
int main(){
    int n;
    scanf("%d", &n);

    int *valores = malloc (n*sizeof(int));

    for(int i=0, j = n; i<n; i++, j--){
        int v;
        scanf("%d", &v);
        valores[i] = v;
    }

    ordena(valores, 0, n-1);

    for(int i=0; i < n-1; i++)
        printf("%d ", valores[i]);

    printf("%d\n", valores[n-1]);
    
    return 0;
}

//Desenvolvimento funcoes
void ordena(int *v, int l, int r){
    int j;
    if(r <= l) return;
    j = separa(v, l, r);
    
    ordena(v, l, j-1);
    ordena(v, j+1, r);
}

int separa(item *v, int l, int r){
    item c = v[r];
    int j = l;
    for(int k = l; k<r; k++)
        if(less(v[k], c)){
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

// separa basico (Muito gasto de memoria/ineficiente)
// int separa(item *v, int l, int r){
//     int tam = r-l+1;
//     item c = v[r];
//     item *menores = malloc (sizeof(item)*tam);
//     item *maiores = malloc (sizeof(item)*tam);
//     int imenor = 0;
//     int imaior = 0;

//     for(int i = l; i < r; i++){
//         if(less(v[i], c))
//             menores[imenor++] = v[i];
//         else maiores[imaior++] = v[i];
//     }
    
//     int i = l;
//     for(int j= 0; j < imenor; j++)
//         v[i++] = menores[j];
//     v[i] = c;
//     int Cpos = i;
//     i++;
//     for(int j = 0; j < imaior; j++)
//         v[i++] = maiores[j];
    
//     free(maiores);
//     free(menores);
//     return Cpos;
// }

//Separa Sedwick version
// int separa(item *v, int l, int r){
//     int i = l-1;
//     int j = r;
//     item c = v[r];
//     for(;;){
//         while(less(v[++i], c));
//         while(less(c,v[--j]))
//             if(j==l) break;
//         if(i>=j) break;
//         exch(v[i], v[j])
//     }
//     exch(v[i], v[r]);
// }