#include <bits/stdc++.h>

#define MAXI 130000
using namespace std;

struct tAresta{
    int dis;
    int x, y;
};

bool comp(tAresta a, tAresta b){ return a.dis < b.dis; }

int n, rodovias;
tAresta aresta[MAXI]; 
int pai[MAXI], peso[MAXI];

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r", stdin);
    freopen("out","w", stdout);

    cin >> n >> rodovias;

    int a,b, peso;
    for(int i = 1; i <= rodovias; i++)
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
    
    for(int i = 1; i <= n; i++) pai[i] = i;

    sort(aresta+1, aresta+rodovias+1, comp);

    int size = 0, soma = 0;
    for(int i = 1; i <= rodovias; i++){
        if(find(aresta[i].x) != find(aresta[i].y)){
            join(aresta[i].x, aresta[i].y);
            soma += aresta[i].dis;
            size++; 
        }
        if(size == n - 1) break;
    }
    cout << soma;
    return 0;
}

