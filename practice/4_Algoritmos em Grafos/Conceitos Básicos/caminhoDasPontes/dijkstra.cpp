#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 100005;
const ll oo = 1e18;

ll d[N]; // vetor onde guardamos as distancias

int n; // numeros de vertices

// lista de adjacencias guarda
// pair <vertice para onde a aresta vai, peso da aresta>
vector<pair<int, ll>> g[N];

void dijkstra(int start){
    n++;

	// inicialmente a distancia do vertice
	// start para todo os outros é infinita
	for(int u = 0; u <= n; u++)
		d[u] = oo;

	// fila de prioridade de pair<ll, int>, mas que o
	// menor pair fica no topo da fila
	// guardamos um pair <distancia ate o vertice, vertice>
	// assim o topo da fila sempre é o vertice com menor distancia
	priority_queue<pair<ll, int>, vector<pair<ll, int>>,
		greater<pair<ll, int>> > pq;

	d[start] = 0;
	pq.emplace(d[start], start);

	ll dt, w;
	int u, v;
	while(!pq.empty()){
		tie(dt, u) = pq.top(); pq.pop();
		if(dt > d[u]) continue;
		for(auto edge : g[u]){
			tie(v, w) = edge;

			// se a distancia ate o u somado com o peso
			// da aresta é menor do que a distancia ate o v que
			// tinhamos antes, melhoramos a distancia ate o v
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.emplace(d[v], v);
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int pontes,n1,n2,peso;
    cin >> n >> pontes;

    for(int x = 1; x <= pontes; x++){
        cin >> n1 >> n2 >> peso;
        g[n1].emplace_back(n2, peso);
        g[n2].emplace_back(n1, peso);
    } 

    dijkstra(0);
    
    for(int x = 0; x <= n; x++){
         printf("d[%d] = %lld \n", x, d[x]);
    }
    return 0;
}
