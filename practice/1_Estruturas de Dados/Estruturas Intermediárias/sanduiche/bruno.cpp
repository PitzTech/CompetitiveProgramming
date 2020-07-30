#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int vet[N], n, d;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> d;
	for (int i = 0; i < n; ++i)
		cin >> vet[i];
	int res = 0, s = 0, j = 0;
	for (int i = 0; i < n; ++i)
	{
		if (j < i) s += vet[j+1], ++j;
		while (j < n && s < d) 
			s += vet[j], ++j;
		res += s==d; 
		s -= vet[i];
	}
	s = vet[n-1], j = n-1;
	while (j-1 > 0 && vet[j-1]+s < d) s += vet[j-1], --j;
	for (int i = 0; i < n-1; ++i)
	{
		s += vet[i];
		while (j < n-1 && s > d) 
			s -= vet[j], ++j;
		if (i == j)
			s -= vet[j], ++j;
		res += s==d;
	}
	cout << res << endl;
}

