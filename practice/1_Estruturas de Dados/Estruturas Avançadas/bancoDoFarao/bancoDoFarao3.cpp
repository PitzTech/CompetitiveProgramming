#include <bits/stdc++.h>

#define MAXN 1000000
#define ff first
#define ss second

using namespace std;
using ii = pair< int,int >;

ii sum(ii a,ii b){
    return make_pair(a.ff+b.ff,a.ss+b.ss);
}
 
struct seg {
    ii ml,mm,mr,in;
};
 
seg mkseg(int n){
    seg p;
    p.ml = p.mm = p.mr = p.in = make_pair(n,1);
    return p;
}
seg mk0(){
    seg p;
    p.ml = p.mm = p.mr = p.in = make_pair(0,0);
    return p;
}
 
seg merge(seg a, seg b){
    if(a.in.ss == 0) return b;
    if(b.in.ss == 0) return a;
    seg ans;
    ans.ml = max(a.ml,sum(a.in,b.ml));
    ans.mm = max(max(a.mm,b.mm),sum(a.mr,b.ml));
    ans.mr = max(b.mr,sum(b.in,a.mr));
    ans.in = sum(a.in,b.in);
    return ans;
}
 
int l,r;
int rig[MAXN];
int lef[MAXN];
int v  [MAXN];
seg val[MAXN];
 
void build(int n){
    if(n==1){
        lef[n]=l;
        rig[n]=r;
    }
    if(rig[n] == lef[n]){
        val[n] = mkseg(v[rig[n]]);
        return;
    }
    int mid = lef[n] + (rig[n]-lef[n])/2;
    //left
    lef[2*n] = lef[n]; 
    rig[2*n] = mid;
    build(2*n);

    //right
    lef[2*n+1] = mid+1;
    rig[2*n+1] = rig[n];   
    build(2*n+1);
    
    val[n] = merge(val[2*n],val[2*n+1]);
}
 
seg query(int n, int left,int right){
    if(lef[n] >= left && rig[n] <= right)
        return val[n];
    if(lef[n] > right || rig[n] < left)
        return mk0();
    return merge(query(2*n,left,right),query(2*n+1,left,right));
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("in","r",stdin);
    freopen("out","w",stdout);
 
    int t;
    cin >> t;
 
    while(t--){
        cin >> r;
        for(int i = 1; i <= r; i++)
            cin >> v[i];
        build(1);
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
            int a,b;
            cin >> a >>b;
            seg resp = query(1,a,b);
            cout << resp.mm.ff << " " << resp.mm.ss << "\n";
        }
    }
 
    return 0;
}