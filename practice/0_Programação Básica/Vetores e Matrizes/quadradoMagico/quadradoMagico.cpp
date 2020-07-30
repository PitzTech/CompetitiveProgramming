#include <bits/stdc++.h>
using namespace std;
int main(){
    int length,somaxx = 0,somayy = 0,somadiagg = 0;

    cin >> length;

    int somax[length], somay[length],somadiag[2],quadrado[length][length];
    for(int x = 0; x < length; x++){
        somax[x] = 0;
        somay[x] = 0;
    }
    somadiag[0] = 0;
    somadiag[1] = 0;
    for(int x = 0; x < length; x++){
        for(int y = 0; y < length; y++){
            cin >> quadrado[x][y];
            somax[y] += quadrado[x][y];
            somay[x] += quadrado[x][y];
            if(x == y) somadiag[0] += quadrado[x][y];
            if(y == length-1-x) somadiag[1] += quadrado[x][y];
        }
    }
    for(int x = 0; x < length; x++){
        somaxx += somax[x];
        somayy += somay[x];
        if(somax[x] != somay[x])
            somaxx = 0;
        if(x != length -1){
            if(somax[x+1] != somax[x] || somay[x+1] != somax[x])
                somaxx = 0;
            if(somay[x + 1] != somay[x] || somax[x+1] != somay[x])
                somaxx = 0;
        }
        //cout << "somaxx " << somaxx << endl;
        //cout << "somax " << somax[x] << endl;
        //cout << "somayy " << somayy << endl;
        //cout << "somay " << somay[x] << endl;
    }

    somaxx /= length;
    somayy /= length;

    somadiagg = somadiag[0] == somadiag[1] ? somadiag[0] : -1;
    if(somaxx == somax[0] && somayy == somay[0] && somaxx == somayy && somaxx == somadiagg){
        cout << somaxx;
    }else{
        cout << -1;
    }
}
