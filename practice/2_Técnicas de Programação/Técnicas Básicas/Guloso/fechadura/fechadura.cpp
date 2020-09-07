#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int nPinos, altura, moves = 0,  pinos[1000];

    scanf("%d %d", &nPinos, &altura);
    
    for(int x = 0; x < nPinos; x++) scanf("%d", &pinos[x]);
    for(int x = 0; x+1 < nPinos; x++){
       int diff = altura - pinos[x];
       pinos[x] += diff;
       pinos[x+1] += diff;
       moves += abs(diff);
    }
    if(pinos[nPinos-1] != altura) moves--;
    printf("%d", moves);
    return 0;
}