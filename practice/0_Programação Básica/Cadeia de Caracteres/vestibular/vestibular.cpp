#include <bits/stdc++.h>
using namespace std;
int main(){
    
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int car, pt = 0;
    string res, gab;
    cin >> car >> res >> gab;
    for(int x = 0; x < car; x++)
        if(res[x] == gab[x]) pt++;
    cout << pt;
}