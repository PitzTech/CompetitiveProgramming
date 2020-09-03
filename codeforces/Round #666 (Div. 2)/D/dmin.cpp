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
    int piles[105];
    int choosen;
    for(int test = 0; test < t; test++){
        cin >> npiles;
        for(int n = 0; n < npiles; n++)
            cin >> piles[n];

        choosen = -1;
        bool winner = false; // HL
        bool entrou = true;
        //first T
        //second HL
        while(entrou){
            entrou = false;
            for(int n = 0; n < npiles; n++){
                if(n != choosen && piles[n] > 0){
                    piles[n]--;
                    choosen = n;
                    entrou = true;
                    winner = !winner;
                    break;
                }
            }
        }
        if(winner) cout << "T\n";
        else cout << "HL\n";      
    }

    return 0;
}