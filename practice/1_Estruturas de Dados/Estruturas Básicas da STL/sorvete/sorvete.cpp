#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int beach, n;
vector <pair<int, int>> area;
pair<int,int> sorvete[5000];
int main(){

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    scanf("%d %d", &beach, &n);

    for(int x = 0; x < n; x++){
        scanf("%d %d", &sorvete[x].ff,&sorvete[x].ss);
        if(sorvete[x].ff > sorvete[x].ss) swap(sorvete[x].ss,sorvete[x].ff);
    }
    sort(sorvete, sorvete+n);
    /*for(int x = 0; x < n; x++){
        printf("%d %d\n", sorvete[x].ff,sorvete[x].ss);
    }*/
    
    for(int x = 0; x < n; x++){
        if(x && sorvete[x].ff <= area.back().ss){
            if(area.back().ss < sorvete[x].ss){
                //printf("entrou\n");
                area.back().ss = sorvete[x].ss;
            }
        }
        else area.emplace_back(sorvete[x]);
    }
    for(int x = 0; x < area.size(); x++)
        if(area[x].ff == area[x].ss) printf("%d\n", area[x].ff);
        else printf("%d %d\n", area[x].ff, area[x].ss);
    return 0;
}