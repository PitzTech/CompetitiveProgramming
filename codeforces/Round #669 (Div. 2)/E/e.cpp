#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;

int solve(int x, int y, vii arr, int maxi){
    for(int i = 0; i < x; i++){
        arr[i] = arr.size();
    }for(int i = arr.size() - 1 - y; i < arr.size(); i++)
        arr[i] = arr.size();



    sort(arr.begin(), arr.end());

    return maxi;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vii arr; //dis, el

    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        arr.emplace_back(el-i,el);
    }
    
    for(ii el : arr)
        cout << "(" << el.first << " ; " << el.second << ")\n";
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << solve(x,y, arr, 0) << "\n";
    }

    return 0;
}