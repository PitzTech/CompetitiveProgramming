#include <bits/stdc++.h>
using namespace std;

int main(){   
    int num;
    int ini = 0, fim = 100, med;
    char ans;
    while(fim - ini > 1){   
        med = (fim+ini)/2;
        printf("Seu numero e maior que %d? ", med);
        cin >> ans;
        if(ans == 'n')
            fim = med;
        else 
            ini = med;
    }
    printf("Seu numero e %d", fim);
}