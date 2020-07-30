#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <utility>
#include <set>

#define endl "\n"
#define MAX 1000001
#define ff first
#define ss second
using namespace std;
using ll = long long;

ll n, cities, total, tank, cost[MAX], custo;
set<pair<ll,pair<ll, ll>>> dfs;

void runCar(ll pos, ll fuel, ll costs){
    if(pos < cities && fuel > 0){
        for(ll x = min(fuel, cities - pos); x > 0; x--){
            if(x == fuel && cost[pos+x] == 0 && x+pos != cities) continue;
            
            if(dfs.find(make_pair(pos, make_pair(fuel, costs))) == dfs.end()){
                dfs.insert(make_pair(pos, make_pair(fuel, costs)));

                runCar(pos+x, fuel - x, costs);
                if(cost[pos+x] != 0)
                    runCar(pos+x, fuel, cost[pos+x] + costs);
            }
        }
    }else if(pos == cities && fuel >= 0){
        if(custo == -1){
            custo = costs;
        }else{ 
            custo = min(costs, custo);
        }   
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    cin >> n;

    for(int x = 1; x <= n; x++){
        total;
        cin >> cities >> tank;

        for(ll y = 1; y <= cities; y++)
            cin >> cost[y];
        
        custo = -1;
        runCar(1, tank, 0);
        cout << "Case #" << x << ": " << custo << endl; 
    }

    return 0;
}