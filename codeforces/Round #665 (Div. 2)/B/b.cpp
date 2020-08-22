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

        int old = a0;
        a0 = max(a0 - b2,(long)0);
        b2 = max(b2 - old,(long)0);

        if(a0){ 
            old = a0;
            a0 = max(a0 - b0,(long)0);
            b0 = max(b0 - old,(long) 0);
            if(a0){
                old = a0;
                a0 = max(a0 - b1, (long) 0);
                b1 = max(b1 - old, (long) 0); 
            }
        }
        if(b0){
            old = b0;
            b0 = max(b0 - a1, (long) 0);
            a1 = max(a1 - old, (long) 0);
            if(b0){
                old = b0;
                b0 = max(b0 - a2, (long) 0);
                a2 = max(a2 - old, (long) 0); 
            }
        }
        if(a1){
            old = a1;
            a1 = max(a1 - b1, (long) 0); 
            b1 = max(b1 - old, (long) 0); 
            if(a1){
                old = a1;
                soma -= a1*2;
                a1 = max(a1 - b2, (long) 0);
                b2 = max(b2 - old, (long) 0);
            }
        }
        if(b1){
            old = b1;
            soma += b1*2;
            b1 = max(b1 - a2, (long) 0);
            a2 = max(a2 - old, (long) 0);
        }
        
        cout << soma << "\n";
    }
    return 0;
}