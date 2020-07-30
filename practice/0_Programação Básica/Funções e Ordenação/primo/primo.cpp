#include <bits/stdc++.h>
using namespace std;

bool eh_primo(int num){
	int div = 2;
    for(int x = 2; x < floor(sqrt(num))+1; x++){
        if(num % x == 0){
            div += (num / x == x) ? 1 : 2; 
            break;
        }
    }
    return div > 2 || num == 1 ? false : true;
}

int main(){

    freopen("input","r",stdin);
    freopen("output","w",stdout);

	int x;

	cin>>x;

	if(eh_primo(x)){
		cout << "S";
	}else{
		cout << "N";
	}
}
