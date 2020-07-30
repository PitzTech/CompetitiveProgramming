#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input", "r", stdin);
    freopen("output","w", stdout);
    int n, cont = 0;;
    cin >> n;
    int seq[n], copia[n], err[n];
    for(int x = 0; x < n; x++){
        cin >> seq[x];
        copia[x] = seq[x];
    }
    sort(copia, copia+n);
    for(int x = 0; x < n; x++){
        if(copia[x] != seq[x]){
            err[cont++] = seq[x];
        }
    }
    sort(err, err+cont);
    cout << cont << "\n";
    for(int x = 0; x < cont; x++)
        cout << err[x] << " ";
}