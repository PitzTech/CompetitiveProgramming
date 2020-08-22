#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    long a0,a1,a2;
    long b0,b1,b2;
    for(int i = 0; i < t; i++){
        long long soma = 0;

        cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;

        a0 = max(a0 - b0,(long)0);
        b0 = max(b0 - a0, (long) 0);

        if(a0 > 0){
            a0 = max(a0 - b2, (long) 0);
            b2 = max(b2 - a0, (long) 0);
            if(a0 > 0){
                a0 = max(a0 - b1, (long) 0);
                b1 = max(b1 - a0, (long) 0);   
            }
        }
        if(b0 > 0){
            b0 = max(b0 - a1, (long) 0);
            a1 = max(a1 - b0, (long) 0);
            if(b0 > 0){
                b0 = max(b0 - a2, (long) 0);
                a2 = max(a2 - b0, (long) 0); 
            }
        }
        if(a1 > 0){
            a1 = max(a1 - b1, (long) 0); 
            b1 = max(b1 - a1, (long) 0); 
            if(a1 > 0){
                soma -= a1*2;
                a1 = max(a1 - b2, (long) 0);
                b2 = max(b2 - a1, (long) 0);
            }
        }
        if(b1 > 0){
            soma += b1*2;
            b1 = max(b1 - a2, (long) 0);
            a2 = max(a2 - b1, (long) 0);
        }
        
        cout << soma << "\n";
    }
    return 0;
}