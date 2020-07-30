#include <bits/stdc++.h>

#define MAX 1000000
#define ff first
#define ss second

using namespace std;
using ii = pair<int,int>;

struct no{
	ii prefix, sufix, total, maximo; 
};

ii somar(ii a, ii b){
	return make_pair(a.ff+b.ff, a.ss+b.ss);
}

no merge(no l, no r){
	if(l.total.ss == 0)
		return r;
	if(r.total.ss == 0)
		return l;

	no m;

	m.prefix = max(l.prefix, somar(l.total, r.prefix));
	m.sufix = max(r.sufix, somar(r.total, l.sufix));
	m.total = somar(l.total, r.total);
	m.maximo = max(max(l.maximo, r.maximo), somar(l.sufix, r.prefix));

	return m;
}

no makenozero(){
	no m;
	m.prefix = m.sufix = m.total = m.maximo = make_pair(0,0);
	return m;
}

no makeno(int n){
	no m;
	m.prefix = m.sufix = m.total = m.maximo = make_pair(n,1);
	return m;
}

int noleft[MAX], noright[MAX], v[MAX];
no arvore[MAX];

void buildTree(int n){
	if(noleft[n] == noright[n]){
		arvore[n] = makeno(v[noleft[n]]);
		return;
	}

	int mid = (noleft[n]+noright[n])/2;
	
    //left
    noleft[2*n] = noleft[n]; 
    noright[2*n] = mid;
	//right
    noleft[2*n+1] = mid+1; 
    noright[2*n+1] = noright[n];

	buildTree(2*n);
	buildTree(2*n+1);

	arvore[n] = merge(arvore[2*n], arvore[2*n+1]);
}

no busca(int n, int esq, int dir){
	if(noleft[n] >= esq && noright[n] <= dir)
		return arvore[n];
	if(noright[n] < esq || noleft[n] > dir)
		return makenozero();

	return merge(busca(2*n, esq, dir),busca(2*n+1, esq, dir));
}

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
	int instancias;
	scanf("%d", &instancias);

    int n, Q, A, B;
    no aux;
	while(instancias--){
		scanf("%d", &n);
		for(int x = 1; x <= n; x++)
			scanf("%d", &v[x]);

		noleft[1] = 1;
        noright[1] = n;
		buildTree(1);

		scanf("%d", &Q);
		while(Q--){
			scanf("%d %d", &A, &B);
			aux = busca(1, A, B);
			printf("%d %d\n", aux.maximo.ff, aux.maximo.ss);
		}
	}

	return 0;
}