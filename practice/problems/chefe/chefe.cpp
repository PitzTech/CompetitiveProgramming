#include <bits/stdc++.h>

#define ff first
#define ss second
#define MAXP 501
#define MAXAGE 101

using namespace std;

int nEmp, nRelGerDir, nIns, idades[MAXP], trocas[MAXP];
vector<int> empChefes[MAXP];

int buscaChefe(int emp, int idade){
    //printf("emp: %d | menorIdade: %d\n", emp, idade);
    int menoridade = idade, posi;
    for(int x = 1; x <= nEmp; x++) 
        if(trocas[x] == emp) posi = x;

    if(empChefes[posi].size() == 0) return menoridade;
    for(int x = 0; x < empChefes[posi].size(); x++){
        int idadeChefe = idades[trocas[empChefes[posi][x]]];
        if(idadeChefe < menoridade) menoridade = idadeChefe;

        int atuIdade = buscaChefe(trocas[empChefes[posi][x]],menoridade);
        if(atuIdade < menoridade) menoridade = atuIdade;
    }     
    return menoridade;
}

int main(){
    // freopen("in", "r",stdin);
    // freopen("out", "w", stdout);

    scanf("%d %d %d", &nEmp, &nRelGerDir, &nIns);

    for(int e = 1; e <= nEmp; e++){
        scanf("%d", &idades[e]);
        trocas[e] = e;
    }
    for(int r = 1; r <= nRelGerDir; r++){
        int chefe, empregado;
        scanf("%d %d", &chefe, &empregado);
        empChefes[empregado].push_back(chefe);
    }
    
    for(int i = 0; i < nIns; i++){
        char tipo;
        scanf(" %c", &tipo);
        if(tipo == 'P'){//trade
            int emp;
            scanf("%d", &emp);            
            int maisnovo = buscaChefe(emp,MAXAGE); 
            if(maisnovo == MAXAGE) printf("*\n");
            else printf("%d\n", maisnovo);
        }else{//quest
            int p, s;
            scanf("%d %d", &p,&s);
            for(int x = 1; x <= nEmp; x++){
                if(trocas[x] == p) trocas[x] = s;
                else if(trocas[x] == s) trocas[x] = p;
            }
        }
    }
    return 0;
}