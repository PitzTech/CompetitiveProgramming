#include <bits/stdc++.h>
using namespace std;

int n,f;
int mapa[505][505];
bool dfs[505][505];

void procura(int x, int y){
    if(dfs[x][y]) return;
    dfs[x][y] = true;
    //cout << "x: " << x << " y: " << y << "\n"; 
    //x
    //left
    if(x > 0 && mapa[x-1][y] <= f){
        mapa[x-1][y] = -1;
        procura(x-1,y);
    }
    //right
    if(x < n-1 && mapa[x+1][y] <= f){
        mapa[x+1][y] = -1;
        procura(x+1,y);
    }
    //y
    //top
    if(y > 0 && mapa[x][y-1] <= f){
        mapa[x][y-1] = -1;
        procura(x,y-1);
    }
    //down
    if(y < n-1 && mapa[x][y+1] <= f){
        mapa[x][y+1] = -1;
        procura(x,y+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> f;

    for(int i = 0; i < n; i++){
        string linha;
        cin >> linha;
        for(int j = 0; j < n; j++){
            mapa[i][j] = linha[j]-'0';
        }   
    }   
    if(mapa[0][0] <= f) {
        mapa[0][0] = -1;
        procura(0,0);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mapa[i][j] == -1)
                cout << "*"; 
            else
                cout << mapa[i][j]; 
        }
        cout << "\n";
    }
    return 0;
}