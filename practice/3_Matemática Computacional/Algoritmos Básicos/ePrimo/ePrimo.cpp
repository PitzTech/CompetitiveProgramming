#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    long n,primo = 1;
    cin >> n;
    if(n == 1) primo = 0;
    else{
        for(int x = 2; x <= floor(sqrt(n)); x++){
            if(n%x == 0){
                primo = 0;
                break;
            } 
        }     
    }
    cout << (primo ? "S" : "N");

    return 0;
}