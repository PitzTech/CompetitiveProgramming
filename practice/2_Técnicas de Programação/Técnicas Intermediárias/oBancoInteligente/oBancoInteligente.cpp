#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;
using ii = pair<int,int>;

const int MAX = 5001;
const int N = 6;

ii nota[N];
int dp[MAX], n; 

int main(){

    freopen("in", "r",stdin);
    freopen("out", "w",stdout);

    nota[0].ff = 2;
    nota[1].ff = 5;
    nota[2].ff = 10;
    nota[3].ff = 20;
    nota[4].ff = 50;
    nota[5].ff = 100;
    
    scanf("%d", &n);
    for(int x = 0; x < 6; x++) scanf("%d", &nota[x].ss);
    
    dp[0] = 1;
    for(int nNota = N-1; nNota >= 0; nNota--){
        for(int vFinal = n; vFinal >= 0; vFinal--){
            for(int qNotas = 1; qNotas <= nota[nNota].ss && vFinal - qNotas*nota[nNota].ff >= 0; ++qNotas){
                dp[vFinal] += dp[vFinal - qNotas*nota[nNota].ff]; 
            }
        }
    }
    printf("%d", dp[n]);
    return 0;
}