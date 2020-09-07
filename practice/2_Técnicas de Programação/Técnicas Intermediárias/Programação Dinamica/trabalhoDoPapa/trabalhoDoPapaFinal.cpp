#include <bits/stdc++.h>
using namespace std;

struct Caixas{
    int p, r, s;
};
int n, menorPeso[1005][1005];
Caixas caixa[1005];
bool sortCaixas(Caixas a, Caixas b){
    return a.r > b.r;
}

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d", &n);
    
    for(int x = 0; x < n; x++){
        scanf("%d %d", &caixa[x].p, &caixa[x].r);
        caixa[x].s = caixa[x].r - caixa[x].p;
    }
    sort(caixa, caixa+n, sortCaixas);
    
    for(int x = 0; x <= n; x++){
        for(int y = 0; y <= n; y++){
            menorPeso[x][y] = x == 0 ? 0 : 1000006;
        }
    }
    for(int mp = 1; mp <= n; mp++){
    	for(int blo = 0; blo < n; blo++){ 
			// Se a caixa[blo] pode ficar na base da menor pilha com mp-1 caixas
			// a gente consegue fazer uma pilha de mp caixas com as caixas de blo
			// pra frente
	        if(caixa[blo].p + menorPeso[mp-1][blo+1] <= caixa[blo].r){
	            menorPeso[mp][blo] = caixa[blo].p + menorPeso[mp-1][blo+1];
	        }
	    }
		// Sem esse loop de baixo menorPeso[x][y] considera só a resposta pegando o elemento y
		// obrigatoriamente, pegando o mínimo de tudo que tem pra frente considera pegar ou não
		// o elemento y
		for(int blo = n-2; blo >= 0; blo--){
			menorPeso[mp][blo] = min(menorPeso[mp][blo+1], menorPeso[mp][blo]);
		}
	}
    int maxi = 0;
    for(int x = 0; x <= n; x++){
        for(int y = n-1; y >= 0; y--){
            if(menorPeso[x][y] < 1000006){
                maxi = x;
                break;
            }
        }
    }
    printf("%d\n", maxi);
}