#include <bits/stdc++.h>
using namespace std;

struct Atendimento{
    int ini, fim;
};
bool pegaAtendimento(Atendimento a, Atendimento b){
    return a.fim < b.fim;
}
int n, livre = 0, resul = 0;
Atendimento consultas[10000];
int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    scanf("%d", &n);
    for(int x = 0; x < n; x++)
        scanf("%d %d", &consultas[x].ini, &consultas[x].fim);
    sort(consultas, consultas+n, pegaAtendimento);
    for(int x = 0; x < n; x++){
        if(consultas[x].ini >= livre){
            resul++;
            livre = consultas[x].fim;
        }
    }
    printf("%d", resul);
    return 0;
}