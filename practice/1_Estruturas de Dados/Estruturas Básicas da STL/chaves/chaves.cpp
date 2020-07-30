#include <bits/stdc++.h>
using namespace std;

stack<char> pilha;
int linhas;
string linha;
bool ok = true;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d", &linhas);
    //int cont = 0;
    while(cin >> linha){
        //cont++;
        //printf("linha %d\n", cont);
        for(int y = 0; y < (int)linha.size(); y++){
            if(linha[y] == '{') pilha.push('{');
            if(linha[y] == '}'){
                if(!pilha.empty()) pilha.pop();
                else{
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) break;
    }

    if(ok && pilha.empty()) printf("S");
    else printf("N");
    return 0;
}