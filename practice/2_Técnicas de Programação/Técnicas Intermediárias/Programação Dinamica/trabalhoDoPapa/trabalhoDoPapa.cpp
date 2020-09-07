#include <bits/stdc++.h>
using namespace std;

struct Caixas{
    int p, r, s;
};
int n, menorPeso[1005][1005];
Caixas caixa[1005];
bool sortCaixas(Caixas a, Caixas b){
    return a.r > b.r;
}

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d", &n);
    
    for(int x = 0; x < n; x++){
        scanf("%d %d", &caixa[x].p, &caixa[x].r);
        caixa[x].s = caixa[x].r - caixa[x].p;
    }
    sort(caixa, caixa+n, sortCaixas);
    //for(int blo = n-1; blo >= 0; blo--)
    //    printf("%d\n", caixa[blo].p);
    
    //memset(menorPeso, 1005, sizeof(menorPeso));
    for(int x = 0; x <= n; x++){
        for(int y = 0; y < n; y++){
            menorPeso[x][y] = x == 0 ? 0 : 1005;
        }
    }
    //memset(menorPeso[0], 0, sizeof(menorPeso[0]));
    for(int x = 1; x <= n; x++)
        //menorPeso[x] = 1005;
    for(int mp = 1; mp <= n; mp++){
        for(int blo = n-1; blo >= 0; blo--){ 
            if((caixa[blo].s >= 0 && caixa[blo].p + menorPeso[mp-1][n-mp] < menorPeso[mp][n-mp])){
                menorPeso[mp][n-mp] = caixa[blo].p + menorPeso[mp-1][n-mp];
                //printf("menorPeso[%d][%d] = %d | add el %d | = %d + %d \n", mp, blo, menorPeso[mp][n-mp], blo,caixa[blo].p , menorPeso[mp-1][n-mp]);
            }
        }
    }
    int maxi = 0;
    for(int x = 0; x <= n; x++){
        //printf("menorPeso[%d] = %d\n", x, menorPeso[x]);
        for(int y = n-1; y >= 0; y--){
            if(menorPeso[x+1][y-x] == 1005){
                maxi = x;
                break;
            }
        }
    }
    printf("%d", maxi);
}