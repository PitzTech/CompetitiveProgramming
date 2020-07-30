#include <bits/stdc++.h>
using namespace std;

const int N = 6, S = 5001;
int vet[N] = {2, 5, 10, 20, 50, 100}, has[N], dp[S], s;

int solve()
{
	dp[0] = 1;
	for (int i = N-1; i >= 0; --i)
		for (int j = s; j >= 0; --j)
			for (int k = 1; k <= has[i] && j-k*vet[i] >= 0; ++k)
				dp[j] += dp[j-k*vet[i]];
	return dp[s];
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	for (int i = 0; i < N; ++i)
		cin >> has[i];
	cout << solve() << "\n";
}

