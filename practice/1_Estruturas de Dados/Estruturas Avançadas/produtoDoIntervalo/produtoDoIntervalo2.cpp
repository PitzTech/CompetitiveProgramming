#include <bits/stdc++.h>

using namespace std;

void startTree(int arvore[], int arr[], int atual, int comeco, int fim) {
    if (comeco == fim) {
        arvore[atual] = arr[comeco];
    } else {
        int meio = (comeco + fim)/2;
        int esq = atual*2;
        int dir = (atual*2)+1;
        startTree(arvore, arr, esq, comeco, meio);
        startTree(arvore, arr, dir, meio+1, fim);
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
void updateTree(int arvore[], int atual, int comeco, int fim, int pos, int novo_valor) {
    if (comeco == fim) {
        arvore[atual] = novo_valor;
    } else {
        int meio = (comeco + fim)/2;
        int esq = atual*2;
        int dir = (atual*2)+1;
        if (pos <= meio) {
            updateTree(arvore, esq, comeco, meio, pos, novo_valor);
        } else {
            updateTree(arvore, dir, meio+1, fim, pos, novo_valor);
        }
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
int checkNode(int arvore[], int atual, int comeco, int fim, int A, int B) {
    if (A <= comeco && fim <= B) {
        return arvore[atual];
    }
    if (comeco > B || fim < A) {
        return INT_MIN;
    }
    int esq = atual*2;
    int dir = (atual*2) + 1;
    int meio = (comeco + fim)/2;

    int resposta_esquerda = checkNode(arvore, esq, comeco, meio, A, B);
    int resposta_direita = checkNode(arvore, dir, meio+1, fim, A, B);

    if (resposta_direita == INT_MIN) return resposta_esquerda;
    if (resposta_esquerda == INT_MIN) return resposta_direita;

    if (resposta_direita == 0 || resposta_esquerda == 0) {
        return 0;
    } else if ((resposta_esquerda > 0 && resposta_direita < 0) || (resposta_esquerda < 0 && resposta_direita > 0)) {
        return -1;
    } else {
        return 1;
    }
}
int main(){
    
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int n, nCmd;
    
    while(scanf("%d %d",&n,&nCmd) == 2){
        int nums[n];
        int arvore[n*4];
        for(int x = 0; x < n; x++) scanf("%d",&nums[x]);

        //arvore(nó, i, j, posição, novoValor);
        //startTree(arvore[], arr[], atual, comeco, fim)
        startTree(arvore, nums, 1, 0, n-1);
        
        string ans;
        char cmd;
        int n1, n2;
        for(int x = 0; x < nCmd; x++){   
            scanf(" %c %d %d",&cmd, &n1, &n2);
            if(cmd == 'C')
            //updateTree(arvore[], atual, comeco, fim, posi, novoValor)
                updateTree(arvore, 1, 0, n-1, n1-1, n2);
            else{
                //checkNode(arvore[], atual, comeco, fim, a, b)
                int answer = checkNode(arvore, 1, 0, n-1, n1-1, n2-1);
                if(answer > 0) ans += "+";
                else if(answer < 0) ans += "-";
                else ans += "0";
            }
        }
        
        printf("%s\n", ans.c_str());
    }
    return 0;
}