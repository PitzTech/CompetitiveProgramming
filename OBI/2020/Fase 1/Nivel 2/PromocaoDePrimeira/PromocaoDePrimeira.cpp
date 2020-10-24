#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using vvp = vector<vector<pair<int,int>>>;

struct par{
    int max0, max1;
};

vvp arr;
int opt;

par dfs(int v, int pai){
    par atual {0,0};

    for(auto u : arr[v]){
        if(u.first != pai){
            auto ret = dfs(u.first, v);
            if(u.second == 0)
                atual.max0 = max(atual.max0, ret.max1 + 1);
            else
                atual.max1 = max(atual.max1, ret.max0 + 1);
        }
    }

    opt = max(opt, atual.max0 + atual.max1 + 1);

    return atual;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    arr = vvp(n+1);
    for(int i = 0; i < n-1; i++){
        int a,b,e;
        cin >> a >> b >> e;
        arr[a].pb({b,e});
        arr[b].pb({a,e});
    }

    opt = 0;
    dfs(1,-1);
    cout << opt << "\n";

    return 0;
}