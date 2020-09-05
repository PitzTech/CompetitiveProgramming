#include <bits/stdc++.h>
using namespace std;

long mina,minb;
long findmin(long a,long b, long n, long mini){
    mini = min(a * b, mini);
    if(n > 0){
        if(mina > 0 && a > mina)
            mini = min(findmin(a-1,b,n-1,mini), mini);
        if(minb > 0 && b > minb)
            mini = min(findmin(a,b-1,n-1,mini), mini);
    }
    return mini;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    long n,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b >> mina >> minb >> n;
        cout << findmin(a, b, n, a*b) << "\n"; 
    }

    return 0;
}