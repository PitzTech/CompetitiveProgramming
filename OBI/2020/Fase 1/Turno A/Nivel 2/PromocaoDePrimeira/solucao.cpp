// OBI-2020, promocao, O(N), Guilherme A. Pinto

#include <iostream>
#include <vector>
using namespace std;

struct ReturnPair { int max0, max1; };

vector<vector<pair<int,int>>> g;
int opt;

ReturnPair dfs( int v, int parent ){
  ReturnPair r {0,0};

  for ( auto u: g[v] )
    if ( u.first != parent ){
      auto ret = dfs( u.first, v );
      if ( u.second == 0 ) r.max0 = max( r.max0, ret.max1 + 1 );
      else r.max1 = max( r.max1, ret.max0 + 1 );
    }

  opt = max( opt, r.max0 + r.max1 + 1 );
  return r;
}

int main(){
  ios::sync_with_stdio( false ); cin.tie( 0 );

  int N;
  cin >> N;

  g = vector<vector<pair<int,int>>>( N+1 );

  for( int i = 1; i <= N-1; i++ ){
    int A,B,E;
    cin >> A >> B >> E;
    
    g[A].push_back( {B,E} );
    g[B].push_back( {A,E} );
  }

  opt = 0;
  dfs( 1 , -1 );
  cout << opt << endl;

  return 0;
}
