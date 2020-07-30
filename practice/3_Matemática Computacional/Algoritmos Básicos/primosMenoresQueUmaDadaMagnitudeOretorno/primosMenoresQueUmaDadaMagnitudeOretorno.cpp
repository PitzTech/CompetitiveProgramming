#include <bits/stdc++.h>

#define MAX 10000007
using namespace std;

bool composto[MAX];

void crivo(long n){
    composto[1] = 1;
    for(long x = 2; x <= n; ++x){
        if(!composto[x]){
            for(long y = 2; y*x <= n; ++y){
                composto[y*x] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    long n;
    cin >> n;
    
    crivo(n);

    for(long x = 2; x <= n; x++){
        if(!composto[x])
            cout << x << " ";
    }

    return 0;
}