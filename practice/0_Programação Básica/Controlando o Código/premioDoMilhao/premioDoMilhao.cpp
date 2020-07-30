#include <bits/stdc++.h>
using namespace std;

int n, valor, cont, total = 1000000;
int main(){
    scanf("%d", &n);
    for(int x = 0; x < n; x++){
        if(total > 0){
            scanf("%d", &valor);
            total -= valor; 
            cont++;
        }
    }
    printf("%d",cont);
    return 0;
}