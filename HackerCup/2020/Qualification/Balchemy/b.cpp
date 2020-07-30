//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    //freopen("in","r",stdin);
    //freopen("out","w",stdout);

    int n, shards, soma;
    bool find = true;
    cin >> n;

    for(int x = 1; x <= n; x++){
        cin >> shards;
        vector<char> colors(shards);

        for(int y = 0; y < shards; y++)
            cin >> colors[y];

        do{  
            find = false;
            for(int z = shards - 2; z > 0; z--){
                soma = colors[z-1] + colors[z] + colors[z+1];
                if(soma %'A' != 0 && soma % 'B' != 0){
                    if(colors[z-1] != colors[z] && colors[z] == colors[z+1])
                            colors[z-1] = colors[z];
                    colors.erase(colors.begin() + z, colors.begin() + z + 1);
                    shards -= 2;
                    find = true;
                    break;
                }
            }
        }while(shards > 1 && find);

        cout << "Case #" << x << ": ";
        if(shards == 1) cout << "Y";
        else  cout << "N";
        cout << endl;
    }
    return 0;
}