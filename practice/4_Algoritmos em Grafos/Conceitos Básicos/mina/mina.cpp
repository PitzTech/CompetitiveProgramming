#include <bits/stdc++.h>

#define ff first
#define ss second
using namespace std;
using ii = pair<int,int>;

int n, mapa[100][100], d[100][100];
vector<ii> mv {{1,0},{-1,0},{0,1},{0,-1}};

bool can(int x, int y){
    return x >= 0 && x < n 
        && y >= 0 && y < n; 
}

void djikstra(int x, int y){
    memset(d, -1, sizeof(d));
    
    set<vector<int>> q;    
    q.insert({0,x,y});

    vector<int> aux;
    while(!q.empty()){
        aux = *q.begin();
        q.erase(q.begin());
        x = aux[1];
        y = aux[2];

        int dist = aux[0];
        if(d[x][y] != -1) continue;
        d[x][y] = dist;
        for(auto u:mv){
            int i = x+u.ff;
            int j = y+u.ss;
            if(!can(i,j)) continue;
            if(d[i][j] != -1) continue;
            q.insert({dist+mapa[i][j], i, j});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int x = 0; x < n;x++)
        for(int y= 0; y < n; y++)
            cin >> mapa[x][y];
    
    djikstra(0,0);
    cout << d[n-1][n-1];

    return 0;
}