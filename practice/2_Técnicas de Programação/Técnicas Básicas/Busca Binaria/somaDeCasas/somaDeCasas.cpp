#include <bits/stdc++.h>
using namespace std;

int ncasas, soma, casas[100002], numa,numb = 0;
int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    scanf("%d", &ncasas);
    for(int x = 0; x < ncasas; x++) scanf("%d",&casas[x]);
    scanf("%d", &soma);
    for(int x = 0; x < ncasas; x++){
        numa = casas[x];
        if(numa >= soma) continue;
        int falta = soma - numa;
        int ini = 0, final = ncasas, media;
        while(final >= ini){
            media = (final+ini)/2;
            //printf("Inicio: %d | Final: %d | Falta: %d | Media: %d \n", ini, final, falta, media);
            //printf("(%d ; %d)\n", numa, casas[media]);
            if(casas[media] == falta){
                numb = falta;
                break;
            }
            if(falta < casas[media]) final = media - 1;
            else ini = media + 1;
        }
        if(numb > 0) break;
    }
    printf("%d %d", numa,numb);
}