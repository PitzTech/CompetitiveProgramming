// Guilherme A. Pinto, OBI-2017, codigo

#include <iostream>
#include <string>
#include <set>

#define MAX 10

using namespace std;

set<string> prefixo[MAX+1],sufixo[MAX+1];
int N;
string buf;

int main(){

  cin >> N;
  for ( int i = 0; i < N; i++ ){
    cin >> buf;

    // checa validade
    for ( int k = MAX; k > 0; k-- ){
      string pref (buf,0,k);
      if ( sufixo[k].count( pref ) > 0 ){
	if ( k == MAX ){
	  cout << buf << endl;
	  return 0;
	} else {
	  string suf (buf,k,MAX-k);
	  if ( prefixo[MAX-k].count( suf ) > 0 ){
	    cout << buf << endl;
	    return 0;
	  }
	}
      }
    }

    // inclui palavra (prefixos e sufixos)
    for ( int k = MAX; k >= 0; k-- ){
      if ( k < MAX && k > 0 ){
	string pref (buf,0,k);
	prefixo[k].insert(pref);
      }
      if ( k < MAX ){
	string suf (buf,k,MAX-k);
	sufixo[MAX-k].insert(suf);
      }
    }
    
  }

  cout << "ok" << endl;

  return 0;
}
