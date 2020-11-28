#include <bits/stdc++.h>
using namespace std;

long a,b;
long lado1, lado2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    lado1 = ((a - 4) / 4);
    //lado2 = ((a - 4) % 4);
    //lado2 = ((a - 4) - lado1) / 2;
    lado2 = lado1 + ((a - 4) % 4) / 2;
    
    if(b != lado1 * lado2){
        cout << "-1 -1";
        return 0;
    }

    lado1 += 2;
    lado2 += 2;
    cout << lado1 << " " << lado2;

    return 0;
}