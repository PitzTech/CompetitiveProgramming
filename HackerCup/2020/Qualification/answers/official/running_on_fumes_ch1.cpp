// Running on Fumes - Chapter 1
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
#define IMP 1e18

int N, M;
int C[LIM];
deque<pair<int, LL>> D; // <city, min. cost to be there with full tank>

LL ProcessCase()
{
  int i;
  // input
  Read(N), Read(M);
  Fox(i, N)
    Read(C[i]);
  // iterate over cities while maintaining deque of min. costs
  D.clear();
  D.push_back(mp(0, 0));
  Fox(i, N)
  {
    // remove entries too far back to reach current city
    while (!D.empty() && D.front().x < i - M)
      D.pop_front();
    // impossible to make it this far?
    if (D.empty())
      return(-1);
    // consider refueling here
    if (C[i])
    {
      LL d = D.front().y + C[i];
      // remove no-longer-relevant entries
      while (!D.empty() && d <= D.back().y)
        D.pop_back();
      D.push_back(mp(i, d));
    }
  }
  return(D.front().y);
}

int main()
{
  int T, t;
  Read(T);
  Fox1(t, T)
    printf("Case #%d: %lld\n", t, ProcessCase());
  return(0);
}