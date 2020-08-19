#include <bits/stdc++.h>

#define ff first
#define ss second
#define MAXN 1000006
using namespace std;
using ii = pair<int,int>; // w , h

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int houses;
    int n, k, w; // rooms, k constants, width
    long AL, BL, CL, DL; //L constants
    long AH, BH, CH, DH; //H constants

    cin >> houses;

    for(int house = 0; house < houses; house++){
        ii coords[MAXN]; // (Li, Hi);
        int hstart = -1;
        int vback = 0;

        cin >> n >> k >> w;
        for(int i = 0; i < k; i++)
            cin >> coords[i].ff;
        cin >> AL >> BL >> CL >> DL;
        AL %= DL; BL %= DL; CL %= DL;
        for(int i = 0; i < k; i++)
            cin >> coords[i].ss;
        cin >> AH >> BH >> CH >> DH;
        AH %= DH; BH %= DH; CH %= DH;

        long long result = 1;
        for(int i = 0; i < n; i++){
            long perimeter;
            if(i >= k){
                coords[i-2].ff %= DL;
                coords[i-1].ff %= DL;
                coords[i-2].ss %= DH;
                coords[i-1].ss %= DH;

                coords[i].ff = ((AL*coords[i-2].ff + BL * coords[i-1].ff + CL) % DL)+1;
                coords[i].ss = ((AH*coords[i-2].ss + BH * coords[i-1].ss + CH) % DH)+1;
            }
            
            //cout << "L" << i << ": " << coords[i].ff << endl;

            if(i == 0 || coords[i-1].ff + w < coords[i].ff){//just work on a1, need to add coords[i+1].ff > coords[i].ff or just ordenate 
                perimeter = w*2 + coords[i].ss*2 + vback;
                hstart = coords[i].ss;
            }else{
                perimeter = vback + (coords[i].ff - coords[i - 1].ff)*2;
                if(coords[i].ss > hstart) perimeter += (coords[i].ss - hstart)*2;
                hstart = max(coords[i].ss, hstart);
            }
            vback = perimeter;
            //cout << "i: " << (i+1) << " perimeter is " << perimeter << "\n";
            
            result = (result % 1000000007) * (perimeter % 1000000007);
            result %= 1000000007;
            //cout << "resul: " << result << "\n";
        }
        cout << "Case #" << house + 1 << ": " << result << "\n";
    }

    return 0;
}