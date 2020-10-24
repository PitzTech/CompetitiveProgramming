#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vll> pilhas;
    int n;
    cin >> n;
    while(n--){
        int el;
        cin >> el;
        for(auto &pilha : pilhas){
            if(pilha.back() <= el)
                pilha.push_back(el);
        }
        pilhas.push_back(vll {el});
    }
    ll maxn = 1;
    //int pilh = 1;
    for(auto pilha : pilhas){
        // cout << "Pilha " << pilh++ << "\n";
        // for(auto el : pilha)
        //     cout << el << "\n";
        maxn = max(maxn, (ll)pilha.size());
    }
    cout << maxn;

    return 0;
}