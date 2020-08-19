// Dislodging Logs
// Solution by Jacob Plachta

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x * x); }
string plural(string s) { return(Sz(s) && s[Sz(s) - 1] == 'x' ? s + "en" : s + "s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

#define GETCHAR getchar_unlocked

bool Read(int& x)
{
  char c, r = 0, n = 0;
  x = 0;
  for (;;)
  {
    c = GETCHAR();
    if ((c < 0) && (!r))
      return(0);
    if ((c == '-') && (!r))
      n = 1;
    else
      if ((c >= '0') && (c <= '9'))
        x = x * 10 + c - '0', r = 1;
      else
        if (r)
          break;
  }
  if (n)
    x = -x;
  return(1);
}

#define LIM 1000001

int N[2], K, S;
int P[2][LIM];

void ReadSeq(int* V, int N, int K)
{
  int i, A, B, C, D;
  Fox(i, K)
    Read(V[i]);
  Read(A), Read(B), Read(C), Read(D);
  FoxI(i, K, N - 1)
    V[i] = ((LL)A * V[i - 2] + (LL)B * V[i - 1] + C) % D + 1;
}

bool IsValid(LL m)
{
  int i, j = 0;
  // iterate over log drivers from left to right
  Fox(i, N[0])
  {
    // greedily allocate as many clusters as possible to this log driver
    int k = j;
    while (k < N[1])
    {
      LL d = min(Abs(P[0][i] - P[1][j]), Abs(P[0][i] - P[1][k])) + (P[1][k] - P[1][j]);
      if (d > m)
        break;
      k++;
    }
    // all clusters covered?
    if (k == N[1])
      return(1);
    j = k;
  }
  return(0);
}

LL ProcessCase()
{
  int i;
  // input, and sort by position
  Fox(i, 2)
    Read(N[i]);
  Read(K), Read(S);
  Fox(i, 2)
  {
    ReadSeq(P[i], N[i], K);
    sort(P[i], P[i] + N[i]);
  }
  // binary search for min. valid # of seconds
  LL r1 = 1, r2 = INF;
  while (r2 > r1)
  {
    LL m = (r1 + r2) >> 1;
    if (IsValid(m))
      r2 = m;
    else
      r1 = m + 1;
  }
  return(r1);
}

int main()
{
  int T, t;
  Read(T);
  Fox1(t, T)
    printf("Case #%d: %lld\n", t, ProcessCase());
  return(0);
}