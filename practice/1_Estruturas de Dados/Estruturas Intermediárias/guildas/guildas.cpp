#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int nPlayers, nCmd, vitorias, players[MAXN],guildas[MAXN], pt[MAXN];

int findP(int a){
    if(guildas[a] == a) return a;
    guildas[a] = findP(guildas[a]);
    return guildas[a];
}
void join(int p1, int p2){
    p1 = findP(p1);
    p2 = findP(p2);

    if(p1 == 1){
        guildas[p2] = p1;
        pt[p1] += pt[p2];
    }else if(p2 == 1){
        guildas[p1] = p2;
        pt[p2] += pt[p1];
    }else{
        guildas[p1] = p2;
        pt[p2] += pt[p1];
    }
}
void battle(int a, int b){
    a = findP(a);
    b = findP(b);
    if((a == 1 && pt[1] > pt[b]) || (b == 1 && pt[1] > pt[a])){
        vitorias++;
    }
}
int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    //rafael = 1
    while(scanf("%d %d", &nPlayers, &nCmd) == 2 && nPlayers+nCmd > 0){
        vitorias = 0;
        for(int x = 1; x <= nPlayers; x++){
            scanf("%d", &players[x]);
            guildas[x] = x;
            pt[x] = players[x];
        }
        int acao,gA,gB;
        for(int x = 0; x < nCmd; x++){
            scanf("%d %d %d", &acao, &gA, &gB);
            if(acao == 1){ //fusion
                join(gA, gB);
            }else{ //battle
                battle(gA, gB);
            }
        }
        printf("%d", vitorias);
    }
    return 0;
}