#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int c = 0; c < t; c++){
        int strings;
        bool poss = true;
        map<char, int> letras;
        cin >> strings;
        for(int n = 0; n < strings; n++){
            string linha;
            cin >> linha;
            for(int letra = 0; letra < (int)linha.size(); letra++){
                if(letras.find(linha[letra]) != letras.end())
                    letras[linha[letra]] += 1;
                else letras[linha[letra]] = 1;
            }
        }

        for(map<char, int>::iterator it = letras.begin(); it != letras.end(); ++it){
            if(it->second % strings != 0){
                poss = false;
                break;
            }
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}