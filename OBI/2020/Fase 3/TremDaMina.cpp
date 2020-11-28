#include <bits/stdc++.h>
#define ss second
#define ff first
using namespace std;
using pii = pair<int, int>;   

//---------------------
#define MAXN 10100
// como não existe o Infinito no computador, usaremos um número bem grande
#define INFINITO INT_MAX

int n, m, k;                      // número de vértices e arestas
int cidade_noic;               // cidade onde está o Noic
int cidade_succa;              // cidade onde está o Succa
int distancia[MAXN];           // o array de distâncias à fonte
int processado[MAXN];          // o array que guarda se um vértice foi processado
vector<pii> vizinhos[MAXN];    // nossas listas de adjacência. O primeiro elemento do par representa a distância e o segundo representa o vértice
//---------------------

void Dijkstra(int S, int el){
	
	for(int i = 1;i <= n;i++) distancia[i] = INFINITO; // definimos todas as distâncias como infinito, exceto a de S.
	distancia[S] = 0;                                  // Assim, garantimos que o primeiro vértice selecionado será o próprio S.
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(distancia[S], S) );                     // Como se pode ver, colocamos o primeiro elemento como seja a distância do
	// vértice a S e o segundo como sendo o próprio vértice
	
	while(true){ // rodar "infinitamente"
		
		int davez = -1;
		int menor = INFINITO;
		
		// selecionamos o vértice mais próximo
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){ // podemos usar esse vértice porque ele ainda não foi processado
				davez = atual;
				break;
			}
			
			// se não, continuamos procurando
		}
		
		if(davez == -1) break; // se não achou ninguém, é o fim do algoritmo
		
		processado[davez] = true; // marcamos para não voltar para este vértice
		
		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
			
			// A nova possível distância é distancia[davez] + dist.
			// Comparamos isso com distancia[atual]
			
			if( distancia[atual] > distancia[davez] + dist ){  // vemos que vale a pena usar o vértice davez
				distancia[atual] = distancia[davez] + dist;    // atualizamos a distância
				fila.push( pii(distancia[atual], atual) );     // inserimos na fila de prioridade
			}
		}
	}
	
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y, d;
		cin >> x >> y >> d;
		
		vizinhos[x].push_back( pii(d, y) );
		vizinhos[y].push_back( pii(d, x) );
	}
	cin >> k;
    for(int i = 0; i < k; i++){
        int origem, tam;
        cin >> origem >> tam;

        int el = vizinhos[origem].back().ss;

        Dijkstra(origem, el);
        cout << "el: " << el << "\n";
        cout << distancia[el] << "\n";
    }
	
	return 0;
}