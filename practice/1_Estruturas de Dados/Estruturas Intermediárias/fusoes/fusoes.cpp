#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n, nOP, donos[MAXN], distancia[MAXN], qtd[MAXN];

int find(int x){
    if(donos[x] == x) return x;
    return donos[x] = find(donos[x]);
}
void joint(int b1, int b2){
    b1 = find(b1);
    b2 = find(b2);
    if(b1 != b2){
        if(distancia[b1] < distancia[b2]){
            donos[b1] = b2;
            qtd[b2] += b1;
        }
        if(distancia[b1] > distancia[b2]){
            donos[b2] = b1;
            qtd[b1] += b2;
        }
        if(distancia[b1] == distancia[b2]){
            donos[b1] = b2;
            distancia[b2]++;
            qtd[b2] += b1;
        }   
    }
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w", stdout);

    scanf("%d %d", &n, &nOP);

    for(int x = 1; x <= n; x++){
        donos[x] = x;
        qtd[x] = 1;
    } 

    char temp;
    int b1, b2;
    for(int x = 0; x < nOP; x++){
        scanf(" %c %d %d", &temp, &b1, &b2);
        if(temp == 'F'){
            //printf("joint\n");
            joint(b1,b2);
        }else{
            //printf("ask\n");
            if(find(b1) == find(b2)) printf("S\n");
            else printf("N\n");
        }
    }

    return 0;
}