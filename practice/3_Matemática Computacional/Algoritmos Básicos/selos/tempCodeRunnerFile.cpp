#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n;
    cin >> n;
    if(n > 3){
        for(int x = 2; x*x <= n; x++){
            if(n % x == 0){
                cout << "S";
                return 0;
            } 
        }
    }
    cout << "N";
    return 0;
}