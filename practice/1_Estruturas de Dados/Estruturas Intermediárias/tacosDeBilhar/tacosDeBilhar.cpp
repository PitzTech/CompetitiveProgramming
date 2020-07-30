#include <bits/stdc++.h>

using namespace std;

set<int> tacos;
int n, fabri = 0;

int main(){

    freopen("in", "r", stdin);
    freopen("out","w", stdout);

    scanf("%d", &n);

    for(int x = 0; x < n; x++){
        int temp;
        scanf("%d", &temp);
        if(tacos.find(temp) == tacos.end()){
            tacos.insert(temp);
            fabri += 2;
        }else{
            tacos.erase(temp);
        }
    }

    printf("%d",fabri);
    return 0;
}