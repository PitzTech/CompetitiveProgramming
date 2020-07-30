#include <bits/stdc++.h>
using namespace std;

bool visitado[1003];
vector<int>amigos[1003];

void dfs(int x){
    visitado[x] = true;
    for(int alu : amigos[x]){
        if(visitado[alu]) continue;
        dfs(alu);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int alunos, lista;
    scanf("%d %d",&alunos,&lista);

    int a,b;
    for(int x = 0; x < lista;x++){
        scanf("%d %d",&a,&b);
        amigos[a].push_back(b);
        amigos[b].push_back(a);
    }
    
    int res = 0;
    for(int x = 1;x <= alunos; x++){
        if(!visitado[x]){
            res++;
            dfs(x);
        }
    }

    printf("%d", res);
    
    return 0;
}