#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    string n;
    cin >> n;
    if(n.back() % 2 == 0)
        printf("S\n");
    else printf("N\n");
    
    int cont = 0;
    for(int x = 0; x < n.size(); x++)
        cont += n[x] - '0';
        
    if(cont % 3 == 0)
        printf("S\n");
    else printf("N\n");

    if(n.back() == '0' || n.back() == '5')
        printf("S\n");
    else printf("N\n");
    return 0;
}