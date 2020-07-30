#include <bits/stdc++.h>
using namespace std;

map<int, int> instalados;
map<int, int> atualizados;
int nInsta, nAtua;
int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d %d", &nInsta, &nAtua);
    for(int x = 0; x < nInsta; x++){
        pair<int,int> temp;
        scanf("%d %d", &temp.first, &temp.second);
        instalados.insert(temp);
    }
    for(int x = 0; x < nAtua; x++){
        pair<int,int> temp;
        scanf("%d %d", &temp.first, &temp.second);
        if(instalados[temp.first] < temp.second){
            if(atualizados.find(temp.first) == atualizados.end())
                atualizados.insert(temp);
            else
                if(atualizados[temp.first] < temp.second)
                    atualizados[temp.first] = temp.second;
        }
    }
    for(map<int, int>::iterator it = atualizados.begin(); it != atualizados.end(); ++it){
        printf("%d %d\n", it->first, it->second);
    }
}