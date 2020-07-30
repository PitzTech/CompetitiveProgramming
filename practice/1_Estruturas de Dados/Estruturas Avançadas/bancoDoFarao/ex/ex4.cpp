#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.14159265358979323846
#define mod 998244353
#define INF 100000000
#define MAX 1000000
#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define forn(i, n) for(int i=0; i<(int)(n); i++)

using namespace std;


typedef struct
{
	pii prefix, sufix, total, maximo; 
} no;

int noleft[MAX], noright[MAX], v[MAX];
no arvore[MAX];

pii somar(pii a, pii b)
{
	return mp(a.f+b.f, a.s+b.s);
}

no une(no l, no r)
{
	if(l.total.s==0)
		return r;
	if(r.total.s==0)
		return l;

	no m;

	m.prefix = max(l.prefix, somar(l.total, r.prefix));
	m.sufix = max(r.sufix, somar(r.total, l.sufix));
	m.total = somar(l.total, r.total);
	m.maximo = max(max(l.maximo, r.maximo), somar(l.sufix, r.prefix));

	return m;
}

no makenozero()
{
	no m;
	m.prefix=m.sufix=m.total=m.maximo=mp(0,0);
	return m;
}

no makeno(int k)
{
	no m;
	m.prefix=m.sufix=m.total=m.maximo=mp(k,1);
	return m;
}

void monta(int n)
{
	if(noleft[n]==noright[n])
	{
		arvore[n]=makeno(v[noleft[n]]);
		return;
	}

	int mid = (noleft[n]+noright[n])/2;
	noleft[2*n]=noleft[n]; noright[2*n]=mid;
	noleft[2*n+1]=mid+1; noright[2*n+1]=noright[n];

	monta(2*n);
	monta(2*n+1);

	arvore[n]=une(arvore[2*n], arvore[2*n+1]);
}

no busca(int n, int esq, int dir)
{
	if(noleft[n]>=esq and noright[n]<=dir)
		return arvore[n];
	if(noright[n]<esq or noleft[n]>dir)
		return makenozero();

	return une(busca(2*n, esq, dir),busca(2*n+1, esq, dir));
}

int main()
{
	int T, N, Q, A, B;
	no aux;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		for(int i=1;i<=N;i++)
			scanf("%d", &v[i]);

		noleft[1]=1;noright[1]=N;
		monta(1);

		cin >> Q;
		while(Q--)
		{
			scanf("%d%d", &A, &B);
			aux = busca(1, A, B);
			printf("%d %d\n", aux.maximo.f, aux.maximo.s);
		}
	}


	return 0;
}