#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int way[n][n];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            way[i][j] = INF;
    
    for(int i = 1; i <= n; i++)
        way[i][i] = 0;

    int u,v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;

        way[u][v] = min(way[u][v], w);
        way[v][u] = way[u][v];
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                way[i][j] = min(way[i][j],
                            way[i][k] + way[k][j]);
    int res = INF;
    for(int i = 0; i < n; i++){
        int maxi = 0;
        for(int j = 0; j < n; j++)
            maxi = max(maxi, way[i][j]);
        res = min(res, maxi); 
    }

    cout << res;

    return 0;
}