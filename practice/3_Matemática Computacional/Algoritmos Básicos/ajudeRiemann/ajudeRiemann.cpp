#include <bits/stdc++.h>

#define MAX 12000000
using namespace std;

bool composto[MAX];

void crivo(long n){
    composto[1] = 1;
    for(long x = 2; x <= n; ++x){
        if(!composto[x]){
            for(long y = 2; x*y <= n; ++y){
                composto[x*y] = 1;
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

    crivo(MAX);

    long primo = 0;

    for(int x = 0; primo <= n; x++){
        if(!composto[x]){
            primo++;
            if(primo-1 == n)
                cout << x;
        }
    }

    return 0;
}