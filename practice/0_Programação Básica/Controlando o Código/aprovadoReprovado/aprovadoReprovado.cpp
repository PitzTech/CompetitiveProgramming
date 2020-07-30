#include <bits/stdc++.h>
using namespace std;

float n1,n2,media;

int main(){
	scanf("%f %f", &n1,&n2);
    media = (n1+n2)/2;
    if(media >= 7) printf("Aprovado");
    else if(media >= 4) printf("Recuperacao");
    else printf("Reprovado");
    return 0;
}