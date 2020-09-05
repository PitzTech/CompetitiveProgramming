#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll check(ll n , ll ok){
    ll ans=n+ok;
    ll total=0;
    while(ans){
        total+=(ans%10);
        ans/=10;
    }
    return total;
}
 
void solve(){  
    ll n,s;
    cin>>n>>s;
    ll a=n;
    ll total=0;
    while(a){
        total+=(a%10);
        a/=10;
    }
    if(total<=s){
        cout<<0<<"\n";
        return;
    }
    ll b=n;
    ll ok=0;
    ll p=1;
    ll tot=0;
    ll ss=0;
    while(b && total>s){
        ll last=b%10;
        total-=last;
        // cout<<"in "<<last<<" "<<total<<"\n";
        if(last){
            ok+=(ll)(p*(10-last));
            b/=10;
            b+=1;
            ss=b;
            while(ss){
                tot+=(ss%10);
                ss/=10;
            }
            if(b==1){
                b=0;
                break;
            }
            total=tot;
        }
        else{
            b/=10;
        }
        p*=(ll)10;
        if(check(n,ok)<=s){
            cout<<ok<<"\n";
            return;
        }
    }
    cout<<ok<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}