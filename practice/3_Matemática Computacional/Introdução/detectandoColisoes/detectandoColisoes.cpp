#include <bits/stdc++.h>
using namespace std;

int axSup, axInf, ayInf, aySup, bxSup, bxInf, byInf, bySup;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d %d %d %d", &axInf, &ayInf, &axSup, &aySup);
    scanf("%d %d %d %d", &bxInf, &byInf, &bxSup, &bySup);

    if(axSup < bxInf || bxSup < axInf
    || aySup < byInf || bySup < ayInf){
        printf("0");
        
    }else{
        printf("1");
    }

    return 0;
}