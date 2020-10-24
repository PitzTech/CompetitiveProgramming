#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, valores[100005];
    cin >> n;

    int valor = 0;
    for(int i = 0; i < n; i++)
        cin >> valores[i];
        
    sort(valores, valores+n, greater<int>());
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0 && i >= 3) continue;
            valor += valores[i-1];
    }

    cout << valor;
    return 0;
}