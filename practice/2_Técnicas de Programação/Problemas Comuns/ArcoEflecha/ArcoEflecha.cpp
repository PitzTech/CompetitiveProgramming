#include <bits/stdc++.h>
#define INF INT_MAX
#define pb push_back
using namespace std;

int mergeSort(vector<long>&v){
    if(v.size() == 1) return 0;

    int inter = 0;
    vector<long> u1,u2;
    for(int i = 0; i < v.size()/2;i++)
        u1.pb(v[i]);
    for(int i = v.size()/2; i < v.size(); i++)
        u2.pb(v[i]);

    inter += mergeSort(u1);
    inter += mergeSort(u2);

    int ini1 = 0, ini2 = 0;
    for(int i = 0; i < v.size(); i++){
        if(u1[ini1] <= u2[ini2]){
            v[i] = u1[ini1++];
            inter += u2.size() - ini2 - 1;
        }else
            v[i] = u2[ini2++];
    }

    return inter;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long> v(n);
    for(long &el : v){
        int x, y;
        cin >> x >> y;
        el = x*x + y*y;
    }
    
    cout << mergeSort(v);

    return 0;
}