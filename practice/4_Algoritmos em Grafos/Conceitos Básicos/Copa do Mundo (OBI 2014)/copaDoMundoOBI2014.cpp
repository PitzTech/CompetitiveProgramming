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
taresta arestar[MAXN];
taresta arestaf[MAXN];
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
        peso[a] = b;
        peso[b]++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> n >> f >> r;
    for(int i = 1; i <= f; i++)
        cin >> arestaf[i].x >> arestaf[i].y >> arestaf[i].dis;
    for(int i = 1; i <= r; i++)
        cin >> arestar[i].x >> arestar[i].y >> arestar[i].dis;

    for(int i = 1; i <= n; i++) pai[i] = i;

    sort(arestaf+1, arestaf+f+1, comp);
    sort(arestar+1, arestar+r+1, comp);

    int size = 0, soma = 0;
    for(int i = 1; i <= f+r; i++){
        if(i <= f && find(arestaf[i].x) != find(arestaf[i].y)){
            join(arestaf[i].x, arestaf[i].y);
            soma += arestaf[i].dis;
            size++;
        }else if(i >= r && find(arestar[i].x) != find(arestar[i].y)){
            join(arestar[i].x, arestar[i].y);
            soma += arestar[i].dis;
            size++;
        }
        if(size == n-1) break;
    }

    cout << soma;

    return 0;
}
