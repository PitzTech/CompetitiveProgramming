#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

int n, resp = 0, passado, cont = 0, temp, maxi, h[MAX];

int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    
    scanf("%d", &n);
    for(int x = 0; x < n; x++){
        scanf("%d", &temp);
        h[temp]++;
        if(x == 0)
            maxi = temp;
        else{
            if(temp < maxi){
                if(temp > passado){
                    for(int x = 1; x < temp; x++){
                        resp += h[x];
                        h[x] = 0;
                    }
                }
            }else{
                for(int x = 1; x < maxi; x++){
                    resp += h[x];
                    h[x] = 0;
                }
                h[maxi]--;
                maxi = temp;
            }
        }
        passado = temp;
    }
    printf("%d", resp);
    return 0;
}