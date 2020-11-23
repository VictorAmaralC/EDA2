#include<stdio.h>
#include<stdlib.h>

// Chamada Funcoes
int hashN(int n);

int main(){
    int n, c;
    int v[262139];
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        v[hashN(t)]= t;
    }

    while(scanf("%d", &c) == 1){
        int t = hashN(c);
        
        if(v[t]==c)
            printf("sim\n");
        else if(v[t]==0)
            printf("nao\n");
        else if(v[t]!= c)
            printf("Putz\n");
    }

    return 0;
}

// Funcoes
int hashN(int n){
    return n%262139;
}
