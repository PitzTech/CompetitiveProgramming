// OBI-2020, pandemia, O(NM), linear na entrada, Guilherme A. Pinto

#include <iostream>
#include <vector>
using namespace std;

int N, M, I, R;
vector<bool> amigo; // lista de amigos infectados

int main(){

  cin >> N >> M;
  cin >> I >> R;

  amigo = vector<bool>( N+1, false );

  for( int m = 1; m <= M; m++ ){

    // amigo I participou infectado (de fora)
    if ( m == R ) amigo[I] = true;

    // le lista de amigos na reuniao
    vector<int> presentes = vector<int>();

    int A;
    cin >> A;
    bool participanteInfectado = false;
    for( int a = 1; a <= A; a++ ){
      int k;
      cin >> k;
      presentes.push_back( k );
      if ( amigo[k] ) participanteInfectado = true;
    }

    // contaminacao
    if ( participanteInfectado )
      for( int a: presentes )
        amigo[a] = true;
  }

  // conta infectados ao final
  int cnt = 0;
  for ( bool infectado: amigo )
    if ( infectado )
      cnt++;

  cout << cnt << endl;

  return 0;
}
