#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int c = 0; c < t; c++){
        long a,b;
        cin >> a >> b;
        long subs = max(b,a) - min(a,b); 
        long ans = subs / 10;
        if(subs % 10) ans++;
        cout << ans << "\n";
    }

    return 0;
}