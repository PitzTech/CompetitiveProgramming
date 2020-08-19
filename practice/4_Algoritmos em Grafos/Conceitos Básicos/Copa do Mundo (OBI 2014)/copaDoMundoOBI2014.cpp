#include <bits/stdc++.h>

#define MAXN 100005
using namespace std;

struct taresta{
    int x,y, dis;
};

bool comp(taresta a, taresta b){
    return a.dis < b.dis;
}

int n, f, r;
taresta aresta[MAXN];
int pai[MAXN], peso[MAXN];

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

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> n >> f >> r;
    for(int i = 0; i < f+r; i++){
        int a,b;
        cin >> a >> b >> aresta[i].dis;
        aresta[i].x = --a;
        aresta[i].y = --b;
    }
    for(int i = 0; i < n; i++) pai[i] = i;

    sort(aresta, aresta+f, comp);
    sort(aresta+f, aresta+r+f, comp);

    int size = 0, soma = 0;
    for(int i = 0; i < f+r; i++){
        if(find(aresta[i].x) != find(aresta[i].y)){
            join(aresta[i].x, aresta[i].y);
            //cout << "aresta: " << aresta[i].x << " para " << aresta[i].y << endl;
            soma += aresta[i].dis;
            //cout << "soma: " << soma << " \n";
            size++;
        }
        if(size == n-1) break;
    }

    cout << soma;

    return 0;
}
