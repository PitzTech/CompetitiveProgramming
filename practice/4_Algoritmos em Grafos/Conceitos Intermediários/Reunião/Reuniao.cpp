#include <bits/stdc++.h>

#define MAXC 101
#define INF 0x3f3f3f3f
using namespace std;

int m[MAXC][MAXC];
int main(){

    int N, M;
    cin >> N >> M;
    
    memset(m, 0x3f, sizeof(m));

    for(int i = 0; i < M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(m[a][b] > 100 || m[a][b] > c)
            m[a][b] = m[b][a] = c;
    }
    for(int i = 0; i < N; i++)
        m[i][i] = 0;

    //FLoyd-Warshall
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
  
    int menor = INF;
    for(int i = 0; i < N; i++){
        int maior = -1;
        for(int j = 0; j < N; j++)
            maior = max(maior, m[j][i]);
        if(maior < menor)
            menor = maior;
    }
    cout << menor;
    return 0;
}