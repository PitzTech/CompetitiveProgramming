#include <bits/stdc++.h>
using namespace std;

int maxi, valores[3], cont = 0;

int main(){

    //freopen("in","r",stdin);
    //freopen("out","w",stdout);

    scanf("%d %d %d %d", &maxi, &valores[0], &valores[1],&valores[2]);
    sort(valores, valores+3);
    for(int x = 0; x < 3; x++){
        if(maxi - valores[x] >= 0 ){
            maxi -= valores[x];
            cont++;
        }else break;
    }
    printf("%d", cont);
    return 0;
}