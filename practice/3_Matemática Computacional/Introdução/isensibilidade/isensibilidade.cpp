#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(NULL);

    freopen("in","r", stdin);
    freopen("out","w",stdout);

    int n;
    scanf("%d", &n);
    
    int ox,oy,ax,ay, nivel = 0, dx, dy; 
    for(int x = 0; x < n; x++){
        scanf("%d %d %d %d", &ox, &oy, &ax, &ay);
        dx = abs(ax-ox);
        dy = abs(ay-oy);
        nivel += pow(dx,2) + pow(dy, 2);
    }

    printf("%d", nivel);
    return 0;
}