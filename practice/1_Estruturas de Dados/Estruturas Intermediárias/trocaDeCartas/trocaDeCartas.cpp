#include <bits/stdc++.h>

using namespace std;

int n1, n2, cont1 = 0, cont2 = 0;
set<int> a;
set<int> b;

int main(){

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    scanf("%d %d", &n1, &n2);

    for(int x = 0; x < n1; x++){
        int temp;
        scanf("%d", &temp);
        if(a.find(temp) == a.end())
            a.insert(temp);
    }
    for(int x = 0; x < n2; x++){
        int temp;
        scanf("%d", &temp);
        if(b.find(temp) == b.end()){
            b.insert(temp);
            if(a.find(temp) == a.end()) cont2++;
            
        }
    }
    for(set<int>::iterator it = a.begin(); it != a.end(); ++it){
        if(b.find(*it) == b.end()) cont1++;
    }

    printf("%d", cont1 < cont2 ? cont1 : cont2);

    return 0;
}