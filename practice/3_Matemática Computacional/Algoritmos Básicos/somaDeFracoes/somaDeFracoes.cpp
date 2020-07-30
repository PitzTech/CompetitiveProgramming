#include <bits/stdc++.h>

using namespace std;

long mdc(long a, long b){
    return (b == 0 ? a : mdc(b,a%b)); 
}
long mmc(long a,long b){
    return a*(b/mdc(a,b));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    long n1,d1,n2,d2;
    cin >> n1 >> d1 >> n2 >> d2;

    long div1 = mdc(n1,d1);
    long div2 = mdc(n2,d2);

    n1 /= div1;
    d1 /= div1;
    n2 /= div2;
    d2 /= div2;
    
    long n, d;
    d = mmc(d1,d2);
    n1 *= d/d1;
    n2 *= d/d2;
    n = n1+n2;

    div1 = mdc(n,d);
    n /= div1;
    d /= div1;
    cout << n << " " << d;
    return 0;
}