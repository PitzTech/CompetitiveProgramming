#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAXN 1000
#define MAXM 10000

typedef pair<int, int> aresta;
typedef pair<int, aresta> estrada;

int N, M;

int conj[MAXN];
estrada v[MAXM];


/* Minimum Spanning Tree */
int mst(){
	sort(v,v+M);

	int res = 0;
	for(int i = 0; i < N; i++) conj[i] = i;
	for(int i = 0; i < M; i++){
		estrada e = v[i];
		int p,q,u;
		p = e.second.first;
		q = e.second.second;
		u = e.first;

		if(conj[p] == conj[q]) continue;
		int c = conj[p];
		for(int j = 0; j < N; j++)
			if(conj[j] == c) 
				conj[j] = conj[q];

		res += u;
	}
	return res;
}

int main(void){

	scanf("%d %d",&N, &M);
	for(int i = 0; i < M; i++){
		int p,q,u;
		scanf("%d %d %d", &p, &q, &u);
		v[i] = estrada(u, aresta(p,q));
	}
	printf("%d\n",mst());
	return 0;
}



