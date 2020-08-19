// Perimetric - Chapter 2
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
#define MOD 1000000007

LL cur, ans;
int L[LIM], W[LIM], H[LIM];
set<PR> S;

void ReadSeq(int* V, int N, int K)
{
  int i, A, B, C, D;
  Fox(i, K)
    Read(V[i]);
  Read(A), Read(B), Read(C), Read(D);
  FoxI(i, K, N - 1)
    V[i] = ((LL)A * V[i - 2] + (LL)B * V[i - 1] + C) % D + 1;
}

void ProcessRect(int L, int R, int H)
{
  // find first x interval overlapping with this rectangle
  auto I = prev(S.lower_bound(mp(L, -1)));
  if (I->y < L)
    I++;
  Min(L, I->x);
  // erase all x intervals overlapping with this rectangle
  while (I->x <= R)
  {
    Max(R, I->y);
    cur -= I->y - I->x + H;
    I = S.erase(I);
  }
  // add x interval for this rectangle (and any intervals it overlapped)
  cur += R - L + H;
  S.insert(mp(L, R));
}

int ProcessCase()
{
  int N, K, i;
  // input
  Read(N), Read(K);
  ReadSeq(L, N, K);
  ReadSeq(W, N, K);
  ReadSeq(H, N, K);
  // process rectangles, while maintaining set of covered x intervals
  cur = 0, ans = 1;
  S.clear();
  S.insert(mp(-1, -1));
  S.insert(mp(INF + 1, INF + 1));
  Fox(i, N)
  {
    ProcessRect(L[i], L[i] + W[i], H[i]);
    ans = (LL)ans * (cur % MOD) * 2 % MOD;
  }
  return(ans);
}

int main()
{
  int T, t;
  Read(T);
  Fox1(t, T)
    printf("Case #%d: %d\n", t, ProcessCase());
  return(0);
}