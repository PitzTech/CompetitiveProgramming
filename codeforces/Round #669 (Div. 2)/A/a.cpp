#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(i%2){//even
                even += arr[i];
            }else{
                odd += arr[i];
            }
        }
        int subs = abs(even - odd);
        cout << n - subs << "\n";
        for(int i = 0; i < n; i++){
            if(arr[i] && subs){
                subs--;
            }else{
                //cout << "entrou";
                cout << arr[i] << " ";
            }
        }
        cout << "\n"; 
    }

    return 0;
}