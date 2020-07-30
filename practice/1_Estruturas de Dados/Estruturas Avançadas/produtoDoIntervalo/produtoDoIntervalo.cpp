#include <bits/stdc++.h>

using namespace std;

int n, nCmd, temp;
set<int> neg, posi, nulos;
string saida = "";

void chang(int n1, int n2){ //n1 posi | n2 valor
    bool entrou = false;
    if(n2 >= 0 && neg.find(n1) != neg.end()){
        neg.erase(n1);
        entrou = true;
    } 
    else if(n2 <= 0 && posi.find(n1) != posi.end()){
        posi.erase(n1);
        entrou = true;
    }else if(n2 != 0){
        nulos.erase(n1);
        entrou = true;
    } 
    if(entrou){
        if(n2 > 0) posi.insert(n1);
        else if(n2 < 0) neg.insert(n1);
        else nulos.insert(n1);
    }

}
void prod(int n1, int n2){
    bool sinal = true; // posi
    for(int x = n1; x <= n2; x++){
        if(nulos.find(x) != nulos.end()){
            saida += "0";
            return;
        }else if(neg.find(x) != neg.end()){
            sinal = !sinal;
        }
    }
    saida += sinal ? "+" : "-";
}

int main(){
    
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    while(scanf("%d %d", &n, &nCmd) == 2){
        saida = "";
        neg.clear(); 
        posi.clear();
        nulos.clear();
        for(int x = 1; x <= n; x++){
            scanf("%d", &temp);
            if(temp == 0) nulos.insert(x);
            else if(temp > 0) posi.insert(x);
            else neg.insert(x);
        }
        char cmd;
        int n1, n2;
        for(int x = 0; x < nCmd; x++){
            scanf(" %c %d %d", &cmd, &n1, &n2);
            if(cmd == 'C') // change
                chang(n1, n2);
            else // product
                prod(n1, n2);
        }
        printf("%s\n", saida.c_str());
    }
    return 0;
}