#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll mina, ll minb, ll n){
    ll sub = min(a - mina, n);
    n-=sub;
    a-=sub;
    sub = min(b - minb, n);
    b-=sub;
    n-=sub;
    return (a*b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    long long n,a,b,mina,minb,sub;
    cin >> t;
    while(t--){
        cin >> a >> b >> mina >> minb >> n;
        cout << min(solve(a,b,mina,minb,n),solve(b,a,minb,mina,n)) << "\n";        
    }

    return 0;
}