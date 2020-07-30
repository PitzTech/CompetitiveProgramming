#include <iostream>
#include <algorithm>

#define ff first
#define ss second
using namespace std;
using ii = pair<int,int>;

int n, trees, maxi, temp, fim ;
ii p[800000];

int getSize(int n, int fim){
    int tam = p[n].ss;
    int soma = 0;
    for(int x = n+1; x < trees; x++){
        if(p[x].ff - p[x].ss > fim) break;
        if(p[x].ff == fim){
            soma = max(getSize(x, fim + p[x].ss), soma);  
        }else if(p[x].ff - p[x].ss == fim){
            soma = max(getSize(x, p[x].ff), soma);
        }
    }
    return tam + soma;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> n;
    for(int x = 1; x <= n ; x++){
        cin >> trees;
        maxi = 0;
        
        for(int y = 0; y < trees; y++)
            cin >> p[y].ff >> p[y].ss;

        sort(p, p+trees);

        for(int y = 0; y < trees; y++){
            int tam = p[y].ss;
            int fimr = p[y].ss + p[y].ff;
            int fiml = p[y].ff;

            int fim, esc, soma = 0;
            for(int z = y+1; z < trees; z++){
                if(p[z].ff - p[z].ss > fimr) break;
                if(p[z].ff == fimr || p[z].ff == fiml){
                    soma = max(getSize(z, fimr + p[z].ss), soma);
                }else if(p[z].ff - p[z].ss == fimr || p[z].ff - p[z].ss == fiml){
                    soma = max(getSize(z, p[z].ff), soma );
                }
            }
            maxi = max(tam+soma, maxi);
        }
        cout << "Case #" << x << ": " << maxi << endl;
    }

    return 0;
}