#include <bits/stdc++.h>

#define MAX 1000005
using namespace std;

bool composto[MAX];

void crivo(int n){
    composto[1] = 1;
    for(int x = 2;x<=n;x++){
        if(!composto[x]){
            for(int y = 2; y*x <=n;y++){
                composto[y*x] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    crivo(x);

    if(x == 1 || composto[x]){
        printf("N");
        return 0;
    }
    printf("S");
    
}