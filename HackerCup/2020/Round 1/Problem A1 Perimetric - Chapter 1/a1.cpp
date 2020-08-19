#include <bits/stdc++.h>

#define MAXN 1000006
#define MODU 1000000007
using namespace std;

struct rooms{
    long l, h, w;
} room[MAXN];
bool comp(rooms a, rooms b){
    return (a.l < b.l);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in", "r", stdin);
    freopen("out","w", stdout);

    int t;
    cin >> t;
    
    long n, k;
    int w;

    long AL, BL, CL, DL;
    long AH, BH, CH, DH;
    for(int floor = 1; floor <= t; floor++){
        cin >> n >> k >> w;

        for(int i = 0; i < k; i++)
            cin >> room[i].l;
        cin >> AL >> BL >> CL >> DL;
        AL %= DL; BL %= DL; CL %= DL;
        for(int i = 0; i < k; i++)
            cin >> room[i].h;
        cin >> AH >> BH >> CH >> DH;
        AH %= DH; BH %= DH; CH %= DH;

        long maxh = 0;
        long long P = 1;  //perimeter
        long long AP = 0; //actual perimeter
        long long Psum = 0;
        for(int i = 0; i < n; i++){
            if(i >= k){
                room[i].l = ((AL * (room[i-2].l % DL) + BL * (room[i-1].l % DL) + CL) % DL) + 1;
                room[i].h = ((AH * (room[i-2].h % DH) + BH * (room[i-1].h % DH) + CH) % DH) + 1;
            }
            if(i == 0 || room[i-1].l + w < room[i].l){
                maxh = 0;
                if(i < n && room[i].l + w >= room[i+1].l){
                    maxh = room[i].h;
                }
                AP = w*2 + room[i].h*2 + Psum; 
            }else{
                //AP = room[i].l + room[i].w - room[i-1].l - room[i-1].w;
                AP = (room[i].l - room[i-1].l)*2 + Psum;
                if(room[i].h > maxh)
                    AP += (room[i].h - maxh)*2;
                maxh = max(room[i].h, maxh);
            }
            // cout << "(" << room[i].l << ";" << room[i].h << ")  ";
            // cout << "ap: " << AP << endl;
            Psum = AP;
            P = (P * AP) % MODU;
            //cout << P << endl;
        }

        cout << "Case #" << floor << ": " << (P % MODU) << "\n"; 
    }
}