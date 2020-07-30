#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define PLAYERS 10

const char PAUS = 'C';
const char OUROS = 'D';
const char COPAS = 'H';
const char ESPADAS = 'S';

using namespace std;
using ia = pair<int,char>;

ia descarte;
vector<ia> mao[PLAYERS];
vector<ia> saque;
int players, pcards, gcards;
bool effect = false, sentido = true;

bool vePlayer(ia a, ia b){
    if(a.ff == descarte.ff || b.ff == descarte.ff){
        if(a.ff == b.ff){
            if(a.ss == ESPADAS || (a.ss == COPAS && b.ss != ESPADAS) || (a.ss == OUROS && b.ss == PAUS))
                return false;
        }else if(a.ff == descarte.ff) return false;
    }
    if(a.ss == descarte.ss || b.ss == descarte.ss){
        if(a.ss == b.ss && a.ff > b.ff) return false;  
        else if(a.ss == descarte.ss) return false;
    }
    return true;
}
int proxRound(int jogador){ // jogador = atual != prox
    //printf("jogador: %d\n", jogador);
    if(effect){
        if(descarte.ff == 1){
            mao[jogador].pb(saque.back());
            saque.pop_back();
        }else if(descarte.ff == 7){
            mao[jogador].pb(saque.back());
            saque.pop_back();
            mao[jogador].pb(saque.back());
            saque.pop_back();
        }
        effect = false;  
    }else{
        sort(mao[jogador].begin(), mao[jogador].end(), vePlayer);
        if(mao[jogador].back().ss == descarte.ss || mao[jogador].back().ff == descarte.ff){
            descarte = mao[jogador].back(); 
            
            if(mao[jogador].size() - 1 == 0){
                return jogador + 1; 
            }
            mao[jogador].pop_back();
            
            if(descarte.ff == 1 || descarte.ff == 7 || descarte.ff == 11)
                effect = true;
            else if(descarte.ff == 12)
                sentido = !sentido;
            
            
        }else{
            mao[jogador].pb(saque.back());
            saque.pop_back();
        }
    }
    if(sentido){
        if(jogador+1 > players - 1) jogador = 0;
        else jogador++;
    }else{
        if(jogador-1 < 0) jogador = players - 1;
        else jogador--;
    }
    return proxRound(jogador);
}
int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    while(true){
        scanf("%d %d %d", &players, &pcards, &gcards);
        effect = false;
        sentido = true;
        if(players == 0 && pcards == 0 && gcards == 0) break;
        for(int jogador = 0; jogador < players; jogador++){
            mao[jogador].clear();
            for(int cartas = 0; cartas < pcards; cartas++){
                ia c;
                scanf("%d %c", &c.ff, &c.ss);
                mao[jogador].pb(c); // emplace_back(ff,ss)
            }
        }
        scanf("%d %c", &descarte.ff,&descarte.ss);
        
        if(descarte.ff == 1 || descarte.ff == 7 || descarte.ff == 11)
            effect = true;
        else if(descarte.ff == 12)
            sentido = !sentido;
        

        saque.clear();
        saque.reserve(gcards - players*pcards - 1);
        for(int nsaque = gcards - players*pcards - 2; nsaque >= 0; nsaque--){
            scanf("%d %c", &saque[nsaque].ff ,&saque[nsaque].ss);
        }
        printf("%d\n", proxRound(0));
    }
    return 0;
}