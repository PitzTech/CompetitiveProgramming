#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int li,co;    
    cin >> li >> co;

    char mapa[co][li];
    int costa = 0;

    for(int c = 0; c < co; c++)
        for(int l = 0; l < li; l++)
            cin >> mapa[c][l];
    
    for(int c = 0; c < co; c++){
        for(int l = 0; l < li; l++){
            if(mapa[c][l] == '#'){
                if(l == 0 || l == li-1 || c == 0 || c == co-1
                || mapa[c][l-1] == '.' || mapa[c][l+1] == '.' 
                || mapa[c-1][l] == '.' || mapa[c+1][l] == '.')
                    costa++;
            }
        }
    }    

    cout << costa;

    return 0;
}