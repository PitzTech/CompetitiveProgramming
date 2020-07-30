//https://neps.academy/problem/859
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n, el = 0, will = 0;
    cin >> n;
    for(int x = 0; x < n; x++){
        int nel, nwill;
        cin >> nwill >> nel;
        if(max(nwill, nel) == min(nwill, nel) + 1 || max(nwill, nel) == min(nwill, nel) + 2){
            if(nwill < nel) will++;
            else el++;
        }else{
            if(nwill > nel) will++;
            else el++;
        }
    }
    
    if(el > will) cout << "11";
    else cout << "will";

    return 0;
}