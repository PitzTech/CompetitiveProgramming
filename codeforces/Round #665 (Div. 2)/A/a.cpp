#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    int a, distance, ans;
    for(int i = 0; i < t; i++){
        cin >> a >> distance;
        if(distance == 0){ 
            if(a % 2 == 0) ans = 0;
            else ans = 1;
        }else if(distance > a){
            ans = distance - a;
        }else{
            if(distance % 2 != a % 2){
                ans = 1;
            }else{
                ans = 0;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}