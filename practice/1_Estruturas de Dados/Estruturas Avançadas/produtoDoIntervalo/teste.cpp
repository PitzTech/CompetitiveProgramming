void construirArvore (int arvore[], int arr[], int atual, int comeco, int fim) {
    if (comeco == fim) {
        arvore[atual] = arr[comeco];
    } else {
        int meio = (comeco + fim)/2;
        int esq = atual*2;
        int dir = (atual*2)+1;
        construirArvore(arvore, arr, esq, comeco, meio);
        construirArvore(arvore, arr, dir, meio+1, fim);
        int noEsq = arvore[esq];
        int noDir = arvore[dir];
        if (noDir == 0 || noEsq == 0) {
            arvore[atual] = 0;
        } else if ((noEsq > 0 && noDir < 0) || (noEsq < 0 && noDir > 0)) {
            arvore[atual] = -1;
        } else {
            arvore[atual] = 1;
        }
    }
}