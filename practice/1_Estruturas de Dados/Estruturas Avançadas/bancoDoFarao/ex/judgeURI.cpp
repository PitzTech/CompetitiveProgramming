#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 32416187567
 
pii sum(pii a,pii b){
    return mp(a.f+b.f,a.s+b.s);
}
 
struct seg {pii ml,mm,mr,in;};
 
seg mkseg(int n){
    seg p;p.ml=p.mm=p.mr=p.in=mp(n,1);
    return p;
}
seg mk0(){
    seg p;p.ml=p.mm=p.mr=p.in=mp(0,0);
    return p;
}
 
seg merge(seg a, seg b){
    if(a.in.s==0)return b;
    if(b.in.s==0)return a;
    seg ans;
    ans.ml=max(a.ml,sum(a.in,b.ml));
    ans.mm=max(max(a.mm,b.mm),sum(a.mr,b.ml));
    ans.mr=max(b.mr,sum(b.in,a.mr));
    ans.in=sum(a.in,b.in);
    return ans;
}
 
int l,r;
int rig[412345];
int lef[412345];
int v  [412345];
seg val[412345];
 
void build(int n){
    if(n==1){lef[n]=l;rig[n]=r;}
    if(rig[n]==lef[n]){
        val[n]=mkseg(v[rig[n]]);
        return;
    }
    int mid=lef[n]+(rig[n]-lef[n])/2;
    lef[2*n]=lef[n]; rig[2*n]=mid;
    lef[2*n+1]=mid+1;rig[2*n+1]=rig[n];
    build(2*n);build(2*n+1);
    val[n]=merge(val[2*n],val[2*n+1]);
}
 
seg query(int n, int left,int right){
    if(lef[n]>=left && rig[n]<=right)return val[n];
    if(lef[n]>right || rig[n]<left)return mk0();
    return merge(query(2*n,left,right),query(2*n+1,left,right));
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("in","r",stdin);
    freopen("out","w",stdout);
 
    int t;cin>>t;
 
    while(t--){
        cin>>r;
        for(int i=1;i<=r;i++)cin>>v[i];
        build(1);
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int a,b;cin>>a>>b;
            seg resp = query(1,a,b);
            cout<<resp.mm.f<<" "<<resp.mm.s<<endl;
        }
    }
 
    return 0;
}