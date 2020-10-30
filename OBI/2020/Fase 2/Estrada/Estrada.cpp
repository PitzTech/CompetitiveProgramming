#include <bits/stdc++.h>
using namespace std;

long t; // road size
int n; //n cities
float ans, temp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> n;
    long dist[n]; //city distance

    for(int i = 0; i < n; i++)
        cin >> dist[i];

    sort(dist, dist+n);

    ans = dist[0] + (float)(dist[1] - dist[0]) / 2;
    for(int i = 1; i < n - 1; i++){
        temp = (float)(dist[i]-dist[i-1])/2 + (float)(dist[i+1]-dist[i])/2;
        if(temp < ans) ans = temp;
    }    
    temp = (float)(t - dist[n-1]) + (float)(dist[n-1]-dist[n-2])/2; 
    if(temp < ans) ans = temp;

    cout << setprecision(2) << fixed;
    cout << ans;
    return 0;
}