#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int nAero, nVoo, teste = 1;
    while(scanf("%d %d",&nAero,&nVoo) == 2 && nAero && nVoo){
        printf("Teste %d\n", teste++);
        int aero[nAero+1], origem, destino;
        memset(aero, 0,sizeof(aero));
        for(int x = 1; x <= nVoo;x++){
            scanf("%d %d", &origem, &destino);
            aero[origem]++;
            aero[destino]++;
        }

        int maxi = 0, nres = 0, res[nVoo];
        for(int x = 1; x <= nAero; x++){
            if(aero[x] > maxi){
                maxi = aero[x];
                nres = 0;
                res[nres++] = x;
            }else if(aero[x] == maxi){
                res[nres++] = x;
            }
        }
        sort(res, nres+res);
        for(int x = 0; x < nres; x++)
            printf("%d ", res[x]);
        printf("\n\n");
    }
    return 0;
}