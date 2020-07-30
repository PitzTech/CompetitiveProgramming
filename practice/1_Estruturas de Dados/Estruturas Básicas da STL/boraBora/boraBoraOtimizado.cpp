#include <bits/stdc++.h>

#define PLAYERS 10

const char PAUS = 'C'; // + 4
const char OUROS = 'D'; // + 3
const char COPAS = 'H'; // + 2
const char ESPADAS = 'S'; // + 1

using namespace std;

int players, pcards, gcards, descarte, num;
bool effect = false, sentido = true;
char naipe;
vector<int> mao[PLAYERS];
vector<int> saque;
/**
mao[jogador].insert(
mao[jogador].begin(), 
lower_bound(mao[jogador].begin(), mao[jogador].end(),saque.back()) - mao[jogador].begin(),
saque.back());
 * */

int proxRound(int jogador){
    //printf("PLayer: %d\n",jogador);
    if(effect){
        if(floor(descarte/10) != 11){
            mao[jogador].insert(lower_bound(mao[jogador].begin(), mao[jogador].end(),saque.back()), saque.back());
            saque.pop_back();
            if(floor(descarte/10) == 7){
               mao[jogador].insert(lower_bound(mao[jogador].begin(), mao[jogador].end(),saque.back()), saque.back());
                saque.pop_back(); 
            }
        }
        effect = false;  
    }else{
        int posi = -1;
        for(int carta = mao[jogador].size() - 1; carta >= 0; carta--){
            if(floor(mao[jogador][carta]/10) == floor(descarte/10) || mao[jogador][carta]%10 == descarte%10){
                posi = carta;
                break;
            }
        }
        if(posi == -1){
            mao[jogador].insert(lower_bound(mao[jogador].begin(), mao[jogador].end(),saque.back()), saque.back());
            saque.pop_back();
        }
        for(int carta = mao[jogador].size() - 1; carta >= 0; carta--){
            if(floor(mao[jogador][carta]/10) == floor(descarte/10) || mao[jogador][carta]%10 == descarte%10){
                posi = carta;
                break;
            }
        }
        if(posi != -1){
            //printf("Joga: %d\n", mao[jogador][posi]);
            descarte = mao[jogador][posi];
            if(mao[jogador].size() - 1 == 0){
                return jogador + 1; 
            }
            
            mao[jogador].erase(mao[jogador].begin() + posi);
        
            if(floor(descarte/10) == 1 || floor(descarte/10) == 7 || floor(descarte/10) == 11)
                effect = true;
            else if(floor(descarte/10) == 12)
                sentido = !sentido;
        
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
        //printf("Reinicia\n");
        scanf("%d %d %d", &players, &pcards, &gcards);
        if(players == 0 && pcards == 0 && gcards == 0) break;

        effect = false;
        sentido = true;

        for(int jogador = 0; jogador<players;jogador++){
            mao[jogador].clear();
            for(int cartas = 0; cartas < pcards;cartas++){
                int num;
                char naipe;
                scanf("%d %c", &num, &naipe);
                if(naipe == ESPADAS) naipe = 4;
                else if(naipe == COPAS) naipe = 3;
                else if(naipe == OUROS) naipe = 2;
                else naipe = 1;
                mao[jogador].push_back(10*num+naipe); 
            }
            sort(mao[jogador].begin(), mao[jogador].end());
        }
        
        scanf("%d %c", &num, &naipe);
        if(naipe == ESPADAS) naipe = 4;
        else if(naipe == COPAS) naipe = 3;
        else if(naipe == OUROS) naipe = 2;
        else naipe = 1;
        descarte = 10*num+naipe;

        if(floor(descarte/10) == 1 || floor(descarte/10) == 7 || floor(descarte/10) == 11)
            effect = true;
        else if(floor(descarte/10) == 12)
            sentido = !sentido;
        
        saque.clear();
        for(int nsaque = gcards - players*pcards - 2; nsaque >= 0; nsaque--){
            scanf("%d %c", &num, &naipe);
            if(naipe == ESPADAS) naipe = 4;
            else if(naipe == COPAS) naipe = 3;
            else if(naipe == OUROS) naipe = 2;
            else naipe = 1;
            saque.push_back(10*num+naipe);
        }
        reverse(saque.begin(),saque.end());
        
        printf("%d\n", proxRound(0));
    }
    return 0;
}