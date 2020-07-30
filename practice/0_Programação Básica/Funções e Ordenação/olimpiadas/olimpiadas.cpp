#include <bits/stdc++.h>
using namespace std;

struct Pais{
    int id;
    int medalha[3] = {0,0,0};
};
bool compPais(Pais p1, Pais p2){
    if(p1.medalha[0] != p2.medalha[0]) return p1.medalha[0] > p2.medalha[0];
    if(p1.medalha[1] != p2.medalha[1]) return p1.medalha[1] > p2.medalha[1];
    if(p1.medalha[2] != p2.medalha[2]) return p1.medalha[2] > p2.medalha[2];
    return p1.id < p2.id;
}
int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int pai, mod, resul;
    cin >> pai >> mod;
    Pais pais[pai];
    for(int x = 0; x < pai; x++)
        pais[x].id = x + 1;
    for(int x = 0; x < mod; x++){
        for(int y = 0; y < 3; y++){
            cin >> resul;
            pais[resul - 1].medalha[y]++;
        }
    }
    sort(pais, pais+pai, compPais);
    for(int x = 0; x < pai; x++){
        cout << pais[x].id << " ";
    }
}