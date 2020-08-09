#include <bits/stdc++.h>

#define oo 1e18
#define MAXN 1005
#define ll long long

using namespace std;
using lli = pair<ll, int>;


int n, npath, start; 


int dijkstra(int start, vector<lli> node[]){
    ll c[MAXN];

    for(int x = 0; x < n; x++)
        c[x] = oo;
    c[start] = 0;

    priority_queue<lli, vector<lli>, greater<lli>> fila;
    
    fila.emplace(c[start], start);

    ll custo, dcusto;
    int atual, datual;
    while(!fila.empty()){
        tie(dcusto, datual) = fila.top();fila.pop();
        
        if(datual < npath - 1){
            //cout << "\nentrou " << datual << endl;
            //cout << "custo antes: " << dcusto << "\n";
            
            while(datual < npath - 1){
                for(auto el : node[datual]){
                    if(el.second == datual + 1){
                        dcusto += el.first;
                        break;    
                    }
                }
                //cout << "node " << datual << endl;
                //cout << "custo dps: " << dcusto << "\n";
                datual++;
            }
            c[npath - 1] = min(dcusto, c[npath - 1]);
        }else{
            //cout << endl << datual << " ";
            if(dcusto > c[datual]) continue;
            for(auto nod : node[datual]){
                tie(custo, atual) = nod;
                //cout << " \nsub " << atual << " ";
                if(c[atual] > c[datual] + custo){
                    //cout << endl << c[atual] << endl;
                    c[atual] = c[datual] + custo;
                    //cout << "c[datual] = " <<  c[datual] << endl;
                    //cout << "custo = " << custo << endl;
                    //cout << "c[atual] = " << c[atual] << endl;
                    fila.emplace(c[atual], atual);
                }
            }
        }
    }
    return c[npath - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
    int roads, n1, n2, custo;
    while(cin >> n >> roads >> npath >> start && n != 0 & roads != 0 & npath != 0 & start != 0){ 
        vector<lli> node[MAXN];

        for(int x = 0; x < roads; x++){
            cin >> n1 >> n2 >> custo;
            node[n1].emplace_back(custo, n2);
            node[n2].emplace_back(custo, n1);
        }

        cout << dijkstra(start, node) << "\n";

    }
    return 0;
}