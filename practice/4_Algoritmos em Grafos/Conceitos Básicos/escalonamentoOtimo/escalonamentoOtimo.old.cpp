#include <bits/stdc++.h>

#define MAXN 200005
using namespace std;

int n, m;
vector<int> grafo[MAXN];
int grau[MAXN];
vector<int> lista; // grau 0

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        grau[b]++;
        grafo[a].push_back(b);
    }
    for(int i = 0; i < n; i++)
        if(grau[i] == 0) 
            lista.push_back(i);

    int ini = 0;
    while(ini < (int)lista.size()){
        int atual = lista[ini];
        ini++;
        
        for(int el : grafo[atual]){
            grau[el]--;
            if(grau[el] == 0)
                lista.push_back(el);
        }
    }

    if((int)lista.size() < n) cout << "*";
    else{
        for(int el : lista)
            cout << el << "\n";
    }
    return 0;
}