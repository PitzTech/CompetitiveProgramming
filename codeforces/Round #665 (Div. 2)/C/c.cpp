#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b){
    return (b == 0 ? a : mdc(b, a%b));
}

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n;    
    for(int i = 0; i < t; i++){
        cin >> n;
        long arr[n];
        long mini = LONG_MAX;

        for(int j = 0; j < n; j++){
            cin >> arr[j];
            min(mini, arr[j]);
        }

        bool done = true;

        while(arr[0] > arr[1]){
            for(int j = 0; j < n; j++){
                done = false;
                for(int k = j; k < n; k++){
                    if(arr[j] > arr[k] && mdc(arr[j], arr[k]) == mini){
                        swap(arr[j], arr[k]);
                        done = true;
                        break;
                    }else if(arr[j] < arr[k]){
                        done = true;
                        break;
                    }else if(arr[j] == arr[k]){
                        done = true;
                    }else if(mdc(arr[j], arr[k]) != mini && k == n-1){
                        done = false;
                        goto END;
                    }
                }
            }
        } 
        END:
        if(done) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}