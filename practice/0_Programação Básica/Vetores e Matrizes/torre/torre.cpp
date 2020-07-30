#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    
    int n, pmaior = 0, patual;
    cin >> n;
    int coluna[n], linha[n], quadro[n][n];

    for(int x = 0; x < n; x++){
        coluna[x] = 0;
        linha[x] = 0;
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cin >> quadro[x][y];
            coluna[x] += quadro[x][y];
            linha[y] += quadro[x][y];
        }
    }
    //int linhap = -1, colunap = -1;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            patual = coluna[x] + linha[y] - 2*quadro[x][y];
            if(patual > pmaior){
                // printf("(%d) > (%d) \n", patual, pmaior);
                //linhap = y, colunap = x;
                pmaior = patual;
            }// else printf("(%d) < (%d) \n", patual, pmaior);
        }
    }
    printf("%d", pmaior);
}
