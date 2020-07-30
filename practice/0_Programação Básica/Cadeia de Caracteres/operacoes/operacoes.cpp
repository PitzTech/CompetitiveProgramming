#include <bits/stdc++.h>
using namespace std;
int main(){

   //freopen("input", "r", stdin);
   //freopen("output", "w", stdout);

	char letra, letras = 'M';
    double num1, num2;
    cin >> letra;
    cin >> num1 >> num2;
    cout << fixed << setprecision(2);
    if(letra == letras)
        cout << num1*num2;
        //printf("%.2f", num[0]*num[1]);
    else
        cout << num1/num2;
        //printf("%.2f", num[0] / num[1]);
}
