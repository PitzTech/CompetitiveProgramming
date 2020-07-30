#include <bits/stdc++.h>

using namespace std;

int c, n, atrasos = 0, caixa, tAtend, hEntrada;
priority_queue<int, vector<int>, greater<int>> caixas; 

int main(){

    freopen("in", "r",stdin);
    freopen("out", "w", stdout);

    scanf("%d %d", &c, &n);

    for(int x = 0; x < c; x++) caixas.push(0);

    for(int x = 0; x < n; x++){
        scanf("%d %d", &hEntrada, &tAtend);
        caixa = caixas.top();
        caixas.pop();
        
        if(caixa > hEntrada+20) atrasos++;
        
        caixas.push(max(caixa, hEntrada) + tAtend);
    }

    printf("%d", atrasos);
    return 0;
}