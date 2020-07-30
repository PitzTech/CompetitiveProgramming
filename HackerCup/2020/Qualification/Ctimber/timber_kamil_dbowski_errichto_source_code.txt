#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }



void test_case() {
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> in(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &in[i].first, &in[i].second);
	}
	sort(in.begin(), in.end());
	map<int,int> dp;
	int answer = 0;
	for(pair<int,int> p : in) {
		int pos = p.first;
		int h = p.second;
		dp[pos+h] = max(dp[pos+h], dp[pos] + h);
		dp[pos] = max(dp[pos], dp[pos-h] + h);
		answer = max({answer, dp[pos], dp[pos+h]});
	}
	printf("%d\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
