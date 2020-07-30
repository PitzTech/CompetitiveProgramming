#include <bits/stdc++.h>

#define MAX 1000005

using namespace std;

int total, quero, sanduba[2*MAX], soma[2*MAX], cont = 0;

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
    scanf("%d %d", &total, &quero);

    for(int x = 1; x <= total; x++){
        scanf("%d", &sanduba[x]);
        //duplicando
        sanduba[x+total] = sanduba[x];
    }
    //calculando todos
    for(int x = 1; x <= 2*total; x++)   
        soma[x] = sanduba[x] + soma[x-1];

    if(soma[total] >= quero){
        int fim = 1;
        for(int ini = 1; ini <= total; ini++){
            while(fim < 2*total && soma[fim+1]-soma[ini-1] <= quero)
                fim++;
            if(soma[fim]-soma[ini-1] == quero)
                cont++;
        }
    }
    printf("%d\n", cont);
    return 0;
}