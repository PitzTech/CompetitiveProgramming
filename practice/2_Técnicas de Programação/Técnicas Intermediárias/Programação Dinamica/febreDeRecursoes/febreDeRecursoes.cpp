#include <bits/stdc++.h>
using namespace std;

long long int recu[1003], soma[1003];
long long int n, k, m, cont;
int recursao(int k){
    if(k <= n || k <= cont) return recu[k];
    recu[k] = 0;
    for(int x = 1; x <= n; x++){
        recu[k] += (soma[x] * recursao(k-x)) % m;
    }
    //printf("k: %d = %d\n", k, recu[k]);
    cont++;
    return recu[k];
}
int main(){
     freopen("in","r",stdin);
     freopen("out","w",stdout);
    
    scanf("%d %d %d", &n,&k,&m);
    cont = n;
    for(int x = 1; x <= n;x++)
        scanf("%d", &soma[x]);
    for(int x = 1; x <= n; x++)
        scanf("%d", &recu[x]);
    printf("%d", recursao(k) % m);
}