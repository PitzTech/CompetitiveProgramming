#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n,primo = 1;
    cin >> n;
    if(n == 1) primo = 0;
    else{
        for(int x = 2; x*x <= n; x++){
            if(n%2 == 0){
                primo = 0;
                break;
            } 
        }     
    }
    cout << (primo ? "S" : "N");

    return 0;
}