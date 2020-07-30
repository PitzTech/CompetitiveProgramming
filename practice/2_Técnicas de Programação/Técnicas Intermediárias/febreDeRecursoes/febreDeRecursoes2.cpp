#include <bits/stdc++.h>
using namespace std;

int recu[1003], soma[1003], resul;
long int n, k, m;
int main(){
     freopen("in","r",stdin);
     freopen("out","w",stdout);
    
    scanf("%d %d %d", &n,&k,&m);
    for(int x = 1; x <= n;x++)
        scanf("%d", &soma[x]);
    for(int x = 1; x <= n; x++){
        if(x <= n) scanf("%d", &recu[x]);
        else{
            recu[x] = 0;
            for(int y = 1; y <= n; y++){
                recu[x] +=  soma[y] * recu[x-y];
            }
        }
    }
    resul = recu[n] % m;
    printf("%d", resul);
}