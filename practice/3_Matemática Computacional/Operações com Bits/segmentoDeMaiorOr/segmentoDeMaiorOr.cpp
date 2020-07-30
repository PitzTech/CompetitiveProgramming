#include <bits/stdc++.h>
using namespace std;

class SegTree{
private:
    int n;
    vector<int>tree;
    vector<int>v;
    int maxi = 0;

    void build(int node, int i, int j){
        if(i == j){
            tree[node] = v[i];
            maxi = max(v[i], maxi);
            return;
        }
        int m = (i+j)/2;
        int l = (node << 1);
        int r = l+1;
        build(l, i, m);
        build(r, m+1, j);
        tree[node] = tree[l]|tree[r];
        maxi = max(maxi, tree[node]);
    }
    int query(int node, int i, int j, int a, int b){
        if(i>b || j < a)
            return 0;
        if(a <= i && j <= b)
            return tree[node];
        int m = (i+j)/2;
        int l = (node << 1);
        int r = l+1;
        return query(l, i, m, a,b) + query(r, m+1, j, a,b);
    }
public:
    template <class MyType>
    SegTree(MyType begin, MyType end){
        n = end - begin;
        v = vector<int>(begin,end);
        tree.resize(4*n+5);
        build(1,0,n-1);
    }
    int query(int a, int b){
        return query(1,0,n-1,a,b);
    }
    int getMaxi(){
        return maxi;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n;
    cin >> n;
  
    vector<int> nums(n);
    for(int x = 0;x < n; x++)
        cin >> nums[x];

    SegTree tree(nums.begin(),nums.end());

    cout << tree.getMaxi();

    return 0;
}