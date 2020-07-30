#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    long n;
    cin >> n;
    if(n > 3){
        for(int x = 2; x < floor(sqrt(n))+1; x++){
            if(n % x == 0){
                printf("S");
                return 0;
            } 
        }
    }
    printf("N");
    return 0;
}