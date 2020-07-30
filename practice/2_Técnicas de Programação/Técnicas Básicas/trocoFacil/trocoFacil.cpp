#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

//1, 5, 10, 25, 50 e 100

   int resul = 0, entra;
   scanf("%d", &entra); 
   
   if(entra / 100 > 0){
       resul += entra / 100;
       entra -= floor(entra / 100)*100;
   }
   if(entra / 50 > 0){
       resul += entra / 50;
       entra -= floor(entra / 50)*50;
   }
   if(entra / 25 > 0){
       resul += entra / 25;
       entra -= floor(entra / 25)*25;
   }
   if(entra / 10 > 0){
       resul += entra / 10;
       entra -= floor(entra / 10)*10;
   }
   if(entra / 5 > 0){
       resul += entra / 5;
       entra -= floor(entra / 5)*5;
   }
   if(entra / 1 > 0){
       resul += entra / 1;
       entra -= floor(entra / 1);
   }

   printf("%d", resul);
}