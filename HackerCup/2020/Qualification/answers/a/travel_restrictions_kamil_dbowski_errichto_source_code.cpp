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

const int nax = 1005;
char in[nax], out[nax];

void test_case() {
	int n;
	scanf("%d", &n);
	scanf("%s", in);
	scanf("%s", out);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			bool ok = true;
			if(i <= j) {
				for(int k = i; k < j; ++k) {
					if(out[k] != 'Y' || in[k+1] != 'Y') {
						ok = false;
					}
				}
			}
			else {
				for(int k = i; k > j; --k) {
					if(out[k] != 'Y' || in[k-1] != 'Y') {
						ok = false;
					}
				}
			}
			printf(ok ? "Y" : "N");
		}
		puts("");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		puts("");
		test_case();
	}
}
