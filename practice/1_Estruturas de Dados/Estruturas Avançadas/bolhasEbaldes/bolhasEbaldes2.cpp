#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int v[MAX], n;

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);
    
    while(scanf("%d", &n) && n > 0){
        for(int x=1;x<=n;x++) scanf("%d",&v[x]);
        
        int ac = 1;
        for(int x=1;x<n;x++){
            while(v[x] != x){
                int temp = v[x];
                int posi = v[x];
                v[x] = v[posi];
                v[posi] = temp;
                ac = 1 - ac;
            }
        }
        
        // for(int x=1; x<=n;x++){
        //     printf("%d ", v[x]);
        // }
        printf(ac==0 ? "Marcelo\n" : "Carlos\n");
    }
 
    return 0;
}