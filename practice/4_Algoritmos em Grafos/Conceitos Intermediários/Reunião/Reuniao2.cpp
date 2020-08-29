#include <bits/stdc++.h>

#define INF 1000000000;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int dist[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dist[i][j] = INF;

    for(int i = 0; i < n; i++)
        dist[i][i] = 0;

    int u, v, w;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = dist[u][v];
    }

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int resp = INF;
    for(int i = 0; i < n; i++) {
        int max_dist = 0;
        for(int j = 0; j < n; j++)
            max_dist = max(max_dist, dist[i][j]);
        resp = min(resp, max_dist);
    }

    cout << resp;
}
