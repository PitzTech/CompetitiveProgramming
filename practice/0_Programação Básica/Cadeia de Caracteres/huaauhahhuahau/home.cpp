#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    string ris, ris2 = "", inv = "";
    char a = 'a', e = 'e', i = 'i', o = 'o', u = 'u';
    cin >> ris;
    if(ris.find('a') || ris.find('e') || ris.find('i') || ris.find('o') || ris.find('u')){
        for(int x = 0 ; x < ris.size(); x++)
            if(ris[x] == a || ris[x] == e || ris[x] == i || ris[x] == o || ris[x] == u)
                ris2 += ris[x];
        for(int x = 0; x < ris2.size(); x++)
            inv += ris2[ris2.size() - 1 - x];
    }
    if(ris2 == inv)
        printf("S");
    else
        printf("N");
}