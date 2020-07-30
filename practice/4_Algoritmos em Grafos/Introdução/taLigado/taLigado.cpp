#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    

    int n, m;
    cin >> n >> m;

    vector<int>pontes[n+1];

    int q, a,b;
    for(int x = 0; x < m; x++){
        cin >> q >> a >> b;
        if(q == 0){ // pergunta
            if(find(pontes[a].begin(), pontes[a].end(), b) != pontes[a].end()
            || find(pontes[b].begin(), pontes[b].end(), a) != pontes[b].end())
                printf("1\n");
            else
                printf("0\n");
        }else{
            pontes[a].push_back(b);
            pontes[b].push_back(a);
        }
    }

    return 0;
}
