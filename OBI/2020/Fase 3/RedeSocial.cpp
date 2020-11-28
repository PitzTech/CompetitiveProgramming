#include <bits/stdc++.h>
using namespace std;

long n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    long msg[n];

    for(long i = 0; i < n; i++)
        cin >> msg[i];

    sort(msg, msg+n, greater<long>());

    long cont = 0;

    for(long i = 0; i < n; i++){
        if(msg[i] >= cont + 1)
            cont++;
        else 
            break;
    }  
    cout << cont;

    return 0;
}