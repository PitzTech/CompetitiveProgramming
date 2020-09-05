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
    void solve(){  
        int n,x,y;
        cin>>n>>x>>y;
        vector<int>a(n);
        vector<int>b(n);
        if(n==2){
            b[0]=x;
            b[1]=y;
            for(auto i : b)
                cout<<i<<" ";
            cout<<"\n";
            return;
        }
        b[n-1]=1e9+5;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                a[i]=x;
                a[j]=y;
                int diff=y-x;
                int d=j-i;
                if(diff%d==0){
                    diff=diff/d;
                    for(int k=i-1;k>=0;k--)
                        a[k]=a[k+1]-diff;
                    for(int k=i+1;k<n;k++)
                        a[k]=a[k-1]+diff;
                    if(a[0]>0 && a[n-1]<b[n-1])
                        b=a;
                }
            }
        }
        for(auto i : b)
            cout<<i<<" ";
        cout<<"\n";
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