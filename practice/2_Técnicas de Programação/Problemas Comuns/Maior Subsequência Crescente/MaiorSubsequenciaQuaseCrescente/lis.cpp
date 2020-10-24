#include <bits/stdc++.h>
#define MAXN 1003
#define PB push_back
using namespace std;
using ll = long long;

int lis(vector<ll> &v){
	
	vector<ll> pilha; // declaro o vector que guardará o topo de cada pilha
	
	// para cada elemento v[i] da sequência
	for(int i=0; i<v.size(); i++){
		
		// declaro um iterador que guardará o elemento mais à esquerda de pilha
		// que não é menor que v[i]
		vector<ll>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
		
		// se it for o fim do vector, então não há elemento que não seja menor que v[i]
		// ou seja, todos os topos de pilha são menores ou iguais a v[i]
		
		// logo, criamos uma nova pilha e colocamos v[i.] no seu topo
		if(it==pilha.end()) pilha.PB(v[i]);
		
		// porém, se it apontar para alguma posição válida do vector
		// colocamos v[i] no topo desta pilha, substintuindo o valor que it aponta por v[i]
		else *it = v[i];
	}
	
	return pilha.size();
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> lista(n);
    for(ll &el : lista)
        cin >> el;

    cout << lis(lista);
    return 0;
}
