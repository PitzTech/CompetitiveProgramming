#include <bits/stdc++.h>

#define MAX 1000005
using namespace std;

int n;
vector<int>peca[MAX];
bool balanceado = true;

int findBalanca(int atual){
    if(!balanceado) return 0;

    if(peca[atual].size() == 0)
        return 0;

    int peso1, pesotot = peca[atual].size();
    peso1 = findBalanca(peca[atual][0]);
    pesotot += peso1;
    //printf("%d | peso %d\n", atual, peso1);
    for(int x = 1; x < peca[atual].size(); x++){
        int pesotemp = findBalanca(peca[atual][x]);
        if(peso1 != pesotemp){
            balanceado = false;
            return 0;
        }
        pesotot += pesotemp;
    }
    return pesotot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> n;

    int prende, lugar;
    for(int x = 0; x < n; x++){
        cin >> prende >> lugar;
        peca[lugar].push_back(prende);
    }

    int peso = findBalanca(0);

    printf(balanceado ? "bem" : "mal");

    return 0;
}