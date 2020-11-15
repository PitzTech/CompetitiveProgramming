#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MAXN 10004
using namespace std;
using pll = pair<long,long>;

long n, k, c;
long fita[MAXN];
pll grupos[MAXN];
long soma = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> c;

    for(int i = 0; i < n; i++){
        cin >> fita[i];
        soma += fita[i];
        grupos[i].ss = i;
        if(i < n-4){
            grupos[i].ff = fita[i];
        }
        for(int j = 1; j <= c-1; j++){
            grupos[i-j].ff += fita[i];
        }
    }

    sort(grupos, grupos + n-c+1);

    long cont = k;
    for(pll el : grupos){
        bool quebrou = false;
        if(!cont) break;

        for(int i = 0; i < c; i++){
            if(fita[el.ss + i] == LLONG_MAX){
                quebrou = true;
                break;
            }  
        }      
        if(quebrou) continue;   
        for(int i = 0; i < c; i++)
            fita[el.ss + i] = LLONG_MAX;
        soma -= el.ff;
        //cout << (el.ss+1) << endl;
        //cout << "cont = " << cont << endl;
        cont--;      
    }

    cout << soma;

    return 0;
}