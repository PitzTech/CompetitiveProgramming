#include <bits/stdc++.h>

using namespace std;

int soma_vetor(int n, int v[]){
	int final = 0;
    for(int x = 0; x < n; x++){
        final += v[x];
    }
    return final;
}

int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
	
	int n, v[100100];
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> v[i];

	cout << soma_vetor(n,v) << "\n";
}