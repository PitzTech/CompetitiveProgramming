#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b){
    return (b == 0 ? a : mdc(b,a%b)); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n;
    cin >> n;
    
    int num[n], max = 0;
    for(int x = 0; x<n; x++){
        cin >> num[x];
        if(x > 0){
            num[x] = mdc(num[x-1],num[x]);
        }
    }
    cout << num[n-1];
    return 0;
}