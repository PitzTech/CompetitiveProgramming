#include <bits/stdc++.h>
using namespace std;

set<int> chamada;
int n, cont = 0;
int main(){

    freopen("in","r", stdin);
    freopen("out","w", stdout);

    scanf("%d",&n);
    for(int x = 0; x < n; x++){
        int atual;
        scanf("%d",&atual);
        if(chamada.find(atual) == chamada.end()){
            cont++;
            chamada.insert(atual);
        }
    }
    printf("%d", cont);
}