#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
	int max, n1, n2;
    char sinal, multi = '*', ad = '+'; 
    cin >> max >> n1 >> sinal >> n2;
    if(sinal == multi)
        if(n1*n2 > max) printf("OVERFLOW");
    	else printf("OK");
    else if(n1 + n2 > max)printf("OVERFLOW");
    else printf("OK");
}