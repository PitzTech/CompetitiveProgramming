#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;

int n, c;
int peso[MAXN], valor[MAXN], tab[MAXN][MAXN];

int knapstack(int el, int aguenta){
    if(tab[el][aguenta] >= 0) return tab[el][aguenta];
    if(el == n || !aguenta) return tab[el][aguenta] = 0;

    int ncoloca = knapstack(el+1, aguenta);

    if(peso[el] <= aguenta){
        int coloca = valor[el] + knapstack(el+1, aguenta-peso[el]);
        return tab[el][aguenta] = max(coloca, ncoloca);
    }
    return tab[el][aguenta] = ncoloca;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int caso = 1;
    while(cin >> c >> n && c && n){
        
        memset(tab, -1, sizeof(tab));

        for(int i = 0; i < n; i++)
            cin >> peso[i] >> valor[i];
        
        cout << "Teste " << caso++ << "\n";
        cout << knapstack(0, c) << "\n\n";
    }   
    return 0;
}