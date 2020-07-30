#include <bits/stdc++.h>

using namespace std;

string title(string F){
    bool i = true;
	for(int x = 0; x < F.size(); x++){
        if(isspace(F[x])) i = true;
        else if(i == true){
            F[x] = toupper(F[x]);
            i = false;
        }else
            F[x] = tolower(F[x]);
    }
    return F;
}

int main(){ 
    freopen("input", "r", stdin);
    freopen("output","w",stdout);
	string F;
	getline(cin, F);
	cout << title(F) << "\n";
}