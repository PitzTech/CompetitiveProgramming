#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int stages;
    cin >> stages;
    long rp, rl, ra;
    cin >> rp >> rl >> ra;
    long teleport;
    cin >> teleport;
    int monsters[stages];
    for(int n = 0; n < stages; n++)
        cin >> monsters[n];

    long long ttime = 0;
    long long time;

    for(int i = 0; i < stages; i++){
        if(i == stages - 1) teleport *= 2;
        time = min({rp * monsters[i] + min(2*rp + teleport,ra), 
                    2 * rl + teleport, 
                    rl + rp + teleport
                    });
        ttime += time;
        //cout << "level: " << (i+1) << " time: " << time;
        if(i < stages - 1) ttime += teleport;
        //cout << "\ntotal: " << ttime << "\n";
    }

    cout << ttime;

    return 0;
}