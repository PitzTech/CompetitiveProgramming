// OBI-2020, fissura, O(N^2), linear na entrada, Guilherme A. Pinto

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int di[4] {1,0,-1,0};
int dj[4] {0,1,0,-1};

queue<pair<int,int>> q;

int N, F;

vector<string> m;

int main(){
  ios::sync_with_stdio( false ); cin.tie( 0 );

  cin >> N >> F;

  m = vector<string>( N );

  for( int i = 0; i < N; i++ )
    cin >> m[i];

  if ( m[0][0]-'0' <= F ){
    m[0][0] = '*';
    q.push( {0,0} );

    // BFS
    while( not q.empty() ){
      auto e = q.front();
      q.pop();

      int i = e.first;
      int j = e.second;

      for( int k = 0; k < 4; k++ ){
        int a = i+di[k];
        int b = j+dj[k];
        if ( a >= 0 and a < N and b >= 0 and b < N )
          if ( m[a][b] != '*' and m[a][b]-'0' <= F ){
            m[a][b] = '*';
            q.push( {a,b} );
          }
      }
    }
  }

  for( int i = 0; i < N; i++ )
    cout << m[i] << endl;

  return 0;
}
