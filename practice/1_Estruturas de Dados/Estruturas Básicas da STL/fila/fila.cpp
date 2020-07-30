#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n, s;
vector<int> fila;
set<int> saida;

int main(){
    freopen("in", "r",stdin);
    freopen("out", "w", stdout);

    scanf("%d", &n);
    for(int x = 0; x < n; x++){
        int entrada;
        scanf("%d", &entrada);
        fila.pb(entrada);
    }
    scanf("%d", &s);
    for(int x = 0; x < s; x++){
        int sair;
        scanf("%d", &sair);
        saida.insert(sair);     
    }

    for(int x = 0; x < (int)fila.size(); x++){
        if(saida.find(fila[x]) == saida.end())
            printf("%d ", fila[x]);
    }
    return 0;
}