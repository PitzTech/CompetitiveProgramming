#include <bits/stdc++.h>

#define MAX 200
using namespace std;

int linhas,colunas, mapa[MAX][MAX], menor = MAX;
bool dfs[MAX][MAX];

int busca(int l, int c){
    //cout << l << " " << c << endl;
    dfs[l][c] = true;
    int atual = 1;
    if(!dfs[l+1][c] && mapa[l+1][c] == mapa[l][c] && l != linhas){
        atual += busca(l+1, c);
    }
    if(!dfs[l][c+1] && mapa[l][c+1] == mapa[l][c] && c != colunas){
        atual += busca(l, c+1);
    }
    if(!dfs[l-1][c] && mapa[l-1][c] == mapa[l][c] && l != 0){
        atual += busca(l-1, c);
    }
    if(!dfs[l][c-1] && mapa[l][c-1] == mapa[l][c] && c != 0){
        atual += busca(l, c-1);
    }
    return atual;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> linhas >> colunas;

    for(int x = 0; x < linhas;x++)
        for(int y = 0; y < colunas;y++)
            cin >> mapa[x][y];

    int atual;
    for(int x = 0; x < linhas;x++){
        for(int y = 0; y < colunas;y++){
            if(!dfs[x][y]){
                atual = busca(x,y);
                //cout << atual << endl;
                if(atual < menor)
                     menor = atual;
            }  
        }
    }
    cout << menor;
    return 0;
}