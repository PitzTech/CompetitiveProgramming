#include <bits/stdc++.h>

#define oo 1e18
#define MAXN 10005
#define ll long long

using namespace std;
using lli = pair<ll,int>;

int n;
ll peso[MAXN];
vector<lli> node[MAXN]; // peso / dir

void dijkstra(int start){
    for(int x = 0; x <= n; x++)
        peso[x] = oo;
    peso[start] = 0;
    
    priority_queue<lli, vector<lli>, greater<lli>> fila;

    fila.emplace(peso[start], start);

    int actual, dactual;
    ll holes, dholes;
    while(!fila.empty()){
        tie(dholes, dactual) = fila.top();
        fila.pop();
        
        if(dholes > peso[dactual]) continue;
        for(auto anode : node[dactual]){
            tie(holes, actual) = anode;
            if(peso[actual] > peso[dactual] + holes){
                peso[actual] = peso[dactual] + holes;
                fila.emplace(peso[actual], actual);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int pontes, n1, n2, b;

    cin >> n >> pontes;
    n++;

    for(int x = 0; x < pontes; x++){
        cin >> n1 >> n2 >> b;
        node[n1].emplace_back(b,n2);
        node[n2].emplace_back(b,n1);
    }

    dijkstra(0);

    cout << peso[n];

    return 0;
}