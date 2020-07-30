#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int n[10] = {0,0,0,0,0,0,0,0,0,0}, numInt;
    string numInp;
    cin >> numInt;
    for(int x = 0; x < numInt; x++){
        cin >> numInp;
        for(int y = 0; y < numInp.size(); y++){
            switch((int)numInp[y]){
                case '0': n[0]++;
                    break;
                case '1': n[1]++;
                    break;
                case '2': n[2]++;
                    break;
                case '3': n[3]++;
                    break;
                case '4': n[4]++;
                    break;
                case '5': n[5]++;
                    break;
                case '6': n[6]++;
                    break;
                case '7': n[7]++;
                    break;
                case '8': n[8]++;
                    break;
                case '9': n[9]++;
                    break;
            }
        }
    }
    for(int x = 0; x <= 9; x++)
        printf("%d - %d\n", x, n[x]);
}