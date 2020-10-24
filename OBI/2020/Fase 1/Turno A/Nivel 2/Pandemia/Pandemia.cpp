#include <bits/stdc++.h>
using namespace std;

bool infe[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int prinfec, reunifec;
    cin >> prinfec >> reunifec;
    infe[prinfec] = true;

    int ninf = 1;
    for(int i = 1; i <= m; i++){
        //cout << ninf << endl;
        int nguests;
        bool infec = false;
        cin >> nguests;
        int guests[nguests];
        for(int j = 0; j < nguests; j++){
            cin >> guests[j];
            
            if(i >= reunifec){
                if(infec){
                    if(!infe[guests[j]]){
                        infe[guests[j]] = true;
                        ninf++;
                    }   
                }else if(infe[guests[j]]){
                    infec = true;
                    ninf += j;
                    for(int k = 0; k < j; k++)
                        infe[guests[k]] = true;
                }
            }
        }
    }

    cout << ninf << "\n";
    return 0;
}