// Running on Fumes - Chapter 2
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

#define LIM 1000008
#define LIM2 2100000

int N, M, A, B;
vector<int> con[LIM];
int P[LIM], C[LIM];
int mZ, mD, mHas[LIM], mC[LIM];
int sz;
LL tree[LIM2];

// DFS from node i, while populating parents
void rec1(int i)
{
  int j, c;
  Fox(j, Sz(con[i]))
    if ((c = con[i][j]) != P[i])
    {
      P[c] = i;
      rec1(c);
    }
}

// DFS from node i, with depth d and previous node p, while populating min. C values per depth
void rec2(int i, int d, int p)
{
  int j, c;
  if (C[i])
  {
    Max(mD, d);
    if (mHas[d] == mZ)
      Min(mC[d], C[i]);
    else
      mHas[d] = mZ, mC[d] = C[i];
  }
  Fox(j, Sz(con[i]))
    if ((c = con[i][j]) != P[i])
      if (c != p)
        rec2(c, d + 1, p);
}

// update value at index i in segment tree to be at most v
void Update(int i, LL v)
{
  i += sz;
  while (i)
  {
    Min(tree[i], v);
    i >>= 1;
  }
}

// query min. value in segment tree within indices [a, b]
LL Query(int i, int r1, int r2, int a, int b)
{
  if (a <= r1 && r2 <= b)
    return(tree[i]);
  i <<= 1;
  int m = (r1 + r2) >> 1;
  LL ret = (LL)INF * INF;
  if (a <= m)
    Min(ret, Query(i, r1, m, a, b));
  if (b > m)
    Min(ret, Query(i + 1, m + 1, r2, a, b));
  return(ret);
}

LL ProcessCase()
{
  int i, j, k, p, d;
  // input
  Read(N), Read(M), Read(A), Read(B);
  Fox1(i, N)
  {
    Read(j), Read(C[i]);
    if (j)
    {
      con[i].pb(j);
      con[j].pb(i);
    }
  }
  // root tree at B
  P[B] = -1;
  rec1(B);
  // init segment tree of min. costs
  Fill(tree, 60);
  for (sz = 1; sz < N; sz <<= 1);
  // iterate along path from A to B while maintaining segment tree
  Update(0, 0);
  for (p = A, i = P[A], k = 1; i != B; p = i, i = P[i], k++)
  {
    // explore branches off of main path
    mZ++, mD = -1;
    rec2(i, 0, p);
    // consider refueling here or within an attached branch
    Fox(d, mD + 1)
      if (k - d >= 0 && mHas[d] == mZ)
      {
        LL m = Query(1, 0, sz - 1, max(0, k - (M - d)), k);
        Update(k - d, m + mC[d]);
      }
  }
  // clear graph
  Fox1(i, N)
    con[i].clear();
  // get answer
  LL ans = Query(1, 0, sz - 1, max(0, k - M), k - 1);
  return ans >= (LL)INF * INF ? -1 : ans;
}

int main()
{
  int T, t;
  Read(T);
  Fox1(t, T)
    printf("Case #%d: %lld\n", t, ProcessCase());
  return(0);
}
