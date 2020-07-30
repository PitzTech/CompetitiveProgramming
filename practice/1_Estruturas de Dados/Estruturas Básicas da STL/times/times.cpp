#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define MAX 10000

using namespace std;
using is = pair<int,string>;

vector<is> times[MAX];
is alunos[MAX];
int nalunos, ntimes, atu = 0;

bool sortPair(is a, is b){
    return a.ff > b.ff;
}
bool sortTimes(is a, is b){
    return a.ss < b.ss;
}
int main(){

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    scanf("%d %d", &nalunos,&ntimes);

    for(int x = 0; x < nalunos; x++){
        cin >> alunos[x].ss >> alunos[x].ff;
    }
    sort(alunos, alunos+nalunos, sortPair);
    for(int x = 0; x < nalunos; x++){
        if(atu == ntimes) atu = 0;
        times[atu].pb(alunos[x]);
        atu++;
    }
    for(int x = 0; x < ntimes; x++){
        printf("Time %d\n", x+1);
        sort(times[x].begin(),times[x].end(), sortTimes);
        for(int y = 0; y < times[x].size(); y++) cout << times[x][y].ss << "\n";
        printf("\n");
    }
}