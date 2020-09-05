#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+5;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
 
    ll modPow(ll a, ll b){
        if(b==0)
            return 1LL;
        if(b==1)
            return a%M;
        ll res=1;
        while(b){
            if(b%2==1)
                res=mul(res,a);
            a=mul(a,a);
            b=b/2;
        }
        return res;
    }
 
    ll ok(ll a, ll b, ll x, ll y, ll n){
        ll d1=a-x;
        ll d2=b-y;
        ll c1=min(d1,n);
        a-=c1;
        n-=c1;
        ll c2=min(d2,n);
        b-=c2;
        n-=c2;
        ll ans=a*b;
        return ans;
    }
 
    void solve(){  
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll ans =min(ok(a,b,x,y,n),ok(b,a,y,x,n));
        cout<<ans<<"\n";
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }