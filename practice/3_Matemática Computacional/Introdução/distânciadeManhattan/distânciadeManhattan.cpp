#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int cx,cy,tx,ty;   
    scanf("%d %d %d %d", &cx,&cy,&tx,&ty);

    printf("%d", abs(tx-cx) + abs(ty-cy));

    return 0;
}