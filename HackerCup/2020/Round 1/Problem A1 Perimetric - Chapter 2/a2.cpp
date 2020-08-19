#include <bits/stdc++.h>

#define ff first
#define ss second
#define MAXN 1000006
using namespace std;

struct room{
    int l,h,w;
};
bool comp(room a, room b){
    return (a.l < b.l);
}
room coords[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int houses;
    int n, k; // rooms, k constants
    int AL, BL, CL, DL; //L constants
    int AW, BW, CW, DW; //H constants
    int AH, BH, CH, DH; //H constants

    cin >> houses;

    for(int house = 0; house < houses; house++){
        int hstart = -1;
        int vback = 0;
        long long result = 1;
        
        cin >> n >> k;
        for(int i = 0; i < k; i++)
            cin >> coords[i].l;
        cin >> AL >> BL >> CL >> DL;
        AL %= DL; BL %= DL; CL %= DL;
        for(int i = 0; i < k; i++)
            cin >> coords[i].w;
        cin >> AW >> BW >> CW >> DW;
        AW %= DW; BW %= DW; CW %= DW;
        for(int i = 0; i < k; i++)
            cin >> coords[i].h;
        cin >> AH >> BH >> CH >> DH;
        AH %= DH; BH %= DH; CH %= DH;

        for(int i = k; i < n; i++){
            coords[i-2].l %= DL;
            coords[i-1].l %= DL;
            coords[i-2].h %= DH;
            coords[i-1].h %= DH;

            coords[i].l = ((AL*coords[i-2].l + BL * coords[i-1].l + CL) % DL)+1;
            coords[i].l = ((AH*coords[i-2].h + BH * coords[i-1].h + CH) % DH)+1;
        }
        sort(coords, coords + n, comp);
        
        for(int i = 0; i < n; i++){
            int perimeter;
            if(i == 0 || coords[i-1].l + coords[i-1].w < coords[i].l){
                perimeter = coords[i].w*2 + coords[i].h*2 + vback;
                hstart = coords[i].h;
            }else{
                perimeter = vback + (coords[i].l + coords[i].w - coords[i - 1].l + coords[i - 1].w)*2;
                if(coords[i].h > hstart) perimeter += (coords[i].h - hstart)*2;
                hstart = max(coords[i].h, hstart);
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