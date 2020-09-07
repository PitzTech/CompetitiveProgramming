#include <bits/stdc++.h>
#define INF LLONG_MAX
#define pb push_back
using namespace std;
typedef long long ll;

ll mergeSort(vector<ll>&v){
	if(v.size() == 1) return 0;

    ll inter = 0;
    vector<ll> u1,u2;

	for(ll i = 0; i < v.size()/2;i++)
        u1.pb(v[i]);
    for(ll i = v.size()/2; i < v.size(); i++)
        u2.pb(v[i]);

    inter += mergeSort(u1);
    inter += mergeSort(u2);

    u1.pb(INF);
    u2.pb(INF);

	int ini1 = 0, ini2 = 0;
    for(ll i = 0; i < v.size(); i++){
        if(u1[ini1] <= u2[ini2])
            v[i] = u1[ini1++];
        else{
            v[i] = u2[ini2++];
            inter += u1.size() - ini1 - 1;
        }
    }

    return inter;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    
	ll n;
	cin >> n;

    vector<ll> v(n);
    for(ll &el : v){
		ll x, y;
		cin >> x >> y;
        el = x*x + y*y;
	}
	cout<< (n*(n-1)/2) - mergeSort(v)<<endl;

	return 0;
}