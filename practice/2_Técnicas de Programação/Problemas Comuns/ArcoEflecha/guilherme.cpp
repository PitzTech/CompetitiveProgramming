// Guilherme A. Pinto, OBI-2016, arco

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXT 131073 // 2^17 > 100000
#define MAXN 100000

struct flecha {
  ll x,y,d;
  int id;
  flecha() {};
  flecha( ll _x, ll _y, int _id ) {
    x = _x; y = _y; id = _id;
    d = x*x + y*y;
  }
  bool operator<(const flecha& o) const {
    return (d < o.d);
  }
};

int N,K;
int v[MAXN];
flecha comp[MAXN];
ll tree[MAXT];

int read( int idx ){
  int sum = 0;
  while (idx > 0){
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update( int idx , int val ){
  while (idx <= K){
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

int main() {
  int i;
  ll res,x,y;

  scanf("%d",&N);
  for ( i = 0; i < N; i++ ){
    scanf("%lld %lld", &x, &y);
    comp[i] = flecha( x, y, i );
  }

  sort( comp, comp + N );

  // substitui o quadrado das distancias por
  // inteiros de 1 a K (o numero de distancias distintas)
  ll d = -1LL;
  for ( K = 0, i = 0; i < N; i++ ) {
    if ( comp[i].d != d ) {
      d = comp[i].d;
      K++;
    }
    v[comp[i].id] = K;
  }

  for ( res = 0LL, i = 0; i < N; i++ ) {
    res += read( v[i] );
    update( v[i], +1 );
  }
  
  printf("%lld\n",res);
  return 0;
}
