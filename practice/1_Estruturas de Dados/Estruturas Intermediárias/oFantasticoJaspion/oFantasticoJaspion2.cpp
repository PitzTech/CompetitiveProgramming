#include <bits/stdc++.h>
using namespace std;

int instancias, palavrasDic, linhasMus;
map<string, string> dicionario;

int main(){
    freopen("in","r",stdin);
    freopen("out","w", stdout);

    scanf("%d", &instancias);

    for(int ins = 0; ins < instancias; ins++){
        dicionario.clear();
        scanf("%d %d ", &palavrasDic, &linhasMus);

        for(int palavra = 0; palavra < palavrasDic; palavra++){
            string japones, portugues;
            getline(cin,japones);
            getline(cin,portugues);
            dicionario[japones] = portugues;
            //cout << japones << "\n";
            //cout << portugues << "\n";
        }
        for(int linha = 0; linha < linhasMus; linha++){
            string letraMus;
            getline(cin, letraMus);
            stringstream ss(letraMus);
            while(ss){
                string temp;
                ss >> temp;
               
                if(dicionario.find(temp) != dicionario.end()){
                    cout << dicionario[temp] << " ";
                }else{
                    cout << temp << " ";
                }
            }
            printf("\n");
        }
        if(ins < instancias -1) printf("\n");
    }

    return 0;
}