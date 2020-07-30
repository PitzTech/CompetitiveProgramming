#include <bits/stdc++.h>
using namespace std;

int alunos, lista,a,b;
vector<int>amigos[1000];

int main(){
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);

    scanf("%d %d",&alunos,&lista);

    for(int x = 0; x < lista;x++){
        scanf("%d %d",&a,&b);
        amigos[a].push_back(b);
        amigos[b].push_back(a);
    }

    int ntimes = 0;
    set<int>times[alunos+1];

    for(int x = 1; x <= alunos;x++){
        //printf("aluno %d\n",x);
        bool encontrou = false;
        for(int y = 1; y <= ntimes; y++){
            if(times[y].find(x) != times[y].end()){
                times[y].insert(x);
                times[y].insert(amigos[x].begin(),amigos[x].end());
                encontrou = true;
            }
            for(int i = 0; i < amigos[x].size(); i++){
                if(times[y].find(i) != times[y].end()){
                    times[y].insert(x);
                    times[y].insert(amigos[x].begin(),amigos[x].end());
                    encontrou = true;
                }
            }
        }
        if(!encontrou){
            times[++ntimes].insert(x);
            times[ntimes].insert(amigos[x].begin(), amigos[x].end());
        }
    }
    
    printf("%d", ntimes);
    
    return 0;
}