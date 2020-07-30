#include <bits/stdc++.h>
using namespace std;

#define MAXN 501
#define INF 101 // maior que idade maxima

vector<int> g[MAXN]; // grafo de cargos
int mark[MAXN],idade[MAXN];
int cargoParaEmpregado[MAXN];
int empregadoParaCargo[MAXN];
int N,M,I,cnt;

int dfs( int cargo, bool flag ){
  int minIdade = INF;
  if ( flag ) minIdade = idade[cargoParaEmpregado[cargo]];
  mark[cargo] = cnt;
  for ( auto ch : g[cargo] )
    if ( mark[ch] < cnt ){
      int m = dfs( ch, true );
      if ( m < minIdade ) minIdade = m;
    }
  return minIdade;
}

int main(){
  int a,b;
  
  cin >> N >> M >> I;
  
  for( int i = 1; i <= N; i++ ){
    cin >> idade[i];
    cargoParaEmpregado[i] = i; // empregado igual a cargo
    empregadoParaCargo[i] = i; // cargo igual a empregado
    mark[i] = 0;
  }

  // monta grafo de cargos
  for( int i = 1; i <= M; i++ ){
    int chefe, subordinado;
    cin >> chefe >> subordinado;
    g[subordinado].push_back(chefe); 
  }
  
  cnt = 0;
  for( int i = 1; i <= I; i++ ){
    char op;
    cin >> op;
    if ( op == 'T' ) {
      cin >> a >> b;
      // troca empregados nos cargos
      swap( cargoParaEmpregado[empregadoParaCargo[a]],
	    cargoParaEmpregado[empregadoParaCargo[b]]);
      // troca cargos nos empregados
      swap( empregadoParaCargo[a],
	    empregadoParaCargo[b] );
    } else {
      cin >> a;
      cnt++;
      int minIdade = dfs( empregadoParaCargo[a], false );
      if ( minIdade < INF ) cout << minIdade << endl;
      else cout << "*" << endl;
    }
  }
  
  return 0;
}
