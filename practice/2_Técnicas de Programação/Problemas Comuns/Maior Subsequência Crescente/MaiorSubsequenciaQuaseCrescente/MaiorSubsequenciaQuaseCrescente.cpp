#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll pilhas[n];
    int tam[n], maxn = 1;

    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        for(int j = 0; j < i; j++){
            if(pilhas[j] <= el){
                pilhas[j] = el;
                tam[j]++;
                maxn = max(maxn, tam[j]);
            }
        }
        pilhas[i] = el;
        tam[i] = 1;
    }

    cout << maxn << "\n";

    return 0;
}