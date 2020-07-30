#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
int v[N];
bool e[N], d[N];

int main (void) {
	int n;
	scanf ("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf ("%d", &v[i]);
	}

	int me = v[0];
	for (int i = 1; i < n; ++i) {
		if (v[i] < me) e[i] = true;	
		me = max (me, v[i]);
	}
	int md = v[n-1];
	for (int i = n-2; i >= 0; --i) {
		if (v[i] < md) d[i] = true;
		md = max (md, v[i]);
	}

	int ans = 0;
	for (int i = 1; i < n-1; ++i) {
		if (e[i] and d[i]) ans++;
	}
	printf ("%d\n", ans);

	return 0;
}	
