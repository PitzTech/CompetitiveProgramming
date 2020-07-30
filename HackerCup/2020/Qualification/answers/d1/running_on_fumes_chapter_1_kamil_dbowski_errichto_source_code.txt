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

// const int INF = 1e9 + 5;
const long long LONG_INF = 1e18L + 5;

void test_case() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<long long> cost(n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &cost[i]);
		if(cost[i] == 0) {
			cost[i] = LONG_INF;
		}
	}
	vector<long long> dp(n, LONG_INF);
	dp[0] = 0;
	int B = 1;
	while(B < n) {
		B *= 2;
	}
	vector<long long> tree(2*B, LONG_INF);
	tree[B] = dp[0];
	// for(int i = 0; i < n; ++i) {
		// tree[B+i] = dp[i];
	// }
	for(int i = B - 1; i >= 1; --i) {
		tree[i] = min(tree[2*i], tree[2*i+1]);
	}
	for(int i = 1; i < n; ++i) {
		int L = max(0, i - m) + B;
		int R = i - 1 + B;
		long long small = min(tree[L], tree[R]);
		while(L + 1 < R) {
			small = min(small, tree[L+1]);
			small = min(small, tree[R-1]);
			L /= 2;
			R /= 2;
		}
		if(small >= LONG_INF) {
		}
		else {
			if(i == n - 1) {
				// debug() << imie(dp);
				printf("%lld\n", small);
				return;
			}
			dp[i] = small + cost[i];
			tree[B+i] = dp[i];
			for(int j = (B + i) / 2; j >= 1; j /= 2) {
				tree[j] = min(tree[2*j], tree[2*j+1]);
			}
		}
		// debug() << imie(i) imie(dp[i]);
	}
	puts("-1");
	// assert(false);
	/*
	long long answer = 0;
	for(int i = m; i < n - 1; ++i) {
		int L = B + i - m+1;
		int R = B + i;
		int small = min(tree[L], tree[R]);
		while(L + 1 < R) {
			small = min(small, tree[L+1]);
			small = min(small, tree[R-1]);
			L /= 2;
			R /= 2;
		}
		if(small == INF) {
			puts("-1");
			return;
		}
		answer += small;
	}
	printf("%lld\n", answer);*/
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
