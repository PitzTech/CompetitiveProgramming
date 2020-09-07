#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, p;
ll peso[2001], valor[2001], tab[2001][2001];

ll knapstack(int el, ll aguenta){
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
    
    cin >> p >> n;
    for(int i = 0; i < n; i++)
        cin >> peso[i] >> valor[i];

    memset(tab, -1, sizeof(tab));

    cout << knapstack(0, p) << "\n";

    return 0;
}