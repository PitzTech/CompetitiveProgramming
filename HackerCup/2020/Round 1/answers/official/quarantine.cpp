// Quarantine
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

#define LIM 1000001
#define MOD 1000000007

#define MCPR pair<LL,LL>

int N, K, A, B;
char S[LIM];
int E[LIM], C[LIM];
int pi, P[LIM], L[LIM], R[LIM];
vector<int> ch[LIM];
MCPR preM[LIM], sufM[LIM], subM[LIM];

void ReadSeq(int* V, int N, int K)
{
  int i, A, B, C;
  Fox1(i, K)
    Read(V[i]);
  Read(A), Read(B), Read(C);
  FoxI(i, K + 1, N - 1)
    V[i] = ((LL)A * V[i - 2] + (LL)B * V[i - 1] + C) % i + 1;
}

// traverses the tree in pre-order, numbering nodes and storing their subtrees' ranges
void Pre(int i)
{
  P[pi] = i;
  L[i] = pi++;
  for (auto j : ch[i])
    Pre(j);
  R[i] = pi - 1;
}

// returns number of "*" nodes reachable from i in its subtree
int CountC(int i)
{
  if (S[i] == '#')
    return(0);
  int c = 1;
  for (auto j : ch[i])
    c += CountC(j);
  return(c);
}

// sets C values of all "*" nodes reachable from i in its subtree
void SetC(int i, int c)
{
  if (S[i] == '#')
    return;
  C[i] = c;
  for (auto j : ch[i])
    SetC(j, c);
}

// combines two max/count pairs
MCPR Comb(MCPR a, MCPR b)
{
  LL m = max(a.x, b.x);
  return(mp(m, (a.x == m ? a.y : 0) + (b.x == m ? b.y : 0)));
}

MCPR ProcessCase()
{
  int i, j;
  // init
  Fill(C, 0);
  Fox(i, N)
    ch[i].clear();
  // input, and generate E values
  Read(N), Read(K);
  scanf("%s", &S);
  ReadSeq(E, N, K);
  Fox1(i, N - 1)
  {
    E[i]--;
    ch[E[i]].pb(i);
  }
  // number nodes in pre-order
  pi = 0;
  Pre(0);
  // floodfill to find connected * regions
  int nr = 0;
  LL base = 0;
  Fox(i, N)
    if (S[i] == '*' && !C[i])
    {
      nr++;
      int c = CountC(i);
      SetC(i, c);
      base += (LL)c * (c - 1) / 2;
    }
  // precompute prefix, suffix, and subtree C value max/count pairs
  preM[0] = sufM[N] = mp(-1, 0);
  Fox(i, N)
    preM[i + 1] = Comb(preM[i], mp(C[P[i]], 1));
  FoxR(i, N)
  {
    sufM[i] = Comb(sufM[i + 1], mp(C[P[i]], 1));
    subM[i] = mp(C[i], 1);
    for (auto j : ch[i])
      subM[i] = Comb(subM[i], subM[j]);
  }
  // consider each possible edge to delete
  MCPR ans = mp(-1, 0);
  Fox1(i, N - 1)
    if (S[i] == '#' || S[E[i]] == '#' || nr == 1)
    {
      // compute max/count pairs inside/outside i's subtree
      MCPR in, out;
      if (nr == 1 && (S[i] == '#' || S[E[i]] == '#'))
      {
        // max values are irrelevant in this case
        in = mp(0, R[i] - L[i] + 1);
        out = mp(0, N - in.y);
      }
      else
      {
        in = subM[i];
        out = Comb(preM[L[i]], sufM[R[i] + 1]);
      }
      MCPR cur = mp(base, in.y * out.y);
      if (nr > 1)
        cur.x += in.x * out.x;
      ans = Comb(ans, cur);
    }
  return(ans);
}

int main()
{
  int T, t;
  Read(T);
  Fox1(t, T)
  {
    MCPR ans = ProcessCase();
    printf("Case #%d: %lld %lld\n", t, ans.x, ans.y);
  }
  return(0);
}