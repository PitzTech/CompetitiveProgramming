#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

void buildTree(int arvore[], int arr[], int atual, int ini, int fim){
    if(ini == fim) arvore[atual] = arr[ini];
    else{
        int meio = (ini + fim)/2;
        //build left
        buildTree(arvore, arr, atual*2, ini, meio);
        //build right
        buildTree(arvore,arr, atual*2+1, meio+1, fim);
        //actual node
        arvore[atual] = arvore[atual*2] + arvore[atual*2+1];
    }
}
int checkTree(int arvore[], int atual, int ini, int fim, int a, int b){
    //printf("ini: %d, fim: %d, atual: %d \n", ini,fim,atual);
    if(ini > fim) return 0;
    if(a == ini && b == fim) return arvore[atual];
    if(fim == ini) return 0;

    int meio = (ini+fim)/2;
    int soma = 0;

    if(a <= meio) 
        soma += checkTree(arvore, atual*2, ini, meio, a, min(meio, b));
    if(b >= meio+1)
        soma += checkTree(arvore, atual*2+1, meio+1, fim, max(a, meio+1), b);
    return soma;
}

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int instancia, ncontas, nconsultas, ini, fim;
    pair<int,int> resul;
    pair<int,int> maior;
    scanf("%d", &instancia);
    for(int x = 0; x < instancia; x++){
        scanf("%d", &ncontas);
        int contas[ncontas], arvore[ncontas*4];
        for(int x = 0; x < ncontas; x++)
            scanf("%d", &contas[x]);
        
        buildTree(arvore, contas, 1, 0, ncontas-1);

        scanf("%d", &nconsultas);
        for(int x = 0; x < nconsultas; x++){
            scanf("%d %d", &ini, &fim);
            maior.ff = INT_MIN;
            maior.ss = 0;
            for(int x = ini; x <= fim; x++){
                for(int y = x; y <= fim; y++){
                    resul.ff = checkTree(arvore,1,0,ncontas-1,x-1,y-1);
                    //printf("%d\n", resul.ff);
                    resul.ss = y-x+1;
                    if(resul.ff > maior.ff || (resul.ff == maior.ff && resul.ss > maior.ss))
                         maior = resul;
                }
            }
            printf("%d %d\n", maior.ff, maior.ss);
        }
    }
    return 0;
}