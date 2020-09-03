#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    int npiles;
    int piles[100];
    int choosen;
    for(int test = 0; test < t; test++){
        cin >> npiles;
        for(int n = 0; n < npiles; n++)
            cin >> piles[n];
        sort(piles, piles+npiles, greater<int>()); 
        choosen = npiles-1;
        bool winner = false; // T
        bool entrou = true;
        //first T
        //second HL
        while(entrou){
            entrou = false;
            winner = !winner;
            for(int n = 0; n < npiles; n++){
                if(n != choosen && piles[n]){
                    for(int n1 = n; n1 < npiles; n1++){
                        if(!piles[n] || !piles[n1]) break;
                        int old = piles[n];
                        piles[n] -= min(piles[n1], piles[n]);
                        piles[n1] -= min(piles[n1], old);
                        entrou = true;
                        choosen = n1;
                    }
                }
                choosen = n;
            }
        }
        if(winner) cout << "T\n";
        else cout << "HL\n";      
    }

    return 0;
}