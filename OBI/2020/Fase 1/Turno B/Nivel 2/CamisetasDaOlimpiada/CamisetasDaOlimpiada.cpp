#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;//premiados
    int nm = 0, np = 0;//tamanhos solicitados 1 peq 2 medio 
    int p; // tamanho pequeno produzida
    int m; // tamanho medio produzida

    cin >> n;
    for(int i = 0; i < n; i++){
        int pedido;
        cin >> pedido;
        if(pedido == 1)
            np++;
        else
            nm++;
    }
    cin >> p >> m;

    if(p <= np && m <= nm)
        cout << 'S';
    else 
        cout << 'N';

    return 0;
}