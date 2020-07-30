#include <bits/stdc++.h>

#define MAX 1300000
using namespace std;

bool composto[MAX];
long primos[MAX];
long cont = 0;

void crivo(long n){
    composto[1] = 1;
    for(long x = 2; x <= n; x++){
        if(!composto[x]){
            for(long y = 2; y*x <= n; y++)
                composto[x*y] = 1;
            primos[++cont] = x;
        }
    }
}
int buscaBinaria(long n){
    long ini = 1, fim = cont, meio;
    while(ini<=fim){
        meio = (fim+ini)/2;
        if(n == primos[meio]) return meio;
        if(n > primos[meio]) ini = meio+1;
        else fim = meio-1;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    long n;
    cin >> n;
    long nums[n], maxi = 0;

    for(long y = 0; y < n; y++){
        cin >> nums[y];
        maxi = max(nums[y], maxi);
    }
    crivo(maxi);

    for(long x = 0; x < n; x++){
        cout << buscaBinaria(nums[x]) << "\n";
    }

    return 0;
}