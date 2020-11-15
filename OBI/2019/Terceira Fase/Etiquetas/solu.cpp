// OBI-2019, etiquetas, Guilherme A. Pinto

#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000 // 10^9 >> 10000^2

vector<vector<int>> m; // m[k][i] = melhor solucao para k etiquetas no prefixo de 1 a i
vector<int> f;         // vetor de entrada

int N,K,C;

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> K >> C;

  f = vector<int>(N+1);
  m = vector<vector<int>>(K+1,vector<int>(N+1,-INF));

  m[0][0] = 0;
  for( int i = 1; i <= N; i++ ){
    cin >> f[i];
    m[0][i] = m[0][i-1]+f[i];
  }

  // DP
  for( int k = 1; k <= K; k++ )
    for( int i = k*C; i <= N; i++ )
      m[k][i] = max( m[k-1][i-C], m[k][i-1]+f[i] );

  cout << m[K][N] << endl;

  return 0;
}