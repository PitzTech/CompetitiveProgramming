#include <bits/stdc++.h>

#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    int n;
    ll c1,c2,c3;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> c1 >> c2 >> c3;
        cout << ((c1 + c2 + c3)/2) << "\n";
    }

    return 0;
}