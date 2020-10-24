#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll d;
    cin >> d;
    
    d = (d-3) % 8;

    if(d == 3)
        cout << 1;
    else if(d == 4)
        cout << 2;
    else cout << 3;

    return 0;
}