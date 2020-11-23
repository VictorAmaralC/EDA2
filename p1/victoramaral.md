Victor Amaral - 17/0164411
Teclado americano (ignorar possiveis erros de gramatica/acentuacao)

T1 - ESTABILIDADE

A estabilidade de um algoritmo se refere a manutencao da posicao inicial dos valores dentro de um vetor em caso de valores semelhantes, ou seja, um algoritmo estavel mantem no pos-operacao as posicoes iniciais em caso de valores equivalentes. Sabendo que a funcao cmpexch compara 2 valores e verifica se o primeiro valor eh menor que o segundo, apos a operacao em caso de valores semelhantes a funcao mantem a posicao inicial do vetor, tornando-a estavel.


int insertionSort(int *v, int l, int r){
    for(int i=r; i >l; i--){
        cmpexch(v[i-1], v[i]);
    }
    for(int i = l+2; i<=r; i++){
        int j= i; 
        item tmp = v[j];
        while(less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

T2 - SEPARA

No caso do vetor v[6] = {4, 3, 5, 2, 1, 4}, o indice retornado = 5, que faz com que o intervalo retornado v[p..i] seja maior que o intervalo v[i+1..r].
Ainda estaria fora do intervalo previsto do vetor citado, sim

int sep( int v[], int p, int r) {
    int q, i, j, t;
    i = p; q = (p + r) / 2; j = r;
    do {
    while (v[i] < v[q]) ++i;
    while (v[j] > v[q]) --j;
    if (i <= j) {
    t = v[i], v[i] = v[j], v[j] = t;
    ++i, --j;
    }
    } while (i <= j);
    return i;
}