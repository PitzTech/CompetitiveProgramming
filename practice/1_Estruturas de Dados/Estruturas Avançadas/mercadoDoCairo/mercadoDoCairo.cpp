#include <bits/stdc++.h>
using namespace std;

/*
A parte mais difícil desse problema é a BIT 2D, se você já sabe implementar a estrutura o problema fica simples. 

Você precisa criar uma BIT que representa o mercado e cada "elemento da matriz" na BIT você terá a maior quantidade de itens que é possível comprar até esse ponto, ou seja, você não terá uma BIT de soma e sim uma BIT de máximo. Você vai processar os vendedores na mesma ordem da entrada (já que eles são apresentados por ordem de idade) e para cada vendedor você realizará as seguintes operações.

1) Consulta: Você irá consultar a BIT e precisa achar o maior valor no quadrado que começa na posição (0,0) e termina na posição (x,y). 
2) Atualização: Você irá atualizar sua BIT com o valor encontrado na consulta + 1. O novo valor em cada celula da matriz será "consulta + 1" ou o valor que já está lá, o que for maior.

Ao final, a consulta do último vendedor lhe da a resposta para o problema.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    

    return 0;
}