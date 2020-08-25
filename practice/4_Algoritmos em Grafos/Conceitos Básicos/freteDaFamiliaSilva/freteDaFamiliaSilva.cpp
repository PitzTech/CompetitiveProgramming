#include <bits/stdc++.h>

#define MAXN 10005
using namespace std;

struct estrada{
    int a, b, custo;
};

int n, m;
estrada v[MAXN];
int pai[MAXN];

bool ordenar(estrada a, estrada b){
    return a.custo < b.custo;
}

int mst(){
    int ans = 0;
    sort(v, v+m, ordenar);

    for(int i = 0; i < n; i++) pai[i] = i;
    for(int i = 0; i < m; i++){
        int q = v[i].a; 
        int p = v[i].b;
        int u = v[i].custo;

        if(pai[q] == pai[p]) continue;
        int defi = pai[q];
        for(int x = 0; x < n; x++)
            if(defi == pai[x])
                pai[x] = pai[p];
        
        ans += u;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
        cin >> v[i].a >> v[i].b >> v[i].custo;


    cout << mst();

    return 0;
}
