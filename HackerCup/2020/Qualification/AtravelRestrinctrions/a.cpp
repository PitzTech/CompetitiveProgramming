//#include <bits/stdc++.h>
#include <iostream>

#define endl "\n"
using namespace std;

int airlines, countries;
char in[50], out[50];

bool possible(int a, int b){
    if(a != b){
        if(a < b){
            if(out[a] == 'Y' && in[a+1] == 'Y')
                return possible(a+1, b);
            return false;
        }else{
            if(out[a] == 'Y' && in[a-1] == 'Y')
                return possible(a-1, b);
            return false;
        }
    }
    return true;
}

int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> airlines;

    for(int x = 1; x <= airlines; x++){
        cin >> countries;
        for(int y = 0; y < countries; y++)
            cin >> in[y];
        for(int y = 0; y < countries; y++)
            cin >> out[y];

        cout << "Case #" << x << ":" endl;
        for(int y = 0; y < countries; y++){
            for(int z = 0; z < countries; z++)
                if(possible(y, z)) cout << "Y";
                else cout << "N";
            cout << endl;
        }
    }

    return 0;
}