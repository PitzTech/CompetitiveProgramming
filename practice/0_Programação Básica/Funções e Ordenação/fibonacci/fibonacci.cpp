#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n){
    if(n <= 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int n;
    cin >> n;
    cout << fibonacci(n);
}