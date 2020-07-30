#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int n, h[MAX], resul, prefix[MAX], suffix[MAX];

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d", &n);
    for(int x = 1; x <= n; x++)
        scanf("%d", &h[x]);

    for(int x = 1; x <= n; x++)
        prefix[x] = max(prefix[x-1], h[x]);
    for(int x = n; x >= 1; x--)
        suffix[x] = max(suffix[x+1], h[x]);
    
    for(int x = 1; x <= n; x++)
        if(h[x] < min(prefix[x-1], suffix[x+1]))
            resul++;
    
    printf("%d", resul);
    return 0;
}