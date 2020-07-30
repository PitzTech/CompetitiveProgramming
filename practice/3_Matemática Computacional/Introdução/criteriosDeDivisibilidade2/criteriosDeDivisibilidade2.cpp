#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    string n, dig;
    cin >> n;
    if(n.size() >= 2){
        dig += n[n.size()-2];
        dig += n.back();

        if(stoi(dig) % 4 == 0)
            printf("S\n");
        else printf("N\n");
    }else{
        if(stoi(n) % 4 == 0)
            printf("S\n");
        else printf("N\n");
    }

    int cont = 0;
    for(int x = 0; x < n.size(); x++)
        cont += n[x]-'0';
    if(cont % 9 == 0)
        printf("S\n");
    else printf("N\n");
    if(n.size() >= 2){
        if(stoi(dig) % 25 == 0)
            printf("S\n");
        else printf("N\n");
    }else if(n == "0") printf("S\n");
    else printf("N\n");
    return 0;
}