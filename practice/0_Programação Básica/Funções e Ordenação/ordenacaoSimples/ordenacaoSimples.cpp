#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input", "r", stdin);
    freopen("output","w", stdout);
	int n;
    cin >> n;
	int dig[n];
   	for(int x = 0; x < n; x++)
        cin >> dig[x];
    sort(dig, dig+n);
    for(int x = 0; x < n; x++)
        cout << dig[x] << " ";
}