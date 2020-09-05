#include <bits/stdc++.h>
using namespace std;

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
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}