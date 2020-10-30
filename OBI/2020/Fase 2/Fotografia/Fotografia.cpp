#include <bits/stdc++.h>
using namespace std;

int fh,fw,fa;
int n,h,w,a;
int ans = -1, dif;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> fh >> fw;
    fa = fh*fw;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> h >> w;
        if(max(h,w) >= max(fh,fw) 
        && min(h,w) >= min(fh,fw)){
            int tempdif = h*w - fa;
            if(ans == -1 || dif > tempdif){
                ans = i;
                dif = tempdif;
            }
        }   
    }
    cout << ans;

    return 0;
}