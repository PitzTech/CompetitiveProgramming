#include <bits/stdc++.h>
using namespace std;

string expre;
int qnt;

int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);

    scanf("%d", &qnt);
    for(int y = 0; y < qnt; y++){
        bool ok = true;
        stack<char> pilha;
        cin >> expre;
        if((int)expre.size() % 2 == 0){
            for(int x = 0; x < (int)expre.size(); x++){
                if(expre[x] == '{' || expre[x] == '[' || expre[x] == '(')
                    pilha.push(expre[x]);
                else if(!pilha.empty()){
                    if(expre[x] == '}' && pilha.top() == '{'){
                        // printf("entrou 1\n");
                        pilha.pop();
                    }else if(expre[x] == ')' && pilha.top() == '('){
                        //printf("entrou 2\n");
                        pilha.pop();
                    }else if(expre[x] == ']' && pilha.top() == '['){
                        //printf("entrou 3\n");
                        pilha.pop();
                    }else{
                        ok = false;
                        break;
                    }
                }else{
                    ok = false;
                    break;
                }
            }
            if(ok) printf("S\n");
            else printf("N\n");
        }else printf("N\n");
    }
    return 0;
}