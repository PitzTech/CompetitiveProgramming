#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

bool ePrimo(int n){
    if(n == 1) return false;
    for(int x = 2; x*x <= n; x++)
        if(n % x==0) return false;
    return true;
}
/*
bool ePrimo(int n){
    if(n == 1) return false;
    for(int x = 2; x < floor(sqrt(n))+1; x++)
        if(n % x==0) return false;
    return true;
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int n;
    cin >> n;
    for(int x = 2; x <= n; x++){
        if(ePrimo(x))
            cout << x << " ";
    }
    return 0;
}