#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, pw, pd;
    cin >> n >> p >> pw >> pd;
    
    if(p > pw*n){
        cout << -1;
    }else{
        int wins, draws, loses;
        wins = min(p / pw, n);
        draws = min(p % pw, n) / pd;
        if(min(p % pw, n) % pd != 0){
            
        }
        loses = n - (wins + draws);
        cout << wins << " " << draws << " " << loses;
    }

    return 0;
}