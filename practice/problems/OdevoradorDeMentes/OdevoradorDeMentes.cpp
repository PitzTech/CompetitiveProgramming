//https://neps.academy/problem/860
#include <bits/stdc++.h>

using namespace std;
#define MAXI 1000
#define pb push_back 
#define endl "\n"

vector<int> host[MAXI];

int getHost(int p){
    if(host[p][0] == -1)
        return true;
    return false;
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);    

    int p, cad, passado;
    cin >> p >> cad;
    
    int xp = -1;
    for(int x = 0; x < cad; x++){
        if(x != xp){
            passado = -1;
            xp = x;
        } 
        int atu;

        cin >> atu;
        host[atu].pb(passado);
        passado = atu;

        int np;
        cin >> np;

        for(int y = 0; y < np; y++){
            cin >> atu;
            host[atu].pb(passado);
            passado = atu;
        }
    }

    for(int x = 1; x <= p; x++)
        if(getHost(x))
            cout << x << endl;
    return 0;
}