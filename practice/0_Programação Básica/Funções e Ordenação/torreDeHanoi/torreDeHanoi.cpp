#include <bits/stdc++.h>
using namespace std;

int hanoi(int n){
    int resul;
    if(n == 1) resul = 1;
    else resul = hanoi(n-1) + pow(2, n-1);
    return resul;
}

int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int n, teste = 0;
    while(true){
        cin >> n;
        if(n == 0) break;
        teste++;
        printf("Teste %d \n", teste);
        cout << hanoi(n) << "\n";
    }
}