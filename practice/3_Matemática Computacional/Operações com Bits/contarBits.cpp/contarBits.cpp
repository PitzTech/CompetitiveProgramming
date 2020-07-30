#include <bits/stdc++.h>
using namespace std;

int countBits(long long n){
    int cont = 0;

    while(n){   
        cont += n&1;
        n = n >> 1;
    }
    return cont;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    long long n;
    cin >> n;

    cout << countBits(n);

    return 0;
}