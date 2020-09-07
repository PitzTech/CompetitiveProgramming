#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll arr[n], soma = 0, coins = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            soma += arr[i];
        }
        sort(arr, arr+n);
        while(soma){
            for(int i = 0; i < n; i++){
                for(int j = n-1; j >= 0; j--){
                    if(arr[i] == 0) break;
                    if(arr[i] <= arr[j]){
                        if(abs(arr[i]) < abs(arr[j])){
                            arr[j] += arr[i];
                            arr[i] = 0;
                        }    
                        arr[i] = 0;
                    }
                }
            }
        }
        cout << coins << "\n";
    }

    return 0;
}