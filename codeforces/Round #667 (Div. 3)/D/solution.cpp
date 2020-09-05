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