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
        bool trocou = false;
        int parou = 1;
        while(!trocou){
            trocou = true;
            for(int x=parou;x<n;x++){
                if(v[x] > v[x+1]){
                    int temp = v[x];
                    v[x] = v[x+1];
                    v[x+1] = temp;
                    ac = 1 - ac;
                    trocou = false;
                }else if(x == parou && v[x] == x){
                    parou++;
                }
            }
        }
        
        // for(int x=1; x<=n;x++){
        //     printf("%d ", v[x]);
        // }
        printf(ac==0 ? "Marcelo\n" : "Carlos\n");
    }
 
    return 0;
}