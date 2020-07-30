#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    string n;
    cin >> n;
    int c1 = 0,c2 = 0;
    for(int x = 0; x < n.size(); x++){
        if(x % 2 == 0) c1 += n[x]-'0';
        else c2 += n[x]-'0';
    }
    if(c1 == c2) printf("S");
    else printf("N");

    return 0;
}