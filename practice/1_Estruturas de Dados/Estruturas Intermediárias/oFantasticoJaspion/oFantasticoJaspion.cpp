#include <bits/stdc++.h>
using namespace std;

int instancias, palavrasDic, linhasMus;
map<string, string> dicionario;

int main(){

    // erro de compilação
    
    freopen("in","r",stdin);
    freopen("out","w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    scanf("%d", &instancias);

    for(int ins = 0; ins < instancias; ins++){
        scanf("%d %d ", &palavrasDic, &linhasMus);
        dicionario.clear();

        for(int palavra = 0; palavra < palavrasDic; palavra++){
            char japones[80];
            char portugues[80];
            gets(japones);
            gets(portugues);
            dicionario[japones] = portugues;
            //printf("%s\n", japones);
            //printf("%s\n", portugues);
        }
        for(int linha = 0; linha < linhasMus; linha++){
            char letraMus[80];
            //printf("%s\n", letraMus);
            while(cin >> letraMus){                
                if(dicionario.find(letraMus) != dicionario.end()){
                    cout << dicionario[letraMus] << " ";
                }else{
                    cout << letraMus << " ";
                }
                if (cin.get() == '\n') break;
            }
            printf("\n");
        }
        if(ins < instancias -1) printf("\n");
    }

    return 0;
}