#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n;
pii mapa[2003];

int achar(ll d, int p, int x, int y){ //distancia passada e pontos
    cout << "(" << x << ";" << y << ")\n";
    int maior = -1;
    int maiord = -1;
    for(int i = 0; i < n; i++){
        int ax = abs(mapa[i].ff - x);
        int ay = abs(mapa[i].ss - y);
        if(ax == 0 && ay == 0) continue;

        ll dist = ax*ax + ay*ay;
        if(dist < d && dist > maiord){
            cout << "   " << "(" << mapa[i].ff << ";" << mapa[i].ss << ")\n";
            maior = i;
            maiord = dist;
        }
    }
    if(maior == -1)
        return p;
    else
        return achar(maiord,p+1, mapa[maior].ff, mapa[maior].ss);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> mapa[i].ff >> mapa[i].ss;
    
    cout << achar(LLONG_MAX, 0, 0, 0);
    return 0;
}