#include <bits/stdc++.h>
using namespace std;

#define maxn 100002
int nfaixas, nogros, faixas[maxn], premios[maxn], ogros[maxn];

int busca(int alvo){
    int in = 0, fim = nfaixas, meio;
    while(fim - in > 1){
        meio = (fim+in)/2;
        if(alvo < faixas[meio])
            fim = meio;
        else
            in = meio ;
    } return premios[fim-1];
}

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d %d", &nfaixas, &nogros);
    faixas[0] = 0;
    for(int i = 0; i < nfaixas-1; i++) scanf("%d", &faixas[i+1]);
    for(int i = 0; i < nfaixas; i++) scanf("%d",&premios[i]);
    for(int i = 0; i < nogros; i++) scanf("%d", &ogros[i]);
    
    for(int i = 0; i < nogros; i++)
        printf("%d ", busca(ogros[i]));

}