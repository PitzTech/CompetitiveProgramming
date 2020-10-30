#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using vi = vector<int>;

int nsalas, ntuneis, inicio;
int h[210];
int maxi = 0;
vi tree[210];

int pega(int n, int sala){
    if(maxi == ntuneis) return n;
    if(tree[sala].empty()) return n;
    for(int el : tree[sala]){
        if(h[sala] > h[el]){
            //cout << "entrou " << el << endl;
            int temp = pega(n+1, el);
            if(temp > maxi) maxi = temp;
        }
    }
    return n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> nsalas >> ntuneis >> inicio;
    
    for(int i = 1; i <= nsalas; i++)
        cin >> h[i];
    for(int i = 0; i < ntuneis; i++){
        int a,b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    pega(0, inicio);
    
    cout << maxi;
    return 0;
}