#include <bits/stdc++.h>

#define linha first
#define coluna second
using namespace std;

int li, co, mapa[1000][1000];
bool achou = false;
vector<pair<int,int>>path;

void findPath(vector<pair<int,int>>caminho){
    if(achou){
        return;
    }

    int l = caminho.back().linha;
    int c = caminho.back().coluna;

    //printf("%d %d | cauda: %d\n", l, c, caminho.size());

    if(mapa[l][c] == 3){
        achou = true;
        printf("%d", caminho.size());
        return;
    }
    
    if(l != 0 && mapa[l-1][c] != 0 
    && l-1 != caminho[caminho.size() - 2].linha){
        vector<pair<int,int>>temp = caminho;
        temp.emplace_back(l-1, c);
        findPath(temp);
    }
    if(l != li-1 && mapa[l+1][c] != 0 
    && l+1 != caminho[caminho.size() - 2].linha){
        vector<pair<int,int>>temp = caminho;
        temp.emplace_back(l+1, c);
        findPath(temp);
    }
    if(c != 0 && mapa[l][c-1] != 0 
    && c-1 != caminho[caminho.size() - 2].coluna){
        vector<pair<int,int>>temp = caminho;
        temp.emplace_back(l, c-1);
        findPath(temp);
    }
    if(c != co-1 && mapa[l][c+1] != 0 
    && c+1 != caminho[caminho.size() - 2].coluna){
        vector<pair<int,int>>temp = caminho;
        temp.emplace_back(l, c+1);
        findPath(temp);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> li >> co;
    int paths = 0;
    for(int l = 0;l < li; l++){
        for(int c = 0; c < co ; c++){
            cin >> mapa[l][c];
            if(mapa[l][c] == 2)
                path.emplace_back(l,c);
        }
    }    
    findPath(path);
    return 0;
}