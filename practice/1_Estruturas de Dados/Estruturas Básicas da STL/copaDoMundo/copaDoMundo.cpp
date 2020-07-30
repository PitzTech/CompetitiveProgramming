#include <bits/stdc++.h>
using namespace std;

queue<int> campeao;
int main(){
    freopen("in","r", stdin);
    freopen("out","w",stdout);

    for(int x = 0; x < 16;x++) campeao.push(65+x);

    for(int x = 0 ; x < 15; x++){
        int p,s;
        scanf("%d %d",&p,&s);
        if(p < s){
            campeao.pop();
            campeao.push(campeao.front());
            campeao.pop();
        }else{
            campeao.push(campeao.front());
            campeao.pop();
            campeao.pop();
        }
    }
    printf("%c",campeao.front());
    return 0;
}