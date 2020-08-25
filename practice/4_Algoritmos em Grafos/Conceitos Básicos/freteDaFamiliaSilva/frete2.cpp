#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define MAXM 10000

struct Estrada{
    int custo;
    int a;
    int b;
};


int N, M;
int pai[MAXN];
Estrada v[MAXM];

bool ordenar(Estrada a, Estrada b){
    return a.custo < b.custo;
}

/* Minimum Spanning Tree */
int mst(){
	sort(v,v+M, ordenar);

	int res = 0;
	for(int i = 0; i < N; i++) pai[i] = i;
	for(int i = 0; i < M; i++){
		Estrada e = v[i];
		int p,q,u;
		p = e.a;
		q = e.b;
		u = e.custo;

		if(pai[p] == pai[q]) continue;
		int c = pai[p];
		for(int j = 0; j < N; j++)
			if(pai[j] == c) 
				pai[j] = pai[q];

		res += u;
	}
	return res;
}

int main(){

	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	scanf("%d %d",&N, &M);
	for(int i = 0; i < M; i++)
		scanf("%d %d %d", &v[i].a, &v[i].b, &v[i].custo);
	
    printf("%d\n",mst());

	return 0;
}



