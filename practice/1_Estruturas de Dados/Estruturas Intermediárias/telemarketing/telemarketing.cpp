#include <bits/stdc++.h>

#define MAXV 1000006

using namespace std;
using ii = pair<int,int>;

int nV, nL, tempo, nlVendedor[MAXV];
priority_queue <ii, vector<ii>, greater<ii>> vendedores;
ii vendedor;

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d %d", &nV, &nL);

    for(int x = 1; x <= nV; x++) vendedores.push(make_pair(0, x));

    for(int x = 0; x < nL; x++){
        scanf("%d", &tempo);
        vendedor = vendedores.top();
        vendedores.pop();
        nlVendedor[vendedor.second]++;
        vendedores.push(make_pair(vendedor.first + tempo, vendedor.second));
    }
    for(int x = 1; x <= nV; x++){
        printf("%d %d\n", x, nlVendedor[x]);
    }
    return 0;

}