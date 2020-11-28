#include <bits/stdc++.h>
using namespace std;

long nel, nop;

long mdc(long a, long b){
    return (b == 0 ? a : mdc(b, a % b));
}

long countsub(long arr[], long ini, long fim){
    long n = fim - ini + 1;
    long count = 0;
    for(long i = ini; i <= fim; i++){
        long nmdc = arr[i];
        for(long j = i; j <= fim; j++){
            //cout << "i = " << i << " j = " << j << "\n";
            nmdc = mdc(nmdc,arr[j]);
            if(nmdc > 1)
                count++;
            else
                break;
            //cout << "count = " << count << "\n";
        } 
    }
   return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> nel >> nop;

    long s[nel + 1];
    for(long i = 1; i <= nel; i++)
        cin >> s[i];

    for(long m = 0; m < nop; m++){
        int t; // 1 ou 2
        long i, v;
        cin >> t >> i >> v;
        if(t == 1)
            s[i] = v;
        else{
            // i = inicio
            // v = fim
            cout << countsub(s, i, v) << "\n";
        }
    }
    return 0;
}